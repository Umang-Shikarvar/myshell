#include "myshell.h"

char** parser(char* input)
{
    char **args = malloc(MAX_ARG * sizeof(char*));
    if(args == NULL)
    {
        perror("malloc failed");
        exit(1);
    }
    int i=0;
    char* token=strtok(input," ");
    while(token!=NULL && i<MAX_ARG-1)
    {
        args[i++]=token;
        token=strtok(NULL," ");
    }
    args[i]=NULL;
    return args;
}