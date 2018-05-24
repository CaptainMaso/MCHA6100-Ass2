function mse = scansampleerr(theta, X, map, scan, param)
N = size(X,2);
err = zeros(1,91*N);

for t = 1:N
    for i = 1:91
        xbar = X(:,t);
        xbar(3) = xbar(3) + deg2rad(i - 45 - 1);  
        err(t*i) = scan(i,t) - SampleLidar(xbar, map, theta, param);
    end
end

mse = sqrt(sum(err.^2));
end