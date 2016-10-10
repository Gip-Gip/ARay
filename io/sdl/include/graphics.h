/* graphics.h - defines things needed for graphics interaction(SDL)

ENUMS:

TYPEDEFS:

DEFINITIONS:

SDL_REDOFF - the offset in a pixel where the red intensity is stored
SDL_GRNOFF - the offset in a pixel where the green intensity is stored
SDL_BLUOFF - the offset in a pixel where the blue intensity is stored
SDL_PIXELSZ - the size of each pixel(in bytes)

MACROS:

PUTPIXEL - puts a pixel at the screen offset specified
REFRESH_SCREEN - refreshes the screen

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
