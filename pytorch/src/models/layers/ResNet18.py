import torch
import numpy

N_LAYERS = 20


# the shapes of the unfolded filter (matrix_A) and input tensor (matrix_B) for each conv layer

target_layers = numpy.arange(N_LAYERS) # covers all layers

shape_layer = [(0,0) for _ in range(N_LAYERS)]
shape_layer_sw = [(0,0) for _ in range(N_LAYERS)]

#"""
#if using: Weight x Input
shape_layer[0] = (torch.Size([64, 147]), torch.Size([147, 12544]))
shape_layer[1] = (torch.Size([64, 576]), torch.Size([576, 3136]))
shape_layer[2] = (torch.Size([64, 576]), torch.Size([576, 3136]))
shape_layer[3] = (torch.Size([64, 576]), torch.Size([576, 3136]))
shape_layer[4] = (torch.Size([64, 576]), torch.Size([576, 3136]))
shape_layer[5] = (torch.Size([128, 576]), torch.Size([576, 784]))
shape_layer[6] = (torch.Size([128, 1152]), torch.Size([1152, 784]))
shape_layer[7] = (torch.Size([128, 64]), torch.Size([64, 784]))
shape_layer[8] = (torch.Size([128, 1152]), torch.Size([1152, 784]))
shape_layer[9] = (torch.Size([128, 1152]), torch.Size([1152, 784]))
shape_layer[10] = (torch.Size([256, 1152]), torch.Size([1152, 196]))
shape_layer[11] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[12] = (torch.Size([256, 128]), torch.Size([128, 196]))
shape_layer[13] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[14] = (torch.Size([256, 2304]), torch.Size([2304, 196]))
shape_layer[15] = (torch.Size([512, 2304]), torch.Size([2304, 49]))
shape_layer[16] = (torch.Size([512, 4608]), torch.Size([4608, 49]))
shape_layer[17] = (torch.Size([512, 256]), torch.Size([256, 49]))
shape_layer[18] = (torch.Size([512, 4608]), torch.Size([4608, 49]))
shape_layer[19] = (torch.Size([512, 4608]), torch.Size([4608, 49]))


