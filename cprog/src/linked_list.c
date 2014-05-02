/*
  Linked List - data structure and utility functions.
*/

#include <stdlib.h>
#include <stdbool.h>

#include "dbg.h"
#include "linked_list.h"


int head(linked_element *el)
{
     check(el, "Cannot access property of a null pointer.");
     return el->val;
error:
     return -1;
}

int size(linked_element *el)
{
     if(!el) {
	  return 0;
     } else {
	  int i = 1;
	  while(1) {
	       if(el->next) {
		    i++;
		    el = el->next;
	       } else {
		    break;
	       }
	  }
	  return i;
     }
}

int push(linked_element **el, int i)
{
     check(el, "Invalid pointer to *linked_element.");

     linked_element *_el = *el;
     check(_el, "Empty pointer to linked_element.");

     if(!_el->set) {
	  _el->val = i;
	  _el->set = true;
     } else {
	  linked_element *el_new = malloc(sizeof (linked_element));
	  check_mem(el_new);

	  // set properties of el_new
	  el_new->prev = NULL;
	  el_new->next = _el;
	  el_new->val = i;
	  el_new->set = true;

	  // setup pointer to el_new from _el
	  _el->prev = el_new;

	  // make el_new the new head of the list
	  *el = el_new;
     }
     return 0;
error:
     return -1;
}

linked_element *get_tail(linked_element *el)
{
/*
  Traverse a linked list and return reference to list's tail.
 */
     while(1) {
	  if(el && el->next) {
	       el = el->next;
	  } else {
	       return el;
	  }
     }
}

int inject(linked_element **el, int i)
{
     check(el, "Invalid pointer to *linked_element.");

     linked_element *_el = *el;
     check(_el, "Empty pointer to linked_element.");

     linked_element *tail_element = get_tail(_el);
     if(tail_element && !tail_element->set) {
	  tail_element->val = i;
	  tail_element->set = true;
	  return 0;
     } else {
	  linked_element *el_new = malloc(sizeof (linked_element));
	  check_mem(el_new);
	  el_new->next = NULL;
	  el_new->val = i;
	  el_new->set = true;

	  if(!tail_element) {
	       el_new->prev = NULL;
	       tail_element = el_new;
	  } else {
	       el_new->prev = tail_element;
	       tail_element->next = el_new;
	  }
	  return 0;
     }
error:
     return 1;
}

int pop(linked_element **el)
{
     check(el, "Invalid pointer to *linked_element.");

     linked_element *_el = *el;
     check(_el, "Empty ponter to linked_element.");

     int i = 0;
     if(_el->set) {
	  i = _el->val;
	  *el = _el->next? _el->next: NULL;

	  free(_el);
	  return i;
     } else {
	  sentinel("_el->set should not be false. Something's wrong.");
     }
error:
     return -1;
}
