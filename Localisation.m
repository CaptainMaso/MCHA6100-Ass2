global param
%% Load Map data
data = load('ass2dataLocalise.mat');

% Create Map Object
map.dx = 0.2;
map.dy = 0.2;
map.Nx = size(data.map, 2);
map.Ny = size(data.map, 1);
map.map = data.map;

map.xmax = map.Nx*map.dx;
map.ymax = map.Ny*map.dy;

% Create other necessary variables
ytii = data.scan;
U = [data.v; data.w];

%% Set known parameters
% LIDAR parameters
param.ymax = 120;       % Maximum range of LIDAR (m)
param.dymax = 0.01;
param.scanrate = 10;    % Scan Rate (Hz)
param.dT = 0.1;

% EM LIDAR Parameters
W = [0.6800
     0.1956
     0.0878
     0.0366];
W = W/sum(W);
 
Sigma = 0.1813;
Lambda = 0.7575;

param.theta = [W;Sigma;Lambda];

% Model Parameters
param.Q = diag([0.05, 0.05, pi/4]);


%% Run PF
x_pf = LocalisationPF(ytii(:,1:500), U, map, 1e3);

%% Plot all the things
figure(2);
hold on;
PlotMap(map);

particles = plot(x_pf(1,:,1), x_pf(2,:,1), '.');
hold off
for t = 2:size(x_pf,3)
    if ~ishandle(2)
        return
    end
    %set(h1, 'XData', {squeeze(hit.x(:,t)), squeeze(hit.x0(:,t))'}, 'YData', {squeeze(hit.y(:,t))'; squeeze(hit.y0(:,t))'});
    set(particles, 'XData', x_pf(1,:,t), 'YData', x_pf(2,:,t));
    title(['t =' num2str(t)]);
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