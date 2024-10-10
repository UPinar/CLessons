#include <stdio.h>

/*
                  -------------------------
                  | traditional enterence |
                  -------------------------
*/

/*
  #include <stdio.h>
  // preprocessor will copy declerations from stdio.h to the beginning
  // .h -> header file

  int main(void)
  {
    printf("hello world\n");
  }

  // defined a function idenfied as main
  // called a function identified as prinf inside main function
*/

/*
  function -> fonksiyon (işlev, yordam)

  <---- Check global_local_namespaces.png ---->
  global namespace  -> includes everything 
  local namespace   -> a space inside functions

  -> to define a function   (fonksiyonu tanimlamak) 
  function definition : writing the code of the function

  -> to call a function     (fonksiyonu cagirmak)   
  function call : such an expression that runs the code of the function
  
  -> to declare a function  (fonksiyonu bildirmek)
  function declaration - function prototype : 
    for compiler to know the identifier of the function
*/

/*
  int main(void)  
  {
    // the main block of a function

    {
      // nested block
    } 

    // main block

    {
      // nested block
    }

    // main block
  }
*/

/*
  #include <stdio.h>

  int printf(const char*, ...); 
  // printf function declaration is coming from stdio.h

  int main(void)    // function definition 
  {
    printf("Hello world\n");  // function call
  }
*/

/*
                  =============================
                  | basic types of C language |
                  =============================
*/

/*
  <---- Check basic_types_c.png ---->

  _Bool type (1 byte)

  char types (1 byte) 
  -------------------
    signed char       -128 - 127
    unsigned char        0 - 255
    char  (depends on compiler, it can be signed or unsigned)

  short int types (2 byte)
  -----------------------
  signed short
  unsigned short

  int types (4 byte) 
  -----------------
  signed int 
  unsigned int

  long int types (4 byte)
  ----------------------
  signed long 
  unsigned long

  long long int types (8 byte)
  ---------------------------
  signed long long 
  unsigned long long 


  C STANDART RULES FOR COMPILERS :
  ---------------------------------
    * char = 1 byte 
    * short <= int <= long <= long long
    * long long >= 8 byte
  
  Compiler_1 Example :
  char        1 byte
  short       2 byte 
  int         2 byte
  long        4 byte
  long long   8 byte 

  Compiler_2 Example (Most Common):
  char        1 byte
  short       2 byte 
  int         4 byte
  long        4 byte
  long long   8 byte 
*/

/*
  #include <stdio.h>

  int main(void)
  {
    printf("sizeof(char) = %zu\n", sizeof(char)); 
    printf("sizeof(_Bool) = %zu\n", sizeof(_Bool));
    printf("sizeof(short) = %zu\n", sizeof(short));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(long long) = %zu\n", sizeof(long long));

    // output -> compiled with gcc compiler
    // sizeof(char)       = 1
    // sizeof(_Bool)      = 1
    // sizeof(short)      = 2
    // sizeof(int)        = 4
    // sizeof(long)       = 4
    // sizeof(long long)  = 8
  }
*/

/*
  #include <stdbool.h>  

  int main(void)
  {
    _Bool flag;
    flag = 0;
    flag = 1;
    // if we did not include <stdbool.h> header file we can only 
    // use 0 and 1 to assign _Bool variable

    _Bool headerAddedFlag;
    headerAddedFlag = true;
    headerAddedFlag = false;
  }
*/

/*
  float
  double 
  long double

  -> there is no unsigned in floating types 
  -> generally IEEE754 is used for implementation but it is not a 
  standart for compilers 
*/

/*
  int main(void)
  {
    printf("sizeof(float) = %zu\n", sizeof(float)); 
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("sizeof(long double) = %zu\n", sizeof(long double));

    // output -> compiled with gcc compiler
    //  sizeof(float) = 4
    //  sizeof(double) = 8
    //  sizeof(long double) = 12
  }
*/

