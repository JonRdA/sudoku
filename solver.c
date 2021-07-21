// Implements helper functions to solve a sudoku

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
                    // If n is valid, put it and solve new grid
                    if (valid(n, row, col))
                    {
                        grid[row][col] = n;
                        solve();
                        
                        // Stop execution once a solution was found.
                        if (!run)
                        {
                            return;
                        }

                        // solve() returned, set box to 0 to backtrack
                        grid[row][col] = 0;
                    }
                }
                // No n worked, bad guess somewhere, return & backtrack
                return;
            }
        }
    }
    // All values filled, found a puzzle solution

    // TODO end of loop, one solution is here, what to do, get more, print?
    printf("Seems like I am done\n");
    print_grid();
    run = false;
    //return;
}

// Check wether a number can be put in position [row][col]
bool valid(int n, int row, int col)
{
    bool inrow = isin_row(n, row);
    bool incol = isin_col(n, col);
    bool insub = isin_sub(n, row, col);
    //printf("%i, %i, %i\n", inrow, incol, insub);
    if(inrow == false & incol == false & insub == false)
    {
        return true;
    }
    return false;
}

// Check wether number n is in row
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

// Check wheter number is in column
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

// Check wether number is in subgrid
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
           // printf("Checking element [%i, %i]\tvalue: %i\n", r, c, grid[r][c]);
            if (grid[r][c] == n)
            {
                //printf("Really? %i, %i, %i, %i\n", r, c, n, grid[r][c] );
                return true;
            }
        }
    }
    return false;
}

// Formatted representation of sudoku grid
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

