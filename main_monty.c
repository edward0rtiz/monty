#include "monty.h"

char **opcodetk = NULL;

int main(int argc, char **argv)
{
	FILE *fd = NULL;
	int exit_val = EXIT_SUCCESS;

	if (argc != 2)
/* error function */
		return (0);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
/* error function */
		return (0);
	exit_val = cmd_monty(fd);
	fclose(fd);
	return (exit_val);
}
