#include "monty.h"

stack_t *create_node_stackfirst(stack_t **stack, int n)
{
	stack_t *newnode_stack;

	if (stack == NULL)
/* has to be an error of malloc */
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		return NULL;
	newnode_stack->n = n;
	newnode_stack->next = *stack;
	newnode_stack->prev = NULL;
	*stack = newnode_stack;
	return (newnode_stack);
}

stack_t *create_node_stackend(stack_t **stack, int n)
{
	stack_t *newnode_stack;
	stack_t *temp;

	if (stack == NULL)
	/* has to be an error of malloc */
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		return NULL;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode_stack;
	newnode_stack->prev = temp;
	newnode_stack->next = NULL;
	return (newnode_stack);
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
	return (ret_val);
}
