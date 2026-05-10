#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <fstream>

class TicTacToe {
private:
    char* board; // 1D array mapped to 2D for easier dynamic allocation (requirement mentions "a pointer")
    int N;
    char currentPlayer;
    char winner; // 'X', 'O', 'D' (Draw), or ' ' (Ongoing)
    int moveCount;

    // Helper to determine the status after a move
    void checkGameStatus();

public:
    // Constructors & Destructor
    TicTacToe(); // Default 3x3
    TicTacToe(int n); // Parameterized NxN
    TicTacToe(const TicTacToe& other); // Copy Constructor
    ~TicTacToe();

    // Assignment operator
    TicTacToe& operator=(const TicTacToe& other);

    // Game Logic
    bool isValidMove(int row, int col) const;
    bool makeMove(int row, int col);
    char getWinner() const;
    bool isGameOver() const;
    int getSize() const;
    char getCell(int row, int col) const;
    void setCell(int row, int col, char value);
    char getCurrentPlayer() const;
    void switchPlayer();
    int getMoveCount() const;

    // Stream operator functions for console
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);

    // File stream operator functions
    friend std::ofstream& operator<<(std::ofstream& ofs, const TicTacToe& game);
    friend std::ifstream& operator>>(std::ifstream& ifs, TicTacToe& game);
};

#endif
