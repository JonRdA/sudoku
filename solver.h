// Declares a solvers' functionallity

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

// Initial grid SIZE constant
#define SIZE 9

// Function prototypes
void solve(int grid[][SIZE]);
bool valid(int grid[][SIZE], int n, int row, int col);
bool isin_row(int grid[][SIZE], int n, int row);
bool isin_col(int grid[][SIZE], int n, int col);
bool isin_sub(int grid[][SIZE], int n, int row, int col);
void print_grid(int grid[][SIZE]);

