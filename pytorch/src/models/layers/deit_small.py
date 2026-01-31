import torch
import numpy

N_LAYERS = 7


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

shape_layer[0] = (torch.Size([197, 384]), torch.Size([384, 1152]))
shape_layer[1] = (torch.Size([197, 64]), torch.Size([64, 197]))
shape_layer[2] = (torch.Size([197, 197]), torch.Size([197, 64]))
shape_layer[3] = (torch.Size([197, 384]), torch.Size([384, 384]))
shape_layer[4] = (torch.Size([197, 384]), torch.Size([384, 1536]))
shape_layer[5] = (torch.Size([197, 1536]), torch.Size([1536, 384]))
#shape_layer[6] = (torch.Size([8, 384]), torch.Size([384, 1000]))
shape_layer[6] = (torch.Size([1024, 384]), torch.Size([384, 1000])) # fixed with an exagerated batch size

shape_layer_sw[0] = torch.Size([197, 384])
shape_layer_sw[1] = torch.Size([197, 64])
shape_layer_sw[2] = torch.Size([197, 197])
shape_layer_sw[3] = torch.Size([197, 384])
shape_layer_sw[4] = torch.Size([197, 384])
shape_layer_sw[5] = torch.Size([197, 1536])
#shape_layer_sw[6] = torch.Size([8, 384])
shape_layer_sw[6] = torch.Size([1024, 384])  # fixed with an exagerated batch size


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
