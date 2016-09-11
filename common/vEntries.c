/*

ARGUMENTS:

VARIABLES:

vEntry *vars[] - holds all the arguments

*/

#include <vEntries.h>

vEntry vars[] =
{
    {"screenWidth", vt_natural, false, &screenWidth},
    {"screenHeight", vt_natural, false, &screenHeight},
    {"map", vt_string, false, &mapName},
    {NULL, ZERO, false, NULL},
};
