/* main - handles command-line arguments and calls all the functions

ARGUMENTS:

int argc - the amount of arguments provided in argv
char *argv[] - the arguments provided from the commandline

VARIABLES:

string mapName - the name of the map being played
FILE *logFile - the logfile
bool overwrite - a flag that determines whether we overwrite files or not

*/

#include <main.h>
#include <time.h>

string mapName = NULL;
string confName = NULL;
string gzReadMode = READMODE;
string gzWriteMode = NULL;
FILE *logFile = NULL;
bool overwrite = false;
bool verbose = false;

extern rational r_getSlope(rational);

int main(int argc, char *argv[])
{
    natural argn = ZERO;
    string buildIn = NULL, buildOut = NULL;
    clock_t t;
    gargv = argv;
    gargc = argc;

    print(MSG_SPLASH);

    while(++argn < argc)
    {
        switch(getArg(argv[argn]))
        {
            case(arg_help):
                help();
                return err_helpGiven;
                break;

            case(arg_license):
                print(MSG_LICENSE);
                return err_licenseGiven;
                break;

            case(arg_overwrite):
                overwrite = true;
                break;

            case(arg_verbose):
                verbose = true;
                break;

            case(arg_logFile): case(arg_confFile): case(arg_buildIn):
            case(arg_buildOut): case(arg_gzWriteFlags):
                break;

            default:
                switch(getArg(argv[argn - 1]))
                {
                    case(arg_logFile):
                        if(!overwrite && (logFile = fopen(argv[argn], "rb")))
                        {
                            print(MSG_EXISTS_1);
                            return err_exists;
                        }

                        logFile = fopen(argv[argn], "wb");
                        break;

                    case(arg_confFile):
                        confName = argv[argn];
                        break;

                    case(arg_buildIn):
                        buildIn = argv[argn];
                        break;

                    case(arg_buildOut):
                        buildOut = argv[argn];
                        break;

                    case(arg_gzWriteFlags):
                        if(gzWriteMode) free(gzWriteMode);

                        gzWriteMode = strapp(
                            WRITEMODE, argv[argn], false, false);

                        break;

                    default:
                        mapName = argv[argn];
                        break;
                }
                break;
        }
    }

    if(!gzWriteMode) gzWriteMode = WRITEMODE;
<<<<<<< HEAD
    else print(MSG_GZFLAGS);
=======
>>>>>>> d166d0282dddb62f0488955eadffa57e6122efb4

    if(buildIn && buildOut) return c2i_proc(buildIn, buildOut);

    if(confName && !freopen(confName, READMODE, stdin))
    {
        perror(MSG_PERROR);
        return errno;
    }

    if(confName && getConfg(stdin)) return err_unknown;

    if(!mapName)
    {
        print(MSG_NOMAP);
        return err_nomap;
    }

    if(getMap(mapName)) return err_unknown;

    initScrn();

    initAngl();

    t = clock();

    drawScrn();

    t = clock() - t;

    printf("It took %f MS!", (((double)t)/CLOCKS_PER_SEC) * 1000);

    SDL_Delay(10000);

    dintScrn();

    return 0;
}
