#ifndef MYSHELL_H
#define MYSHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_INPUT 1024
#define MAX_ARG 100
char** parser(char* input);
#endif