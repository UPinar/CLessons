#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include <stdio.h>

typedef struct Person {
  int m_id;
  char m_name[32];
  char m_surname[32];
  Date_t m_birth_date;
} Person_t;


Person_t* person_set_random(Person_t* p_p1);
void person_print(const Person_t* p_cp1);
void person_print_file(FILE* f_dest, const Person_t* p_cp1);
int person_compare(const Person_t* p_cp1, const Person_t* p_cp2);

#endif // PERSON_H