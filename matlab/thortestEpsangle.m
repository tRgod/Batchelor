clc 
clear 
close
logdata1=importdata('loogWithAxisAndEpsAngle005.txt', ' ');
logdata2=importdata('loogwithAxisAndEpsAngle0175.txt', ' ');
%logdata3=importdata('loogwithAxisAndEpsAngle02.txt', ' ');
%logdata4=importdata('loogwithAxisandEpsAngle03.txt', ' ');
%logdata5=importdata('loogwithAxisAndEpsAngle05.txt', ' ');
groundtrouth=0.5:1:24;
groundtrouthypos=[-1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 -1.5 ];
grountrouthneg=[1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 1.5 ];


%distvector=0:size(logdata1)-1;

distvector2=0:size(logdata1);
distvector2=distvector2.*0.2
%distvector=distvector.*0.2;


%x1=logdata1(:,1);
%y1=logdata1(:,2);
x2=logdata2(:,1);
y2=logdata2(:,2);
%x3=logdata3(:,1);
%y3=logdata3(:,2);
%x4=logdata4(:,1);
%y4=logdata4(:,2);
%x5=logdata5(:,1);
%y5=logdata5(:,2);

%x1korigeret=x1+distvector';
x2korigeret=x2+distvector2';
%x3korigeret=x3+distvector2';
%x4korigeret=x4+distvector2';
%x5korigeret=x5+distvector2';
hold on
grid on
grid minor
plot(groundtrouth,groundtrouthypos,'o k',groundtrouth,grountrouthneg,'o k')
%plot(x1korigeret,y1, '* r')
plot(x2korigeret,y2, '* ')
%plot(x3korigeret,y3, '* ')
%plot(x4korigeret,y4, '* ')
%plot(x5korigeret,y5, '* ')
legend('GroundTruthPos','GroundTruthNeg','0.175')
title('Plot of different EpsAnple thresholds')
xlabel('Distance [m] ')
ylabel('Distance [m]')