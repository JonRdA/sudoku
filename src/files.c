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
        // Accept '.' as an empty value, 0.
        if (c == '.')
        {
            c = '0';
        }
        if (isdigit(c))
        {
            // Check if grid is completely loaded.
            if (count >= SIZE * SIZE)
            {
                fprintf(stderr, "Wrong input file: too many numbers.\n");
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
        fprintf(stderr, "Wrong input file: missing numbers.\n");
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
        fprintf(stderr, "Could not save to file '%s'.\n", fname);
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

// Read and load grid from user input.
bool input(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        bool inserted;
        do
        {
            char *text = ask_row(i);
            inserted = insert_row(i, text);
        }
        while (!inserted);
    }
    printf("\n");
    return true;
}

// Prompt user for row values and return string.
char *ask_row(int n)
{
    char *input_row = malloc(sizeof(char) * ROWSIZE);
    printf("Row %i: ", n + 1);
    fgets(input_row, ROWSIZE, stdin);
    return input_row;
}

// Extract digits from string and construct row array.
bool insert_row(int n, char * input_row)
{
    int ind = 0;        // Index to fill row
    char c;

    for (int i = 0; i < ROWSIZE; i++)
    {
        c = input_row[i];

        // Accept '.' as an empty value, 0.
        if (c == '.')
        {
            c = '0';
        }

        if (isdigit(c))
        {
            grid[n][ind] = c - '0';
            ind++;
        }

        if (ind > SIZE)
        {
            printf("Too many numbers\n");
            return false;
        }
    }

    // Input loaded but not enough numbers loaded.
    if (ind < SIZE)
    {
        printf("Missing numbers\n");
        return false;
    }

    free(input_row);
    return true;
}
