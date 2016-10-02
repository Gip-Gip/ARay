/* c2i_proc.h - includes files and defines things needed by c2i_proc.c

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

*/

#include <common.h>
#include <ctype.h>
#include <messages.h>
#include <zlib.h>
#include <fileIO.h>
#include <IAM.h>

extern bool overwrite;
extern natural bzLevel;
extern natural bzVerb;
extern natural bzWF;
extern string gExample();
extern natural fgetnum();
extern int ppm_proc();
extern int csv_proc();
extern string gzWriteMode;

#define C2I_STRTDELM '"'
#define C2I_ENDDELM '"'
#define C2I_ESCDELM '\\'
#define C2I_IMAGE 'I'
#define C2I_LAYER 'L'
