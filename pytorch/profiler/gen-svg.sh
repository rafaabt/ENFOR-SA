
#in_fn=$1  # output.prof
#out_fn=$2 # output.svg

#gprof2dot -f pstats $in_fn | dot -Tsvg -o $out_fn


cd prof

for file in *.prof; do
  # Check if any files matched
  [ -e "$file" ] || continue

  echo "Processing $file"
  gprof2dot -f pstats $file | dot -Tsvg -o ../svg/$file.svg

done

