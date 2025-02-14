#include "raylib.h"
#include "../include/player.h"
#include "../include/ai.h"
#include "../include/ball.h"
#include "../include/menu.h"
#include "../include/score.h"
#include <thread>
#include <chrono>

void WaitForKeyRelease(int key) {
    while (IsKeyDown(key)) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
}

int main() {
    int windowWidth = 800;
    int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "Pong");

    while (!WindowShouldClose()) {
        WaitForKeyRelease(KEY_ENTER);

        Menu menu;
        bool restartGame = false;

        while (menu.isRunning) {
            BeginDrawing();
            ClearBackground(BLACK);
            menu.Draw();
            menu.HandleInput();
            EndDrawing();

            if (menu.exitGame) {
                CloseWindow();
                return 0;
            }
        }

        Score score(menu.maxScore);
        bool isAI = (menu.mode == PLAYER_VS_AI);
        int aiDifficulty = menu.aiDifficulty;

        Player playerOne(20, windowHeight / 2 - 50, 10, 100, 5);
        Player* playerTwo = nullptr;
        AI* aiPlayer = nullptr;
        Ball ball(windowWidth / 2, windowHeight / 2, 4.0f, 4.0f, 5.0f);

        if (isAI) {
            aiPlayer = new AI(windowWidth - 30, windowHeight / 2 - 50, 10, 100, aiDifficulty);
        } else {
            playerTwo = new Player(windowWidth - 30, windowHeight / 2 - 50, 10, 100, 5);
        }

        SetTargetFPS(60);

        while (!WindowShouldClose()) {
            if (score.gameOver) {
                BeginDrawing();
                ClearBackground(BLACK);
                score.Draw();
                EndDrawing();

                if (IsKeyPressed(KEY_ENTER)) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    WaitForKeyRelease(KEY_ENTER);
                    restartGame = true;
                    break;
                }
                continue;
            }

            playerOne.Update();
            if (isAI && aiPlayer) {
                aiPlayer->Update(ball.position);
            } else if (!isAI && playerTwo) {
                playerTwo->ManualControl();
            }

            ball.Update();

            if (ball.CheckCollision(playerOne.paddle)) {
                ball.speed.x *= -1;
            }

            if ((isAI && aiPlayer && ball.CheckCollision(aiPlayer->paddle)) ||
                (!isAI && playerTwo && ball.CheckCollision(playerTwo->paddle))) {
                ball.speed.x *= -1;
            }

            if (ball.position.x - ball.radius <= 0) {
                score.playerTwoScore++;
                ball.position = {windowWidth / 2.0f, windowHeight / 2.0f};
            }

            if (ball.position.x + ball.radius >= windowWidth) {
                score.playerOneScore++;
                ball.position = {windowWidth / 2.0f, windowHeight / 2.0f};
            }

            score.CheckWinner();

            BeginDrawing();
            ClearBackground(BLACK);
            playerOne.Draw();
            if (isAI && aiPlayer) {
                aiPlayer->Draw();
            } else if (!isAI && playerTwo) {
                playerTwo->Draw();
            }
            ball.Draw();
            score.Draw();
            EndDrawing();
        }

        delete playerTwo;
        delete aiPlayer;

        if (restartGame) {
            continue;
        }
    }

    CloseWindow();
    return 0;
}
