import torch
import time
import warnings

from collections import defaultdict
from typing import List, Optional

from src.models import common
from src.conv import cached_tensors as tcache
from src.utils import dataset_loader as dataloader
from src import definitions as defs
#from . import forward_ResNet18 as fw_ResNet18


warnings.filterwarnings("ignore", message="TypedStorage is deprecated")
warnings.filterwarnings("ignore", message="must run observer before calling calculate_qparams")



# encapsulates a base dnn model ands provides basic model inference and tensor manipulation facilities
class BaseModel(torch.nn.Module):

    def __init__(self, model_name):
        super(BaseModel, self).__init__()

        if defs.VIT: # ViTs
            self.model = common.QUANTIZED_MODELS_VIT(model_name)(pretrained=True, num_classes=1000, drop_rate=0, drop_path_rate=0.1)

        else: # CNNs
            weights_work = common.QUANTIZED_MODELS[model_name][0]
            model_work   = common.QUANTIZED_MODELS[model_name][1]
            self.model   = model_work(weights=weights_work, quantize=True)

        self.model.eval()

        self.is_golden = True

        BaseModel.input_batch_indices: List[int] = None

        self.top1_conf = defaultdict(int)
        self.top2_conf = defaultdict(int)
        self.conf_gap  = defaultdict(int)

        # Use all layers of the base model except the final fully connected (fc) layer
        # this would be used for fastforwarding the model
        #self.features = torch.nn.Sequential(*list(self.model.children())[:-1])
        #self.features = torch.nn.Sequential(*list(self.model.children())[:]) # take all layers
        #self.n_layers = len(self.features)

        #print(self.features)
        #exit(0)

        self.time_samples_forward_pass = [] # [Debug only]: stores the execution times of the forward pass
        self.calibrate = False
        

    # Loads the model state from a checkpoint. This is used for ViT models only
    def load_checkpoint(self, cp_file=None):
        #print(f"Loading state from checkpoint: {cp_file}")

        if not defs.VIT:
            raise("load_checkpoint() is only applicable to ViT models")
            
        if not cp_file:
            cp_file=f"./checkpoints/{defs.MODEL_NAME}.pth.tar"

        current_model_dict = self.model.state_dict()
        loaded_state_dict = torch.load(cp_file, map_location=torch.device('cpu'), weights_only=True)

        new_state_dict={k:v if v.size() == current_model_dict[k].size() else current_model_dict[k] for k,v in zip(current_model_dict.keys(), loaded_state_dict.values())}
        self.model.load_state_dict(new_state_dict, strict=False)
        #self.model.load_state_dict(loaded_state_dict, strict=False)
        #exit(0)


    # every type of variable that is shared between faulty and golden models is static (i.e, BaseModel.var):
    #   ex: input batches, input batch ids, ground truth labels (these are set whenever a new golden run is performed)
    # other types of fields are not static (these are set whenever a new inference is performed)
    #   ex: classification labels, scores, accuracy, etc.

    # runs a new batch inference (both golden or faulty models can call this). this stores model-dependent results
    def run_batch_inference(self):
        if len(BaseModel.input_batch): # when pruning the inputs in the tree mode, the batch maybe completely erased
            with torch.no_grad():  # No need to compute gradients
                # Get the model's output
                #self.output_logits = self.model(BaseModel.input_batch) # this wont call the forward pass!!
                self.output_logits = self(BaseModel.input_batch.float())

                if defs.CUDA:
                    torch.cuda.synchronize()

                # Apply softmax to get probabilities
                self.probabilities = torch.nn.functional.softmax(self.output_logits, dim=1)
     
                # top5_classes.values contains the score probabilities - top5_classes.indices containts the associated classification indices
                self.top5_classes = torch.topk(self.probabilities, 5)

                # the top 5 labels
                self.top5_classes_indices = self.top5_classes.indices      

                # the top-5 scores  
                self.top5_classes_values = self.top5_classes.values  # shape ([16,5])
                #top5_classes_values, top5_classes_indices = torch.topk(self.probabilities, k=5, dim=1)

                # Get the predicted top-1 label for each input in the batch
                self.predicted_labels = torch.argmax(self.probabilities, dim=1)

                if self.is_golden:
                    # computes the conf. gap between top1 and top2 confidence levels
                    for i in range(len(BaseModel.input_batch)):
                        self.top1_conf[BaseModel.input_batch_indices[i]] = self.top5_classes_values[i][0].item()
                        self.top2_conf[BaseModel.input_batch_indices[i]] = self.top5_classes_values[i][1].item()
                        self.conf_gap[BaseModel.input_batch_indices[i]] = (self.top1_conf[BaseModel.input_batch_indices[i]] - self.top2_conf[BaseModel.input_batch_indices[i]])

                return self.predicted_labels, self.top5_classes, self.output_logits

        return None, None, None


    # loads an input batch and runs the golden mode. stores batch-related info (static class members) and golden mode information
    def run_golden_batch(self, batch_indices: List[int]):
        if not self.is_golden:
            print("[Error]: run_golden_batch() called from non-golden model")
            exit(0)

        # early‑out if unchanged
        if not self.calibrate and batch_indices == BaseModel.input_batch_indices:
            return True

        if not batch_indices: # empty list - do nothing else (maybe the tree approach pruned all inputs)
            return False

        #custom_conv.input_ids = batch_indices[:] # moved to experiment_sequential.py

        # returns a batch of input tensors with their respective expected top1 labels
        BaseModel.input_batch, BaseModel.ground_truth_labels = dataloader.get_input_batch(batch_indices)
        
        BaseModel.input_batch = BaseModel.input_batch.to(defs.DEVICE)
        BaseModel.ground_truth_labels = BaseModel.ground_truth_labels.to(defs.DEVICE)

        # reads a toy input batch from the examples in folder toy_inputs
        #BaseModel.input_batch, BaseModel.ground_truth_labels = dataloader.load_toy_input(batch_indices[0])
        
        # the batch of inputs (list of indexes to the imagenet dataset inputs)
        BaseModel.input_batch_indices = batch_indices[:] # shallow copy is enough
        BaseModel.input_batch_size = len(batch_indices)
        BaseModel.input_batch_size_full = len(batch_indices)

        # runs the batch in golden mode
        _, _, _ = self.run_batch_inference()

        # counts the number of inputs in the batch that are mispredicted (wrong top1 class)
        count_gold_top_1_mispredicted = torch.sum(self.predicted_labels != BaseModel.ground_truth_labels).item()

        # computes the batch top1 accuracy
        self.batch_top1_accuracy = (BaseModel.input_batch_size - count_gold_top_1_mispredicted)/BaseModel.input_batch_size
        #print(f"Batch top1 accuracy: {100*self.batch_top1_accuracy:.4f}% (size: {BaseModel.input_batch_size})")

        # empties the tensor LUTs - must call this when running multiple inputs in the same campaign to force the LUT tensors to be loaded again to the new input
        tcache.clear_luts()



    def layer_names(self): # Returns a list of layer names.
        return [name for name, _ in self.model.named_modules()]


    def forward(self, *inputs, **kwargs):
        return self.model(*inputs, **kwargs)


