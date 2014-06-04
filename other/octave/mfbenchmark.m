function mfbenchmark(h, b, seed)
%  mfbenchmark(h, b)   Benchmark medfilt1
%
%    h = half-window size
%    b = number of blocks
%    seed = random seed

rand('seed', seed);
k = 2*h+1;
n = k*b;
x = randi([0,intmax('uint32')], n, 1, 'uint32');
y = medfilt1(x, 1);  % make sure the function is already loaded
tic;
y = medfilt1(x, k);
e = toc;
fprintf('octave\t%u\t%u\tr-large\t%u\t%.5f\n', h, b, seed, e);
