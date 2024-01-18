#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n += current->n;
	pop(stack, line_number);
}

/**
 * nop - Doesn't do anything.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
