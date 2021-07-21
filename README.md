# SUDOKU
Sudoku solver in C using the backtracking algorithm.

Accepts input on the command line row by row or alternatively a file where
the grid is written.

## TODO
* Read from file:
  * Not working on functions. Needs to be an array of pointers.
  * Load per line. each line completes an array and a pointer.
  * What happens with all solving functions, need a 2d array.
  * convert dynamic memory array to 2d array? Why does not it work?
  * Get filename, open, read l

* Split into diferent files, solving & helpers? Don't like it...
* I/O of arguments
  * Option `-f` reading from file `-o` output file & `-i` manual input
  * File reading writting
  * User input, can rows be printed after input, already formatted?

## DOUBTS
* Use flag for options, or call functions from getopt switch?
