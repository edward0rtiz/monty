#include "monty.h"

int create_node_stack(stack_t **stack)
{
	stack_t *node_stack;

	node_stack = malloc(sizeof(stack_t));
	if (node_stack == NULL)
/* has to be an error of malloc */
		return (0);

	node_stack->n = STACK;
	node_stack->prev = NULL;
	node_stack->next = NULL;

	*stack = node_stack;

	return  (EXIT_SUCCESS);
}

void free_node_stack(stack_t **stack)
{
	stack_t *temp_node = *stack;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;
	}
}

int check_opcode(stack_t *stack)
{
	int ret_val = 2;

	if (stack->n == STACK)
		return (STACK);
	else if(stack->n == QUEUE)
		return (QUEUE);
	return (ret_val)
}
