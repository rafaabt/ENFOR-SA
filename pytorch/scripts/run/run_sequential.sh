#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$SCRIPT_DIR/_setup_.sh"

init_params $MODE_SEQUENTIAL
write_notes_start
start_time_s=$(date +%s)
return_code_total=0

for layer in "${target_layers[@]}"; do
    python3 main.py \
            --model $model \
            --fmodel $fault_model \
            --config $gemmini_config_key \
            --batches $nbatches \
            --bsize $batch_size \
            --layer $layer \
            --faultlist $fault_list \
            --injections $injections \
            --output $base_dir \
            --alias $sim_alias \
            --th_inter $inter_threads \
            --th_intra $intra_threads \
            --seed $seed \
            #--gold \
            #--seqp \

    #the script's return code in sys.exit(<return code>)
    ret=$?
    return_code_total=$((return_code_total + ret))
done

end_time_s=$(date +%s)
elapsed=$((end_time_s - start_time_s))
write_notes_end $elapsed $return_code_total
echo "Script (run_sequential.sh) finished after $elapsed seconds"
