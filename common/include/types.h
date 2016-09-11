/* types.h - contains the types used accross the project

ENUMS:

bool - possible boolean states
arg - command line arguments

TYPEDEFS:

natural - natural numbers
real - real numbers(signed)
rational - rational numbers(double)
byte - a single byte
string - a string of characters
character - a single character of a string
mapunit - a single map unit
bool - flag type
arg - command line argument
vEntry - config file variable entry

DEFINITIONS:

TYPES - used to tell if the header was included twice somehow

MACROS:

*/

#include <defs.h>

#ifndef TYPES
#define TYPES NULL
typedef unsigned long int natural;
typedef long int real;
typedef double rational;
typedef char byte;
typedef byte* string;
typedef byte character;
typedef byte mapunit;
typedef mapunit* map;
typedef enum {
    false,
    true,
    neither,
} bool;
typedef enum {
    arg_confFile,
    arg_help,
    arg_logFile,
    arg_overwrite,
    arg_map,
} arg;
typedef enum {
    xHitP,
    xHitN,
    yHitP,
    yHitN,
    zHitP,
    zHitN,
} hit;
typedef enum {
    vt_natural,
    vt_string,
} vType;
typedef struct
{
    string name;
    vType type;
    bool freeable;
    void *var;
} vEntry;
#endif
