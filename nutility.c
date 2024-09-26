#include "nutility.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void randomize(void){
  srand((unsigned)time(NULL));
}

void set_array_random(int* pArr, int size){
  while (size--)
    *pArr++ = rand() % 1000;
}

void print_array(const int* pArr, int size){
  for (int i = 0; i < size; ++i){
    if (i && i % 10 == 0)
      putchar('\n');
    printf("%3d ", pArr[i]);
  }
  printf("\n---------------------------------------\n");
}

void sort_array(int* pArr, int size){
  for (int i = 0; i < size - 1; ++i){
    for (int k = i + 1; k < size; ++k){
      if (pArr[i] > pArr[k]){
        int temp = pArr[i];
        pArr[i] = pArr[k];
        pArr[k] = temp;
      }
    }
  }
}

void sgets(char* pStr){
  int c;
  while ((c = getchar()) != '\n')
    *pStr++ = (char)c;
  *pStr = '\0';
}

void swap(int* x, int* y){
  int temp = *x;
  *x = *y;
  *y = temp;
}