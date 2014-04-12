Median Filter
=============

(a.k.a. **sliding window median** or **running median**)

Benchmarking median filter algorithms,
see: http://cstheory.stackexchange.com/q/21730/74


Algorithms
----------

- "sort": O(n log k): sort blocks, do linear-time post-processing

- "tree": O(n log k): maintain balanced search trees

- "move": O(n k): maintain sorted vector


Compilation
-----------

The software is written in C++11. To compile it, you will need a
recent C++ compiler. For example, the following compilers should
work fine:

- g++ (GCC 4.7.3 or later). Tested with these versions:

    g++-4.7 (Ubuntu/Linaro 4.7.3-2ubuntu1~12.04) 4.7.3
    g++-4.8 (GCC) 4.8.2

- clang++ (LLVM 3.4 or later). Tested with these versions:

    Apple LLVM version 5.1 (clang-503.0.40) (based on LLVM 3.4svn)





**OS X** 10.9:

- Install "gcc48" and "scons" from Homebrew.

- Run "scons". This compiles with both Clang and GCC.


**Linux** with GCC 4.8:

- Run "bin/build-gcc".


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


Results
-------

Example:

    build-gcc-short/tester 10 500000 0 4 1
    build-gcc-short/tester 10 500000 1 4 1
    build-gcc-short/tester 10 500000 2 4 1

    build-gcc-short/tester 100000 5 0 4 1
    build-gcc-short/tester 100000 5 1 4 1
    build-gcc-short/tester 100000 5 2 4 1

    build-gcc-short/tester 1000000 5 0 4 1
    build-gcc-short/tester 1000000 5 1 4 1

    build-gcc-short/tester 10000000 5 0 4 1
    build-gcc-short/tester 10000000 5 1 4 1

Output:

    sort   10    500000   r-large   1   0.41762
    tree   10    500000   r-large   1   1.87928
    move   10    500000   r-large   1   0.58916

    sort   100000     5   r-large   1   0.10857
    tree   100000     5   r-large   1   1.28120
    move   100000     5   r-large   1   8.74902

    sort   1000000    5   r-large   1   1.66317
    tree   1000000    5   r-large   1   27.97039

    sort   10000000   5   r-large   1   25.30195
    tree   10000000   5   r-large   1   426.24067

Columns:

- algorithm
- h, the half-window size
- b, the number of blocks
- input data generator
- random seed
- time in seconds

Here window size is k = 2h + 1.
Input data is a vector with n = bk elements.


Plots
-----

**plot/summary-...**:

- x axis: half-window size
- y axis: running time
- blue: "sort" algorithm
- red: "tree" algorithm
- black: "move" algorithm

**plot/speedup-...**:

- x axis: half-window size
- y axis: speedup of "sort" vs. "tree"

In each plot:

- solid curve = median
- shaded area = 10% ... 90% region


License
-------

Copyright (c) 2014, Jukka Suomela.

Enjoy, use at your own risk.

To contact the author, see http://users.ics.aalto.fi/suomela/


Acknowledgements
----------------

Computer resources were provided by the Aalto University
School of Science "Science-IT" project.
