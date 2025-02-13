#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include "raylib.h"

class PlayerTwo {
  public:
    Rectangle paddle;
    float speed;

    PlayerTwo(float x, float y, float width, float height, float speed);

    void Update(Vector2 ballPosition);
    void Draw();
};

#endif // !PLAYERTWO_H