/*
          ---------------------------------------------------
          | declaration(bildirim) and definition(tanimlama) |
          ---------------------------------------------------
*/

/*
  -> If a declaration makes compiler to allocate space for an 
    object, it will also be called definition.

  -> If compiler is NOT allocating space for an object 
    in a declaration, it has been called non-defining declaration

  -> All definitions are declarations but not all declarations 
    are definitions.
*/

/*
  int main(void)
  {
    a = 5
    // Question : When does the compiler understands 
      "a" is an identifier?
    // Answer : In tokenizing phase (Lexical analysis)

    // When compiler finds out that an identifier has been used 
    // in an expression, it has to understand which object(entity)
    // is that identifier has been related to. 
    // This phase is called name lookup

    // 1. Name lookup
    // 2. Context control
  }
*/

/*
  int main(void)
  {
    int x = 6;  // this is not an assignment -> initialization
    x = 12;     // this is an assignment 
  }
*/

/*
  int main(void)
  {
    double dval;      // definition of dval but not initialized
    int ival = 123;   // definition with initialization
  }
*/

/*
  Those keyword or keywords can be used in type declarations
  ----------------------------------------------------------
  signed 
  unsigned 
  char
  _Bool
  short
  int
  long
  float
  double
*/

/*
  -----------------------------------------
  _Bool
  -----------------------------------------
  char
  -----------------------------------------
  signed char
  -----------------------------------------
  unsigned char
  -----------------------------------------
  signed short int
  signed short
  short int
  short
  -----------------------------------------
  unsigned short int
  unsigned short
  -----------------------------------------
  singed int
  int
  signed
  -----------------------------------------
  unsigned int 
  unsigned
  -----------------------------------------
  signed long int
  signed long
  long int
  long
  -----------------------------------------
  unsigned long int
  unsigned long
  -----------------------------------------
  signed long long int
  signed long long
  long long int
  long long                     
  -----------------------------------------
  unsigned long long int
  unsigned long long        
  -----------------------------------------
  float
  -----------------------------------------
  double
  -----------------------------------------
  long double
  -----------------------------------------
*/

/*
  -> keywords can not be used as an identifier
  -> C standarts reserved names can not be used as an identifier 
    starts with double underscore __
    starts with underscore and a capital letter _B, _F, _K
*/

/*
  int main(void)
  {
    int x, y, z; // comma seperated list

    int a, double b, c; // syntax error 
    // all types must be same in comma seperated list
  }
*/

/*
                  --------------------
                  | storage duration |
                  --------------------
*/

/*
  Term : storage duration (lifespan)

  static duration     (static storage class)
    -> from program start till the program end 
  automatic duration  (automatic storage class)
    -> when a specific code running it stays in the memory then die
  dynamic duration    (dynamic storage class)
    -> when program running, a unique code will set those memory
*/

/*
  int g_x;  // global variable  -> static storage duration

  void func(void)
  {
    static int s_x; // static local variable -> static storage duration
    int y;  // local variable -> automatic storage duration
  }

  int main(void)
  {

  }
*/

/*
  int global_x; 

  int main(void)
  {
    static int local_static_y;

    printf("global_x = %d\n", global_x); 
    // output -> global_x = 0
    printf("local_static_y = %d\n", local_static_y); 
    // output -> local_static_y = 0
  }

  // variables which have static storage duration and 
  // is not initialized when defined, will have a value of 0.
*/

/*
  int main(void)
  {
    int x;  // local variable -> automatic storage duration
    // starts its life with an indeterminate(garbage) value
  }
*/

/*
  int main(void)
  {
    int x;
    int y = x + 5;  // undefined behaviour (using indeterminate value)
  }
*/

/*
  int main(void)
  {
    int x;
    ++x; // undefined behaviour (using indeterminate value)
  }
*/

/*
  undefined behaviour (tanımsız davranış)
    There is no guarantee in run-time, what will happen in the program.
    -> using indeterminate value
    -> overflow and underflow in signed integer types
    -> dividing by 0
    -> x << y  if (y >= x) 

  In optimization phase, compiler assumes that there is not any
  undefined behaviour in the code!
*/

