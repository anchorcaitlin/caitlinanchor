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

/*
Detects a collision between two rectangles
*/
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

/*
Detects a collision bewteen a rectangle and a circle
*/
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
    if (rect_pos.x <= circle_center.x && circle_center.x <= rect_pos.x + rect_size.x ||
        rect_pos.y <= circle_center.y && circle_center.y <= rect_pos.y + rect_size.y)
    {
        float circle_diameter = circle_radius * 2;
        RectangleShape binding_rectangle(Vector2f(circle_diameter, circle_diameter));
        binding_rectangle.setPosition(circle_pos);

        return collisionBetween(rect, binding_rectangle);
    }

    // Find the corner the circle is closest to and get x and y displacement
    float x_diff, y_diff, distance;
    const bool circle_above = circle_center.y < rect_pos.y;
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
bool collisionBetween(const CircleShape &circle, const RectangleShape &rect)
{
    return collisionBetween(rect, circle);
}

/*
Solves a collision between two rectangles along the x-axis.
Assumes a collision has already been detected between the shapes
*/
void solveCollisionX(RectangleShape &rect, float xMovement, const RectangleShape &other_rect)
{
    // The current y value, not changed in the x-axis movement
    const float y = rect.getPosition().y;

    if (xMovement > 0) // If moving right
    {
        // Set the right of the rectangle to the left of the other rectangle
        rect.setPosition(other_rect.getPosition().x - rect.getSize().x, y);
    }
    else // If moving left
    {
        // Set the left of the rectangle to the right of the other rectangle
        rect.setPosition(other_rect.getPosition().x + other_rect.getSize().x, y);
    }
}

/*
Solves a collision between a rectangle and a circle
Assumes a collision has already been detected between the shapes
*/
void solveCollisionX(RectangleShape &rect, float xMovement, const CircleShape &other_circle)
{
    Vector2f rect_pos = rect.getPosition();
    Vector2f rect_size = rect.getSize();
    Vector2f circle_pos = other_circle.getPosition();
    Vector2f circle_center = other_circle.getPosition();

    float circle_radius = other_circle.getRadius();
    circle_center.x += circle_radius;
    circle_center.y += circle_radius;

    // If the center of the circle is within the bounds of the sides of the rectangle
    // The consider the circle a rectangle and procede from there
    if (rect_pos.x <= circle_center.x && circle_center.x <= rect_pos.x + rect_size.x ||
        rect_pos.y <= circle_center.y && circle_center.y <= rect_pos.y + rect_size.y)
    {
        // Get the binding rectangle
        float circle_diameter = circle_radius * 2;
        RectangleShape binding_rectangle(Vector2f(circle_diameter, circle_diameter));
        binding_rectangle.setPosition(circle_pos);

        // Solve
        solveCollisionX(rect, xMovement, binding_rectangle);

        return; // We are finished here
    }

    // If not then MATH

    // Find the penetrating corner, we want to move this out of the circle
    Vector2f corner_coord = rect_pos;
    const bool circle_above = circle_center.y < rect_pos.y;
    if (circle_center.x < rect_pos.x) // If the circle is to the left of the rectangle
        if (!circle_above)            // If the circle is below the rectangle
        {
            // Bottom left
            corner_coord.y += rect_size.y;
        }
        else // If the circle is to the right of the rectangle
        {
            corner_coord.x += rect_size.x;
            if (!circle_above) // If the circle is below the rectangle
            {
                // Bottom right
                corner_coord.y += rect_size.y;
            }
        }

    // Suddenly trig

}

/*
Solves a collision between two rectangles along the y-axis.
Assumes a collision has already been detected between the shapes
*/
void solveCollisionY(RectangleShape &rect, float yMovement, const RectangleShape &other_rect)
{
    // The current x value, not changed in the y-axis movement
    const float x = rect.getPosition().x;

    if (yMovement > 0) // If moving down
    {
        // Set the bottom of the rectangle to the bottom of the top rectangle
        rect.setPosition(x, other_rect.getPosition().y - rect.getSize().y);
    }
    else // If moving up
    {
        // Set the top of the rectangle to the bottom of the other rectangle
        rect.setPosition(x, other_rect.getPosition().y + other_rect.getSize().y);
    }
}

/*
Moves a rectangle along the x-axis only
*/

/*
Moves a rectangle along the y-axis only
*/

/*
Moves a rectangle and solves any detected collisions
*/

/*
Moves a rectangle and solves any detected collisions
*/

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

    // Other shapes
    RectangleShape rect1(Vector2f(1000.f, 20.f));
    rect1.setPosition(150.f, 150.f);
    rect1.setFillColor(Color(255, 127, 127));
    RectangleShape rect2(Vector2f(50.f, 400.f));
    rect2.setPosition(700.f, 200.f);
    rect2.setFillColor(Color(255, 127, 127));
    CircleShape circle1(100.f);
    circle1.setPosition(100.f, 600.f);
    circle1.setFillColor(Color(255, 127, 127));

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

        // moveRectangle(rectangle, x_movement, y_movement, shapes);

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
        // for (Shape *shape : shapes)
        //     window.draw(*shape);

        // WOOO
        window.display();
    }

    cout << "\n=============== End ===============\n"
         << endl;

    return 0;
}