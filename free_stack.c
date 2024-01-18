#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: double pointer to stack
 * Return: Nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		if (!current->next)
		{
			free(current);
			break;
		}
		current = current->next;
		free(current->prev);
	}
}
