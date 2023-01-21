#include "monty.h"

/**
 * execute - exec the opcode
 * @content: instruction
 * @stack: pointer to stack
 * @line_number: line number
 * @file: monty file
 * Return: void
 */
void execute(char *content, stack_t **stack, unsigned int line_number,
FILE *file)
{
	char *opcode;
	instruction_t opst[] = { {"push", push}, {"pall", pall},
{"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add},
{"nop", nop}, {NULL, NULL} };
	int i;

	opcode = strtok(content, " \n\t\r");
	if (opcode == NULL || opcode[0] == '#')
		return;

	for (i = 0; opst[i].opcode; i++)
	{
		if (!strcmp(opcode, opst[i].opcode))
		{
			opst[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, ERROR_INSTRUCTION, line_number, opcode);
	fclose(file);
	exit(EXIT_FAILURE);
}
