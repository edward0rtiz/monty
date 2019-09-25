#include "monty.h"

/**
 * get_builtin - Parses the instruction with the function.
 * @token: type pointer extern var char
 * @stack: type pointer node of data struct
 * @line_number: line of instructions
 * Return: Retunr the funtion
 */
void *get_builtin(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_built[] = {
		{ "push", push },
		{ "pall", pall},
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "mul", mul},
		{ "div", div_m },
		{ "pchar", pchar },
		{ "mod", mod_m },
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
