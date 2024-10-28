#include <stdio.h>
/*
                  ============================
                  | functions (fonksiyonlar) |
                  ============================
*/

/*
  pure function : function which is not changing the 
    state of the program

  -> to define a function (function definition)
  -> to call a function (function call)
  -> to declare a function (function declaration - function prototype)
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
  // return value type      --> double
  // identifier             --> get_circle_area
  // parameter paranthesis  --> ()
  // parameter variable(s)  --> double radius

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
  // function overloading is NOT VALID in C

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
  // inside function body if the observable behavior is not changing 
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

  // Those functions are pure functions, 
  // There won't be any state change happen in the program
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
  1. The reason for the existence of those functions is, 
  to calculate a value and the return value is that calculated value.
  Ex : get_circle_area, get_abs, get_max ...

  2. The reason for the existance of those functions is,
  answering a question (yes-no, true-false, valid-invalid)
    -> test, query, predicate function
  Ex : isprime, iseven, isodd, hasattribute ...
*/

/*
  // <---- Check boolean_int_function.png ---->
  
  int isprime(int x)
  {
    // if not prime -> return 0
    // if prime     -> return non-zero (1, -1..)

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
    // This situation is being called UNSPECIFIED BEHAVIOR
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
  Every implementation-defined should be unspecified behavior
  but not every unspecified behavior is implementation-defined.

  If it is an implementation-defined, it should be documented by
  the compiler and the compiler should generate the same code 
  everytime the same implementation-defined code runs.
*/

/*
  sizeof(int) // implementation-defined
  // sizeof(int) can be 2, 4, 8 byte in different compilers
  // it is implementation-defined and in every compiler it has been 
  // documented, changing compiler can change the programs behavior.

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

/*
  // those are not character control functions, 
  // those two are character modify functions
  int toupper(int c);
  int tolower(int c); 
*/

/*
  #include <ctype.h>

  int main(void){
    int ch;
    printf("Write a character: ");
    ch = getchar();

    int cx = toupper(ch);
    printf("(%c - %d) ==> (%c - %d)\n", ch, ch, cx, cx);

    // input -> Write a character: a
    // output -> (a - 97) ==> (A - 65)

    // input -> Write a character: A
    // output -> (A - 65) ==> (A - 65)

    // if a character is lowercase, toupper() function will return
    // lowercase, if character is uppercase toupper() function
    // returns the same character.
  }
*/

/*
  #include <ctype.h>

  int main(void){
    int ch;
    printf("Write a character: ");
    ch = getchar();

    int cx = tolower(ch);
    printf("(%c - %d) ==> (%c - %d)\n", ch, ch, cx, cx);

    // input -> Write a character: a
    // output -> (a - 97) ==> (a - 97)

    // input -> Write a character: A
    // output -> (A - 65) ==> (a - 97)
  }
*/

/*
  #include <ctype.h>

  int main(void){
    int c1, c2;

    printf("Write 2 characters : ");

    c1 = getchar();
    c2 = getchar();

    if (c1 == c2)
      printf("%c and %c are same characters\n", c1, c2);
    else
      printf("%c and %c are different characters\n", c1, c2);

    // input -> Write 2 characters : ye
    // output -> y and e are different characters

    // input -> Write 2 characters : aa
    // output -> a and a are same characters
  }
*/

/*
  #include <ctype.h>

  int main(void){
    int c1, c2;

    printf("Write 2 characters : ");

    c1 = getchar();
    c2 = getchar();

    if (c1 == c2)
      printf("%c and %c are same characters\n", c1, c2);
    else
      printf("%c and %c are different characters\n", c1, c2);

    // input -> Write 2 characters : ye
    // output -> y and e are different characters

    // input -> Write 2 characters : aa
    // output -> a and a are same characters

    // input -> Write 2 characters : bB
    // output -> b and B are different characters
  }
*/

/*
  #include <ctype.h>

  int main(void){
    int c1, c2;

    printf("Write 2 characters : ");

    c1 = getchar();
    c2 = getchar();

    if (toupper(c1) == toupper(c2))
      printf("toupper - %c and %c are same characters\n", c1, c2);
    else
      printf("toupper - %c and %c are different characters\n", c1, c2);

    if (tolower(c1) == tolower(c2))
      printf("tolower - %c and %c are same characters\n", c1, c2);
    else
      printf("tolower - %c and %c are different characters\n", c1, c2);

    // input -> Write 2 characters : aA
    // output -> 
    //  toupper - a and A are same characters
    //  tolower - a and A are same characters
  }
*/

/*
  #include <stdlib.h>

  int main(void){

    while(1){
      int ch = rand() % 128;  // ch's value is a valid ASCII code.

      if (isupper(ch))
        putchar(ch);
        // output -> CZTKEPIIODPDSVVWIMQOJWSKIUTHSYDPTZTNF ...
    }

    while(1){
      int ch = rand() % 128; 

      if (isxdigit(ch))
        putchar(ch);
        // output -> CBb5aBa9EF0be82D0cFBfb64b2c88b6B33A1D5B0 ...
    }
  }
*/

