/*

ARGUMENTS:

VARIABLES:

char *args[] - holds all the arguments

*/

#include <types.h>

string args[] =
{
    "-c", "--config", "sets the config file",
    "-h", "--help", "displays this message and exits",
    "-l", "--log", "sets the logfile",
    "-L", "--license", "displays the license and exits",
    "-Bi", "--build-script", "sets the build script, if building",
    "-Bo", "--build-product", "sets the file that will be written to, if building",
    "-v", "--verbose", "print extra debugging messages",
    "-y", "--overwrite", "overwrites files without complaining",
    NULL,
};
