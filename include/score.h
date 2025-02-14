#ifndef SCORE_H
#define SCORE_H

#include "raylib.h"

class Score {
  public:
    int playerOneScore;
    int playerTwoScore;
    int maxScore;
    bool gameOver;
    int winner;

    Score(int maxScore);

    void Draw();
    void CheckWinner();
};

#endif // !SCORE_H
