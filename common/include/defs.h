/* defs.h - contains definitions use across the project

ENUMS:

TYPEDEFS:

DEFINITIONS:

NULL - macro representation of 0
DEFS - used to tell if everything has been defined before
ZERO - macro representation of 0
INDEXINIT - the value to initialize indexes to
STRALLOC - the minimum size of a string
UNIT_STR - size of a single character in a string
SPACE - the space character in string form
SPACESZ - the size of a single space character

MACROS:

*/

#ifndef DEFS
#ifndef NULL
#define NULL 0
#endif
#define DEFS NULL
#define ZERO 0
#define INDEXINIT -1
#define STRALLOC 1
#define UNIT_STR sizeof(char)
#define SPACE " "
#define SPACESZ UNIT_STR
#endif
