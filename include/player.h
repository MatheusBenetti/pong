#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
  public:
    Rectangle paddle;
    float speed;

    Player(float x, float y, float width, float height, float speed);

    void Update();
    void ManualControl();
    void Draw();
};

#endif // !PLAYER_H

