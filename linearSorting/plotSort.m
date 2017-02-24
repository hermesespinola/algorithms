clc;
clear;

source('../plotData.m');

plotPath = '../plots/bucket_sort'

% Random
plotData('./bigData/bucketRand.txt', 1000, 'BucketSort', ...
          'input size', 'clock ticks', ...
          {'Worst', 'Best', 'Random'}, plotPath, [1000 3]);

% % Best case
% plotData('./bigData/outBest.txt', 'Priority Queue Best Input', ...
% 'input size', 'clock ticks', ...
% {'insert', 'maximum', 'increase key', 'extract max'}, plotPath);
%
% % Worst case
% plotData('./bigData/outWorst.txt', 'Priority Queue Worst Input', ...
% 'input size', 'clock ticks', ...
% {'insert', 'maximum', 'increase key', 'extract max'}, plotPath);
