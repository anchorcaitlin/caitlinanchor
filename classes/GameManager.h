#ifndef OOP_GROUP_PROJECT_GAMEMANAGER_H
#define OOP_GROUP_PROJECT_GAMEMANAGER_H

#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include "Entity.h"
#include "Player.h"
// #include "Projectile.h"

class Projectile;


class GameManager {
public:
    RenderWindow &window;

    explicit GameManager(RenderWindow &window);

    /*
    vector<Projectile> projectiles;
    void updateProjectiles();
    void drawProjectiles();
     */

    vector<Entity *> enemies;
    // Adds an enemy
    void addEnemy(Entity *enemy);

    // Updates enemies
    void updateEnemies();

    // Makes the enemies visible on the screen
    void drawEnemies();

    Entity *player;

    // Sets a player
    void setPlayer(Entity *player);

    // Updates players
    void updatePlayer();

    // Makes the player visible on the screen
    void drawPlayer();
};

#endif //OOP_GROUP_PROJECT_GAMEMANAGER_H