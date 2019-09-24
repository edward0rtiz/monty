#include "monty.h"

int cmd_monty(FILE *fd)
{
	size_t len = 0, exit_s = EXIT_SUCCESS;
	unsigned int lnum = 0, tok_len = 0;
	char *ln = NULL;
	stack_t *stack = NULL;
	void (*op_function)(stack_t **, unsigned int);

	while (getline(&ln, &len, fd))
	{
		lnum++;
		opcodetk = strtow(ln, DELIM);
		if (opcodetk == NULL)
		{
			if (no_line(ln, DELIM))
				continue;
			free_node_stack(&stack);
			return (0); /*null error */
		}
		op_function = get_builtin(opcodetk[0]);
		if (op_function == NULL)
		{
			free_node_stack(&stack);
			exit_s; /* error check */
			free_tok(); /* free token */
			break;
		}
		tok_len = array_len();
		op_function(&stack, lnum);
		if (array_len() != tok_len)
		{
			if (opcodetk && opcodetk[tok_len])
				exit_s = atoi(opcodetk[tok_len]);
			else
				exit_s = EXIT_FAILURE;
			free_tok(); /*free tok */
			break;
		}
		free_tok(); /*free tok */
	}
	free_node_stack(&stack);
	if (ln && *ln == 0)
	{
		free(ln);
		return (0); /*error */
	}
	free(ln);
	return (exit_s);
}
