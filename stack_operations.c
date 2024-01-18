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

/**
 * execute_instruction - Parses the line and executes the corresponding opcode function.
 * @line: The line containing the opcode and, if applicable, arguments.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file where the opcode appears.
 * @instructions: An array of instruction_t structures representing opcode-function pairs.
 */
void execute_instruction(char *line, stack_t **stack, unsigned int line_number, instruction_t *instructions)
{
	char *opcode;
	int i;

	if (line == NULL || line[0] = '#' || line[0] == '\n')
		return;

	opcode = strtok(line, " \t\n");

	if (opcode == NULL)
		return;

	for (i = 0; i < NUM_OPCODES; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			/* Found a matching opcode, execute the corresponding function */
			instructions[i].f(stack, line_number);
			return;
		}
	}

	/* If no matching opcode is found, print an error message and exit */
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
