/* ppm_proc - processes a raw PPM file and writes to the given BZFILE

ARGUMENTS:

string inName - the name of the file being read, for debugging purposes
FILE *in - the file being read
gzFile *outGZ - the file being written to

VARIABLES:

natural index - used to keep track of where we are in the image
natural width - the width of the image
natural height - the height of the image
natural dividend - used in the max value feature of PPMs
natutal buffer - stores data until it is written to outGZ
string gzReturn - the message returned by GZERROR
rational multiplier - the amount to multiply the pixels, equal to 255/dividend
int gzRetNum - the return int of GZERROR

*/

#include <ppm_proc.h>

int ppm_proc(string inName, FILE *in, gzFile outGZ)
{
    natural index = INDEXINIT, width, height, dividend, buffer;
    string gzReturn;
    rational multiplier;
    int gzRetNum = 0;

    if(READBYTE(in) != PPM_MN1 || READBYTE(in) != PPM_MN2) return err_badPPM;

    fgetnum(in, &width);
    fgetnum(in, &height);
    fgetnum(in, &dividend);

    multiplier = PPM_MM / dividend;

    gzputc(outGZ, width - IAM_NUMCORR);
    gzputc(outGZ, height - IAM_NUMCORR);

    if((gzReturn = GZERROR(outGZ, &gzRetNum)) && gzRetNum == Z_ERRNO)
    {
        print(MSG_GZERR);
        return errno;
    }

    print(MSG_PPMLOADED);

    for(buffer = READBYTE(in);
        !feof(in) && ++index < width * height * PPM_PXSZ;
        buffer = READBYTE(in))
    {
        gzputc(outGZ, RR2N(multiplier * buffer) - IAM_NUMCORR);

        if((gzReturn = GZERROR(outGZ, &gzRetNum)) && gzRetNum == Z_ERRNO)
        {
            print(MSG_GZERR);
            return errno;
        }
    }

    return none;
}
