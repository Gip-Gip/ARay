/* getConfg.h - includes files and defines things needed by getConfg.c

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

*/

#include <common.h>
#include <ctype.h>
#include <messages.h>

extern void *getVar();

#define EQUDELEM '='
#define COMMENT '#'
#define STRSTART '"'
#define STREND '"'
#define ESCDELM '\\'
#define NLDELEM 'n'
