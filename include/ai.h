#ifndef AI_H
#define AI_H

#include "raylib.h"

class AI {
  public:
    Rectangle paddle;
    float speed;
    int difficulty;

    AI(float x, float y, float width, float height, int difficulty);

    void Update(Vector2 ballPosition);
    void ManualControl();
    void Draw();
};

#endif // !AI_H
