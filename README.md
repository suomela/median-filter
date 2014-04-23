Median Filter
=============

(a.k.a. **sliding window median**, **running median filter**,
and **rolling median filter**)

Benchmarking median filter algorithms,
see: http://cstheory.stackexchange.com/q/21730/74


Problem
-------

Input:

  - vector x with n elements
  - window size k

Output:

  - vector y with n-k+1 elements
  - y[i] is the median of x[i], x[i+1], ..., x[i+k−1].

See: http://en.wikipedia.org/wiki/Median_filter


Algorithms
----------

  - "sort": O(n log k): sort blocks, do linear-time post-processing

  - "heap": O(n log k): maintain a maxheap + minheap pair

  - "tree": O(n log k): maintain balanced search trees

  - "move": O(n k): maintain a sorted vector


### Sort algorithm

This algorithm is discussed here:

  - http://cstheory.stackexchange.com/a/21991/74


### Heap algorithm

The basic idea is to maintain a maxheap + minheap pair.
The original idea is from:

  - W. Hardle and W. Steiger (1995):
    "Algorithm AS 296: Optimal median smoothing",
    Journal of the Royal Statistical Society, Series C
    (Applied Statistics), 44(2):258-264
  - http://dx.doi.org/10.2307/2986349
  - http://www.jstor.org/stable/2986349

This algorithm is used in R function runmed, with parameter
algorithm = "Turlach".

The present implementation is by AShelly:

  - http://stackoverflow.com/a/5970314/383299
  - https://gist.github.com/ashelly/5665911

It was further adapted by Colin Raffel, and this is the version that
we use (almost verbatim):

  - https://github.com/craffel/median-filter


Compilation
-----------

The software is written in C++11. To compile it, you will need a
recent C++ compiler. For example, the following compilers should
work fine:

  - g++ (GCC 4.7.3 or later). Tested with these versions:

        g++-4.7 (Ubuntu/Linaro 4.7.3-2ubuntu1~12.04) 4.7.3
        g++-4.8 (GCC) 4.8.2
        g++-4.9 (GCC) 4.9.0

  - clang++ (LLVM 3.4 or later). Tested with these versions:

        Apple LLVM version 5.1 (clang-503.0.40) (based on LLVM 3.4svn)

For OS X 10.9.2, you can get the right versions of the compilers
from the following sources:

  - clang++: from Apple
  - g++-4.9: from Homebrew ("brew install gcc49")

Depending on your C++ compiler and operating system, use one of
the following scripts to compile this software.

**OS X**:

  - "bin/build-clang": compiles with "clang++"
  - "bin/build-gcc-4.8-osx": compiles with "g++-4.8"
  - "bin/build-gcc-4.9-osx": compiles with "g++-4.9"

**Linux**:

  - "bin/build-gcc": compiles with "g++"
  - "bin/build-gcc-4.7": compiles with "g++-4.7"
  - "bin/build-gcc-4.8": compiles with "g++-4.8"
  - "bin/build-gcc-4.9": compiles with "g++-4.9"

You can also try to use "scons" to compile everything. The build
scripts are configured for OS X platforms that have both clang++
and g++-4.9 installed. You can get both scons and g++-4.9 from
Homebrew.


Versions
--------

  - build-clang-short: compiled with Clang, 32-bit data
  - build-clang-long: compiled with Clang, 64-bit data
  - build-gcc-short: compiled with GCC, 32-bit data
  - build-gcc-long: compiled with GCC, 64-bit data


Tools
-----

**verify**: does some sanity-checking and makes sure that all three
algorithms produce the same output. Use the command line parameter
for larger tests, and another parameter to skip the slowest
algorithm. Examples:

    build-gcc-short/verify
    build-gcc-short/verify 10
    build-gcc-short/verify 100 x

**tester**: benchmarking with different parameter values and
different input data generators. Run without command line parameters
for brief usage instructions.


Examples
--------

See "bin/examples"

Output (fastest algorithms marked with a star):

    sort    10      500000   r-asc     1     0.37903
    heap    10      500000   r-asc     1     0.33694 *
    tree    10      500000   r-asc     1     1.92399
    move    10      500000   r-asc     1     0.61234
    sort    10      500000   r-large   1     0.40114
    heap    10      500000   r-large   1     0.33726 *
    tree    10      500000   r-large   1     1.97069
    move    10      500000   r-large   1     0.59606

    sort    100000       5   r-asc     1     0.08125 *
    heap    100000       5   r-asc     1     0.23712
    tree    100000       5   r-asc     1     0.66017
    move    100000       5   r-asc     1    26.93506
    sort    100000       5   r-large   1     0.08979 *
    heap    100000       5   r-large   1     0.09957
    tree    100000       5   r-large   1     1.53184
    move    100000       5   r-large   1     9.01672

    sort    1000000      5   r-asc     1     0.91729 *
    heap    1000000      5   r-asc     1     3.73655
    tree    1000000      5   r-asc     1     8.75793
    sort    1000000      5   r-large   1     1.48117
    heap    1000000      5   r-large   1     1.32437 *
    tree    1000000      5   r-large   1    29.67124

    sort    10000000     5   r-asc     1     9.27875 *
    heap    10000000     5   r-asc     1    44.77312
    tree    10000000     5   r-asc     1    95.78014
    sort    10000000     5   r-large   1    23.72148
    heap    10000000     5   r-large   1    14.37096 *
    tree    10000000     5   r-large   1   441.65488


Columns:

  - algorithm
  - h, the half-window size
  - b, the number of blocks
  - input data generator
  - random seed
  - time in seconds

Here window size is k = 2h + 1.
Input data is a vector with n = bk elements.

In this example we used the following generators:

  - "r-asc": monotonically incresing sequence + random noise
  - "r-large": large random numbers


Plots
-----

  - x axis: half-window size
  - y axis: running time
  - blue: "sort" algorithm
  - green: "heap" algorithm
  - red: "tree" algorithm
  - black: "move" algorithm
  - solid curve = median
  - shaded area = 10% ... 90% region


License
-------

### Other parts

Copyright (c) 2014, Jukka Suomela.

Enjoy, use at your own risk.

To contact the author, see http://users.ics.aalto.fi/suomela/


### HeapMedian.cc

Based on: https://github.com/craffel/median-filter (file Mediator.h)

    Sliding median filter
    Created 2012 by Colin Raffel
    Portions Copyright (c) 2011 ashelly.myopenid.com under
    <http://www.opensource.org/licenses/mit-license>


Acknowledgements
----------------

Computer resources were provided by the Aalto University
School of Science "Science-IT" project.

Thanks to David Eppstein, Geoffrey Irving, Pat Morin, and Saeed
for comments and discussions here:

  - http://cstheory.stackexchange.com/q/21730/74
  - https://plus.google.com/+JukkaSuomela/posts/JWtBkytfJsA

