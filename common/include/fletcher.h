/* fletcher16.h - contains definitions and macros for fletcher16 calculation

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

FLETCHER16_INIT - initializes the fletcher16 variables

FLETCHER16_ADD - add to the checksum

FLETCHER16_GET - get the result of the checksum

*/

#include <common.h>

extern byte fletcherA;
extern byte fletcherB;

#define FLETCHER16_AVAL 1
#define FLETCHER16_BVAL 0
#define FLETCHER16_MOD 256
#define FLETCHER16_ASHIFT (fletcherA << 8)
#define FLETCHER16_BSHIFT fletcherB

#define FLETCHER16_INIT() \
    fletcherA = FLETCHER16_AVAL; fletcherB = FLETCHER16_BVAL

#define FLETCHER16_ADD(addition) \
    fletcherB += (fletcherA += addition); fletcherB %= FLETCHER16_MOD, \
    fletcherA %= FLETCHER16_MOD

#define FLETCHER16_GET() \
    (FLETCHER16_ASHIFT + FLETCHER16_BSHIFT)
