#include "sudoku.h"
#include "solver.h"
#include "files.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Missing puzzle to solve.\nTry 'sudoku --help'\n");
        return 1;
    }
    run = true;

    // Options & argument selection
    char *options = ":f:o:i";

    char * out_file = NULL;
    char * inp_file = NULL;

    int option;
    while ((option = getopt(argc, argv, options)) != -1)
    {
        switch (option)
        {
            case 'f':
                inp_file = optarg;
                if (!load(inp_file))
                {
                    return 2;
                }
                break;

            case 'o':
                out_file = optarg;
                break;

            case 'i':
                printf("Enter sudoku\n");
                printf("digits: [0-9] empty: ['0','.']\n\n");
                input();
                break;

            case 'h':
                // TODO Help printing function here
                printf("Help to be entered printing");
                break;
        }
    }
    check_grid();
    print_grid();
    solve();
    print_grid();

    if (out_file != NULL)
    {
        save(out_file);
    }
    
}

