f = fopen('result', 'w');
mfbenchmark(f, 1, 10000);
mfbenchmark(f, 2, 5000);
mfbenchmark(f, 5, 2000);
mfbenchmark(f, 10, 1000);
mfbenchmark(f, 20, 500);
mfbenchmark(f, 50, 200);
mfbenchmark(f, 100, 100);
mfbenchmark(f, 200, 50);
mfbenchmark(f, 500, 20);
mfbenchmark(f, 1000, 10);
mfbenchmark(f, 2000, 5);
mfbenchmark(f, 5000, 2);
mfbenchmark(f, 10000, 1);
fclose(f);
exit
