#include "raylib.h"
#include "../include/playerOne.h"
#include "../include/playerTwo.h"
#include "../include/ball.h"

bool CheckCollisionBallPaddle(Vector2 ballPos, float ballRadius, Rectangle paddle) {
  bool collisionX = (ballPos.x + ballRadius >= paddle.x) && (ballPos.x - ballRadius <= paddle.x + paddle.width);

  bool collisionY = (ballPos.y + ballRadius >= paddle.y) && (ballPos.y - ballRadius <= paddle.y + paddle.height);

  return collisionX && collisionY;
}

int main() {
  int windowWidth{800};
  int windowHeight{600};
  InitWindow(windowWidth, windowHeight, "Pong");

  PlayerOne playerOne(20, windowHeight / 2 - 50, 10, 100, 10);
  PlayerTwo playerTwo(windowWidth - 20, windowHeight / 2 - 50, 10, 100, 10);
  Ball ball(windowWidth / 2, windowHeight / 2, 4.0f, 4.0f, 5.0f);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    playerOne.Update();
    playerTwo.Update(ball.position);
    ball.Update();

    if (ball.CheckCollision(playerOne.paddle) || ball.CheckCollision(playerTwo.paddle)) {
      ball.speed.x *= -1;
    }

    BeginDrawing();
    ClearBackground(BLACK);

    playerOne.Draw();
    playerTwo.Draw();
    ball.Draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
