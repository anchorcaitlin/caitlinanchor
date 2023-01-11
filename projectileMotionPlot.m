%  ---------------------- MODEL CONSTANT PARAMETERS --------------------- 
accelerationGravity = -9.8; % Acceleration due to gravity in metres per second 
% per second. This constant is needed in many projectile motion calculations 
% used later in the program.

%  ------------------- USER TO INPUT KNOWN PARAMETERS -------------------
% User to select all the parameters known in their projectile motion
% problem from a multiple choice list. 

% List of choices for user to select.
list = {'Initial velocity','Angle of launch','Initial height',...                   
'Time of flight','Range','Maximum height'};

% Store the index of the user's selection in a vector. The user can enter
% more than one known parameter since the 'multiple' function has been
% used.
[indexList] = listdlg('PromptString', {'Select the known parameters', ...
    'in your projectile motion question.', ''}, 'ListString', list, ...
    'SelectionMode', 'multiple');

%  --------------- GET USER INPUT FOR INITIAL PARAMETERS ----------------
% User to input the values of the parameters they entered in the
% multiple choice list previously.

if isequal(indexList, [1, 2, 3]) == 1 % The 'isequal' MATLAB function is used 
    % to determine if all the elements in the vector 'indexList' are the same 
    % to the vector [1, 2, 3].
    % User to input all values for initial velocity, angle above the
    % horizontal and the initial height of the projectile.
    inputValues = {['Please enter the initial velocity of the projectile in ' ...
        'metres per second: '],['Please enter the angle above the horizontal ' ...
        'of the projectile in degrees: '], ['Please enter the initial height ' ...
        'of the projectile in metres:']};
    projectileValues = inputdlg(inputValues); % Input values entered by the 
    % user into a vector.
    
    % Assign the parameter values entered by user into individual elements.
    initialVelocity = str2double(projectileValues{1});
    angleHorizontal = str2double(projectileValues{2});
    initialHeight = str2double(projectileValues{3});
    
    % Check if velocity is positive.
    [initialVelocity] = initialVelocityCheck(initialVelocity);

    % Check that there is a valid angle between 0 and 360 degrees.
    [angleHorizontal] = angleHorizontalCheck(angleHorizontal);

    % Check that the initial height is positive. The projectile must be
    % projected from a height of 0 metres or higher from the ground. 
    [initialHeight] = initialHeightCheck(initialHeight);

elseif isequal(indexList, [1, 3, 5]) == 1
    % User to input all values for initial velocity, initial height and
    % range of projectile.
    inputValues = {['Please enter the initial velocity of the projectile in ' ...
        'metres per second: '], ['Please enter the initial height of the ' ...
        'projectile in metres: '], ['Please enter the range of the projectile ' ...
        'in metres:']};
    projectileValues = inputdlg(inputValues); % Input values entered by the 
    % user into a vector.
    
    % Assign the parameter values into individual elements.
    initialVelocity = str2double(projectileValues{1});
    initialHeight = str2double(projectileValues{2});
    rangeProjectile = str2double(projectileValues{3});
    
    % Check if velocity is positive.
    [initialVelocity] = initialVelocityCheck(initialVelocity);

    % Check that the initial height is positive. The projectile must be
    % projected from a height of 0 metres or higher from the ground. 
    [initialHeight] = initialHeightCheck(initialHeight);

    % Check that the range is positive.
    [rangeProjectile] = rangeProjectileCheck(rangeProjectile);

elseif isequal(indexList, [2, 3, 5]) == 1
    % User to input all values for launch angle above the horizontal,
    % initial height and range of projectile. 
    inputValues = {['Please enter the initial launch angle of the projectile ' ...
        'in degrees: '], ['Please enter the initial height of the ' ...
        'projectile in metres: '], ['Please enter the range of the projectile ' ...
        'in metres:']};
    projectileValues = inputdlg(inputValues); % Input values entered by the 
    % user into a vector.
    
    % Assign the parameter values into individual elements.
    angleHorizontal = str2double(projectileValues{1});
    initialHeight = str2double(projectileValues{2});
    rangeProjectile = str2double(projectileValues{3});

    % Check that there is a valid angle between 0 and 360 degrees.
    [angleHorizontal] = angleHorizontalCheck(angleHorizontal);

    % Check that the initial height is positive. The projectile must be
    % projected from a height of 0 metres or higher from the ground. 
    [initialHeight] = initialHeightCheck(initialHeight);

    % Check that the range is positive.
    [rangeProjectile] = rangeProjectileCheck(rangeProjectile);

elseif ismember([4, 5, 6], indexList) % If all of the elements [4, 5, 6] 
    % are present in 'indexList', the user already is aware of the
    % projectile motion calculations.
    calculationsDone = sprintf("You already know the time of flight, maximum " + ...
        "height and range of the projectile! ");
    message = sprintf('%s', calculationsDone);
    uiwait(helpdlg(calculationsDone, 'Projectile Motion Calculations'));

else
    calculationsImpossible = sprintf("You do not have enough known values " + ...
        "to calculate the time of flight, range and maximum height of " + ...
        "the projectile. ");
    message = sprintf('%s', calculationsImpossible);
    uiwait(helpdlg(calculationsImpossible, 'Projectile Motion Calculations'));
