This directory contains all fault injection report files. See the example below on how to proces a trace file.

```
# Reads the trace file
df_full = pd.read_csv(<some trace file>, comment='#', sep='\t')

# The dataframe of the critical faults only
df_critical = df_full[(df_full['sdc1'] == 1)]

# The dataframe of faults masked by Gemmini 
df_gemm_msk = df_full[(df_full['gemm_msk'] == 1)]

# The total number of injections
injections = len(df_full)

# The total number of critical runs
sdc1 = len(df_critical)

# The list of (unique) critical faults
critical_list = df_critical["fault_tag"].unique().tolist()

# The fraction of injections masked during the Gemmini matmul
len(df_gemm_msk)/injections

# The number of injections exposed to the the layer output, to the SW
count = (
    (df_full['gemm_msk']  == 0) &
    (df_full['scale_msk'] == 0) &
    (df_full['round_msk'] == 0) &
    (df_full['clamp_msk'] == 0)
).sum()

```