#include "../include/menu.h"
#include <raylib.h>

Menu::Menu() {
  mode = PLAYER_VS_PLAYER;
  maxScore = 5;
  aiDifficulty = 1;
  isRunning = true;
  exitGame = false;
}

void Menu::Draw() {
  ClearBackground(BLACK);

  int centerX = GetScreenWidth() / 2;
  int startY = 100;
  int spacing = 50;

  DrawText("PONG MENU", 320, 50, 30, WHITE);

  Color pvpColor = (mode == PLAYER_VS_PLAYER) ? GREEN : WHITE;
  Color aiColor = (mode == PLAYER_VS_AI) ? GREEN : WHITE;

  DrawText("Press 1 - Player vs Player", centerX - MeasureText("Press 1 - Player vs Player", 20) / 2, startY + spacing, 20, pvpColor);
  DrawText("Press 2 - Player vs AI", centerX - MeasureText("Press 2 - Player vs AI", 20) / 2, startY + spacing * 2, 20, aiColor);

  DrawText("Press UP/DOWN to change max score", centerX - MeasureText("Press UP/DOWN to change max score", 20) / 2, startY + spacing * 4, 20, WHITE);
  DrawText(TextFormat("Max Score: %d", maxScore), centerX - MeasureText("Max Score: 5", 20) / 2, startY + spacing * 5, 20, WHITE);

  DrawText("Press LEFT/RIGHT to change AI difficulty", centerX - MeasureText("Press LEFT/RIGHT to change AI difficulty", 20) / 2, startY + spacing * 6, 20, WHITE);
  DrawText(TextFormat("AI Difficulty: %d", aiDifficulty), centerX - MeasureText("AI Difficulty: 5", 20) / 2, startY + spacing * 7, 20, WHITE);

  DrawText("Press ENTER to Start", centerX - MeasureText("Press ENTER to Start", 20) / 2, startY + spacing * 9, 20, YELLOW);
  DrawText("Press ESC to Exit", centerX - MeasureText("Press ESC to Exit", 20) / 2, startY + spacing * 10, 20, RED);
}

void Menu::HandleInput() {
  if (IsKeyPressed(KEY_ONE)) mode = PLAYER_VS_PLAYER;
  if (IsKeyPressed(KEY_TWO)) mode = PLAYER_VS_AI;

  if (IsKeyPressed(KEY_UP)) maxScore++;
  if (IsKeyPressed(KEY_DOWN) && maxScore > 1) maxScore--;

  if (IsKeyPressed(KEY_RIGHT)) aiDifficulty++;
  if (IsKeyPressed(KEY_LEFT) && aiDifficulty > 1) aiDifficulty--;

  if (IsKeyPressed(KEY_ENTER)) isRunning = false;
  if (IsKeyPressed(KEY_ESCAPE)) exitGame = true;
}
