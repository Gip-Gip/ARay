/* drawScrn - draws to the screen pointer

ARGUMENTS:

VARIABLES:

natural index - the index used to go through the screen and the angle arrays
rational rayX - the ray's x coordnate
rational rayY - the ray's y coordnate
rational rayZ - the ray's x coordnate
mapunit wall - the wall hit by the ray

*/

#include <drawScrn.h>

void drawScrn()
{
    natural index = INDEXINIT;
    rational rayX = playerX;
    rational rayY = playerY;
    rational rayZ = playerZ;
    mapunit wall = AIR;

    for(wall = AIR;++index < screenWidth * screenHeight;wall = AIR)
    {
        /* Since the texture coordnates increase up -> down, and the map
           coordnates increase down -> up, we have to invert the Z texture
           offset. To do that, we subtract the fractional from 1 (stored inside
           the macro ICONST for readablility) */

        while(wall == AIR)
        {
            if((wall = ARRAY_ACCESS3D(
                R2N((rayX += angleArray_X[index])),
                R2N(rayY),
                R2N(rayZ))) != AIR)
            {
                if(angleArray_X[index] < 0) getPixel(
                    xHitN,
                    RFRACT(rayY),
                    ICONST - RFRACT(rayZ),
                    index,
                    wall - TNUMCORR);

                else getPixel(
                    xHitP,
                    RFRACT(rayY),
                    ICONST - RFRACT(rayZ),
                    index,
                    wall - TNUMCORR);
            }

            else if((wall = ARRAY_ACCESS3D(
                R2N(rayX),
                R2N((rayY += angleArray_Y[index])),
                R2N(rayZ))) != AIR)
            {
                if(angleArray_Y[index] < 0) getPixel(
                    yHitN,
                    RFRACT(rayX),
                    ICONST - RFRACT(rayZ),
                    index,
                    wall - TNUMCORR);

                else getPixel(yHitP,
                    RFRACT(rayX),
                    ICONST - RFRACT(rayZ),
                    index,
                    wall - TNUMCORR);
            }

            else if((wall = ARRAY_ACCESS3D(
                R2N(rayX),
                R2N(rayY),
                R2N((rayZ += angleArray_Z[index])))) != AIR)
            {
                if(angleArray_Z[index] < 0) getPixel(
                        zHitN,
                        RFRACT(rayX),
                        RFRACT(rayY),
                        index,
                        wall - TNUMCORR);

                else getPixel(zHitP,
                    RFRACT(rayX),
                    RFRACT(rayY),
                    index,
                    wall - TNUMCORR);
            }
        }

        rayX = playerX;
        rayY = playerY;
        rayZ = playerZ;
    }

    REFRESH_SCREEN();
}
