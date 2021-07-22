#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <ctype.h>

#include "solver.h"

#define SIZE 9
int grid[SIZE][SIZE];

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


int main(void)
{
    print_grid();
    save("testfile.sk");
}

