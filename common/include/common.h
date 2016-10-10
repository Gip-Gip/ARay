/* common.h - contains common headers and functions

ENUMS:

TYPEDEFS:

DEFINITIONS:

FRACTNUM - the number an exponent has to be greater than to round up

MACROS:

R2N - converts a rational to a natural
N2R - converts a natural to a rational
RINT - removes the interger-part(the decimals left of the decimal point)
RR2N - rounds and converts rationals to naturals

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arrAcc.h>
#include <enums.h>

#define FRACTNUM 0.445
#define R2N(rat) ((natural) rat)
#define N2R(nat) ((rational) nat)
#define RINT(rat) (rat - R2N(rat))
#define RR2N(rat) (R2N(rat) + (RINT(rat) > FRACTNUM))

extern void print();
extern string strapp();
extern string strcut();
