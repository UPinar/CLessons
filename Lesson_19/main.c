#include <stdio.h>

/*
              ===================================
              | preprocessor(önişlemci program) |
              ===================================
*/

/*
  source file -> preprocessor -> translation unit 
                  directives

  preprocessor does not know C language.
  preprocessor directives does not ends with ";" semicolon
  preprocessor does not have any scope

  # -> number sign charactter
*/

/*
  preprocessor directives :
  -------------------------
  #         (null directive) -> does nothing 
  #include 
  #define
  #undef
  ---------------
  #if
  #else
  #elif    -> those 6 are related with conditional compiling
  #ifdef
  #ifndef
  #endif
  ---------------
  #line
  #error
  #pragram
*/

/*
                          ------------
                          | #include |
                          ------------
*/

/*
  #include <stdio.h>    
  // <> generally used for libraries comes with the compiler
  // it checks this header file inside default directory

  #include "myheader.h"
  // "" generally used for 3rd party header files and 
  //  our projects header files
  // it checks where main project files are
*/


/*
  main.c  
  ========
  #include "header1.h"

  int main(void){
    int x = bar(12);      // valid
    int y = foo(22, 44);  // valid  
  }

  header1.h
  ==========
  #include "header2.h"
  int bar(int);

  header2.h
  =========
  #include "header3.h"
  int foo(int, int);

  // when main.c includes header1 (#include "header1.h"), 
  // header1.h is also including header2.h so compiler
  // can see foo and bar functions declarations.
*/

/*
                          -----------
                          | #define |
                          -----------
*/

/*
  -> #define önişlemci komutu ile önişlemci programa bir isim 
    tanıtıyoruz. Bu isimlere macro deniliyor.
  -> introducing an identifier to preprocessor with #define directive
  those identifiers called "macros"
*/

/*
                          ----------
                          | macros |
                          ----------
  -> object-like macros               (nesne benzeri makrolar)
  -> function-like(functional) macros (fonksiyon benzeri makrolar)
*/

/*
                      ----------------------
                      | object-like macros |
                      ----------------------
*/

/*
  #define SIZE  30

  int main(void){

    for(int i = 0; i < SIZE; ++i){
      printf("xo");
    }
    // output -> 
    //  xoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxo
  }
*/

/*
  int x = SIZE;   // syntax error 
  // error: 'SIZE' undeclared here
  // replacement(substitution) CAN NOT be done. 

  #define SIZE  30

  int y = SIZE;   // VALID
  // replacement(substitution) CAN be done. 

  int main(void){
  }
*/

/*
  void foo(void);

  int main(void){
    #define SIZE  100   // preprocessor DOES NOT have scope !
    foo();
  }

  void foo(void){
    int x = SIZE;
    printf("x = %d", x);  // output -> x = 100
  }
*/

/*
  #define SIZE  100

  int main(void){
    int x = MAX_SIZE; // syntax error
    // error: 'MAX_SIZE' is undefined
    // preprocessor DID NOT make MAX_SIZE to MAX_100

    int y = SIZE;     // VALID
  }
*/

/*
  #define 100   300   // syntax error
  #define 100   SIZE  // syntax error
*/

/*
  #define SIZE  100

  int main(void){
    printf("SIZE"); // output -> SIZE

    // for replacement(substitution) to happen macro should be a token,
    //  not a part of any other token 
    //  "SIZE" is string literal and it is a token
  }
*/

/*
  #define SIZE  100

  int main(void){
    int x = size; // syntax error
    // macros are CASE-SENSITIVE
  }
*/

/*
  #define     ADD   100 + 200
  #define     ADD2  (100 + 200)

  int main(void){
    int x = 7 * ADD;
    int y = 7 * ADD2;

    printf("x = %d\n", x);  // output -> x = 900
    printf("y = %d\n", y);  // output -> y = 2100
  }
  // int x = 7 * 100 + 200 
  // int y = 7 * (100 + 200) 
*/

/*
  #define   TOS     HEY + 100
  #define   HEY     100
  #define   YOLO    HEY + 400

  int main(void){
    int x = TOS;
    printf("x = %d\n", x);  // output -> x = 200

    int y = YOLO;
    printf("y = %d\n", y);  // output -> y = 500
  }

  // macro can be used inside another macro
*/

