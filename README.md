<h1 align="center">holbertonschool-monty</h1>

## description:

A stack is a linear data structure that follows the Last In First Out (LIFO) principle. This means that the last element added to the stack will be the first one to be removed. Stacks can be implemented using an array or a linked list.

A queue is a linear data structure that follows the First In First Out (FIFO) principle. This means that the first element added to the queue will be the first one to be removed. Queues can also be implemented using an array or a linked list.

## More Info :
### Data structures:
                      Please use the following data structures for this project. Don’t forget to include them in your header file.

                      /**
                      * struct stack_s - doubly linked list representation of a stack (or queue)
                      * @n: integer
                      * @prev: points to the previous element of the stack (or queue)
                      * @next: points to the next element of the stack (or queue)
                      * Description: doubly linked list node structure
                      * for stack, queues, LIFO, FIFO
                      */
                       typedef struct stack_s
                       {
                            int n;
                            struct stack_s *prev;
                            struct stack_s *next;
                        } stack_t;
                            
                        /**
                        * struct instruction_s - opcode and its function
                        * @opcode: the opcode
                        * @f: function to handle the opcode
                        * Description: opcode and its function
                        * for stack, queues, LIFO, FIFO
                        */
                        typedef struct instruction_s
                        {
                            char *opcode;
                            void (*f)(stack_t **stack, unsigned int line_number);
                        } instruction_t;
                             
### Compilation & Output:

                                  $ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
                                  
                                  
