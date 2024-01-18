#include "monty.h"

/**
 * initialize_instructions - Initializes the opcode-function pairs.
 * @instructions: An array of instruction_t structures to be initialized.
 *
 * Description: Populates the instruction set with opcode-function pairs.
 * Add opcode-function pairs to the instructions array as needed.
 */
void initialize_instructions(instruction_t *instructions)
{
	instructions[0].opcode = "push";
	instructions[0].f = push;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pint";
	instructions[2].f = pint;
	instructions[3].opcode = "pop";
	instructions[3].f = pop;
}