/*
  #define   HEY   100;  
  // semicolon has been used in macro
  // HEY will be replaced with "100;"

  int main(void){

    int x;
    x = HEY;  
    // x = 100;;  second ";" becomes null statement -> VALID


    if (x == HEY) // syntax error 
      ++x;
    // if (x == 100;) NOT VALID 
    // error: expected ')' before ';' token
  }
*/

/*
  #define   MESSAGE   "NOT ENOUGH MEMORY"

  int main(void){
    printf(MESSAGE);  // output -> NOT ENOUGH MEMORY
  }
*/

/*
  #define   AAAAAAA  1
  #define   BBBBBBB  2
  #define   CCCCCCC  30
  #define   XXXXXXX  100
  #define   YYYYYYY  200
  #define   ZZZZZZZ  300

  #define   SIZE      AAAAAAA + BBBBBBB + CCCCCCC + \
                      XXXXXXX + YYYYYYY + ZZZZZZZ

  // for using next line in the macros "\" character needs to be used

  int main(void){
    int x = SIZE;

    printf("x = %d", x);  // output -> x = 633
  }
*/

/*
  #define   NO_OF_ANIMALS  6478263
  // symbolic(manifest) constant -> sembolik sabit

  // 1. when constants have been used naked, code is getting harder
  //  to understand, using symbolic constants makes it easy.

  // 2. large numbers are hard to write properly 100'000 can easily
  //  be writeen as 1'000'000. Using symbolic constant decrease the
  //  risk using wrong value.
*/

/*
  int main(void){
    int arr[100] = { 0 };     // related with array size

    for (int i = 0; i < 100; ++i){  // related with array size
      arr[i] = 1;   
    }

    int x = 100;    // not related with the array size

    if (x == 100)   // not related with the array
      ;
  }

  // think about we need to increase size of the array 100 -> 500
  // when we change every 100 to 500 inside THE file 
  // it will broke other code which are not related 
  // with the size of the array

  #define   SIZE 500

  int symbolic_constant_main(void){
    int arr[SIZE] = { 0 };     

    for (int i = 0; i < SIZE; ++i){  
      arr[i] = 1;   
    }

    int x = 100;    

    if (x == 100)   
      ;
  }
*/

/*
  #include <stdlib.h>

  int main(void){
    rand(); 

    RAND_MAX; 
    // max value that rand() function can generate
    // its value depends on the compiler

    fseek(f, 0L, SEEK_SET);  

    // functions 3rd parameter should be one of those macros
    SEEK_SET;
    SEEK_CUR;
    SEEK_END;
    // https://en.cppreference.com/w/c/io/fseek
  }
*/

/*
  #include <limits.h>

  int main(void){

    int x = 2147483647;

    int y = INT_MAX;
    // INT_MAX macro's value depends on the compiler
  }
*/

/*
  #define   PUBLIC
  #define   PRIVATE
  #define   IN        
  #define   OUT

  // preprocessor will delete macros without values
  PUBLIC int foo(IN int x);
  PRIVATE int bar(IN int x);


  // what compiler will see is 
  int foo(int x);
  int bar(int x);

  #define NODISCARD

  NODISCARD int foo(void);
*/

/*
              ------------------------------------
              | function-like(functional) macros |
              ------------------------------------
*/

/*
  #define SQRT(a)
  #define FOO(a, b)
  #define BAR(a, b, c)
  #define BAZ() 
*/

/*
  #define SQUARE(A)   A * A 

  int main(void){
    int x = 9;

    printf("%d * %d = %d", x, x, SQUARE(x));
    // output -> 9 * 9 = 81
  }
*/

/*
  #define SQUARE_1(A)       A * A 
  #define SQUARE_2(A)     (A) * (A)
  #define SQUARE_3(A)     ((A) * (A))

  int main(void){
    int x = 5;

    // <----- PROBLEM 1 ----->

    int y = SQUARE_1(x + 1);  
    // int y = x + 1 * x + 1 
    printf("y = %d\n", y);  // output -> y = 11

    int z = SQUARE_2(x + 1);
    // int z = (x + 1) * (x + 1)
    printf("z = %d\n", z);  // output -> z = 36


    // <----- PROBLEM 2 ----->

    int k = 100 / SQUARE_2(x);      
    // int k = 100 / (x) * (x)
    printf("k = %d\n", k);  // output -> k = 100

    int l = 100 / SQUARE_3(x);
    // int l = 100 / ((x) * (x))
    printf("l = %d\n", l);  // output -> l = 4
  }
*/

