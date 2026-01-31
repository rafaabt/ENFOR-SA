import torch
import numpy

N_LAYERS = 57


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

conv_layers_names={
0:'conv1.conv',
1:'conv2.conv',
2:'conv3.conv',
3:'inception3a.branch1.conv',
4:'inception3a.branch2.0.conv',
5:'inception3a.branch2.1.conv',
6:'inception3a.branch3.0.conv',
7:'inception3a.branch3.1.conv',
8:'inception3a.branch4.1.conv',
9:'inception3b.branch1.conv',
10:'inception3b.branch2.0.conv',
11:'inception3b.branch2.1.conv',
12:'inception3b.branch3.0.conv',
13:'inception3b.branch3.1.conv',
14:'inception3b.branch4.1.conv',
15:'inception4a.branch1.conv',
16:'inception4a.branch2.0.conv',
17:'inception4a.branch2.1.conv',
18:'inception4a.branch3.0.conv',
19:'inception4a.branch3.1.conv',
20:'inception4a.branch4.1.conv',
21:'inception4b.branch1.conv',
22:'inception4b.branch2.0.conv',
23:'inception4b.branch2.1.conv',
24:'inception4b.branch3.0.conv',
25:'inception4b.branch3.1.conv',
26:'inception4b.branch4.1.conv',
27:'inception4c.branch1.conv',
28:'inception4c.branch2.0.conv',
29:'inception4c.branch2.1.conv',
30:'inception4c.branch3.0.conv',
31:'inception4c.branch3.1.conv',
32:'inception4c.branch4.1.conv',
33:'inception4d.branch1.conv',
34:'inception4d.branch2.0.conv',
35:'inception4d.branch2.1.conv',
36:'inception4d.branch3.0.conv',
37:'inception4d.branch3.1.conv',
38:'inception4d.branch4.1.conv',
39:'inception4e.branch1.conv',
40:'inception4e.branch2.0.conv',
41:'inception4e.branch2.1.conv',
42:'inception4e.branch3.0.conv',
43:'inception4e.branch3.1.conv',
44:'inception4e.branch4.1.conv',
45:'inception5a.branch1.conv',
46:'inception5a.branch2.0.conv',
47:'inception5a.branch2.1.conv',
48:'inception5a.branch3.0.conv',
49:'inception5a.branch3.1.conv',
50:'inception5a.branch4.1.conv',
51:'inception5b.branch1.conv',
52:'inception5b.branch2.0.conv',
53:'inception5b.branch2.1.conv',
54:'inception5b.branch3.0.conv',
55:'inception5b.branch3.1.conv',
56:'inception5b.branch4.1.conv',
}

