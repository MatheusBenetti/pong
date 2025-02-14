# 🏓 Pong Game (C++ & Raylib)

A classic Pong game implemented in **C++** using the **Raylib** library.  
This project supports **Player vs Player (PvP)** and **Player vs AI (PvAI)** modes, with adjustable difficulty settings.

## 🚀 Features
- **Two game modes:** Player vs Player and Player vs AI.
- **Difficulty settings:** AI difficulty can be adjusted.
- **Speed variation:** The ball speed increases with higher difficulty levels.
- **Score tracking:** The game keeps track of scores and resets when a player reaches the max score.
- **Game Over Screen:** Displays the winner and waits for user input to restart or return to the menu.

## 🎮 Controls
| Action       | Player 1 | Player 2 |
|-------------|----------|----------|
| Move Up    | `W`      | `Up Arrow` |
| Move Down  | `S`      | `Down Arrow` |
| Start Game | `Enter`  |  |
| Quit Game  | `Esc`    |  |

## 📥 Installation & Execution
### 🛠️ **Requirements**
- **C++ Compiler** (`g++` or `gcc`)
- **Raylib Library** (version 4.0 or later)
- **Makefile support** (recommended for Linux/macOS)

### 📌 **1. Install Raylib**
#### 🔹 **Arch Linux**
```sh
yay -S raylib
```

#### 🔹 **Debian/Ubuntu**
```sh
sudo apt install libraylib-dev
```

#### 🔹 **macOS (Homebrew)**
```sh
brew install raylib
```

#### 🔹 **Windows**
- Download and install Raylib from [Raylib official site](https://www.raylib.com/).
- Make sure to link `raylib.lib` correctly in your compiler settings.

---

### 📌 **2. Clone the repository**
```sh
git clone https://github.com/yourusername/pong-game.git
cd pong-game
```

---

### 📌 **3. Compile the project**
#### 🔹 **Using Makefile (Recommended)**
```sh
make
```

#### 🔹 **Manual Compilation (Linux/macOS)**
```sh
g++ src/main.cpp src/player.cpp src/ai.cpp src/ball.cpp src/menu.cpp src/score.cpp -o pong -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

#### 🔹 **Manual Compilation (Windows)**
```sh
g++ src/main.cpp src/player.cpp src/ai.cpp src/ball.cpp src/menu.cpp src/score.cpp -o pong -lraylib
```

---

### 📌 **4. Run the game**
```sh
./pong
```

---

## 🏗️ Project Structure
```
/pong-game/
│── /src/               # Source files
│   │── main.cpp        # Game loop
│   │── player.cpp      # Player class
│   │── ai.cpp          # AI logic
│   │── ball.cpp        # Ball physics
│   │── menu.cpp        # Game menu
│   │── score.cpp       # Score handling
│── /include/           # Header files
│   │── player.h
│   │── ai.h
│   │── ball.h
│   │── menu.h
│   │── score.h
│── /bin/               # Compiled output (optional)
│── Makefile            # Build automation
│── README.md           # Documentation
```

---

## ⚡ Future Improvements
- **Sound Effects** 🎵: Add collision and score sounds.
- **Better AI** 🤖: Improve AI behavior and responsiveness.
- **Power-ups** 🔥: Introduce fun game modifications like speed boosts.

---