/*
  #define   MAX(A, B)   ((A) > (B) ? (A) : (B))

  int main(void){
    int x = 45, y = 21;

    printf("max = %d\n", MAX(x, y));  
    // output -> max = 45
  }
*/

/*
  #define ISLEAP(y) \
          ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0)) 

  int main(void){
    int year = 1988;

    if (ISLEAP(year))
      printf("leap year");
    else
      printf("not leap year");

    // output -> leap year
  }
*/

/*
  #define ISUPPER(c)  ((c) >= 'A' && (c) <= 'Z')    
  #define ISLOWER(c)  ((c) >= 'a' && (c) <= 'z')    
  #define ISDIGIT(c)  ((c) >= '0' && (c) <= '9')    
  #define ISALPHA(c)  (ISUPPER(c) || ISLOWER(c))    
  #define ISALNUM(c)  (ISALPHA(c) || ISDIGIT(c))    
*/

/*
  #include <stdlib.h>   
  // for srand() function also NULL macro 

  #define   RANDOMIZE()   srand((unsigned int)time(NULL))

  int main(void){
    RANDOMIZE();    // no paramater functional macro
  }
*/

/*
  #define   SQUARE(x)     ((x) * (x))

  int main(void){
    int a = 6;
    int b = SQUARE(a++);    // undefined behaviour(UB)

    // int b = ((a++) * (a++));   -> compiler sees
    //  there is no sequence point 
    //  "a" has side effect in first (a++)
    //  "a" has been used for the second time
  }
*/

/*
  #define   SQUARE(x)     ((x) * (x))

  int foo(void);

  int main(void){
    SQUARE(foo());
    // ((foo()) * (foo()))  -> compiler sees

    // what we want is sending "foo" functions return value to 
    // SQUARE() functional macro

    // but "foo" function has been called for 2 times not 1
    // "foo" function might change global variables value
    // and calling it for 2nd time can create problems
  }

  // <--- HOW TO SOLVE --->
  // gcc compiler -> statement expression can solve this kind of 
  // problems where macro argument have been used more than once 
  // inside that macro

  // some libraries can create both functional macros and functions 
  // with the same name
*/

/*
  int square(int x){
    printf("real function called\n");
    return x * x;
  }

  #define   square(x)     ((x) * (x))

  int main(void){
    int i = 7;

    int result = square(i); 
    // functional macro will be called 
    // because preprocessor will run before compiler 
    printf("--------------------\n");

    int result_2 = (square)(i);
    // function will be called
    printf("--------------------\n");

    // output ->
    //  --------------------
    //  real function called
    //  --------------------
  }
*/

/*
  #define  swap_1(a, b)     { int temp = a; a = b; b = temp; }
  #define  swap_2(a, b)   do{ int temp = a; a = b; b = temp; } while(0)

  int main(void){
    int x = 10, y = 20;

    swap_1(x, y); // valid
    // { int temp = x; x = y; y = temp; };

    printf("x = %d, y = %d\n", x, y);  // output -> x = 20, y = 10

    // <---- PROBLEM ---->
    if (x > 10)
      swap_1(x, y);   // syntax error
    else
      x++;
    // error : 'else' without a previous 'if'

    // if (x > 10){
    //   int temp = x; x = y; y = temp;
    // };   -> null statement broke the if-else statement's syntax
    // else
    //   x++;


    // <---- SOLUTION ---->
    if (x > 10)
      swap_2(x, y); 
    else
      x++;

    // if (x > 10)
    //   do
    //   {
    //     int temp = x; x = y; y = temp;
    //   } while (0);
    // else
    //   x++; 
  }
*/

/*
  Why macros are used ?

  1. can generate less machine code
  2. complicated expressions can be simplified
    #define   get_elem(a, b)    ptr->ar[a][b].x  

  3. code can be optimized by compiler better
    Scenario 1:
    ------------
    code 
    code
    foo();
    code 
    code    
    -> in this scenario compilers optimizer have less space to optimize

    Scenario 2:
    ------------
    code
    code
    code
    code
    code
    -> in this scenario compilers optimizer have more space to optimize
*/

