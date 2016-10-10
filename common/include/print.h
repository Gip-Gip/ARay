/* print.h - includes files and defines things needed by print.c

ENUMS:

TYPEDEFS:

DEFINITIONS:

PRINT_STYLDELM - the style delemeter
PRINT_STYLSTR - the style code for a string
PRINT_STYLNATR - the style code for a natural number
PRINT_STYLPREV - the style code for the previous string
PRINT_STYLVERB - the style code for marking verbose-only strings
PRINT_STYLCHAR - the style code for a single character
PRINT_NCORR - the amount to compensate due to the inaccuracy of number-length
              detection algorithms

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
