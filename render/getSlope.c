/* r_getSlope - gets the slope of an angle

ARGUMENTS:

rational angle - the angle

VARIABLES:

*/

#include <getSlope.h>

rational getSlope(rational angle)
{
    if(angle < 1) return angle;
    if(angle >= 1 && angle <= 3) return 1;
    if(angle > 3 && angle <= 4) return 1.0 - RFRACT(angle);
    if(angle > 4 && angle < 5) return 0 - RFRACT(angle);
    if(angle >= 5 && angle <= 7) return -1;
    if(angle > 7) return -1 + RFRACT(angle);

    return 0;
}
