#include "GameManager.h"
#include "Projectile.h"

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include "Projectile.h"
#include "Player.h"

GameManager::GameManager(RenderWindow &window)
{
    self->window = window;
}

/*
 * Updates and moves all projectiles
 */
/*
void GameManager::updateProjectiles()
{
     * Updates the projectiles
     * Then moves them
     * Then checks
    for (Projectile projectile : projectiles)
    {
        projectile.update(projectiles, enemies, player);
        projectile.move();
    }
}
*/


/*
 * Draws all projectiles
 */
// void GameManager::drawProjectiles() {}

/*
 * Adds the enemy to the list of managed enemies
 */
void GameManager::addEnemy(Entity *new_enemy)
{
    enemies.push_back(new_enemy);
}

/*
 * Updates and moves all enemies
 */
void GameManager::updateEnemies()
{
    /*
     * Updates the enemies
     * Moves the enemies
     * Checks for any dead enemies
     */
    for (Entity *enemy : enemies)
    {
        enemy->update(projectiles, enemies, player);
        enemy->move();
    }
}

/*
 * Draws all enemies
 */
void GameManager::drawEnemies()
{
    for (Entity *enemy : enemies)
    {
        window.draw(enemy->body);
    }
}

// Implementation of updating the player
void GameManager::updatePlayer()
{

}

// Implementation of drawing the player
void GameManager::drawPlayer()
{

}

void GameManager::setPlayer(Entity *player) {
    self->player = player;
}
