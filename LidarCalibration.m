%clear variables;
global param
%% Load Map data
data = load('ass2data.mat');

% True state data
x_t = [data.x;data.y;data.h]; % [x,y,psi]

N = size(x_t,2);

% Create Map Object
map.dx = 0.2;
map.dy = 0.2;
map.Nx = size(data.map, 2);
map.Ny = size(data.map, 1);
map.map = data.map;

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

dX = zeros(3,N);
u_t = zeros(1,N);
w_t = zeros(1,N);
for t = 1:N-1
    dX(:,t) = (x_t(:,t+1) - x_t(:,t))/param.dT;
    u_t(t) = norm(dX(1:2,t));
    w_t(t) = dX(3,t);
end

%% Maximise LIDAR Calibration parameters
% W = [0.6800
%      0.1956
%      0.0878
%      0.0366];
% W = W/sum(W);

Sigma0 = 0.5;
Lambda0 = 0.5;

Theta = ExpMax(Sigma0, Lambda0, x_t, map, data.scan);

W = Theta(1:4)
Sigma = Theta(5)
Lambda = Theta(6)

param.theta = [W;Sigma;Lambda];

assert((sum(W) <= 1+eps) && (sum(W) >= 1-eps), 'W_i must sum to 1');

%% Plot Map

%% Test Measurement Likelihood
lp = zeros(1,91);
offset = linspace(-pi, pi, 1001);
t_test = 4;
for ii = 1:1001
    lp(ii) = measurementLikelihood(data.scan(:,t_test), x_t(:,t_test) + [0;0;offset(ii)], Theta, map);
end

figure(3);
plot(rad2deg(offset), lp);

%%
for t = 1:N
    for i = 1:91
        xbar = x_t(:,t);
        xbar(3) = xbar(3) + deg2rad(i - 45 - 1);        
        
        %[hit.x(i,t), hit.y(i,t)] = CastRay(xbar, map);
        dist = SampleLidar(xbar, map, Theta, param);
        hit.x(i,t) = xbar(1) + dist*cos(xbar(3));
        hit.y(i,t) = xbar(2) + dist*sin(xbar(3));
        
        % Get Actual Reading
        shit.x(i,t) = xbar(1) + data.scan(i,t)*cos(xbar(3));
        shit.y(i,t) = xbar(2) + data.scan(i,t)*sin(xbar(3));
    end
end

% Plot all the data
figure(2);
hold on;
PlotMap(map);

%h1 = plot([squeeze(hit.x(:,1))'; squeeze(hit.x0(:,1))'], [squeeze(hit.y(:,1))'; squeeze(hit.y0(:,1))'], 'k-x','linewidth', 0.2);
plot_hit = plot(hit.x(:,1), hit.y(:,1), 'xr', 'MarkerSize', 10,'linewidth', 2);
plot_shit = plot(shit.x(:,1), shit.y(:,1), 'xg', 'MarkerSize', 10, 'linewidth', 2);
plot_bot = plot(x_t(1,1), x_t(2,1), 'bo', 'MarkerSize', 16);
plot_botdir = plot([x_t(1,1), x_t(1,1) + 5*cos(x_t(3,1))], [x_t(2,1), x_t(2,1) + 5*sin(x_t(3,1))], 'b-');

for t = 2:N
    if ~ishandle(2)
        return
    end
    %set(h1, 'XData', {squeeze(hit.x(:,t)), squeeze(hit.x0(:,t))'}, 'YData', {squeeze(hit.y(:,t))'; squeeze(hit.y0(:,t))'});
    set(plot_hit, 'XData', hit.x(:,t), 'YData', hit.y(:,t));
    set(plot_shit, 'XData', shit.x(:,t), 'YData', shit.y(:,t));
    set(plot_bot, 'XData', x_t(1,t), 'YData', x_t(2,t));
    set(plot_botdir, 'XData', [x_t(1,t), x_t(1,t) + 5*cos(x_t(3,t))], 'YData', [x_t(2,t), x_t(2,t) + 5*sin(x_t(3,t))]);
    
    drawnow limitrate;
    pause(1/param.scanrate);
end
hold off;

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