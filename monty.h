#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define USAGE "USAGE: monty file\n"
#define ERROR_OPEN "Error: Can't open file %s\n"
#define ERROR_INSTRUCTION "L%d: unknown instruction %s\n"
#define ERROR_MALLOC "Error: malloc failed\n"
#define ERROR_PUSH "L%d: usage: push integer\n"
#define ERROR_PINT "L%d: can't pint, stack empty\n"
#define ERROR_POP "L%d: can't pop an empty stack\n"
#define ERROR_SWAP "L%d: can't swap, stack too short\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack or queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

/* function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void execute(char *content, stack_t **stack, unsigned int line_number,
FILE *file);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void _stack(stack_t **head, unsigned int counter);
void add(stack_t **stack, unsigned int line_number);
void addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int counter);

#endif /* MONTY_H */
