/* args.h - defines things and includes files needed to interface with args[]

ENUMS:

TYPEDEFS:

DEFINITIONS:

ARGS_ENTRYDPTH - the size of each entry in args[]
ARGS_SHRTDPTH - the offset of the short argument in an entry
ARGS_LONGDPTH - the offset of the long argument in an entry
ARGS_HELPDPTH - the offset of the help in an entry

MACROS:

ARGS_GETARG - gets the argument from the offset specified

*/

extern string args[];
#define ARGS_ENTRYDPTH 3
#define ARGS_SHRTDPTH 0
#define ARGS_LONGDPTH 1
#define ARGS_HELPDPTH 2
#define ARGS_GETARG(argument) args[(ARGS_ENTRYDPTH * argument) + ARGS_SHRTDPTH]
