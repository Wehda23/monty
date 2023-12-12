#include "monty.h"


int main(int argc, char *argv)
{
    File *file;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    printf("Eksh");
    fclose(file);
    return (0);
}