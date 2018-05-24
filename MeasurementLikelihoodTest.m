%clear variables;
global param
% Create Map Object
map.dx = 1;
map.dy = 1;
map.Nx = 11;
map.Ny = 11;
map.map = zeros(map.Ny, map.Nx);

map.map(:,[1,11]) = 1;
map.map([1,11],:) = 1;

map.map(3:5, 2:3) = 1;

map.xmax = map.Nx*map.dx;
map.ymax = map.Ny*map.dy;

%% Set known parameters
% LIDAR parameters
param.ymax = 120;       % Maximum range of LIDAR (m)
param.dymax = 0.01;
param.scanrate = 10;    % Scan Rate (Hz)
param.dT = 0.1;

% Model Parameters
param.Q = diag([0.05, 0.05, pi/4]);

%% Maximise LIDAR Calibration parameters
W = [0.6800
     0.1956
     0.0878
     0.0366];
W = W/sum(W);

Sigma0 = 0.1813;
Lambda0 = 0.7575;

param.theta = [W;Sigma0;Lambda0];

assert((sum(W) <= 1+eps) && (sum(W) >= 1-eps), 'W_i must sum to 1');

%% Test Measurement Likelihood
lp = zeros(1,91);
offset = linspace(-pi/4, pi/4, 1001);
t_test = 1;


y = zeros(91,1);
for ii = 1:91
    x_tii = [3;6;-pi/2] + [0;0;deg2rad(ii - 45 - 1)];
    y(ii) = SampleLidar(x_tii, map);
end

for ii = 1:length(offset)
    lp(ii) = measurementLikelihood(y, [3;6;-pi/2] + [0;0;offset(ii)], map);
end

%%
figure(1);
plot(rad2deg(offset), lp);
ylabel('Log Likelihood');
xlabel('Offset from heading');
% 
figure(2);
PlotMap(map);


function h = PlotMap(map)
    x = 0:map.dx:((map.Nx)*map.dx);
    y = 0:map.dy:((map.Ny)*map.dy);
    z = [map.map, zeros(map.Ny,1); zeros(1, map.Nx+1)];
    h = pcolor(x,y,1-z);
    set(h,'edgecolor','none')
    %grid off;
    colormap bone;
    xlim([0, (map.Nx)*map.dx]);
    ylim([0, (map.Ny)*map.dy]);
end





