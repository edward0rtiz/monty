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

	int n = 0;

	n = atoi(token2);
	if (*stack  == NULL)
	{
		create_node_stackfirst(stack, n);
	}
	else
	{
		create_node_stackend(stack, n);
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
	printf("%d", temp->n);
}


/**
* pint - Print the stack
* @stack: head of linkedlist
* @line_number: line number of the instruction
*
* Return: No return
*/
/*void pint(stack_t **stack, unsigned int line_number)
{





}*/

/*void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *temp_node;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return;
	}

	if (token[1] == NULL)
	{
		return;
	}

	for (i = 0; token[1][i]; i++)
	{
		if (token[1][i] == '-' && i == 0)
			continue;
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			return;
		}
	}
	new_node->n = atoi(token[1]);


	if (check_opcode(*stack) == STACK)
	{
		temp_node = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = temp_node;
		if (temp_node)
			temp_node->prev = new_node;
		(*stack)->next = new_node;
	}
	else
	{
		temp_node = *stack;
		while (temp_node->next)
			temp_node = temp_node->next;
		new_node->prev = temp_node;
		new_node->next = NULL;
		temp_node->next = new_node;
	}
	}*/
