#include "monty.h"




/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to a stack
 * @line_number: Line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = (*stack)->next;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	first->prev = second;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}
