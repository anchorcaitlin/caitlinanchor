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

    % ADDITION TO PROGRAM: CONSIDERING WHEN THE USER DOES NOT HAVE ENOUGH
    % KNOWN VALUES TO COMPUTE THE TIME OF FLIGHT, RANGE AND MAXIMUMUM
    % HEIGHT. Note, the calculations cannot be calculated if the parameters
    % do not fall in any of the if statements above, therefore an 'else'
    % condition is used. 
else
    calculationsImpossible = sprintf("You do not have enough known values " + ...
        "to calculate the time of flight, range and maximum height of " + ...
        "the projectile. ");
    message = sprintf('%s', calculationsImpossible);
    uiwait(helpdlg(calculationsImpossible, 'Projectile Motion Calculations'));
end 