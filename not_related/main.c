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

/*
                        ----------------
                        | localization |
                        ----------------
*/

/*
  default locale -> "C" locale
    - locale dependent functions (i.e printf, scanf)
    - locale independent functions
*/

/*
  #include <locale.h> // setlocale

  int main(void)
  {
    char* p = setlocale(LC_ALL, "turkish");
    // first argument is a macro starting with `LC_`
    // LC_ALL, 
    // LC_COLLATE, 
    // LC_CTYPE, 
    // LC_MAX, LC_MIN
    // LC_MONETARY, 
    // LC_NUMERIC, 
    // LC_TIME

    if (!p){
      printf("locale set failed\n");
      return 1;
    }

    printf("locale set to [%s]\n", p);
    // output -> locale set to [Turkish_Türkiye.1254]
  }
*/

/*
  #include <locale.h>   // setlocale

  int main(void)
  {
    double dval = 123.645874; 
    printf("dval = %f\n", dval);  // output -> dval = 123.645874

    setlocale(LC_ALL, "turkish");
    printf("dval = %f\n", dval);  // output -> dval = 123,645874
  }
*/

/*
  int main(void)
  {
    double dval;

    printf("Enter a double value: ");
    scanf("%lf", &dval);
    printf("dval = %f\n", dval);

    // input  -> Enter a double value: 2374.1982
    // output -> dval = 2374.198200

    // input  -> Enter a double value: 2374,1982
    // output -> dval = 2374.000000
  }
*/

/*
  #include <locale.h>   // setlocale

  int main(void)
  {
    setlocale(LC_ALL, "turkish");

    double dval;

    printf("Enter a double value: ");
    scanf("%lf", &dval);
    printf("dval = %f\n", dval);

    // input  -> Enter a double value: 2374.1982
    // output -> dval = 2374,000000

    // input  -> Enter a double value: 2374,1982
    // output -> dval = 2374,1982
  }
*/

// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------