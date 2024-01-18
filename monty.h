#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <string.h>


extern unsigned int line_number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next elemet of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, quesues, LIFO, FIFO
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
 * free_stack - frees memory allocated to stack nodes
 * @stack: double pointer to stack head
 * Return: Nothing
 */
/*
void free_stack(stack_t **stack)
{
	stack_t *current;

	current = *stack;

	while (current != NULL)
	{
		free(current);
		current = current->next;
		free(current->prev);
	}
}*/

stack_t *build_list(stack_t *head);
void call(char **tokens, stack_t **stack);
char **tokenized(char *buffer);
void _push(stack_t **stack, unsigned int n);
void _pall(stack_t **stack, unsigned int n);
void free_stack(stack_t **stack);
void is_valid(char ** token, stack_t **stack);
void _pint(stack_t **stack, unsigned int n);
void _pop(stack_t **stack, unsigned int n);
void _swap(stack_t **stack, unsigned int n);
void _add(stack_t **stack, unsigned int n);
void _sub(stack_t **stack, unsigned int n);
void _div(stack_t **stack, unsigned int n);
void _mul(stack_t **stack, unsigned int n);
void _mod(stack_t **stack, unsigned int n);
void _pchar(stack_t **stack, unsigned int n);
void _pstr(stack_t **stack, unsigned int n);
void _rotl(stack_t **stack, unsigned int n);
void _rotr(stack_t **stack, unsigned int n);
#endif /* _MONTY_H */
