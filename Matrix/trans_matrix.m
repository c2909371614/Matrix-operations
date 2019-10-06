function res = trans_matrix(size, trans_x, trans_y)
%----get the trans-matrix of swap x-th row and y-th row---
    res = zeros(size);
    for i = [1:size]
        if i == trans_x
            res(trans_x, trans_y) = 1;
            continue;
        elseif i == trans_y
            res(trans_y, trans_x) = 1;
            continue;
        end   
        res(i, i) = 1;
    end