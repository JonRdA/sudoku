// Declares a sudoku's functionallity

#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <ctype.h>

// Initial grid SIZE constant
#define SIZE 9

int grid[SIZE][SIZE];       // Global sudoku grid.
bool run;                   // Running flag to stop recursive execution.

#endif
