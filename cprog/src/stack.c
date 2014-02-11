#include <stdio.h>
#include <stdlib.h>

#include "dbg.h"
#include "stack.h"
#include "linked_list.h"


LinkedStack *Stack_create()
{
     LinkedStack *st = (LinkedStack *) malloc(sizeof(LinkedStack));
     check_mem(st);

     st->_head = (linked_element *) malloc(sizeof(linked_element));
     check_mem(st->_head);

     st->_head->val = 0;
     st->_head->set = false;
     st->_head->next = NULL;
     st->_head->prev = NULL;
     
     st->head = head;
     st->push = push;
     st->pop = pop;
     st->size = size;

     return st;

error:
     if(st) free(st);
     return NULL;
}
