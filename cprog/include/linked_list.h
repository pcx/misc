#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdbool.h>


typedef struct linked_element {
     int val;
     bool set;
     struct linked_element *next, *prev;
} linked_element;

int head(linked_element *el);
void push(linked_element **el, int i);
int pop(linked_element **el);

#endif
