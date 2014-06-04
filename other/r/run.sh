#!/bin/sh

seed="$1"
R --version | tee "log-$seed" || exit 1
R CMD BATCH --slave --no-timing "--args seed=$seed" mfbenchmark.r /dev/stdout | tee "result-$seed"
