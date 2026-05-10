# 🎮 Tic-Tac-Toe & Ultimate Tic-Tac-Toe

A C++ implementation of the classic **Tic-Tac-Toe** game along with the advanced **Ultimate Tic-Tac-Toe** variant — built using Object-Oriented Programming principles.

---

## 📋 Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [How to Play](#how-to-play)
- [Game Rules](#game-rules)
- [Technologies Used](#technologies-used)

---

## ✨ Features

- **Classic Tic-Tac-Toe** — Play on a standard 3×3 board or customize the board size (N×N)
- **Ultimate Tic-Tac-Toe** — A strategic 9-board variant where each cell contains its own Tic-Tac-Toe game
- **OOP Architecture** — Clean class hierarchy with proper encapsulation, copy constructors, and operator overloading
- **Dynamic Memory Management** — Board allocated dynamically using pointers with proper RAII
- **Save & Load** — Game state serialization via overloaded file stream operators (`<<` / `>>`)
- **Input Validation** — Robust move validation to prevent illegal plays

---

## 📁 Project Structure

```
TIC-TAC-TOE/
├── main.cpp                 # Entry point — game loop and menu
├── TicTacToe.h              # TicTacToe class declaration
├── TicTacToe.cpp            # TicTacToe class implementation
├── UltimateTicTacToe.h      # UltimateTicTacToe class declaration
├── UltimateTicTacToe.cpp    # UltimateTicTacToe class implementation
├── .gitignore               # Git ignore rules
└── README.md                # Project documentation
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting **C++11** or later (e.g., `g++`, `clang++`, or MSVC)

### Build & Run

```bash
# Clone the repository
git clone https://github.com/Abduls-stack/TIC-TAC-TOE.git
cd TIC-TAC-TOE

# Compile
g++ -o game main.cpp TicTacToe.cpp UltimateTicTacToe.cpp -std=c++11

# Run
./game
```

On Windows (with MinGW):
```bash
g++ -o game.exe main.cpp TicTacToe.cpp UltimateTicTacToe.cpp -std=c++11
game.exe
```

---

## 🎯 How to Play

### Classic Tic-Tac-Toe
1. Players take turns placing **X** or **O** on the board
2. Enter the **row** and **column** number to make a move
3. First player to get N in a row (horizontally, vertically, or diagonally) wins!

### Ultimate Tic-Tac-Toe
1. The game is played on a **3×3 grid of 3×3 boards**
2. Your move determines which board the next player must play in
3. Win three small boards in a row to win the overall game!

---

## 📏 Game Rules

### Classic Mode
| Rule | Description |
|------|-------------|
| Board Size | Default 3×3, supports N×N |
| Players | Two players: **X** and **O** |
| Win Condition | N marks in a row, column, or diagonal |
| Draw | All cells filled with no winner |

### Ultimate Mode
| Rule | Description |
|------|-------------|
| Structure | 9 small Tic-Tac-Toe boards in a 3×3 grid |
| Move Constraint | The cell you play in determines the next player's board |
| Board Win | Standard Tic-Tac-Toe rules apply per small board |
| Global Win | Win 3 small boards in a row, column, or diagonal |

---

## 🛠 Technologies Used

- **Language:** C++11
- **Paradigm:** Object-Oriented Programming
- **Concepts:** Dynamic memory allocation, operator overloading, copy semantics, file I/O

---

## 👤 Author

**Abdul** — [@Abduls-stack](https://github.com/Abduls-stack)

---

## 📄 License

This project is open source and available for educational purposes.
