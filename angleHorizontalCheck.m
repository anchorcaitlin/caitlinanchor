function [angleHorizontal] = angleHorizontalCheck(angleHorizontal)
    while angleHorizontal <= 0 || angleHorizontal >= 360
        % The angle of the horizontal must lie between 0 and 360 degrees
        % (not inclusive). This program provides a calculation for
        % non-horizontally launched projectiles, so if the angle is 0 or
        % 360 degrees, the projectile would be horizontally launched. 
        fprintf("You must enter a valid angle\n");
        angleHorizontal= input("Please enter another angle above the " + ...
        "horizontal of the projectile in degrees: ");
    end 
end 