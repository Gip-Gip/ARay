/* graphics.h - defines things needed for graphics interaction(SDL)

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

*/

#include <SDL/SDL.h>
#include <grphTyps.h>

extern rgbUnit *screenRaw;
extern SDL_Surface *screen;

#define PIXELSZ 3
#define PUTPIXEL(offset, r, g, b) (*(screenRaw + (offset * PIXELSZ)) = r, \
                                    *(screenRaw + (offset * PIXELSZ) + 1) = g, \
                                    *(screenRaw + (offset * PIXELSZ) + 2) = b)

#define REFRESH_SCREEN() SDL_Flip(screen);
