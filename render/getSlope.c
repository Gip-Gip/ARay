/* r_getSlope - gets the slope of an angle

ARGUMENTS:

rational angle - the angle

VARIABLES:

*/

#include <getSlope.h>

rational getSlope(rational angle)
{
    if(angle < 1) return angle;
    if(angle >= 1 && angle <= 3) return 2.0 - angle;
    if(angle > 3) return -4.0 + angle;
    return 0;
}
