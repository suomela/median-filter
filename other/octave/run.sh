#!/bin/sh

octave -W --eval 'pkg list' | tee log
octave -q -W --eval runit | tee result
