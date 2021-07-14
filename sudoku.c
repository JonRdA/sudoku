#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

#include "solver.h"

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

    int grid[9][9] = {
    {4, 0, 0, 0, 0, 5, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 9, 8},
    {3, 0, 0, 0, 8, 2, 4, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 8, 0},
    {9, 0, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0, 6, 7, 0},
    {0, 5, 0, 0, 0, 9, 0, 0, 0},
    {0, 0, 0, 2, 0, 0, 9, 0, 7},
    {6, 4, 0, 3, 0, 0, 0, 0, 0},
    };
    
    solve(grid);
}

