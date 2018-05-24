function [hx,hy] = CastRay(X,map)
x0 = X(1);
y0 = X(2);
h0 = X(3);

dx = cos(h0);
dy = sin(h0);

if ((dy < 10^-6) && (dy > -10^-6))
    dy = 0; 
end

if (dx < 10^-6 && dx > -10^-6)
    dx = 0; 
end

xi = floor(x0/map.dx)+1;
yi = floor(y0/map.dy)+1;

if dx == 0
    xinc = 0;
    error = inf;
elseif dx > 0
    xinc = 1;
    error = (xi - (x0/map.dx + 1) + 1)*abs(dy);
else % dx < 0
    xinc = -1;
    error = ((x0/map.dx + 1) - xi)*abs(dy);
end

if dy == 0
    yinc = 0;
    error = error - inf;
elseif dy > 0
    yinc = 1;
    error = error - (yi - (y0/map.dy + 1) + 1)*abs(dx);
else % dy < 0
    yinc = -1;
    error = error - ((y0/map.dx + 1) - yi)*abs(dx);
end

top_or_side = 0;

while (map.Nx >= xi) && (0 < xi) && (map.Ny >= yi) && (0 < yi) && (map.map(yi,xi) ~= 1)
    if error > 0
        top_or_side = 1; %Hit top or bottom
        yi = yi + yinc;
        error = error - abs(dx);
    else
        top_or_side = 0; %Hit one of the sides
        xi = xi + xinc;
        error = error + abs(dy);
    end
    %plot((xi-0.5)*map.dx, (yi-0.5)*map.dy, '.g');
end

if dx ~= 0
    m = (dy/dx);
else
    m = inf;
end
b = y0 - m*x0;

if top_or_side == 1
    % Hit TOP or BOTTOM
    if dy > 0
        hy = floor(yi-0.5)*map.dy;
    else
        hy = ceil(yi-0.5)*map.dy;
    end
    if m == inf
        hx = x0;
    else
        hx = (hy - b)/m;
    end
else
    % Hit SIDE
    if dx > 0
        hx = floor(xi-0.5)*map.dx;
    else
        hx = ceil(xi-0.5)*map.dx;
    end
    hy = m*hx + b;
end

