#include "monty.h"

/**
 * _push - pushes a node onto the stack
 * @stack: double pointer to stack (head)
 * @n: line number
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int n)
{
	stack_t *node = NULL;
	(void) n;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	node->prev = NULL;
	node->next = NULL;

	if (!(*stack))
	{
		*stack = node;
	}
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		*stack = node;
	}
}

/**
 * _pall - displays the elements in a stack
 * @stack: double pointer to stack
 * @n: line number
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *head;
	stack_t *node;

	(void) n;

	if (!stack || !(*stack))
	{
		return;
	}
	node = head = *stack;

	while (node)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}
