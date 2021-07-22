// Implements helper functions to operate with files.

#include "files.h"

// Load sudoku grind from file into global 'grid' array.
bool load(char *fname)
{
    // Open file and get pointer to it
    FILE *f = fopen(fname, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Could not load file '%s'\n", fname);
        return false;
    }

    int i = 0, j = 0, count = 0;
    for (int c = fgetc(f); c != EOF; c = fgetc(f))
    {
        if (isdigit(c))
        {
            // Check if grid is completely loaded.
            if (count >= SIZE * SIZE)
            {
                fprintf(stderr, "Invalid input, too many numbers.\n");
                return false;
            }
            // Row is complete, jump to next.
            else if (j == 9)
            {
                i++;
                j = 0;
            }

            // Insert value in its position.
            grid[i][j] = c - '0'; 
            j++;
            count++;
        }
    }

    // Loading finished, check if enough numbers where loaded.
    if (count < SIZE * SIZE)
    {
        fprintf(stderr, "Invalid input, numbers missing.\n");
        return false;
    }

    fclose(f);
    return true;
}

// Save sudoku grid into file
bool save(char *fname)
{
    FILE *f = fopen(fname, "w");
    if (f == NULL)
    {
        fprintf(stderr, "Could not save to file\n");
        return false;
    }

    fprintf(f, "\n");
    for (int row = 0; row < SIZE; row++)
    {
        if (row % 3 == 0 & row != 0)
        {
            fprintf(f, " ----- + ----- + -----\n");
        }
        for (int col = 0; col < SIZE; col++)
        {
            if (col % 3 == 0 & col != 0)
            {
                fprintf(f, " |");
            }
            fprintf(f, " %i", grid[row][col]);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "\n");

    fclose(f);
    return true;
}
