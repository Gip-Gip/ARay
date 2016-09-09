/* getMap - reads a map from the specified file stream, storing it in the global
            array

ARGUMENTS:

FILE *file - the filestream being read

VARIABLES:

*/

#include <getMap.h>

int getMap(FILE *file)
{
    natural index = INDEXINIT;

    FLETCHER16_INIT();

    if(!(ARRAY_INIT3D(READBYTE(file), READBYTE(file), READBYTE(file))))
    {
        perror(MSG_PERROR);
        return errno;
    }

    while(++index < ARRAY_LENGTH)
    {
        ARRAY_ACCESS(index) = READBYTE(file);
        FLETCHER16_ADD(ARRAY_ACCESS(index));
    }

    if(fletcherA != READBYTE(file) || fletcherB != READBYTE(file))
    {
        printf(MSG_BADFLETCHER);
        return err_badFletcher;
    }

    return none;
}
