#include "monty.h"

/**
 * push - Add node to the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void push(stack_t **stack, unsigned int line_number)
{

	stack_t *node = NULL;
	int n = 0;

	if (*stack  == NULL)
	{
		node = create_node_stackfirst(&node, line_number);
	}
	else
	{
		node = create_node_stackend(&node, line_number);
	}
}

/**
* pall - Print the stack
* @stack: head of linkedlist
* @line_number: line number of the instruction
*
* Return: No return
*/
void pall(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;

	if (stack == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d", temp->n);
		temp = temp->prev;
		printf("\n");
	}
}

/**
* pint - Print the stack
* @stack: head of linkedlist
* @line_number: line number of the instruction
*
* Return: No return
*/
void pint(stack_t **stack, unsigned int line_number)
{





}
