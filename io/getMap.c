/* getMap - reads a map from the specified file stream, storing it in the global
            array

ARGUMENTS:

FILE *file - the filestream being read

VARIABLES:

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