shape_layer[0] = (torch.Size([64, 147]), torch.Size([147, 12544]))
shape_layer[1] = (torch.Size([64, 64]), torch.Size([64, 3136]))
shape_layer[2] = (torch.Size([192, 576]), torch.Size([576, 3136]))
shape_layer[3] = (torch.Size([64, 192]), torch.Size([192, 784]))
shape_layer[4] = (torch.Size([96, 192]), torch.Size([192, 784]))
shape_layer[5] = (torch.Size([128, 864]), torch.Size([864, 784]))
shape_layer[6] = (torch.Size([16, 192]), torch.Size([192, 784]))
shape_layer[7] = (torch.Size([32, 144]), torch.Size([144, 784]))
shape_layer[8] = (torch.Size([32, 192]), torch.Size([192, 784]))
shape_layer[9] = (torch.Size([128, 256]), torch.Size([256, 784]))
shape_layer[10] = (torch.Size([128, 256]), torch.Size([256, 784]))
shape_layer[11] = (torch.Size([192, 1152]), torch.Size([1152, 784]))
shape_layer[12] = (torch.Size([32, 256]), torch.Size([256, 784]))
shape_layer[13] = (torch.Size([96, 288]), torch.Size([288, 784]))
shape_layer[14] = (torch.Size([64, 256]), torch.Size([256, 784]))
shape_layer[15] = (torch.Size([192, 480]), torch.Size([480, 196]))
shape_layer[16] = (torch.Size([96, 480]), torch.Size([480, 196]))
shape_layer[17] = (torch.Size([208, 864]), torch.Size([864, 196]))
shape_layer[18] = (torch.Size([16, 480]), torch.Size([480, 196]))
shape_layer[19] = (torch.Size([48, 144]), torch.Size([144, 196]))
shape_layer[20] = (torch.Size([64, 480]), torch.Size([480, 196]))
shape_layer[21] = (torch.Size([160, 512]), torch.Size([512, 196]))
shape_layer[22] = (torch.Size([112, 512]), torch.Size([512, 196]))
shape_layer[23] = (torch.Size([224, 1008]), torch.Size([1008, 196]))
shape_layer[24] = (torch.Size([24, 512]), torch.Size([512, 196]))
shape_layer[25] = (torch.Size([64, 216]), torch.Size([216, 196]))
shape_layer[26] = (torch.Size([64, 512]), torch.Size([512, 196]))
shape_layer[27] = (torch.Size([128, 512]), torch.Size([512, 196]))
shape_layer[28] = (torch.Size([128, 512]), torch.Size([512, 196]))
shape_layer[29] = (torch.Size([256, 1152]), torch.Size([1152, 196]))
shape_layer[30] = (torch.Size([24, 512]), torch.Size([512, 196]))
shape_layer[31] = (torch.Size([64, 216]), torch.Size([216, 196]))
shape_layer[32] = (torch.Size([64, 512]), torch.Size([512, 196]))
shape_layer[33] = (torch.Size([112, 512]), torch.Size([512, 196]))
shape_layer[34] = (torch.Size([144, 512]), torch.Size([512, 196]))
shape_layer[35] = (torch.Size([288, 1296]), torch.Size([1296, 196]))
shape_layer[36] = (torch.Size([32, 512]), torch.Size([512, 196]))
shape_layer[37] = (torch.Size([64, 288]), torch.Size([288, 196]))
shape_layer[38] = (torch.Size([64, 512]), torch.Size([512, 196]))
shape_layer[39] = (torch.Size([256, 528]), torch.Size([528, 196]))
shape_layer[40] = (torch.Size([160, 528]), torch.Size([528, 196]))
shape_layer[41] = (torch.Size([320, 1440]), torch.Size([1440, 196]))
shape_layer[42] = (torch.Size([32, 528]), torch.Size([528, 196]))
shape_layer[43] = (torch.Size([128, 288]), torch.Size([288, 196]))
shape_layer[44] = (torch.Size([128, 528]), torch.Size([528, 196]))
shape_layer[45] = (torch.Size([256, 832]), torch.Size([832, 49]))
shape_layer[46] = (torch.Size([160, 832]), torch.Size([832, 49]))
shape_layer[47] = (torch.Size([320, 1440]), torch.Size([1440, 49]))
shape_layer[48] = (torch.Size([32, 832]), torch.Size([832, 49]))
shape_layer[49] = (torch.Size([128, 288]), torch.Size([288, 49]))
shape_layer[50] = (torch.Size([128, 832]), torch.Size([832, 49]))
shape_layer[51] = (torch.Size([384, 832]), torch.Size([832, 49]))
shape_layer[52] = (torch.Size([192, 832]), torch.Size([832, 49]))
shape_layer[53] = (torch.Size([384, 1728]), torch.Size([1728, 49]))
shape_layer[54] = (torch.Size([48, 832]), torch.Size([832, 49]))
shape_layer[55] = (torch.Size([128, 432]), torch.Size([432, 49]))
shape_layer[56] = (torch.Size([128, 832]), torch.Size([832, 49]))


