#ifndef OOP_GROUP_PROJECT_ENTITY_H
#define OOP_GROUP_PROJECT_ENTITY_H

#include <vector>
using std::vector;

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Graphics.hpp>
using sf::RectangleShape;

#include "GameManager.h"

class GameManager;


class Entity{
private:
    // The current velocity of the entity
    Vector2f velocity;

protected:

    // The current health of the entity
    int health;

    // The max speed of the entity
    float max_speed;

    // The speed the entity moves at, or the distance per frame
    float move_speed;

public:
    sf::RectangleShape body;

    // Returns true if the damage taken results in death
    bool takeDamage(unsigned int damage);

    // Moves the entity's location by the current velocity
    void move();

    // Adjusts the velocity by the values given
    void changeVelocity(Vector2f adjustment);
    void changeVelocity(float xAdjustment, float yAdjustment);

    // Gets the velocity of the entity
    Vector2f getVelocity();

    // Gets the origin of the entity
    Vector2f getOrigin();

    // Updates the velocity of the entity
    virtual void update(GameManager *manager) = 0;
};

#endif //OOP_GROUP_PROJECT_ENTITY_H