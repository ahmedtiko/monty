#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;

	arg = strtok(NULL, " \n");
	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	if (!push_stack(stack, value))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: Unused parameter for consistency with opcode function signature.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
