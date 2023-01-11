function [initialVelocity] = initialVelocityCheck(initialVelocity)
    while initialVelocity <= 0
        % The initial velocity of the projectile is not valid in real-life 
        % contexts when it is less than or equal to 0, so the user 
        % must enter a positive number.
        fprintf("You must enter a valid initial velocity\n");
        initialVelocity = input("Please enter another value for the initial " + ...
            "velocity in metres per second: ");
    end 
end 