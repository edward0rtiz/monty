#include "monty.h"


/**
 * stderr_usage - usage error.
 * Return: EXIT_FAILURE
 */
int stderr_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * stderr_malloc - Prints malloc error messages.
 * Return: EXIT_FAILURE
 */

int stderr_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * stderr_fopen - error of fopen.
 * @filename: type pointer char of filename
 * Return: EXIT_FAILURE
 */
int stderr_fopen(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
/**
 * stderr_int - error of int.
 * @line_number: type pointer of line number
 * Return: EXIT_FAILURE
 */
int stderr_int(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * stderr_unknown - unknown error messagess.
 * @line_number: line number of the instruction.
 * @token: type pointer char of the instruction.
 * Return: EXIT_FAILURE
 */
int stderr_unknown(char *token, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	return (EXIT_FAILURE);
}
