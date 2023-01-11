#include "Scoreboard.h"
#include <fstream>
#include <string>
using std::string;

// Implementation of adjusting the score function.
void Scoreboard::adjustScore(unsigned int adjustment)
{
    // Each time the player hits an enemy with a projectile, increase by some integer value ('adjustment amount')

    // Determine when the player hits an enemy
    currentScore += adjustment;
}

// Implementation of saving all scores to a text file.
bool saveScoreToFile(string "scores.txt"){
    // function saveScore to save to a file (.txt file, have a list of the high scores)
    std::ofstream high_score_file;
    high_score_file.open("scores.txt", std::ios_base::app);
    high_score_file << currentScore;
}

// Implementation of resetting the score.
void Scoreboard::resetScore(){
    currentScore = 0;
}