#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n -= current->n;
	pop(stack, line_number);
}

/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n /= current->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n *= current->n;
	pop(stack, line_number);
}

/**
 * mod - Computes the rest of the division of the second top element by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n %= current->n;
	pop(stack, line_number);
}
