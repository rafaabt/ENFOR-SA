import torch
import numpy

N_LAYERS = 62


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

conv_layers_names={
0:'features.0.0',
1:'features.1.block.0.0',
2:'features.1.block.1.0',
3:'features.2.block.0.0',
4:'features.2.block.1.0',
5:'features.2.block.2.0',
6:'features.3.block.0.0',
7:'features.3.block.1.0',
8:'features.3.block.2.0',
9:'features.4.block.0.0',
10:'features.4.block.1.0',
11:'features.4.block.2.fc1',
12:'features.4.block.2.fc2',
13:'features.4.block.3.0',
14:'features.5.block.0.0',
15:'features.5.block.1.0',
16:'features.5.block.2.fc1',
17:'features.5.block.2.fc2',
18:'features.5.block.3.0',
19:'features.6.block.0.0',
20:'features.6.block.1.0',
21:'features.6.block.2.fc1',
22:'features.6.block.2.fc2',
23:'features.6.block.3.0',
24:'features.7.block.0.0',
25:'features.7.block.1.0',
26:'features.7.block.2.0',
27:'features.8.block.0.0',
28:'features.8.block.1.0',
29:'features.8.block.2.0',
30:'features.9.block.0.0',
31:'features.9.block.1.0',
32:'features.9.block.2.0',
33:'features.10.block.0.0',
34:'features.10.block.1.0',
35:'features.10.block.2.0',
36:'features.11.block.0.0',
37:'features.11.block.1.0',
38:'features.11.block.2.fc1',
39:'features.11.block.2.fc2',
40:'features.11.block.3.0',
41:'features.12.block.0.0',
42:'features.12.block.1.0',
43:'features.12.block.2.fc1',
44:'features.12.block.2.fc2',
45:'features.12.block.3.0',
46:'features.13.block.0.0',
47:'features.13.block.1.0',
48:'features.13.block.2.fc1',
49:'features.13.block.2.fc2',
50:'features.13.block.3.0',
51:'features.14.block.0.0',
52:'features.14.block.1.0',
53:'features.14.block.2.fc1',
54:'features.14.block.2.fc2',
55:'features.14.block.3.0',
56:'features.15.block.0.0',
57:'features.15.block.1.0',
58:'features.15.block.2.fc1',
59:'features.15.block.2.fc2',
60:'features.15.block.3.0',
61:'features.16.0',
}

shape_layer[0] = (torch.Size([16, 27]), torch.Size([27, 12544]))
shape_layer[1] = (torch.Size([16, 9]), torch.Size([9, 200704]))
shape_layer[2] = (torch.Size([16, 16]), torch.Size([16, 12544]))
shape_layer[3] = (torch.Size([64, 16]), torch.Size([16, 12544]))
shape_layer[4] = (torch.Size([64, 9]), torch.Size([9, 200704]))
shape_layer[5] = (torch.Size([24, 64]), torch.Size([64, 3136]))
shape_layer[6] = (torch.Size([72, 24]), torch.Size([24, 3136]))
shape_layer[7] = (torch.Size([72, 9]), torch.Size([9, 225792]))
shape_layer[8] = (torch.Size([24, 72]), torch.Size([72, 3136]))
shape_layer[9] = (torch.Size([72, 24]), torch.Size([24, 3136]))
shape_layer[10] = (torch.Size([72, 25]), torch.Size([25, 56448]))
shape_layer[11] = (torch.Size([24, 72]), torch.Size([72, 1]))
shape_layer[12] = (torch.Size([72, 24]), torch.Size([24, 1]))
shape_layer[13] = (torch.Size([40, 72]), torch.Size([72, 784]))
shape_layer[14] = (torch.Size([120, 40]), torch.Size([40, 784]))
shape_layer[15] = (torch.Size([120, 25]), torch.Size([25, 94080]))
shape_layer[16] = (torch.Size([32, 120]), torch.Size([120, 1]))
shape_layer[17] = (torch.Size([120, 32]), torch.Size([32, 1]))
shape_layer[18] = (torch.Size([40, 120]), torch.Size([120, 784]))
shape_layer[19] = (torch.Size([120, 40]), torch.Size([40, 784]))
shape_layer[20] = (torch.Size([120, 25]), torch.Size([25, 94080]))
shape_layer[21] = (torch.Size([32, 120]), torch.Size([120, 1]))
shape_layer[22] = (torch.Size([120, 32]), torch.Size([32, 1]))
shape_layer[23] = (torch.Size([40, 120]), torch.Size([120, 784]))
shape_layer[24] = (torch.Size([240, 40]), torch.Size([40, 784]))
shape_layer[25] = (torch.Size([240, 9]), torch.Size([9, 47040]))
shape_layer[26] = (torch.Size([80, 240]), torch.Size([240, 196]))
shape_layer[27] = (torch.Size([200, 80]), torch.Size([80, 196]))
shape_layer[28] = (torch.Size([200, 9]), torch.Size([9, 39200]))
shape_layer[29] = (torch.Size([80, 200]), torch.Size([200, 196]))
shape_layer[30] = (torch.Size([184, 80]), torch.Size([80, 196]))
shape_layer[31] = (torch.Size([184, 9]), torch.Size([9, 36064]))
shape_layer[32] = (torch.Size([80, 184]), torch.Size([184, 196]))
shape_layer[33] = (torch.Size([184, 80]), torch.Size([80, 196]))
shape_layer[34] = (torch.Size([184, 9]), torch.Size([9, 36064]))
shape_layer[35] = (torch.Size([80, 184]), torch.Size([184, 196]))
shape_layer[36] = (torch.Size([480, 80]), torch.Size([80, 196]))
shape_layer[37] = (torch.Size([480, 9]), torch.Size([9, 94080]))
shape_layer[38] = (torch.Size([120, 480]), torch.Size([480, 1]))
shape_layer[39] = (torch.Size([480, 120]), torch.Size([120, 1]))
shape_layer[40] = (torch.Size([112, 480]), torch.Size([480, 196]))
shape_layer[41] = (torch.Size([672, 112]), torch.Size([112, 196]))
shape_layer[42] = (torch.Size([672, 9]), torch.Size([9, 131712]))
shape_layer[43] = (torch.Size([168, 672]), torch.Size([672, 1]))
shape_layer[44] = (torch.Size([672, 168]), torch.Size([168, 1]))
shape_layer[45] = (torch.Size([112, 672]), torch.Size([672, 196]))
shape_layer[46] = (torch.Size([672, 112]), torch.Size([112, 196]))
shape_layer[47] = (torch.Size([672, 25]), torch.Size([25, 32928]))
shape_layer[48] = (torch.Size([168, 672]), torch.Size([672, 1]))
shape_layer[49] = (torch.Size([672, 168]), torch.Size([168, 1]))
shape_layer[50] = (torch.Size([160, 672]), torch.Size([672, 49]))
shape_layer[51] = (torch.Size([960, 160]), torch.Size([160, 49]))
shape_layer[52] = (torch.Size([960, 25]), torch.Size([25, 47040]))
shape_layer[53] = (torch.Size([240, 960]), torch.Size([960, 1]))
shape_layer[54] = (torch.Size([960, 240]), torch.Size([240, 1]))
shape_layer[55] = (torch.Size([160, 960]), torch.Size([960, 49]))
shape_layer[56] = (torch.Size([960, 160]), torch.Size([160, 49]))
shape_layer[57] = (torch.Size([960, 25]), torch.Size([25, 47040]))
shape_layer[58] = (torch.Size([240, 960]), torch.Size([960, 1]))
shape_layer[59] = (torch.Size([960, 240]), torch.Size([240, 1]))
shape_layer[60] = (torch.Size([160, 960]), torch.Size([960, 49]))
shape_layer[61] = (torch.Size([960, 160]), torch.Size([160, 49]))


