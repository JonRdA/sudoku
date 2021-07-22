#include "sudoku.h"
#include "solver.h"
#include "files.h"

int main(int argc, char *argv[])
{
    run = true;

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
                load(inp_file);
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
    print_grid();
    solve();
    print_grid();

    if (out_file != NULL)
    {
        save(out_file);
    }
    
}

