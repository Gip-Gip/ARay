/* messages.h - holds the messages used across the program

ENUMS:

TYPEDEFS:

DEFINITIONS:

PROGNAME - the pointer to the program's name
MSG_PERROR - the perror message
MSG_EXISTS - the error displayed when a file exists
MSG_NOMAP - the error displayed when no map is given
MSG_BADFLETCHER - the error when a fletcher checksum is bad

MACROS:

*/

#include <types.h>
#include <args.h>

extern string *gargv;
extern natural gargc;
extern string genExample();

#define PROGNAME gargv[0]

#define MSG_PERROR "ERROR"
#define MSG_EXISTS "ERROR: \"%s\" already exists! Run \"%s\" to overwrite\n", \
                   gargv[argn], gExample(ARGS_GETARG(arg_overwrite),argn - 1)
#define MSG_NOMAP "ERROR: No map specified!\n"
#define MSG_BADFLETCHER "ERROR: Bad fletcher16 checksum!\n"
