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
  typedef int INTARR100[100];

  int main(void)
  {
    INTARR100 a, b, c;

    printf("sizeof(a) = %zu\n", sizeof(a));
    printf("sizeof(b) = %zu\n", sizeof(b));
    printf("sizeof(c) = %zu\n", sizeof(c));

    // output ->
    //  sizeof(a) = 400
    //  sizeof(b) = 400
    //  sizeof(c) = 400
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

/*
  #define  WORD int
  // preprocessor macros does not have a scope

  typedef int word;

  void foo(void)
  {
    typedef int word_2; 
    // "word_2" identifiers scope is this block
  }

  int main(void)
  {
    WORD x, y, z;  
    // preprocessing time identifier.
    // compiler is not seing "WORD" as an identifier. 

    word a, b, c;  
    // compile time identifier
    // compiler is seeing "word" as an identifier.
  }
*/

/*
        < -------------- SCEANARIO_1 -------------- >

  - using typedef declarations to make code 
    more readable and much easier to write. 
    -> especially in function pointers and structures
*/

/*
  // <------------ complex declarations ------------>

  void foo(int(*fp)(const char*, const char*));
  // "foo" function's parameter variable is a function pointer

  void bar(int(*fp1)(const char*, const char*),
          int(*fp2)(const char*, const char*));
  // "bar" function's parameter variables are function pointers


  int(*baz( int(*fp1)(const char*, const char*),
            int(*fp2)(const char*, const char*)))
                                (const char*, const char*);

  // "baz" function's return type is a function pointer
  // "baz" function's parameter variables are function pointers

  int main(void)
  {
    int(*fptr_1)(const char*, const char*); 
    // function pointer variable
    int(*fptr_2)(const char*, const char*); 
    // function pointer variable
    int(*fptr_3)(const char*, const char*); 
    // function pointer variable


    int(*fptr_arr[3])(const char*, const char*) = 
                                    { fptr_1, fptr_2, fptr_3 };
    // function pointer array
  }
*/

/*
  typedef int(*FPTR)(const char*, const char*);
  // typedef declaration for function pointer type
  // int(*)(const char*, const char*)

  void foo(FPTR fptr_1);
  // function's parameter variable is a function pointer

  void bar(FPTR fptr_1, FPTR fptr_2);
  // function's parameter variables are function pointers

  FPTR baz(FPTR fptr_1, FPTR fptr_2);
  // function's return type is a function pointer
  // function's parameter variables are function pointers

  int main(void)
  {
    FPTR fptr_1, fptr_2, fptr_3;
    // function pointer variables

    FPTR fptr_arr[3] = { fptr_1, fptr_2, fptr_3 };
    // function pointer array
  }
*/

/*
        < -------------- SCEANARIO_2 -------------- >

  - using typedef declarations for representation of 
    integral and floating point types in much narrowing domain.

  - typedef bildirimlerinin tam sayı ve gerçek sayı türlerinin 
    daha dar bir domainde temsil edilmesi için kullanılması.
*/

/*
  typedef double Dollar;
  typedef int CounterType;
  typedef int FLAG;

  int main(void)
  {
    CounterType cnt = 0;
    Dollar x = 34.26;
    FLAG f = 0;
  }
*/

/*
        < -------------- SCEANARIO_3 -------------- >

  - using typedef declarations for a generalized type
  and when that generalized type wanted to change it is much more
  easier to change it in one place.
*/

/*
  typedef int CounterType;    // typedef long CounterType;

  int main(void)
  {
    // suppose that we want our new counter type to be long
    int cnt1 = 0;     // long cnt1 = 0;
    int cnt2 = 0;     // long cnt2 = 0;
    // we need to change all of the counter variables' type


    // if we use typedef declaration
    CounterType cnt3 = 0;
    CounterType cnt4 = 0; 
    // we only need to change the typedef declaration
  }
*/

/*
  standart type aliases -> 
    size_t, time_t, clock_t, ptrdiff_t, fpos_t ...

  // for different compilers types sizes are different.

  unsigned int strlen(const char* p);
  // for compiler1 -> unsigned int is 2 bytes
  // for compiler2 -> unsigned int is 4 bytes

  // - for not making problems for compilers, typedef declarations
  //  is being used.
  // - letting type selection to the compiler

  size_t strlen(const char* p);
  time_t time(time_t* p);
*/

/*
  #include <string.h>   // size_t, strlen
  #include <time.h>     // time_t, time

  int main(void)
  {
    char str[100];
    size_t len = strlen(str);

    time_t sec;
    time(&sec);
  }
*/

/*
              ------------------------------------
              | type aliases in standart library |
              ------------------------------------
*/

/*
  - size_t is an unsigned integer type
  - size_t is defined in 
    <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, <time.h>
    <uchar.h>, <wchar.h>

  - the bit width of size_t is not less than 16.(C99)
*/

/*
  standart library is using size_t 
    - type for length of string(s) 
    - sizeof operator's generated type
    - array length type
    - piece type (tane-adet)
*/

/*
  #include <stdlib.h> // malloc, qsort
  #include <string.h> // memset, memcmp, strlen

  void* malloc(size_t size);
  void* memset(void* dest, int ch, size_t count);
  int memcmp(const void* ptr1, const void* ptr2, size_t count);
  size_t strlen(const char* str);

  void qsort( void* base, 
              size_t num, 
              size_t size, 
              int(*cmp)(const void*, const void*));
*/

/*
  #include <stddef.h> // size_t

  int main(void)
  {
    size_t len = 235;

    printf("len = %zu\n", len);   
    // output -> len = 235
    // %zu format specifier is for size_t type
  }
*/

/*
  - ptrdiff_t is the signed integer type of the result of 
    subtracting two pointers.
*/

/*
  fixed width integer types(C99)
    - int8_t, int16_t, int32_t, int64_t
    - uint8_t, uint16_t, uint32_t, uint64_t

  - fixed width integer types are type aliases
  - fixed width integer types are standart.
  - not all compilers support some of the fixed width integer types.
*/

/*
  #include <stdint.h> // int16_t

  int main(void)
  {
    int16_t x = 243;
    // there is a type needs to be 16 bit signed integer
    // for int16_t to be supported by the compiler

    // int16_t can be different type's type alias 
    // for different compilers.
    
    // if a system's bit width is 12 bit.
    // int16_t can not be supported by the compiler.
  }
*/

/*
  - intmax_t is the largest signed integer type
  - uintmax_t is the largest unsigned integer type
*/

/*
  - system's bit width is 12 bit 

  - intleast32_t can at least be a 
    4 byte(4 * 12 > 32) signed integer type
*/

/*
  - in some scenarios we need to use a type that can hold 
    a pointer value as an integer.
  - intptr_t is integer type capable of holding a pointer.
*/

/*
  - in some hardware's operation speed with integer types 
    can be vary.
  - int_fast16_t is the fastest signed integer type with
    width of AT LEAST 16 bits.
*/