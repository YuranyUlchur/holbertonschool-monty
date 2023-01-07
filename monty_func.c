#include "monty.h"
/**
 * is_number - checks if is a number
 * @token: string to check id is a number
 * Return: 0
 */
int is_number(char *token)
{
	int i;

	if (token == NULL)
		return (-1);
	for (i = 0; token[i] != '\0'; i++)
	{
		if (!(token[i] >= '0' && token[i] <= '9') && token[i] != '-')
			return (-1);
	}
	return (0);
}
/**
 * open_file_to_read - Open a monty files
 * @filename: Name if monty file
 * @stack: Structure
 * Return: 0
 */
int open_file_to_read(char *filename, stack_t **stack)
{
	FILE *in_file;
	char *token = NULL, *buff_line = NULL, *number = NULL;
	unsigned int line_counter = 0;
	size_t buff_size;

	in_file = fopen(filename, "r");
	if (in_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buff_line, &buff_size, in_file) != EOF)
	{
		token = strtok(buff_line, "\n\t\r ");
		number = strtok(NULL, "\n\t\r ");
		line_counter++;
		if (token && token[0] != '#')
		{
			if (strcmp(token, "push") == 0)
			{
				if (is_number(number) == -1)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_counter);
					_free(buff_line, in_file);
				}
				take_num = atoi(number);
			}
			/* printf("token = %s, number = %d\n", token, take_num); */
			if (get_opcode(token, line_counter, stack) == 1)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_counter, token);
				_free(buff_line, in_file);
				free_stack(stack);
			}
		}
	}
	free(buff_line);
	free_stack(stack);
	fclose(in_file);
	return (0);
}
/**
 * _free - Free line, close file and exit
 * @buff_line:line
 * @in_file: file
 * Return: 0
 */
void _free(char *buff_line, FILE *in_file)
{
	free(buff_line);
	fclose(in_file);
	exit(EXIT_FAILURE);
}
