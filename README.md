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
                                  
                                  
### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files:

   ![Capture d’écran 2022-12-22 041036 mo](https://user-images.githubusercontent.com/113900578/209146633-52fb7ccf-8616-49fd-ac28-30ac4fe616be.png)

                    
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

   ![Capture d’écran 2022-12-22 041135](https://user-images.githubusercontent.com/113900578/209146781-1894b233-9334-4f4b-8aa1-35d657a9dc45.png)

### The monty program:

Usage: monty file
where file is the path to the file containing Monty byte code
If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number where the instruction appears.
Line numbers always start at 1
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured
If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
