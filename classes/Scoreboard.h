#ifndef OOP_GROUP_PROJECT_SCOREBOARD_H
#define OOP_GROUP_PROJECT_SCOREBOARD_H

#include <string>
using std::string;

class Scoreboard {
public:
    unsigned int highScore;
    unsigned int currentScore;

    // Adjusts the score function when each sprite dies.
    void adjustScore(unsigned int adjustment);

    // Resets the score when the player collides with an enemy
    void resetScore();

    // Saves score to text file
    bool saveScoreToFile(string fileName);
};


#endif //OOP_GROUP_PROJECT_SCOREBOARD_H
