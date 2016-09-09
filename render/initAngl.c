/* initAngl - initializes the angle array

ARGUMENTS:

VARIABLES:

rational *angleArray_X = the X angle array
rational *angleArray_Y - the Y angle array
rational *angleArray_Z - the Z angle array

natural index - the index that goes through the angle arrays
natural multipliedHeight - the screen height * HMULT
natural arrSize - the size of each angle array
rational hInc - the horizontal increment
rational vInc - the vertical increment
rational angleX - the X angle
rational angleY  - the Y angle
rational slopeZ - the Z slope

*/


#include <initAngl.h>

rational *angleArray_X = NULL;
rational *angleArray_Y = NULL;
rational *angleArray_Z = NULL;

int initAngl()
{
    natural index = INDEXINIT;
    natural multipliedHeight = screenHeight * HMULT;
    natural arrSize = screenWidth * multipliedHeight;
    rational hInc = ANGLEMAX / screenWidth;
    rational vInc = -(VRANGE / multipliedHeight);
    rational angleX = ANGLEX_INIT - hInc;
    rational angleY = ANGLEY_INIT - hInc;
    rational slopeZ = SLOPEZ_INIT;

    if(!(angleArray_X = calloc(arrSize, sizeof(rational))) |
        !(angleArray_Y = calloc(arrSize, sizeof(rational))) |
        !(angleArray_Z = calloc(arrSize, sizeof(rational))))
    {
        perror(MSG_PERROR);
        return errno;
    }

    while(++index < arrSize)
    {
        if((angleX += hInc) >= ANGLEMAX) angleX = ZERO, slopeZ += vInc;
        if((angleY += hInc) >= ANGLEMAX) angleY = ZERO;

        angleArray_X[index] = getSlope(angleX);
        angleArray_Y[index] = getSlope(angleY);
        angleArray_Z[index] = slopeZ;
    }

    return none;
}
