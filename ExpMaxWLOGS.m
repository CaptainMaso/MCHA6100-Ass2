function ThetaM = ExpMaxWLOGS(sigma0, lambda0, X, map, scan)
    N = size(scan,1)*size(scan,2);
    le = zeros(4,N);
    sigma = sigma0;
    lambda = lambda0;
    lW = [1/4; 1/4; 1/4; 1/4];
    
    lastExpect = 0;
    expectation = 1;
    k = 0;
    
    lp_all = zeros(4,N);
    
    yhat = zeros(1,N);
    for t = 1:size(scan,2)
        for ii = 1:size(scan,1)
            tii = (t-1)*91 + ii;
            xbar = X(:,t);
            xbar(3) = xbar(3) + deg2rad(ii - 45 - 1);  

            [hx, hy] = CastRay(xbar,map);
            yhat(tii) = norm([hy - xbar(2),hx - xbar(1)]);
        end
    end
    
    ytii = scan(:)';
    
    while expectation - lastExpect > 10^-6
        k = k+1;
        for t = 1:size(scan,2)
            for ii = 1:size(scan,1)
                tii = (t-1)*91 + ii;
                lp_all(1,tii) = lp_hit(ytii(tii), yhat(tii), sigma);
                lp_all(2,tii) = lp_short(ytii(tii), yhat(tii), lambda);
                lp_all(3,tii) = lp_max(ytii(tii));
                lp_all(4,tii) = lp_rand(ytii(tii));
                
                le(:, tii) = lp_all(:,tii) -logSumExp(lp_all(:,tii)');
            end
        end
        
        lW(1) = logSumExp(le(1,:));
        lW(2) = logSumExp(le(2,:));
        lW(3) = logSumExp(le(3,:));
        lW(4) = logSumExp(le(4,:));
        lW = lW - logSumExp(lW');
        
        lastExpect = expectation;
        expectation = logSumExp(logSumExp(lW+lp_all)');
        [k, expectation]
        
        sigma = exp(0.5*(logSumExp((le(1,:) + 2*log(abs(ytii-yhat)))) - logSumExp(le(1,:))));
        lambda = exp(logSumExp(le(2,:)) - logSumExp(le(2,:) + log(ytii)));
    end
    
    ThetaM = [exp(lW);sigma;lambda];
end

function lp = lp_hit(y, yhat, sigma)
    global param
    if y > 0 && y < param.ymax - param.dymax
        eta = normcdf(param.ymax, yhat, sigma);
        lp = (-log(2*pi*sigma.^2) - ((y - yhat)./sigma).^2)/2 - log(eta);
    else
        lp = 0; 
    end
end

function lp = lp_short(y, yhat, lambda)
    if y >= 0 && y <= yhat
        lp = log(lambda) - lambda*y - log(1-exp(-lambda*yhat));
    else
        lp = -inf;
    end
end
function lp = lp_max(y)
    global param
    if (y > param.ymax - param.dymax) && (y <= param.ymax + param.dymax)
        lp = -log(2*param.dymax);
    else
        lp = -inf;
    end
end

function lp = lp_rand(y)
    global param
    if (y >= 0) && (y <= param.ymax - param.dymax)
        lp = -log(param.ymax);
    else
        lp = -inf;
    end
end