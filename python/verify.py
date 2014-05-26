#!/usr/bin/env python3

import random
import statistics
import SortMedian

h = 1000
b = 10
k = 2 * h + 1
n = k * b

def gen_data():
    x = []
    for i in range(n):
        x.append(random.random())
    return x

def verify(x, y):
    for i in range(n - k + 1):
        assert y[i] == statistics.median(x[i:i+k])

def main():
    print("generate...")
    random.seed(1)
    x = gen_data()
    print("filter...")
    y = SortMedian.sort_median(h, b, x)
    print("verify...")
    verify(x, y)

main()
