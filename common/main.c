/* main - handles command-line arguments and calls all the functions

ARGUMENTS:

int argc - the amount of arguments provided in argv
char *argv[] - the arguments provided from the commandline

VARIABLES:

string mapname - the name of the map being played
FILE *logFile - the logfile
bool overwrite - a flag that determines whether we overwrite files or not

*/

#include <main.h>

string mapname = NULL;
FILE *logFile = NULL;
bool overwrite = false;

extern rational r_getSlope(rational);

int main(int argc, char *argv[])
{
    natural argn = ZERO;
    gargv = argv;
    gargc = argc;

    while(++argn < argc)
    {
        switch(getArg(argv[argn]))
        {
            case(arg_help):
                help();
                return err_helpGiven;
                break;
            case(arg_overwrite):
                overwrite = true;
                break;
            case(arg_logFile):
                break;
            default:
                switch(getArg(argv[argn - 1]))
                {
                    case(arg_logFile):
                        if(!overwrite && (logFile = fopen(argv[argn], "rb")))
                        {
                            print(MSG_EXISTS);
                            return err_exists;
                        }

                        logFile = fopen(argv[argn], "wb");
                        break;
                    default:
                        mapname = argv[argn];
                        break;
                }
                break;
        }
    }

    if(!mapname)
    {
        print(MSG_NOMAP);
        return err_nomap;
    }

    if(!freopen(mapname, READMODE, stdin))
    {
        perror(MSG_PERROR);
        return errno;
    }

    if(getMap(stdin)) return err_unknown;

    initScrn();

    initAngl();

    drawScrn();

    SDL_Delay(5000);

    dintScrn();

    return 0;
}
