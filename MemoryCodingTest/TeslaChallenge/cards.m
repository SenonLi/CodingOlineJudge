clear;

% x1^2 + 0.2x1 - 99 = 0

a = 1;
b = 0.2;
c = -99;

x1 = (-b + sqrt(b*b - 4 * a * c))/(2*a);

cosThita3 = (1 + 100 - x1^2) / (20);
cosThita4 = - cosThita3;

a = 1;
b = -2 * cosThita4;
c = -99;
x2 = (-b + sqrt(b*b - 4 * a * c))/(2*a);


cosThita5 = (1 + 100 - x2^2) / (20);
cosThita6 = - cosThita5;

a = 1;
b = -2 * cosThita6;
c = -99;
x3 = (-b + sqrt(b*b - 4 * a * c))/(2*a);

% cosThita7 = (1 + 100 - x3^2) / (20);


distance = 3 - x3 * cosThita5


