#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

unsigned int line_number = 0;

/**
 * main - Program entrance (control)
 * @argc: number of arguments
 * @argv: list of argumentas
 * Return: Alwyas zero
 */
int main(int argc, char *argv[])
{
	char **tokens = NULL; /*List of tokens */
	stack_t *head = NULL; /* pointer to stack */
	char *buffer = NULL;
	int delim = '\n';
	FILE *fp;
	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r+");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getdelim(&buffer, &n, delim, fp)) != -1)
	{
		line_number++;
		tokens = tokenized(buffer);
		if (tokens)
		{
			call(tokens, &head);
			free(tokens);
		}
	}
	free(buffer);
	free_stack(&head);
	fclose(fp);
	return (0);
}
