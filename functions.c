#include "monty.h"

/**
 * push- Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_number: Interger representing the line number of of the opcode.
 **/
void push(stack_t **new_node, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	tmp->prev = NULL;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 **/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		others_error(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - Swap element 1 for element 2 of the stack
 * @stack: points to the top node of the stack.
 * @line_num: opcode line number.
 **/
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		others_error(8, line_num, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * nop - does nothing
 * @stack: top of the stack
 * @line_num: current line number
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)*stack;
	(void)line_num;
}

/**
 * pall - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
