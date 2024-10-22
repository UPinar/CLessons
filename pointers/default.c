#include "default.h"

FP_TYPE g_fp = &f2;

void f1(void)
{
  g_fp();
  // f1 function's default behaviour is to call 
  // function that "g_fp" global function pointer variable holds
}

FP_TYPE set_f1(FP_TYPE fn)
{
  FP_TYPE ret_fp = g_fp;
  g_fp = fn;
  return ret_fp;

  // set_f1 function sets the "g_fp" global function pointer variable
  // to the function pointer that is passed as an argument
  // and returns the previous function pointer that "g_fp" holds
}

void f2(void)
{
  printf("f2 function is called\n");
}