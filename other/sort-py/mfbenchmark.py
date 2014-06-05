#!/usr/bin/env python

import random
import time
import sys
import SortMedian

def test(h, b, seed):
    random.seed(1)
    k = 2*h+1
    n = k*b
    x = []
    for i in range(n):
        x.append(random.randrange(2**32))
    s = time.time()
    y = SortMedian.sort_median(h, b, x)
    e = time.time() - s
    assert len(y) == n - k + 1
    sys.stdout.write('sort-py\t{}\t{}\tr-large\t{}\t{:.5f}\n'.format(h, b, seed, e))
    sys.stdout.flush()

for seed in range(1,11):
    test(1, 10000, seed)
    test(10, 1000, seed)
    test(100, 100, seed)
    test(1000, 10, seed)
    test(1, 100000, seed)
    test(10, 10000, seed)
    test(100, 1000, seed)
    test(1000, 100, seed)
    test(10000, 10, seed)
