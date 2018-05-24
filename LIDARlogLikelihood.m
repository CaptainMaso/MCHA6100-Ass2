function lp_any = LIDARlogLikelihood(y, yhat)
    global param
    lW = log(param.theta(1:4));
    Sigma = param.theta(5);
    Lambda = param.theta(6);
    lp_any = zeros(length(y),1);
    le = zeros(1,4);
    
    for ii = 1:length(y)
        le(1) = lW(1) + lp_hit(y(ii), yhat(ii), Sigma);
        le(2) = lW(2) + lp_short(y(ii), yhat(ii), Lambda);
        le(3) = lW(3) + lp_max(y(ii));
        le(4) = lW(4) + lp_rand(y(ii));
        lp_any(ii) = logSumExp(le);
    end
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