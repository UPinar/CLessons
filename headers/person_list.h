#ifndef PERSON_LIST_H
#define PERSON_LIST_H

#include <stddef.h> // size_t

typedef struct Person Person_t;

void list_push_front(const Person_t*);
void list_pop_front(void);
void list_get_first(Person_t*);
size_t list_get_size(void);
void list_print(void);
void list_make_empty(void);
int list_is_empty(void);


#endif // PERSON_LIST_H