/*
  int main(void)
  {
    int a;
    int b = 0;

    int y = a / b;  // if b = 0 -> undefined behaviour

    // always false condition
    if (b == 0){  
      // some code
    }
    // if-block will be deleted by the compiler in optimization  
    // because there is no chance that "b" variable can be 0  
    // in "int y = a / b;" statement
  }
*/

/*
  int g_x = 10;   // valid
  int g_y = g_x;  // syntax error : initializer element is not constant

  int main(void)
  {
    int k = 5;          // valid
    static int s_l = k; // syntax error
  }

  // static storage duration variables can only be initialized 
  // with constant expression
*/

/*
  int main(void)
  {
    int x = 5;                    // initialization
    int a = 2, b = 3, c = a + b;  // initialization 

    int y = x + 5;
    int z = x * y - 3;
  }

  // for local storage duration variables initialization with 
  // constant expression is not needed
*/

/*
  int g_z = 5;

  void func(void)
  {
    int x = 5;
    static int y = 5;

    printf("x = %d, y = %d, g_z = %d\n", x, y, g_z);

    ++x;
    ++y;
    ++g_z;
  }

  int main(void)
  {
    func();   //  x = 5, y = 5, g_z = 5
    func();   //  x = 5, y = 6, g_z = 6
    func();   //  x = 5, y = 7, g_z = 7
  }
*/

/*
                -----------------------------------
                | scope (kapsam - faaliyet alani) |
                -----------------------------------
  -> Scope is a concept about identifiers, not variables
  -> Every identifier have a scope 
  -> Scope is a compile time concept

  If we use an identifier out of its scope, compiler 
  can not relate that identifier with declared one.
*/

/*
  1. file scope
  2. block scope
  3. function prototype scope
  4. function scope
*/

/*
  int x = 10;

  int main()
  {
    x = 5;  // name lookup will find global variable x 
  }

//  x:
//    .long 10
//  main:
//    push rbp
//    mov rbp, rsp
//    mov DWORD PTR x[rip], 5
//    mov eax, 0
//    pop rbp
//    ret

*/

/*
  int x = 10;

  int main()
  {
    x(); // syntax error 
    // called object 'x' is not a function or function pointer

    // name lookup will find identifier x in the file scope 
    // context control phase will be fail
  }
*/

/*
  int x = 10;     // x is an identifier and it is in file scope

  void foo(void)  // foo is an identier and it is in file scope
  {

  }

  typedef int Word; // Word is an identifier and it is in file scope
*/

/*
  x = 20; // NOT VALID, 
  // x identifier has been used before its declaration
  // name lookup will fail

  int x = 10;     // syntax error : redefinition of 'x'

  void foo(void)  
  {
    x = 30; // valid
  }

  x = 40; // valid 

  void bar(void)
  {
    x = 50; // valid
  }

  x = 60; // valid
*/

/*
  int main(void)
  {
    if (1){ // enclosing block
      {
        // nested block
      }
    }

  }

  // There are 3 blocks in this code 
*/

/*
  int main(void)
  {
    int x; // x identifier can be used in main functions block scope

    // a identifier can not be used in main functions block scope (1)

    {
      // a identifier can not be used before its declearation  (2)

      int a = 5;

      // a identifier can be used after its decleration and inside 
      // its block scope (3)
    }
  }
*/

/*
  int main(void)
  {
    int a;

    {

      {

        int b;

        {
          int c;
          int d;
        }
      }
    }
  }

  // a, b, c identifiers are in block scope 
  // but their scopes are not same

  // If two identifier are in the same block scope, their scopes are 
  // in opening and closing braces of that block

  // c, d identifiers are both in block scope 
  // and their scopes are same.
*/

/*
  a = 3;  // not valid

  void foo(int a)
  {
    a = 5;  // valid
      // a identifier is in the block scope of foo function 

    int b;  
    // a and b identifiers are in the same block scope  
  }
*/

