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
	instructions[4].opcode = "swap";
	instructions[4].f = swap;
	instructions[5].opcode = "add";
	instructions[5].f = add;
	instructions[6].opcode = "nop";
	instructions[6].f = nop;
	instructions[7].opcode = "sub";
	instructions[7].f = sub;
	instructions[8].opcode = "div";
	instructions[8].f = div_op;
	instructions[9].opcode = "mul";
	instructions[9].f = mul;
	instructions[10].opcode = "mod";
	instructions[10].f = mod;
}
