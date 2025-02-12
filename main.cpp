#include "raylib.h"

int main() {
  int windowWidth{800};
  int windowHeight{600};
  InitWindow(windowWidth, windowHeight, "Pong");

  //Player
  int playerOneHeight{100};
  int playerOneWidth{10};
  int playerOneX{100};
  int playerOneY{250};

  //Player2
  int playerTwoHeight{100};
  int playerTwoWidth{10};
  int playerTwoX{700};
  int playerTwoY{250};

  //Random ball moviment 
  int directionX = (GetRandomValue(0, 1) == 0) ? -1 : 1;
  int directionY = (GetRandomValue(0, 1) == 0) ? -1 : 1;

  float ballRadius{3.0f};
  Vector2 ballPosition{windowWidth / 2.0f, windowHeight / 2.0f};
  Vector2 ballSpeed{4.0f * directionX, 4.0f * directionY};
  
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(BLACK);
      
      DrawRectangle(playerOneX, playerOneY, playerOneWidth, playerOneHeight, WHITE);
      DrawRectangle(playerTwoX, playerTwoY, playerTwoWidth, playerTwoHeight, WHITE);
      DrawCircleV(ballPosition, ballRadius, WHITE);

      ballPosition.x += ballSpeed.x;
      ballPosition.y += ballSpeed.y;

      if (ballPosition.x - ballRadius <= 0 || ballPosition.x + ballRadius >= windowWidth) {
        ballSpeed.x *= -1;
      }

      if (ballPosition.y - ballRadius <= 0 || ballPosition.y + ballRadius >= windowHeight) {
        ballSpeed.y *= -1;
      }

      if (IsKeyDown(KEY_W) && playerOneY > 0) {
        playerOneY -= 10;
      }

      if (IsKeyDown(KEY_S) && playerOneY < windowHeight - 100) {
        playerOneY += 10;
      }

      EndDrawing();
  }

  CloseWindow();

  return 0;
}
