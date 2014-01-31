#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


char Stack_head(Stack *st)
{
     return st->_head->val;
}

void Stack_push(Stack *st, char c)
{
     if(st->_head->val == '\0') {
	  st->_head->val = c;
     } else {
	  element *el = malloc(sizeof(element));
	  el->next = st->_head;
	  el->prev = NULL;
	  el->val = c;
	  
	  st->_head = el;
     }
}

char Stack_pop(Stack *st)
{
     char c;
     if(st->_head) {
	  c = st->_head->val;
	  if(st->_head->next) {
	       st->_head = st->_head->next;
	  } else {
	       st->_head = NULL;
	  }
	  return c;
     } else {
	  return '\0';
     }
}


Stack *Stack_create()
{
     Stack *st = (Stack *) malloc(sizeof(Stack));
     st->_head = (element *) malloc(sizeof(element));
     st->_head->val = '\0';
     st->_head->next = NULL;
     st->_head->prev = NULL;
     
     st->head = Stack_head;
     st->push = Stack_push;
     st->pop = Stack_pop;


     return st;
}
