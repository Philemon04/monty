#include "monty.h"
stack_t *head = NULL;

/**
 * free_nodes - Frees nodes in the stack.
 * return : void
 **/
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * new_node - Creates and populates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */

stack_t *new_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_out(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * main - Entry to the program
 * @argc: Number of command line arguments.
 * @argv: An array containing the arguments.
 * Return: Always Zero.
 **/
int main(int argc, char **argv)
{
	/*argc must be 2*/
	if (argc < 2 || argc > 2)
		error_out(1);
	open_file(argv[1]);
	/*Free memory*/
	free_nodes();
		return (0);
}
