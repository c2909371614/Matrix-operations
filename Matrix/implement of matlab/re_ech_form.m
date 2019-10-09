function res = re_ech_form(a)
Size = size(a);
row = Size(1);
column = Size(2);

for i = 1:row-1
 %-----find the max val in the columns---
    mx = i;
    for j = i+1:row
        if abs(a(j, i)) > abs(a(mx,i))
            mx = j;
        end
        fprintf('mx = %d j = %d\n', mx, j);
    end
    
    a = trans_matrix(row, i, mx) * a;
    pivot = i;
    while a(i, pivot) == 0 && pivot <= column
        pivot = pivot + 1;
    end
    
    for j = i+1:row
        %-----row operation----
        temp = a(j, pivot) / a(i, pivot);
        a(j,:) = a(j,:) - a(i,:) * temp;
    end
    fprintf('%d-th step=\n', i);
    disp(a);
    res = a;
end

            
        