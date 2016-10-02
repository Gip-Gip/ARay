/* common.h - contains common headers and functions

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

R2N - converts a rational to a natural
RFRACT - removes the fractional-part of a rational

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arrAcc.h>
#include <enums.h>

#define FRACTNUM 0.445
#define R2N(rat) ((natural) rat)
#define RFRACT(rat) (rat - R2N(rat))
#define RR2N(rat) (R2N(rat) + (RFRACT(rat) > FRACTNUM))

extern void print();
extern string strapp();
extern string strcut();