/*
          ---------------------------------------------------
          |  function prototype(s) | function declaration   |
          |--------------------------------------------------
          | fonksiyon prototipleri | fonksiyon bildirimleri |
          ---------------------------------------------------
*/

/*
  In classic C, function declarations does not have parameters
    int func(); -> is a function declaration in classic C

  In standardization, function declaration become function prototype
    int func(int, int); -> is a function prototype 
    double foo(void);   -> is a function prototype

  Nowadays, both prototype and declaration used in the same meaning
*/

/*
  int foo(int, int); // function prototype

    compiler understands 
    1. foo is a function identifier
    2. foo function have 2 parameters
    3. foo functions parameters in order int, int
    4. foo functions return type is int 

    compiler generates 
    1. function entry codes
    2. function exit codes 
      when it sees a function declaration
*/

/*
  int foo(int a, int b);  

  1. "a" and "b" identifiers are inside parameter paranthesis 
    in function declaration   
  2. "a" and "b" identifiers's scope is function prototype scope
  3. function prototype scope is only include parameter paranthesis
    int func(int a, int a) -> syntax error

  4. identifiers has been used in function declaration, should not be 
    same as identifiers used in function definition

    int ndigit(int x);  // function declaration
    int ndigit(int y){  // function definition
      // function code
    }
    int ndigit(int z);  // function redeclaration
*/

/*
  int foo(int, int);

  int main(void){
    int x;
    x = foo(10, 20);  
    // compiler must understand what are "x" and "foo" identifiers
    // this is called name lookup.

    // if foo is a function compiler must see foo function's 
    // declaration or foo functions definition

    // when compiler sees function declaration or definition
    // it will generate an assembly code depends on the 
    // functions return type and its parameters count and types
  }
*/

/*
  // before C99    VALID -> implicitly declare int foo();  
  // after C99     syntax error
  //  error : implicit declaration of function 'foo'  

  int main(void){
    int x;
    x = foo(12, 45);
  }
*/

/*
  int foo();  
  // function declaration without parameter variable
  // not giving any information about the function's parameters

  int func(void);

  int main(void){
    foo(12);              // VALID
    foo(12, 13);          // VALID
    foo(12, 13, 14);      // VALID

    func();               // VALID
    func(12);             // syntax error
    // error: too many arguments to function 'func'
  }
*/

/*
  int foo(int);
  int foo(int);
  // those 2 are function redeclarations

  int func(int x);
  int func(int y);
  int func(int);
  // those 3 are function redeclarations
*/

/*
                    ---------------------
                    | function wrappers |
                    ---------------------
*/

/*
  function wrapper :
    bir fonksiyonu çağıran başka bir fonksiyon oluşturmak.

    1. augmentation
    2. default argument wrapper
    3. changing parameter order
*/

/*
  // 1. augmentation

  #include <stdlib.h>   // malloc, exit, EXIT_FAILURE, free

  // malloc function wrapper that controls the return value
  void* malloc_wrapper_1(size_t N)
  {
    void* vp = malloc(N);

    if (!vp){
      fprintf(stderr, "Memory allocation failed!\n");
      exit(EXIT_FAILURE);
    }

    return vp;
  }

  // malloc function wrapper that controls the return value
  // and writes error message that has been passed as argument
  void* malloc_wrapper_2(size_t N, const char* p_err_msg)
  {
    void* vp = malloc(N);

    if (!vp){
      fprintf(stderr, "%s\n", p_err_msg);
      exit(EXIT_FAILURE);
    }

    return vp;
  }

  int main(void)
  {
    size_t N = 20;

    int* p1 = malloc_wrapper_1(N * sizeof(int));

    int* p2 = malloc_wrapper_2( N * sizeof(int), 
                                "memory block allocation failed!");

    free(p1);
    free(p2);
  }
*/

/*
  // default argument wrapper

  #include <stdlib.h>   // strtol

  // strtol function wrappers that simulate default argument

  // this function wrapper increased argument count of strtol function
  long strtol_wrapper(const char* p, char** pp_end)
  {
    return strtol(p, pp_end, 10);
  }

  // if 2nd parameter will be ignored
  long strtol_wrapper_2(const char* p)
  {
    return strtol(p, NULL, 10);
  }
*/

/*
  // changing parameter order

  #include <stdlib.h>

  // - we want to change set parameter to be the first parameter 
  //  and get parameter to be the second parameter
  // - we want value will always passed as a decimal(base 10) number
  char* itoa_wrapper(char* buffer, int val)
  {
    return _itoa(val, buffer, 10);
  }

  int main(void)
  {
    // _itoa is not a standart C function 
    // compiler can give this function as an extension

    // ---------------------------------------------------------

    int x = 2138;
    char buffer[100];

    _itoa(x, buffer, 10);  
    puts(buffer);  // output -> 2138

    // ---------------------------------------------------------

    int y = 99999;
    char buffer_2[100];

    itoa_wrapper(buffer_2, y);
    puts(buffer_2);  // output -> 99999

    // ---------------------------------------------------------
  }
*/