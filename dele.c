#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <ctype.h>

#include "solver.h"

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


int *load(void)
{
    char *inp_file = "input.sdk";

    // Open file and get pointer to it
    FILE *f = fopen(inp_file, "r");
    if (f == NULL)
    {
        printf("Could not load file '%s'\n", inp_file);
        //return 1;
    }

    //int arr[SIZE][SIZE];
    int arr[SIZE][SIZE];

    int i = 0, j = 0, count = 0;
    for (int c = fgetc(f); c != EOF; c = fgetc(f))
    {
        if (isdigit(c))
        {
            arr[i][j] = c - '0'; 
            j++;
            count++;

            // Row is complete, jump to next.
            if (j == 9)
            {
                i++;
                j = 0;
            }

            // Check if array is full
            if (count > SIZE * SIZE)
            {
                printf("Invalid input, too many numbers provided\n");
                //return 1;
            }
        }
    }
    if (count < 81)
    {
        printf("Invalid input, too few numbers provided\n");
        //return 1;
    }
    print_grid(arr);
    return &arr;
    
}
int main(void)
{
    load();
}

