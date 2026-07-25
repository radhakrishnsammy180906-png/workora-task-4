# 2-Player Console Tic-Tac-Toe in C++

## Project Description
A console-based 2-player Tic-Tac-Toe game developed in C++ utilizing a 2D vector matrix representation. The application features dynamic ASCII board rendering after every turn, rigorous player turn switching ('X' vs 'O'), coordinate mapping for inputs, and robust win/draw evaluation algorithms across rows, columns, and diagonals.

---

## Features & Implementation
* **2D Array Matrix Representation:** Manages game state efficiently using a standard 3x3 character vector matrix.
* **Turn Switching & Validation:** Automatically switches turns between Player X and Player O, validating that moves fall within range (1-9) and that spaces are not double-booked.
* **Comprehensive Error Handling:** Implements `cin` error-clearing buffers and input checks to prevent infinite loops and crashes upon receiving invalid character inputs.
* **Win/Draw Detection Logic:** Scans rows, columns, and both diagonals dynamically after every single turn to catch victories instantly.

---

## How to Run & Build Instructions

Make sure you have a standard C++ compiler installed (such as `g++`).

### 1. Compilation Command
Open your terminal or command prompt in the directory containing your source file and run:
```bash
g++ -std=c++11 tictactoe.cpp -o tictactoe
