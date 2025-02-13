#include "../include/playerTwo.h"
#include <raylib.h>

PlayerTwo::PlayerTwo(float x, float y, float width, float height, float speed) {
    paddle = {x, y, width, height};
    this->speed = speed;
}

void PlayerTwo::Update(Vector2 ballPosition) {
  if (ballPosition.y > paddle.y + paddle.height / 2 && paddle.y < GetScreenHeight() - paddle.height) {
        paddle.y += speed;
    }
    if (ballPosition.y < paddle.y + paddle.height / 2 && paddle.y > 0) {
        paddle.y -= speed;
    }
}

void PlayerTwo::Draw() {
  DrawRectangleRec(paddle, WHITE);
}
