// Program to implement 8-queen’s problem

#include <iostream>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int board[8][8], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < 8; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve the 8-Queens problem using backtracking
bool solveNQueens(int board[8][8], int col) {
    // If all queens are placed then return true
    if (col >= 8)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < 8; ++i) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, col + 1))
                return true;

            // If placing queen at board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0; // Remove the queen from board[i][col]
        }
    }

    // If the queen cannot be placed in any row in this column, then return false
    return false;
}

// Function to print the solution
void printSolution(int board[8][8]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int board[8][8] = {0}; // Initialize the chessboard with zeros

    if (solveNQueens(board, 0)) {
        cout << "Solution exists:\n";
        printSolution(board);
    } else {
        cout << "Solution does not exist!";
    }

    return 0;
}

/*
        Complexity:- 
        The power of the set of all possible solutions of the n queen’s problem is n! and the 
        bounding function takes a linear amount of time to calculate, therefore the running time 
        of the n queens problem is O(n!). 

*/
