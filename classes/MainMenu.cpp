#include "MainMenu.h"
#include "SFML/Graphics.hpp"
#include <iostream>

// Loads an image and displays as a background
void MainMenu::displayBackground(){
    sf::RenderWindow window(sf::VideoMode(800,800), "MAIN MENU");
    window.setFramerateLimit(100);

    sf::Texture image;
    image.loadFromFile("somefile.png");
    sf::Sprite sprite(image);
}

// Display appropriate buttons
void MainMenu::displayPlayButton(){
    MenuItem playButton;
    playButton.rect.left = 150;
    playButton.rect.top = 500;
    playButton.rect.width = 550;
    playButton.rect.height = 100;
    playButton.action = Play;
}

void MainMenu::displayPauseButton(){
    MenuItem pauseButton;
    pauseButton.rect.left = 250;
    pauseButton.rect.top = 500;
    pauseButton.rect.width = 550;
    pauseButton.rect.height = 100;
    pauseButton.action = Pause;
}

void MainMenu::displayResumeButton(){
    MenuItem resumeButton;
    resumeButton.rect.left = 250;
    resumeButton.rect.top = 500;
    resumeButton.rect.width = 550;
    resumeButton.rect.height = 100;
    resumeButton.action = Resume;
}

void MainMenu::displayQuitButton(){
    MenuItem quitButton;
    quitButton.rect.left = 250;
    quitButton.rect.top = 500;
    quitButton.rect.width = 550;
    quitButton.rect.height = 100;
    quitButton.action = Quit;
}

// Redirecting user to appropriate window
void MainMenu::update(){

}