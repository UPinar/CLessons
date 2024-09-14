#ifndef   UTILITY_H
#define   UTILITY_H

#define   asize(x)      (sizeof(x) / sizeof(x[0]))

void randomize(void);
void set_array_random(int* pArr, int size);
void print_array(const int* pArr, int size);



#endif // UTILITY_H