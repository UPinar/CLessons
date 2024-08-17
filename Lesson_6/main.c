#include <stdio.h>
/*
                  ----------------------------
                  | functions (fonksiyonlar) |
                  ----------------------------
*/

/*
  pure function : function which is not changing the 
    state of the program

  -> to define a function (function definition)
  -> to call a function (function call)
  -> to declare a function (function decleration - function prototype)
*/

/*
  how functions are returning value to caller code 
    1. return value
    2. call by reference (out parameter)
    3. global variable
*/

/*
                  ------------------------------
                  | function definition syntax |
                  ------------------------------
*/

/*
  // return value type
  // identifier
  // parameter paranthesis
  // parameter variable(s)

  double get_circle_area(double radius)
  {
    // code
  }
*/

/*
  int foo(int x, y, z);           // syntax error
  int foo(int x, int y, int z);   // valid
*/

/*
  // implicit (gizli, kapalı, örtülü)
  // explicit (açık açık yazarak)

  // IMPLICIT INT, removed in C99 but still okay because of 
  // backward compatibility but compiler will give warning
  // function's return type is int 

  foo (int x)
  {
    // code
  }
  // warning: return type defaults to 'int' [-Wimplicit-int]
*/

/*
  // void function 
  void func(int x)
  {

  }
*/

/*
  int sum(int x, int y)
  {
    return x + y;
  }
  // int x and int y are parameter variables (parameters)

  int main(void)
  {
    int a = 6, b = 8;
    int c = sum(a, b);  // a and b are arguments 
  }

  // arguments will be copied to parameter variables 
  // when the function call will be done.
*/

/*
  // functions do not need to have a parameter variable(s)
  // It is better adding void type inside parameter paranthesis
  int func(void)
  {

  }
*/

/*
  // Can not define another function inside a function definition!
  // "nested function" concept is not valid in C and C++

  void foo(void)
  {
    void bar(void)  // NOT VALID
    {
      // SYNTAX ERROR!
    }
  }
*/

/*
  // function overloading is NOT VALID in C, but valid in C++

  void func(int x)
  {

  }

  void func(double x)
  {

  }
  // syntax error : conflicting types for 'func'
*/

/*
  // parameter variables are in block scope
  // have an automatic storage duration
  void func(int x)
  {
    double x;  // syntax error
  }

  // parameter variables CAN NOT have static storage duration
*/

/*
  void foo(int x)
  {
    // statement 1
    // statement 2
    // statement 3
    // statement 4
  }

  // compiler can change order of the statements or delete some of them
  // inside function body if the observable behaviour is not changing 
  // it has been called (as if rule)
*/

/*
                  -------------------------
                  | statements (deyimler) |
                  -------------------------
*/

/*
  expression statement (ifade deyimi)
  compound statement  (bileşik deyim)
  null statement (boş deyim)
  control statement (kontrol deyimi)
*/

/*
  ++x;    // expression statement
  a = 5;  // expression statement 
  a;      // expression statement
  a + 5;  // expression statement

  ;       // null statement

  {
    x = 5;
    y = 4;
    z = 2;
  }
  // compound statement 


  // control statements have a defined syntax
  // control statement have minimum 1 keyword
  // control statements can change the control flow of the program 

  // if statement           -> control statement 

  // loop statements        -> control statement 
  //    while statement
  //    do while statement
  //    for statement

  // break statement        -> control statement 
  // continue statement     -> control statement 

  // switch statement       -> control statement 
  // goto statement         -> control statement 

  // return statement       -> control statement 

  C have 9 control statement.
*/

/*
                    --------------------
                    | return statement |
                    --------------------
*/

/*
  return;       // yalın(ifadesiz) return deyimi
  return expr;  // ifadeli return deyimi
*/

/*
  void func(int x)
  {
    // code 
    return; 
  }
  // void functions can have return statement without expression
  // if return statement is not needed(redundant) do not use it!
*/

/*
  1. return statement with an expression will stop function to run
  2. it will return the expression as return value 
*/

/*
  // one-liner function 
  int sum(int x, int y)
  {
    return x + y; 
  }
*/

/*
  int func(int x, int y)
  {
    return x + y;

    x +=y;    // unreachable code (logic error)
    return x; // unreachable code (logic error)
  }
*/

