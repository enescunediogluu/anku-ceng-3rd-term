function[max r c]= functionExample2(X)

[m,n]=size(X);
max=X(1,1);

for i=1:m
    for j=1:n
        if X(i,j)>max
            max=X(i,j);
            r=i;
            c=j;
        end
    end
end


end