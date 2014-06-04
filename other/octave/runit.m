pkg load signal;
for seed = 1:10
    mfbenchmark(1, 10000, seed);
    mfbenchmark(10, 1000, seed);
    mfbenchmark(100, 100, seed);
    mfbenchmark(1000, 10, seed);
    mfbenchmark(1, 100000, seed);
    mfbenchmark(10, 10000, seed);
    mfbenchmark(100, 1000, seed);
    mfbenchmark(1000, 100, seed);
    mfbenchmark(10000, 10, seed);
endfor
