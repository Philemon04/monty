#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 **/
void add(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		others_error(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub - Substrac the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 **/
void sub(stack_t **stack, unsigned int line_num)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		others_error(8, line_num, "sub");

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * multiply - multiplies the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 **/
void multiply(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	pop(doubly, cline);
}

/**
 * divide - Division the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 **/
void divide(stack_t **stack, unsigned int line_num)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		others_error(8, line_num, "div");

	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod - computes the rest of the division of the second element
 * by the top element of the stack
 **
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 **/
void mod(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", cline);
		free_nodes();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", cline);
		free_nodes();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	pop(doubly, cline);
}
