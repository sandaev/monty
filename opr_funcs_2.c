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
	if (!stack || (*stack))
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
