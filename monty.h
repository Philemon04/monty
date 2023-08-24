#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/*Type for opcode functions*/
typedef void (*op_func)(stack_t **, unsigned int);

void push(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void divide(stack_t **stack, unsigned int line_num);
void multiply(stack_t **doubly, unsigned int cline);
void mod(stack_t **doubly, unsigned int cline);

/*Error hanlding*/
void error_out(unsigned int error_code, ...);
void others_error(unsigned int error_code, ...);

void search_func(char *, char *, int, int);
void add_to_queue(stack_t **, unsigned int);
void open_file(char *);
void read_file(FILE *);
int len_chars(FILE *);
int interpret_line(char *, int, int);
stack_t *new_node(int n);
void free_nodes(void);

#endif
