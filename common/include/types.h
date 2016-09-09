/* types.h - contains the types used accross the project

ENUMS:

bool - possible boolean states
arg - command line arguments

TYPEDEFS:

natural - natural numbers
real - real numbers(signed)
rational - rational numbers(double)
byte - a single byte
mapunit - a single map unit
bool - flag type
arg - command line argument

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
typedef byte mapunit;
typedef mapunit* map;
typedef enum {
    false,
    true,
    neither,
} bool;
typedef enum {
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
#endif
