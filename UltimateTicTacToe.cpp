#include "UltimateTicTacToe.h"

using namespace std;

// Default Constructor
UltimateTicTacToe::UltimateTicTacToe() : activeBoard(-1), currentPlayer('X'), globalWinner(' ') {
    for (int i = 0; i < 9; i++) {
        mainBoard[i] = '-';
    }
}

// Copy Constructor
UltimateTicTacToe::UltimateTicTacToe(const UltimateTicTacToe& other) : activeBoard(other.activeBoard), currentPlayer(other.currentPlayer), globalWinner(other.globalWinner) {
    for (int i = 0; i < 9; i++) {
        boards[i] = other.boards[i];
        mainBoard[i] = other.mainBoard[i];
    }
}

// Destructor
UltimateTicTacToe::~UltimateTicTacToe() {
    // Memory handled by TicTacToe destructors
}

// Validate move
bool UltimateTicTacToe::isValidMove(int boardIdx, int cellIdx) const {
    if (globalWinner != ' ') return false;
    if (boardIdx < 0 || boardIdx >= 9 || cellIdx < 0 || cellIdx >= 9) return false;
    
    // Check if player is forced to play in a specific board
    if (activeBoard != -1 && boardIdx != activeBoard) return false;

    // Check if the board is already won or full
    if (mainBoard[boardIdx] != '-') return false;
    if (boards[boardIdx].isGameOver()) return false;

    // Check if cell is empty
    int row = cellIdx / 3;
    int col = cellIdx % 3;
    return boards[boardIdx].isValidMove(row, col);
}

// Make a move
bool UltimateTicTacToe::makeMove(int boardIdx, int cellIdx) {
    if (!isValidMove(boardIdx, cellIdx)) return false;

    int row = cellIdx / 3;
    int col = cellIdx % 3;
    
    // Sync current player with the sub-board
    if (boards[boardIdx].getCurrentPlayer() != currentPlayer) {
        boards[boardIdx].switchPlayer();
    }

    boards[boardIdx].makeMove(row, col);

    // Check if the sub-board was won or drawn
    if (boards[boardIdx].isGameOver()) {
        char bw = boards[boardIdx].getWinner();
        mainBoard[boardIdx] = bw;
        checkGlobalWinner();
    }

    // Determine next active board
    // The next active board is determined by the cell index of the current move
    if (mainBoard[cellIdx] == '-' && !boards[cellIdx].isGameOver()) {
        activeBoard = cellIdx;
    } else {
        activeBoard = -1; // Next player can play anywhere
    }

    // Switch player
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    return true;
}

// Check global winner
void UltimateTicTacToe::checkGlobalWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (mainBoard[i*3] != '-' && mainBoard[i*3] != 'D' && mainBoard[i*3] == mainBoard[i*3+1] && mainBoard[i*3+1] == mainBoard[i*3+2]) {
            globalWinner = mainBoard[i*3];
            return;
        }
        // Check cols
        if (mainBoard[i] != '-' && mainBoard[i] != 'D' && mainBoard[i] == mainBoard[i+3] && mainBoard[i+3] == mainBoard[i+6]) {
            globalWinner = mainBoard[i];
            return;
        }
    }
    // Check diags
    if (mainBoard[0] != '-' && mainBoard[0] != 'D' && mainBoard[0] == mainBoard[4] && mainBoard[4] == mainBoard[8]) {
        globalWinner = mainBoard[0];
        return;
    }
    if (mainBoard[2] != '-' && mainBoard[2] != 'D' && mainBoard[2] == mainBoard[4] && mainBoard[4] == mainBoard[6]) {
        globalWinner = mainBoard[2];
        return;
    }

    // Check draw
    bool allFilled = true;
    for (int i = 0; i < 9; i++) {
        if (mainBoard[i] == '-') {
            allFilled = false;
            break;
        }
    }
    if (allFilled) globalWinner = 'D';
}

// Get global winner
char UltimateTicTacToe::getGlobalWinner() const {
    return globalWinner;
}

// Is game over
bool UltimateTicTacToe::isGameOver() const {
    return globalWinner != ' ';
}

// Get active board
int UltimateTicTacToe::getActiveBoard() const {
    return activeBoard;
}

// Get current player
char UltimateTicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

// Output stream
ostream& operator<<(ostream& os, const UltimateTicTacToe& game) {
    os << "\n";
    for (int bigRow = 0; bigRow < 3; bigRow++) {
        for (int smallRow = 0; smallRow < 3; smallRow++) {
            for (int bigCol = 0; bigCol < 3; bigCol++) {
                int boardIdx = bigRow * 3 + bigCol;
                for (int smallCol = 0; smallCol < 3; smallCol++) {
                    if (game.mainBoard[boardIdx] == 'X' || game.mainBoard[boardIdx] == 'O') {
                        // Display winner of the small board block
                        os << " " << game.mainBoard[boardIdx] << " ";
                    } else {
                        os << " " << game.boards[boardIdx].getCell(smallRow, smallCol) << " ";
                    }
                }
                if (bigCol < 2) os << " | ";
            }
            os << "\n";
        }
        if (bigRow < 2) {
            os << "-------------------------------------\n";
        }
    }
    os << "\n";
    return os;
}

// File output stream
ofstream& operator<<(ofstream& ofs, const UltimateTicTacToe& game) {
    static_cast<ostream&>(ofs) << game.activeBoard << " " << game.currentPlayer << " " << game.globalWinner << "\n";
    for (int i = 0; i < 9; i++) {
        static_cast<ostream&>(ofs) << game.mainBoard[i] << " ";
    }
    static_cast<ostream&>(ofs) << "\n";
    for (int i = 0; i < 9; i++) {
        ofs << game.boards[i]; // correctly uses ofstream overload
    }
    return ofs;
}

// File input stream
ifstream& operator>>(ifstream& ifs, UltimateTicTacToe& game) {
    if (static_cast<istream&>(ifs) >> game.activeBoard >> game.currentPlayer >> game.globalWinner) {
        for (int i = 0; i < 9; i++) {
            static_cast<istream&>(ifs) >> game.mainBoard[i];
        }
        for (int i = 0; i < 9; i++) {
            ifs >> game.boards[i]; // correctly uses ifstream overload
        }
    }
    return ifs;
}
