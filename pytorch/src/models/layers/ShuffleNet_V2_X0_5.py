import torch
import numpy

N_LAYERS = 56


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

conv_layers_names={
0:'conv1.0',
1:'stage2.0.branch1.0',
2:'stage2.0.branch1.2',
3:'stage2.0.branch2.0',
4:'stage2.0.branch2.3',
5:'stage2.0.branch2.5',
6:'stage2.1.branch2.0',
7:'stage2.1.branch2.3',
8:'stage2.1.branch2.5',
9:'stage2.2.branch2.0',
10:'stage2.2.branch2.3',
11:'stage2.2.branch2.5',
12:'stage2.3.branch2.0',
13:'stage2.3.branch2.3',
14:'stage2.3.branch2.5',
15:'stage3.0.branch1.0',
16:'stage3.0.branch1.2',
17:'stage3.0.branch2.0',
18:'stage3.0.branch2.3',
19:'stage3.0.branch2.5',
20:'stage3.1.branch2.0',
21:'stage3.1.branch2.3',
22:'stage3.1.branch2.5',
23:'stage3.2.branch2.0',
24:'stage3.2.branch2.3',
25:'stage3.2.branch2.5',
26:'stage3.3.branch2.0',
27:'stage3.3.branch2.3',
28:'stage3.3.branch2.5',
29:'stage3.4.branch2.0',
30:'stage3.4.branch2.3',
31:'stage3.4.branch2.5',
32:'stage3.5.branch2.0',
33:'stage3.5.branch2.3',
34:'stage3.5.branch2.5',
35:'stage3.6.branch2.0',
36:'stage3.6.branch2.3',
37:'stage3.6.branch2.5',
38:'stage3.7.branch2.0',
39:'stage3.7.branch2.3',
40:'stage3.7.branch2.5',
41:'stage4.0.branch1.0',
42:'stage4.0.branch1.2',
43:'stage4.0.branch2.0',
44:'stage4.0.branch2.3',
45:'stage4.0.branch2.5',
46:'stage4.1.branch2.0',
47:'stage4.1.branch2.3',
48:'stage4.1.branch2.5',
49:'stage4.2.branch2.0',
50:'stage4.2.branch2.3',
51:'stage4.2.branch2.5',
52:'stage4.3.branch2.0',
53:'stage4.3.branch2.3',
54:'stage4.3.branch2.5',
55:'conv5.0',
}


shape_layer[0] = (torch.Size([24, 27]), torch.Size([27, 12544]))
shape_layer[1] = (torch.Size([24, 9]), torch.Size([9, 18816]))
shape_layer[2] = (torch.Size([24, 24]), torch.Size([24, 784]))
shape_layer[3] = (torch.Size([24, 24]), torch.Size([24, 3136]))
shape_layer[4] = (torch.Size([24, 9]), torch.Size([9, 18816]))
shape_layer[5] = (torch.Size([24, 24]), torch.Size([24, 784]))
shape_layer[6] = (torch.Size([24, 24]), torch.Size([24, 784]))
shape_layer[7] = (torch.Size([24, 9]), torch.Size([9, 18816]))
shape_layer[8] = (torch.Size([24, 24]), torch.Size([24, 784]))
shape_layer[9] = (torch.Size([24, 24]), torch.Size([24, 784]))
shape_layer[10] = (torch.Size([24, 9]), torch.Size([9, 18816]))
shape_layer[11] = (torch.Size([24, 24]), torch.Size([24, 784]))
shape_layer[12] = (torch.Size([24, 24]), torch.Size([24, 784]))
shape_layer[13] = (torch.Size([24, 9]), torch.Size([9, 18816]))
shape_layer[14] = (torch.Size([24, 24]), torch.Size([24, 784]))
shape_layer[15] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[16] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[17] = (torch.Size([48, 48]), torch.Size([48, 784]))
shape_layer[18] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[19] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[20] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[21] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[22] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[23] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[24] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[25] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[26] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[27] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[28] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[29] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[30] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[31] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[32] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[33] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[34] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[35] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[36] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[37] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[38] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[39] = (torch.Size([48, 9]), torch.Size([9, 9408]))
shape_layer[40] = (torch.Size([48, 48]), torch.Size([48, 196]))
shape_layer[41] = (torch.Size([96, 9]), torch.Size([9, 4704]))
shape_layer[42] = (torch.Size([96, 96]), torch.Size([96, 49]))
shape_layer[43] = (torch.Size([96, 96]), torch.Size([96, 196]))
shape_layer[44] = (torch.Size([96, 9]), torch.Size([9, 4704]))
shape_layer[45] = (torch.Size([96, 96]), torch.Size([96, 49]))
shape_layer[46] = (torch.Size([96, 96]), torch.Size([96, 49]))
shape_layer[47] = (torch.Size([96, 9]), torch.Size([9, 4704]))
shape_layer[48] = (torch.Size([96, 96]), torch.Size([96, 49]))
shape_layer[49] = (torch.Size([96, 96]), torch.Size([96, 49]))
shape_layer[50] = (torch.Size([96, 9]), torch.Size([9, 4704]))
shape_layer[51] = (torch.Size([96, 96]), torch.Size([96, 49]))
shape_layer[52] = (torch.Size([96, 96]), torch.Size([96, 49]))
shape_layer[53] = (torch.Size([96, 9]), torch.Size([9, 4704]))
shape_layer[54] = (torch.Size([96, 96]), torch.Size([96, 49]))
shape_layer[55] = (torch.Size([1024, 192]), torch.Size([192, 49]))


shape_layer_sw[0] = (torch.Size([24, 3, 3, 3]), torch.Size([1, 3, 224, 224]))
shape_layer_sw[1] = (torch.Size([24, 1, 3, 3]), torch.Size([1, 24, 56, 56]))
shape_layer_sw[2] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[3] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 56, 56]))
shape_layer_sw[4] = (torch.Size([24, 1, 3, 3]), torch.Size([1, 24, 56, 56]))
shape_layer_sw[5] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[6] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[7] = (torch.Size([24, 1, 3, 3]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[8] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[9] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[10] = (torch.Size([24, 1, 3, 3]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[11] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[12] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[13] = (torch.Size([24, 1, 3, 3]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[14] = (torch.Size([24, 24, 1, 1]), torch.Size([1, 24, 28, 28]))
shape_layer_sw[15] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 28, 28]))
shape_layer_sw[16] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[17] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 28, 28]))
shape_layer_sw[18] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 28, 28]))
shape_layer_sw[19] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[20] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[21] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[22] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[23] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[24] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[25] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[26] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[27] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[28] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[29] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[30] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[31] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[32] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[33] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[34] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[35] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[36] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[37] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[38] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[39] = (torch.Size([48, 1, 3, 3]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[40] = (torch.Size([48, 48, 1, 1]), torch.Size([1, 48, 14, 14]))
shape_layer_sw[41] = (torch.Size([96, 1, 3, 3]), torch.Size([1, 96, 14, 14]))
shape_layer_sw[42] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[43] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 14, 14]))
shape_layer_sw[44] = (torch.Size([96, 1, 3, 3]), torch.Size([1, 96, 14, 14]))
shape_layer_sw[45] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[46] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[47] = (torch.Size([96, 1, 3, 3]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[48] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[49] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[50] = (torch.Size([96, 1, 3, 3]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[51] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[52] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[53] = (torch.Size([96, 1, 3, 3]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[54] = (torch.Size([96, 96, 1, 1]), torch.Size([1, 96, 7, 7]))
shape_layer_sw[55] = (torch.Size([1024, 192, 1, 1]), torch.Size([1, 192, 7, 7]))
