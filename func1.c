#include "monty.h"
/**
 * pop - remove the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack;

	*stack = top->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(top);
}
/**
 * swap - swap the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack;
	stack_t *second = top->next;

	top->prev = second;
	top->next = second->next;
	if (second->next)
		second->next->prev = top;
	second->prev = NULL;
	second->next = top;
	*stack = second;
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
/**
 * add - add the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack;
	stack_t *second = top->next;
	second->n += top->n;
	second->prev = NULL;
	*stack = second;
	free(top);
}
