

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
#define TEXTURE_ACCESS_R_XY(num, offsetX, offsetY) \
    textures[num][(offsetX + (offsetY * tex_width[num])) * RGBSZ + RDPTH]
#define TEXTURE_ACCESS_G(num, offset) textures[num][offset * RGBSZ + GDPTH]
#define TEXTURE_ACCESS_G_XY(num, offsetX, offsetY) \
    textures[num][(offsetX + (offsetY * tex_width[num])) * RGBSZ + GDPTH]
#define TEXTURE_ACCESS_B(num, offset) textures[num][offset * RGBSZ + BDPTH]
#define TEXTURE_ACCESS_B_XY(num, offsetX, offsetY) \
    textures[num][(offsetX + (offsetY * tex_width[num])) * RGBSZ + BDPTH]
