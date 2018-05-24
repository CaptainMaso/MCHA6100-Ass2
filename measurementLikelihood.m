function lp_x = measurementLikelihood(yt, x_t, map)
    if (~checkStateConstraints(x_t, map))
        yhat = zeros(91,1);
        for ii = 1:91
                [hx,hy] = CastRay(x_t + [0;0;deg2rad(ii - 45 - 1)], map);
                yhat(ii) = norm([hx;hy] - x_t(1:2));
        end
        lp_x = logSumExp(LIDARlogLikelihood(yt, yhat)');
    else
        lp_x = -inf;
    end
end
function clipping = checkStateConstraints(x_t,map)
    xi = floor(x_t(1)/map.dx)+1;
    yi = floor(x_t(2)/map.dy)+1;
    if (xi > map.Nx || xi <= 0 || yi > map.Ny || yi <= 0)
        clipping = 1;
    else
        if (map.map(yi,xi) == 1)
            clipping = 1;
        else
            clipping = 0;
        end
    end
    
end