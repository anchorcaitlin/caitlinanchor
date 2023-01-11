#ifndef OOP_GROUP_PROJECT_PLAYER_H
#define OOP_GROUP_PROJECT_PLAYER_H

#include <SFML/System.hpp>
using sf::Vector2f;

#include "Entity.h"
#include "GameManager.h"


class Player: public Entity{

private:
    int fireRate;
    int bulletType;

public:
    // Initialises the player
    Player(float x, float y, float width, float height, int speed);
    Player(Vector2f position, Vector2f size);

    void update(GameManager *manager);

};

#endif //OOP_GROUP_PROJECT_PLAYER_H