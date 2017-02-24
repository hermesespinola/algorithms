function plotData(filePath, maxIn, t, xlbl, ylbl, legends, targetPath, reshapeSize)
%PLOTDATA Plots the data points in a file into a new figure
%   PLOTDATA(filePath) plots the data points and gives the figure axes labels of
%   population and profit.

data = load(filePath);

x = data(1:maxIn, 1);

if exist('reshapeSize') && ~isempty(reshapeSize)
  y = reshape(data(:, 2:end), reshapeSize);
else
  y = data(:, 2:end);
end
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
