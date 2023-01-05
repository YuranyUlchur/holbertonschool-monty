#include "monty.h"
int sq_flag = 0;
/**
 * main - driver function for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&stack);
	}
	read_file(argv[1], &stack);
	free_dlistint(stack);
	return (0);
}
