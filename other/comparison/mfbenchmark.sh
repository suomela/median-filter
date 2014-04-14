#!/bin/sh

tester=../../build-gcc-short/tester
for alg in 0 1 2 3; do
    $tester 1 10000 $alg 4 1 || exit 1
    $tester 10 1000 $alg 4 1 || exit 1
    $tester 100 100 $alg 4 1 || exit 1
    $tester 1000 10 $alg 4 1 || exit 1
    $tester 1 100000 $alg 4 1 || exit 1
    $tester 10 10000 $alg 4 1 || exit 1
    $tester 100 1000 $alg 4 1 || exit 1
    $tester 1000 100 $alg 4 1 || exit 1
    $tester 10000 10 $alg 4 1 || exit 1
done
