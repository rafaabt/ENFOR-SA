## Description

This is a simple example on how to:
1. Instantiate models instrumented for fault injection; 
2. Configure and load the fault list;
3. Load the dataset and iterate over it;
4. Run an injection loop over the model. 

The fault model is abstracted. For RTL, Gemmini will be invoked in the background to compute a single tile. This aspect is transparent. This example is available in [`pytorch/example_injection_loop.py`](example_injection_loop.py).

Import the modules:
```
import torch
import src.utils.dataset_loader as dataloader
import src.definitions as defs
from src.conv import cached_tensors as tcache
from src.models.instrumented_model import InstrumentedModel
from src.models.base_model import BaseModel
from src.flist.fl import fl
from src.flist import fi_target as fit
from src.gemmini import gemmini_config as c
from src.utils import utils as u
```

Load the models and the dataloader
```
# loads a golden, reference model
model_golden = BaseModel(defs.MODEL_NAME)

# loads the instrumented model for fault injections
model_faulty = InstrumentedModel(defs.MODEL_NAME)

# gets a handle to iterate over the dataset
val_loader = dataloader.load_dataset_imagenet(batch_size=defs.BATCH_SIZE)
```

Declare some counters
```
# total number of injections
injections = 120

# batches tested
max_batches = 5

# counters
critical_faults, total_sdcs = 0, 0
```

Configure the fault targets, for example:
```
fault_target = {
    #
    # the target conv layer (QuantizedConv2d, QuantizedConvReLU2d, etc...)
    #
    'layer': 4,
    
    #
    # target PE position
    #
    'pe_row': 0, # targets only PEs of row 0
    'pe_col':(u.NONE, [0, 2]), # all columns except for columns 0 and 2

    #
    # the target bit in each PE
    #
    'bit': (u.ANY, [5, 6, 7]),  # inject only bits 5, 6, and 7

    #
    # the target signal in each PE (inputs, outputs or ctrl signals)
    #
    'target': (u.ANY, [c.IN_A, c.IN_B, c.OUT_C]), # inject only in the PE inputs and outputs
    #'target': (u.ANY, [c.SIG_PROPAG, c.SIG_VALID]), # inject only in the control signals
}
```

Load the fault list
```
fault_list = fl.load_fault_list(defs.FAULT_LIST, (0, injections-1), filters=fault_target) 
```

Run the injection loop
```
# loops over the dataset
for i, (inputs, gt_target) in enumerate(val_loader):
    if i == max_batches:
        break

    inputs = inputs.to(defs.DEVICE, non_blocking=True)
    
    # the ground truth label. this could be used to compute the model accuracy
    gt_target = gt_target.to(defs.DEVICE, non_blocking=True)

    # runs the golden inference. returns the output logits
    logits_golden = model_golden.run_inference(inputs)

    # compute the golden softmax probabilities over the logits
    probabilities_golden = torch.nn.functional.softmax(logits_golden, dim=1)

    # extracts the computed golden labels
    predicted_labels_golden = torch.argmax(probabilities_golden, dim=1)

    # runs the faulty mode by iterating over each fault in the list
    for fault in fault_list:
        # faulty inference run
        logits_faulty = model_faulty.run_inference(inputs, fault=fault)
        probabilities_faulty = torch.nn.functional.softmax(logits_faulty, dim=1)
        predicted_labels_faulty = torch.argmax(probabilities_faulty, dim=1)

        # count the number of inputs for which the faulty model != golden reference
        count_inputs_failed = (predicted_labels_faulty != predicted_labels_golden).sum().item()

        # the fault is critical if at least one input failed
        critical_faults += count_inputs_failed != 0

        # the total number of inputs with faults
        total_sdcs += count_inputs_failed

    # fault injections run on repeated inputs/layers. we store the conv outputs in LUTs to improve injection time. 
    # the LUTs must be cleared whenever new inputs are to be simulated
    tcache.clear_luts()

print(f"Finished with {critical_faults} critical faults ({100*critical_faults/len(fault_list):.2f}%)")
```

## High level experiment handlers
There's a high level "API" way to run injection experiments on input indices, as shown in the [`main.py`](./main.py) script. This approach relies on the API defined in [pytorch/src/experiment](./src/experiment) folder. The functions defined in this API, in general, cannot be used in isolation.


For example, instead of using explicit model calls, as shown in the previous example, one can run:

```
model_golden = BaseModel(defs.MODEL_NAME)
model_faulty = InstrumentedModel(defs.MODEL_NAME)

experiment = exp_seq.ExperimentSequential(model_faulty=model_faulty, model_golden=model_golden) 

#generates a random set of indices. inputs are loaded from the dataset based on the indices
input_indices = u.random_indices(size=defs.BATCHES*defs.BATCH_SIZE, max=dataloader.dataset_len-1)

critical_faults = experiment.run_experiment(input_indices)
```

This will run the injection loop and store the results in the reports folders.