/*
  int x = 5;
  double x = 3.14;
  // NOT VALID, identifiers are in the same scope

  int foo = 4;
  void foo(void)
  {

  }
  // NOT VALID, identifiers are in the same scope
*/

/*
  int a = 111;

  int main(void)
  {
    a = 222;  // assigning to global variable

    int a = 555;
    a = 777;  // assigning to local variable
  }
  // both identifiers are different variables

  //  a:
  //    .long 111
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR a[rip], 222
  //    mov DWORD PTR [rbp-4], 555
  //    mov DWORD PTR [rbp-4], 777
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int a = 111;

  int main(void)
  {
    int a = 222;
    {
      int a = 333;
    }
  }
  // all 3 identifiers are different variables

  // a:
  //   .long 111
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   mov DWORD PTR [rbp-4], 222
  //   mov DWORD PTR [rbp-8], 333
  //   mov eax, 0
  //   pop rbp
  //   ret
*/

/*
  void func(int a)
  {
    int a = 9;
    // NOT VALID, both identifiers are in the same block scope
  }
*/

/*
  void foo(void)  // function name foo identifier is in file scope
  {
    int foo = 5;  // variable identifier is in block scope
    // VALID CODE
  }
*/

/*
  // 5 file scope
  int main()
  {
    // 4 - enclosing block scope
    {
      // 3 - enclosing block scope
      {
        // 2 - enclosing block scope
        {
          // 1 - block scope
          a = 5;
        }
      }
    }
  }

  // name lookup will be done from 1 to 5.
  // Once its find the identifier, name lookup phase is DONE.
  // It will continue with context control, 
  // name lookup will NEVER start again.
*/

/*
  int a = 111;  
  // a identifier in block scope will hide a identifier in file scope
  // It has been called NAME HIDING, NAME MASKING, NAME SHADOWING

  int main(void)
  {
    int a = 222;
    a = 333;  // assigning to local variable a
  }

  // a:
  //   .long 111
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   mov DWORD PTR [rbp-4], 222
  //   mov DWORD PTR [rbp-4], 333
  //   mov eax, 0
  //   pop rbp
  //   ret
*/

/*
  int main(void)
  {
    int x = 5;

    if (x > 2){
      int x = 3;
      x = 111;
    }
  }

  // main:
  //   push rbp
  //   mov rbp, rsp
  //   mov DWORD PTR [rbp-4], 5
  //   cmp DWORD PTR [rbp-4], 2
  //   jle .L2
  //   mov DWORD PTR [rbp-8], 3
  //   mov DWORD PTR [rbp-8], 111
  // .L2:
  //   mov eax, 0
  //   pop rbp
  //   ret
*/

/*
  int x = 111;

  int main(void)
  {
    printf("[1] - %d\n", x);
    int x = 222;
    printf("[2] - %d\n", x);

    {
      printf("[3] - %d\n", x);
      int x = 333;
      printf("[4] - %d\n", x);
    }

    printf("[5] - %d\n", x);
  }

  // output 
  // [1] - 111
  // [2] - 222
  // [3] - 222
  // [4] - 333
  // [5] - 222
*/

/*
  int x = 111;

  int main(void)
  {
    int x = x;  
    // initialization happening inside the block scope
    // so x will initialize with its indeterminate(garbage) value
    ++x;  // undefined behaviour
  }

  // x:
  //   .long 111
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   add DWORD PTR [rbp-4], 1
  //   mov eax, 0
  //   pop rbp
  //   ret
*/

/*
                  --------------------------------
                  | naming - naming conventions |
                  --------------------------------
*/

/*
  -> variables should not be named ALLCAPS, 
  generally it has been used in preprocessor program.
  
  snake case -> tax_increase_rate
  camel case -> taxIncreaseRate

  -> do not use bilingual naming 
  -> do not use similar names in different variables
  -> use more descriptive names when the scope of the variable is wide
*/