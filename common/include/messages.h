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

#define FIRSTARG 1
#define PROGNAME gargv[0]

#define MSG_PERROR "ERROR"
#define MSG_EXISTS_1 "ERROR: \"%s\" already exists! Run \"%s\" to overwrite\n", \
                   gargv[argn], gExample(ARGS_GETARG(arg_overwrite), argn - 1)
#define MSG_EXISTS_2 "ERROR: \"%s\" already exists! Run \"%s\" to overwrite\n", \
                   outName, gExample(ARGS_GETARG(arg_overwrite), FIRSTARG)
#define MSG_NOMAP "ERROR: No map specified!\n"
#define MSG_BADENTRY "WARNING(On line %n): No variable with the name \"%s\"\n",\
                     lineNum, buffer
#define MSG_GZERR "ERROR: zlib: %s\n", gzReturn
#define MSG_LOADGMAP \
"INFO: Loading map \"%s\"%v with the diminsions %nx%nx%n%v\n", in, mwidth, \
mheight, mdepth
#define MSG_LOADDMAP \
"INFO: \"%s\" has been loaded%v. Memory allocation adds up to %n bytes%v\n", \
in, mwidth * mheight * mdepth + tAllocSum
#define MSG_LOADDTEX \
"%vINFO: Texture #%n has been loaded, with the diminsions %nx%n\n", \
index, twidth, theight
#define MSG_LOADDPPM "INFO: Texture #%n has been loaded from PPM \"%s\"\n", \
inNum, inName
#define MSG_LOADDCSV "INFO: Layer #%n has been loaded from PPM \"%s\"\n", \
index, buffer
#define MSG_BADMODE "ERROR: Bad csv2iam mode \"%c\"!\n", mode
#define MSG_BADTEXCNT "ERROR: Texture count doesn't match the given number\n"
