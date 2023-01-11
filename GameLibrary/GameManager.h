#ifndef OOP_GROUP_PROJECT_GAMEMANAGER_H
#define OOP_GROUP_PROJECT_GAMEMANAGER_H

#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include "Entity.h"
class Entity;

class GameManager
{
public:
    // The window being drawn to
    RenderWindow *window;

    // Constructor, window is necessary for the draw functions
    GameManager(RenderWindow *window);

    // Player
    Entity *player;
    // Set the player entity
    void setPlayer(Entity *player);
    // Updates the player entity
    void updatePlayer();
    // Draws the player to the window given in construction
    void drawPlayer();

    // Enemies
    vector<Entity *> enemies;
    // Add an enemy
    void addEnemy(Entity *enemy);
    // Update all enemies
    void updateEnemies();
    // Draws all the enemies
    void drawEnemies();

};

#endif // OOP_GROUP_PROJECT_GAMEMANAGER_H
