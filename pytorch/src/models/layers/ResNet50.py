import torch
import numpy


N_LAYERS = 53


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

conv_layers_names={
0:'conv1',
1:'layer1.0.conv1',
2:'layer1.0.conv2',
3:'layer1.0.conv3',
4:'layer1.0.downsample.0',
5:'layer1.1.conv1',
6:'layer1.1.conv2',
7:'layer1.1.conv3',
8:'layer1.2.conv1',
9:'layer1.2.conv2',
10:'layer1.2.conv3',
11:'layer2.0.conv1',
12:'layer2.0.conv2',
13:'layer2.0.conv3',
14:'layer2.0.downsample.0',
15:'layer2.1.conv1',
16:'layer2.1.conv2',
17:'layer2.1.conv3',
18:'layer2.2.conv1',
19:'layer2.2.conv2',
20:'layer2.2.conv3',
21:'layer2.3.conv1',
22:'layer2.3.conv2',
23:'layer2.3.conv3',
24:'layer3.0.conv1',
25:'layer3.0.conv2',
26:'layer3.0.conv3',
27:'layer3.0.downsample.0',
28:'layer3.1.conv1',
29:'layer3.1.conv2',
30:'layer3.1.conv3',
31:'layer3.2.conv1',
32:'layer3.2.conv2',
33:'layer3.2.conv3',
34:'layer3.3.conv1',
35:'layer3.3.conv2',
36:'layer3.3.conv3',
37:'layer3.4.conv1',
38:'layer3.4.conv2',
39:'layer3.4.conv3',
40:'layer3.5.conv1',
41:'layer3.5.conv2',
42:'layer3.5.conv3',
43:'layer4.0.conv1',
44:'layer4.0.conv2',
45:'layer4.0.conv3',
46:'layer4.0.downsample.0',
47:'layer4.1.conv1',
48:'layer4.1.conv2',
49:'layer4.1.conv3',
50:'layer4.2.conv1',
51:'layer4.2.conv2',
52:'layer4.2.conv3',
}


shape_layer[0] = (torch.Size([64, 147]), torch.Size([147, 12544]))
shape_layer[1] = (torch.Size([64, 64]), torch.Size([64, 3136]))
shape_layer[2] = (torch.Size([64, 576]), torch.Size([576, 3136]))
shape_layer[3] = (torch.Size([256, 64]), torch.Size([64, 3136]))
shape_layer[4] = (torch.Size([256, 64]), torch.Size([64, 3136]))
shape_layer[5] = (torch.Size([64, 256]), torch.Size([256, 3136]))
shape_layer[6] = (torch.Size([64, 576]), torch.Size([576, 3136]))
shape_layer[7] = (torch.Size([256, 64]), torch.Size([64, 3136]))
shape_layer[8] = (torch.Size([64, 256]), torch.Size([256, 3136]))
shape_layer[9] = (torch.Size([64, 576]), torch.Size([576, 3136]))
shape_layer[10] = (torch.Size([256, 64]), torch.Size([64, 3136]))
shape_layer[11] = (torch.Size([128, 256]), torch.Size([256, 3136]))
shape_layer[12] = (torch.Size([128, 1152]), torch.Size([1152, 784]))
shape_layer[13] = (torch.Size([512, 128]), torch.Size([128, 784]))
shape_layer[14] = (torch.Size([512, 256]), torch.Size([256, 784]))
shape_layer[15] = (torch.Size([128, 512]), torch.Size([512, 784]))
shape_layer[16] = (torch.Size([128, 1152]), torch.Size([1152, 784]))
shape_layer[17] = (torch.Size([512, 128]), torch.Size([128, 784]))
shape_layer[18] = (torch.Size([128, 512]), torch.Size([512, 784]))
shape_layer[19] = (torch.Size([128, 1152]), torch.Size([1152, 784]))
shape_layer[20] = (torch.Size([512, 128]), torch.Size([128, 784]))
shape_layer[21] = (torch.Size([128, 512]), torch.Size([512, 784]))
shape_layer[22] = (torch.Size([128, 1152]), torch.Size([1152, 784]))
shape_layer[23] = (torch.Size([512, 128]), torch.Size([128, 784]))
shape_layer[24] = (torch.Size([256, 512]), torch.Size([512, 784]))
shape_layer[25] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[26] = (torch.Size([1024, 256]), torch.Size([256, 196]))
shape_layer[27] = (torch.Size([1024, 512]), torch.Size([512, 196]))
shape_layer[28] = (torch.Size([256, 1024]), torch.Size([1024, 196]))
shape_layer[29] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[30] = (torch.Size([1024, 256]), torch.Size([256, 196]))
shape_layer[31] = (torch.Size([256, 1024]), torch.Size([1024, 196]))
shape_layer[32] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[33] = (torch.Size([1024, 256]), torch.Size([256, 196]))
shape_layer[34] = (torch.Size([256, 1024]), torch.Size([1024, 196]))
shape_layer[35] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[36] = (torch.Size([1024, 256]), torch.Size([256, 196]))
shape_layer[37] = (torch.Size([256, 1024]), torch.Size([1024, 196]))
shape_layer[38] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[39] = (torch.Size([1024, 256]), torch.Size([256, 196]))
shape_layer[40] = (torch.Size([256, 1024]), torch.Size([1024, 196]))
shape_layer[41] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[42] = (torch.Size([1024, 256]), torch.Size([256, 196]))
shape_layer[43] = (torch.Size([512, 1024]), torch.Size([1024, 196]))
shape_layer[44] = (torch.Size([512, 4608]), torch.Size([4608, 49]))
shape_layer[45] = (torch.Size([2048, 512]), torch.Size([512, 49]))
shape_layer[46] = (torch.Size([2048, 1024]), torch.Size([1024, 49]))
shape_layer[47] = (torch.Size([512, 2048]), torch.Size([2048, 49]))
shape_layer[48] = (torch.Size([512, 4608]), torch.Size([4608, 49]))
shape_layer[49] = (torch.Size([2048, 512]), torch.Size([512, 49]))
shape_layer[50] = (torch.Size([512, 2048]), torch.Size([2048, 49]))
shape_layer[51] = (torch.Size([512, 4608]), torch.Size([4608, 49]))
shape_layer[52] = (torch.Size([2048, 512]), torch.Size([512, 49]))


