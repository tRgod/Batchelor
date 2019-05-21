clear
clc
logdata=importdata('loog.txt', ' ');
x=logdata(:,1);
y=logdata(:,2);
time=logdata(:,3);
distvector=1:size(logdata);
distvector=distvector.*0.2;
Meantime=mean(time)
Maxtime=max(time)
MinTime=min(time)
Stdvariation=std(time)
xkorigeret=x+distvector'

plot(xkorigeret,y,'*')