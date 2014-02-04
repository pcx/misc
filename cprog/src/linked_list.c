/*
  Linked List - data structure and utility functions.
*/

#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"


int head(linked_element *el)
{
     return el->val;
}

void push(linked_element **el, int i)
{
     linked_element *_el = *el;
     if(!_el->set) {
	  _el->val = i;
	  _el->set = true;
     } else {
	  linked_element *el_new = malloc(sizeof(linked_element));
	  el_new->prev = NULL;
	  el_new->next = _el;
	  el_new->val = i;
	  el_new->set = true;

	  _el->prev = el_new;

	  *el = el_new;
     }
}

int pop(linked_element **el)
{
     linked_element *_el = *el;
     int i;
     if(_el->set) {
	  i = _el->val;
	  if(_el->next) {
	       *el = _el->next;
	  } else {
	       *el = NULL;
	       free(_el);
	  }
	  return i;
     } else {
	  return 0;
     }
}


