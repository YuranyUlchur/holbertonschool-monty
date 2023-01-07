#include "monty.h"
/**
 * push_stack - Function that pushes an element to the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void push_stack(stack_t **top, unsigned int line_number)
{
	stack_t *new_node;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->next = *top;
	new_node->prev = NULL;
	new_node->n = take_num;
	if (*top)
		(*top)->prev = new_node;
	*top = new_node;
}
/**
 * pall_stack - Prints all values of stack, starting from top of stack.
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void pall_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	(void) line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint_stack - Function that print the valueat top of stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void pint_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", tmp->n);
}
/**
 * free_stack - Function that print the valueat top of stack
 * @top: element at the top of the stack (head)
 * Return: void
 */
void free_stack(stack_t **top)
{
	stack_t *tmp;

	if (top == NULL)
		return;

	tmp = *top;
	while (tmp)
	{
		*top = tmp->next;
		free(tmp);
		tmp = *top;
	}
}
