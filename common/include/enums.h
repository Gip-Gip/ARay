/* enums.h - contains enums used across the project

ENUMS:

retvals - possible values to return to the console

TYPEDEFS:

DEFINITIONS:

ENUMS - used to tell if the enums have been defined before

MACROS:

*/

#include <types.h>

#ifndef ENUMS
#define ENUMS NULL
enum retvals {
    none,
    err_unknown,
    err_helpGiven,
    err_licenseGiven,
    err_nomap,
    err_badMode,
    err_badPPM,
    err_badTexCnt,
    err_eof,
    err_exists,
};
#endif
