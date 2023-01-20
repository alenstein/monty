#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the top of the stack.
 *
 * Return: void
 */
void pall(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
