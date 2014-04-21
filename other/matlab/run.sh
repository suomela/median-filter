#!/bin/sh

cat /proc/cpuinfo > log-cpu
free > log-memory
matlab -nojvm -nodisplay -nosplash -logfile log -r run || exit 1

