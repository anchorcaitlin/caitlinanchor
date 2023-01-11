#include "Entity.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <math.h>

/*
 * Reduces the health of the entity by damage amount
 * Returns true if the entity was 'killed' by the damage
 */
bool Entity::takeDamage(unsigned int damage)
{
    health -= damage;
    return health <= 0;
}

/*
 * Moves the entity by its current velocity
 */
void Entity::move(){
    velocity += velocity;
}

/*
 * Changes the entities velocity by the given amounts
 * If the new velocity magnitude exceeds the max speed then it is normalised to the max speed
 */
void Entity::changeVelocity(float xAdjustment, float yAdjustment)
{
    // Changes the velocity
    velocity.x += xAdjustment;
    velocity.y += yAdjustment;

    // Get the magnitude
    const float velocity_magnitude = sqrtf(xAdjustment * xAdjustment + yAdjustment * yAdjustment);

    // If the magnitude is larger than the speed make the magnitude the speed
    if (velocity_magnitude > max_speed)
    {
        velocity.x = velocity.x / velocity_magnitude * max_speed;
        velocity.y = velocity.y / velocity_magnitude * max_speed;
    }
}

// Implementation of changing the velocity of the entity
void Entity::changeVelocity(Vector2f adjustment)
{
    Entity::changeVelocity(adjustment.x, adjustment.y);
}

// Implementation of getting the velocity of the entity
Vector2f Entity::getVelocity()
{
    return velocity;
}

// Implementation of getting the centre of the entity.
Vector2f Entity::getOrigin()
{
    return body.getOrigin();
}