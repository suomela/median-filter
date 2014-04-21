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
for alg in 0 1 2; do
    $tester 1 1000000 $alg 4 1 || exit 1
    $tester 10 100000 $alg 4 1 || exit 1
    $tester 100 10000 $alg 4 1 || exit 1
    $tester 1000 1000 $alg 4 1 || exit 1
    $tester 10000 100 $alg 4 1 || exit 1
    $tester 100000 10 $alg 4 1 || exit 1
    $tester 1 10000000 $alg 4 1 || exit 1
    $tester 10 1000000 $alg 4 1 || exit 1
    $tester 100 100000 $alg 4 1 || exit 1
    $tester 1000 10000 $alg 4 1 || exit 1
    $tester 10000 1000 $alg 4 1 || exit 1
    $tester 100000 100 $alg 4 1 || exit 1
    $tester 1000000 10 $alg 4 1 || exit 1
done
