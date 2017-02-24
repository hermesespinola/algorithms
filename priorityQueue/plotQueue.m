clc;
clear;

source('../plotData.m');

plotPath = '../plots/priority_queue';

% Random
plotData('./bigData/outRand.txt', 1000, 'Priority Queue Random Input', ...
          'input size', 'clock ticks', ...
          {'insert', 'maximum', 'increase key', 'extract max'}, plotPath);

% Best case
plotData('./bigData/outBest.txt', 1000, 'Priority Queue Best Input', ...
'input size', 'clock ticks', ...
{'insert', 'maximum', 'increase key', 'extract max'}, plotPath);

% Worst case
plotData('./bigData/outWorst.txt', 1000, 'Priority Queue Worst Input', ...
'input size', 'clock ticks', ...
{'insert', 'maximum', 'increase key', 'extract max'}, plotPath);
