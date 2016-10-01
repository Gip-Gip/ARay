/*

ARGUMENTS:

VARIABLES:

char *args[] - holds all the arguments

*/

#include <types.h>

string args[] =
{
    "-c", "--config", "set the config file",
    "-h", "--help", "displays this message and exits",
    "-l", "--log", "the logfile",
    "-Bi", "--build-script", "the build script, if building",
    "-Bo", "--build-product", "the file that will be written to, if building",
    "-v", "--verbose", "print extra debugging messages",
    "-y", "--overwrite", "overwrites files without complaining",
    NULL,
};
