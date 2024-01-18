#include "monty.h"

/**
 * main - Monty program entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	instruction_t *instructions;

	if (argc !=2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	instructions = malloc(sizeof(instruction_t) * NUM_OPCODES);
	if (!instructions)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	/* Populate the instruction set with opcode-function pairs */
	initialize_instructions(instructions);

	while ((read = getline(&line, &len, file)) != -1)
	{
		execute_instruction(line, &stack, line_number, instructions);
		line_number++;
	}

	free(line);
	fclose(file);
	free_stack(&stack);
	free(instructions);

	return (EXIT_SUCCESS);
}
