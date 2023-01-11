#ifndef OOP_GROUP_PROJECT_BUTTON_H
#define OOP_GROUP_PROJECT_BUTTON_H

#include <SFML/System.hpp>
using sf::Vector2f;

class Button {
protected:
    Vector2f buttonCoordinates;
    bool buttonIsPressed;

public:
    // Displays the play, pause, resume and quit buttons.
    void displayPlayButton();
    void displayPauseButton();
    void displayResumeButton();
    void displayQuitButton();

    void onPress();
    void update();
    void displayBackground();
};


#endif //OOP_GROUP_PROJECT_BUTTON_H