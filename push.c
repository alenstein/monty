#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @n: value to be pushed
 *
 * Return: void
 */
void push(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
