/* csv_proc - process the given csv and writes it to the given BZFILE

ARGUMENTS:

FILE *in - the csv being read
BZFILE *out - the bzip2 file being written to

VARIABLES:

natural index - the index that goes through the map buffer

*/

#include <csv_proc.h>

int csv_proc(FILE *in, map mapbuff, natural width, natural height)
{
    natural index = INDEXINIT, buffer;

    while(!fgetnum(in, &buffer) && ++index < width * height)
        mapbuff[index] = buffer + CSV_ADDVAL;

    return none;
}
