/* print - project-wide logging function

ARGUMENTS:

char *format - the format of the message being printed

VARIABLES:

va_list arglist - the variable-argument list
string history - the previous print
bool freeHistory - if set, history will be freed
natural num - used for natural conversions

*/

#include <print.h>

void print(char *format, ...)
{
    va_list arglist;
    string history;
    bool freeHistory = false;
    natural num = 1;

    va_start(arglist, format);

    while(*format)
    {
        if(*format == PRINT_STYLDELM) switch(*(++format))
        {
            case(PRINT_STYLSTR):
                if(freeHistory)
                {
                    freeHistory = false;
                    free(history);
                }

                print(history = va_arg(arglist, string));
                break;
            case(PRINT_STYLNATR):
                if(freeHistory) free(history);

                num = va_arg(arglist, natural);
                history =
                    calloc((num?floor(log10(num)):STRALLOC) + STRALLOC,
                    sizeof(character));
                sprintf(history, F_NATURAL, num);
                print(history);

                freeHistory = true;
                break;
            case(PRINT_STYLPREV):
                print(history);
                break;
        }
        else LPUTC(*format);

        format ++;
    }
}

