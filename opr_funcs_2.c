#include "monty.h"

/**
 * _pchar - prints the character at the top of the stack
 * @stack: double pointer to stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: double pointer to stack
 * @n: line number
 *
 * Return: Nothing
 */
void _pstr(stack_t **stack, unsigned int n)
{
	stack_t *node;
	(void) n;

	if (!stack || !(*stack))
	{
		fprintf(stdout, "\n");
		return;
	}

	node = *stack;
	while (node)
	{
		if (node->n <= 0 || node->n > 127)
		{
			break;
		}
		fprintf(stdout, "%c", node->n);
		node = node->next;
	}
	fprintf(stdout, "\n");
}

/**
 * _rotl - rotates the stack elements bottom up
 * @stack: double pointer to stack
 * @n: line number
 *
 * Return: Nothing
 */
void _rotl(stack_t **stack, unsigned int n)
{
	stack_t *head = NULL;
	stack_t *tail = NULL;
	(void) n;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		return;
	}

	head = *stack;
	tail = head->next;
	tail->prev = NULL;
	*stack = tail;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
}

/**
 * _rotr - rotates a stack
 * @stack: double ptr to stack
 * @n: line number
 *
 * Return: Nothing
 */
void _rotr(stack_t **stack, unsigned int n)
{
	stack_t *head = NULL;
	stack_t *tail = NULL;

	(void) n;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		return;
	}

	tail = *stack;
	head = *stack;

	while (head->next)
	{
		head = head->next;
	}

	head->prev->next = NULL;
	head->next = tail;
	head->prev = NULL;
	tail->prev = head;
	*stack = head;
}
