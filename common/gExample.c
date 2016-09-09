/* gExample - generates an usage example before the arg provided

ARGUMENTS:

string exampleArg - the example argument
natural before - the argument to place the example argument before

VARIABLES:

natural argn - an index used to go through an array

*/

#include <gExample.h>

string gExample(string exampleArg, natural before)
{
    natural argn = INDEXINIT;
    string base = calloc(STRALLOC, UNIT_STR);

    for(;++argn < before;base = strapp(base, SPACE, true, false))
        base = strapp(base, gargv[argn], true, false);

    base = strapp(base, exampleArg, true, false);
    base = strapp(base, SPACE, true, false);

    for(--argn; ++argn < gargc; base = strapp(base, SPACE, true, false))
        base = strapp(base, gargv[argn], true, false);

    /* A space is left at the end of the string. Get rid of it. */
    base = strcut(base, strlen(base) - SPACESZ, true);

    return base;
}
