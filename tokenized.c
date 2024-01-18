#include "monty.h"

/**
 * tokenized - tokenized a given buffer
 * @buffer: string to tonize
 *
 * Return: double pointer to tokenized string
 */
char **tokenized(char *buffer)
{
	char *token = NULL;  /*pointer to nxt tok */
	char **arr_toks; /* stores tokkens */
	int idx = 3;
	char *delim = "\t \r\n";

	token = strtok(buffer, delim);

	if (token == NULL)
	{
		return (NULL);
	}

	arr_toks = malloc(sizeof(char **) * 3);
	if (arr_toks == NULL)
	{
		fprintf(stderr, "Error: malloc fialed\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	while (--idx)
	{
		arr_toks[idx - 1] = NULL;
	}

	while (token)
	{
		if (idx < 3)
		{
			arr_toks[idx] = token;
		}
		token = strtok(NULL, delim); /* next token */
		idx++;
	}

	arr_toks[2] = NULL;

	return (arr_toks);
}
