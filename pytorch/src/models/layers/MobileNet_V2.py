import torch
import numpy

N_LAYERS = 52


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

conv_layers_names={
0:'features.0.0',
1:'features.1.conv.0.0',
2:'features.1.conv.1',
3:'features.2.conv.0.0',
4:'features.2.conv.1.0',
5:'features.2.conv.2',
6:'features.3.conv.0.0',
7:'features.3.conv.1.0',
8:'features.3.conv.2',
9:'features.4.conv.0.0',
10:'features.4.conv.1.0',
11:'features.4.conv.2',
12:'features.5.conv.0.0',
13:'features.5.conv.1.0',
14:'features.5.conv.2',
15:'features.6.conv.0.0',
16:'features.6.conv.1.0',
17:'features.6.conv.2',
18:'features.7.conv.0.0',
19:'features.7.conv.1.0',
20:'features.7.conv.2',
21:'features.8.conv.0.0',
22:'features.8.conv.1.0',
23:'features.8.conv.2',
24:'features.9.conv.0.0',
25:'features.9.conv.1.0',
26:'features.9.conv.2',
27:'features.10.conv.0.0',
28:'features.10.conv.1.0',
29:'features.10.conv.2',
30:'features.11.conv.0.0',
31:'features.11.conv.1.0',
32:'features.11.conv.2',
33:'features.12.conv.0.0',
34:'features.12.conv.1.0',
35:'features.12.conv.2',
36:'features.13.conv.0.0',
37:'features.13.conv.1.0',
38:'features.13.conv.2',
39:'features.14.conv.0.0',
40:'features.14.conv.1.0',
41:'features.14.conv.2',
42:'features.15.conv.0.0',
43:'features.15.conv.1.0',
44:'features.15.conv.2',
45:'features.16.conv.0.0',
46:'features.16.conv.1.0',
47:'features.16.conv.2',
48:'features.17.conv.0.0',
49:'features.17.conv.1.0',
50:'features.17.conv.2',
51:'features.18.0',
}


