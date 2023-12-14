#include "monty.h"

/**
 * command - function that is used to detect, build and execute commands.
 * @buffer: String may contain one or more commands.
 * @stack: Doubly linked list.
 */
void command(char *buffer, stack_t **stack, unsigned int line_number)
{
    int length = strlen(buffer); /* Get the length of string */
    char *action;
    /*instruction_t actions[] = {  Actions array 
        {NULL, NULL},
    };
    */
    if (length != 0) /* practically ignore lines with 0 length */
    {   
        
        push(stack, line_number);
        action = strtok(buffer, " \n\t");
        if (action == NULL)
            exit(EXIT_FAILURE);
            
        printf("%s\n", action);
    }
}