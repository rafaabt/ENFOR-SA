import torch
import numpy

N_LAYERS = 94


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

conv_layers_names={
0:'Conv2d_1a_3x3.conv',
1:'Conv2d_2a_3x3.conv',
2:'Conv2d_2b_3x3.conv',
3:'Conv2d_3b_1x1.conv',
4:'Conv2d_4a_3x3.conv',
5:'Mixed_5b.branch1x1.conv',
6:'Mixed_5b.branch5x5_1.conv',
7:'Mixed_5b.branch5x5_2.conv',
8:'Mixed_5b.branch3x3dbl_1.conv',
9:'Mixed_5b.branch3x3dbl_2.conv',
10:'Mixed_5b.branch3x3dbl_3.conv',
11:'Mixed_5b.branch_pool.conv',
12:'Mixed_5c.branch1x1.conv',
13:'Mixed_5c.branch5x5_1.conv',
14:'Mixed_5c.branch5x5_2.conv',
15:'Mixed_5c.branch3x3dbl_1.conv',
16:'Mixed_5c.branch3x3dbl_2.conv',
17:'Mixed_5c.branch3x3dbl_3.conv',
18:'Mixed_5c.branch_pool.conv',
19:'Mixed_5d.branch1x1.conv',
20:'Mixed_5d.branch5x5_1.conv',
21:'Mixed_5d.branch5x5_2.conv',
22:'Mixed_5d.branch3x3dbl_1.conv',
23:'Mixed_5d.branch3x3dbl_2.conv',
24:'Mixed_5d.branch3x3dbl_3.conv',
25:'Mixed_5d.branch_pool.conv',
26:'Mixed_6a.branch3x3.conv',
27:'Mixed_6a.branch3x3dbl_1.conv',
28:'Mixed_6a.branch3x3dbl_2.conv',
29:'Mixed_6a.branch3x3dbl_3.conv',
30:'Mixed_6b.branch1x1.conv',
31:'Mixed_6b.branch7x7_1.conv',
32:'Mixed_6b.branch7x7_2.conv',
33:'Mixed_6b.branch7x7_3.conv',
34:'Mixed_6b.branch7x7dbl_1.conv',
35:'Mixed_6b.branch7x7dbl_2.conv',
36:'Mixed_6b.branch7x7dbl_3.conv',
37:'Mixed_6b.branch7x7dbl_4.conv',
38:'Mixed_6b.branch7x7dbl_5.conv',
39:'Mixed_6b.branch_pool.conv',
40:'Mixed_6c.branch1x1.conv',
41:'Mixed_6c.branch7x7_1.conv',
42:'Mixed_6c.branch7x7_2.conv',
43:'Mixed_6c.branch7x7_3.conv',
44:'Mixed_6c.branch7x7dbl_1.conv',
45:'Mixed_6c.branch7x7dbl_2.conv',
46:'Mixed_6c.branch7x7dbl_3.conv',
47:'Mixed_6c.branch7x7dbl_4.conv',
48:'Mixed_6c.branch7x7dbl_5.conv',
49:'Mixed_6c.branch_pool.conv',
50:'Mixed_6d.branch1x1.conv',
51:'Mixed_6d.branch7x7_1.conv',
52:'Mixed_6d.branch7x7_2.conv',
53:'Mixed_6d.branch7x7_3.conv',
54:'Mixed_6d.branch7x7dbl_1.conv',
55:'Mixed_6d.branch7x7dbl_2.conv',
56:'Mixed_6d.branch7x7dbl_3.conv',
57:'Mixed_6d.branch7x7dbl_4.conv',
58:'Mixed_6d.branch7x7dbl_5.conv',
59:'Mixed_6d.branch_pool.conv',
60:'Mixed_6e.branch1x1.conv',
61:'Mixed_6e.branch7x7_1.conv',
62:'Mixed_6e.branch7x7_2.conv',
63:'Mixed_6e.branch7x7_3.conv',
64:'Mixed_6e.branch7x7dbl_1.conv',
65:'Mixed_6e.branch7x7dbl_2.conv',
66:'Mixed_6e.branch7x7dbl_3.conv',
67:'Mixed_6e.branch7x7dbl_4.conv',
68:'Mixed_6e.branch7x7dbl_5.conv',
69:'Mixed_6e.branch_pool.conv',
70:'Mixed_7a.branch3x3_1.conv',
71:'Mixed_7a.branch3x3_2.conv',
72:'Mixed_7a.branch7x7x3_1.conv',
73:'Mixed_7a.branch7x7x3_2.conv',
74:'Mixed_7a.branch7x7x3_3.conv',
75:'Mixed_7a.branch7x7x3_4.conv',
76:'Mixed_7b.branch1x1.conv',
77:'Mixed_7b.branch3x3_1.conv',
78:'Mixed_7b.branch3x3_2a.conv',
79:'Mixed_7b.branch3x3_2b.conv',
80:'Mixed_7b.branch3x3dbl_1.conv',
81:'Mixed_7b.branch3x3dbl_2.conv',
82:'Mixed_7b.branch3x3dbl_3a.conv',
83:'Mixed_7b.branch3x3dbl_3b.conv',
84:'Mixed_7b.branch_pool.conv',
85:'Mixed_7c.branch1x1.conv',
86:'Mixed_7c.branch3x3_1.conv',
87:'Mixed_7c.branch3x3_2a.conv',
88:'Mixed_7c.branch3x3_2b.conv',
89:'Mixed_7c.branch3x3dbl_1.conv',
90:'Mixed_7c.branch3x3dbl_2.conv',
91:'Mixed_7c.branch3x3dbl_3a.conv',
92:'Mixed_7c.branch3x3dbl_3b.conv',
93:'Mixed_7c.branch_pool.conv',
}

