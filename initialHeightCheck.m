function [initialHeight] = initialHeightCheck(initialHeight)
    while initialHeight < 0 
        % Initial height of the projectile must be greater than 0. 
        fprintf("You must enter a valid initial height\n");
        initialHeight = input("Please enter a valid initial height of the " + ...
            "projectile in metres: ");
    end 
end 