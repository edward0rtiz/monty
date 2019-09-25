#include "monty.h"

void *get_builtin(char **token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_built[] = {
		{ "push", push },
		{ "pall", pall},
		{ NULL, NULL }
	};
	int i;
	char **argumentos = NULL;
	argumentos = token;

	for (i = 0; op_built[i].opcode; i++)
	{
		if (strcmp(argumentos, op_built[i].opcode) == 0)
		{
			op_built[i].f(stack, line_number);
			break;
		}
	}
}
