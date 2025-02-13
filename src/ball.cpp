#include "../include/ball.h"
#include <raylib.h>

Ball::Ball(float startX, float startY, float speedX, float speedY, float radius) {
  position = {startX, startY};
  speed = {speedX, speedY};
  this->radius = radius;
}

void Ball::Update() {
  position.x += speed.x;
  position.y += speed.y;

  if (position.y - radius <= 0 || position.y + radius >= GetScreenHeight()) {
    speed.y *= -1;
  }
}

void Ball::Draw() {
  DrawCircleV(position, radius, WHITE);
}

bool Ball::CheckCollision(Rectangle paddle) {
  return CheckCollisionCircleRec(position, radius, paddle);
}
