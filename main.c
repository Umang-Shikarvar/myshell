#include "myshell.h"

int main(void)
{
    char** args;
    while(1)
    {
        char input[MAX_INPUT];
        printf("$> ");
        fflush(stdout);

        if(fgets(input,MAX_INPUT,stdin)==NULL)
        {
            perror("fgets failed");
            continue;
        }    
        input[strcspn(input,"\n")]='\0';
        if(input[0]=='\0')
        continue;

        args=parser(input);

        if(strcmp(args[0], "exit")==0)
        {
            break;
        }
        else
        {
            int p=fork();
            if(p<0)
            {
                perror("fork failed");
                continue;
            }
            else if(p==0)
            {
                execvp(args[0],args);
                perror("exec failed");
                exit(1);
            }
            else
            {
                wait(NULL);
            }
        }
        free(args);
    }
}