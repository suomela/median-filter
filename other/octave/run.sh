#!/bin/sh

tester=../../build-gcc-short/tester
for alg in 0 1 2; do
    $tester 1 100000 $alg 4 1 || exit 1
    $tester 2  50000 $alg 4 1 || exit 1
    $tester 5  20000 $alg 4 1 || exit 1
    $tester 10 10000 $alg 4 1 || exit 1
    $tester 20  5000 $alg 4 1 || exit 1
    $tester 50  2000 $alg 4 1 || exit 1
    $tester 100 1000 $alg 4 1 || exit 1
    $tester 200  500 $alg 4 1 || exit 1
    $tester 500  200 $alg 4 1 || exit 1
    $tester 1000 100 $alg 4 1 || exit 1
    $tester 2000  50 $alg 4 1 || exit 1
    $tester 5000  20 $alg 4 1 || exit 1
    $tester 10000 10 $alg 4 1 || exit 1
    $tester 20000  5 $alg 4 1 || exit 1
    $tester 50000  2 $alg 4 1 || exit 1
    $tester 100000 1 $alg 4 1 || exit 1
    $tester 1 1000000 $alg 4 1 || exit 1
    $tester 2  500000 $alg 4 1 || exit 1
    $tester 5  200000 $alg 4 1 || exit 1
    $tester 10 100000 $alg 4 1 || exit 1
    $tester 20  50000 $alg 4 1 || exit 1
    $tester 50  20000 $alg 4 1 || exit 1
    $tester 100 10000 $alg 4 1 || exit 1
    $tester 200  5000 $alg 4 1 || exit 1
    $tester 500  2000 $alg 4 1 || exit 1
    $tester 1000 1000 $alg 4 1 || exit 1
    $tester 2000  500 $alg 4 1 || exit 1
    $tester 5000  200 $alg 4 1 || exit 1
    $tester 10000 100 $alg 4 1 || exit 1
done
octave -q -W --eval runit || exit 1