# the model shape of the input and weight tensors (for sw injection)
shape_layer_sw[0] = (torch.Size([64, 3, 7, 7]), torch.Size([1, 3, 224, 224]))
shape_layer_sw[1] = (torch.Size([64, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[2] = (torch.Size([64, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[3] = (torch.Size([256, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[4] = (torch.Size([256, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[5] = (torch.Size([64, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[6] = (torch.Size([64, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[7] = (torch.Size([256, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[8] = (torch.Size([64, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[9] = (torch.Size([64, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[10] = (torch.Size([256, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[11] = (torch.Size([128, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[12] = (torch.Size([128, 128, 3, 3]), torch.Size([1, 128, 56, 56]))
shape_layer_sw[13] = (torch.Size([512, 128, 1, 1]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[14] = (torch.Size([512, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[15] = (torch.Size([128, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[16] = (torch.Size([128, 128, 3, 3]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[17] = (torch.Size([512, 128, 1, 1]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[18] = (torch.Size([128, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[19] = (torch.Size([128, 128, 3, 3]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[20] = (torch.Size([512, 128, 1, 1]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[21] = (torch.Size([128, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[22] = (torch.Size([128, 128, 3, 3]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[23] = (torch.Size([512, 128, 1, 1]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[24] = (torch.Size([256, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[25] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 28, 28]))
shape_layer_sw[26] = (torch.Size([1024, 256, 1, 1]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[27] = (torch.Size([1024, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[28] = (torch.Size([256, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[29] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[30] = (torch.Size([1024, 256, 1, 1]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[31] = (torch.Size([256, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[32] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[33] = (torch.Size([1024, 256, 1, 1]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[34] = (torch.Size([256, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[35] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[36] = (torch.Size([1024, 256, 1, 1]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[37] = (torch.Size([256, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[38] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[39] = (torch.Size([1024, 256, 1, 1]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[40] = (torch.Size([256, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[41] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[42] = (torch.Size([1024, 256, 1, 1]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[43] = (torch.Size([512, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[44] = (torch.Size([512, 512, 3, 3]), torch.Size([1, 512, 14, 14]))
shape_layer_sw[45] = (torch.Size([2048, 512, 1, 1]), torch.Size([1, 512, 7, 7]))
shape_layer_sw[46] = (torch.Size([2048, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[47] = (torch.Size([512, 2048, 1, 1]), torch.Size([1, 2048, 7, 7]))
shape_layer_sw[48] = (torch.Size([512, 512, 3, 3]), torch.Size([1, 512, 7, 7]))
shape_layer_sw[49] = (torch.Size([2048, 512, 1, 1]), torch.Size([1, 512, 7, 7]))
shape_layer_sw[50] = (torch.Size([512, 2048, 1, 1]), torch.Size([1, 2048, 7, 7]))
shape_layer_sw[51] = (torch.Size([512, 512, 3, 3]), torch.Size([1, 512, 7, 7]))
shape_layer_sw[52] = (torch.Size([2048, 512, 1, 1]), torch.Size([1, 512, 7, 7]))
