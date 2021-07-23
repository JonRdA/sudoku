// Implements helper functions to solve a sudoku.

#include "solver.h"

// Backtracking recursive sudoku solver
void solve(void)
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int n = 1; n <= SIZE; n++)
                {
                    // If n is valid, put it and solve new grid.
                    if (valid(n, row, col))
                    {
                        grid[row][col] = n;
                        solve();
                        
                        // Stop execution once a solution was found.
                        if (!run)
                        {
                            return;
                        }

                        // solve() returned, set box to 0 to backtrack.
                        grid[row][col] = 0;
                    }
                }
                // No n worked, bad guess somewhere, return & backtrack.
                return;
            }
        }
    }
    // All values filled, found a puzzle solution, stop execution.
    run = false;
}

// Check wether a number can be put in position [row][col].
bool valid(int n, int row, int col)
{
    bool inrow = isin_row(n, row);
    bool incol = isin_col(n, col);
    bool insub = isin_sub(n, row, col);
    if(!inrow & !incol & !insub)
    {
        return true;
    }
    return false;
}

// Check wether number n is in row.
bool isin_row(int n, int row)
{
    for (int j = 0; j < SIZE; j++)
    {
        if (grid[row][j] == n)
        {
            return true;
        }
    }
    return false;
}

// Check wheter number is in column.
bool isin_col(int n, int col)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[i][col] == n)
        {
            return true;
        }
    }
    return false;
}

// Check wether number is in subgrid.
bool isin_sub(int n, int row, int col)
{
    int r0 = row / 3 * 3;
    int r1 = r0 + 3;
    int c0 = col / 3 * 3;
    int c1 = c0 + 3;
    for (int r = r0; r < r1; r++)
    {
        for (int c = c0; c < c1; c++)
        {
            if (grid[r][c] == n)
            {
                return true;
            }
        }
    }
    return false;
}

// Formatted representation of sudoku grid.
void print_grid(void)
{
    printf("\n");
    for (int row = 0; row < SIZE; row++)
    {
        if (row % 3 == 0 & row != 0)
        {
            printf(" ----- + ----- + -----\n");
        }
        for (int col = 0; col < SIZE; col++)
        {
            if (col % 3 == 0 & col != 0)
            {
                printf(" |");
            }
            printf(" %i", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the grid has any wrong number
bool check_grid(void)
{
    int n, tmp;
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            n = grid[row][col];
            if (n != 0)
            {
                // Make box = 0, otherwise its not compatible with itself.
                grid[row][col] = 0;
                if (!valid(n, row, col))
                {
                    fprintf(stderr, "Sudoku error at (%i, %i)\n", row, col);
                    return false;
                }
                grid[row][col] = n;
            }
        }
    }
    return true;
}
