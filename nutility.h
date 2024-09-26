#ifndef   NUTILITY_H
#define   NUTILITY_H

#define   asize(x)      (sizeof(x) / sizeof(x[0]))

void randomize(void);
void set_array_random(int* pArr, int size);
void print_array(const int* pArr, int size);
void sort_array(int* pArr, int size);
void sgets(char* pStr);
void swap(int* x, int* y);



#endif // NUTILITY_H