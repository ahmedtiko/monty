#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	(void)line_number;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *prev = NULL;

	(void)line_number;

	while (current && current->next != NULL)
	{
		prev = current;
		current = current->next;
	}

	if (prev != NULL)
	{
		prev->next = NULL;
		current->next = *stack;
		(*stack)->prev = current;
		*stack = current;
	}
}
