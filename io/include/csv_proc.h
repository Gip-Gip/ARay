/* csv_proc.h - includes files  and defines things needed by csv_proc.c

ENUMS:

TYPEDEFS:

DEFINITIONS:

CSV_ADDVAL - In IAM air is represented as the value 0, while in csv it is
             represented as -1. To fix this, CSV_ADDVAL is added to each input
             number so it is IAM valid

MACROS:

*/

#include <fileIO.h>

extern bool fgetnum();

#define CSV_ADDVAL 1
