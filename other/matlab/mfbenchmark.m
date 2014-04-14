function mfbenchmark(f, h, b)
%  mfbenchmark(f, h, b)   Benchmark medfilt1
%
%    f = log file
%    h = half-window size
%    b = number of blocks

seed = 1;
randn('seed', seed);
k = 2*h+1;
n = k*b;
x = randi([0,intmax('uint32')], n, 1);
y = medfilt1(x, 1);  % make sure the function is already loaded
tic;
y = medfilt1(x, k);
e = toc;
fprintf(f, 'matlab\t%u\t%u\tr-large\t%u\t%.5f\n', h, b, seed, e);
