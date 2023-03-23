#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define DELIM " \t"
#define MAX_LINE_LEN 1024
#define MAX_TOKENS 128

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 *
 * Description: opcode and its function
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct global_s
{
        char *n;
} global_t;

extern char *tokens[MAX_TOKENS];
extern char *line;
extern char *stack;
extern char *queue;
extern char *stack_mode;
extern char *queue_mode;
extern char *mode;
extern char *filename;
extern char *opcode;
extern char *arg;
extern char *line_number;
extern char *line_number_str;
extern int line_number_int;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

void free_stack(stack_t *stack);
void free_tokens(void);
void free_line(void);
void free_all(void);

void get_opcode(stack_t **stack, unsigned int line_number);
void get_arg(stack_t **stack, unsigned int line_number);
void get_line_number(stack_t **stack, unsigned int line_number);
void get_line_number_str(stack_t **stack, unsigned int line_number);
void get_line_number_int(stack_t **stack, unsigned int line_number);

void get_filename(stack_t **stack, unsigned int line_number);
void get_stack(stack_t **stack, unsigned int line_number);
void get_queue(stack_t **stack, unsigned int line_number);
void get_stack_mode(stack_t **stack, unsigned int line_number);
void get_queue_mode(stack_t **stack, unsigned int line_number);
void get_mode(stack_t **stack, unsigned int line_number);

void get_line(stack_t **stack, unsigned int line_number);
void get_tokens(stack_t **stack, unsigned int line_number);

void (*get_func(char *s))(stack_t **stack, unsigned int line_number);

#endif
