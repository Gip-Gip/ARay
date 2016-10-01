/* txtrInit - initializes the texture array

ARGUMENTS:

VARIABLES:

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
