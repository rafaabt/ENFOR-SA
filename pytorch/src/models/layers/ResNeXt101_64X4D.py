import torch
import numpy

N_LAYERS = 104


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
43:'layer3.6.conv1',
44:'layer3.6.conv2',
45:'layer3.6.conv3',
46:'layer3.7.conv1',
47:'layer3.7.conv2',
48:'layer3.7.conv3',
49:'layer3.8.conv1',
50:'layer3.8.conv2',
51:'layer3.8.conv3',
52:'layer3.9.conv1',
53:'layer3.9.conv2',
54:'layer3.9.conv3',
55:'layer3.10.conv1',
56:'layer3.10.conv2',
57:'layer3.10.conv3',
58:'layer3.11.conv1',
59:'layer3.11.conv2',
60:'layer3.11.conv3',
61:'layer3.12.conv1',
62:'layer3.12.conv2',
63:'layer3.12.conv3',
64:'layer3.13.conv1',
65:'layer3.13.conv2',
66:'layer3.13.conv3',
67:'layer3.14.conv1',
68:'layer3.14.conv2',
69:'layer3.14.conv3',
70:'layer3.15.conv1',
71:'layer3.15.conv2',
72:'layer3.15.conv3',
73:'layer3.16.conv1',
74:'layer3.16.conv2',
75:'layer3.16.conv3',
76:'layer3.17.conv1',
77:'layer3.17.conv2',
78:'layer3.17.conv3',
79:'layer3.18.conv1',
80:'layer3.18.conv2',
81:'layer3.18.conv3',
82:'layer3.19.conv1',
83:'layer3.19.conv2',
84:'layer3.19.conv3',
85:'layer3.20.conv1',
86:'layer3.20.conv2',
87:'layer3.20.conv3',
88:'layer3.21.conv1',
89:'layer3.21.conv2',
90:'layer3.21.conv3',
91:'layer3.22.conv1',
92:'layer3.22.conv2',
93:'layer3.22.conv3',
94:'layer4.0.conv1',
95:'layer4.0.conv2',
96:'layer4.0.conv3',
97:'layer4.0.downsample.0',
98:'layer4.1.conv1',
99:'layer4.1.conv2',
100:'layer4.1.conv3',
101:'layer4.2.conv1',
102:'layer4.2.conv2',
103:'layer4.2.conv3',
}


shape_layer[0] = (torch.Size([64, 147]), torch.Size([147, 12544]))
shape_layer[1] = (torch.Size([256, 64]), torch.Size([64, 3136]))
shape_layer[2] = (torch.Size([256, 36]), torch.Size([36, 200704]))
shape_layer[3] = (torch.Size([256, 256]), torch.Size([256, 3136]))
shape_layer[4] = (torch.Size([256, 64]), torch.Size([64, 3136]))
shape_layer[5] = (torch.Size([256, 256]), torch.Size([256, 3136]))
shape_layer[6] = (torch.Size([256, 36]), torch.Size([36, 200704]))
shape_layer[7] = (torch.Size([256, 256]), torch.Size([256, 3136]))
shape_layer[8] = (torch.Size([256, 256]), torch.Size([256, 3136]))
shape_layer[9] = (torch.Size([256, 36]), torch.Size([36, 200704]))
shape_layer[10] = (torch.Size([256, 256]), torch.Size([256, 3136]))
shape_layer[11] = (torch.Size([512, 256]), torch.Size([256, 3136]))
shape_layer[12] = (torch.Size([512, 72]), torch.Size([72, 50176]))
shape_layer[13] = (torch.Size([512, 512]), torch.Size([512, 784]))
shape_layer[14] = (torch.Size([512, 256]), torch.Size([256, 784]))
shape_layer[15] = (torch.Size([512, 512]), torch.Size([512, 784]))
shape_layer[16] = (torch.Size([512, 72]), torch.Size([72, 50176]))
shape_layer[17] = (torch.Size([512, 512]), torch.Size([512, 784]))
shape_layer[18] = (torch.Size([512, 512]), torch.Size([512, 784]))
shape_layer[19] = (torch.Size([512, 72]), torch.Size([72, 50176]))
shape_layer[20] = (torch.Size([512, 512]), torch.Size([512, 784]))
shape_layer[21] = (torch.Size([512, 512]), torch.Size([512, 784]))
shape_layer[22] = (torch.Size([512, 72]), torch.Size([72, 50176]))
shape_layer[23] = (torch.Size([512, 512]), torch.Size([512, 784]))
shape_layer[24] = (torch.Size([1024, 512]), torch.Size([512, 784]))
shape_layer[25] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[26] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[27] = (torch.Size([1024, 512]), torch.Size([512, 196]))
shape_layer[28] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[29] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[30] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[31] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[32] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[33] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[34] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[35] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[36] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[37] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[38] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[39] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[40] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[41] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[42] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[43] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[44] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[45] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[46] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[47] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[48] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[49] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[50] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[51] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[52] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[53] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[54] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[55] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[56] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[57] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[58] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[59] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[60] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[61] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[62] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[63] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[64] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[65] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[66] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[67] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[68] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[69] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[70] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[71] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[72] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[73] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[74] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[75] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[76] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[77] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[78] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[79] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[80] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[81] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[82] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[83] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[84] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[85] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[86] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[87] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[88] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[89] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[90] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[91] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[92] = (torch.Size([1024, 144]), torch.Size([144, 12544]))
shape_layer[93] = (torch.Size([1024, 1024]), torch.Size([1024, 196]))
shape_layer[94] = (torch.Size([2048, 1024]), torch.Size([1024, 196]))
shape_layer[95] = (torch.Size([2048, 288]), torch.Size([288, 3136]))
shape_layer[96] = (torch.Size([2048, 2048]), torch.Size([2048, 49]))
shape_layer[97] = (torch.Size([2048, 1024]), torch.Size([1024, 49]))
shape_layer[98] = (torch.Size([2048, 2048]), torch.Size([2048, 49]))
shape_layer[99] = (torch.Size([2048, 288]), torch.Size([288, 3136]))
shape_layer[100] = (torch.Size([2048, 2048]), torch.Size([2048, 49]))
shape_layer[101] = (torch.Size([2048, 2048]), torch.Size([2048, 49]))
shape_layer[102] = (torch.Size([2048, 288]), torch.Size([288, 3136]))
shape_layer[103] = (torch.Size([2048, 2048]), torch.Size([2048, 49]))

