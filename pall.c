#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the top of the stack.
 * @line_number: the line numbe rat any instance.
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)(line_number);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
