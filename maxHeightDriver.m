% test equivalence case of a boundary case.
% expected output is 0
verticalInitial = 0;
accelerationGravity = -9.8;
[maximumHeight] = maxHeight (verticalInitial, accelerationGravity)

% test equivalence case of negative and positive numbers 
% expected output is 
verticalInitial = 60;
accelerationGravity = -9.8;
[maximumHeight] = maxHeight (verticalInitial, accelerationGravity)