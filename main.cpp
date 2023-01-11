#include <iostream>
using std::cout;
using std::endl;

#include <math.h>

#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::CircleShape;
using sf::RectangleShape;
using sf::Color;

#include <SFML/System.hpp>
using sf::Vector2f;

#include "GameLibrary/GameLibrary.h"

class TempEnemy : public Entity
{
public:
    TempEnemy(int health, float max_speed, float move_speed);
    void update(GameManager *manager);
};

TempEnemy::TempEnemy(int health, float max_speed, float move_speed)
{
    this->health = health;
    this->max_speed = max_speed;
    this->move_speed = move_speed;
}

void TempEnemy::update(GameManager *manager)
{
    Vector2f vec = manager->player->getCenter() - getCenter();
    const float vec_mag = sqrt(vec.x * vec.x + vec.y * vec.y);
    vec /= vec_mag;
    vec *= move_speed;
    changeVelocity(vec);
}

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    RenderWindow window(sf::VideoMode(1280, 720),
                        "OOP Group Project");

    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Gamelibrary stuff

    // Create an entity for the player
    Entity player;
    player.body.setFillColor(Color::Cyan);
    player.body.setSize(Vector2f(25.f, 25.f));
    player.body.setPosition(640.f, 360.f);

    // Create some enemies to play with the player
    TempEnemy enemy = TempEnemy(1, 1.f, 0.1f);
    enemy.body.setFillColor(Color::Magenta);
    enemy.body.setSize(Vector2f(25.f, 25.f));
    enemy.body.setPosition(500.f, 500.f);
    enemy.changeVelocity(2.f, 0.f);

    // Create the manager and pass the necessary stuff to it
    GameManager manager(&window);
    manager.setPlayer(&player);
    manager.addEnemy(&enemy);

    // LOADS OF ENEMIES
    TempEnemy *temp_entity_pointer;
    for (int i = 0; i < 50; i++)
    {
        // Create the entity
        temp_entity_pointer = new TempEnemy(1, 5.f, 0.1f);

        // Make em special
        temp_entity_pointer->body.setFillColor(Color::Green);
        temp_entity_pointer->body.setSize(Vector2f(15.f, 15.f));
        temp_entity_pointer->body.setPosition(100.f + (float)i * 20.f, 250.f);

        // Pass it to the manager
        manager.addEnemy(temp_entity_pointer);
    }

    // Where the event being handled is stored
    sf::Event event{};

    // Game loop
    while (window.isOpen())
    {
        // Event handler
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed: // Window closed
                window.close();
                break;

            case sf::Event::KeyPressed: // Escape key pressed
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            default:
                break;
            }
        }

        // Updates here
        manager.updateEnemies();

        // Drawing stuff
        window.clear();

        manager.drawPlayer();
        manager.drawEnemies();

        // WOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}