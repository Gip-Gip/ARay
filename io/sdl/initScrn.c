/* initScrn - initialized the screen(SDL)

ARGUMENTS:

VARIABLES:

SDL_Surface *screen - the surface used for holding the screen
rgbUnit *screenRaw - the pointer to the RGB interface for screen
natural screenWidth - the width of the screen
natural screenHeight - the height of the screen

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
