/* PPM.h - contains specs for PPMs

ENUMS:

TYPEDEFS:

DEFINITIONS:

PPM_MN1 - part 1 of the PPM magic number
PPM_MN2 - part 2 of the PPM magic number
PPM_MM - the max value of any RGB value
PPM_PXSZ - the size of each pixel
PPM_WSSEEK - the amount to seek after the header(what counts as a single
             whitespace character)

MACROS:

*/

#include <common.h>

#define PPM_MN1 'P'
#define PPM_MN2 '6'
#define PPM_MM 255.0
#define PPM_PXSZ 3
#define PPM_WSSEEK sizeof(character)
