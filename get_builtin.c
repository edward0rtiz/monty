#include "monty.h"

void (*get_builtin(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_built[] = {
		{ "push", push },
		/*	{ "pall", pall }, */
		{ "pall", pall},
		{ NULL, NULL }
	};
	int i;

	for (i = 0; op_built[i].opcode; i++)
	{
		if (strcmp(opcode, op_built[i].opcode) == 0)
			return (op_built[i].f);
	}
	return;
}
