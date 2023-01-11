#ifndef OOP_GROUP_PROJECT_MAINMENU_H
#define OOP_GROUP_PROJECT_MAINMENU_H

#include <SFML/System.hpp>
using sf::Vector2f;

class MainMenu {
protected:
    Vector2f buttonCoordinates;
    bool buttonIsPressed;

public:
    // Displays the play, pause, resume and quit buttons.
    void displayPlayButton();
    void displayPauseButton();
    void displayResumeButton();
    void displayQuitButton();

    // Redirects user to appropriate windows upon clicking a button.
    void onPress();
    void update();

    // Displays background of main menu.
    void displayBackground();
};

#endif //OOP_GROUP_PROJECT_MAINMENU_H