/*
  int max2(int x, int y)
  {
    if (x > y)
      return x;

    return y;
  }

  int max3(int x, int y, int z)
  {
    int max = x;

    if (y > max)
      max = y;

    if (z > max)
      max = z;

    return max;
  }

  // Those functions are pure functions, no state change will 
  // happen in the program
*/

/*
  int ndigit(int x)
  {
    if (x == 0)
      return 1;

    int digit_count = 0;
    
    while (x != 0){
      ++digit_count;
      x /= 10;
    }

    return digit_count;
  }
*/

/*
  1. The reason for the existence of the function is to calculate 
  a value and the return value is the calculated value.
  Ex : get_circle_area, get_abs, get_max ...

  2. The reason for the existance of the function is answering
  a question(yes-no, true-false, valid-invalid)
  -> test, query, predicate function
  Ex : isprime, iseven, isodd, hasattribute ...
*/

/*
  // <---- check boolean_int_function.png ---->
  
  int isprime(int x)
  {
    // if not prime return 0
    // else return non-zero (1, -1..)

    // when the number is prime function will return non-zero
    // when the number is not prime function will return 0
  }
*/

/*
  // old style function definition

  double func(a, b, c)
  double a, b;
  float c;
  {
    return a * b + c;
  }

  foo(a, b, c)
  {
    return a * b + c;
  }
  // both return type and parameters are implicitly int
*/

/*
                  -----------------
                  | function call |
                  -----------------
  function call is an expression (ifade)
*/

/*
  int sum(int x, int y)
  {
      return x + y;
  }

  int main(void)
  {
      int a = 10, b = 20;
      sum(a * a, b * b);
  }

  // compiled with ==> x86-64 gcc 14.1 -O0
  // sum:
  //   push rbp
  //   mov rbp, rsp
  //   mov DWORD PTR [rbp-4], edi
  //   mov DWORD PTR [rbp-8], esi
  //   mov edx, DWORD PTR [rbp-4]
  //   mov eax, DWORD PTR [rbp-8]
  //   add eax, edx
  //   pop rbp
  //   ret
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   sub rsp, 16
  //   mov DWORD PTR [rbp-4], 10
  //   mov DWORD PTR [rbp-8], 20
  //   mov eax, DWORD PTR [rbp-8]
  //   imul eax, eax
  //   mov edx, eax
  //   mov eax, DWORD PTR [rbp-4]
  //   imul eax, eax
  //   mov esi, edx
  //   mov edi, eax
  //   call sum
  //   mov eax, 0
  //   leave
  //   ret
*/

/*
  int sum(int x, int y)
  {
      return x + y;
  }

  int main(void)
  {
      int a = 10, b = 20;

      sum(a, b);
      // sum(a, b) expressions type is "int" 
      // because functions return value type is int

      // sum(a, b) expressions value is 30 
      // functions return value is 30
  }
*/

/*
  int max2(int x, int y){
    return (x > y) ? x : y;
  }

  int main(void){
    int a = 25, b = 33;

    max2(25, 33); 
    // discarding return value is logic error in this context

    printf("hello world");
    // printf function, also have a return type but discarding it 
    // is not a logic error in this context
  }

  // compiled with ==> x86-64 gcc 14.1 -O0
  // max2:
  //   push rbp
  //   mov rbp, rsp
  //   mov DWORD PTR [rbp-4], edi
  //   mov DWORD PTR [rbp-8], esi
  //   mov edx, DWORD PTR [rbp-8]
  //   mov eax, DWORD PTR [rbp-4]
  //   cmp edx, eax
  //   cmovge eax, edx   -> https://www.felixcloutier.com/x86/cmovcc
  // 0F 4D /r 	CMOVGE r32, r/m32 	Move if greater or equal (SF=OF).
  //   pop rbp
  //   ret
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   sub rsp, 16
  //   mov DWORD PTR [rbp-4], 25
  //   mov DWORD PTR [rbp-8], 33
  //   mov esi, 33
  //   mov edi, 25
  //   call max2
  //   mov eax, 0
  //   leave
  //   ret
*/

/*
  int ndigit(int);

  int main(){
    int x = 10, y = 5, z = 222;

    // if functions return value will not be used in the code 
    // again it is better using it as sub-expression
    if (ndigit(x) > ndigit(y)){
      // code
    }

    // if functions return value will be used more than once
    // better hold the return value in a variable
    int ival = ndigit(z);
  }
*/

