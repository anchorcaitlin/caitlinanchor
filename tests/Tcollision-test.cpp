#include <iostream>
using std::cout;
using std::endl;

#include <math.h>

#include <SFML/Graphics.hpp>
using sf::CircleShape;
using sf::Color;
using sf::RectangleShape;

#include <SFML/System.hpp>
using sf::Vector2f;

#include <SFML/Window.hpp>
using sf::Keyboard;

bool collisionBetween(const RectangleShape &rect1, const RectangleShape &rect2)
{
    Vector2f rect1_pos = rect1.getPosition();
    Vector2f rect1_size = rect1.getSize();
    Vector2f rect2_pos = rect2.getPosition();
    Vector2f rect2_size = rect2.getSize();

    if (rect1_pos.x < rect2_pos.x + rect2_size.x)             // If the left is left of the right
        if (rect1_pos.x + rect1_size.x > rect2_pos.x)         // If the right is right of the left
            if (rect1_pos.y < rect2_pos.y + rect2_size.y)     // If the top is above the bottom
                if (rect1_pos.y + rect1_size.y > rect2_pos.y) // If the bottom is below the top
                    return true;

    // If any of the above are false then there is no collision
    return false;
}

bool collisionBetween(const RectangleShape &rect, const CircleShape &circle)
{
    Vector2f rect_pos = rect.getPosition();
    Vector2f rect_size = rect.getSize();
    Vector2f circle_pos = circle.getPosition();
    Vector2f circle_center = circle.getPosition();

    float circle_radius = circle.getRadius();
    circle_center.x += circle_radius;
    circle_center.y += circle_radius;

    // If the center of the circle is within the bounds of the sides of the rectangle
    // The consider the circle a rectangle
    if (
        rect_pos.x <= circle_center.x && circle_center.x <= rect_pos.x + rect_size.x ||
        rect_pos.y <= circle_center.y && circle_center.y <= rect_pos.y + rect_size.y)
    {
        float circle_diameter = circle_radius * 2;
        RectangleShape binding_rectangle(Vector2f(circle_diameter, circle_diameter));
        binding_rectangle.setPosition(circle_pos);

        return collisionBetween(rect, binding_rectangle);
    }

    // Find the corner the circle is closest to and get x and y displacement
    float x_diff, y_diff, distance;
    bool circle_above = circle_center.y < rect_pos.y;
    if (circle_center.x < rect_pos.x) // If the circle is to the left of the rectangle
        if (circle_above)             // If the circle is above the rectangle
        {
            // Get displacement to the rectangles top left corner
            x_diff = circle_center.x - rect_pos.x;
            y_diff = circle_center.y - rect_pos.y;
        }
        else // If the circle is below the rectangle
        {
            // Get displacement to the rectangles bottom left corner
            x_diff = circle_center.x - rect_pos.x;
            y_diff = circle_center.x - rect_pos.y - rect_size.y;
        }
    else                  // If the circle is to the right of the rectangle
        if (circle_above) // If the circle is above the rectangle
        {
            // Get the displacement to the rectangles top right corner
            x_diff = circle_center.x - rect_pos.x - rect_size.x;
            y_diff = circle_center.y - rect_pos.y;
        }
        else // If the circle is below the rectangle
        {
            // Get the displacement to the rectangles bottom right corner
            x_diff = circle_center.x - rect_pos.x - rect_size.x;
            y_diff = circle_center.y - rect_pos.y - rect_size.y;
        }

    // Find the distance and check against radius
    distance = sqrt(x_diff * x_diff + y_diff * y_diff);
    if (distance < circle_radius)
        return true;

    return false;
}
bool rectangleCollisionWithCircle(const CircleShape &circle, const RectangleShape &rect)
{
    return collisionBetween(rect, circle);
}

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720),
                            "Collision Test");

    // Circle
    CircleShape circle(100.f);         // Radius
    circle.setFillColor(Color::Green); // Colour
    circle.setPosition(100.f, 100.f);  // Position

    // Rectangle 1
    RectangleShape rectangle1(Vector2f(100.f, 100.f)); // Width, height
    rectangle1.setFillColor(Color::Blue);              // Colour
    rectangle1.setPosition(500.f, 250.f);              // Position
    Vector2f rectangle1_size = rectangle1.getSize();

    float x_movement, y_movement; // For moving Rectangle 1

    // Rectangle 2
    RectangleShape rectangle2(Vector2f(50.f, 50.f)); // Width, height
    rectangle2.setFillColor(Color::Yellow);          // Colour
    rectangle2.setPosition(700.f, 50.f);             // Position

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
                if (event.key.code == Keyboard::Escape)
                    window.close();
                break;
            }
        }

        // Moving the rectangle
        x_movement = 0.f;
        y_movement = 0.f;
        if (Keyboard::isKeyPressed(Keyboard::Left))
            x_movement -= 1.f;
        if (Keyboard::isKeyPressed(Keyboard::Right))
            x_movement += 1.f;
        if (Keyboard::isKeyPressed(Keyboard::Up))
            y_movement -= 1.f;
        if (Keyboard::isKeyPressed(Keyboard::Down))
            y_movement += 1.f;

        rectangle1.move(x_movement, y_movement);

        // Clamping to the screen

        // X Axis
        Vector2f position = rectangle1.getPosition();
        if (position.x < 0)
            rectangle1.setPosition(0, rectangle1.getPosition().y);
        else if (position.x > 1280 - rectangle1_size.x)
            rectangle1.setPosition(1280 - rectangle1_size.x, rectangle1.getPosition().y);

        // Y Axis
        if (position.y < 0)
            rectangle1.setPosition(rectangle1.getPosition().x, 0);
        else if (position.y > 720 - rectangle1_size.y)
            rectangle1.setPosition(rectangle1.getPosition().x, 720 - rectangle1_size.y);

        // Collision detection with rectangle or circle
        if (collisionBetween(rectangle1, rectangle2) ||
            collisionBetween(rectangle1, circle))
            rectangle1.setFillColor(Color::Red);
        else
            rectangle1.setFillColor(Color::Blue);

        // Drawing stuff
        window.clear();
        window.draw(circle);
        window.draw(rectangle1);
        window.draw(rectangle2);

        // WOOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}