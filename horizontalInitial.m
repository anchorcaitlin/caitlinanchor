function [horizontalInitial] = horizontalInitial(initialVelocity, angleHorizontal)
    % HORIZONTALINITIAL represents the initial horizontal velocity of the
    % projectile.
    % The horizontal initial velocity is calculated using the projectile
    % motion equation, v = v_0 * cos (theta).
    horizontalInitial = initialVelocity * cosd(angleHorizontal);
end 