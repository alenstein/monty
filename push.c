#include "monty.h"

/**
* push - add node to the stack
* @head: stack head
* @line_number: line number at any specific instance:wq
*
* Return: no return
*/
void push(stack_t **head, unsigned int line_number)
{
	int n, flag = 0, i = 0;

	if (!bus.arg)
	{
		fprintf(stderr, ERROR_PUSH, line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	for ( ; bus.arg[i]; i++)
	{
		if (!isdigit(bus.arg[i]))
			flag = 1;
	}

	if (flag)
	{
		fprintf(stderr, ERROR_PUSH, line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
