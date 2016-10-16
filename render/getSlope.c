/* r_getSlope - gets the slope of an angle

ARGUMENTS:

rational angle - the angle

VARIABLES:

*/

#include <getSlope.h>

rational getSlope(rational angle)
{
    if(angle < 1) return angle;
    if(angle >= 1 && angle <= 2) return 1.0 - RINT(angle);
    if(angle > 2 && angle <= 3) return 0 - RINT(angle);
    if(angle > 3) return -1 + RINT(angle);
    return 0;
}
