#include "../include/score.h"

Score::Score(int maxScore) {
  playerOneScore = 0;
  playerTwoScore = 0;
  this->maxScore = maxScore;
  gameOver = false;
  winner = 0;
}

void Score::Draw() {
    DrawText(TextFormat("%d", playerOneScore), 350, 20, 40, WHITE);
    DrawText(TextFormat("%d", playerTwoScore), 450, 20, 40, WHITE);

    if (gameOver) {
      DrawRectangle(200, 200, 400, 200, BLACK);
      DrawText("GAME OVER!", 300, 250, 30, RED);
      DrawText(TextFormat("Player %d Wins!", winner), 320, 300, 20, WHITE);
      DrawText("Press ENTER to return to menu", 260, 350, 20, YELLOW);
    }
}

void Score::CheckWinner() {
  if (playerOneScore >= maxScore) {
    gameOver = true;
    winner = 1;
  }
  if (playerTwoScore >= maxScore) {
    gameOver = true;
    winner = 2;
  }
}
