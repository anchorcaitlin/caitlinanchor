#include <SFML/Graphics.hpp>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(200, 200),
                            "SFML works!");

    // Create a shape
    sf::CircleShape shape(100.f);
    // Give it a colour
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        // Where the event being handled is stored
        sf::Event event;
        // Event loop
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // Close event, you pressed the X
                window.close();                  // YEET!
        }

        // Clear the window
        window.clear();
        // Draw stuff
        window.draw(shape);
        // Display stuff
        window.display();
    }

    return 0;
}