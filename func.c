#include "monty.h"
/**
 * push - adds an element to the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the file
 * @file: file to read the opcode from
 */
void push(stack_t **stack, unsigned int line_number, FILE *file)
{
    int n;
    stack_t *new;
    char *opcode;

    if (!stack)
    {
        fprintf(stderr, "L%u: can't push, stack is NULL\n", line_number);
        exit(EXIT_FAILURE);
    }

    // read next opcode
    opcode = malloc(sizeof(char) * 1024);
    if (!opcode)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    if (fscanf(file, "%s", opcode) == EOF)
        return;

    n = atoi(opcode);
    if (n == 0 && strcmp(opcode, "0") != 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = n;
    new->prev = NULL;
    new->next = *stack;
    if (*stack)
        (*stack)->prev = new;
    *stack = new;

    free(opcode);
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the command in the file (unused)
 * @file: file to read the opcode from (unused)
 */
void pall(stack_t **stack, unsigned int line_number, FILE *file)
{
    stack_t *current;

    (void)line_number;
    (void)file;

    if (!stack || !*stack)
        return;

    current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
