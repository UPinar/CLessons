#include "nutility.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void randomize(void){
  srand((unsigned)time(NULL));
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

void set_array_random(int* p_array, int size){
  while(size--)
    *p_array++ = rand() % 1000;
}

void print_array(const int* p_array, int size){
  for (int i = 0; i < size; ++i){
    if (i && i % 10 == 0)
      putchar('\n');
    printf("%3d ", p_array[i]);
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

void reverse_array(int* p_array, int size)
{
  for(int i = 0; i < size / 2; ++i)
    swap(p_array + i, p_array + size - i - 1);
}

int get_sum(const int* p_array, int size)
{
  int sum = 0;
  for(int i = 0; i < size; ++i)
    sum += p_array[i];
  
  return sum;
}

double get_mean(const int* p_array, int size)
{
  return (double)get_sum(p_array, size) / size;
}

double get_std_dev(const int* p_array, int size)
{
  double mean = get_mean(p_array, size);
  double sum_square = 0.;

  for(int i = 0; i < size; ++i)
    sum_square += (p_array[i] - mean) * (p_array[i] - mean);

  return sqrt(sum_square / (size - 1));
}

int get_max_elem(const int* p_array, int size)
{
  int max = p_array[0];
  for(int i = 1; i < size; ++i)
    if(p_array[i] > max)
      max = p_array[i];
  
  return max;
}

int get_min_elem(const int* p_array, int size)
{
  int min = *p_array;
  for(int i = 1; i < size; ++i)
    if(p_array[i] < min)
      min = p_array[i];
  
  return min;
}

void get_min_max(const int* p_array, int size, int* p_min, int* p_max)
{
  *p_min = *p_max = *p_array;

  for(int i = 1; i < size; ++i){
    if(p_array[i] > *p_max)
      *p_max = p_array[i];
    else if(p_array[i] < *p_min)
      *p_min = p_array[i];
  }
}

void copy_array(int* p_dest, const int* p_source, int size)
{
  while (size--)
    *p_dest++ = *p_source++;
}

void swap_arrays(int* p_array1, int* p_array2, int size)
{
  while (size--)
    swap(p_array1++, p_array2++);
}