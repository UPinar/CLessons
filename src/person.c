#include <string.h> // strcpy
#include <stdio.h>  // printf
#include <stdlib.h> // rand

#include "../headers/person.h"
#include "../headers/nutility.h"
#include "../headers/date.h"

#define PUBLIC

PUBLIC 
Person_t* person_set_random(Person_t* p_p1)
{
  p_p1->m_id = rand();
  strcpy(p_p1->m_name, get_random_name());
  strcpy(p_p1->m_surname, get_random_surname());
  date_set_random(&p_p1->m_birth_date);

  return p_p1;
}

PUBLIC
void person_print(const Person_t* p_cp1)
{
  printf("%-5d %-12s %-12s ", 
          p_cp1->m_id, 
          p_cp1->m_name, 
          p_cp1->m_surname);
  date_print(&p_cp1->m_birth_date);
}

PUBLIC
void person_print_file(FILE* f_dest, const Person_t* p_cp1)
{
  fprintf(f_dest,
          "%-5d %-12s %-12s ", 
          p_cp1->m_id, 
          p_cp1->m_name, 
          p_cp1->m_surname);
  date_print_file(f_dest, &p_cp1->m_birth_date);
}

PUBLIC
int person_compare(const Person_t* p_cp1, const Person_t* p_cp2)
{
  // comparison criteria
  // 1. surname comparison 
  // 2. name comparison
  // 3. birth date comparison
  // 4. id comparison

  // comparison of surnames
  int cmp_result = strcmp(p_cp1->m_surname, p_cp2->m_surname);
  if (cmp_result) return cmp_result;

  // comparison of names
  cmp_result = strcmp(p_cp1->m_name, p_cp2->m_name);
  if (cmp_result) return cmp_result;

  // comparison of birth dates
  cmp_result = date_compare(&p_cp1->m_birth_date,
                            &p_cp2->m_birth_date);

  if (cmp_result) return cmp_result;

  // comparison of ids
  return p_cp1->m_id - p_cp2->m_id; 
  // if no overflow risk
}