/* texture.h - contains definitions used for texture I/O

ENUMS:

TYPEDEFS:

DEFINITIONS:

RGBSZ - the size of each pixel

RDPTH - the location of the red value in each pixel
GDPTH - the location of the green value in each pixel
BDPTH - the location of the blue value in each pixel

MACROS:

TEXTURE_ADDENTRY - adds an entry to the texture array

TEXTURE_ACCESS_R - accesses the red value of a pixel in the provided texture
TEXTURE_ACCESS_G - accesses the green value of a pixel in the provided texture
TEXTURE_ACCESS_B - accesses the blue value of a pixel in the provided texture

TEXTURE_ACCESS_R_XY - same as TEXTURE_ACCESS_R, except it uses XY coornates
                      instead of a direct offset
TEXTURE_ACCESS_G_XY - same as TEXTURE_ACCESS_G, except it uses XY coornates
                      instead of a direct offset
TEXTURE_ACCESS_B_XY - same as TEXTURE_ACCESS_B, except it uses XY coornates
                      instead of a direct offset

*/

#include <common.h>
#include <IAM.h>

extern image *textures;
extern natural *tex_width;
extern natural *tex_height;

#define RGBSZ IAM_IMGDEPTH
#define RDPTH 0
#define GDPTH 1
#define BDPTH 2

#define TEXTURE_ADDENTRY(num, width, height) (textures[num] = \
                                              calloc(width * height, RGBSZ), \
                                              tex_width[num] = width, \
                                              tex_height[num] = height)

#define TEXTURE_ACCESS_R(num, offset) textures[num][offset * RGBSZ + RDPTH]
#define TEXTURE_ACCESS_G(num, offset) textures[num][offset * RGBSZ + GDPTH]
#define TEXTURE_ACCESS_B(num, offset) textures[num][offset * RGBSZ + BDPTH]

#define TEXTURE_ACCESS_R_XY(num, offsetX, offsetY) \
    textures[num][(offsetX + (offsetY * tex_width[num])) * RGBSZ + RDPTH]
#define TEXTURE_ACCESS_G_XY(num, offsetX, offsetY) \
    textures[num][(offsetX + (offsetY * tex_width[num])) * RGBSZ + GDPTH]
#define TEXTURE_ACCESS_B_XY(num, offsetX, offsetY) \
    textures[num][(offsetX + (offsetY * tex_width[num])) * RGBSZ + BDPTH]
