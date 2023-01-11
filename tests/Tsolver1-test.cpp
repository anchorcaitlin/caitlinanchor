#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

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

void moveRectangle(RectangleShape &rect, float xMovement, float yMovement, vector<RectangleShape> other_rects)
{
    /*
Moves the rectangle and solves any collisions with the rectangles in the given vector
    */

    // Size cause size
    Vector2f size = rect.getSize();

    // If there is x-axis movement
    if (xMovement)
    {

        // The current y value, not changed in the x-axis movement
        const float y = rect.getPosition().y;

        // Move along the x-axis
        rect.move(xMovement, 0);

        // For every other rectangle
        for (RectangleShape other_rect : other_rects)
        {
            // If there is a collision
            if (collisionBetween(rect, other_rect))
            {
                if (xMovement > 0) // If moving right
                {
                    // Set the right of the rectangle to the left of the other rectangle
                    rect.setPosition(other_rect.getPosition().x - size.x, y);
                }
                else // If moving left
                {
                    // Set the left of the rectangle to the right of the other rectangle
                    rect.setPosition(other_rect.getPosition().x + other_rect.getSize().x, y);
                }
            }
        }
    }

    if (yMovement)
    {
        // The current x value, not changed in the y-axis movement
        const float x = rect.getPosition().x;

        // Move along the y-axis
        rect.move(0, yMovement);

        // For every other rectangle
        for (RectangleShape other_rect : other_rects)
        {
            // If there is a collision
            if (collisionBetween(rect, other_rect))
            {
                if (yMovement > 0) // If moving down
                {
                    // Set the bottom of the rectangle to the bottom of the top rectangle
                    rect.setPosition(x, other_rect.getPosition().y - size.y);
                }
                else // If moving up
                {
                    // Set the top of the rectangle to the bottom of the other rectangle
                    rect.setPosition(x, other_rect.getPosition().y + other_rect.getSize().y);
                }
            }
        }
    }
}

void moveRectangle(RectangleShape &rect, Vector2f movement, vector<RectangleShape> other_rects)
{
    moveRectangle(rect, movement.x, movement.y, other_rects);
}

int main()
{
    cout << "\n========== Program Start ==========\n"
         << endl;

    // Create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720),
                            "Collision Solver Test");

    // Set the framerate to 60fps
    window.setFramerateLimit(60);

    // Rectangle 1
    RectangleShape rectangle(Vector2f(100.f, 100.f)); // Width, height
    rectangle.setFillColor(Color::Blue);              // Colour
    rectangle.setPosition(500.f, 250.f);              // Position
    Vector2f rectangle_size = rectangle.getSize();

    float x_movement, y_movement; // For moving Rectangle 1
    float move_speed = 5.f;       // Pixels moved per frame

    // Other rectangles
    vector<RectangleShape> other_rectangles;
    RectangleShape rect1(Vector2f(1000.f, 20.f));
    rect1.setPosition(150.f, 150.f);
    rect1.setFillColor(Color(255, 127, 127));
    other_rectangles.push_back(rect1);
    RectangleShape rect2(Vector2f(50.f, 400.f));
    rect2.setPosition(700.f, 200.f);
    rect2.setFillColor(Color(255, 127, 127));
    other_rectangles.push_back(rect2);

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
            x_movement -= move_speed;
        if (Keyboard::isKeyPressed(Keyboard::Right))
            x_movement += move_speed;
        if (Keyboard::isKeyPressed(Keyboard::Up))
            y_movement -= move_speed;
        if (Keyboard::isKeyPressed(Keyboard::Down))
            y_movement += move_speed;

        moveRectangle(rectangle, x_movement, y_movement, other_rectangles);

        // Clamping to the screen

        //  X Axis
        Vector2f position = rectangle.getPosition();
        if (position.x < 0)
            rectangle.setPosition(0, rectangle.getPosition().y);
        else if (position.x > 1280 - rectangle_size.x)
            rectangle.setPosition(1280 - rectangle_size.x, rectangle.getPosition().y);

        //  Y Axis
        if (position.y < 0)
            rectangle.setPosition(rectangle.getPosition().x, 0);
        else if (position.y > 720 - rectangle_size.y)
            rectangle.setPosition(rectangle.getPosition().x, 720 - rectangle_size.y);

        // Drawing stuff
        window.clear();
        window.draw(rectangle);
        for (RectangleShape other_rectangle : other_rectangles)
            window.draw(other_rectangle);

        // WOOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}