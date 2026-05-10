#ifndef ULTIMATETICTACTOE_H
#define ULTIMATETICTACTOE_H

#include "TicTacToe.h"
#include <iostream>
#include <fstream>

class UltimateTicTacToe {
private:
    TicTacToe boards[9]; // 9 boards of 3x3
    char mainBoard[9];   // 'X', 'O', 'D' (Draw), or '-'
    int activeBoard;     // -1 for any, 0-8 for specific board
    char currentPlayer;
    char globalWinner;   // 'X', 'O', 'D', or ' '

    void checkGlobalWinner();

public:
    // Constructors & Destructor
    UltimateTicTacToe();
    UltimateTicTacToe(const UltimateTicTacToe& other);
    ~UltimateTicTacToe();

    // Game Logic
    bool isValidMove(int boardIdx, int cellIdx) const;
    bool makeMove(int boardIdx, int cellIdx);
    char getGlobalWinner() const;
    bool isGameOver() const;
    int getActiveBoard() const;
    char getCurrentPlayer() const;

    // Stream operator functions for console
    friend std::ostream& operator<<(std::ostream& os, const UltimateTicTacToe& game);

    // Stream operator functions for filing
    friend std::ofstream& operator<<(std::ofstream& ofs, const UltimateTicTacToe& game);
    friend std::ifstream& operator>>(std::ifstream& ifs, UltimateTicTacToe& game);
};

#endif
