import torch
import numpy

N_LAYERS = 7


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

shape_layer[0] = (torch.Size([197, 768]), torch.Size([768, 2304]))
shape_layer[1] = (torch.Size([197, 64]), torch.Size([64, 197]))  # original: shape_layer[1] = (torch.Size([12, 197, 64]), torch.Size([1, 12, 64, 197]))  -> 12 is num_heads: just remove the head
shape_layer[2] = (torch.Size([197, 197]), torch.Size([197, 64])) # original: shape_layer[2] = (torch.Size([12, 197, 197]), torch.Size([1, 12, 197, 64]))
shape_layer[3] = (torch.Size([197, 768]), torch.Size([768, 768]))
shape_layer[4] = (torch.Size([197, 768]), torch.Size([768, 3072]))
shape_layer[5] = (torch.Size([197, 3072]), torch.Size([3072, 768]))
#shape_layer[6] = (torch.Size([1, 768]), torch.Size([768, 1000]))
shape_layer[6] = (torch.Size([1024, 768]), torch.Size([768, 1000])) # fixed with an exagerated batch size


shape_layer_sw[0] = torch.Size([197, 768])
shape_layer_sw[1] = torch.Size([197, 64])
shape_layer_sw[2] = torch.Size([197, 197])
shape_layer_sw[3] = torch.Size([197, 768])
shape_layer_sw[4] = torch.Size([197, 768])
shape_layer_sw[5] = torch.Size([197, 3072])
#shape_layer_sw[6] = torch.Size([1, 768])
shape_layer_sw[6] = torch.Size([1024, 768])  # fixed with an exagerated batch size

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
