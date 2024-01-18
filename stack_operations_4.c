#include "monty.h"


/**
 * pchar - Prints the char at the top of the stack, followed by a new line.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current->n < 0 || current->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current->n);
}

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (current && current->next)
	{
		while (current->next != NULL)
			current = current->next;

		current->next = *stack;
		(*stack)->prev = current;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (current && current->next)
	{
		while (current->next != NULL)
			current = current->next;

		current->prev->next = NULL;
		current->prev = NULL;
		current->next = *stack;
		(*stack)->prev = current;
		*stack = current;
	}
}
