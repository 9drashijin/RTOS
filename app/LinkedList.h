#ifndef  __LINKED_LIST_H__
#define  __LINKED_LIST_H__

#include <stdint.h>

typedef struct Element_t{
	struct Element_t *next;
	uint32_t data;
}Element;

typedef struct {
	Element *head;
	Element *tail;
	uint32_t length;
}LinkedList;

#endif //__LINKED_LIST_H__
