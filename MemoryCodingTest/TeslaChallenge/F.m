function xp = F(t, x)
xp = zeros(2,1);
xp(1) = x(2);
xp(2) = exp(t^2)+exp(x(1)^2);
