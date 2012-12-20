import medianFilter
import numpy as np
import scipy.signal
from time import time

a = np.random.rand(1000000)

numpy_start = time()
b = scipy.signal.medfilt( a, 13 )
numpy_end = time()

swig_start = time()
c = np.array(a)
medianFilter.filter( c, 13 )
swig_end = time()

print "Scipy took ", (numpy_end-numpy_start)
print "medianFilter took ", (swig_end-swig_start)