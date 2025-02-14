#include "../include/ai.h"
#include <raylib.h>

AI::AI(float x, float y, float width, float height, int difficulty) {
    paddle = {x, y, width, height};
    this->difficulty = difficulty;

    switch (difficulty) {
      case 1: speed = 3.0f; break;
      case 2: speed = 5.0f; break;
      case 3: speed = 7.0f; break;
      default: speed = 5.0f; break;
    }
}

void AI::Update(Vector2 ballPosition) {
  if (ballPosition.y > paddle.y + paddle.height / 2 && paddle.y < GetScreenHeight() - paddle.height) {
    paddle.y += speed;
  }
  if (ballPosition.y < paddle.y + paddle.height / 2 && paddle.y > 0) {
    paddle.y -= speed;
  }
}

void AI::Draw() {
  DrawRectangleRec(paddle, WHITE);
}