# the model shape of the input and weight tensors (for sw injection)
shape_layer_sw[0] = (torch.Size([64, 3, 7, 7]), torch.Size([1, 3, 224, 224]))
shape_layer_sw[1] = (torch.Size([64, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[2] = (torch.Size([64, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[3] = (torch.Size([64, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[4] = (torch.Size([64, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[5] = (torch.Size([128, 64, 3, 3]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[6] = (torch.Size([128, 128, 3, 3]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[7] = (torch.Size([128, 64, 1, 1]), torch.Size([1, 64, 56, 56]))
shape_layer_sw[8] = (torch.Size([128, 128, 3, 3]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[9] = (torch.Size([128, 128, 3, 3]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[10] = (torch.Size([256, 128, 3, 3]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[11] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[12] = (torch.Size([256, 128, 1, 1]), torch.Size([1, 128, 28, 28]))
shape_layer_sw[13] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[14] = (torch.Size([256, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[15] = (torch.Size([512, 256, 3, 3]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[16] = (torch.Size([512, 512, 3, 3]), torch.Size([1, 512, 7, 7]))
shape_layer_sw[17] = (torch.Size([512, 256, 1, 1]), torch.Size([1, 256, 14, 14]))
shape_layer_sw[18] = (torch.Size([512, 512, 3, 3]), torch.Size([1, 512, 7, 7]))
shape_layer_sw[19] = (torch.Size([512, 512, 3, 3]), torch.Size([1, 512, 7, 7]))


#"""

"""
the bias shape of the first conv layer is bias = 1x64
in the two unfolding approaches:
W x I = C -> C.shape = 64x147 x 147 x 12544 = 64 x 12544
It x Wt = C -> C.shape = 12544x147 x 147x64 = 12544 x 64  (this one proves the correct way is actually It x Wt, because the number of cols. = number of cols in the bias tensor)


[11/07/2025] Update: it does NOT matter which format we use, as long as the way the tile matmul is done matches the tensors returned in the unfold process:

e.g.: 

if unfold_tensors_quantized returns: return torch.transpose(input_unfolded[0], 0, 1), torch.transpose(conv_weight_flat, 0, 1)
    then matrix_A, matrix_B = input_unfolded_t, conv_weight_flat_t
    we must use a fault list generated with the shapes BELOW, and transpose the output matrix computed by Gemmini

if using return conv_weight_flat, input_unfolded[0]
    then matrix_A, matrix_B = conv_weight_flat, conv_weight_flat
    we must use a fault list generated with the shapes ABOVE
"""


# if using: Input.T x Weight.T
"""
shape_layer[0] = (torch.Size([12544, 147]), torch.Size([147, 64])) # 'conv1'
shape_layer[1] = (torch.Size([3136, 576]), torch.Size([576, 64])) # 'layer1.0.conv1'
shape_layer[2] = (torch.Size([3136, 576]), torch.Size([576, 64])) # 'layer1.0.conv2', and so on...
shape_layer[3] = (torch.Size([3136, 576]), torch.Size([576, 64]))
shape_layer[4] = (torch.Size([3136, 576]), torch.Size([576, 64]))
shape_layer[5] = (torch.Size([784, 576]), torch.Size([576, 128]))
shape_layer[6] = (torch.Size([784, 1152]), torch.Size([1152, 128]))
shape_layer[7] = (torch.Size([784, 64]), torch.Size([64, 128]))
shape_layer[8] = (torch.Size([784, 1152]), torch.Size([1152, 128]))
shape_layer[9] = (torch.Size([784, 1152]), torch.Size([1152, 128]))
shape_layer[10] = (torch.Size([196, 1152]), torch.Size([1152, 256]))
shape_layer[11] = (torch.Size([196, 2304]), torch.Size([2304, 256]))
shape_layer[12] = (torch.Size([196, 128]), torch.Size([128, 256]))
shape_layer[13] = (torch.Size([196, 2304]), torch.Size([2304, 256]))
shape_layer[14] = (torch.Size([196, 2304]), torch.Size([2304, 256]))
shape_layer[15] = (torch.Size([49, 2304]), torch.Size([2304, 512]))
shape_layer[16] = (torch.Size([49, 4608]), torch.Size([4608, 512]))
shape_layer[17] = (torch.Size([49, 256]), torch.Size([256, 512]))
shape_layer[18] = (torch.Size([49, 4608]), torch.Size([4608, 512]))
shape_layer[19] = (torch.Size([49, 4608]), torch.Size([4608, 512])) # 'layer4.1.conv2'
"""

# conv1: type QuantizedConvReLU2d
# conv2: type QuantizedConv2d
# TODO: this is not accounting for the 'downsample layers' e.g., in ResNet18 some downsampling layers are implemented as conv layers (but the layer name does not contain the conv string)
# downsampling layers are 1x1 kernels. i'll ignore them for now...
# ResNet18: 17 (core layers) + 3 (skip connections - downsampling) = 20 convolutional layers


conv_layers_names={ 0:'conv1',
                    1:'layer1.0.conv1',
                    2:'layer1.0.conv2',
                    3:'layer1.1.conv1',
                    4:'layer1.1.conv2',
                    5:'layer2.0.conv1',
                    6:'layer2.0.conv2',
                    7:'layer2.0.downsample.0',
                    8:'layer2.1.conv1',
                    9:'layer2.1.conv2',
                    10:'layer3.0.conv1',
                    11:'layer3.0.conv2',
                    12:'layer3.0.downsample.0',
                    13:'layer3.1.conv1',
                    14:'layer3.1.conv2',
                    15:'layer4.0.conv1',
                    16:'layer4.0.conv2',
                    17:'layer4.0.downsample.0',
                    18:'layer4.1.conv1',
                    19:'layer4.1.conv2',
                    }
"""
conv_layers_names = {   0:'conv1',
                        1:'layer1.0.conv1', 
                        2:'layer1.0.conv2',
                        3:'layer1.1.conv1',
                        4:'layer1.1.conv2',
                        5:'layer2.0.conv1',
                        6:'layer2.0.conv2',
                        7:'layer2.1.conv1',
                        8:'layer2.1.conv2',
                        9:'layer3.0.conv1',
                        10:'layer3.0.conv2',
                        11:'layer3.1.conv1',
                        12:'layer3.1.conv2',
                        13:'layer4.0.conv1',
                        14:'layer4.0.conv2',
                        15:'layer4.1.conv1',
                        16:'layer4.1.conv2'
                    }
"""



"""
when using REPL_ALL = True

1 Replaced layer: QuantizedConvReLU2d(3, 64, kernel_size=(7, 7), stride=(2, 2), scale=0.028605546802282333, zero_point=0, padding=(3, 3)) - conv1
2 Replaced layer: QuantizedConvReLU2d(64, 64, kernel_size=(3, 3), stride=(1, 1), scale=0.016524722799658775, zero_point=0, padding=(1, 1)) - layer1.0.conv1
3 Replaced layer: QuantizedConv2d(64, 64, kernel_size=(3, 3), stride=(1, 1), scale=0.04645531252026558, zero_point=75, padding=(1, 1)) - layer1.0.conv2
4 Replaced layer: QuantizedConvReLU2d(64, 64, kernel_size=(3, 3), stride=(1, 1), scale=0.017180869355797768, zero_point=0, padding=(1, 1)) - layer1.1.conv1
5 Replaced layer: QuantizedConv2d(64, 64, kernel_size=(3, 3), stride=(1, 1), scale=0.06583978235721588, zero_point=82, padding=(1, 1)) - layer1.1.conv2
6 Replaced layer: QuantizedConvReLU2d(64, 128, kernel_size=(3, 3), stride=(2, 2), scale=0.014848409220576286, zero_point=0, padding=(1, 1)) - layer2.0.conv1
7 Replaced layer: QuantizedConv2d(128, 128, kernel_size=(3, 3), stride=(1, 1), scale=0.043153878301382065, zero_point=58, padding=(1, 1)) - layer2.0.conv2
8 Replaced layer: QuantizedConv2d(64, 128, kernel_size=(1, 1), stride=(2, 2), scale=0.03397900238633156, zero_point=68) - layer2.0.downsample.0   (!!!!!)
9 Replaced layer: QuantizedConvReLU2d(128, 128, kernel_size=(3, 3), stride=(1, 1), scale=0.015309284441173077, zero_point=0, padding=(1, 1)) - layer2.1.conv1
10 Replaced layer: QuantizedConv2d(128, 128, kernel_size=(3, 3), stride=(1, 1), scale=0.04422105476260185, zero_point=70, padding=(1, 1)) - layer2.1.conv2
11 Replaced layer: QuantizedConvReLU2d(128, 256, kernel_size=(3, 3), stride=(2, 2), scale=0.018436331301927567, zero_point=0, padding=(1, 1)) - layer3.0.conv1
12 Replaced layer: QuantizedConv2d(256, 256, kernel_size=(3, 3), stride=(1, 1), scale=0.05117332935333252, zero_point=47, padding=(1, 1)) - layer3.0.conv2
13 Replaced layer: QuantizedConv2d(128, 256, kernel_size=(1, 1), stride=(2, 2), scale=0.014961435459554195, zero_point=84) - layer3.0.downsample.0 (!!!!!)
14 Replaced layer: QuantizedConvReLU2d(256, 256, kernel_size=(3, 3), stride=(1, 1), scale=0.01651308871805668, zero_point=0, padding=(1, 1)) - layer3.1.conv1
15 Replaced layer: QuantizedConv2d(256, 256, kernel_size=(3, 3), stride=(1, 1), scale=0.046813614666461945, zero_point=77, padding=(1, 1)) - layer3.1.conv2
16 Replaced layer: QuantizedConvReLU2d(256, 512, kernel_size=(3, 3), stride=(2, 2), scale=0.013452869839966297, zero_point=0, padding=(1, 1)) - layer4.0.conv1
17 Replaced layer: QuantizedConv2d(512, 512, kernel_size=(3, 3), stride=(1, 1), scale=0.04732713848352432, zero_point=68, padding=(1, 1)) - layer4.0.conv2
18 Replaced layer: QuantizedConv2d(256, 512, kernel_size=(1, 1), stride=(2, 2), scale=0.036629535257816315, zero_point=65) - layer4.0.downsample.0 (!!!!!)
19 Replaced layer: QuantizedConvReLU2d(512, 512, kernel_size=(3, 3), stride=(1, 1), scale=0.013848909176886082, zero_point=0, padding=(1, 1)) - layer4.1.conv1
20 Replaced layer: QuantizedConv2d(512, 512, kernel_size=(3, 3), stride=(1, 1), scale=0.2509911060333252, zero_point=42, padding=(1, 1)) - layer4.1.conv2

"""
"""
Critical faults per layer:
1: 1074  QuantizedConvReLU2d
2: 1848  QuantizedConvReLU2d
3: 0     QuantizedConv2d
4: 1767  QuantizedConvReLU2d
5: 0     QuantizedConv2d
6: 1772  QuantizedConvReLU2d
7: 0     QuantizedConv2d
8: 0     QuantizedConv2d
9: 1384  QuantizedConvReLU2d
10: 0    QuantizedConv2d
11: 1579 QuantizedConvReLU2d
12: 0    QuantizedConv2d
13: 0    QuantizedConv2d
14: 1412 QuantizedConvReLU2d
15: 0    QuantizedConv2d
16: 1863 QuantizedConvReLU2d
17: 0    QuantizedConv2d
18: 0    QuantizedConv2d
19: 1406 QuantizedConvReLU2d
20: 0    QuantizedConv2d
"""
