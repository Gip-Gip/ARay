/* print.h - includes files and defines things needed by print.c

ENUMS:

TYPEDEFS:

DEFINITIONS:

PRINT_STYLEDELM - the style delemeter
PRINT_STYLESTR - the style code for a string
PRINT_STYLESTR - the style code for the previous string

MACROS:

LPUTC - prints a character to both the log file and stderror

*/

#include <stdio.h>
#include <stdarg.h>

extern FILE *logFile;

#define LPUTC(chr) fputc(chr, stderr); if(logFile) fputc(chr, logFile);

#define PRINT_STYLDELM '%'
#define PRINT_STYLSTR 's'
#define PRINT_STYLPREV '<'