shape_layer[0] = (torch.Size([32, 27]), torch.Size([27, 22201]))
shape_layer[1] = (torch.Size([32, 288]), torch.Size([288, 21609]))
shape_layer[2] = (torch.Size([64, 288]), torch.Size([288, 21609]))
shape_layer[3] = (torch.Size([80, 64]), torch.Size([64, 5329]))
shape_layer[4] = (torch.Size([192, 720]), torch.Size([720, 5041]))
shape_layer[5] = (torch.Size([64, 192]), torch.Size([192, 1225]))
shape_layer[6] = (torch.Size([48, 192]), torch.Size([192, 1225]))
shape_layer[7] = (torch.Size([64, 1200]), torch.Size([1200, 1225]))
shape_layer[8] = (torch.Size([64, 192]), torch.Size([192, 1225]))
shape_layer[9] = (torch.Size([96, 576]), torch.Size([576, 1225]))
shape_layer[10] = (torch.Size([96, 864]), torch.Size([864, 1225]))
shape_layer[11] = (torch.Size([32, 192]), torch.Size([192, 1225]))
shape_layer[12] = (torch.Size([64, 256]), torch.Size([256, 1225]))
shape_layer[13] = (torch.Size([48, 256]), torch.Size([256, 1225]))
shape_layer[14] = (torch.Size([64, 1200]), torch.Size([1200, 1225]))
shape_layer[15] = (torch.Size([64, 256]), torch.Size([256, 1225]))
shape_layer[16] = (torch.Size([96, 576]), torch.Size([576, 1225]))
shape_layer[17] = (torch.Size([96, 864]), torch.Size([864, 1225]))
shape_layer[18] = (torch.Size([64, 256]), torch.Size([256, 1225]))
shape_layer[19] = (torch.Size([64, 288]), torch.Size([288, 1225]))
shape_layer[20] = (torch.Size([48, 288]), torch.Size([288, 1225]))
shape_layer[21] = (torch.Size([64, 1200]), torch.Size([1200, 1225]))
shape_layer[22] = (torch.Size([64, 288]), torch.Size([288, 1225]))
shape_layer[23] = (torch.Size([96, 576]), torch.Size([576, 1225]))
shape_layer[24] = (torch.Size([96, 864]), torch.Size([864, 1225]))
shape_layer[25] = (torch.Size([64, 288]), torch.Size([288, 1225]))
shape_layer[26] = (torch.Size([384, 2592]), torch.Size([2592, 289]))
shape_layer[27] = (torch.Size([64, 288]), torch.Size([288, 1225]))
shape_layer[28] = (torch.Size([96, 576]), torch.Size([576, 1225]))
shape_layer[29] = (torch.Size([96, 864]), torch.Size([864, 289]))
shape_layer[30] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[31] = (torch.Size([128, 768]), torch.Size([768, 289]))
shape_layer[32] = (torch.Size([128, 896]), torch.Size([896, 289]))
shape_layer[33] = (torch.Size([192, 896]), torch.Size([896, 289]))
shape_layer[34] = (torch.Size([128, 768]), torch.Size([768, 289]))
shape_layer[35] = (torch.Size([128, 896]), torch.Size([896, 289]))
shape_layer[36] = (torch.Size([128, 896]), torch.Size([896, 289]))
shape_layer[37] = (torch.Size([128, 896]), torch.Size([896, 289]))
shape_layer[38] = (torch.Size([192, 896]), torch.Size([896, 289]))
shape_layer[39] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[40] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[41] = (torch.Size([160, 768]), torch.Size([768, 289]))
shape_layer[42] = (torch.Size([160, 1120]), torch.Size([1120, 289]))
shape_layer[43] = (torch.Size([192, 1120]), torch.Size([1120, 289]))
shape_layer[44] = (torch.Size([160, 768]), torch.Size([768, 289]))
shape_layer[45] = (torch.Size([160, 1120]), torch.Size([1120, 289]))
shape_layer[46] = (torch.Size([160, 1120]), torch.Size([1120, 289]))
shape_layer[47] = (torch.Size([160, 1120]), torch.Size([1120, 289]))
shape_layer[48] = (torch.Size([192, 1120]), torch.Size([1120, 289]))
shape_layer[49] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[50] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[51] = (torch.Size([160, 768]), torch.Size([768, 289]))
shape_layer[52] = (torch.Size([160, 1120]), torch.Size([1120, 289]))
shape_layer[53] = (torch.Size([192, 1120]), torch.Size([1120, 289]))
shape_layer[54] = (torch.Size([160, 768]), torch.Size([768, 289]))
shape_layer[55] = (torch.Size([160, 1120]), torch.Size([1120, 289]))
shape_layer[56] = (torch.Size([160, 1120]), torch.Size([1120, 289]))
shape_layer[57] = (torch.Size([160, 1120]), torch.Size([1120, 289]))
shape_layer[58] = (torch.Size([192, 1120]), torch.Size([1120, 289]))
shape_layer[59] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[60] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[61] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[62] = (torch.Size([192, 1344]), torch.Size([1344, 289]))
shape_layer[63] = (torch.Size([192, 1344]), torch.Size([1344, 289]))
shape_layer[64] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[65] = (torch.Size([192, 1344]), torch.Size([1344, 289]))
shape_layer[66] = (torch.Size([192, 1344]), torch.Size([1344, 289]))
shape_layer[67] = (torch.Size([192, 1344]), torch.Size([1344, 289]))
shape_layer[68] = (torch.Size([192, 1344]), torch.Size([1344, 289]))
shape_layer[69] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[70] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[71] = (torch.Size([320, 1728]), torch.Size([1728, 64]))
shape_layer[72] = (torch.Size([192, 768]), torch.Size([768, 289]))
shape_layer[73] = (torch.Size([192, 1344]), torch.Size([1344, 289]))
shape_layer[74] = (torch.Size([192, 1344]), torch.Size([1344, 289]))
shape_layer[75] = (torch.Size([192, 1728]), torch.Size([1728, 64]))
shape_layer[76] = (torch.Size([320, 1280]), torch.Size([1280, 64]))
shape_layer[77] = (torch.Size([384, 1280]), torch.Size([1280, 64]))
shape_layer[78] = (torch.Size([384, 1152]), torch.Size([1152, 64]))
shape_layer[79] = (torch.Size([384, 1152]), torch.Size([1152, 64]))
shape_layer[80] = (torch.Size([448, 1280]), torch.Size([1280, 64]))
shape_layer[81] = (torch.Size([384, 4032]), torch.Size([4032, 64]))
shape_layer[82] = (torch.Size([384, 1152]), torch.Size([1152, 64]))
shape_layer[83] = (torch.Size([384, 1152]), torch.Size([1152, 64]))
shape_layer[84] = (torch.Size([192, 1280]), torch.Size([1280, 64]))
shape_layer[85] = (torch.Size([320, 2048]), torch.Size([2048, 64]))
shape_layer[86] = (torch.Size([384, 2048]), torch.Size([2048, 64]))
shape_layer[87] = (torch.Size([384, 1152]), torch.Size([1152, 64]))
shape_layer[88] = (torch.Size([384, 1152]), torch.Size([1152, 64]))
shape_layer[89] = (torch.Size([448, 2048]), torch.Size([2048, 64]))
shape_layer[90] = (torch.Size([384, 4032]), torch.Size([4032, 64]))
shape_layer[91] = (torch.Size([384, 1152]), torch.Size([1152, 64]))
shape_layer[92] = (torch.Size([384, 1152]), torch.Size([1152, 64]))
shape_layer[93] = (torch.Size([192, 2048]), torch.Size([2048, 64]))

