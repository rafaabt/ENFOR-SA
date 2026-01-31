import torch
import numpy

N_LAYERS = 7


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]


# NOTE: the input and att head dim were removed manually from the layer shapes...

shape_layer[0] = (torch.Size([197, 192]), torch.Size([192, 576]))
shape_layer[1] = (torch.Size([197, 64]),  torch.Size([64, 197]))
shape_layer[2] = (torch.Size([197, 197]), torch.Size([197, 64]))
shape_layer[3] = (torch.Size([197, 192]), torch.Size([192, 192]))
shape_layer[4] = (torch.Size([197, 192]), torch.Size([192, 768]))
shape_layer[5] = (torch.Size([197, 768]), torch.Size([768, 192]))
#shape_layer[6] = (torch.Size([8, 192]),   torch.Size([192, 1000]))
shape_layer[6] = (torch.Size([1024, 192]),   torch.Size([192, 1000])) # fixed with an exagerated batch size


# ignore the batch dim
shape_layer_sw[0] = torch.Size([197, 192])
shape_layer_sw[1] = torch.Size([197, 64])
shape_layer_sw[2] = torch.Size([197, 197])
shape_layer_sw[3] = torch.Size([197, 192])
shape_layer_sw[4] = torch.Size([197, 192])
shape_layer_sw[5] = torch.Size([197, 768])
#shape_layer_sw[6] = torch.Size([8, 192])      
shape_layer_sw[6] = torch.Size([1024, 192])  # fixed with an exagerated batch size

# TODO: Fix this issue with layer [6]. the first dimention depends on the number of inputs in the batch!!
# the fault list must be the same regardless of the batch size
# so for the attention head, the x position must be decided at runtime!
# to fix this: use a fixed fault list with a big batch size
# for fi with arbitrary batch sizes: take the input number from the list % batch size 

# actually not convolutions, but i kept this to be compatible with the CNN models
conv_layers_names={
0:'qkv',
1:'matmul_1',
2:'matmul_2',
3:'proj',
4:'mlp.fc1',
5:'mlp.fc2',
6:'head'
}
