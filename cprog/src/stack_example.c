#include <stdio.h>

#include "stack.h"


int main(int argc, char **argv)
{
     Stack *st = Stack_create();
     printf("Created an empty stack data structure.\n");
     
     st->push(st, 'f');
     st->push(st, 'o');
     st->push(st, 'o');
     st->push(st, 'b');
     st->push(st, 'a');
     st->push(st, 'r');
     printf("Pushed the letters of the word 'foobar' onto the stack.\n");

     printf("Now emptying stack by poping all its elements:\n");
     for(int i = 1; ; i++) {
	  printf("element %d is %c.\n", i, st->pop(st));
	  if(!st->_head)
	       break;
     }

     return 0;
}
