function res = GaussEli(a)
res = re_ech_form(a);
Size = size(a);
row = Size(1);
column = Size(2);

for i = 1:row
    %--find the pivot position---
    pivot = i;
    while pivot < column && ~res(i, pivot)
        pivot = pivot + 1;
    end
    res(i,:) = res(i,:) / res(i, pivot);%let leading enty to zero
    %---row operation----
    for j =1 : row
        if j == i
            continue;
        end
        res(j,:) = res(j,:) - res(i,:) * res(j, pivot);
    end
end
        
    