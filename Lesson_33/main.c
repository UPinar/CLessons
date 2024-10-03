#include <stdio.h>

/*
    ---------------------------------------------------------------
    | Type Alias(typedef) Declarations (Tür eş isim bildirimleri) |
    ---------------------------------------------------------------
*/

/*
  typedef int Word;
  // "Word" is an alias for int
  // int türüne eş isim olarak Word ismini vermek

  Word foo(Word);

  int main(void)
  {
    // ----------------------------------------------

    Word x, y, z; // x, y, z's type is int
    Word ar[10];

    // ----------------------------------------------

    int ival = 10;
    int ret = foo(ival);
    Word ret_2 = foo(ival);
    Word* ptr = &ival;

    // ----------------------------------------------
  }
*/

/*
  typedef int Word;
  typedef int Mint;
  typedef int Myint;

  int main(void)
  {
    Word a = 10;
    Mint b = 20;
    Myint c = 30;
  }
*/

/*
  typedef int Word; 
  // "Word" is an identifier and every identifier has a scope.
  // "Word" typedef declaration in global scope


  void foo(void)
  {
    Word x = 5; 
    // "Word" identifier's scope is global scope
    // it is visible in this function's block scope

    typedef int Word_2; 
    // declaration in foo function's block scope

    Word_2 k = 11; 
    // "Word_2" identifier is visible in this block scope
  }


  void bar(void)
  {
    Word y = 10; 
    // "Word" identifier's scope is global scope
    // it is visible in this function's block scope

    Word_2 m = 22;  // syntax error
    // error: unknown type name 'Word_2'

    // "Word_2" identifier is not visible in 
    // this function's block scope
  }
*/

/*
  typedef double Dollar;  
  // "Dollar" is an alias for double
  typedef Dollar USD;     
  // "USD" is an alias for "Dollar" and is an alias for double 

  int main(void)
  {
    Dollar x = 3.4;
    USD y = 5.6;
  }
*/

/*
  typedef int* Iptr;

  int main(void)
  {
    // ----------------------------------------------

    int x = 10;
    Iptr p = &x;    // int* p = &x;

    // ----------------------------------------------

    int* p1, p2;   
    // "p1" type is int*, "p2" type is int
    Iptr p3, p4;    // int* p3, *p4;
    // "p3" type is int*, "p4" type is int*

    // ----------------------------------------------
  }
*/

/*
  #define   IPTR  int*
  typedef int* iptr;

  int main(void)
  {
    IPTR p1, p2, p3;   // int* p1, p2, p3;
    // "p1" is int*, "p2" is int, "p3" is int

    iptr p4, p5, p6;   // int* p4, *p5, *p6;
    // "p4" is int*, "p5" is int*, "p6" is int*
  }
*/

/*
  1. hangi türe eş isim vermek istiyorsanız 
    o türden bir değişken tanımlayın.
  2. değişken tanımının(declaration statement) başına
    typedef anahtar sözcüğünü ekleyin.
  3. değişken isminin yerine vermek istediğiniz
    eş ismi yazın.
*/

/*
  typedef int INTARR5[5];

  int main(void)
  {
    int i_arr[20];      // "i_arr" variable's type is int[20]
    double d_arr[5];    // "d_arr" variable's type is double[5]

    INTARR5  x, y, z;  // int x[5], y[5], z[5];

    for (int i = 0; i < 5; ++i)
      x[i] = y[i] = z[i] = i;
    

    for (int i = 0; i < 5; ++i)
      printf("%d %d %d\n", x[i], y[i], z[i]);

    // output ->
    //  0 0 0
    //  1 1 1
    //  2 2 2
    //  3 3 3
    //  4 4 4
  }
*/

/*
  typedef const int* CIPTR;

  int main(void)
  {
    CIPTR p;  // const int* p;

    CIPTR p1, p2, p3;  
    // const int* p1; 
    // const int* p2; 
    // const int* p3;
  }
*/

/*
  typedef int* IPTR;

  int main(void)
  {
    int x = 34;

    const IPTR p = &x;    

    // Question : `const IPTR p = &x;` statement is equivalent 
    //  to which one of the following?
    // int* const p = &x;   // 1  (top-level const)
    // const int* p = &x;   // 2  (low-level const)

    // Answer : 1

    *p = 12;  // VALID

    p = NULL; // syntax error
    // error: assignment of read-only variable 'p'
  }
*/