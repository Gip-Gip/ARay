/* drawScrn.h - includes files and defines things needed by drawScrn.h

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

*/

#include <common.h>
#include <arrAcc.h>
#include <graphics.h>

#define AIR 0

extern rational playerX;
extern rational playerY;
extern rational playerZ;

extern void getTextr(hit, rational, rational, natural, natural);
extern rational *angleArray_X;
extern rational *angleArray_Y;
extern rational *angleArray_Z;
extern natural screenWidth;
extern natural screenHeight;