shape_layer_sw[0] = (torch.Size([32, 3, 3, 3]), torch.Size([1, 3, 299, 299]))
shape_layer_sw[1] = (torch.Size([32, 32, 3, 3]), torch.Size([1, 32, 149, 149]))
shape_layer_sw[2] = (torch.Size([64, 32, 3, 3]), torch.Size([1, 32, 147, 147]))
shape_layer_sw[3] = (torch.Size([80, 64, 1, 1]), torch.Size([1, 64, 73, 73]))
shape_layer_sw[4] = (torch.Size([192, 80, 3, 3]), torch.Size([1, 80, 73, 73]))
shape_layer_sw[5] = (torch.Size([64, 192, 1, 1]), torch.Size([1, 192, 35, 35]))
shape_layer_sw[6] = (torch.Size([48, 192, 1, 1]), torch.Size([1, 192, 35, 35]))
shape_layer_sw[7] = (torch.Size([64, 48, 5, 5]), torch.Size([1, 48, 35, 35]))
shape_layer_sw[8] = (torch.Size([64, 192, 1, 1]), torch.Size([1, 192, 35, 35]))
shape_layer_sw[9] = (torch.Size([96, 64, 3, 3]), torch.Size([1, 64, 35, 35]))
shape_layer_sw[10] = (torch.Size([96, 96, 3, 3]), torch.Size([1, 96, 35, 35]))
shape_layer_sw[11] = (torch.Size([32, 192, 1, 1]), torch.Size([1, 192, 35, 35]))
shape_layer_sw[12] = (torch.Size([64, 256, 1, 1]), torch.Size([1, 256, 35, 35]))
shape_layer_sw[13] = (torch.Size([48, 256, 1, 1]), torch.Size([1, 256, 35, 35]))
shape_layer_sw[14] = (torch.Size([64, 48, 5, 5]), torch.Size([1, 48, 35, 35]))
shape_layer_sw[15] = (torch.Size([64, 256, 1, 1]), torch.Size([1, 256, 35, 35]))
shape_layer_sw[16] = (torch.Size([96, 64, 3, 3]), torch.Size([1, 64, 35, 35]))
shape_layer_sw[17] = (torch.Size([96, 96, 3, 3]), torch.Size([1, 96, 35, 35]))
shape_layer_sw[18] = (torch.Size([64, 256, 1, 1]), torch.Size([1, 256, 35, 35]))
shape_layer_sw[19] = (torch.Size([64, 288, 1, 1]), torch.Size([1, 288, 35, 35]))
shape_layer_sw[20] = (torch.Size([48, 288, 1, 1]), torch.Size([1, 288, 35, 35]))
shape_layer_sw[21] = (torch.Size([64, 48, 5, 5]), torch.Size([1, 48, 35, 35]))
shape_layer_sw[22] = (torch.Size([64, 288, 1, 1]), torch.Size([1, 288, 35, 35]))
shape_layer_sw[23] = (torch.Size([96, 64, 3, 3]), torch.Size([1, 64, 35, 35]))
shape_layer_sw[24] = (torch.Size([96, 96, 3, 3]), torch.Size([1, 96, 35, 35]))
shape_layer_sw[25] = (torch.Size([64, 288, 1, 1]), torch.Size([1, 288, 35, 35]))
shape_layer_sw[26] = (torch.Size([384, 288, 3, 3]), torch.Size([1, 288, 35, 35]))
shape_layer_sw[27] = (torch.Size([64, 288, 1, 1]), torch.Size([1, 288, 35, 35]))
shape_layer_sw[28] = (torch.Size([96, 64, 3, 3]), torch.Size([1, 64, 35, 35]))
shape_layer_sw[29] = (torch.Size([96, 96, 3, 3]), torch.Size([1, 96, 35, 35]))
shape_layer_sw[30] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[31] = (torch.Size([128, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[32] = (torch.Size([128, 128, 1, 7]), torch.Size([1, 128, 17, 17]))
shape_layer_sw[33] = (torch.Size([192, 128, 7, 1]), torch.Size([1, 128, 17, 17]))
shape_layer_sw[34] = (torch.Size([128, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[35] = (torch.Size([128, 128, 7, 1]), torch.Size([1, 128, 17, 17]))
shape_layer_sw[36] = (torch.Size([128, 128, 1, 7]), torch.Size([1, 128, 17, 17]))
shape_layer_sw[37] = (torch.Size([128, 128, 7, 1]), torch.Size([1, 128, 17, 17]))
shape_layer_sw[38] = (torch.Size([192, 128, 1, 7]), torch.Size([1, 128, 17, 17]))
shape_layer_sw[39] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[40] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[41] = (torch.Size([160, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[42] = (torch.Size([160, 160, 1, 7]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[43] = (torch.Size([192, 160, 7, 1]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[44] = (torch.Size([160, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[45] = (torch.Size([160, 160, 7, 1]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[46] = (torch.Size([160, 160, 1, 7]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[47] = (torch.Size([160, 160, 7, 1]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[48] = (torch.Size([192, 160, 1, 7]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[49] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[50] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[51] = (torch.Size([160, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[52] = (torch.Size([160, 160, 1, 7]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[53] = (torch.Size([192, 160, 7, 1]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[54] = (torch.Size([160, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[55] = (torch.Size([160, 160, 7, 1]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[56] = (torch.Size([160, 160, 1, 7]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[57] = (torch.Size([160, 160, 7, 1]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[58] = (torch.Size([192, 160, 1, 7]), torch.Size([1, 160, 17, 17]))
shape_layer_sw[59] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[60] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[61] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[62] = (torch.Size([192, 192, 1, 7]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[63] = (torch.Size([192, 192, 7, 1]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[64] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[65] = (torch.Size([192, 192, 7, 1]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[66] = (torch.Size([192, 192, 1, 7]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[67] = (torch.Size([192, 192, 7, 1]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[68] = (torch.Size([192, 192, 1, 7]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[69] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[70] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[71] = (torch.Size([320, 192, 3, 3]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[72] = (torch.Size([192, 768, 1, 1]), torch.Size([1, 768, 17, 17]))
shape_layer_sw[73] = (torch.Size([192, 192, 1, 7]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[74] = (torch.Size([192, 192, 7, 1]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[75] = (torch.Size([192, 192, 3, 3]), torch.Size([1, 192, 17, 17]))
shape_layer_sw[76] = (torch.Size([320, 1280, 1, 1]), torch.Size([1, 1280, 8, 8]))
shape_layer_sw[77] = (torch.Size([384, 1280, 1, 1]), torch.Size([1, 1280, 8, 8]))
shape_layer_sw[78] = (torch.Size([384, 384, 1, 3]), torch.Size([1, 384, 8, 8]))
shape_layer_sw[79] = (torch.Size([384, 384, 3, 1]), torch.Size([1, 384, 8, 8]))
shape_layer_sw[80] = (torch.Size([448, 1280, 1, 1]), torch.Size([1, 1280, 8, 8]))
shape_layer_sw[81] = (torch.Size([384, 448, 3, 3]), torch.Size([1, 448, 8, 8]))
shape_layer_sw[82] = (torch.Size([384, 384, 1, 3]), torch.Size([1, 384, 8, 8]))
shape_layer_sw[83] = (torch.Size([384, 384, 3, 1]), torch.Size([1, 384, 8, 8]))
shape_layer_sw[84] = (torch.Size([192, 1280, 1, 1]), torch.Size([1, 1280, 8, 8]))
shape_layer_sw[85] = (torch.Size([320, 2048, 1, 1]), torch.Size([1, 2048, 8, 8]))
shape_layer_sw[86] = (torch.Size([384, 2048, 1, 1]), torch.Size([1, 2048, 8, 8]))
shape_layer_sw[87] = (torch.Size([384, 384, 1, 3]), torch.Size([1, 384, 8, 8]))
shape_layer_sw[88] = (torch.Size([384, 384, 3, 1]), torch.Size([1, 384, 8, 8]))
shape_layer_sw[89] = (torch.Size([448, 2048, 1, 1]), torch.Size([1, 2048, 8, 8]))
shape_layer_sw[90] = (torch.Size([384, 448, 3, 3]), torch.Size([1, 448, 8, 8]))
shape_layer_sw[91] = (torch.Size([384, 384, 1, 3]), torch.Size([1, 384, 8, 8]))
shape_layer_sw[92] = (torch.Size([384, 384, 3, 1]), torch.Size([1, 384, 8, 8]))
shape_layer_sw[93] = (torch.Size([192, 2048, 1, 1]), torch.Size([1, 2048, 8, 8]))
