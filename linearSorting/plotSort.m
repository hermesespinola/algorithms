clc;
clear;

source('../plotData.m');

plotPath = '../plots/bucket_sort'

plotData('./bigData/bucketRand.txt', 1000, 'BucketSort', ...
        'input size', 'clock ticks', ...
        {'Random', 'Worst', 'Best'}, plotPath, [1000 3]);

plotPath = '../plots/radix_sort'

plotData('./bigData/radixOut.txt', 1000, 'RadixSort', ...
        'input size', 'clock ticks', ...
        {'Random', 'Worst', 'Best'}, plotPath, [1000 3]);