shape_layer[0] = (torch.Size([32, 27]), torch.Size([27, 12544]))
shape_layer[1] = (torch.Size([32, 9]), torch.Size([9, 401408]))
shape_layer[2] = (torch.Size([16, 32]), torch.Size([32, 12544]))
shape_layer[3] = (torch.Size([96, 16]), torch.Size([16, 12544]))
shape_layer[4] = (torch.Size([96, 9]), torch.Size([9, 301056]))
shape_layer[5] = (torch.Size([24, 96]), torch.Size([96, 3136]))
shape_layer[6] = (torch.Size([144, 24]), torch.Size([24, 3136]))
shape_layer[7] = (torch.Size([144, 9]), torch.Size([9, 451584]))
shape_layer[8] = (torch.Size([24, 144]), torch.Size([144, 3136]))
shape_layer[9] = (torch.Size([144, 24]), torch.Size([24, 3136]))
shape_layer[10] = (torch.Size([144, 9]), torch.Size([9, 112896]))
shape_layer[11] = (torch.Size([32, 144]), torch.Size([144, 784]))
shape_layer[12] = (torch.Size([192, 32]), torch.Size([32, 784]))
shape_layer[13] = (torch.Size([192, 9]), torch.Size([9, 150528]))
shape_layer[14] = (torch.Size([32, 192]), torch.Size([192, 784]))
shape_layer[15] = (torch.Size([192, 32]), torch.Size([32, 784]))
shape_layer[16] = (torch.Size([192, 9]), torch.Size([9, 150528]))
shape_layer[17] = (torch.Size([32, 192]), torch.Size([192, 784]))
shape_layer[18] = (torch.Size([192, 32]), torch.Size([32, 784]))
shape_layer[19] = (torch.Size([192, 9]), torch.Size([9, 37632]))
shape_layer[20] = (torch.Size([64, 192]), torch.Size([192, 196]))
shape_layer[21] = (torch.Size([384, 64]), torch.Size([64, 196]))
shape_layer[22] = (torch.Size([384, 9]), torch.Size([9, 75264]))
shape_layer[23] = (torch.Size([64, 384]), torch.Size([384, 196]))
shape_layer[24] = (torch.Size([384, 64]), torch.Size([64, 196]))
shape_layer[25] = (torch.Size([384, 9]), torch.Size([9, 75264]))
shape_layer[26] = (torch.Size([64, 384]), torch.Size([384, 196]))
shape_layer[27] = (torch.Size([384, 64]), torch.Size([64, 196]))
shape_layer[28] = (torch.Size([384, 9]), torch.Size([9, 75264]))
shape_layer[29] = (torch.Size([64, 384]), torch.Size([384, 196]))
shape_layer[30] = (torch.Size([384, 64]), torch.Size([64, 196]))
shape_layer[31] = (torch.Size([384, 9]), torch.Size([9, 75264]))
shape_layer[32] = (torch.Size([96, 384]), torch.Size([384, 196]))
shape_layer[33] = (torch.Size([576, 96]), torch.Size([96, 196]))
shape_layer[34] = (torch.Size([576, 9]), torch.Size([9, 112896]))
shape_layer[35] = (torch.Size([96, 576]), torch.Size([576, 196]))
shape_layer[36] = (torch.Size([576, 96]), torch.Size([96, 196]))
shape_layer[37] = (torch.Size([576, 9]), torch.Size([9, 112896]))
shape_layer[38] = (torch.Size([96, 576]), torch.Size([576, 196]))
shape_layer[39] = (torch.Size([576, 96]), torch.Size([96, 196]))
shape_layer[40] = (torch.Size([576, 9]), torch.Size([9, 28224]))
shape_layer[41] = (torch.Size([160, 576]), torch.Size([576, 49]))
shape_layer[42] = (torch.Size([960, 160]), torch.Size([160, 49]))
shape_layer[43] = (torch.Size([960, 9]), torch.Size([9, 47040]))
shape_layer[44] = (torch.Size([160, 960]), torch.Size([960, 49]))
shape_layer[45] = (torch.Size([960, 160]), torch.Size([160, 49]))
shape_layer[46] = (torch.Size([960, 9]), torch.Size([9, 47040]))
shape_layer[47] = (torch.Size([160, 960]), torch.Size([960, 49]))
shape_layer[48] = (torch.Size([960, 160]), torch.Size([160, 49]))
shape_layer[49] = (torch.Size([960, 9]), torch.Size([9, 47040]))
shape_layer[50] = (torch.Size([320, 960]), torch.Size([960, 49]))
shape_layer[51] = (torch.Size([1280, 320]), torch.Size([320, 49]))


# (N, C, H, W)

