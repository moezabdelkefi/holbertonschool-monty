#include "monty.h"
/**
 * push - push an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n;

	if (!stack)
		return;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (sscanf(strtok(NULL, " \n"), "%d", &n) != 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - print all the values on the stack, starting from the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack || !*stack)
		return;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}
#include "monty.h"

/**
 * pint - print the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * free_stack - free the memory used by the stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current, *next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
