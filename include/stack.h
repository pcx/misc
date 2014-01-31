#ifndef _STACK_H
#define _STACK_H

typedef struct element {
     char val;
     struct element *next, *prev;
} element;

typedef struct Stack{
     element *_head;
     char (*head)(struct Stack *st);
     void (*push)(struct Stack *st, char c);
     char (*pop)(struct Stack *st);
} Stack;

Stack *Stack_create();
char Stack_head(Stack *st);
void Stack_push(Stack *st, char c);
char Stack_pop(Stack *st);

#endif
