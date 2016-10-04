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

#define SDL_REDOFF 2
#define SDL_GRNOFF 1
#define SDL_BLUOFF 0
#define SDL_PIXELSZ 3

#define PUTPIXEL(offset, r, g, b) (*(screenRaw + (offset * SDL_PIXELSZ) + SDL_REDOFF) = r, \
                                    *(screenRaw + (offset * SDL_PIXELSZ) + SDL_GRNOFF) = g, \
                                    *(screenRaw + (offset * SDL_PIXELSZ) + SDL_BLUOFF) = b)

#define REFRESH_SCREEN() SDL_Flip(screen);
