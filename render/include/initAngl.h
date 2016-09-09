/* initAngl.h - includes files needed by initAngl.c

ENUMS:

TYPEDEFS:

DEFINITIONS:

HMULT - the amount of times the height is multiplied(gives the illusion of
        looking up/down)

MACROS:

*/

#include <common.h>
#include <messages.h>
#include <angle.h>

#define HMULT 1

extern rational getSlope(rational);
extern natural screenWidth;
extern natural screenHeight;