shape_layer_sw[0] = (torch.Size([16, 3, 3, 3]), torch.Size([1, 3, 224, 224]))
shape_layer_sw[1] = (torch.Size([16, 1, 3, 3]), torch.Size([1, 16, 112, 112]))
shape_layer_sw[2] = (torch.Size([16, 16, 1, 1]), torch.Size([1, 16, 112, 112]))
shape_layer_sw[3] = (torch.Size([64, 16, 1, 1]), torch.Size([1, 16, 112, 112]))
shape_layer_sw[4] = (torch.Size([64, 1, 3, 3]), torch.Size([1, 64, 112, 112]))
shape_layer_sw[5] = (torch.Size([24, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[6] = (torch.Size([72, 24, 1, 1]), torch.Size([1, 24, 56, 56]))
shape_layer_sw[7] = (torch.Size([72, 1, 3, 3]), torch.Size([1, 72, 56, 56]))
shape_layer_sw[8] = (torch.Size([24, 72, 1, 1]), torch.Size([1, 72, 56, 56]))
shape_layer_sw[9] = (torch.Size([72, 24, 1, 1]), torch.Size([1, 24, 56, 56]))
shape_layer_sw[10] = (torch.Size([72, 1, 5, 5]), torch.Size([1, 72, 56, 56]))
shape_layer_sw[11] = (torch.Size([24, 72, 1, 1]), torch.Size([1, 72, 1, 1]))
shape_layer_sw[12] = (torch.Size([72, 24, 1, 1]), torch.Size([1, 24, 1, 1]))
shape_layer_sw[13] = (torch.Size([40, 72, 1, 1]), torch.Size([1, 72, 28, 28]))
shape_layer_sw[14] = (torch.Size([120, 40, 1, 1]), torch.Size([1, 40, 28, 28]))
shape_layer_sw[15] = (torch.Size([120, 1, 5, 5]), torch.Size([1, 120, 28, 28]))
shape_layer_sw[16] = (torch.Size([32, 120, 1, 1]), torch.Size([1, 120, 1, 1]))
shape_layer_sw[17] = (torch.Size([120, 32, 1, 1]), torch.Size([1, 32, 1, 1]))
shape_layer_sw[18] = (torch.Size([40, 120, 1, 1]), torch.Size([1, 120, 28, 28]))
shape_layer_sw[19] = (torch.Size([120, 40, 1, 1]), torch.Size([1, 40, 28, 28]))
shape_layer_sw[20] = (torch.Size([120, 1, 5, 5]), torch.Size([1, 120, 28, 28]))
shape_layer_sw[21] = (torch.Size([32, 120, 1, 1]), torch.Size([1, 120, 1, 1]))
shape_layer_sw[22] = (torch.Size([120, 32, 1, 1]), torch.Size([1, 32, 1, 1]))
shape_layer_sw[23] = (torch.Size([40, 120, 1, 1]), torch.Size([1, 120, 28, 28]))
shape_layer_sw[24] = (torch.Size([240, 40, 1, 1]), torch.Size([1, 40, 28, 28]))
shape_layer_sw[25] = (torch.Size([240, 1, 3, 3]), torch.Size([1, 240, 28, 28]))
shape_layer_sw[26] = (torch.Size([80, 240, 1, 1]), torch.Size([1, 240, 14, 14]))
shape_layer_sw[27] = (torch.Size([200, 80, 1, 1]), torch.Size([1, 80, 14, 14]))
shape_layer_sw[28] = (torch.Size([200, 1, 3, 3]), torch.Size([1, 200, 14, 14]))
shape_layer_sw[29] = (torch.Size([80, 200, 1, 1]), torch.Size([1, 200, 14, 14]))
shape_layer_sw[30] = (torch.Size([184, 80, 1, 1]), torch.Size([1, 80, 14, 14]))
shape_layer_sw[31] = (torch.Size([184, 1, 3, 3]), torch.Size([1, 184, 14, 14]))
shape_layer_sw[32] = (torch.Size([80, 184, 1, 1]), torch.Size([1, 184, 14, 14]))
shape_layer_sw[33] = (torch.Size([184, 80, 1, 1]), torch.Size([1, 80, 14, 14]))
shape_layer_sw[34] = (torch.Size([184, 1, 3, 3]), torch.Size([1, 184, 14, 14]))
shape_layer_sw[35] = (torch.Size([80, 184, 1, 1]), torch.Size([1, 184, 14, 14]))
shape_layer_sw[36] = (torch.Size([480, 80, 1, 1]), torch.Size([1, 80, 14, 14]))
shape_layer_sw[37] = (torch.Size([480, 1, 3, 3]), torch.Size([1, 480, 14, 14]))
shape_layer_sw[38] = (torch.Size([120, 480, 1, 1]), torch.Size([1, 480, 1, 1]))
shape_layer_sw[39] = (torch.Size([480, 120, 1, 1]), torch.Size([1, 120, 1, 1]))
shape_layer_sw[40] = (torch.Size([112, 480, 1, 1]), torch.Size([1, 480, 14, 14]))
shape_layer_sw[41] = (torch.Size([672, 112, 1, 1]), torch.Size([1, 112, 14, 14]))
shape_layer_sw[42] = (torch.Size([672, 1, 3, 3]), torch.Size([1, 672, 14, 14]))
shape_layer_sw[43] = (torch.Size([168, 672, 1, 1]), torch.Size([1, 672, 1, 1]))
shape_layer_sw[44] = (torch.Size([672, 168, 1, 1]), torch.Size([1, 168, 1, 1]))
shape_layer_sw[45] = (torch.Size([112, 672, 1, 1]), torch.Size([1, 672, 14, 14]))
shape_layer_sw[46] = (torch.Size([672, 112, 1, 1]), torch.Size([1, 112, 14, 14]))
shape_layer_sw[47] = (torch.Size([672, 1, 5, 5]), torch.Size([1, 672, 14, 14]))
shape_layer_sw[48] = (torch.Size([168, 672, 1, 1]), torch.Size([1, 672, 1, 1]))
shape_layer_sw[49] = (torch.Size([672, 168, 1, 1]), torch.Size([1, 168, 1, 1]))
shape_layer_sw[50] = (torch.Size([160, 672, 1, 1]), torch.Size([1, 672, 7, 7]))
shape_layer_sw[51] = (torch.Size([960, 160, 1, 1]), torch.Size([1, 160, 7, 7]))
shape_layer_sw[52] = (torch.Size([960, 1, 5, 5]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[53] = (torch.Size([240, 960, 1, 1]), torch.Size([1, 960, 1, 1]))
shape_layer_sw[54] = (torch.Size([960, 240, 1, 1]), torch.Size([1, 240, 1, 1]))
shape_layer_sw[55] = (torch.Size([160, 960, 1, 1]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[56] = (torch.Size([960, 160, 1, 1]), torch.Size([1, 160, 7, 7]))
shape_layer_sw[57] = (torch.Size([960, 1, 5, 5]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[58] = (torch.Size([240, 960, 1, 1]), torch.Size([1, 960, 1, 1]))
shape_layer_sw[59] = (torch.Size([960, 240, 1, 1]), torch.Size([1, 240, 1, 1]))
shape_layer_sw[60] = (torch.Size([160, 960, 1, 1]), torch.Size([1, 960, 7, 7]))
shape_layer_sw[61] = (torch.Size([960, 160, 1, 1]), torch.Size([1, 160, 7, 7]))
