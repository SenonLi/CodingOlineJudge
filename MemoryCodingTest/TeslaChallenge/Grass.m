clear;
pi = 3.1415926536;

rightSide = 100 * pi - 250.000;

loopCount = 0;

xMin = 7.50001;
xMax = 10.0001;

xMiddle = (xMin + xMax) / 2;
xLeftM = (xMin + xMiddle) / 2;
xRightM = (xMiddle + xMax) / 2;


thita_M = acosd(xMiddle / 20);
leftSide_M = 10 * pi * thita_M / 18.0 - 5 * xMiddle * sind(thita_M);
errorM = abs(leftSide_M - rightSide);


thita_L = acosd(xLeftM / 20);
leftSide_L = 10 * pi * thita_L / 18.0 - 5 * xLeftM * sind(thita_L);
errorL = abs(leftSide_L - rightSide);

thita_R = acosd(xRightM / 20);
leftSide_R = 10 * pi * thita_R / 18.0 - 5 * xRightM * sind(thita_R);
errorR = abs(leftSide_R - rightSide);



while (errorM > 0.00005)
    if (errorL < errorR)    
        xMax = xMiddle;
    else 
        xMin = xMiddle;
    end
    
    
    xMiddle = (xMin + xMax) / 2;
    xLeftM = (xMin + xMiddle) / 2;
    xRightM = (xMiddle + xMax) / 2;


    thita_M = acosd(xMiddle / 20);
    leftSide_M = 10 * pi * thita_M / 18.0 - 5 * xMiddle * sind(thita_M);
    errorM = abs(leftSide_M - rightSide);


    thita_L = acosd(xLeftM / 20);
    leftSide_L = 10 * pi * thita_L / 18.0 - 5 * xLeftM * sind(thita_L);
    errorL = abs(leftSide_L - rightSide);

    thita_R = acosd(xRightM / 20);
    leftSide_R = 10 * pi * thita_R / 18.0 - 5 * xRightM * sind(thita_R);
    errorR = abs(leftSide_R - rightSide);
   
    
    loopCount = loopCount + 1;
end



%% x == 9.6851











