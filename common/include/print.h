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
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <types.h>

extern FILE *logFile;
extern bool verbose;

#define LPUTC(chr) fputc(chr, stderr); if(logFile) fputc(chr, logFile);

#define PRINT_STYLDELM '%'
#define PRINT_STYLSTR 's'
#define PRINT_STYLNATR 'n'
#define PRINT_STYLPREV '<'
#define PRINT_STYLVERB 'v'
#define PRINT_STYLCHAR 'c'
#define PRINT_NCORR 2
