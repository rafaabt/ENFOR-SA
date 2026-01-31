from dataclasses import dataclass
import src.definitions as defs

# injection trial status (in the output of the injection layer) after each injection trial
@dataclass 
class GemminiMaskingTrack:

    def __init__(self, mask_levels):

        # mask_levels has shape (batchSize, 4)
        batchSize = len(mask_levels) if mask_levels else defs.BATCH_SIZE

        # the faults can be masked during the conv. layer (see this in custom_conv.manual_tile_conv())
        # masking levels:
        # order -> gemm_msk, scale_msk, round_msk, clamp_msk

        self.gemm_msk = [False for _ in range(batchSize)]    # was the fault masked by the gemmini matmul
        self.scale_msk  = [False for _ in range(batchSize)]  # .. during scaling
        self.round_msk  = [False for _ in range(batchSize)]  # .. during rounding
        self.clamp_msk  = [False for _ in range(batchSize)]  # .. during the clamping
        self.qtz_msk    = [False for _ in range(batchSize)]  # .. in any of the previous phases but after the gemmini matmul
        self.fault_msk  = [False for _ in range(batchSize)]  # .. in any of the previous phases

        if mask_levels != None:
            for i in range(batchSize):
                self.gemm_msk[i] = mask_levels[i][0]
                self.scale_msk[i] = mask_levels[i][1]
                self.round_msk[i] = mask_levels[i][2]
                self.clamp_msk[i] = mask_levels[i][3]

                self.qtz_msk[i]   = self.scale_msk[i] or self.round_msk[i] or self.clamp_msk[i]
                self.fault_msk[i] = self.gemm_msk[i] or self.qtz_msk[i]