/*
        ------------------------------------------------------
        | comparison between functional macros and functions |
        ------------------------------------------------------
*/

/*
  functional macros  
  -----------------
  a. not functions, they are replacment of functions
  b. tends to enlarge the code (kodu büyütme eğiliminde)
    when a function has been called for 10 times in the code
    only entry and exit codes will be generated by the compiler 
    for 10 times and functions inner code will be generated for 1 time
    But when a functional macro has been used for 10 times
    its inner code (which is much larger than entry and exit codes)
    will be generated for 10 times.

  c. hatalı kod yazma riski (risk of writing wrong code)
  d. NOT debugger friendly
  e. functional macros are generic (type independent)
  f. functional macros DO NOT have addresses


  functions
  --------- 
  a. lowers risk of writing wrong code (hatalı kod yazma riski azalır)
  b. debugger friendly
  c. functions are type dependent
  d. functions have addresses (function pointers)
*/

/*
                    --------------------------
                    | preprocessor operators |
                    --------------------------
*/

/*
  #   -> stringizing/stringification operator (dizge yapma operatörü)
  ##  -> token pasting operator (atom yapıştırma operatörü)
  defined -> defined operator 
*/

/*
  #define  STR(x)    #x

  int main(void){
    printf(STR(hello world));  // output -> hello world
  }
*/

/*
  int main(void){
    printf(
      "Istanbul "
      "Ankara "
      "Izmir"
    );  
    // output -> Istanbul Ankara Izmir

    printf("\nIstanbul Ankara Izmir");  
    // output -> Istanbul Ankara Izmir

    // both printf() calls are same
  }
*/

/*
  int main(void){
    printf("[1]kayit ekle\n[2]kayit sil\n[3]kayit ara\n[4]menuden cik\n");

    printf(
      "[1]kayit ekle\n"
      "[2]kayit sil\n"
      "[3]kayit ara\n"
      "[4]menuden cik\n"
    );
    // both printf() calls are same

    // output ->
    //  [1]kayit ekle
    //  [2]kayit sil
    //  [3]kayit ara
    //  [4]menuden cik
  }
*/

/*
  #define  iprint(i)  printf("%d\n", i)

  int main(void){
    int x = 10, y = 20, z = 30;

    printf("%d\n", x);                      // output -> 10
    printf("%d\n", x + y);                  // output -> 30
    printf("%d\n", x + y + z);              // output -> 60
    printf("%d\n", x * x + y * y + z * z);  // output -> 1400

    iprint(x);                              // output -> 10
    iprint(x + y);                          // output -> 30
    iprint(x + y + z);                      // output -> 60       
    iprint(x * x + y * y + z * z);          // output -> 1400
  }
*/

/*
  #define  iprint(i)  printf(#i " = %d\n", i)

  int main(void){
    int x = 10, y = 20, z = 30;

    printf("x = %d\n", x);                    
    printf("x + y = %d\n", x + y);                 
    printf("x + y + z = %d\n", x + y + z);             
    printf("x * x + y * y + z * z = %d\n", x * x + y * y + z * z); 

    iprint(x);                          
    iprint(x + y);                         
    iprint(x + y + z);                        
    iprint(x * x + y * y + z * z);         

    // output ->
    //  x = 10
    //  x + y = 30
    //  x + y + z = 60
    //  x * x + y * y + z * z = 1400
  }
*/

/*
  #define   UNITE(x, y)    x##y

  int main(void){
    int odd_sum = 0;

    UNITE(odd_, sum)++;
    // odd_sum++ -> compiler sees

    printf("odd_sum = %d", odd_sum);  // output -> odd_sum = 1
  }
*/

/*
  // önişlemci programa bir fonksiyon tanımı kodu yazdıracak
  // bir fonksiyonel makro oluşturmak
  #define generate_max_1(t)   t max(t x, t y){        \
                              return x > y ? x : y; \
                            }

  generate_max_1(int)
  generate_max_1(double)
  generate_max_1(long)
  generate_max_1(unsigned)
  //  syntax error -> function overloading is not allowed in C language


  #define generate_max_2(t)   t max_##t(t x, t y){        \
                              return x > y ? x : y;       \
                            }

  generate_max_2(int)       // max_int()
  generate_max_2(double)    // max_double()
  generate_max_2(long)      // max_long()
  generate_max_2(unsigned)  // max_unsigned()
*/

