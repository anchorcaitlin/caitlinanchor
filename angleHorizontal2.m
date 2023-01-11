function [angleHorizontal] = angleHorizontal2(rangeProjectile, ...
    accelerationGravity, initialVelocity)
    % ANGLEHORIZONTAL2 returns the angle of the horizontal of the
    % projectile.
    angleHorizontal = 1/2 * asind((rangeProjectile * abs(accelerationGravity)) ...
        /(initialVelocity)^2);
end 