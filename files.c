// Implements helper functions to operate with files.

#include "files.h"

// Load sudoku grind from file into global 'grid' array.
bool load(char *fname)
{
    // Open file and get pointer to it
    FILE *f = fopen(fname, "r");
    if (f == NULL)
    {
        printf("Could not load file '%s'\n", fname);
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
                printf("Invalid input, too many numbers provided.\n");
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
        printf("Invalid input, numbers missing.\n");
        return false;
    }

    return true;
    
}
