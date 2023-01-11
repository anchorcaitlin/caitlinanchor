#include "GameManager.h"

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include <iostream>
using std::cout;
using std::endl;

#include "Entity.h"

/*
 * Construct the manager with a render window
 */
GameManager::GameManager(RenderWindow *window)
{
    // Set the window
    this->window = window;
    // No player for now
    player = nullptr;
}

/*
 * Set the managers player entity
 */
void GameManager::setPlayer(Entity *player)
{
    // Player time
    this->player = player;
}

/*
 * Updates the player entity
 * 
 */
void GameManager::updatePlayer()
{

}

/*
 * Draws the payer entity to the handled window
 */
void GameManager::drawPlayer()
{
    window->draw(player->body);
}

/*
 * Adds an enemy entity to the list of handled enemy entities
 */
void GameManager::addEnemy(Entity *enemy)
{
    enemies.push_back(enemy);
}

/*
 * Updates all handled enemy entities
 */
void GameManager::updateEnemies()
{
    for (Entity *enemy : enemies)
    {
        enemy->update(this);
        enemy->move();
    }
}

/*
 * Draws all handled enemy entites to the handled window
 */
void GameManager::drawEnemies()
{
    for (Entity *enemy : enemies)
    {
        window->draw(enemy->body);
    }
}
