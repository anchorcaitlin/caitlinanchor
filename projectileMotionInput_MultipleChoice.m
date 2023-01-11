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