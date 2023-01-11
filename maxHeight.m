function [maximumHeight] = maxHeight (verticalInitial, accelerationGravity)
    % MAXHEIGHT returns the maximum height of a non-horizontally launched
    % projectile.
    maximumHeight = -(verticalInitial)^2 / (2 * accelerationGravity);
end 