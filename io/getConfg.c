/* getConfg - reads the provided file as a config file

ARGUMENTS:

FILE *file - the file being read

VARIABLES:

string buffer - the buffer
character preBuff - the character before it gets added to the buffer
string varBuff - the string buffer for variables
bool *freeable - set if the string is freeable
vType varType - the type of variable being parsed
void variable - a pointer to the variable being read
natural lineNum - incremented when the pre-buffer is a newline

*/

#include <getConfg.h>

int getConfg(FILE *file)
{
    string buffer = calloc(STRALLOC, UNIT_STR);
    character preBuff[] = {0, 0};
    string varBuff = NULL;
    bool *freeable = NULL;
    vType varType;
    void *variable = NULL;
    natural lineNum = 1;

    for(*preBuff = getchar();!feof(file); *preBuff = getchar())
    {
        if(*preBuff == COMMENT)
        {
            while(getchar() != NEWLINE && !feof(file));
            lineNum ++;
        }

        else if(*preBuff == NEWLINE) lineNum ++;

        else if(*preBuff == EQUDELEM)
        {
            if(!(variable = getVar(buffer, &varType, &freeable)))
                print(MSG_BADENTRY);

            else switch(varType)
            {
                case(vt_natural):
                    fgetnum(file, (natural *)variable);
                    break;
                case(vt_string):
                    varBuff = *((string *)variable);

                    if(*freeable) free(varBuff);
                    else *freeable = true;

                    for(*preBuff = fgetc(file);
                        !feof(file) && *preBuff != STRSTART;
                        *preBuff = fgetc(file));

                    for(varBuff = calloc(STRALLOC, sizeof(character)),
                        *preBuff = fgetc(file);
                        !feof(file) && *preBuff != STREND;
                        *preBuff = fgetc(file))
                    {
                        if(*preBuff == ESCDELM)
                        {
                            *preBuff = fgetc(file);

                            switch(*preBuff)
                            {
                                case(NLDELEM):
                                    *preBuff = NEWLINE;
                                    break;
                                default:
                                    break;
                            }
                        }

                        varBuff = strapp(varBuff, preBuff, true, false);
                    }

                    *((string *)variable) = varBuff;

                    break;
            }

            free(buffer);
            buffer = calloc(STRALLOC, UNIT_STR);
        }

        else if(!isspace(*preBuff))
            buffer = strapp(buffer, preBuff, true, false);
    }

    return none;
}
