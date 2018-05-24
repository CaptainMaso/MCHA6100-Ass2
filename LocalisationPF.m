function x = LocalisationPF(y,U,map,M)
    N = size(y,2);

    xpp = zeros(3,M,N+1);
    xpf = zeros(3,M,N);

    xpp(1,:,1) = unifrnd(0,map.xmax, M, 1);
    xpp(2,:,1) = unifrnd(0,map.xmax, M, 1);
    xpp(3,:,1) = unifrnd(-pi,pi, M, 1);
    
    lW   = zeros(1,M);
    for t = 1:N
        % Evaluate Probability of current particles
        yt = y(:,t);
        
        parfor ii = 1:M
            xpp_m = xpp(:,ii,t);
            lW(ii) = measurementLikelihood_mex(yt, xpp_m, map);
        end
        
        W = exp(lW - logSumExp(lW));    % Normalise log-weights
        % Draw new particle from the mixture density
        ii = randsample(M, M, true, W);

        xpf(:,:,t) = xpp(:,ii,t);
        xpp(:,:,t+1) = processModel(xpf(:,:,t),U(:,t));
        t
    end
    x = xpp;

end

function x_next = processModel(x_t,U_t) % X = [E,N,Psi]
    global param
    
    x_next = x_t + [U_t(1).*cos(x_t(3,:)).*param.dT;
                    U_t(1).*sin(x_t(3,:)).*param.dT;
                    U_t(2).*ones(1,size(x_t,2)).*param.dT] ...
             + sqrt(param.Q)*randn(3,size(x_t,2));
end