import torch
import atexit
import copy
import os

from collections import defaultdict, deque
from typing import List, Optional
from src.models.base_model import BaseModel
from src.experiment import logger
from src import definitions as defs
from src.utils import utils as u
from src.gemmini import gemmini_config as conf
from src.flist import fi_target as fit
from src.flist.fl import fl

if defs.FI_GEMM:
    from src.flist.fault_list import FaultStatus


class Experiment():
    def __init__(self, model_faulty, model_golden):
        self.model_faulty = model_faulty
        self.model_golden = model_golden

        self.model_faulty.model.to(defs.DEVICE)
        self.model_golden.model.to(defs.DEVICE)

        # setup the fault targets
        self.fault_target = fit.setup_target()

        atexit.register(self._cleanup_) 

        self.init_loggers()

    # this is abstract. has to be implemented in the subclass
    def run_experiment(self, 
                       input_indices:List[int],
                       trials=defs.INJECTIONS):
        raise "Error: the class Experiment should not be instantiated"
   

    # this is abstract. has to be implemented in the subclass
    def run_single_batch(self, batch_id:int, batch_indices:List[int], trials=defs.INJECTIONS):
        raise "Error: the class Experiment should not be instantiated"


    def init_loggers(self):
        if logger.SKIP_LOGS:
            print(f"{u.Co['fg'][13]}⚠️   WARNING: Logger is off!{u.R}")

        # the csv report file are stored according to this path pattern
        # the directory is build in the params.sh script file: build_dir "$root_report_path/$root_experiment/$mode_folder/trace/$model"
        # EXP_FOLDER comes from -$base_dir (the args -o $base_dir)
        batch_log_type = logger.TYPE_STATS_PER_BATCH_SEQUENTIAL

        # attach this to the report file name: if using rtl, attach the gemmini config. if SW, just attach SW
        injConf = conf.CONFIG_KEY if defs.FI_GEMM else "SW"

        """ # removed for open source
        if defs.TREE_FI_MODE:
            batch_log_type = logger.TYPE_STATS_PER_BATCH_PARALLEL
            fn_nodes = f"{defs.EXP_FOLDER}/nodes/{defs.CAMP_ALIAS}-s{defs.SEED}-{injConf}.csv"
            
            self.nodes_logger = logger.Logger(
                fn_nodes, 
                logger.TYPE_STATS_PER_NODE,
                skip_log=logger.SKIP_NODES_LOG) 

            fn_tree_dse = f"{defs.EXP_FOLDER}/tree_dse/{defs.CAMP_ALIAS}-s{defs.SEED}-{injConf}.csv"

            self.tree_dse_logger = logger.Logger(
                fn_tree_dse, 
                logger.TYPE_TREE_DSE, 
                skip_log=logger.SKEE_TREE_DSE_LOG)
        """

        trace_path = f"{defs.EXP_FOLDER}/trace"
        batch_path = f"{defs.EXP_FOLDER}/batch"

        fn_trace = f"{trace_path}/{defs.CAMP_ALIAS}-s{defs.SEED}-{injConf}.csv"
        fn_batch = f"{batch_path}/{defs.CAMP_ALIAS}-s{defs.SEED}-{injConf}.csv"

        os.makedirs(trace_path, exist_ok=True)
        os.makedirs(batch_path, exist_ok=True)

        self.trace_logger = logger.Logger(
            fn_trace, 
            logger.TYPE_STATS_PER_FAULT if defs.FI_GEMM else logger.TYPE_STATS_PER_FAULT_SW, 
            skip_log=logger.SKIP_TRACE_LOG
            )

        self.batch_logger = logger.Logger(
            fn_batch, 
            batch_log_type,
            skip_log=logger.SKIP_BATCH_LOG
            ) 


    def _cleanup_(self): # called automatically at program exit
        # dumps the remaining of the buffers if available
        
        if not logger.SKIP_LOGS:
            self.trace_logger.flush()
            self.batch_logger.flush()
     
            #if defs.TREE_FI_MODE: # removed for open source
                #self.nodes_logger.flush()


    def run_all_batches(self, input_indices:List[int], trials=defs.INJECTIONS):
        critical_faults, total_inputs = 0, len(input_indices)

        for batch_id in range(0, total_inputs, defs.BATCH_SIZE):
            ulim = min(total_inputs, batch_id+defs.BATCH_SIZE)
            batch_indices = input_indices[batch_id:ulim]
            
            critical_faults += self.run_single_batch(batch_id, batch_indices, trials=trials)

        return critical_faults


    def run_single_fault(self, fault:fl.Fault):
        # sets the global fault (will be injected in matmul_random_tile())
        fl.next_fault = fault
        fl.fault_list = deque([fault])

        self.model_faulty.run_batch_inference()

        return self.eval_trial_stats()


    # computes and logs the fi stats
    def eval_trial_stats(self, dump_stats=True): # for the node fault list we only dump the stats for leaf nodes

        # the stats of the last trial. one item for each input in the batch
        stats_list = [logger.StatsPerFault() for _ in range(BaseModel.input_batch_size_full)]

        # marks which inputs in the batch are top1 mispredicted (maybe due to the fault or model misclassification)
        is_input_mispredicted = defaultdict(bool) 
        
        # marks which inputs in the batch are different from the golden (golden maybe ground-truth correct or not) 
        is_input_sdc1_critical = defaultdict(bool)
        is_input_sdc5_critical = defaultdict(bool)

        # the accuracy drop status of the fault in the input
        status_input_acc_drop = defaultdict(logger.AccDropStatus)  

        for i, index in enumerate(BaseModel.input_batch_indices):  # iterates over each index (index is the dataset input index)          
            lbl_grth = BaseModel.ground_truth_labels[i]
            lbl_gold = self.model_golden.predicted_labels[i]
            lbl_work = self.model_faulty.predicted_labels[i]

            mismatch_wrt_grth = (lbl_work != lbl_grth).item()  # is there a mismatch w.r.t the ground truth label (a.k.a, critical fault)
            has_sdc1 = (lbl_work != lbl_gold).item() # is there a mismatch w.r.t the gold label (maybe ground truth or not)

            has_sdc5 = not lbl_work in self.model_golden.top5_classes_indices[i] 

            is_input_mispredicted[index]  = mismatch_wrt_grth  # the same as sdc1
            is_input_sdc1_critical[index] = has_sdc1 
            is_input_sdc5_critical[index] = has_sdc5
            
            """
            We define a fault as 'critical' if the top1 label != top1 golden label

            A critical fault can:
                1. drop the accuracy        (if golden == gt)
                2. improve the accuracy     (if work = gt)
                3. have no accuracy effects (if work != gt)

            input  fault  ground_truth_label  gold_label  work_label
            12      1      10                 10          10     # this fault is not critical. it causes no accuracy drops
            10      2      42                 34          56     # this fault is critical. no accuracy drops (w.r.t golden mode)
            12*     3      10                 10          12*    # this fault is critical. it causes accuracy drops, because golden == ground thruth (*)
            14      4      44*                55          44*    # this fault is critical. it improves accuracy, because the faults causes the model to classify correctly (*)
            """

            """
            # computs the accuracy drops
            if has_sdc1:
                status_input_acc_drop[index].did_acc_drop = lbl_gold == lbl_grth
                status_input_acc_drop[index].did_acc_impr = lbl_work == lbl_grth
                status_input_acc_drop[index].did_acc_same = lbl_work != lbl_grth
            else:
                status_input_acc_drop[index].did_acc_drop = False
                status_input_acc_drop[index].did_acc_impr = False
                status_input_acc_drop[index].did_acc_same = True
            """
            if not (dump_stats and not self.trace_logger.skip_log):
                continue

            stats_list[i].input_id = index
            stats_list[i].tgt_layer = defs.TARGET_LAYER
            stats_list[i].sdc1 = has_sdc1
            stats_list[i].sdc5 = has_sdc5

            if defs.FI_GEMM:
              # the (global) last fault (fl.next_faul, Fault() object) was attributed in the last fault injection trial. 
              # here we update the status of such fault
                fl.next_fault.status = FaultStatus(
                    self.model_faulty.stats_gemm_msk.gemm_msk[i], 
                    self.model_faulty.stats_gemm_msk.scale_msk[i], 
                    self.model_faulty.stats_gemm_msk.round_msk[i], 
                    self.model_faulty.stats_gemm_msk.clamp_msk[i],
                    self.model_faulty.stats_gemm_msk.qtz_msk[i], 
                    has_sdc1
                    )

            # copy the status from fl.next_fault to the status to be logged
            # it must be a copy because fl.next_fault will change for each iteration of the loop, 
            # and we do not want to change the status of the previous iterations on stats_list[i]
            stats_list[i].fault = copy.copy(fl.next_fault)
            
            self.trace_logger.try_dump_item(stats_list[i])
        
        # end of block [for i, index in enumerate(BaseModel.input_batch_indices):]

        return is_input_mispredicted, is_input_sdc1_critical
