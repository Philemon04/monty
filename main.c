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
 * read_file - Reads the content of a file line by line.
 * @fd: Pointer to a file descriptor of an open file
 **/
void read_file(FILE *fd)
{
	int number_line;
	int format = 0;
	char *lineprt = NULL;
	size_t n = 0;

	if (fd == NULL)
		error_out(2, "file_name");
	/*Read line by line*/
	for (number_line = 1; getline(&lineprt, &n, fd) != EOF; number_line++)
	{
		format = interpret_line(lineprt, number_line, format);
	}
	free(lineprt);
}

/**
 * open_file - Opens a file.
 * @file_name: String with the name of the file.
 **/
void open_file(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
		error_out(2, file_name);
	/*Checks if the file exists*/
	file_check = access(file_name, R_OK);
	if (file_check == -1)
		error_out(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		error_out(2, file_name);
	/*errors should be handled inside this function*/
	read_file(fd);
	/*might need to check for errors on closing a file.*/
	fclose(fd);
}

/**
 * pint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 **/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		others_error(6, line_number);

	printf("%d\n", (*stack)->n);
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
