/* fileIO.h - includes files and defines things needed for file IO

ENUMS:

TYPEDEFS:

DEFINITIONS:

READMODE - the mode used for reading
GERROR - fixed gerror that won't give warnings

MACROS:

READBYTE - reads a byte from the specified file
WRITEBYTE - writes to the specified file with the given byte

*/

#include <stdio.h>

#define READMODE "rb"
#define WRITEMODE "wb"
#define GZERROR (string)gzerror


#define READBYTE(file) fgetc(file)
#define WRITEBYTE(file, data) fputc(data, file)
