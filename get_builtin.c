#include "monty.h"

void (*get_builtin(char *opcode))(stack_t**, unsigned int)
{
	commands_t op_built[] = {
		{"push", builtin_push},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_function[i].opcode; i++)
	{
		if (strcmp(opcode, op_built[i].opcode) == 0)
			return (op_built[i].f);
	}
	return (NULL);
}
