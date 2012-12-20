%module medianFilter
%{
  #define SWIG_FILE_WITH_INIT
  #include "medianFilter.h"
%}

%include "numpy.i"
%init %{
import_array();
%}

%apply (double* INPLACE_ARRAY1, int DIM1) {(double* array, int n)}; 
%apply (long* INPLACE_ARRAY1, int DIM1) {(long* array, int n)}; 
%apply (double* INPLACE_ARRAY2, int DIM1, int DIM2) {(double* array, int m, int n)}; 
%apply (long* INPLACE_ARRAY2, int DIM1, int DIM2) {(long* array, int m, int n)}; 
%include "medianFilter.h"