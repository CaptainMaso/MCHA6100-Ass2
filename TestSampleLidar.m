% Testing the realisations from SampleLidar

%% Create Map
map.dx = 1;
map.dy = 1;
map.Nx = 10;
map.Ny = 10;

map.map = zeros(map.Ny, map.Nx);
map.map(:,[1,end]) = 1;
map.map([1,end],:) = 1;

param.ymax = 15;
%% Test Map
W_i = [0.9, 0.08, 0.01, 0.01];          % Weights of the pdfs

Sigma2_i = (0.3)^2;                     % Variance on hit normal
Lambda_i = 10^-6;                         % Decay of early hit

assert((sum(W_i) <= 1+eps) && (sum(W_i) >= 1-eps), 'W_i must sum to 1');
Theta0 = [W_i, Sigma2_i, Lambda_i];

N = 10^5;
y = zeros(1,N);
for i = 1:N
    y(i) = SampleLidar([5;5;0], map, Theta, param);
end
figure(2);
hist(y, 1000);