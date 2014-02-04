#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "linked_list.h"


LinkedStack *Stack_create()
{
     LinkedStack *st = (LinkedStack *) malloc(sizeof(LinkedStack));
     st->_head = (linked_element *) malloc(sizeof(linked_element));
     st->_head->val = 0;
     st->_head->set = false;
     st->_head->next = NULL;
     st->_head->prev = NULL;
     
     st->head = head;
     st->push = push;
     st->pop = pop;

     return st;
}
