// Declares a solvers' functionallity

#ifndef FILES_H
#define FILES_H

#include "sudoku.h"

bool load(char *fname);
bool save(char *fname);
bool input(void);

char *ask_row(int n);
bool insert_row(int n, char * input_row);

#endif
