#include "../include/player.h"
#include "raylib.h"

Player::Player(float x, float y, float width, float height, float speed) {
  paddle = {x, y, width, height};
  this->speed = speed;
}

void Player::Update() {
  if (IsKeyDown(KEY_W) && paddle.y > 0) {
    paddle.y -= speed;
  }

  if (IsKeyDown(KEY_S) && paddle.y < GetScreenHeight() - paddle.height) {
    paddle.y += speed;
  }
}

void Player::Draw() {
  DrawRectangleRec(paddle, WHITE);
}

void Player::ManualControl() {
    if (IsKeyDown(KEY_UP) && paddle.y > 0) {
        paddle.y -= speed;
    }
    if (IsKeyDown(KEY_DOWN) && paddle.y < GetScreenHeight() - paddle.height) {
        paddle.y += speed;
    }
}
