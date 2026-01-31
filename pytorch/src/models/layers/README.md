## This directory contains the layer shapes for ImageNet only

The layer shapes are only necessary to generate the fault lists, for each model.

### shape_layer: 

1. For CNNs: the input tensors shapes are determined after applying the im2col procedure. The weight tensor shapes are after flattening the weight tensor.
This is done such that we can compute the convolution as O = W (flattened) x Input (im2col)

Example for CNN layer 0 of ResNet18:
shape_layer[0] = (torch.Size([64, 147]), torch.Size([147, 12544]))

torch.Size([64, 147]) is the flattened weight shape
torch.Size([147, 12544] is the input shape after im2col;

2. For the ViT models, no im2col is involved, because we map layers that are already defined as matmuls to Gemmini. i.e., we already have the layer shapes in every matmul call seen through the model layers.

### shape_layer_sw: these are the original input and weight tensor shapes, as defined in sw. 

> [!NOTE]
> All layer shapes are valid for ImageNet only!
> For other types of datasets, you need to extract the new layer shapes, and generate the fault lists for the specific dataset.
