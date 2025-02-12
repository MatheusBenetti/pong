#include "raylib.h"

bool CheckCollisionBallPaddle(Vector2 ballPos, float ballRadius, Rectangle paddle) {
  bool collisionX = (ballPos.x + ballRadius >= paddle.x) && (ballPos.x - ballRadius <= paddle.x + paddle.width);

  bool collisionY = (ballPos.y + ballRadius >= paddle.y) && (ballPos.y - ballRadius <= paddle.y + paddle.height);

  return collisionX && collisionY;
}

int main() {
  int windowWidth{800};
  int windowHeight{600};
  InitWindow(windowWidth, windowHeight, "Pong");

  //Player
  float playerOneHeight{100.0f};
  float playerOneWidth{10.0f};
  float playerOneX{100.0f};
  float playerOneY{250.0f};
  Rectangle playerOne{playerOneX, playerOneY, playerOneWidth, playerOneHeight};

  //Player2
  float playerTwoHeight{100.0f};
  float playerTwoWidth{10.0f};
  float playerTwoX{700.0f};
  float playerTwoY{250.0f};
  int playerTwoSpeed{5};
  Rectangle playerTwo{playerTwoX, playerTwoY, playerTwoWidth, playerTwoHeight};

  //Random ball movement
  int directionX = (GetRandomValue(0, 1) == 0) ? -1 : 1;
  int directionY = (GetRandomValue(0, 1) == 0) ? -1 : 1;

  float ballRadius{3.0f};
  Vector2 ballPosition{windowWidth / 2.0f, windowHeight / 2.0f};
  Vector2 ballSpeed{4.0f * directionX, 4.0f * directionY};

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(BLACK);

      playerOne.y = playerOneY;
      playerTwo.y = playerTwoY;

      DrawRectangle(playerOne.x, playerOne.y, playerOne.width, playerOne.height, WHITE);
      DrawRectangle(playerTwo.x, playerTwo.y, playerTwo.width, playerTwo.height, WHITE);
      DrawCircleV(ballPosition, ballRadius, WHITE);

      ballPosition.x += ballSpeed.x;
      ballPosition.y += ballSpeed.y;

      if (ballPosition.x - ballRadius <= 0 || ballPosition.x + ballRadius >= windowWidth) {
        ballSpeed.x *= -1;
      }

      if (ballPosition.y - ballRadius <= 0 || ballPosition.y + ballRadius >= windowHeight) {
        ballSpeed.y *= -1;
      }

      if (CheckCollisionBallPaddle(ballPosition, ballRadius, playerOne)) {
        ballSpeed.x *= -1;
      }

      if (CheckCollisionBallPaddle(ballPosition, ballRadius, playerTwo)) {
        ballSpeed.x *= -1;
      }

      if (IsKeyDown(KEY_W) && playerOneY > 0) {
        playerOneY -= 10;
      }

      if (IsKeyDown(KEY_S) && playerOneY < windowHeight - 100) {
        playerOneY += 10;
      }

      if (ballPosition.y > playerTwoY + playerTwoHeight / 2 && playerTwoY < windowHeight - 100) {
         playerTwoY += playerTwoSpeed;
      }

      if (ballPosition.y < playerTwoY + playerTwoHeight / 2 && playerTwoY > 0) {
        playerTwoY -= playerTwoSpeed;
      }

      EndDrawing();
  }

  CloseWindow();

  return 0;
}
