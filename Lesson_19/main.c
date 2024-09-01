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
              -------------------------------------------
              | conditional compiling (koşullu derleme) |
              -------------------------------------------
*/

/*
  #include "conditional.h"

  int main(void){
    int x = foo(11);    // syntax error
    // error: implicit declaration of function 'foo'
    int y = bar(22);    // valid 
  }
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