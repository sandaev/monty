#include "monty.h"

/**
 * _add - adds the topmost two data on stack
 * @stack: double ptr to stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(stack);
		}
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) + ((*stack)->n);
	_pop(stack, line_number);
}
