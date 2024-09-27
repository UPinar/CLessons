#ifndef   NUTILITY_H
#define   NUTILITY_H

void randomize(void);
void sgets(char* pStr);
void swap(int* x, int* y);

void set_array_random(int* p_array, int size);
void print_array(const int* p_array, int size);
void sort_array(int* pArr, int size);
void reverse_array(int* p_array, int size);
int get_sum(const int* p_array, int size);
double get_mean(const int* p_array, int size);
double get_std_dev(const int* p_array, int size);
int get_max_elem(const int* p_array, int size);
int get_min_elem(const int* p_array, int size);
void get_min_max(const int* p_array, int size, int* p_min, int* p_max);
void copy_array(int* p_dest, const int* p_source, int size);
void swap_arrays(int* p_array1, int* p_array2, int size);



#endif // NUTILITY_H