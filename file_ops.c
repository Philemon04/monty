#include "monty.h"

/**
 * interpret_line - interpret each line by separating it one by one
 * @string: String on the line to be read
 * @line_number: line number for the opcode.
 * @format: Format specifier:
 * If the value is 0 --> Stack
 * If the value is 1 --> Queue
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 **/
int interpret_line(char *string, int line_number, int format)
{
	char *opcode;
	char *cmd;
	const char *delim;

	delim = "\n ";
	/*Handle error*/

	if (string == NULL)
		error_out(4);
	/*Read command line by line*/
	opcode = strtok(string, delim);

	/*hanlding blank lines*/
	if (opcode == NULL)
		return (format);

	/*tokens*/
	cmd = strtok(NULL, delim);
	/*compare two strings --> return queue or stack*/
	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	search_func(opcode, cmd, line_number, format);
	return (format);
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
