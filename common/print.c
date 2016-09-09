/* print - project-wide logging function

ARGUMENTS:

char *format - the format of the message being printed

VARIABLES:

va_list arglist - the variable-argument list

*/

#include <print.h>

void print(char *format, ...)
{
    va_list arglist;
    char *history;

    va_start(arglist, format);

    while(*format)
    {
        if(*format == PRINT_STYLDELM) switch(*(++format))
        {
            case(PRINT_STYLSTR):
                print(history = va_arg(arglist, char *));
                break;

            case(PRINT_STYLPREV):
                print(history);
                break;
        }
        else LPUTC(*format);

        format ++;
    }
}

