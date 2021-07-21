// Declares a solvers' functionallity

#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Initial grid SIZE constant
#define SIZE 9
int grid[SIZE][SIZE];

// Function prototypes
void solve(void);
bool valid(int n, int row, int col);
bool isin_row(int n, int row);
bool isin_col(int n, int col);
bool isin_sub(int n, int row, int col);
void print_grid(void);

#endif
