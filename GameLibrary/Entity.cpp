#include "Entity.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <math.h>

#include "GameManager.h"

/*
 * Entities default constructor
 * Shoudnt be used in the actual game as this is just for testing purposes
 */
Entity::Entity()
{
    // Give everything some value
    health = 1;
    max_speed = 2.5f;
    move_speed = 0.1f;
}

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
    body.move(velocity);
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
    const float velocity_magnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);

    // If the magnitude is larger than the speed make the magnitude the speed
    if (velocity_magnitude > max_speed)
    {
        velocity.x = velocity.x / velocity_magnitude * max_speed;
        velocity.y = velocity.y / velocity_magnitude * max_speed;
    }
}

/*
 * Change velocity with a vector rather than 2 floats
 */
void Entity::changeVelocity(Vector2f adjustment)
{
    Entity::changeVelocity(adjustment.x, adjustment.y);
}

/*
 * Gets the current velocity
 */
Vector2f Entity::getVelocity()
{
    return velocity;
}

/*
 * Gets the origin from the body and returns it
 */
Vector2f Entity::getOrigin()
{
    return body.getOrigin();
}

/*
 * Finds and returns the center of the entities body
 */
Vector2f Entity::getCenter()
{
    Vector2f center = body.getPosition();
    center.x += body.getSize().x / 2;
    center.y += body.getSize().y / 2;
    return center;
}

/*
 * PAIN
 */
void Entity::update(GameManager *manager)
{

}