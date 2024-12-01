#include "../headers/person_list.h"
#include "../headers/person.h"

#include <stdlib.h> // malloc, free
#include <stdio.h>  // printf

typedef struct Node {
  Person_t m_Person;
  struct Node* p_next;
} Node_t;

static Node_t* gp_first = NULL;
static size_t g_count = 0;

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


// void list_push_front(const Person_t*);
// void list_pop_front(void);
// void list_get_first(Person_t*);
// size_t list_get_size(void);
// void list_print(void);
// void list_make_empty(void);
// int list_is_empty(void);


void list_push_front(const Person_t* p_person)
{
  Node_t* p_new_node = create_node();
  p_new_node->m_Person = *p_person;

  p_new_node->p_next = gp_first;
  gp_first = p_new_node;
  ++g_count;
}

void list_pop_front(void)
{
  if (g_count == 0) {
    printf("List is empty!\n");
    exit(EXIT_FAILURE);
  }

  Node_t* p_temp_node = gp_first;
  gp_first = gp_first->p_next;
  free(p_temp_node);
  --g_count;
}

void list_get_first(Person_t* p_person)
{
  if (g_count == 0) {
    printf("List is empty!\n");
    exit(EXIT_FAILURE);
  }

  *p_person = gp_first->m_Person;
}

size_t list_get_size(void)
{
  return g_count;
}

void list_print(void)
{

  for (Node_t* p = gp_first; p != NULL; p = p->p_next)
    person_print(&p->m_Person);

  printf("---------------------------------------------------\n");
}

void list_make_empty(void)
{
  while (g_count != 0)
    list_pop_front();
}

int list_is_empty(void)
{
  return gp_first == NULL;
  // return g_count == 0;
}