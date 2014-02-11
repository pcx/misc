#include <stdio.h>
#include <stdlib.h>

#include "dbg.h"
#include "linked_list.h"
#include "stack.h"


int main(int argc, char **argv)
{
     LinkedStack *st = Stack_create();
     check_mem(st);
     log_info("Created an empty stack data structure.\n");

     for(int i = 1; i <= 6; i++) {
	  if(st->push(&(st->_head), i) != 0)
	       sentinel("Failed to push onto stack.");
     }
     log_info("Pushed numbers 1-6 onto the stack.\n");

     log_info("Now emptying stack by poping all its elements:\n");
     int i, v = 0;
     for(i = 1; ; i++) {
	  v = st->pop(&(st->_head));
	  if(!clean_errno()) {
	       sentinel("Failed to pop off the stack. Something's wrong.");
	  }

	  log_info("element %d is %d.\n", i, v);
	  if(!st->_head)
	       break;
     }
     if(st) free(st);
     return 0;
error:
     if(st) free(st);
     return -1;
}
