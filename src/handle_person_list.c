#include "../headers/handle_person_list.h"
#include "../headers/person.h"

#include <stdlib.h> // malloc, free
#include <stdio.h>  // printf

typedef struct Node {
  Person_t m_Person;
  struct Node* mp_next_node;
} Node_t;

struct List {
  Node_t* mp_first_node;
  size_t m_count;
};

typedef struct List List_t;

// ---------------------------------------------------------
// ------------------  PRIVATE FUNCTIONS -------------------
// ---------------------------------------------------------


static Node_t* create_node(void)
{
  Node_t* p_node = malloc(sizeof(Node_t));
  if (!p_node) {
    printf("Memory allocation error!\n");
    exit(EXIT_FAILURE);
  }

  return p_node;
}

// ---------------------------------------------------------
// ------------------- PUBLIC FUNCTIONS --------------------
// ---------------------------------------------------------


List_t* list_create(void)
{
  List_t* p_list = malloc(sizeof(struct List));
  if (!p_list) 
    return NULL;

  p_list->mp_first_node = NULL;
  p_list->m_count = 0;
  return p_list;
}

void list_destroy(List_t* p_list)
{
  list_make_empty(p_list);
  free(p_list);
}

void list_push_front( List_t* p_list, 
                      const Person_t* p_person)
{
  Node_t* p_new_node = create_node();
  p_new_node->m_Person = *p_person;

  p_new_node->mp_next_node = p_list->mp_first_node;
  p_list->mp_first_node = p_new_node;
  ++p_list->m_count;
}

void list_pop_front(List_t* p_list)
{
  if (p_list->m_count == 0) {
    printf("List is empty!\n");
    exit(EXIT_FAILURE);
  }

  Node_t* p_temp_node = p_list->mp_first_node;
  p_list->mp_first_node = p_list->mp_first_node->mp_next_node;
  free(p_temp_node);
  --p_list->m_count;
}

void list_get_first(List_t* p_list, Person_t* p_person)
{
  if (p_list->m_count == 0) {
    printf("List is empty!\n");
    exit(EXIT_FAILURE);
  }

  *p_person = p_list->mp_first_node->m_Person;
}

size_t list_get_size(List_t* p_list)
{
  return p_list->m_count;
}

void list_print(List_t* p_list)
{

  for ( Node_t* p_current_node = p_list->mp_first_node; 
        p_current_node != NULL; 
        p_current_node = p_current_node->mp_next_node)
  {
    person_print(&p_current_node->m_Person);
  }

  printf("---------------------------------------------------\n");
}

void list_make_empty(List_t* p_list)
{
  while (p_list->m_count)
    list_pop_front(p_list);
}

int list_is_empty(List_t* p_list)
{
  return p_list->m_count == 0;
}