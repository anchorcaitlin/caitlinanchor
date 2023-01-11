#include <iostream>
using std::cout;
using std::endl;

#include <SFML/Graphics.hpp>

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    sf::RenderWindow window(
        sf::VideoMode(1280, 720),
        "Framerate Test");
    
    // Reducing the framerate to 60fps
    window.setFramerateLimit(60);

    // Circle
    sf::CircleShape shape(100.f); // Radius
    shape.setFillColor(sf::Color::Green); // Color
    shape.setPosition(100.f, 100.f); // Position

    // For movement of the shape
    float x_movement;
    float y_movement;

    // Where the event being handled is stored
    sf::Event event;

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
                
                // Checking for keypresses to change framerate
                switch (event.key.code)
                {
                case sf::Keyboard::Num1:
                    window.setFramerateLimit(10);
                    break;
                case sf::Keyboard::Num2:
                    window.setFramerateLimit(20);
                    break;
                case sf::Keyboard::Num3:
                    window.setFramerateLimit(30);
                    break;
                case sf::Keyboard::Num4:
                    window.setFramerateLimit(40);
                    break;
                case sf::Keyboard::Num5:
                    window.setFramerateLimit(50);
                    break;
                case sf::Keyboard::Num6:
                    window.setFramerateLimit(60);
                    break;
                case sf::Keyboard::Num7:
                    window.setFramerateLimit(70);
                    break;
                case sf::Keyboard::Num8:
                    window.setFramerateLimit(80);
                    break;
                case sf::Keyboard::Num9:
                    window.setFramerateLimit(90);
                    break;
                }

                break;
            }
        }

        // Moving the shape
        x_movement = 0.f;
        y_movement = 0.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x_movement -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x_movement += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            y_movement -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            y_movement += 1.f;

        shape.move(x_movement, y_movement);

        // Clamping to the screen

        // X Axis
        sf::Vector2f position = shape.getPosition();
        if (position.x < 0)
            shape.setPosition(0, shape.getPosition().y);
        else if (position.x > 1280 - 200)
            shape.setPosition(1280 - 200, shape.getPosition().y);

        // Y Axis
        if (position.y < 0)
            shape.setPosition(shape.getPosition().x, 0);
        else if (position.y > 720 - 200)
            shape.setPosition(shape.getPosition().x, 720 - 200);

        // Drawing stuff
        window.clear();
        window.draw(shape);

        // WOOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}