/* main - handles command-line arguments and calls all the functions

ARGUMENTS:

int argc - the amount of arguments provided in argv
char *argv[] - the arguments provided from the commandline

VARIABLES:

string mapName - the name of the map being loaded
string confName - the name of the config file
string gzReadMode - the read mode for gzip
string gzWriteMode - the write mode for gzip
FILE *logFile - the file pointer to the logfile
bool overwrite - the overwrite flag. If set, files will be overwritten
bool verbose - the verbose flag. If set, output will be verobse
natural argn - an index that is used to go through the arguments
string buildIn - the build script. Only used when building maps
string buildOut - the map being written to. Only used when building maps

*/

#include <main.h>
#include <time.h>

extern rational playerX;
extern rational playerY;
extern rational playerZ;
extern natural playerRot;

string mapName = NULL;
string confName = NULL;
string gzReadMode = READMODE;
string gzWriteMode = NULL;
FILE *logFile = NULL;
bool overwrite = false;
bool verbose = false;

int main(int argc, char *argv[])
{
    natural argn = ZERO, i=0;
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
    else print(MSG_GZFLAGS);

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

    /* Demos */

    if(!strcmp("maps/testmap3.iam", mapName))
    {
        while(i++ < 140)
        {
            playerY += 0.05;
            drawScrn();
        }

        while(i++ < 440)
        {
            playerX -= 0.05;
            drawScrn();
        }
    }

    else if(!strcmp("maps/testmap.iam", mapName))
    {
        while(i++ < 40)
        {
            playerY += 0.05;
            drawScrn();
        }

        while(i++ < 60)
        {
            playerX -= 0.05;
            drawScrn();
        }

        while(i++ < 100)
        {
            playerY -= 0.05;
            drawScrn();
        }

        while(i++ < 120)
        {
            playerZ += 0.05;
            drawScrn();
        }

        while(i++ < 160)
        {
            playerZ -= 0.05;
            drawScrn();
        }
    }

    else if(!strcmp("maps/testmap2.iam", mapName))
    {
        while(i++ < 40)
        {
            playerY += 0.05;
            drawScrn();
        }

        while(i++ < 80)
        {
            playerX -= 0.05;
            drawScrn();
        }
    }

    SDL_Delay(10000);

    dintScrn();

    return none;
}
