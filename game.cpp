#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false; // There is an empty cell, game is not a draw
        }
    }
    return true; // All cells are filled, game is a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X'; // Start with player X
    bool gameOver = false;

    while (!gameOver) {
        // Display current board
        cout << "Current board:" << endl;
        displayBoard(board);

        // Prompt current player for their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the chosen cell is empty and within the board boundaries
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Update board with player's move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            }
            // Check if the game is a draw
            else if (checkDraw(board)) {
                cout << "It's a draw!" << endl;
                gameOver = true;
            }
            // Switch players
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    return 0;
}
