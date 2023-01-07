#include "monty.h"

/**
 * pop_stack - Function that pop (delete) the value at top of stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void pop_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = tmp->next;
	free(*top);
	*top = tmp;
}

/**
 * swap_stack - Function that pushes an element to the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void swap_stack(stack_t **top, unsigned int line_number)
{
	stack_t *node_1_swap, *node_2_swap;

	node_1_swap = *top;
	if (*top && (*top)->next)
	{
		node_2_swap = node_1_swap->next; /* Address of second node*/
		node_1_swap->prev = node_1_swap->next;
		node_1_swap->next = node_2_swap->next;
		if (node_2_swap->next) /* if node_3 exist */
			(node_2_swap->next)->prev = node_1_swap;
		node_2_swap->prev = NULL;
		node_2_swap->next = node_1_swap;
		*top = node_2_swap;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _add - Function that adds the top two elements of the stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 */
void _add(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n += (*top)->n;
	pop_stack(top, line_number);
}
/**
 * _nop - Function that doesnt do anything
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _nop(stack_t **top, unsigned int line_number)
{
	(void) top;
	(void) line_number;
}