/*
  int foo(int);
  int bar(int);

  int main(void)
  {
    int x = 5, y = 4;

    int z = foo(x) + bar(y) * 5;
    // Question: foo or bar function will be called before ?
    // Answer: it depends on the compiler 
    // This situation has been called UNSPECIFIED BEHAVIOUR

    
  }
*/

/*
  int g_x = 20;

  int foo(int a){
    g_x += 80;
    return a * 3;
  }

  int bar(int a){
    return g_x + a;
  }

  int main(){
    int x = 5, y = 4;

    int z = foo(x) + bar(y);
    // if foo is called before z = 15 + 104 = 119
    // if bar is called before z = 24 + 15 = 39

    // this code's logic structure will be changed 
    // by the call orders of the functions 
  }
*/

/*
  Every implementation-defined should be unspecified behaviour
  but not every unspecified behaviour is implementation-defined.

  If it is an implementation-defined, it should be documented by
  the compiler and the compiler should generate the same code 
  everytime the same implementation-defined code runs.
*/

/*
  sizeof(int) // implementation-defined
  // sizeof(int) can be 2, 4, 8 byte in different compilers
  // it is implementation-defined and in every compiler it has been 
  // documented, changing compiler can change the programs behaviour.

  char // implementation-defined
  // char type can be unsigned char or signed char
  // in different compilers

  x >> 3  // implementation-defined if x is a negative integer
  // 1000'0101 -> 1111'0000 -> can be feed by 1's 
  // 1000'0101 -> 0001'0000 -> can be feed by 0's 
*/

/*
  int main(void){
    int x = 56;
    int y = 10;

    printf("Hello\n");                      // 1 argument
    printf("x = %d\n", x);                  // 2 arguments
    printf("%d + %d = %d\n", x, y, x + y);  // 4 arguments
    // printf is a variadic function
    // scanf is a variadic function
  }
*/

/*
  ... -> elipsis token, should be one and only in the last parameter
*/

/*
  void foo(int, int, int);  // foo is not a variadic function
  void bar(int, int, ...);  // bar is a variadic function
  void baz(...);    // NOT VALID function declaration
*/

/*
  void foo(int, int, ...);

  int main(){
    // min 2 arguments to call foo function

    foo();              // not valid 
    foo(1);             // not valid
    foo(1, 2);          // valid
    foo(1, 2, 3);       // valid
    foo(1, 2, 3, 4);    // valid
  }
*/

/*
  // main is also a function
  int main(void){

    return 0; 
    // returning 0 is telling that program succeeds 

    return 1; 
    // returning non-zero is telling that program fails.

    // after C99, return 0 will be added if we did not write.
  }
*/

/*
  int main(void){
    
    FILE* f = fopen("dataxyz.dat", "rb");
    if (f == NULL){
      fprintf(stderr, "can not open the file!\n");
      return 1; // returning error (exit code)
    }

    printf("file opened\n");
    // other code

    return 0; // returning success (exit code)
  }

  // main functions return value will return to operating system
*/

/*
                -------------------------------------
                | test functions (query, predicate) |
                -------------------------------------
*/

/*
  int isprime(int); // returns 0 or non-zero values

  int main()
  {
    int x;

    // <--- Check Lesson_14 if statements --->
    if (isprime(x));  // if the number is prime 
    if (!isprime(x));  // if the number is NOT prime
  }
*/

/*
  int isprime(int); // returns 0 or non-zero values

  int main()
  {
    int x, y;

    // <--- Check Lesson_14 if statements --->
    if (!!isprime(x) == !!isprime(y));  
    // because of there is no guarantee what isprime function
    // will return as non-zero numbers better using !! 
    // to check if return value's logical values are same
  }
*/

/*
  int iseven(int x){ return x % 2 == 0; }
  int isodd(int x){ return x % 2 != 0; }
*/

/*
  // leap year test (artık yıl testi)
  // divisible by 4 AND (not divisible by 100 OR divisible by 400)

  int isleap(int y)
  {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
  }
*/

/*
  // perfect number  
  // positive integer that is equal to the sum of its proper divisors
  // 6        1 + 2 + 3           = 6
  // 28       1 + 2 + 4 + 7 + 14  = 28

  int isperfect(int x)
  {
    int sum_div = 0;

    for (int i = 1; i <= x / 2; ++i)
      if (x % i == 0)
        sum_div += i;

    return x == sum_div;
  }

  int main(void){
    for (int i = 1; i < 10000; ++i)
      if (isperfect(i))
        printf("%d ", i);

    // output -> 6 28 496 8128
  }
*/

