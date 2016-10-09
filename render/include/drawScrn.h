/* drawScrn.h - includes files and defines things needed by drawScrn.h

ENUMS:

TYPEDEFS:

DEFINITIONS:

AIR - the wall that symbolizes air
ICONST - the constant used to correct the Z texture offset
TNUMCORR - the value used when correcting the texture number

MACROS:

*/

#include <common.h>
#include <arrAcc.h>
#include <graphics.h>

#define AIR 0
#define ICONST 1
#define TNUMCORR 1

extern rational playerX;
extern rational playerY;
extern rational playerZ;

extern void getPixel(hit, rational, rational, natural, mapunit);
extern rational *angleArray_X;
extern rational *angleArray_Y;
extern rational *angleArray_Z;
extern natural screenWidth;
extern natural screenHeight;
