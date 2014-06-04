#!/bin/sh

R --version | tee "log" || exit 1
R CMD BATCH --slave --no-timing mfbenchmark.r /dev/stdout | tee "result"
