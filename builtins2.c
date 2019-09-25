#include "monty.h"

/**
 * pop - Add node to the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (stack == NULL)
		return;
	if (*stack == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
	{

		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
/**
 * add - adds the top two elements of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		tokerr(op_e(line_number, "add"));
		return;
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		return;
	else
	{
		temp2->n = temp2->n + temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}

}
/**
 * sub - subtracts the top e of stack from the 2nd top element of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */

void sub(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		tokerr(op_e(line_number, "sub"));
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		return;
	else
	{
		temp2->n = temp2->n - temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
/**
 * mul - Mul 2nd val from top of a stack_t by top value.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
*/
void mul(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		tokerr(op_e(line_number, "mul"));
		return;
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		return;
	else
	{
		temp2->n = temp2->n * temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}

}
/**
 * pchar - Print char.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	if ((*stack)->next == NULL)
	{
		tokerr(pchar_e(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		tokerr(pchar_e(line_number, "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
