#include "monty.h"

/**
 * command - function that is used to detect, build and execute commands.
 * @buffer: String may contain one or more commands.
 * @stack: Doubly linked list.
 * @line_number: line number.
 * Return: integer, 1 in case of success, 0 incase of failure.
 */
int command(char *buffer, stack_t **stack, unsigned int line_number)
{
	int length = strlen(buffer); /* Get the length of string */
	char *action, *argument;
	int position = 0;
	unsigned int value;
	instruction_t actions[] = {
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL},
	};

	if (length != 0) /* practically ignore lines with 0 length */
	{
		action = strtok(buffer, " \n\t");
		argument = strtok(NULL, " \n\t");
		if (action && action[0] == '#')
			return (0);
		for (position = 0; actions[position].opcode != NULL; position++)
		{
			if (strcmp(actions[position].opcode, action) == 0)
			{
				value = line_number;
				if (value == 0 && strcmp("push", action) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				if (strcmp("push", action) == 0)
					value = (unsigned int) atoi(argument);
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
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, action);
		exit(EXIT_FAILURE);
	}
	return (0);
}
