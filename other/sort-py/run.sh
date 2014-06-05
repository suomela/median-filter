#!/bin/sh

./versioninfo.py | tee log
./mfbenchmark.py | tee result
