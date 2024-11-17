#include "person_list.h"
#include "person.h"

#include <stdlib.h> // malloc, free

typedef struct Node {
  Person_t m_Person;
  struct Node* p_next;
} Node_t;

static Node_t* gp_first = NULL;
static int g_count = 0;


static Node_t* create_node(void)
{
  Node_t* p_node = malloc(sizeof(Node_t));
  if (!p_node) {
    printf("Memory allocation error!\n");
    exit(EXIT_FAILURE);
  }

  return p_node;
}

int is_empty(void)
{
  return gp_first == NULL;
  // return g_count == 0;
}

size_t list_get_size(void)
{
  return g_count;
}