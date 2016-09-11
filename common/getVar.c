/* getVar - checks the string to see if it's a variable, and returns a pointer
            to the variable if it is

ARGUMENTS:

char *var - the var to look for

VARIABLES:

int index - used for going through the argument array

*/

#include <getVar.h>

void *getVar(char *var, vType *varType, bool **freeable)
{
    natural index = ZERO;

    while(vars[index].name)
    {
        if(!strcmp(vars[index].name, var))
        {
            *varType = vars[index].type;
            *freeable = &(vars[index].freeable);
            return vars[index].var;
        }

        index += VARS_ENTRYDPTH;
    }

    return NULL;
}
