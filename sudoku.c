#include <stdio.h>

#define SIZE 5

void printGrid(int[SIZE][SIZE]);
int isValid(int[SIZE][SIZE], int, int, int);
int solveSudoku(int[SIZE][SIZE]);

int main() 
{
    int grid[SIZE][SIZE] = {
        {1, 0, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 4, 0},
        {0, 0, 0, 0, 5}
    };

    printf("Sudoku Puzzle:\n");
    printGrid(grid);

    if(solveSudoku(grid)) {
        printf("\nSolution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}

// prints the sudoku grid
void printGrid(int grid[SIZE][SIZE]) 
{
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// checks if a number is valid in a particular cell
int isValid(int grid[SIZE][SIZE], int row, int col, int num) 
{
    // checks if the same num is not present in the same row or col
    for(int p = 0; p < SIZE; p++) {
        if(grid[row][p] == num || grid[p][col] == num) {
            return 0;
        }
    }

    return 1;
}

// solves sudoku using backtracking
int solveSudoku(int grid[SIZE][SIZE]) 
{
    int row, col;

    // finds an empty cell
    int isEmpty = 0;
    for(row = 0; row < SIZE; row++) {
        for(col = 0; col < SIZE; col++) {
            if(grid[row][col] == 0) {
                isEmpty = 1;
                break;
            }
        }
        if(isEmpty) {
            break;
        }
    }

    // if there is no empty cell, then it is solved
    if(!isEmpty) {
        return 1;
    }

    // place valid num in an empty cell
    for(int num = 1; num <= SIZE; num++) {
        if(isValid(grid, row, col, num)) {
            grid[row][col] = num;

            // recursive solving
            if(solveSudoku(grid)) {
                return 1;
            }

            // backtrack if it does not lead to correct solution
            grid[row][col] = 0;
        }
    }

    return 0;
}