/*
            ---------------------------------------------
            | constantly used functional macro examples |
            ---------------------------------------------
*/

/*
  #include <stddef.h>

  struct Data{
    int x, y, z;
    double d;
  };

  int main(void){
    // offsetof() is a functional macro
    offsetof(struct Data, y); 
    ((size_t)&((struct Data *)0)->y); // same as above
  }
*/

/*
  #define   asize(x)   (sizeof(x) / sizeof(x[0]))

  int main(void){
    int a[] = {1, 5, 3, 6, 4, 9};

    sizeof(a) / sizeof(a[0]);  
    asize(a);  // same as above
  }
*/

/*
              -------------------------------------------
              | conditional compiling (koşullu derleme) |
              -------------------------------------------
*/

/*
  Using preprocessor directives for compiler 
  to compile different parts of the code.
  
  -> hardware differences
  -> operating system differences
  -> programming language differences
  -> version differences
  -> localization differences
  ...  
  -> debug and release versions
    debug version have assertion codes release does not
*/

/*
  #if pp_expr
    code
    directives
  #endif

  #if 1 

  #include <stdio.h>
  #define   SIZE  100
  int foo(int);

  #endif
*/

/*
  int main(void){
  #if 0
    prinf("hello world\n");
  #endif

  #if 1
    printf("hello galaxy\n");
  #endif
  } // output -> hello galaxy
*/

/*
  int main(void){
  #if 1
    printf("Istanbul\n");
  #else
    printf("Ankara\n");
  #endif

    // output -> Istanbul 
  }
*/

/*
  #define   SIZE  100

  int main(void){
  #if SIZE > 20
    printf("SIZE is greater than 20\n");
  #endif

    // output -> SIZE is greater than 20
  }
*/

/*
  #define   AAA  100
  #define   BBB  200

  int main(void){
  #if AAA > 90 && BBB < 180
    printf("IF directive\n");
  #else
    printf("ELSE directive\n");
  #endif
    // output -> ELSE directive
  }
*/

/*
  #define   AAA  100
  #define   BBB  200

  int main(void){
  #if AAA + BBB > 250
    printf("IF directive\n");
  #else
    printf("ELSE directive\n");
  #endif
    // output -> IF directive
  }
*/

/*
  #define   AAAA
  #define   BBBB    1000

  int main(void){
  #ifdef  AAAA
    printf("AAAA is defined\n");
  #endif

  #ifdef  BBBB
    printf("BBBB is defined\n");
  #endif

  #ifdef  CCCC
    printf("CCCC is defined\n");
  #endif

  // output ->
  //  AAAA is defined
  //  BBBB is defined
  }
*/

/*
  #define   AAAA

  int main(void){
  #ifdef  AAAA
    printf("AAAA is defined\n");
  #else
    printf("AAAA is not defined\n");
  #endif

  #ifdef  CCCC
    printf("CCCC is not defined\n");
  #else
    printf("CCCC is not defined\n");
  #endif

  // output ->
  //  AAAA is defined
  //  CCCC is not defined
  }
*/

/*
  #define  AAAA

  int main(void){
  #ifdef  AAAA
    printf("AAAA is defined\n");
  #endif

  #if defined(AAAA)
    printf("AAAA is defined\n");
  #endif

  // output ->
  //  AAAA is defined
  //  AAAA is defined 

  // #ifdef AAAA <==> #if defined(AAAA)
  }
*/

/*
  int main(void){
  #ifndef  DEBUG
    printf("DEBUG is not defined\n");
  #endif

  #if !defined(DEBUG)
    printf("DEBUG is not defined\n");
  #endif

  // output ->
  //  DEBUG is not defined
  //  DEBUG is not defined 

  // #ifndef DEBUG <==> #if !defined(DEBUG) 
  }
*/

/*
  #define  XXXX
  #define  YYYY

  // <--- 1st way --->
  int main(void){
  #ifdef XXXX 
  #ifdef YYYY
    printf("both are defined\n");
  #endif
  #endif

  // <--- 2nd way --->
  #if defined(XXXX) && defined(YYYY)
    printf("both are defined\n");
  #endif
  // better using defined operator in this scenario

  // output -> 
  //  both are defined
  //  both are defined
  }
*/

