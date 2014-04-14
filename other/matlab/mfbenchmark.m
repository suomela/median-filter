function mfbenchmark(f, h, b)
%  mfbenchmark(h, b)   Benchmark medfilt1
%
%    f = log file
%    h = half-window size
%    b = number of blocks

k = 2*h+1;
n = k*b;
x = randi([0,intmax('uint32')], n, 1);
tic;
y = medfilt1(x, k);
e = toc;
fprintf(f, 'matlab\t%u\t%u\tr-large\t0\t%.5f\n', h, b, e);
