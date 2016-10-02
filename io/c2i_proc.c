/* c2i_proc - reads a csv2iam script and builds a map

ARGUMENTS:

string inName - the filename of the c2i script
string outName - the filename of the iam map

VARIABLES:

string buffer - the buffer that stores lines from the given csv2iam script
string gzReturn - the message returned from GZERROR
character prebuff - the pre-buffer buffer
character mode - determines the way the input script is processed
map mapbuff - the buffer that holds the map before it is written to outGZ
natural mwidth - the width of the map
natural mheight - the height of the map
natural mdepth - the depth of the map
natural textureCount - the amount of textures in the index
natural index - the layer of the map that is being written to
natural texCount - the amount of textures processed, for debugging purposes
bool reading - when true, the buffer is updated with every byte read from in
FILE *in - the file being read
FILE *foo - the file pointer used for secondary files, like PPMs and CSVs
gzFile outGZ - the file being written to
int gzRetNum - the return int of GZERROR

*/

#include <c2i_proc.h>

int c2i_proc(string inName, string outName)
{
    string buffer = calloc(STRALLOC, sizeof(character)), gzReturn;
    character preBuff[] = {0, 0}, mode = ZERO;
    map mapbuff;
    natural mwidth, mheight, mdepth, textureCount, index = ZERO, texCount = 0;
    bool reading = false;
    FILE *in, *foo;
    gzFile outGZ;
    int gzRetNum;

    if(!overwrite && fopen(outName, READMODE))
    {
        print(MSG_EXISTS_2);
        return err_exists;
    }

    if(!(in = fopen(inName, READMODE)) ||
        !(outGZ = gzopen(outName, gzWriteMode)))
    {
        perror(MSG_PERROR);
        return errno;
    }

    /* Get and write the heights */
    fgetnum(in, &mwidth);
    fgetnum(in, &mheight);
    fgetnum(in, &mdepth);
    fgetnum(in, &textureCount);

    gzputc(outGZ, mwidth - IAM_NUMCORR);
    gzputc(outGZ, mheight - IAM_NUMCORR);
    gzputc(outGZ, mdepth - IAM_NUMCORR);
    gzputc(outGZ, textureCount - IAM_NUMCORR);

    if((gzReturn = GZERROR(outGZ, &gzRetNum)) && gzRetNum == Z_ERRNO)
    {
        print(MSG_GZERR);
        return errno;
    }

    if(!(mapbuff = calloc(mwidth * mheight * mdepth, sizeof(mapunit))))
    {
        perror(MSG_PERROR);
        return errno;
    }

    /* Process the c2i script */
    for(*preBuff = READBYTE(in); !feof(in); *preBuff = READBYTE(in))
    {
        if(!reading && *preBuff == C2I_STRTDELM) reading = true;

        else if(reading && *preBuff == C2I_ENDDELM)
        {
            reading = false;

            if(!(foo = fopen(buffer, READMODE)))
            {
                perror(MSG_PERROR);
                return errno;
            }

            switch(mode)
            {
                case(C2I_IMAGE):
                    ppm_proc(buffer, texCount, foo, outGZ);
                    if(!(textureCount--))
                    {
                        print(MSG_BADTEXCNT);
                        return err_badTexCnt;
                    }

                    texCount ++;
                    break;
                case(C2I_LAYER):
                    csv_proc(foo, (index * mwidth * mheight) + mapbuff,
                             mwidth, mheight);

                    print(MSG_LOADDCSV);
                    index ++;
                    break;
                default:
                    print(MSG_BADMODE);
                    return err_badMode;
                    break;
            }

            fclose(foo);
            free(buffer);
            buffer = calloc(STRALLOC, sizeof(character));
        }

        else if(reading && !isspace(*preBuff))
            buffer = strapp(buffer, preBuff, true, false);

        else if(!isspace(*preBuff)) mode = *preBuff;
    }

    /* If the # of textures read doesn't equal the given texture count... */
    if(textureCount)
    {
        print(MSG_BADTEXCNT);
        return err_badTexCnt;
    }

    gzwrite(outGZ, mapbuff, mwidth * mheight * mdepth);

    if((gzReturn = GZERROR(outGZ, &gzRetNum)) && gzRetNum == Z_ERRNO)
    {
        print(MSG_GZERR);
        return errno;
    }

    gzclose(outGZ);

    return none;
}