/*
  #define   DEBUG
  // if we define DEBUG macro, we can see the codes inside #if DEBUG
  // else compiler will ignore those codes

  int main(void){
  #ifdef DEBUG
    printf("DEBUG_1\n");
  #endif

  #ifdef DEBUG
    printf("DEBUG_2\n");
  #endif

  #ifdef DEBUG
    printf("DEBUG_3\n");
  #endif

    // output ->
    //  DEBUG_1
    //  DEBUG_2
    //  DEBUG_3
  }
*/

/*
  #define NDEBUG  // need to define if we want to use assert macro
  #include <assert.h>
*/

/*
  // without #elif directive
  #define     TL     1
  #define     USD    2
  #define     EUR    3
  #define     GBP    4
  #define     JPY    5

  #define     CUR    TL

  #if CUR == TL
    #define CURRENCY "TL"
  #else
  #if CUR == USD
    #define CURRENCY "USD"
  #else
  #if CUR == EUR
    #define CURRENCY "EUR"
  #else
  #if CUR == GBP
    #define CURRENCY "GBP"
  #else
  #if CUR == JPY
    #define CURRENCY "JPY"
  #endif
  #endif
  #endif
  #endif
  #endif

  int main(void){
    printf("CURRENCY = %s\n", CURRENCY);
    // output -> CURRENCY = TL
  }
*/

/*
  // with elif directive
  #define     TL     1
  #define     USD    2
  #define     EUR    3
  #define     GBP    4
  #define     JPY    5

  #define     CUR    JPY

  #if CUR == TL
    #define CURRENCY "TL"
  #elif CUR == USD
    #define CURRENCY "USD"
  #elif CUR == EUR
    #define CURRENCY "EUR"
  #elif CUR == GBP
    #define CURRENCY "GBP"
  #elif CUR == JPY
    #define CURRENCY "JPY"
  #endif

  int main(void){
    printf("CURRENCY = %s\n", CURRENCY);
    // output -> CURRENCY = JPY
  }
*/

/*
                  ----------------------------
                  | multiple inclusion guard |
                  ----------------------------
*/

/*
  // bazı bildirimlerin ikinci defa yapılması sentaks hatası değildir
  // some declarations can be done more than once
  int foo(int);
  int foo(int);


  // bazı bildirimlerin ikinci defa yapılması sentaks hatasıdır
  // some declarations can not be done more than once
  struct Data{
    int x, y, z;
  };
  struct Data{
    int x, y, z;
  };
  // syntax error: redefinition of 'struct Data


  #include "example.h"
  #include "example.h"
  // syntax error: redefinition of 'struct Data_2
*/

/*
  #include "example2.h"
  #include "example2.h"
  // no syntax error

  #include "example3.h"
  #include "example3.h"
  // no syntax error
*/

/*
  #pragma once 
  // is also used for multiple inclusion guard
  // this directive IS NOT standard
  // it IS NOT supported by all compilers
*/

/*
                        ----------
                        | #undef |
                        ----------
*/
/*
  #undef  SIZE
  #undef  SQUARE    // if SQUARE() is a functional macro
  #undef  DEBUG    
*/

/*
  #define   SIZE  100
  // code
  // code
  // code
  #define   SIZE  200 
  // code

  // undefined behaviour(UB) -> redefinition of 'SIZE'
*/

/*
  void foo(void)
  {
  #define SIZE 100
  }

  void bar(void)
  {
  #define SIZE 500
  }

  // undefined behaviour(UB) -> redefinition of 'SIZE'
  // macros does not have scope
*/

/*
  void foo(void){
  #undef SIZE
  #define SIZE 100

  // code

  #undef SIZE
  }

  void bar(void){
  #undef SIZE
  #define SIZE 500

  // code

  #undef SIZE
  }

  // SIZE macro kind of have scope in this scenario
*/

/*
  #define  XXXX

  int main(void){
  #ifdef  XXXX
    printf("XXXX seen once\n");
  #endif

  #undef  XXXX
  #ifdef  XXXX
    printf("XXXX seen twice\n");
  #endif

  // output -> XXXX seen once
  }
*/