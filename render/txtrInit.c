/* txtrInit - initializes the texture array

ARGUMENTS:

VARIABLES:

image *textures - the pointer that holds all the textures used
natural *tex_width - an array that holds all the texture widths
natural *tex_height - an array that holds all the texture heights

*/

#include <txtrInit.h>

image *textures;
natural *tex_width, *tex_height;

int txtrInit()
{
    if(!(textures = calloc(MAXTEX, sizeof(image))) ||
        !(tex_width = calloc(MAXTEX, sizeof(natural))) ||
        !(tex_height = calloc(MAXTEX, sizeof(natural))))
    {
        perror(MSG_PERROR);
        return errno;
    }

    return none;
}
