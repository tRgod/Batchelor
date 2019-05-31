clear
landmarkdata = importdata('landmarks.txt', ' ');
posedata = importdata('predictedPoses.txt', ' ');
GTdata = importdata('groundTruth.txt', ' ');
iSAM2Data = importdata('isam2.txt', ' ');
isampose = iSAM2Data(:,2:3);
%XY = landmarkdata(:,3:4);
GT = GTdata(:,2:3);
pose = posedata(:,2:3);

GTlandmarks = transpose(-12:1:59);
posrow = ones(72,1).*1.5;
negrow = posrow*(-1);
GTlandmarks = [GTlandmarks posrow; GTlandmarks negrow];



figure(1),clf, hold on

%landmarks
%plot(XY(:,1),XY(:,2), 'b^');
for i= 1:size(landmarkdata)
    n = mod(landmarkdata(i,2),7);
    switch n
        case 0
            plot(landmarkdata(i, 3),landmarkdata(i, 4), 'b*')
            text(landmarkdata(i, 3),landmarkdata(i, 4), int2str(landmarkdata(i, 2)))
        case 1
            plot(landmarkdata(i, 3),landmarkdata(i, 4), 'r*')
            text(landmarkdata(i, 3),landmarkdata(i, 4), int2str(landmarkdata(i, 2)))
        case 2
            plot(landmarkdata(i, 3),landmarkdata(i, 4), 'y*')
            text(landmarkdata(i, 3),landmarkdata(i, 4), int2str(landmarkdata(i, 2)))
        case 3
            plot(landmarkdata(i, 3),landmarkdata(i, 4), 'g*')
            text(landmarkdata(i, 3),landmarkdata(i, 4), int2str(landmarkdata(i, 2)))
        case 4
            plot(landmarkdata(i, 3),landmarkdata(i, 4), 'm*')
            text(landmarkdata(i, 3),landmarkdata(i, 4), int2str(landmarkdata(i, 2)))
        case 5
            plot(landmarkdata(i, 3),landmarkdata(i, 4), 'c*')
            text(landmarkdata(i, 3),landmarkdata(i, 4), int2str(landmarkdata(i, 2)))
        case 6
            plot(landmarkdata(i, 3),landmarkdata(i, 4), 'k*')
            text(landmarkdata(i, 3),landmarkdata(i, 4), int2str(landmarkdata(i, 2)))
    end
    
end
plot(GT(:,1),GT(:,2), 'k-');
plot(GTlandmarks(:,1), GTlandmarks(:,2),'k^')
plot(pose(:,1),pose(:,2), 'r--');
plot(isampose(:,1),isampose(:,2),'g-')
