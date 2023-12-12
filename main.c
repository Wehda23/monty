#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry function
 * @argc: Is the number of arguments passed in into the file
 * @argv: Argument list
 * Return: int 
 */
int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("/etc/motd", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
    
    return (0);
}
