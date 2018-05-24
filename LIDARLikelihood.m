function p_any = LIDARLikelihood(y, yhat)
    global param
    W = param.theta(1:4);
    Sigma = param.theta(5);
    Lambda = param.theta(6);
    p_any = zeros(length(y),1);
    
    for ii = 1:length(y)
       p_any(ii) = W(1) * p_hit(y(ii), yhat(ii), Sigma) + ...
                   W(2) * p_short(y(ii), yhat(ii), Lambda) + ...
                   W(3) * p_max(y(ii)) + ...
                   W(4) * p_rand(y(ii));
    end
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