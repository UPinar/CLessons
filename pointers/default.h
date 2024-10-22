#ifndef DEFAULT_H
#define DEFAULT_H

#include <stdio.h>

typedef void(*FP_TYPE)(void);

void f1(void);
FP_TYPE set_f1(FP_TYPE fn);

void f2(void);

#endif // DEFAULT_H