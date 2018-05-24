function y = SampleLidar(x, map)
global param
W = param.theta(1:4);
sigma = param.theta(5);
lambda = param.theta(6);

ii = randsample([1,2,3,4], 1, true, W);
guessok = 0;
while ~guessok
    switch ii
        case 1
            % Sample 1: Normal About Estimated Point
            [hx, hy] = CastRay(x,map);
            yhat = norm([hy - x(2),hx - x(1)]);
            y = (yhat + sigma*randn);
            if (y > 0 && y < param.ymax)
                guessok = 1;
            end
        case 2
            % Sample 2: Decreasing Exponential
            [hx, hy] = CastRay(x,map);
            yhat = norm([hy - x(2),hx - x(1)]);

            y = exprnd(1/lambda);
            if (y < yhat && y >= 0)
                guessok = 1;
            end
        case 3
            % Sample 3: Uniform after ymax
            y = random('unif', param.ymax - param.dymax, param.ymax + param.dymax);
            guessok = 1;
        case 4
            % Sample 4: Uniform 0 -> ymax
            y = random('unif', 0, param.ymax - param.dymax);
            guessok = 1;
    end
end