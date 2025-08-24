#include "myshell.h"

void cd(char** args,char** path,const char* base_path)
{
    if (args[1])
    {
        if (chdir(args[1])!=0)
        {
            perror("chdir failed");
        }
        else
        {
            *path=getcwd(NULL, 0);
            if(*path==NULL)
            {
                perror("getcwd failed");
            }
            else if(strstr(*path,base_path)==NULL)
            {
                printf("Permission denied\n");
                chdir(base_path);
                free(*path);
                *path="~";
            }
            else
            {
                char* temp=*path+strlen(base_path);
                free(*path);
                if(temp)
                {
                    temp[0]='~';
                    *path=temp;
                }
                else
                {
                    *path="~";
                }
            }
        }
    }
    else
    {
        chdir(base_path);
        free(*path);
        *path="~";
    }
}
