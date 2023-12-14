#include "monty.h"

/**
 * command - function that is used to detect, build and execute commands.
 * @buffer: String may contain one or more commands.
 * @stack: Doubly linked list.
 */
int command(char *buffer, stack_t **stack, unsigned int line_number)
{
    int length = strlen(buffer); /* Get the length of string */
    char *action, *argument;
    int position = 0;
    unsigned int value;
    instruction_t actions[] = {
        {"push", push},
        {NULL, NULL},
    };
    
    if (length != 0) /* practically ignore lines with 0 length */
    {   
        action = strtok(buffer, " \n\t");
        argument = strtok(NULL, " \n\t");
        
        if (action == NULL)
            exit(EXIT_FAILURE);
        for(position = 0; actions[position].opcode != NULL; position++)
        {
            if (strcmp(actions[position].opcode, action) == 0)
            {      
                value = (unsigned int) atoi(argument);
                if (value == 0 && strcmp("push", action) == 0)
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
                actions[position].f(stack, value);
                return (1);
            }
            else if (strcmp("pall", action) == 0)
            {
                pall(*stack);
                return (1);
            }
        }
        /* incase command was not found raise error */
        fprintf(stderr, "L%d: unknown instruction %s", line_number, action);
        exit(EXIT_FAILURE);
    }
    return (0);
}