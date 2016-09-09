/* getTextr - gets the pixel of a texture and draws it to the screen

ARGUMENTS:

VARIABLES:

*/

#include <getTextr.h>

void getTextr(hit side, rational coord1, rational coord2, natural index, mapunit texture)
{
    if(texture == 1)
    {
        if(side == xHitP || side == yHitP || side == zHitN)
            PUTPIXEL(index, 255, 255, 255);
        else if(side == yHitN || xHitN) PUTPIXEL(index, 191, 191, 191);
        else PUTPIXEL(index, 127, 127, 127);
    }

    else
    {
        if(side == xHitP || side == yHitP || side == zHitN)
            PUTPIXEL(index, 255, 0, 0);
        else if(side == yHitN || xHitN) PUTPIXEL(index, 191, 0, 0);
        else PUTPIXEL(index, 127, 0, 0);
    }
}
