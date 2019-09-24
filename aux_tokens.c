#include "monty.h"

void free_tok(void)
{
	size_t i = 0;

	if (opcodetk == NULL)
		return;
	for (i = 0; opcodetk[i]; i++)
		free(opcodetk[i]);

	free (opcodetk);
}
unsigned int array_len(void)
{
	unsigned int token_len = 0;

	while (opcodetk[token_len])
		token_len++;
	return (token_len);
}

/* check delim in getline */

int no_line(char *line, char *delim)
{
	int a, b;

	for (a = 0; line[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (line[a] == delim[b])
				break;
		}
		if (delim[b] == '\0')
			return (0);
	}

	return (1);
}
