function [rangeProjectile] = rangeProjectileCheck(rangeProjectile)
    while rangeProjectile <= 0 
        % The range of a projectile cannot be less than 0 metres. It must
        % take a positive value as the projectile cannot travel a negative
        % distance.
        fprintf("You must enter a valid range\n");
        initialHeight = input("Please enter a valid range of the projectile in metres: ");
    end 
end 