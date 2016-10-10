/* getArg - checks the string to see if it's an argument

ARGUMENTS:

string str - the string being compared

VARIABLES:

int index - used for going through the argument array

*/

#include <getArg.h>

arg getArg(string str)
{
    natural index = ZERO;

    while(args[index])
    {
        if(!strcmp(args[index + ARGS_SHRTDPTH], str) |
           !strcmp(args[index + ARGS_LONGDPTH], str))
           return index / ARGS_ENTRYDPTH;

        index += ARGS_ENTRYDPTH;
    }

    return index;
}
