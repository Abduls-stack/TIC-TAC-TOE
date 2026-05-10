#include "TicTacToe.h"

using namespace std;

// Default Constructor
TicTacToe::TicTacToe() : N(3), currentPlayer('X'), winner(' '), moveCount(0) {
    board = new char[N * N];
    for (int i = 0; i < N * N; i++) {
        board[i] = '-';
    }
}

// Parameterized Constructor
TicTacToe::TicTacToe(int n) : N(n), currentPlayer('X'), winner(' '), moveCount(0) {
    if (N < 3) N = 3; // Ensure minimum size
    board = new char[N * N];
    for (int i = 0; i < N * N; i++) {
        board[i] = '-';
    }
}

// Copy Constructor
TicTacToe::TicTacToe(const TicTacToe& other) : N(other.N), currentPlayer(other.currentPlayer), winner(other.winner), moveCount(other.moveCount) {
    board = new char[N * N];
    for (int i = 0; i < N * N; i++) {
        board[i] = other.board[i];
    }
}

// Destructor
TicTacToe::~TicTacToe() {
    delete[] board;
}

// Assignment Operator
TicTacToe& TicTacToe::operator=(const TicTacToe& other) {
    if (this != &other) {
        delete[] board;
        N = other.N;
        currentPlayer = other.currentPlayer;
        winner = other.winner;
        moveCount = other.moveCount;
        board = new char[N * N];
        for (int i = 0; i < N * N; i++) {
            board[i] = other.board[i];
        }
    }
    return *this;
}

// Check if a move is valid
bool TicTacToe::isValidMove(int row, int col) const {
    if (row < 0 || row >= N || col < 0 || col >= N) return false;
    return board[row * N + col] == '-';
}

// Make a move
bool TicTacToe::makeMove(int row, int col) {
    if (!isValidMove(row, col) || isGameOver()) return false;
    
    board[row * N + col] = currentPlayer;
    moveCount++;
    checkGameStatus();
    switchPlayer();
    
    return true;
}

// Helper to check the winner
void TicTacToe::checkGameStatus() {
    if (winner != ' ') return; // Already finished

    // Check rows and cols
    for (int i = 0; i < N; i++) {
        bool rowWin = true;
        bool colWin = true;
        for (int j = 1; j < N; j++) {
            if (board[i * N + j] == '-' || board[i * N + j] != board[i * N]) {
                rowWin = false;
            }
            if (board[j * N + i] == '-' || board[j * N + i] != board[0 * N + i]) {
                colWin = false;
            }
        }
        if (rowWin) { winner = board[i * N]; return; }
        if (colWin) { winner = board[0 * N + i]; return; }
    }

    // Check diagonals
    bool diag1Win = true;
    bool diag2Win = true;
    for (int i = 1; i < N; i++) {
        if (board[i * N + i] == '-' || board[i * N + i] != board[0]) {
            diag1Win = false;
        }
        if (board[i * N + (N - 1 - i)] == '-' || board[i * N + (N - 1 - i)] != board[N - 1]) {
            diag2Win = false;
        }
    }

    if (diag1Win) { winner = board[0]; return; }
    if (diag2Win) { winner = board[N - 1]; return; }

    // Check for draw
    if (moveCount == N * N) {
        winner = 'D'; // Draw
    }
}

// Get the winner
char TicTacToe::getWinner() const {
    return winner;
}

// Check if game is over
bool TicTacToe::isGameOver() const {
    return winner != ' ';
}

// Get board size
int TicTacToe::getSize() const {
    return N;
}

// Get specific cell
char TicTacToe::getCell(int row, int col) const {
    if (row >= 0 && row < N && col >= 0 && col < N) {
        return board[row * N + col];
    }
    return '-';
}

// Set specific cell (useful for loading game states)
void TicTacToe::setCell(int row, int col, char value) {
    if (row >= 0 && row < N && col >= 0 && col < N) {
        board[row * N + col] = value;
    }
}

// Get current player
char TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

// Switch player
void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Get total moves made
int TicTacToe::getMoveCount() const {
    return moveCount;
}

// Console output
ostream& operator<<(ostream& os, const TicTacToe& game) {
    for (int i = 0; i < game.N; i++) {
        for (int j = 0; j < game.N; j++) {
            os << game.board[i * game.N + j] << " ";
        }
        os << "\n";
    }
    return os;
}

// File output
ofstream& operator<<(ofstream& ofs, const TicTacToe& game) {
    static_cast<ostream&>(ofs) << game.N << " " << game.currentPlayer << " " << game.winner << " " << game.moveCount << "\n";
    for (int i = 0; i < game.N * game.N; i++) {
        static_cast<ostream&>(ofs) << game.board[i] << " ";
    }
    static_cast<ostream&>(ofs) << "\n";
    return ofs;
}

// File input
ifstream& operator>>(ifstream& ifs, TicTacToe& game) {
    int n;
    if (static_cast<istream&>(ifs) >> n) {
        if (n != game.N) {
            delete[] game.board;
            game.N = n;
            game.board = new char[game.N * game.N];
        }
        static_cast<istream&>(ifs) >> game.currentPlayer >> game.winner >> game.moveCount;
        for (int i = 0; i < game.N * game.N; i++) {
            static_cast<istream&>(ifs) >> game.board[i];
        }
    }
    return ifs;
}
