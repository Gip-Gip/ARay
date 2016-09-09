/* help.h - includes files and defines things needed by help.c

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

*/

#include <common.h>
#include <args.h>
#include <messages.h>

#define HELP_USAGE "\nUSAGE:\n\n%s map.iam [arguments]\n\n\
arguments are read left to right\n\n", PROGNAME
#define HELP_FORMAT "\"%s\" or \"%s\" %s\n\n", \
                    args[index + ARGS_SHRTDPTH], \
                    args[index + ARGS_LONGDPTH], \
                    args[index + ARGS_HELPDPTH]
