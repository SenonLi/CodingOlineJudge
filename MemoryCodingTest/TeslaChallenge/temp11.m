clear;
[t, x] = ode45('F', [0, 0.1], [0, 0]);
% [t, x(:,1)]

plot(t, x(:,1))