shape_layer_sw[0] = (torch.Size([32, 3, 3, 3]), torch.Size([1, 3, 224, 224]))
shape_layer_sw[1] = (torch.Size([32, 1, 3, 3]), torch.Size([1, 32, 112, 112]))
shape_layer_sw[2] = (torch.Size([16, 32, 1, 1]), torch.Size([1, 32, 112, 112]))
shape_layer_sw[3] = (torch.Size([96, 16, 1, 1]), torch.Size([1, 16, 112, 112]))
shape_layer_sw[4] = (torch.Size([96, 1, 3, 3]), torch.Size([1, 96, 112, 112]))
shape_layer_sw[5] = (torch.Size([24, 96, 1, 1]), torch.Size([1, 96, 56, 56]))
shape_layer_sw[6] = (torch.Size([144, 24, 1, 1]), torch.Size([1, 24, 56, 56]))
shape_layer_sw[7] = (torch.Size([144, 1, 3, 3]), torch.Size([1, 144, 56, 56]))
shape_layer_sw[8] = (torch.Size([24, 144, 1, 1]), torch.Size([1, 144, 56, 56]))
shape_layer_sw[9] = (torch.Size([144, 24, 1, 1]), torch.Size([1, 24, 56, 56]))
shape_layer_sw[10] = (torch.Size([144, 1, 3, 3]), torch.Size([1, 144, 56, 56]))
shape_layer_sw[11] = (torch.Size([32, 144, 1, 1]), torch.Size([1, 144, 28, 28]))
shape_layer_sw[12] = (torch.Size([192, 32, 1, 1]), torch.Size([1, 32, 28, 28]))
shape_layer_sw[13] = (torch.Size([192, 1, 3, 3]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[14] = (torch.Size([32, 192, 1, 1]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[15] = (torch.Size([192, 32, 1, 1]), torch.Size([1, 32, 28, 28]))
shape_layer_sw[16] = (torch.Size([192, 1, 3, 3]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[17] = (torch.Size([32, 192, 1, 1]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[18] = (torch.Size([192, 32, 1, 1]), torch.Size([1, 32, 28, 28]))
shape_layer_sw[19] = (torch.Size([192, 1, 3, 3]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[20] = (torch.Size([64, 192, 1, 1]), torch.Size([1, 192, 14, 14]))
shape_layer_sw[21] = (torch.Size([384, 64, 1, 1]), torch.Size([1, 64, 14, 14]))
shape_layer_sw[22] = (torch.Size([384, 1, 3, 3]), torch.Size([1, 384, 14, 14]))
shape_layer_sw[23] = (torch.Size([64, 384, 1, 1]), torch.Size([1, 384, 14, 14]))
shape_layer_sw[24] = (torch.Size([384, 64, 1, 1]), torch.Size([1, 64, 14, 14]))
shape_layer_sw[25] = (torch.Size([384, 1, 3, 3]), torch.Size([1, 384, 14, 14]))
shape_layer_sw[26] = (torch.Size([64, 384, 1, 1]), torch.Size([1, 384, 14, 14]))
shape_layer_sw[27] = (torch.Size([384, 64, 1, 1]), torch.Size([1, 64, 14, 14]))
shape_layer_sw[28] = (torch.Size([384, 1, 3, 3]), torch.Size([1, 384, 14, 14]))
shape_layer_sw[29] = (torch.Size([64, 384, 1, 1]), torch.Size([1, 384, 14, 14]))
shape_layer_sw[30] = (torch.Size([384, 64, 1, 1]), torch.Size([1, 64, 14, 14]))
shape_layer_sw[31] = (torch.Size([384, 1, 3, 3]), torch.Size([1, 384, 14, 14]))
shape_layer_sw[32] = (torch.Size([96, 384, 1, 1]), torch.Size([1, 384, 14, 14]))
shape_layer_sw[33] = (torch.Size([576, 96, 1, 1]), torch.Size([1, 96, 14, 14]))
shape_layer_sw[34] = (torch.Size([576, 1, 3, 3]), torch.Size([1, 576, 14, 14]))
shape_layer_sw[35] = (torch.Size([96, 576, 1, 1]), torch.Size([1, 576, 14, 14]))
shape_layer_sw[36] = (torch.Size([576, 96, 1, 1]), torch.Size([1, 96, 14, 14]))
shape_layer_sw[37] = (torch.Size([576, 1, 3, 3]), torch.Size([1, 576, 14, 14]))
shape_layer_sw[38] = (torch.Size([96, 576, 1, 1]), torch.Size([1, 576, 14, 14]))
shape_layer_sw[39] = (torch.Size([576, 96, 1, 1]), torch.Size([1, 96, 14, 14]))
shape_layer_sw[40] = (torch.Size([576, 1, 3, 3]), torch.Size([1, 576, 14, 14]))
shape_layer_sw[41] = (torch.Size([160, 576, 1, 1]), torch.Size([1, 576, 7, 7]))
shape_layer_sw[42] = (torch.Size([960, 160, 1, 1]), torch.Size([1, 160, 7, 7]))
shape_layer_sw[43] = (torch.Size([960, 1, 3, 3]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[44] = (torch.Size([160, 960, 1, 1]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[45] = (torch.Size([960, 160, 1, 1]), torch.Size([1, 160, 7, 7]))
shape_layer_sw[46] = (torch.Size([960, 1, 3, 3]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[47] = (torch.Size([160, 960, 1, 1]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[48] = (torch.Size([960, 160, 1, 1]), torch.Size([1, 160, 7, 7]))
shape_layer_sw[49] = (torch.Size([960, 1, 3, 3]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[50] = (torch.Size([320, 960, 1, 1]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[51] = (torch.Size([1280, 320, 1, 1]), torch.Size([1, 320, 7, 7]))
