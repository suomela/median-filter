#!/bin/sh

seed="$1"
cat /proc/cpuinfo > "log-cpu-$seed"
free > "log-memory-$seed"
R --version | tee "log-$seed" || exit 1
R CMD BATCH --slave --no-timing "--args seed=$seed" mfbenchmark.r /dev/stdout | tee "result-$seed"
