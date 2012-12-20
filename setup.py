from distutils.core import setup, Extension
import numpy
import os

os.environ['CC'] = 'g++';
setup( name = 'medianFilter',
       version = '1.0',
       description = 'Fast 1D median filter using min/max heap',
       ext_modules = [Extension( '_medianFilter',
                                 ['medianFilter.cpp', 'medianFilter.i'],
                                 include_dirs = [numpy.get_include(),'.'],
                                 swig_opts = ['-c++'] )],
      py_modules = ['medianFilter'] )