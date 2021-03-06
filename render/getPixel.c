/* getPixel - gets the pixel of a texture and draws it to the screen

ARGUMENTS:

hit side - the side that was hit
rational coord1 - the x pixel coornates
rational coord2 - the y pixel coornates
natural index - the offset of the screen to draw to
mapunit texture - the texture to read

VARIABLES:

*/

#include <getPixel.h>

extern natural playerRot;
extern natural screenWidth;

void getPixel(hit side, rational coord1, rational coord2, natural index,
              mapunit texture)
{
    side = (side / 2) + 1;

    index = (index + playerRot) % screenWidth + ((index / screenWidth) * screenWidth);

    PUTPIXEL(index,
        TEXTURE_ACCESS_R_XY(texture,
            R2N((coord1 * tex_width[texture])),
            R2N((coord2 * tex_height[texture]))) / side,
        TEXTURE_ACCESS_G_XY(texture,
            R2N((coord1 * tex_width[texture])),
            R2N((coord2 * tex_height[texture]))) / side,
        TEXTURE_ACCESS_B_XY(texture,
            R2N((coord1 * tex_width[texture])),
            R2N((coord2 * tex_height[texture]))) / side);
}
