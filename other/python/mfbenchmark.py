#!/usr/bin/env python

import numpy.random
import scipy.signal
import time
import sys

def test(h, b, seed):
    numpy.random.seed(seed)
    k = 2*h+1
    n = k*b
    x = numpy.random.random_integers(0, 2**32-1, n)
    s = time.time()
    y = scipy.signal.medfilt(x, k)
    e = time.time() - s
    sys.stdout.write('python\t{}\t{}\tr-large\t{}\t{:.5f}\n'.format(h, b, seed, e))
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
