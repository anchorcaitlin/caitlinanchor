function [time] = timeFlight (verticalInitial, accelerationGravity)
    % TIMEFLIGHT returns the time of flight of a projectile.
    time = -verticalInitial/accelerationGravity * 2;
end 