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

/**
 * _sub - subtracts the two topmost elements of a stack
 * @stack: double ptr to the stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(stack);
		}
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) - ((*stack)->n);
	_pop(stack, line_number);
}

/**
 * _div - divides the topmost by the next ele on the stack
 * @stack: ptr to stack
 * @line_number: Number
 *
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(stack);
		}
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) / ((*stack)->n);
	_pop(stack, line_number);
}

/**
 * _mul - mu;tiply topmost elements
 * @stack: pointer
 * @line_number: number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(stack);
		}
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) * ((*stack)->n);
	_pop(stack, line_number);
}

/**
 * _mod - rest of the division of the second top by the top element
 * @stack: ptr to stack
 * @line_number: number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(stack);
		}
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = ((*stack)->next->n) % ((*stack)->n);
	_pop(stack, line_number);
}
