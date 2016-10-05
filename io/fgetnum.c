/* fgetnum - gets a number from a file

ARGUMENTS:

FILE *file - the file being read
natural *number - the number being returned

VARIABLES:

string buffer - the text buffer
character prebuff

*/

#include <fgetnum.h>

int fgetnum(FILE *file, natural *number)
{
    string buffer = calloc(STRALLOC, sizeof(character));
    character prebuff[] = {0, 0};

    while(!feof(file) && !numchar(*prebuff = READBYTE(file)))
        if(*prebuff == COMMENT) while(!feof(file) && READBYTE(file) != NEWLINE);

    fseek(file, -sizeof(character), SEEK_CUR);

    while(!feof(file) && numchar(*prebuff = READBYTE(file)))
        buffer = strapp(buffer, prebuff, true, false);

    if(!strlen(buffer)) return err_eof;

    *number = atoi(buffer);

    free(buffer);

    return none;
}
