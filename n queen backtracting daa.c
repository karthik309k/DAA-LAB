#include <stdio.h>
#include <stdbool.h>

#define N 4  // Number of queens

// Function to print the chessboard
void printBoard(int board[N][N]) {
    int i, j; // Declare loop variables outside
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j; // Declare loop variables outside

    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int board[N][N], int col) {
    int i; // Declare loop variable outside
    if (col >= N) {
        return true;
    }

    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1)) {
                return true;
            }

            board[i][col] = 0;  // Backtrack
        }
    }

    return false;
}

int main() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0)) {
        printBoard(board);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}

