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

#define MSG_SPLASH \
"\nARay I.MMXVI rev. 2\n\
Run \"%s -h\" to get help, \"%< -L\" to get legal info\n\n", PROGNAME
#define MSG_LICENSE "\n\
Copyright (c) 2016, Charles Thompson <chmithbiz@gmail.com>\n\
Permission to use, copy, modify, and/or distribute this software for any \n\
purpose with or without fee is hereby granted, provided that the above\n\
copyright notice and this permission notice appear in all copies.\n\
\n\
THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL WARRANTIES\n\
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF\n\
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY\n\
SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER\n\
RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF\n\
CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN\n\
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n\n"

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
#define MSG_LOADGCSV \
"INFO: Building a map %nx%nx%n%v with %n textures & the player @ %n,%n,%n%v\n",\
mwidth, mheight, mdepth, textureCount, mplayerX, mplayerY, mplayerZ
#define MSG_LOADDCSV "INFO: Layer #%n has been loaded from PPM \"%s\"\n", \
index, buffer
#define MSG_BADMODE "ERROR: Bad csv2iam mode \"%c\"!\n", mode
#define MSG_BADTEXCNT "ERROR: Texture count doesn't match the given number\n"
