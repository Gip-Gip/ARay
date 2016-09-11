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
    mapunit wall = 0;

    for(;++index < screenWidth * screenHeight;
        rayX = playerX, rayY = playerY, rayZ = playerZ)
    {
        for(;ARRAY_ACCESS3D(
            R2N(rayX), R2N(rayY), R2N(rayZ)) == AIR; wall = AIR)
        {
            if(AIR != (wall = ARRAY_ACCESS3D(
                R2N((rayX += angleArray_X[index])), R2N(rayY), R2N(rayZ))))
            {
                if(angleArray_X[index] > 0)
                    getTextr(xHitP, rayY, rayZ, index, wall);
                else getTextr(xHitN, rayY, rayZ, index, wall);
            }

            else if(AIR != (wall = ARRAY_ACCESS3D(
                R2N(rayX), R2N((rayY += angleArray_Y[index])), R2N(rayZ))))
            {
                if(angleArray_Y[index] > 0)
                    getTextr(yHitP, rayX, rayZ, index, wall);
                else getTextr(yHitN, rayX, rayZ, index, wall);
            }

            else if(AIR != (wall = ARRAY_ACCESS3D(
                R2N(rayX), R2N(rayY), R2N((rayZ += angleArray_Z[index])))))
            {
                if(angleArray_Z[index] > 0)
                    getTextr(zHitP, rayX, rayY, index, wall);
                else getTextr(zHitN, rayX, rayY, index, wall);
            }
        }
    }

    REFRESH_SCREEN();
}
