#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to clear input buffer to prevent infinite loops on bad input
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to initialize the 3x3 game board with numbers 1 to 9
void initializeBoard(vector<vector<char>>& board) {
    char count = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count++;
        }
    }
}

// Function to render the ASCII game board dynamically after each turn
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
    cout << "\n";
}

// Function to check win conditions across rows, columns, and diagonals
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is completely full (Draw condition)
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If any cell still contains a digit '1'-'9', the game is not a draw yet
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3)); // Corrected 2D vector declaration
    char currentPlayer = 'X';
    bool playAgain = true;

    cout << "========================================\n";
    cout << "    WELCOME TO 2-PLAYER TIC-TAC-TOE     \n";
    cout << "========================================\n";

    while (playAgain) {
        initializeBoard(board);
        bool gameOver = false;
        currentPlayer = 'X'; // X always starts

        while (!gameOver) {
            displayBoard(board);
            int move;

            // Input validation loop to ensure user enters a valid slot number (1-9)
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            while (!(cin >> move) || move < 1 || move > 9) {
                cout << "Invalid input. Please enter a number between 1 and 9: ";
                clearInputBuffer();
            }

            // Map grid choice (1-9) to 2D array coordinates [row][col]
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            // Error handling: Check if the selected spot is already taken by X or O
            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Error: That spot is already taken! Choose an empty cell.\n";
                continue; // Skip turn switch and let current player try again
            }

            // Place the player's marker on the board
            board[row][col] = currentPlayer;

            // Check if current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "CONGRATULATIONS! Player " << currentPlayer << " wins the game!\n";
                gameOver = true;
            }
            // Check if the game has ended in a draw
            else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a Draw! The board is full.\n";
                gameOver = true;
            } else {
                // Switch player turns ('X' vs 'O')
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        // Prompt to play again
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            playAgain = false;
            cout << "Thanks for playing!\n";
        }
    }

    return 0;
}
