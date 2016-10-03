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

    for(wall = 0;++index < screenWidth * screenHeight;wall = 0)
    {
        while(wall == AIR)
        {
            if(
                (wall = ARRAY_ACCESS3D(
                    R2N((rayX += angleArray_X[index])),
                    R2N(rayY),
                    R2N(rayZ))) != AIR)
            {
                if(angleArray_X[index] < 0)
                    getPixel(
                        xHitN,
                        1.0 - RFRACT(rayY),
                        1.0 - RFRACT(rayZ),
                        index,
                        wall);

                else getPixel(xHitP, RFRACT(rayY), RFRACT(rayZ), index, wall);
            }

            else if(
                (wall = ARRAY_ACCESS3D(
                    R2N(rayX),
                    R2N((rayY += angleArray_Y[index])),
                    R2N(rayZ))) != AIR)
            {
                if(angleArray_Y[index] < 0)
                    getPixel(
                        yHitN,
                        1.0 - RFRACT(rayX),
                        1.0 - RFRACT(rayZ),
                        index,
                        wall);

                else getPixel(yHitP, RFRACT(rayX), RFRACT(rayZ), index, wall);
            }

            else if(
                (wall = ARRAY_ACCESS3D(
                    R2N(rayX),
                    R2N(rayY),
                    R2N((rayZ += angleArray_Z[index])))) != AIR)
            {
                if(angleArray_Z[index] < 0)
                    getPixel(
                        zHitN,
                        1.0 - RFRACT(rayX),
                        1.0 - RFRACT(rayY),
                        index,
                        wall);

                else getPixel(zHitP, RFRACT(rayX), RFRACT(rayY), index, wall);
            }
        }

        rayX = playerX;
        rayY = playerY;
        rayZ = playerZ;
    }

    REFRESH_SCREEN();
}
