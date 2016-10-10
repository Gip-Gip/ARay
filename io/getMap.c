/* getMap - reads a map from the specified file stream, storing it in the global
            array

ARGUMENTS:

string in - the filename of the map to load

VARIABLES:

natural mwidth - the width of the map
natural mheight - the height of the map
natural mdepth - the depth of the map
natural twidth - the width of the texture being loaded
natural theight - the height of the texture being loaded
natural textureCount - the number of textures to load
natural index - the index used to go through the textures
natural tAllocSum - the amount of memory allocated for textures
string gzReturn - the string to print if gzerror gives Z_ERRNO
int gzRetNum - used for storing the status of gzerror
gzFile inGZ - the gzFile pointer to the map being read

*/

#include <getMap.h>

int getMap(string in)
{
    natural mwidth, mheight, mdepth, twidth, theight, textureCount,
    index = INDEXINIT, tAllocSum = ZERO;
    string gzReturn;
    int gzRetNum;
    gzFile inGZ = gzopen(in, gzReadMode);

    txtrInit();

    if(!inGZ)
    {
        perror(MSG_PERROR);
        return errno;
    }

    mwidth = gzgetc(inGZ) + IAM_NUMCORR;
    mheight = gzgetc(inGZ) + IAM_NUMCORR;
    mdepth = gzgetc(inGZ) + IAM_NUMCORR;
    playerX = N2R(gzgetc(inGZ) + IAM_NUMCORR) + 0.5;
    playerY = N2R(gzgetc(inGZ) + IAM_NUMCORR) + 0.5;
    playerZ = N2R(gzgetc(inGZ) + IAM_NUMCORR) + 0.5;
    textureCount = gzgetc(inGZ) + IAM_NUMCORR;

    if((gzReturn = GZERROR(inGZ, &gzRetNum)) && gzRetNum == Z_ERRNO)
    {
        print(MSG_GZERR);
        return errno;
    }

    if(!ARRAY_INIT3D(mwidth, mheight, mdepth))
    {
        perror(MSG_PERROR);
        return errno;
    }

    print(MSG_LOADGMAP);

    while(++index < textureCount)
    {
        twidth = gzgetc(inGZ) + IAM_NUMCORR;
        theight = gzgetc(inGZ) + IAM_NUMCORR;

        if(!TEXTURE_ADDENTRY(index, twidth, theight))
        {
            perror(MSG_PERROR);
            return errno;
        }

        gzread(inGZ, textures[index], twidth * theight * IAM_IMGDEPTH);

        if((gzReturn = GZERROR(inGZ, &gzRetNum)) && gzRetNum == Z_ERRNO)
        {
            print(MSG_GZERR);
            return errno;
        }

        tAllocSum += twidth * theight * IAM_IMGDEPTH;

        print(MSG_LOADDTEX);
    }

    gzread(inGZ, array, mwidth * mheight * mdepth);

    if((gzReturn = GZERROR(inGZ, &gzRetNum)) && gzRetNum == Z_ERRNO)
    {
        print(MSG_GZERR);
        return errno;
    }

    print(MSG_LOADDMAP);

    gzclose(inGZ);

    return none;
}
