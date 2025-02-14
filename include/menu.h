#ifndef MENU_H
#define MENU_H

#include "raylib.h"

enum GameMode { PLAYER_VS_PLAYER, PLAYER_VS_AI };

class Menu {
public:
    GameMode mode;
    int maxScore;
    int aiDifficulty;
    bool isRunning;
    bool exitGame;

    Menu();

    void Draw();
    void HandleInput();
};

#endif
