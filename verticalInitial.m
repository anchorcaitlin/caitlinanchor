function [verticalInitial] = verticalInitial(initialVelocity, angleHorizontal)
    % VERTICALINITIAL represents the initial vertical velocity of the
    % projectile.
    % The vertical initial velocity is calculated using the projectile
    % motion equation, v = v_0 * sin (theta).
    verticalInitial = initialVelocity * sind(angleHorizontal);
end 