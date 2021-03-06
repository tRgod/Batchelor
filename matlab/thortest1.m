clear
clc
close
% importing data
logdata=importdata('loognoAxisandEpsAngle100iterations.txt', ' ');
log1data=importdata('loognoAxisandEpsAngle200iterations.txt', ' ');
log2data=importdata('loognoAxisandEpsAngle400iterations.txt', ' ');
log3data=importdata('loognoAxisandEpsAngle800iterations.txt', ' ');
%log4data=importdata('loog2.txt',' ');
log4data=importdata('loognoAxisandEpsAngle1000iterations.txt', ' ');
log5data=importdata('loognoAxisandEpsAngle1100iterations.txt', ' ');
%logdata=importdata('loogwithEpsAngle.txt', ' ');
%logdata=importdata('loog.txt',' ');
%logdata=importdata('loogwithAxis.txt', ' ');
%log1data=importdata('loog1.txt',' ');
%log100data=importdata('loog100.txt',' ');

% definning groundtrouth and the 
x=logdata(:,1);
y=logdata(:,2);
x1=log1data(:,1);
y1=log1data(:,2);
x2=log2data(:,1);
y2=log2data(:,2);
x3=log3data(:,1);
y3=log3data(:,2);
x4=log4data(:,1);
y4=log4data(:,2);
x5=log5data(:,1);
y5=log5data(:,1);
groundtrouth=0.5:1:24;
groundtrouthypos=[-1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 ];
grountrouthneg=[1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 ];
time=logdata(:,3);
time1=log1data(:,3);
time2=log2data(:,3);
time3=log3data(:,3);
time4=log4data(:,3);
time5=log5data(:,3);
distvector=0:size(logdata)-1;
distvector=distvector.*0.2;
Meantime=mean(time)
Meantime1=mean(time1)
Meantime2=mean(time2)
Meantime3=mean(time3)
Meantime4=mean(time4)
Meantime5=mean(time5)
Maxtime=max(time)
Maxtime1=max(time1)
Maxtime2=max(time2)
Maxtime3=max(time3)
Maxtime4=max(time4)
Maxtime5=max(time5)
Mintime=min(time)
Mintime1=min(time1)
Mintime2=min(time2)
Mintime3=min(time3)
Mintime4=min(time4)
Mintime5=min(time5)
Stdvariation=std(time)
Stdvariation1=std(time1)
Stdvariation2=std(time2)
Stdvariation3=std(time3)
Stdvariation4=std(time4)
Stdvariation5=std(time5)
xkorigeret=x+distvector';
xkorigeret1=x1+distvector';
xkorigeret2=x2+distvector';
xkorigeret3=x3+distvector';
xkorigeret4=x4+distvector';
xkorigeret5=x5+distvector';
hold on
grid on
grid minor
plot(groundtrouth,groundtrouthypos,'o k',groundtrouth,grountrouthneg,'o k')
plot(xkorigeret,y, '* r')
plot(xkorigeret1,y1, '* g')
plot(xkorigeret2,y2, '* b')
plot(xkorigeret3,y3, '* c')
plot(xkorigeret4,y4, '* m')
plot(xkorigeret5,y5, '* k')
legend({'GroundTruthPos','GroundTruthNeg','100 iteration','200 iteration','400 iteration','800 iteration','1000 iteration','1100 iteration'},'Location','east')
title('Plot of different model iterations')
xlabel('Distance [m] ')
ylabel('Distance [m]')