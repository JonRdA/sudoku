#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>

// Initial grid SIZE constant
#define SIZE 9

// Function declarations
void print_grid(int grid[][SIZE]);
bool isin_row(int grid[][SIZE], int n, int row);
bool isin_col(int grid[][SIZE], int n, int col);
bool valid(int grid[][SIZE], int n, int row, int col);
bool isin_sub(int grid[][SIZE], int n, int row, int col);


int main(int argc, char *argv[])
{
    // Options & argument selection
    char *options = ":f:o:i";

    char * out_file = NULL;
    char * inp_file = NULL;

    int option;
    while ((option = getopt(argc, argv, options)) != -1)
    {
        printf("Option: %c\n", option);
        switch (option)
        {
            case 'f':
                inp_file = optarg;
                printf("Input file: %s\n", inp_file);
                break;
            case 'o':
                out_file = optarg;
                printf("Output file: %s\n", out_file);
                break;
            case 'i':
                printf("Sudoku to be entered manually");
                break;
        }
    }

}

/// Check wether a number can be put in position [row][col]
bool valid(int grid[][SIZE], int n, int row, int col)
{
    bool inrow = isin_row(grid, n, row);
    bool incol = isin_col(grid, n, col);
    bool insub = isin_sub(grid, n, row, col);
    if(inrow == false & incol == false & insub == false)
    {
        return true;
    }
    return false;
}

// Check wether number n is in row
bool isin_row(int grid[][SIZE], int n, int row)
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
bool isin_col(int grid[][SIZE], int n, int col)
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
bool isin_sub(int grid[][SIZE], int n, int row, int col)
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



// Formatted representation of sudoku grid
void print_grid(int grid[][SIZE])
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

