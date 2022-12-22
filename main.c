#include "monty.h"
/**
 *main - make tee not love
 *@argc: is an integer representing the number of arguments
 *@argv: is an array of sring representing the arguments
 *Return: (EXIT_SUCCESS)
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}};
	char *opcode;
	int i;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *fp;
	char *line = NULL;
	size_t len = 0;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, fp) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(instructions[i].opcode, opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}

		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_stack(stack);
			return (EXIT_FAILURE);
		}
	}

	free(line);
	fclose(fp);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
