#include "BasicEnemy.h"
#include "Projectile.h"
#include "Entity.h"

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::RectangleShape;

BasicEnemy::BasicEnemy(Vector2f position)
{
    // Set up the rectangle
    body = RectangleShape(Vector2f(40, 40));
    body.setPosition(position);

    // Load the sprite
    body.setFillColor(sf::Color::Red);

    // Default values
    health = 5;
    max_speed = 4.f;
    move_speed = 0.5f;


}

void BasicEnemy::update(GameManager *manager)
{
    /*
     * Get the vector from the enemy to the player
     * Find the magnitude of this vector
     * Normalise the vector
     * Multiply the vector by the speed
     * Change the velocity by the vector, change velocity
     */

    Vector2f PlayerPosition = manager->player->getOrigin();
    Vector2f BasicEnemyPosition = getOrigin();

    Vector2f vectorPlayerToEnemy = PlayerPosition - BasicEnemyPosition;

    const float vectorPlayerToEnemy_magnitude = sqrtf(vectorPlayerToEnemy.x * vectorPlayerToEnemy.x +
            vectorPlayerToEnemy.y * vectorPlayerToEnemy.y);

    Vector2f normalisedPlayerToEnemy = vectorPlayerToEnemy / vectorPlayerToEnemy_magnitude;

    normalisedPlayerToEnemy *= move_speed;

    // change the velocity by the vector
    changeVelocity(normalisedPlayerToEnemy);
}