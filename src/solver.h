// Declares a solvers' functionallity

#ifndef SOLVER_H
#define SOLVER_H

#include "sudoku.h"

// Function prototypes
void solve(void);
bool valid(int n, int row, int col);
bool isin_row(int n, int row);
bool isin_col(int n, int col);
bool isin_sub(int n, int row, int col);
bool check_grid(void);
void print_grid(void);

#endif
