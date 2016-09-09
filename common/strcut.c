/* strcut - cut a string from the source

ARGUMENTS:

string source - the string being cut from
natural amount -the amount of the string to cut out
bool freeSource - whether to free the source or not

VARIABLES:

string out - the string being returned

*/

#include <strcut.h>

string strcut(string source, natural amount, bool freeSource)
{
    string out = calloc(amount + STRALLOC, UNIT_STR);

    memcpy(out, source, amount);

    if(freeSource) free(source);

    return out;
}