/*
                  --------------------------
                  | ctype <ctype.h> module |
                  --------------------------
*/

/*
  Character test functions
    -> int isupper(int c)   -> (A-Z)    
    -> int islower(int c)   -> (a-z)
    -> int isalpha(int c)   -> (A-Z || a-z)
    -> int isdigit(int c)   -> (0-9)
    -> int isalnum(int c)   -> (0-9 || A-Z || a-z) [alphanumeric]
    -> int isxdigit(int c)  -> (0-9 || A-F || a-f)
    -> int isspace(int c)   -> new-line, carriage return, 
      vertical && horizontal tab, form feed, space
    -> int isblank(int c)   -> space(' ') and horizontal tab('\t')
    -> int ispunct(int c)   -> printable - !alphanumeric
    -> int isprint(int c)   -> printable include space (' ')
    -> int isgraph(int c)   -> printable - exclude space(' ')
    -> int iscntrl(int c)   -> control characters
*/

/*
  #include <ctype.h>

  int main(void){

    // isupper()
    printf("isupper : ");
    for (int i = 0; i < 128; ++i){
    if (isupper(i))
      printf("%c", i);
    }
    putchar('\n');

    // islower()
    printf("islower : ");
    for (int i = 0; i < 128; ++i){
    if (islower(i))
      printf("%c", i);
    }
    putchar('\n');

    // isalpha()
    printf("isalpha : ");
    for (int i = 0; i < 128; ++i){
    if (isalpha(i))
      printf("%c", i);
    }
    putchar('\n');

    // isdigit()
    printf("isdigit : ");
    for (int i = 0; i < 128; ++i){
    if (isdigit(i))
      printf("%c", i);
    }
    putchar('\n');

    // isalnum()
    printf("isalnum : ");
    for (int i = 0; i < 128; ++i){
    if (isalnum(i))
      printf("%c", i);
    }
    putchar('\n');

    // isxdigit()
    printf("isxdigit : ");
    for (int i = 0; i < 128; ++i){
    if (isxdigit(i))
      printf("%c", i);
    }
    putchar('\n');
    
    // ispunct()
    printf("ispunct : ");
    for (int i = 0; i < 128; ++i){
    if (ispunct(i))
      printf("%c", i);
    }
    putchar('\n');

    // isspace() -> they are not visible 
    // will print their character codes
    printf("isspace : ");
    for (int i = 0; i < 128; ++i){
    if (isspace(i))
      printf("%d ", i);
    }
    putchar('\n');

    // isblank() -> they are not visible 
    // will print their character codes
    printf("isblank : ");
    for (int i = 0; i < 128; ++i){
    if (isblank(i))
      printf("%d ", i);
    }
    putchar('\n');

    // isprint() -> includes 32 character code space(' ')
    printf("isprint : ");
    for (int i = 0; i < 128; ++i){
    if (isprint(i))
      printf("%c", i);
    }
    putchar('\n');

    // isgraph() -> DO NOT include 32 character code space(' ')
    printf("isgraph : ");
    for (int i = 0; i < 128; ++i){
    if (isgraph(i))
      printf("%c", i);
    }
    putchar('\n');

    // iscntrl() -> these characters are not visible
    // will print their character codes
    printf("iscntrl : ");
    for (int i = 0; i < 128; ++i){
    if (iscntrl(i))
      printf("%d ", i);
    }
    putchar('\n');
  }

  // output ->
  //  isupper : ABCDEFGHIJKLMNOPQRSTUVWXYZ
  //  islower : abcdefghijklmnopqrstuvwxyz
  //  isalpha : ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
  //  isdigit : 0123456789
  //  isalnum : 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ
  //   abcdefghijklmnopqrstuvwxyz
  //  isxdigit : 0123456789ABCDEFabcdef
  //  ispunct : !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
  //  isspace : 9 10 11 12 13 32
  //  isblank : 9 32
  //  isprint :  !"#$%&'()*+,-./0123456789:;<=>?@
  //   ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
  //  isgraph : !"#$%&'()*+,-./0123456789:;<=>?@
  //   ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
  //  iscntrl : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
  //      20 21 22 23 24 25 26 27 28 29 30 31 127
*/

