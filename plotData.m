function plotData(filePath, t, xlbl, ylbl, legends, targetPath)
%PLOTDATA Plots the data points in a file into a new figure
%   PLOTDATA(filePath) plots the data points and gives the figure axes labels of
%   population and profit.

data = load(filePath);
x = data(:, 1);
y = data(:, 2:end);

hf = figure; % open a new figure window

plot(x, y);
hold on;
xlabel(xlbl);  ylabel(ylbl);
title(t);
h = legend (legends);
name = [targetPath '/' regexprep(t, '[^\w'']', '') '.jpg'];
print(name, '-djpg')

fprintf('Program paused. Press enter to close.\n');
pause;
close all;

% ============================================================

end
