#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$SCRIPT_DIR/_setup_.sh"

init_params $MODE_SEQUENTIAL
write_notes_start

start_time_s=$(date +%s)

return_code_total=0

for layer in "${target_layers[@]}"; do
#echo "Evaluating with batch size: $batch_size"
    python3 profiler/gen-prof.py \
            --model $model \
            --config $gemmini_config_key \
            --batches $nbatches \
            --bsize $batch_size \
            --layer $layer \
            --faultlist $fault_list \
            --injections $injections \
            --output $base_dir \
            --seed $seed \
            --alias $sim_alias \
            --th_inter $inter_threads \
            --th_intra $intra_threads \
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

#gdb --args python main.py -m ResNet18 -a debug -o reports/ResNet18/debug/sequential -s 0 -E 2 -A 2 -b 16 -B 1 -l 0 -n 100 -f ResNet18/fl_ctrl_gemmini_conf_key_0.csv
#run
#backtrace
