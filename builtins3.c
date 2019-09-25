#include "monty.h"

/**
 * div_m - divs 2dn top node by the top element of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void div_m(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		tokerr(op_e(line_number, "div"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		tokerr(op_e(line_number, "div"));
		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * mod_m - mod 2dn top node by the top element of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void mod_m(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		tokerr(op_e(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		tokerr(op_e(line_number, "mod"));
		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
