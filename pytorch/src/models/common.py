import time
from typing import Union

import torch
import torchvision.models.quantization as tch_qtz

# the available transformer models
from src.ivit.models import *


QUANTIZED_MODELS = {
    "GoogLeNet": (
        tch_qtz.GoogLeNet_QuantizedWeights.IMAGENET1K_FBGEMM_V1,
        tch_qtz.googlenet
    ),
    "Inception_V3": (
        tch_qtz.Inception_V3_QuantizedWeights.IMAGENET1K_FBGEMM_V1,
        tch_qtz.inception_v3
    ),
    "MobileNet_V2": (
        tch_qtz.MobileNet_V2_QuantizedWeights.IMAGENET1K_QNNPACK_V1,
        tch_qtz.mobilenet_v2
    ),
    "MobileNet_V3_Large": (
        tch_qtz.MobileNet_V3_Large_QuantizedWeights.IMAGENET1K_QNNPACK_V1,
        tch_qtz.mobilenet_v3_large
    ),
    "ResNeXt101_32X8D": (
        tch_qtz.ResNeXt101_32X8D_QuantizedWeights.IMAGENET1K_FBGEMM_V2,
        tch_qtz.resnext101_32x8d
    ),
    "ResNeXt101_64X4D": (
        tch_qtz.ResNeXt101_64X4D_QuantizedWeights.IMAGENET1K_FBGEMM_V1,
        tch_qtz.resnext101_64x4d
    ),
    "ResNet18": (
        tch_qtz.ResNet18_QuantizedWeights.IMAGENET1K_FBGEMM_V1,
        tch_qtz.resnet18
    ),
    "ResNet50": (
        tch_qtz.ResNet50_QuantizedWeights.IMAGENET1K_FBGEMM_V2,
        tch_qtz.resnet50
    ),
    "ShuffleNet_V2_X0_5": (
        tch_qtz.ShuffleNet_V2_X0_5_QuantizedWeights.IMAGENET1K_FBGEMM_V1,
        tch_qtz.shufflenet_v2_x0_5
    ),
    "ShuffleNet_V2_X1_0": (
        tch_qtz.ShuffleNet_V2_X1_0_QuantizedWeights.IMAGENET1K_FBGEMM_V1,
        tch_qtz.shufflenet_v2_x1_0
    ),
    "ShuffleNet_V2_X1_5": (
        tch_qtz.ShuffleNet_V2_X1_5_QuantizedWeights.IMAGENET1K_FBGEMM_V1,
        tch_qtz.shufflenet_v2_x1_5
    ),
    "ShuffleNet_V2_X2_0": (
        tch_qtz.ShuffleNet_V2_X2_0_QuantizedWeights.IMAGENET1K_FBGEMM_V1,
        tch_qtz.shufflenet_v2_x2_0
    ),
}



# the available transformer models
def QUANTIZED_MODELS_VIT(name):
    d = {
        'deit_tiny': deit_tiny_patch16_224,
        'deit_small': deit_small_patch16_224,
        'deit_base': deit_base_patch16_224,
        'swin_tiny': swin_tiny_patch4_window7_224,
        'swin_small': swin_small_patch4_window7_224,
        'swin_base': swin_base_patch4_window7_224,

        # [Rafael]: added these two. this must be ported in the dataloader
        'vit_base':  vit_base_patch16_224,
        'vit_large': vit_large_patch16_224,
    }

    return d[name]


