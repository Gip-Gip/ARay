/* initAngl - initializes the angle array

ARGUMENTS:

VARIABLES:

*/


#include <initAngl.h>

rational *angleArray_X = NULL;
rational *angleArray_Y = NULL;
rational *angleArray_Z = NULL;

int initAngl()
{
    natural index = INDEXINIT;
    natural arrSize = screenWidth * (screenHeight * HMULT);
    rational hInc = ANGLEMAX / screenWidth;
    rational vInc = ANGLEMAX / screenHeight * 0;
    rational angleX = ANGLEX_INIT - hInc;
    rational angleY = ANGLEY_INIT - hInc;
    rational angleZ = ANGLEZ_INIT;

    if(!(angleArray_X = calloc(arrSize, sizeof(rational))) |
        !(angleArray_Y = calloc(arrSize, sizeof(rational))) |
        !(angleArray_Z = calloc(arrSize, sizeof(rational))))
    {
        perror(MSG_PERROR);
        return errno;
    }

    while(++index < arrSize)
    {
        if((angleX += hInc) >= ANGLEMAX) angleX = 0, angleZ += vInc;
        if((angleY += hInc) >= ANGLEMAX) angleY = 0;

        angleArray_X[index] = getSlope(angleX);
        angleArray_Y[index] = getSlope(angleY);
        angleArray_Z[index] = getSlope(angleZ);
    }

    return none;
}
