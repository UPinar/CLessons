#ifndef   NUTILITY_H
#define   NUTILITY_H

#include <stddef.h> // size_t

#define asize(x) (sizeof(x) / sizeof(x[0]))

extern const char* p_names[];
#define PNAMES_SIZE 335

void randomize(void);
void sgets(char* pStr);
void swap(int* x, int* y);

void set_array_random(int* p_array, size_t size);
void print_array(const int* p_array, size_t size);
void sort_array(int* pArr, size_t size);
void reverse_array(int* p_array, size_t size);
int get_sum(const int* p_array, size_t size);
double get_mean(const int* p_array, size_t size);
double get_std_dev(const int* p_array, size_t size);
int get_max_elem(const int* p_array, size_t size);
int get_min_elem(const int* p_array, size_t size);
void get_min_max(const int* p_array, size_t size, int* p_min, int* p_max);
void copy_array(int* p_dest, const int* p_source, size_t size);
void swap_arrays(int* p_array1, int* p_array2, size_t size);

void swap_T(void* vp1, void* vp2, size_t size);

#endif // NUTILITY_H