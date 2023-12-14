#include "monty.h"


/**
 * mul_stack - multiplies the second top element of the stack with the top element of the stack.
 * @stack: Pointer to a stack
 * @line_number: line number.
 */
void mul_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n *= (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    free(current);
}

/**
 * mod_stack - computes the rest of the division of the second top element of the stack
 *              by the top element of the stack.
 * @stack: Pointer to a stack.
 * @line_number: line number.
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    free(current);
}

