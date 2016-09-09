/* initScrn - initialized the screen(SDL)

ARGUMENTS:

VARIABLES:

*/

#include <initScrn.h>

SDL_Surface *screen = NULL;
rgbUnit *screenRaw = NULL;
natural screenWidth = 320;
natural screenHeight = 200;

int initScrn()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    screen = SDL_SetVideoMode(screenWidth, screenHeight, 24, SDL_SWSURFACE );
    screenRaw = screen->pixels;

    return none;
}
