clear;
pi = 3.1415926536;

area3over4Circle = pi * 5 * 5 * 3 / 4;

a = 1;
b = - 2 * cosd(135);
c = -15;

x = (-b + sqrt(b*b - 4 * a * c))/(2*a);

height = x * cosd(45);
areaTriangle = 0.5 * height;


a = 1;
b = x;
c = 4;

thita = acosd( (a*a + c*c -b*b) / (2* a*c)   );
alpha = 90 - thita;

areaFanShape = pi * 16 * alpha / 360;

areaTotal = area3over4Circle + 2 * ( areaTriangle + areaFanShape)

% areaTotal = 76.5985