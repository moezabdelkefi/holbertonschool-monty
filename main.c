#include "monty.h"
int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};
    char *opcode;
    unsigned int line_number;
    int i;
    FILE *file;

    if (argc != 2)
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

    // parse commands from file
    for (line_number = 1; /* loop until EOF or error */; line_number++)
    {
        opcode = malloc(sizeof(char) * 1024);
        if (!opcode)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }

        // read next opcode
        if (fscanf(file, "%s", opcode) == EOF)
            break;

        // find and execute instruction
        for (i = 0; instructions[i].opcode; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number, file);
                break;
            }
        }
        if (!instructions[i].opcode)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        free(opcode);
    }

    fclose(file);
    return (EXIT_SUCCESS);
}
