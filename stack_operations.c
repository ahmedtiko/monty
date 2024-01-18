#include "monty.h"

/**
 * push_stack - Pushes a new node with a given value onto the stack.
 * @stack: A pointer to the top of the stack.
 * @value: The value to be pushed onto the stack.
 * Return: A pointer to the newly created node.
 */
stack_t *push_stack(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return NULL;

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
	return (new_node);
}

/**
 * is_integer - Checks if a string represents an integer.
 * @str: The string to be checked.
 * Return: 1 if the string is an integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	if (!str || *str == '\0')
		return 0;

	while (*str)
	{
		if (!isdigit(*str) && (*str != '-' || str != 0))
			return 0;
		str++;
	}

	return (1);
}

/**
 * free_stack - Frees the memory allocated for the stack.
 * @stack: A pointer to the top of the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *current, *next;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
