#include "monty.h"

char **token = NULL;

int main(int argc, char **argv)
{
	FILE *fd = NULL;
	int exit_val = EXIT_SUCCESS;

	if (argc != 2)
		return (stderr_usage());
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (stderr_fopen(argv[1]));
	exit_val = cmd_monty(fd);
	fclose(fd);
	return (exit_val);
}
