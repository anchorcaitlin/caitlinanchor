#include "Button.h"
#include "SFML/Graphics.hpp"
#include <iostream>

    // Loads an image and displays as a background
    void Button::displayBackground(){
        sf::Texture image;
        image.loadFromFile("somefile.png");
        sf::Sprite sprite(image);
    }

    void Button::displayPlayButton(){
        MenuItem playButton;
        playButton.rect.left = 150;
        playButton.rect.top = 500;
        playButton.rect.width = 550;
        playButton.rect.height = 100;
        playButton.action = Play;
    }

    void Button::displayPauseButton(){
        MenuItem pauseButton;
        pauseButton.rect.left = 250;
        pauseButton.rect.top = 500;
        pauseButton.rect.width = 550;
        pauseButton.rect.height = 100;
        pauseButton.action = Pause;
    }

    void Button::displayResumeButton(){
    MenuItem resumeButton;
    resumeButton.rect.left = 250;
    resumeButton.rect.top = 500;
    resumeButton.rect.width = 550;
    resumeButton.rect.height = 100;
    resumeButton.action = Resume;
}

void Button::displayQuitButton(){
    MenuItem quitButton;
    quitButton.rect.left = 250;
    quitButton.rect.top = 500;
    quitButton.rect.width = 550;
    quitButton.rect.height = 100;
    quitButton.action = Quit;
}