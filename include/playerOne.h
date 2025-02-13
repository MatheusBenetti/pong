#ifndef PLAYERONE_H
#define PLAYERONE_H

#include "raylib.h"

class PlayerOne {
  public:
    Rectangle paddle;
    float speed;

    PlayerOne(float x, float y, float width, float height, float speed);

    void Update();
    void Draw();
};

#endif // !PLAYERONE_H

