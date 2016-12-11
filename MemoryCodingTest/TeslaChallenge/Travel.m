matrix = dlmread('Matrix.txt', '\t', 0, 0);

total = 6*5*4*3*2 + 1;
flag = ones(7, 1);
begin = 1;
flag(begin, 1) = 0;


data = zeros(total, 1);

for first = 1 : 7
    
    for second = 1 : 7
       
        if (flag(first) == 1)
            data(first) = matrix(1, first);
    
    
    end
end
