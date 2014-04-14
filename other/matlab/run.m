f = fopen('result', 'w');
mfbenchmark(f, 10000, 10);
mfbenchmark(f, 1000, 100);
mfbenchmark(f, 100, 1000);
mfbenchmark(f, 10, 10000);
mfbenchmark(f, 1, 100000);
mfbenchmark(f, 1000, 10);
mfbenchmark(f, 100, 100);
mfbenchmark(f, 10, 1000);
mfbenchmark(f, 1, 10000);
fclose(f);
exit
