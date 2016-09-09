/* arrayAccess.h - contains macros that help with array handling

ENUMS:

TYPEDEFS:

DEFINITIONS:

MACROS:

ARRAY_INIT3D - initializes the array variable
ARRAY_ACCESS3D - accesses an entry in the array variable
ARRAY_DEINIT - frees the memory allocated by the array

*/

#include <stdlib.h>
#include <types.h>

extern map array;
extern natural arr_width;
extern natural arr_height;
extern natural arr_depth;

#define ARRAY_INIT3D(width, height, depth) (array = calloc( \
                                    (arr_width = width) * \
                                    (arr_height = height) * \
                                    (arr_depth = depth), sizeof(mapunit)))

#define ARRAY_ACCESS(x) array[x]

#define ARRAY_ACCESS3D(x, y, z) array[( \
                                    (z * arr_width * arr_height) + \
                                    (y * arr_width) + \
                                    x)]

#define ARRAY_LENGTH (arr_width * arr_height * arr_depth)

#define ARRAY_DEINIT() free(array)
