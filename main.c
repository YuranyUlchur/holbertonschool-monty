#include "monty.h"
/**
 * main - main entry
 * @argc: Total of arguments
 * @argv: Arguments, monty file
 * Return: int
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file_to_read(argv[1], &stack);
	return (0);
}
