/* getTextr - gets the pixel of a texture and draws it to the screen

ARGUMENTS:

VARIABLES:

*/

#include <getPixel.h>

void getPixel(hit side, rational coord1, rational coord2, natural index,
              mapunit texture)
{
    texture -= 1;

    PUTPIXEL(index,
        TEXTURE_ACCESS_R_XY(texture,
            R2N((coord1 * tex_width[texture])),
            R2N((coord2 * tex_height[texture]))),
        TEXTURE_ACCESS_G_XY(texture,
            R2N((coord1 * tex_width[texture])),
            R2N((coord2 * tex_height[texture]))),
        TEXTURE_ACCESS_B_XY(texture,
            R2N((coord1 * tex_width[texture])),
            R2N((coord2 * tex_height[texture]))));
}
