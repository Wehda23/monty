#include "monty.h"


/**
 * push - function that pushes a new node into the stack/Queue
 * @head: Doubly linked list
 * @position: Position at which we are going to insert this new Node.
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));

    if (new == NULL)
    {
        printf("Error");
        exit(EXIT_FAILURE);
    }

    new->n = line_number;
    new->next = NULL;
    new->prev = NULL;

    /* Incase it is a fresh one*/
    if ((*stack) == NULL)
    {
        (*stack) = new;
    }
    else
    {
        new->next = (*stack);
        (*stack)->prev = new;
        (*stack) = new;
    }
}


/**
 * free_stack - function that frees memory allocation of a stack.
 * @stack: doubly linked list to a stack.
 */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    stack_t *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);   
        current = next_node;
    }
}