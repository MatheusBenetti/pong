#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball {
  public:
    Vector2 position;
    Vector2 speed;
    float radius;

    Ball(float startX, float startY, float speedX, float speedY, float radius);

    void Update();
    void Draw();
    bool CheckCollision(Rectangle paddle);
};

#endif // !BALL_H