shape_layer_sw[0] = (torch.Size([64, 3, 7, 7]), torch.Size([1, 3, 224, 224]))
shape_layer_sw[1] = (torch.Size([256, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[2] = (torch.Size([256, 4, 3, 3]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[3] = (torch.Size([256, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[4] = (torch.Size([256, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[5] = (torch.Size([256, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[6] = (torch.Size([256, 4, 3, 3]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[7] = (torch.Size([256, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[8] = (torch.Size([256, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[9] = (torch.Size([256, 4, 3, 3]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[10] = (torch.Size([256, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[11] = (torch.Size([512, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[12] = (torch.Size([512, 8, 3, 3]), torch.Size([1, 512, 56, 56]))
shape_layer_sw[13] = (torch.Size([512, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[14] = (torch.Size([512, 256, 1, 1]), torch.Size([1, 256, 56, 56]))
shape_layer_sw[15] = (torch.Size([512, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[16] = (torch.Size([512, 8, 3, 3]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[17] = (torch.Size([512, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[18] = (torch.Size([512, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[19] = (torch.Size([512, 8, 3, 3]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[20] = (torch.Size([512, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[21] = (torch.Size([512, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[22] = (torch.Size([512, 8, 3, 3]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[23] = (torch.Size([512, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[24] = (torch.Size([1024, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[25] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 28, 28]))
shape_layer_sw[26] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[27] = (torch.Size([1024, 512, 1, 1]), torch.Size([1, 512, 28, 28]))
shape_layer_sw[28] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[29] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[30] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[31] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[32] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[33] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[34] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[35] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[36] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[37] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[38] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[39] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[40] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[41] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[42] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[43] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[44] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[45] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[46] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[47] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[48] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[49] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[50] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[51] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[52] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[53] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[54] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[55] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[56] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[57] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[58] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[59] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[60] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[61] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[62] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[63] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[64] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[65] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[66] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[67] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[68] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[69] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[70] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[71] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[72] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[73] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[74] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[75] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[76] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[77] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[78] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[79] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[80] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[81] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[82] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[83] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[84] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[85] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[86] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[87] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[88] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[89] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[90] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[91] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[92] = (torch.Size([1024, 16, 3, 3]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[93] = (torch.Size([1024, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[94] = (torch.Size([2048, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[95] = (torch.Size([2048, 32, 3, 3]), torch.Size([1, 2048, 14, 14]))
shape_layer_sw[96] = (torch.Size([2048, 2048, 1, 1]), torch.Size([1, 2048, 7, 7]))
shape_layer_sw[97] = (torch.Size([2048, 1024, 1, 1]), torch.Size([1, 1024, 14, 14]))
shape_layer_sw[98] = (torch.Size([2048, 2048, 1, 1]), torch.Size([1, 2048, 7, 7]))
shape_layer_sw[99] = (torch.Size([2048, 32, 3, 3]), torch.Size([1, 2048, 7, 7]))
shape_layer_sw[100] = (torch.Size([2048, 2048, 1, 1]), torch.Size([1, 2048, 7, 7]))
shape_layer_sw[101] = (torch.Size([2048, 2048, 1, 1]), torch.Size([1, 2048, 7, 7]))
shape_layer_sw[102] = (torch.Size([2048, 32, 3, 3]), torch.Size([1, 2048, 7, 7]))
shape_layer_sw[103] = (torch.Size([2048, 2048, 1, 1]), torch.Size([1, 2048, 7, 7]))
