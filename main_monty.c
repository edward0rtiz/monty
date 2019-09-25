#include "monty.h"

char *token2 = NULL;

/**
 * main - entry point for the CLI program
 * @argc: count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	FILE *fd = NULL;
	char *line_buf = NULL;
	char *token = NULL;
	size_t line_buf_size = 0;
	int line_number = 0;
	ssize_t line_size;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (stderr_fopen(argv[1]));
	line_size = getline(&line_buf, &line_buf_size, fd);
	while (line_size >= 0)
	{
		line_number++;
		token = strtok(line_buf, DELIM);
		token2 = strtok(NULL, DELIM);
		get_builtin(token, &stack, line_number);
		line_size = getline(&line_buf, &line_buf_size, fd);

	}
	free(line_buf);
	line_buf = NULL;
	fclose(fd);
	return (EXIT_SUCCESS);
}
