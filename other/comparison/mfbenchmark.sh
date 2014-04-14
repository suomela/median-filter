#!/bin/sh

tester=../../build-gcc-short/tester
for alg in 0 1 2; do
    $tester 1 10000 $alg 4 1 || exit 1
    $tester 2  5000 $alg 4 1 || exit 1
    $tester 5  2000 $alg 4 1 || exit 1
    $tester 10 1000 $alg 4 1 || exit 1
    $tester 20  500 $alg 4 1 || exit 1
    $tester 50  200 $alg 4 1 || exit 1
    $tester 100 100 $alg 4 1 || exit 1
    $tester 200  50 $alg 4 1 || exit 1
    $tester 500  20 $alg 4 1 || exit 1
    $tester 1000 10 $alg 4 1 || exit 1
    $tester 2000  5 $alg 4 1 || exit 1
    $tester 5000  2 $alg 4 1 || exit 1
    $tester 10000 1 $alg 4 1 || exit 1
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
done
