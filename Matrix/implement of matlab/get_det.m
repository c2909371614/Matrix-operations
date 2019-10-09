function res=get_det(n)
syms x a res
res = sym(zeros(n));
for i = 1:n
    for j = 1:n
        if i == j
            res(i, j) = x;
        else
            res(i, j) = a;
        end
    end 
end
det(res)

          
    