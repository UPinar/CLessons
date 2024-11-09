#include <stdio.h>

/*
                        ===============
                        | Not Related |
                        ===============
*/

/*
  - compatible types
  - effective type
  - strict aliasing
*/

/*
                  ------------------------
                  | strict aliasing rule |
                  ------------------------
*/

/*
  int main(void)
  {
    float f = 3.14f;

    int* p_int = (int*)&f;  // undefined behavior(UB)
    // `float` and `int` types sizes are same. 
    // but this code is violating strict aliasing rule.

    int x = *p_int;
  }
*/

/*
  int main(void)
  {
    unsigned int x = 8723u;

    int* p_int = (int*)&x;  // VALID
    // `unsigned int` and `int` types sizes are same.
    // this code IS NOT violating strict aliasing rule.

    int x = *p_int;
  }
*/

/*
  int main(void)
  {
    double dval = 23.5343;

    char* p_char = (char*)&dval;  // VALID
    // this code IS NOT violating strict aliasing rule.
    // functions like `memcpy` and `memmove` are using this technique.
  }
*/

/*
  struct Data {
    int m_x, m_y, m_z;
  };

  int main(void)
  {
    struct Data d1 = { 1, 2, 3 };

    // `&d1`'s data type is `struct Data*`

    int* p_int = (int*)&d1; // VALID
    // structure variable's address can be used 
    // structure variable's first member's address.
    // this code IS NOT violating strict aliasing rule.

    printf("%d\n", *p_int); // output -> 1
  }
*/


