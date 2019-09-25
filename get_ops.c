#include "monty.h"

void *get_builtin(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_built[] = {
		{ "push", push },
<<<<<<< HEAD
		{ "pall", pall},
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
=======
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
>>>>>>> 6c8bdaac6be1ba155639c39559faa0b9ad0309eb
		{ NULL, NULL }
	};
	int i;
	char *argumentos = NULL;
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
