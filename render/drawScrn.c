/* drawScrn - draws to the screen pointer

ARGUMENTS:

VARIABLES:

natural index - the index used to go through the screen and the angle arrays
rational rayX - the ray's x coordnate
rational rayY - the ray's y coordnate
rational rayZ - the ray's x coordnate
rational *U - the texture's X offset
rational *V - the texture's Y offset
hit side - the side the ray hit
mapunit wall - the wall hit by the ray

*/

#include <drawScrn.h>


void drawScrn()
{
    natural index = INDEXINIT;
    natural cutoff;
    rational divisor, maxDivisor, minDivisor;
    rational rayX;
    rational rayY;
    rational rayZ;
    rational *U = &rayX;
    rational *V = &rayY;
    hit side = xHitP;
    mapunit wall = AIR;

    maxDivisor = (screenWidth > screenHeight ? screenWidth : screenHeight);
    minDivisor = maxDivisor / 100;

    for(wall = AIR;++index < screenWidth * screenHeight;wall = AIR)
    {
        divisor = minDivisor / 10;
        cutoff = 0;
        rayX = playerX + angleArray_X[index] / divisor, rayY = playerY + angleArray_Y[index] / divisor, rayZ = playerZ + angleArray_Z[index] / divisor;

        /* Since the texture coordnates increase up -> down, and the map
           coordnates increase down -> up, we have to invert the Z texture
           offset. To do that, we subtract the fractional from 1 (stored inside
           the macro ICONST for readablility) */

        while(divisor <= maxDivisor)
        {
            wall = AIR;
            rayZ -= angleArray_Z[index] / divisor;
            rayX -= angleArray_X[index] / divisor;
            rayY -= angleArray_Y[index] / divisor;
            divisor *= 10;

            while(wall == AIR)
            {
                rayZ += angleArray_Z[index] / divisor;

                if((wall = ARRAY_ACCESS3D(
                        R2N(rayX),
                        R2N(rayY),
                        R2N(rayZ))) != AIR)
                {
                    if(angleArray_Z[index] < 0) side = zHitN;
                    else side = zHitP;

                    U = &rayX;
                    V = &rayY;
                }

                /* Increase the ray's X and check for collision */
                rayX += angleArray_X[index] / divisor;

                if(wall == AIR &&
                    (wall = ARRAY_ACCESS3D(
                        R2N(rayX),
                        R2N(rayY),
                        R2N(rayZ))) != AIR)
                {
                    if(angleArray_X[index] < 0) side = xHitN;
                    else side = xHitP;

                    U = &rayY;
                    V = &rayZ;
                }

                /* Increase the ray's Y */
                rayY += angleArray_Y[index] / divisor;

                if(wall == AIR &&
                    (wall = ARRAY_ACCESS3D(
                        R2N(rayX),
                        R2N(rayY),
                        R2N(rayZ))) != AIR)
                {

                    if(angleArray_Y[index] < 0) side = yHitN;
                    else side = yHitP;

                    U = &rayX;
                    V = &rayZ;
                }
            }
        }

        getPixel(side, RINT(*U), ICONST - RINT(*V), index, wall - TNUMCORR);
    }

    REFRESH_SCREEN();
}