end 

%  ------------------------- PERFORM COMPUTATIONS ------------------------
if isequal(indexList, [1, 2, 3]) == 1
    % Calculate the initial vertical and horizontal components of velocity. 
    [verticalInitial] = verticalInitial(initialVelocity, angleHorizontal);
    [horizontalInitial] = horizontalInitial(initialVelocity, angleHorizontal);

    % Calculate the total time of flight.
    [time] = timeFlight(verticalInitial, accelerationGravity); 

    % Calculate the maximum height of the projectile.
    [maximumHeight] = maxHeight(verticalInitial, accelerationGravity);

    % Calculate range of the projectile. 
    [rangeProjectile] = rangeCalc(horizontalInitial, time);

elseif isequal(indexList, [1, 3, 5]) == 1
    % Calculate the angle of launch above the horizontal. 
    [angleHorizontal] = angleHorizontal2(rangeProjectile, ...
    accelerationGravity, initialVelocity);

    % Calculate the initial vertical and horizontal components of velocity.
    [verticalInitial] = verticalInitial(initialVelocity, angleHorizontal); 
    [horizontalInitial] = horizontalInitial(initialVelocity, angleHorizontal);

    % Caluclate the total time of flight.
    [time] = timeFlight(verticalInitial, accelerationGravity); 

    % Calculate the maximum height of the projectile.
    [maximumHeight] = maxHeight(verticalInitial, accelerationGravity);

elseif isequal(indexList, [2, 3, 5]) == 1
    % Calculate the initial velocity of the projectile.  
    [initialVelocity] = initialVelocity(accelerationGravity, rangeProjectile, ...
    angleHorizontal, initialHeight);

    % Calculate the initial vertical and horizontal components of velocity. 
    [verticalInitial] = verticalInitial(initialVelocity, angleHorizontal); 
    [horizontalInitial] = horizontalInitial(initialVelocity, angleHorizontal);

    % Caluclate the total time of flight.
    [time] = timeFlight(verticalInitial, accelerationGravity); 

    % Calculate the maximum height of the projectile.
    [maximumHeight] = maxHeight(verticalInitial, accelerationGravity);

end 

% ADDITION TO PROGRAM: CREATE GRAPHS REPRESENTING THE VERTICAL
% DISPLACEMENT, VELOCITY AND ACCELERATION OF THE PROJECTILE ON THE SAME
% FIGURE. 
%  ----------------------- PLOT GRAPH OF PROJECTILE ---------------------
% Plot graph of the projectile's vertical displacement versus time, velocity 
% versus time and acceleration versus time. Create an array of time values and 
% its corresponding displacement, velocity and acceleration so its trajectory 
% can be graphed. The projectile will end when it reaches the ground.

if (isequal(indexList, [1, 2, 3]) == 1) || (isequal(indexList, [1, 3, 5]) == 1) ...
        || (isequal(indexList, [2, 3, 5]) == 1)

    % ---------------- VERTICAL DISPLACEMENT VERSUS TIME -----------------
    % Create the x-axis. 
    timeXAxis = linspace(0, time, 100);  
    % Create the y-axis.
    verticalHeightYAxis =  initialHeight + verticalInitial * timeXAxis + (1/2) * ...
        accelerationGravity * timeXAxis.^2;
    
    subplot(3, 1, 1);
    plot(timeXAxis, verticalHeightYAxis, '-or');
    title 'Vertical displacement of projectile over time'
    xlabel('Time (s)');
    ylabel('Vertical height (m)');
    hold on; % Previous image still stays there.
    grid on;
    % Set the dimensions of x and y axis. 
    axis([min(timeXAxis), max(timeXAxis), min(verticalHeightYAxis)-1, ...
        max(verticalHeightYAxis)+1]);

    % Annotate the maximum height of the projectile on the plot. 
    maxHeightAnnotation = text(time/6, maximumHeight+initialHeight, ...
        'Maximum height\rightarrow');

    % ----------------------- VELOCITY VERSUS TIME -----------------------
    % Create the x-axis. 
    timeXAxis = linspace(0, time, 100);
    % Create the y-axis. 
    velocity = verticalInitial + accelerationGravity * timeXAxis;

    subplot(3, 1, 2);
    plot(timeXAxis, velocity, '-xb');
    title 'Velocity of projectile over time'
    xlabel('Time (s)');
    ylabel('Velocity (ms^-1)');
    hold on; 
    grid on; 
    % Set the dimensions of x and y axis.
    axis([min(timeXAxis), max(timeXAxis), min(velocity)-1, ...
        max(velocity)+1]); 

    % --------------------- ACCELERATION VERSUS TIME ---------------------
    % Create the x-axis. 
    timeXAxis = linspace(0, time, 100);
    % Create the y-axis. 
    acceleration = -9.8; % Acceleration is a constant value.
    
    subplot(3, 1, 3);
    plot(timeXAxis, acceleration, '-ok');
    title 'Acceleration of projectile over time'
    xlabel('Time (s)');
    ylabel('Acceleration (ms^-2)');
    hold on; 
    grid on;
    % Set the dimensions of x and y axis. 
    axis([min(timeXAxis), max(timeXAxis), min(acceleration)-1, ...
        max(acceleration)+1]); 
end 