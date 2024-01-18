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

/**
 * _pint - prints the top element of the stack
 * @stack: double pointer to stack
 * @n: line number that opcode is call at.
 * Return: Nothing
 */
void _pint(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element from a stack
 * @stack: double ptr to satck
 * @n: line number
 * Return: Nothing
 */
void _pop(stack_t **stack, unsigned int n)
{
	stack_t *node;

	(void) n;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty list\n", n);
		exit(EXIT_FAILURE);
	}

	node = *stack;

	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(node);
}

/**
 * _swap - swaps the data in two nodes
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if ((stack == NULL) || (*stack == NULL) || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(stack);
		}
		exit(EXIT_FAILURE);
	}

	(void) line_number;

	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}
