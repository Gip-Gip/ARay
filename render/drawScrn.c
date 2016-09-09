/* drawScrn - draws to the screen pointer

ARGUMENTS:

VARIABLES:

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
            rayX += angleArray_X[index];
            if(AIR != (wall = ARRAY_ACCESS3D(
                R2N(rayX), R2N(rayY), R2N(rayZ))))
            {
                if(angleArray_X[index] > 0)
                    getTextr(xHitP, rayY, rayZ, index, wall);
                else getTextr(xHitN, rayY, rayZ, index, wall);
            }

            rayY += angleArray_Y[index];
            if(wall == AIR && AIR != (wall = ARRAY_ACCESS3D(
            R2N(rayX), R2N(rayY), R2N(rayZ))))
            {
                if(angleArray_Y[index] > 0)
                    getTextr(yHitP, rayX, rayZ, index, wall);
                else getTextr(yHitN, rayX, rayZ, index, wall);
            }

            rayZ += angleArray_Z[index];

            if(wall == AIR && AIR != (wall = ARRAY_ACCESS3D(
            R2N(rayX), R2N(rayY), R2N(rayZ))))
            {
                if(angleArray_Z[index] > 0)
                    getTextr(zHitP, rayX, rayY, index, wall);
                else getTextr(zHitN, rayX, rayY, index, wall);
            }
        }
    }

    REFRESH_SCREEN();
}
