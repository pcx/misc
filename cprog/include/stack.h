#ifndef _STACK_H
#define _STACK_H

#include "linked_list.h"

typedef struct LinkedStack {
     linked_element *_head;
     int (*head)(linked_element *el);
     int (*push)(linked_element **el, int i);
     int (*pop)(linked_element **el);
     int (*size)(linked_element *el);
} LinkedStack;

LinkedStack *Stack_create();

#endif
