#include "monty.h"

int cmd_monty(FILE *fd)
{
	size_t len = 0, exit_s = EXIT_SUCCESS;
	unsigned int lnum = 0, tok_len = 0;
	char *ln = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	while (getline(&ln, &len, fd) != -1)
	{
		lnum++;
		token = strtow(ln, DELIM);
		if (token == NULL)
		{
			if (no_line(ln, DELIM))
				continue;
			free_node_stack(&stack);
			return (stderr_malloc());
		}
		get_builtin(token, &stack, lnum);
		if (get_builtin(token, &stack, lnum) == NULL)
		{
			free_node_stack(&stack);
			exit_s = stderr_unknown(token[0], lnum);
			free_tok();
			break;
		}
		tok_len = array_len();
				if (array_len() != tok_len)
		{
			if (token && token[tok_len])
				exit_s = atoi(token[tok_len]);
			else
				exit_s = EXIT_FAILURE;
			free_tok();
			break;
		}
		free_tok();
	}
	free_node_stack(&stack);
	if (ln && *ln == 0)
	{
		free(ln);
		return (stderr_malloc());
	}
	free(ln);
	return (exit_s);
}
