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

	if (!_isdigit(token2) || stack == NULL)
		stderr_int(line_number);
	n = atoi(token2);
	if ( n == 0 || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
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
		stderr_int(line_number);
	if (*stack == NULL)
		stderr_int(line_number);
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d", temp->n);
		temp = temp->prev;
		printf("\n");
	}
	printf("%d\n", temp->n);
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

	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
<<<<<<< HEAD
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (EXIT_FAILURE);
=======
		tokerr(pint_e(line_number));
		return;
>>>>>>> c550f6139c4aa62f0bcb7a27baedab1e6ef564f1
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	printf("%d", temp->n);
	printf("\n");
}

/**
 * swap - Print the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void swap(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	stack_t *temp3 = NULL;
	int j = 0;
	int i = 0;

<<<<<<< HEAD
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't %s, stack too short\n",
			line_number, "swap");
		return (EXIT_FAILURE);
	}
=======
	if (*stack == NULL || stack == NULL)
		op_e(line_number, "swap");
>>>>>>> c550f6139c4aa62f0bcb7a27baedab1e6ef564f1
	if (stack == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i >= 1)
	{
		temp3 = temp2->prev;
		temp2->prev = temp;
		temp2->next = NULL;
		temp->next = temp2;
		temp->prev = temp3;
	}
	else
		op_e(line_number, "swap");
}
/**
 * nop - does not do anything
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
