function ThetaM = ExpMax(sigma0, lambda0, X, map, scan)
    N = size(scan,1)*size(scan,2);
    e = zeros(4,N);
    sigma = sigma0;
    lambda = lambda0;
    W = [1/4; 1/4; 1/4; 1/4];
    
    lastExpect = 0;
    expectation = 1;
    k = 0;
    
    p_all = zeros(4,N);
    
    yhat = zeros(1,N);
    
    for t = 1:size(scan,2)
            for ii = 1:size(scan,1)
                xbar = X(:,t);
                xbar(3) = xbar(3) + deg2rad(ii - 45 - 1);  
                
                [hx, hy] = CastRay(xbar,map);
                yhat((t-1)*91 + ii) = norm([hy - xbar(2),hx - xbar(1)]);
            end
    end
    ytii = scan(:)';
    
    while expectation - lastExpect > 1e-6
        k = k+1;
        
        for t = 1:size(scan,2)
            for ii = 1:size(scan,1)
                tii = (t-1)*91 + ii;
                p_all(1,tii) = p_hit(ytii(tii), yhat(tii), sigma);
                p_all(2,tii) = p_short(ytii(tii), yhat(tii), lambda);
                p_all(3,tii) = p_max(ytii(tii));
                p_all(4,tii) = p_rand(ytii(tii));
                e(:, tii) = p_all(:,tii)./sum(p_all(:,tii));
            end
        end
        
        W(1) = sum(e(1,:));
        W(2) = sum(e(2,:));
        W(3) = sum(e(3,:));
        W(4) = sum(e(4,:));
        W = W/sum(W);
        
        lastExpect = expectation;
        expectation = log(sum(sum(W.*p_all)));
        [k, expectation]
        
        sigma = sqrt((sum(e(1,:).*(ytii-yhat).^2))/sum(e(1,:)));
        lambda = sum(e(2,:))/sum(e(2,:).*ytii);
    end
    
    ThetaM = [W;sigma;lambda];
end

function p = p_hit(y, yhat, sigma)
    global param
    if y > 0 && y < param.ymax - param.dymax
        eta = 1/normcdf(param.ymax, yhat, sigma);
        p = eta.*normpdf(y, yhat, sigma);
    else
        p = 0; 
    end
end

function p = p_short(y, yhat, lambda)
    if y >= 0 && y <= yhat
        eta = 1/(1-exp(-lambda*yhat));
        p = eta*exppdf(y,1/lambda);
    else
        p = 0;
    end
end

function p = p_max(y)
    global param
    p = 1.0*((y > param.ymax - param.dymax) & (y <= param.ymax + param.dymax))/(2*param.dymax);
end

function p = p_rand(y)
    global param
    p = 1.0*((y >= 0) & (y <= param.ymax - param.dymax))/param.ymax;
end
