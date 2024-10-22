#include "register.h"

#define   MAX_NO_OF_FUNCTIONS   10

static FP_TYPE g_fp_arr[MAX_NO_OF_FUNCTIONS];
static int g_fn_count = 0;

void register_fn(FP_TYPE fp)
{
  if (g_fn_count == MAX_NO_OF_FUNCTIONS)
    return;
  
  g_fp_arr[g_fn_count++] = fp;
}

void call_registered_fns(void)
{
  for(int i = g_fn_count - 1; i >= 0; i--)
    g_fp_arr[i]();
}