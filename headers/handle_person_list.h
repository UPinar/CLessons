#ifndef HANDLE_PERSON_LIST_H
#define HANDLE_PERSON_LIST_H

#include <stddef.h> // size_t

typedef struct List* LIST_HANDLE;
typedef struct Person Person_t;

LIST_HANDLE list_create(void);
void list_destroy(LIST_HANDLE);

void list_push_front(LIST_HANDLE, const Person_t*);
void list_pop_front(LIST_HANDLE);
void list_get_first(LIST_HANDLE, Person_t*);
size_t list_get_size(LIST_HANDLE);
void list_print(LIST_HANDLE);
void list_make_empty(LIST_HANDLE);
int list_is_empty(LIST_HANDLE);

#endif // HANDLE_PERSON_LIST_H


