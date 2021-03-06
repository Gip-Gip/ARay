/* numchar - returns true if the given character is a number character

ARGUMENTS:

character chr - the character being checked

VARIABLES:

*/

#include <numchar.h>

bool numchar(character chr)
{
    if(chr >= ZERO_CHR && chr <= NINE_CHR) return true;
    if(chr == NEGITIVE_CHR) return true;
    return false;
}
