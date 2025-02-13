#include "../include/playerOne.h"
#include "raylib.h"

PlayerOne::PlayerOne(float x, float y, float width, float height, float speed) {
  paddle = {x, y, width, height};
  this->speed = speed;
}

void PlayerOne::Update() {
  if (IsKeyDown(KEY_W) && paddle.y > 0) {
    paddle.y -= speed;
  }

  if (IsKeyDown(KEY_S) && paddle.y < GetScreenHeight() - 100) {
    paddle.y += speed;
  }
}

void PlayerOne::Draw() {
  DrawRectangleRec(paddle, WHITE);
}
