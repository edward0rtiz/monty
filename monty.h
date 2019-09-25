#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>



#define QUEUE 1
#define STACK 0
#define DELIM " \n\t\a\b"

extern char *token2;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* aux functions */
stack_t *create_node_stackfirst(stack_t **stack, int n);
stack_t *create_node_stackend(stack_t **stack, int n);
void free_node_stack(stack_t **stack);
int check_opcode(stack_t *stack);

/* builtins functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
/*void pint(stack_t **stack, unsigned int line_number);*/
/* monty exe */
int cmd_monty(FILE *fd);
/* main.c */
int main(int argc, char **argv);
/* get_builtin */
void *get_builtin(char *token, stack_t **stack, unsigned int line_number);
/* aux tokens */
void free_tok(void);
unsigned int array_len(void);
int no_line(char *line, char *delim);
/* aux_str 
int check_delim(char stream, char *delim);
int wstrlen(char *str, char *delim);
int wcounter(char *str, char *delim);
char **strtow(char *str, char *delim);
char *wnext(char *str, char *delim);
*/
/* aux_stack */
/*int create_node_stack(stack_t **stack);*/
void free_node_stack(stack_t **stack);
int check_opcode(stack_t *stack);

stack_t *create_node_stackfirst(stack_t **stack, int n);
stack_t *create_node_stackend(stack_t **stack, int n);

/*error*/
int stderr_usage(void);
int stderr_malloc(void);
int stderr_fopen(char *fd);
int stderr_unknown(char *opcode, unsigned int line_number);
int stderr_int(unsigned int line_number);


#endif
