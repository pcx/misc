#include <stdio.h>

#include "linked_list.h"
#include "stack.h"


int main(int argc, char **argv)
{
     LinkedStack *st = Stack_create();
     printf("Created an empty stack data structure.\n");
     
     st->push(&(st->_head), 1);
     st->push(&(st->_head), 2);
     st->push(&(st->_head), 3);
     st->push(&(st->_head), 4);
     st->push(&(st->_head), 5);
     st->push(&(st->_head), 6);
     printf("Pushed numbers 1-6 onto the stack.\n");

     printf("Now emptying stack by poping all its elements:\n");
     for(int i = 1; ; i++) {
	  printf("element %d is %d.\n", i, st->pop(&(st->_head)));
	  if(!st->_head)
	       break;
     }

     return 0;
}
