#include "sudoku.h"
#include "solver.h"
#include "files.h"


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Missing puzzle to solve.\nTry 'sudoku -h'\n");
        return 1;
    }
    max_sol = 1;
    loaded = false;

    // Options & argument selection
    char *options = ":f:o:imh";

    char * out_file = NULL;
    char * inp_file = NULL;

    int option;
    while ((option = getopt(argc, argv, options)) != -1)
    {
        switch (option)
        {
            case ':':
                fprintf(stderr, "No filename specified\n");
                return 1;

            case '?':
                fprintf(stderr, "Unrecognized option\n");
                return 1;

            case 'f':
                inp_file = optarg;
                break;

            case 'o':
                out_file = optarg;
                break;

            case 'i':
                printf("Enter sudoku\n\n");
                input();
                loaded = true;
                break;

            case 'h':
                // TODO Help printing function here
                printf("Help to be entered printing");
                return 2;
                break;
            case 'm':
                max_sol = 100;
        }
    }

    if (inp_file != NULL)
    {
        if (!load(inp_file))
        {
            return 3;
        }
        
        loaded = true;
    }
     
    // No grid loaded, exit program.
    if (!loaded)
    {
        fprintf(stderr, "No sudoku specified\n");
        return 4;
    }

    printf("Entered sudoku puzzle:\n");
    print_grid();

    if (!check_grid())
    {
        return 5;
    }
    
    printf("Solved sudoku puzzle:\n");
    solve();

    if (out_file != NULL)
    {
        save(out_file);
    }
    
}

