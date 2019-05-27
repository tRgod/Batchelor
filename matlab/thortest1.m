clear
clc
% importing data.
logdata=importdata('loog.txt', ' ');
log1data=importdata('loog1.txt',' ');
log100data=importdata('loog100.txt',' ')

% definning groundtrouth and the 
x2=log100data(:,1);
y2=log100data(:,2);
x1=log1data(:,1);
y1=log1data(:,2);
x=logdata(:,1);
y=logdata(:,2);
groundtrouth=0.5:1:25;
groundtrouthypos=[-1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 ];
grountrouthneg=[1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5];
time=logdata(:,3);
distvector=1:size(logdata);
distvector=distvector.*0.2;
distvector1=1:size(log1data);
distvector1=distvector1.*0.2;
distvector2=1:size(log100data);
distvector2=distvector2.*0.2;
Meantime=mean(time)
Maxtime=max(time)
MinTime=min(time)
Stdvariation=std(time)
xkorigeret=x+distvector';
x1korigeret=x1+distvector1';
x2korigeret=x2+distvector2';
hold on
plot(groundtrouth,groundtrouthypos,'o k',groundtrouth,grountrouthneg,'o k')
plot(xkorigeret,y,'*')
%plot(x1korigeret,y1,'*')
%plot(x2korigeret,y2,'*')
%legend('GroungTruth','1100 iteration','1000iterations','100 iterations')