shape_layer_sw[0] = (torch.Size([64, 3, 7, 7]), torch.Size([1, 3, 224, 224]))
shape_layer_sw[1] = (torch.Size([64, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[2] = (torch.Size([192, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[3] = (torch.Size([64, 192, 1, 1]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[4] = (torch.Size([96, 192, 1, 1]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[5] = (torch.Size([128, 96, 3, 3]), torch.Size([1, 96, 28, 28]))
shape_layer_sw[6] = (torch.Size([16, 192, 1, 1]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[7] = (torch.Size([32, 16, 3, 3]), torch.Size([1, 16, 28, 28]))
shape_layer_sw[8] = (torch.Size([32, 192, 1, 1]), torch.Size([1, 192, 28, 28]))
shape_layer_sw[9] = (torch.Size([128, 256, 1, 1]), torch.Size([1, 256, 28, 28]))
shape_layer_sw[10] = (torch.Size([128, 256, 1, 1]), torch.Size([1, 256, 28, 28]))
shape_layer_sw[11] = (torch.Size([192, 128, 3, 3]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[12] = (torch.Size([32, 256, 1, 1]), torch.Size([1, 256, 28, 28]))
shape_layer_sw[13] = (torch.Size([96, 32, 3, 3]), torch.Size([1, 32, 28, 28]))
shape_layer_sw[14] = (torch.Size([64, 256, 1, 1]), torch.Size([1, 256, 28, 28]))
shape_layer_sw[15] = (torch.Size([192, 480, 1, 1]), torch.Size([1, 480, 14, 14]))
shape_layer_sw[16] = (torch.Size([96, 480, 1, 1]), torch.Size([1, 480, 14, 14]))
shape_layer_sw[17] = (torch.Size([208, 96, 3, 3]), torch.Size([1, 96, 14, 14]))
shape_layer_sw[18] = (torch.Size([16, 480, 1, 1]), torch.Size([1, 480, 14, 14]))
shape_layer_sw[19] = (torch.Size([48, 16, 3, 3]), torch.Size([1, 16, 14, 14]))
shape_layer_sw[20] = (torch.Size([64, 480, 1, 1]), torch.Size([1, 480, 14, 14]))
shape_layer_sw[21] = (torch.Size([160, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[22] = (torch.Size([112, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[23] = (torch.Size([224, 112, 3, 3]), torch.Size([1, 112, 14, 14]))
shape_layer_sw[24] = (torch.Size([24, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[25] = (torch.Size([64, 24, 3, 3]), torch.Size([1, 24, 14, 14]))
shape_layer_sw[26] = (torch.Size([64, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[27] = (torch.Size([128, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[28] = (torch.Size([128, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[29] = (torch.Size([256, 128, 3, 3]), torch.Size([1, 128, 14, 14]))
shape_layer_sw[30] = (torch.Size([24, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[31] = (torch.Size([64, 24, 3, 3]), torch.Size([1, 24, 14, 14]))
shape_layer_sw[32] = (torch.Size([64, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[33] = (torch.Size([112, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[34] = (torch.Size([144, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[35] = (torch.Size([288, 144, 3, 3]), torch.Size([1, 144, 14, 14]))
shape_layer_sw[36] = (torch.Size([32, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[37] = (torch.Size([64, 32, 3, 3]), torch.Size([1, 32, 14, 14]))
shape_layer_sw[38] = (torch.Size([64, 512, 1, 1]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[39] = (torch.Size([256, 528, 1, 1]), torch.Size([1, 528, 14, 14]))
shape_layer_sw[40] = (torch.Size([160, 528, 1, 1]), torch.Size([1, 528, 14, 14]))
shape_layer_sw[41] = (torch.Size([320, 160, 3, 3]), torch.Size([1, 160, 14, 14]))
shape_layer_sw[42] = (torch.Size([32, 528, 1, 1]), torch.Size([1, 528, 14, 14]))
shape_layer_sw[43] = (torch.Size([128, 32, 3, 3]), torch.Size([1, 32, 14, 14]))
shape_layer_sw[44] = (torch.Size([128, 528, 1, 1]), torch.Size([1, 528, 14, 14]))
shape_layer_sw[45] = (torch.Size([256, 832, 1, 1]), torch.Size([1, 832, 7, 7]))
shape_layer_sw[46] = (torch.Size([160, 832, 1, 1]), torch.Size([1, 832, 7, 7]))
shape_layer_sw[47] = (torch.Size([320, 160, 3, 3]), torch.Size([1, 160, 7, 7]))
shape_layer_sw[48] = (torch.Size([32, 832, 1, 1]), torch.Size([1, 832, 7, 7]))
shape_layer_sw[49] = (torch.Size([128, 32, 3, 3]), torch.Size([1, 32, 7, 7]))
shape_layer_sw[50] = (torch.Size([128, 832, 1, 1]), torch.Size([1, 832, 7, 7]))
shape_layer_sw[51] = (torch.Size([384, 832, 1, 1]), torch.Size([1, 832, 7, 7]))
shape_layer_sw[52] = (torch.Size([192, 832, 1, 1]), torch.Size([1, 832, 7, 7]))
shape_layer_sw[53] = (torch.Size([384, 192, 3, 3]), torch.Size([1, 192, 7, 7]))
shape_layer_sw[54] = (torch.Size([48, 832, 1, 1]), torch.Size([1, 832, 7, 7]))
shape_layer_sw[55] = (torch.Size([128, 48, 3, 3]), torch.Size([1, 48, 7, 7]))
shape_layer_sw[56] = (torch.Size([128, 832, 1, 1]), torch.Size([1, 832, 7, 7]))