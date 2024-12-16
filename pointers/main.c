#include <stdio.h>

/*
                          ============
                          | Pointers |
                          ============        
*/

/*
  - Pointer, means address.

  - In C, addresses are divided into two categories;
    1. Object Pointers    (nesnelerin adresleri)
    2. Function Pointers  (fonksiyonların adresleri)
*/

/*
  - expressions(ifade) have data type, value category and value.
  - some expression's data type is address.

  - farklı türlerden değişkenlerin adresleri olan ifadeler 
    farklı türden ifadeler.
      double türden bir nesnenin adresinin türü(double*)ile
      int türden bir nesnenin adresinin türü(int*) farklıdır.

  - x, T türünden bir değişken(variable) olsun, eğer bir ifade(expression)
    x değişkeninin adresi anlamına geliyorsa, bu ifadenin türü, T* olarak
    ifade edilir.

    int     -> int*
    double  -> double*
    char    -> char*
    T       -> T*

  - in a system(x86(x32) - x64), all object pointers sizes are same.

  int*    -> pointer to int 
  double* -> pointer to double
  long*   -> pointer to long

  - int* ptr;  
    ptr değişkeninin değeri(value), 
    int türden bir nesnenin(object) adresi
*/

/*
  float* ptr;  -> there are 3 tokens in this decla

  float -> keyword
  *     -> declarator
  ptr   -> identifier
*/

/*
  "int* p;" is a declaration statement not an expression.

  - if a token(*) in a declaration is used for 
  declaring the type of an object, it's a declarator.

  - eğer bir token(*) bir bildirimde(declaration) bir varlığın(objects)
  türünü(data type) belirtmek için kullanılıyorsa, bu bir deklaratördür.
*/

/*
  int main(void){
    int* p;

    *p = 0;  // "*p" is an expression so (*) token is an operator.
  }
*/

/*
  int main(void){
    printf("sizeof(char) = %zu\n", sizeof(char));
    // output -> sizeof(char) = 1
    printf("sizeof(char*) = %zu\n", sizeof(char*));
    // output -> sizeof(char*) = 8 

    printf("sizeof(short) = %zu\n", sizeof(short));
    // output -> sizeof(short) = 2
    printf("sizeof(short*) = %zu\n", sizeof(short*));
    // output -> sizeof(short*) = 8

    printf("sizeof(int) = %zu\n", sizeof(int));
    // output -> sizeof(int) = 4
    printf("sizeof(int*) = %zu\n", sizeof(int*));
    // output -> sizeof(int*) = 8

    printf("sizeof(long) = %zu\n", sizeof(long));
    // output -> sizeof(long) = 4
    printf("sizeof(long*) = %zu\n", sizeof(long*));
    // output -> sizeof(long*) = 8

    printf("sizeof(long long) = %zu\n", sizeof(long long));
    // output -> sizeof(long long) = 8
    printf("sizeof(long long*) = %zu\n", sizeof(long long*));
    // output -> sizeof(long long*) = 8

    printf("sizeof(float) = %zu\n", sizeof(float));
    // output -> sizeof(float) = 4
    printf("sizeof(float*) = %zu\n", sizeof(float*));
    // output -> sizeof(float*) = 8

    printf("sizeof(double) = %zu\n", sizeof(double));
    // output -> sizeof(double) = 8
    printf("sizeof(double*) = %zu\n", sizeof(double*));
    // output -> sizeof(double*) = 8
  }
*/

/*
  int foo(void);

  int main(void){
    int x = 10;
    int a[10] = { 0 };


    34;       
    // "34" is an expression, its data type is int
    // "34" is an RValue expression 
    
    x;        
    // "x" is an expression, its data type is int
    // "x" is an LValue expression

    x + 12;   
    // "x + 12" is an expression, its data type is int
    // "x + 12" is an RValue expression

    a[3];     
    // "a[3]" is an expression, its data type is int
    // "a[3]" is an LValue expression

    foo();    
    // "foo()" is an expression, its data type is int
    // "foo()" is an RValue expression
  }
*/

/*
  int foo(void);
  int* bar(void);

  int main(void){
    int x = 10;
    int a[10] = { 0 };
    int* ptr = a;
    int* pa[5];


    &x;     // "&x" is an expression,     its data type is int*
    a;      // "a" is an expression,      its data type is int*
    a + 3;  // "a + 3" is an expression,  its data type is int*   
    ptr;    // "ptr" is an expression,    its data type is int*
    bar();  // "bar()" is an expression,  its data type is int*
    pa[2];  // "pa[2]" is an expression,  its data type is int*
  }
*/

/*
  int main(void){
    int* p1, p2, p3;
    // Those declarations are same as below

    int* p1;
    int p2;
    int p3;
  }
*/

/*
  int main(void){
    int x, y[3], z, t[10];
    // Those declarations are same as below

    int x;
    int y[3];
    int z;
    int t[10];
  }
*/

/*
  int main(void){
    int* p1, p2[10], p3, *p4;
    // Those declarations are same as below

    int* p1;
    int p2[10];
    int p3;
    int* p4;
  }
*/

/*
  int main(void){
    int x[5], *y, *z[4];
    // Those declarations are same as below

    int x[5];
    int* y;
    int* z[4];
  }
*/

/*
  int* gp;            
  // global pointer variable (static storage duration)

  void func(float* fptr); 
  // function's parameter pointer variable (automatic storage duration)


  int main(void){
    int* p;           
    // local pointer variable (automatic storage duration)

    static int* sp;   
    // static local pointer variable (static storage duration)
  }
*/

/*
  int g;        // zero initialized (static storage duration)

  int main(void){
    int x;      // defining without initialization (garbage value)
    int y = 10; // defining with initialization

    static int z; // zero initialized (static storage duration)
  }
*/

/*
  int* gp;  // null pointer - (static storage duration)

  int main(void){
    int* p;   // defining without initialization (garbage value)

    static int* sp;  // null pointer - (static storage duration)
  }
*/

/*
  int main(void){
    // int* p = init_expr;
    // init_expr should be an address of an int object

    // p = expr;
    // expr should be an address of an int object
  }
*/

/*
  int main(void){
    int* p;
    int x, y;

    x = 10;
    x = 20;
    // we can change the value of x(int variable)

    p = &x;
    p = &y;
    // we can change the value of p(pointer variable)
  }
*/

/*
  Pointer related operators
  --------------------------
  1. priority level           []    subscript / index operator
  1. priority level           ->    member selection (arrow) operator
  2. priority level           &     address of operator
  2. priority level           *     dereferencing (indirection) operator  

  2. priority level is right associative


  &x       address of (unary prefix) operator
  a & b    bitwise AND (binary infix) operator  

  *p       dereferencing (unary prefix) operator
  a * b    multiplication (binary infix) operator
*/

/*
              -----------------------------------------
              | address of operator (adres operatörü) |
              -----------------------------------------
*/

/*
  - operand must be an LValue expression.
*/

/*
  int main(void){
    &5;       // syntax error
    // error: lvalue required as unary '&' operand

    int x = 6;
    &(x + 5); // syntax error
    // error: lvalue required as unary '&' operand

    &x;       // VALID

    int a[4];
    &a[2];    // VALID

    &+x;      // syntax error
    // error: lvalue required as unary '&' operand
  }
*/

/*
  int main(void){
    int x = 6;
    &x;      // "&x" is an expression, it's data type is int*

    short y = 5;
    &y;      // "&y" is an expression, it's data type is short*
  }
*/

/*
  int main(void){
    int x = 6;
    int y = 56;

    int* ptr = &x;  // initialization
    ptr = &y;       // assignment
  }
*/

/*
  int main(void){
    int x = 5, *p = &x;
    // That line is same as below

    int x = 5;
    int* p = &x;
  }
*/

/*
  int main(void){
    int x = 5;
    int* p1 = &x;
    int* p2 = p1;
    // Those lines are same as below

    int x = 5, *p1 = &x, *p2 = p1;

    // p1 and p2 are pointing the same object(x)
  }
*/

/*
  int main(void){
    int a[5] = { 0 };
    int b[5] = { 0 };

    int* p = a;   
    // "a" expression becomes &a[0] (array decay)
    // int* p = &a[0];  

    p = b;        
    // "b" expression becomes &b[0] (array to pointer conversion)
    // p = &b[0];
  }
*/

/*
  int main(void){
    int* p;
    int x = 10;

    p = x;   // legal in C but gcc compiler gives syntax error
    // error: assignment to 'int *' from 'int' 
    // makes pointer from integer without a cast

    p = (int*)x;
    // warning: cast to pointer from integer of different size
  }
*/

/*
  int main (void){
    int* p;
    double dval = 4.5;

    p = &dval;  
    // legal in C but gcc compiler gives syntax error
    // error: assignment to 'int *' from 
    // incompatible pointer type 'double *' 

    p = (int*)&dval;  // valid
  }
*/

/*
  int main(void){
    int x = 10;

    &x;  // "&x" is RValue expression

    &(&x);  // syntax error
    // error: lvalue required as unary '&' operand
  }
*/

/*
  // variables addresses cannot be changed in programs run time.
  // değişkenlerin adresleri programın çalışma zamanında değiştirilemez.

  int main(void){
    int x = 10;
    int y = 20;
    int* p = &x;

    &x = &y;  // syntax error
    //  error: lvalue required as left operand of assignment
  }
*/

/*
  int main(void){
    int a[10] = { 0 };

    a;    // "a" is LValue expression
    &a;   // "&a" is RValue expression


    // a =         -> becomes &a[0]
    // &a[0] =
    // L value to R value conversion
  }
*/

/*
  L value
    - modifiable L value
    - non-modifiable(unmodifiable) L value 
*/

/*
  int main(void){
    int a[10] = { 0 };
    a;    // "a" is non-modifiable LValue  

    const int x = 10;
    x;    // "x" is non-modifiable LValue
  }
*/

/*
  int main(void){
    int a[10] = { 0 };

    sizeof(&a[0]);  // "&a[0]" is an expression, its data type is int*
    
    printf("%zu\n", sizeof(&a[0]));   // output -> 8
    printf("%zu\n", sizeof(int*));    // output -> 8

    printf("%zu\n", sizeof(a));       // output -> 40
    // array decay is not happening here
    printf("%zu\n", sizeof(int[10])); // output -> 40
  }
*/

/*
  // for pointer expressions %p format specifier is being used.

  int main(void){
    int x = 10;
    int a[] = { 1, 2, 3, 4, 5 };
    int* ptr = &x;
    int* pa = a;

    printf("&x    = %p\n", &x);    
    printf("ptr   = %p\n", ptr);   

    printf("a     = %p\n", a);     
    printf("&a[0] = %p\n", &a[0]); 
    printf("pa    = %p\n", pa);    

    // output ->
    //  &x    = 0000006D5A3FFC3C
    //  ptr   = 0000006D5A3FFC3C
    //  a     = 0000006D5A3FFC20
    //  &a[0] = 0000006D5A3FFC20
    //  pa    = 0000006D5A3FFC20
  }
*/

/*
  int main(void){
    int x = 6;
    int* p = &x;

    // p'nin değeri x'in adresi,  p x'i gösteriyor
    // p's value is address of x, p points to x

    // x and p are variables 
    // x and p both have addresses
  }
*/

/*
  int main(void){
    int x = 6;
    int* ptr = &x;

    printf("&x  = %p\n", &x);   // output -> &x  = 0000008A2DDFFD2C
    printf("ptr = %p\n", ptr);  // output -> ptr = 0000008A2DDFFD2C

    printf("&ptr = %p\n", &ptr);  // output -> &ptr = 0000008A2DDFFD20
  }
*/

/*
  int main(void){
    int x = 6;
    int* ptr = &x;

    // ptr is a pointer, x is a pointee
  }
*/


/*
      ------------------------------------------------------------
      | dereferencing (indirection) operator (içerik operatörü)  |
      ------------------------------------------------------------
*/

/*
  *operand (unary prefix) operator
  - dereferencing operator's operand must be an address.

  - içerik operatörü operandı olan adresteki nesneye erişim sağlar.
    *address -> nesne
    
  - içerik operatörünün operandı hangi nesnenin adresi ise, 
    oluşturulan ifade o nesnenin kendisidir.
    *&x  -> x
*/

/*
  int main(void){
    int x = 6;
    *x;  // syntax error
    // error: invalid type argument of unary '*' (have 'int')
  }
*/

/*
  int main(void){
    int x = 6;

    *&x;    // valid
    *(&x);  // valid
    // Those 2 lines are equivalent
    // & and * operators are same priority level and right associative
  }
*/

/*
  int main(void){
    int x = 6;
    int* p = &x;
    int a[5] = { 0 };

    *p;       // VALID, "p" expressions type is int*

    *a;       // VALID, "a" expressions type is int* -> &a[0]
    *&a[0];   // VALID
    // Those 2 lines are equivalent
  }
*/

/*
  int main(void){
    int x = 6;
    printf("x = %d\n", x);   // output -> x = 6

    *&x = 99;
    printf("x = %d\n", x);   // output -> x = 99

    ++*&x;
    printf("x = %d\n", x);   // output -> x = 100
    // ++, * and & operators are same priority level and 
    // they both right associative
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //  push rbp
  //  mov rbp, rsp  
  //  mov DWORD PTR [rbp-4], 6
  //  mov DWORD PTR [rbp-4], 99 
  //  mov eax, DWORD PTR [rbp-4]
  //  add eax, 1
  //  mov DWORD PTR [rbp-4], eax
  //  mov eax, 0
  //  pop rbp
  //  ret
*/

/*
  int main(void){
    int a[] = { 10, 20, 30 };
    *a = 777;
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-12], 10    : a[0] = 10
  //    mov DWORD PTR [rbp-8], 20     : a[1] = 20
  //    mov DWORD PTR [rbp-4], 30     : a[2] = 30
  //    mov DWORD PTR [rbp-12], 777   : *&a[0] = 777
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  - arr bir dizi olmak üzere 
      arr[0] 
    yazmak ile 
      *arr 
    yazmak aynı anlama gelir.

  - içerik operatörü ile oluşturulan geçerli tüm ifadeler 
    nesne gösterdikleri için LValue expression'dır.
*/

/*
  int main(void){
    int x = 6;
    int* p = &x;

    printf("x = %d\n", x);   // output -> x = 6

    *p = 99;
    printf("x = %d\n", x);   // output -> x = 99

    ++*p;
    printf("x = %d\n", x);   // output -> x = 100
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-12], 6       : x = 6
  //    lea rax, [rbp-12]               : rax = &x  :  [rbp-12] = &x
  //    mov QWORD PTR [rbp-8], rax      : p = &x    :  [rbp-8] = &p
  //    mov rax, QWORD PTR [rbp-8]      : rax = p
  //    mov DWORD PTR [rax], 99         : *p = 99
  //    mov rax, QWORD PTR [rbp-8]      : rax = p
  //    mov eax, DWORD PTR [rax]        : eax = *p
  //    lea edx, [rax+1]                : edx = *p + 1
  //    mov rax, QWORD PTR [rbp-8]      : rax = p
  //    mov DWORD PTR [rax], edx        : *p = edx(*p + 1)
  //    mov eax, 0
  //    pop rbp
  //    ret

  //  LEA — Load Effective Address  
  //  lea rax, [rbp-12]   -> LEA r64,mem
  // https://www.felixcloutier.com/x86/lea
*/

/*
  int main(void){
    int x = 3;
    int* p1 = &x;
    int* p2 = p1;
    int* p3 = p2;

    printf("x = %d\n", x);  // output -> x = 3 

    ++*p1;
    ++*p2;
    ++*p3;

    printf("x = %d\n", x);  // output -> x = 6
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-28], 3       : x = 3
  //    lea rax, [rbp-28]               : rax = &x  :  [rbp-28] = &x  
  //    mov QWORD PTR [rbp-8], rax      : p1 = &x   :  [rbp-8] = &p1
  //    mov rax, QWORD PTR [rbp-8]      : rax = p1
  //    mov QWORD PTR [rbp-16], rax     : p2 = p1   :  [rbp-16] = &p2
  //    mov rax, QWORD PTR [rbp-16]     : rax = p2
  //    mov QWORD PTR [rbp-24], rax     : p3 = p2   :  [rbp-24] = &p3
  //    mov rax, QWORD PTR [rbp-8]      : rax = p1
  //    mov eax, DWORD PTR [rax]        : eax = *p1
  //    lea edx, [rax+1]                : edx = *p1 + 1
  //    mov rax, QWORD PTR [rbp-8]      : rax = p1
  //    mov DWORD PTR [rax], edx        : *p1 = edx(*p1 + 1)
  //    mov rax, QWORD PTR [rbp-16]     : rax = p2
  //    mov eax, DWORD PTR [rax]        : eax = *p2
  //    lea edx, [rax+1]                : edx = *p2 + 1
  //    mov rax, QWORD PTR [rbp-16]     : rax = p2
  //    mov DWORD PTR [rax], edx        : *p2 = edx(*p2 + 1)
  //    mov rax, QWORD PTR [rbp-24]     : rax = p3
  //    mov eax, DWORD PTR [rax]        : eax = *p3
  //    lea edx, [rax+1]                : edx = *p3 + 1
  //    mov rax, QWORD PTR [rbp-24]     : rax = p3
  //    mov DWORD PTR [rax], edx        : *p3 = edx(*p3 + 1)
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void){
    int x = 3;
    int y = 67;

    int* ptr;
    ptr = &x;
    *ptr = 4555;
    ptr = &y;
    *ptr = 4555;

    printf("x = %d\n", x);  // output -> x = 4555
    printf("y = %d\n", y);  // output -> y = 4555
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-12], 3       : x = 3     :  [rbp-12] = &x
  //    mov DWORD PTR [rbp-16], 67      : y = 67    :  [rbp-16] = &y
  //    lea rax, [rbp-12]               : rax = &x  :  [rbp-12] = &x
  //    mov QWORD PTR [rbp-8], rax      : ptr = &x  :  [rbp-8] = &ptr
  //    mov rax, QWORD PTR [rbp-8]      : rax = ptr  
  //    mov DWORD PTR [rax], 4555       : *ptr = 4555
  //    lea rax, [rbp-16]               : rax = &y  :  [rbp-16] = &y
  //    mov QWORD PTR [rbp-8], rax      : ptr = &y  :  [rbp-8] = &ptr
  //    mov rax, QWORD PTR [rbp-8]      : rax = ptr
  //    mov DWORD PTR [rax], 4555       : *ptr = 4555
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void){
    int x = 10;
    int y = 20;
    int* p1 = &x;
    int* p2 = &y;

    *p1 *= 100;
    *p2 /= 5;

    printf("x = %d\n", x);  // output -> x = 1000
    printf("y = %d\n", y);  // output -> y = 4
  }
*/

/*
    int main(void){
      int x = 10;
      int y = 20;
      int* p1 = &x;
      int* p2 = &y;

      printf("x = %d\n", x);  // output -> x = 10
      *p1 = *p2;    // x = y;
      printf("x = %d\n", x);  // output -> x = 20
    }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-20], 10        : x = 10    :  [rbp-20] = &x
  //    mov DWORD PTR [rbp-24], 20        : y = 20    :  [rbp-24] = &y
  //    lea rax, [rbp-20]                 : rax = &x  :  
  //    mov QWORD PTR [rbp-8], rax        : p1 = &x   :  [rbp-8] = &p1
  //    lea rax, [rbp-24]                 : rax = &y  :  
  //    mov QWORD PTR [rbp-16], rax       : p2 = &y   :  [rbp-16] = &p2
  //    mov rax, QWORD PTR [rbp-16]       : rax = p2
  //    mov edx, DWORD PTR [rax]          : edx = *p2
  //    mov rax, QWORD PTR [rbp-8]        : rax = p1
  //    mov DWORD PTR [rax], edx          : *p1 = *p2
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void){
    int x = 10;
    int y = 20;
    int* p1 = &x;
    int* p2 = &y;

    int* ptemp = p1;
    p1 = p2;
    p2 = ptemp;
    // swap p1 and p2, p1 points to y, p2 points to x

    ++*p1;
    --*p2;

    printf("x = %d\n", x);  // output -> x = 9
    printf("y = %d\n", y);  // output -> y = 21
  }
*/

/*
  // call by value 

  void foo(int a){
    a = 999;
  }

  int main(void){
    int x = 10;
    printf("x = %d\n", x);  // output -> x = 10

    foo(x);
    printf("x = %d\n", x);  // output -> x = 10
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  foo:
  //    push rbp                        
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-4], edi      : a = edi     :  a = 10
  //    mov DWORD PTR [rbp-4], 999      : a = 999     :  a = 999
  //    nop
  //    pop rbp
  //    ret
  //  main:
  //    push rbp                        
  //    mov rbp, rsp                    
  //    sub rsp, 16                     
  //    mov DWORD PTR [rbp-4], 10       : x = 10
  //    mov eax, DWORD PTR [rbp-4]      : eax = x       :  eax = 10
  //    mov edi, eax                    : edi = eax     :  edi = 10
  //    call foo                        : foo(x)  
  //    mov eax, 0
  //    leave
  //    ret

  // different stack frames rbp's are different in foo and main
  // rdi is first caller save register
*/

/*
  // call by reference

  void foo(int* a){
    *a = 999;
  }

  int main(void){
    int x = 10;
    printf("x = %d\n", x);  // output -> x = 10

    foo(&x);
    printf("x = %d\n", x);  // output -> x = 999
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  foo:
  //    push rbp
  //    mov rbp, rsp
  //    mov QWORD PTR [rbp-8], rdi    : a = rdi       :  a = &x
  //    mov rax, QWORD PTR [rbp-8]    : rax = a
  //    mov DWORD PTR [rax], 999      : *a = 999      :  x = 999
  //    nop
  //    pop rbp
  //    ret
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    sub rsp, 16
  //    mov DWORD PTR [rbp-4], 10     : x = 10
  //    lea rax, [rbp-4]              : rax = &x      
  //    mov rdi, rax                  : rdi = rax     :  rdi = &x
  //    call foo
  //    mov eax, 0
  //    leave
  //    ret
*/

/*
  void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  int main(void){
    int a = 5;
    int b = 10; 
    printf("a = %d, b = %d\n", a, b);   // output -> a = 5, b = 10

    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);   // output -> a = 10, b = 5

    int* p1 = &a;
    int* p2 = &b;
    swap(p1, p2);
    printf("a = %d, b = %d\n", a, b);   // output -> a = 5, b = 10
  }
*/

/*
  void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  int main(void){
    int a[] = {111, 222, 333};
    int b[] = {999, 888, 777};
    printf("a[0] = %d, b[0] = %d\n", a[0], b[0]);
    // output -> a[0] = 111, b[0] = 999

    swap(a, b);
    // swap(&a[0], &b[0]);
    printf("a[0] = %d, b[0] = %d\n", a[0], b[0]);
    // output -> a[0] = 999, b[0] = 111
  }
*/

/* 
  - if a function will change the value of a variable, 
    the address of the variable should be passed to the function.
    i.e swap function

    Why we need to change the variable ?
*/

/*
  #define PI 3.14159265358979323846

  double get_circle_area_1(double radius)
  {
    return PI * radius * radius;
  }

  void get_circle_area_2(double radius, double* p_area)
  {
    *p_area = PI * radius * radius;
  }

  int main(void)
  {
    double radius = 5.3;

    double area_1 = get_circle_area_1(radius);
    printf("area_1 = %f\n", area_1); 
    // output -> area_1 = 88.247337

    double area_2;
    get_circle_area_2(radius, &area_2);
    printf("area_2 = %f\n", area_2);
    // output -> area_2 = 88.247337
  }
*/

/*
  // if the only reason that I need to calculate area is 
  // to use it in another function

  #define PI 3.14159265358979323846

  double get_circle_area_1(double radius)
  {
    return PI * radius * radius;
  }

  void get_circle_area_2(double radius, double* p_area)
  {
    *p_area = PI * radius * radius;
  }

  double do_important_work(double area)
  {
    return area * 2;
  }

  int main(void)
  {
    double radius = 5.3;
    double dval = do_important_work(get_circle_area_1(radius));

    // get_circle_area_1 function is not making us 
    // to create a variable for area 
    // but get_circle_area_2 function is.
  }
*/

/*
  Question : Which scenarios that we want to select 
              get_circle_area_2 function instead of get_circle_area_1 ?

  - maliyet(cost) 
  - birden fazla değerin iletilmesi (passing multiple values)
*/

/*
  int sum(int a, int b)
  {
    return a + b;
  }

  int main(void)
  {
    int x = 10;
    int y = 20;

    int result = sum(x, y);
  }

  // compiled with x86-64 clang 19.1.0 -std=c11 -O0
  // sum:
  //   push rbp
  //   mov rbp, rsp
  //   mov dword ptr [rbp - 4], edi     : int a = x (x copied to a)
  //   mov dword ptr [rbp - 8], esi     : int b = y (y copied to b)
  //   mov eax, dword ptr [rbp - 4]     : eax = a
  //   add eax, dword ptr [rbp - 8]     : eax += b
  //   pop rbp
  //   ret
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   sub rsp, 16
  //   mov dword ptr [rbp - 4], 10      : int x = 10
  //   mov dword ptr [rbp - 8], 20      : int y = 20
  //   mov edi, dword ptr [rbp - 4]     : edi = x
  //   mov esi, dword ptr [rbp - 8]     : esi = y
  //   call sum
  //   mov dword ptr [rbp - 12], eax    : int result = eax
  //   xor eax, eax
  //   add rsp, 16
  //   pop rbp
  //   ret

  // edi is first caller save register
  // esi is second caller save register
*/

/*
  typedef struct{
    int a[20][20];
    int row, col;
  }Matrix;

  Matrix get_random_matrix_1(void);

  void get_random_matrix_2(Matrix*);

  int main(void)
  {
    printf("sizeof(Matrix) = %zu\n", sizeof(Matrix));
    // output -> sizeof(Matrix) = 1608

    Matrix m; // this object is 1608 bytes

    m = get_random_matrix_1();  
    // 1608 bytes will be copied to m object

    get_random_matrix_2(&m);
    // 8 bytes(Matrix*) will be copied to get_random_matrix_2 function

    // get_random_matrix_1 and get_random_matrix_2 functions
    // are doing the same job but get_random_matrix_2 is cheaper
  }
*/

/*
  typedef struct{
    int a[20][20];
    int row, col;
  }Matrix;

  void get_random_matrix(Matrix*);
  // function is accepting address of an object
  // and it is writing to that object
  // Matrix* : out param(eter)
*/

/*
  // passing multiple values

  // <------------ SCENARIO 1 ------------>
  void get_values(double d1, 
                  double d2, 
                  double* p_alpha, 
                  double* p_beta,
                  double* p_gamma)
  {
    *p_alpha  = d1 + d2;
    *p_beta   = d1 * d2;
    *p_gamma  = d1 - d2;
  }
  // p_alpha, p_beta, p_gamma are being set inside the function

  // <------------ SCENARIO 2 ------------>
  double get_values_2(double d1, 
                      double d2, 
                      double* p_beta, 
                      double* p_gamma)
  {
    *p_beta   = d1 * d2;
    *p_gamma  = d1 - d2;
    return d1 + d2;   
  }
  // returning p_alpha in return value and 
  // p_beta and p_gamma is being set inside the function

  // for this kind of functions, generally return value is 
  // the important value(p_alpha) and others(p_beta, p_gamma) are
  // the values that we might want to change or set but 
  // not as important as the return value

  int main(void)
  {
    double x = 5.3;
    double y = 3.7;
    double alpha, beta, gamma;

    get_values(x, y, &alpha, &beta, &gamma);
  }
*/

/*
  // Write a function that add two matrix objects
  // and pass the sum of the matrices to the caller

  typedef struct{
    int a[20][20];
    int row, col;
  }Matrix;

  Matrix add_matrices_1(Matrix m1, Matrix m2);
  // 3 copies of Matrix object

  void add_matrices_2(Matrix m1, Matrix m2, Matrix* p_result);
  // 2 copies of Matrix object, 1 copy of Matrix* object 

  void add_matrices_3(const Matrix* m1,     
                      const Matrix* m2, 
                      Matrix* p_result);
  // 3 copies of Matrix* object 
  // in params : m1, m2 
  // out param : p_result

  // we do not want to change the values of m1 and m2
  // we will use them as an input of the function
  // so we are using const keyword 

  // void set(T*);          -> function will write to T
  // void access(const T*); -> function will read from T

  int main(void)
  {
    Matrix m1;
    Matrix m2;
    Matrix result;
    // ...

    result = add_matrices_1(m1, m2);

    add_matrices_2(m1, m2, &result);

    add_matrices_3(&m1, &m2, &result);
  }
*/

/*
  // In C, an array CAN NOT call(pass) a function by value 
  // only call it by reference is possible

  void foo(int p[]);
  void bar(int* p);
  // Those 2 functions are equivalent

  int main(void)
  {
    int a[100] = { 1, 2, 3, 4, 5 };

    // because of array's elements are contigious in memory
    // we can reach every elements of the array 
    // by using the address of the first element

    foo(a);   // a ==> &a[0] (array decay)
    bar(a);   // a ==> &a[0] (array to pointer conversion)
  }
*/

/*
  // some functions get the address of an object,
  // it uses the object as an input and also writes to the object
  // and pass the object to the caller
  // in-out parameter

  // out parameter 
  void foo(int* p);

  // in-out parameter
  void bar(int* p);

  int main(void)
  {
    int x;  // indeterminate(garbage) value

    foo(&x);    
    // no logic error 
    // foo function's parameter is out param
    // so foo is not using x variable as an input

    bar(&x);  // undefined behavior
    // bar function's parameter is in-out param
    // so bar is will use x variable as an input
    // but x variable has an indeterminate value
    // using indeterminate value is undefined behavior
  }
*/

/*
                    -----------------------
                    | pointer arithmetics |
                    -----------------------
*/

/*
  LEGAL OPERATIONS
  --------------------
  -> address + integer  = address
  -> integer + address  = address
  -> address - integer  = address
  -> address - address  = signed integer

  ILLEGAL OPERATIONS
  ---------------------
  -> integer - address
  -> address + address
*/

/*
  int main(void)
  {
    int a[10] = { 0 };

    a + 5;  // legal    (address + integer)
    3 + a;  // legal    (integer + address)

    int* p = a + 7;
    p - 5;  // legal    (address - integer)
    p + 1;  // legal    (address + integer)

    p + a;  // illegal  (address + address)
    3 - a;  // illegal  (integer - address)
  }
*/

/*
  - Bir dizinin 5 indisli elemaının adresi ile 1'i toplarsak 
    o dizinin 6 indisli elemanının adresini elde ederiz.
    &a[5] + 1 = &a[6]
*/

/*
  int main(void)
  {
    char a[10] = { 0 };

    for (int i = 0; i < 10; ++i)
      printf("%p\n", a + i);

    // output ->
    //  00000028D9FFFE22
    //  00000028D9FFFE23  
    //  00000028D9FFFE24
    //  00000028D9FFFE25
    //  00000028D9FFFE26
    //  00000028D9FFFE27
    //  00000028D9FFFE28
    //  00000028D9FFFE29
    //  00000028D9FFFE2A
    //  00000028D9FFFE2B
    // addresses are increasing by 1
  }
*/

/*
  int main(void)
  {
    short a[10] = { 0 };

    for (int i = 0; i < 10; ++i)
      printf("%p\n", a + i);
    
    // output ->
    //  000000E4B6DFFC30
    //  000000E4B6DFFC32
    //  000000E4B6DFFC34
    //  000000E4B6DFFC36
    //  000000E4B6DFFC38
    //  000000E4B6DFFC3A
    //  000000E4B6DFFC3C
    //  000000E4B6DFFC3E
    //  000000E4B6DFFC40
    //  000000E4B6DFFC42
    // addresses are increasing by 2
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0 };

    for (int i = 0; i < 10; ++i)
      printf("%p\n", a + i);
    
    // output ->
    //  00000034CEFFF900
    //  00000034CEFFF904
    //  00000034CEFFF908
    //  00000034CEFFF90C
    //  00000034CEFFF910
    //  00000034CEFFF914
    //  00000034CEFFF918
    //  00000034CEFFF91C
    //  00000034CEFFF920
    //  00000034CEFFF924
    // addresses are increasing by 4
  }
*/

/*
  int main(void)
  {
    double a[10] = { 0 };

    for (int i = 0; i < 10; ++i)
      printf("%p\n", a + i);
    
    // output ->
    //  0000006AB49FF730
    //  0000006AB49FF738
    //  0000006AB49FF740
    //  0000006AB49FF748
    //  0000006AB49FF750
    //  0000006AB49FF758
    //  0000006AB49FF760
    //  0000006AB49FF768
    //  0000006AB49FF770
    //  0000006AB49FF778
    // addresses are increasing by 8
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    // &a[3] -> (a + 3)

    for(int i = 0; i < 10; ++i)
      printf("%2d %2d %2d\n", a[i], *(a + i), *(i + a));

    // output ->
    //   0  0  0
    //  11 11 11
    //  22 22 22
    //  33 33 33
    //  44 44 44
    //  55 55 55
    //  66 66 66
    //  77 77 77
    //  88 88 88
    //  99 99 99
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    int* ptr = a;
    printf("%d\n", *ptr); // output -> 0

    ++ptr;
    printf("%d\n", *ptr); // output -> 11

    ptr++; 
    printf("%d\n", *ptr); // output -> 22

    ptr += 1;
    printf("%d\n", *ptr); // output -> 33

    ptr = ptr + 1;
    printf("%d\n", *ptr); // output -> 44
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    int* ptr = a;
    printf("%d\n", *ptr); // output -> 0

    ptr += 5;
    printf("%d\n", *ptr); // output -> 55
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* ptr = a;

    for (int i = 0; i < 10; ++i){
      printf("%2d %2d %2d %2d\n", a[i], *(a + i), *(i + a), *ptr);
      ++ptr;
    }

    // output ->
    //   0  0  0  0
    //  11 11 11 11
    //  22 22 22 22
    //  33 33 33 33
    //  44 44 44 44
    //  55 55 55 55
    //  66 66 66 66
    //  77 77 77 77
    //  88 88 88 88
    //  99 99 99 99
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* ptr = a;

    int n  = 10;
    while(n--){
      printf("%d ", *ptr);
      ++ptr;
    }
    // output -> 0 11 22 33 44 55 66 77 88 99
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0, 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    int* ptr_1 = a + 3;
    int* ptr_2 = a + 8;

    printf("%d\n", ptr_2 - ptr_1);  // output -> 5
    printf("%d\n", ptr_1 - ptr_2);  // output -> -5

    // warning: format '%d' expects argument of type 'int', 
    // but argument 2 has type 'long long int

    // "ptr_2 - ptr_1" expression's data type is ptrdiff_t(type alias)

    // ptrdiff_t is a signed integer type and implementation-defined
    // because of gcc compiler implemented ptrdiff_t as long long int
    // we are getting this warning
  }
*/

/*
            --------------------------------------------------
            | subscript operator (köşeli parantez operatörü) |
            --------------------------------------------------
*/

/*
  - binary operator
  - 1st priority level operator (left associative)

    x[y]  --> *(x + y)
*/

/*
  int main(void)
  {
    int x = 6;
    printf("%d\n", x);    // output -> 6


    (&x)[0] = 99;   // (&x)[0] ===> *(&x + 0)
    printf("%d\n", x);    // output -> 99
  }
*/

/*
  int main(void)
  {
    int x = 5;
    printf("x = %d\n", x);  // output -> x = 5

    int* ptr = &x;
    ptr[0] = 88;   // ptr[0] ===> *(ptr + 0)
    printf("x = %d\n", x);  // output -> x = 88
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* p = a + 5;

    printf("%d\n", *p);     
    // output -> 55

    printf("%d\n", p[0]);   
    // output -> 55  (p[0]  ===> *(p + 0))

    printf("%d\n", p[3]);   
    // output -> 88  (p[3]  ===> *(p + 3))

    printf("%d\n", p[-4]);  
    // output -> 11  (p[-4] ===> *(p - 4))
    
    printf("%d\n", 2[p]);   
    // output -> 77  (2[p]  ===> *(2 + p))
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* ptr = a + 5;

    int k = ptr[-4];
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-64], 0       : a[0] = 0 (a[0] is DWORD(int))
  //    mov DWORD PTR [rbp-60], 11
  //    mov DWORD PTR [rbp-56], 22
  //    mov DWORD PTR [rbp-52], 33
  //    mov DWORD PTR [rbp-48], 44
  //    mov DWORD PTR [rbp-44], 55
  //    mov DWORD PTR [rbp-40], 66
  //    mov DWORD PTR [rbp-36], 77
  //    mov DWORD PTR [rbp-32], 88
  //    mov DWORD PTR [rbp-28], 99
  //    lea rax, [rbp-64]               : rax = &a[0]
  //    add rax, 20                     : rax = &a[0] + 5*4[20byte]
  //    mov QWORD PTR [rbp-8], rax      : ptr = &a[5]
  //    mov rax, QWORD PTR [rbp-8]      : rax = ptr
  //    mov eax, DWORD PTR [rax-16]     : eax = *(ptr - 4*4[16byte])
  //    mov DWORD PTR [rbp-12], eax     : int k = eax 
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    int* p = a;

    p += 3;       // p = &a[0] + 3  ===> p = (a + 3)
    p[-2] = 999;  // p[-2] = *(p - 2) = *(a + 3 - 2) = a[1] = 999

    printf("%d\n", a[1]);  // output -> 999
  }
*/

/*
  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 }; 

    //------------------------------------------------------

    for(int i = 0; i < 10; ++i)
      printf("%d ", a[i]);
    // output -> 0 11 22 33 44 55 66 77 88 99

    printf("\n");

    //------------------------------------------------------
    
    int* p = a;
    for(int i = 0; i < 10; ++i)
      printf("%d ", p[i]);
    // output -> 0 11 22 33 44 55 66 77 88 99

    printf("\n");

    //------------------------------------------------------

    int size = 10;
    while(size--){
      printf("%d ", *p);
      ++p;
    }
    // output -> 0 11 22 33 44 55 66 77 88 99
      
    //------------------------------------------------------
  }
*/

/*  
            ---------------------------------------------
            | diziler üzerinde işlem yapan fonksiyonlar |
            ---------------------------------------------
            |     functions that operate on arrays      |
            ---------------------------------------------
*/

/*
  void foo(int* ptr)
  {
    for(int i = 0; i < sizeof(ptr) / sizeof(ptr[0]); ++i)
      printf("%d ", ptr[i]);

    // sizeof(ptr) is 8 for x64 systems
    // sizeof(ptr[0]) is 4 for int type

    // for(int i = 0; i < 2; ++i)
    //    printf("%d ", ptr[i]);
  }

  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
      printf("%d ", a[i]);

    // output -> 0 11 22 33 44 55 66 77 88 99

    foo(a); // output -> 0 11
  }
*/

/*
  void foo(int* ptr, int size)
  {
    // <---- WAY 1 ---->

    for(int i = 0; i < size; ++i)
      printf("%d ", ptr[i]);

    printf("\n");

    // ptr variable's value is not changed

    // <---- WAY 2 ---->

    while(size--){
      printf("%d ", *ptr);
      ++ptr;
    }

    // ptr variable's value is the address of end of the array
  }
*/

/*
  void aprint_1(int* ptr, int size)
  {
    for(int i = 0; i < size; ++i)
      printf("%d ", ptr[i]);

    printf("\n");
  }

  void aprint_2(int* ptr, int size)
  {
      while(size--){
        printf("%d ", *ptr);
        ++ptr;
      }
      printf("\n");
  }

  int main(void)
  {
    int a[10] = { 0 , 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    aprint_1(a, 10);  // output -> 0 11 22 33 44 55 66 77 88 99
    aprint_2(a, 10);  // output -> 0 11 22 33 44 55 66 77 88 99

    aprint_1(a, 4);   // output -> 0 11 22 33

    // Question: call aprint_1 function to output a[3], a[4], a[5]
    aprint_1(a + 2, 3);  // output -> 22 33 44
    aprint_1(&a[2], 3);  // output -> 22 33 44

    // Question: call aprint_2 function to output last 4 elements
    aprint_2(a + 6, 4);  // output -> 66 77 88 99
    aprint_2(&a[6], 4);  // output -> 66 77 88 99
  } 
*/

/*
  void foo(const int ival);
  void foo(int ival);
  // function redeclaration
  - nothing change for function's caller

  difference in pointer arguments constness is important 
  but difference of non-pointer arguments constness is not important
*/

/*
  #include "../headers/nutility.h"

  #define   SIZE  100

  int get_sum_1(const int* p_array, int size)
  {
    int sum = 0;
    for(int i = 0; i < size; ++i)
      sum += p_array[i];
    
    return sum;
  }

  int get_sum_2(const int* p_array, int size)
  {
    int sum = 0;
    while (size--){
      sum += *p_array;
      ++p_array;
    }
    
    return sum;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random_1(a, SIZE);

    printf("sum array = %d\n", get_sum_1(a, SIZE));
    // sum array = 54941
  }
*/

/*
  #include "../headers/nutility.h"

  #define   SIZE  100

  double get_mean(const int* p_array, int size)
  {
    return (double)get_sum(p_array, size) / size;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    printf("mean = %f\n", get_mean(a, SIZE));
    // mean = mean = 530.040000
  }
*/

/*
  #include "../headers/nutility.h"
  #include <math.h>

  #define   SIZE  100

  // standart deviation
  double get_std_dev(const int* p_array, int size)
  {
    double mean = get_mean(p_array, size);
    double sum_square = 0.;

    for(int i = 0; i < size; ++i)
      sum_square += (p_array[i] - mean) * (p_array[i] - mean);

    return sqrt(sum_square / (size - 1));
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    double std_dev = get_std_dev(a, SIZE);
    printf("standart deviation = %f\n", std_dev);
    // output -> standart deviation = 276.183150
  }
*/

/*
  #include "../headers/nutility.h"

  #define   SIZE  20

  void reverse_array(int* p_array, int size)
  {
    for(int i = 0; i < size / 2; ++i)
      swap(&p_array[i], &p_array[size - i - 1]);
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    print_array(a, SIZE); 
    // output ->
    //  424 314 297 657 734 384 669 623 736 798
    //  703 587 605 390 681 768 213  19 330 906

    reverse_array(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //  906 330  19 213 768 681 390 605 587 703
    //  798 736 623 669 384 734 657 297 314 424
  }
*/

/*
  #include "../headers/nutility.h"

  #define   SIZE  20

  int get_max_elem(const int* p_array, int size)
  {
    int max = *p_array;
    for(int i = 1; i < size; ++i)
      if(p_array[i] > max)
        max = p_array[i];
    
    return max;
  }

  int get_min_elem(const int* p_array, int size)
  {
    int min = *p_array;
    for(int i = 1; i < size; ++i)
      if(p_array[i] < min)
        min = p_array[i];
    
    return min;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    print_array(a, SIZE);
    // output ->
    //  540 253 228 542 375 838 551 535 836 311
    //  887 883 692 370 225 387 927 989 844 183

    int max = get_max_elem(a, SIZE);
    printf("max elem = %d\n", max);
    // output -> max elem = 989

    int min = get_min_elem(a, SIZE);
    printf("min elem = %d\n", min);
    // output -> min elem = 183
  }
*/

/*
  #include "../headers/nutility.h"

  #define   SIZE  20

  // 2 in param   : p_array, size
  // 2 out param  : min, max
  void get_min_max(const int* p_array, int size, int* p_min, int* p_max)
  {
    *p_min = *p_max = *p_array;

    for(int i = 1; i < size; ++i){
      if(p_array[i] > *p_max)
        *p_max = p_array[i];
      else if(p_array[i] < *p_min)
        *p_min = p_array[i];
    }
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    print_array(a, SIZE);
    // output ->
    //  444 886 816 750 228 361 870 638 301 700
    //  962 794  65 318 895 182 481 991 809 274

    int min, max;

    get_min_max(a, SIZE, &min, &max);
    printf("min = %d, max = %d\n", min, max);
    // output -> min = 65, max = 991
  }
*/

/*
  #include "../headers/nutility.h"

  #define  SIZE  20

  void copy_array_1(int* p_dest, const int* p_source, int size)
  {
    for(int i = 0; i < size; ++i)
      p_dest[i] = p_source[i];
  }

  void copy_array_2(int* p_dest, const int* p_source, int size)
  {
    while (size--)
      *p_dest++ = *p_source++;
  }

  int main(void)
  {
    int a[SIZE];
    int b[SIZE];

    randomize();
    set_array_random(a, SIZE);

    print_array(a, SIZE);
    // output ->
    //  119  26 864 694 188 926 925 506 603 469
    //  622 390 580 671 979 495 551 179 696 806

    copy_array_1(b, a, SIZE);
    print_array(b, SIZE);
    // output ->
    //  119  26 864 694 188 926 925 506 603 469
    //  622 390 580 671 979 495 551 179 696 806
  }
*/

/*
  #include "../headers/nutility.h"

  #define  SIZE  40

  int main(void)
  {
    int a[SIZE];
    int b[SIZE] = { 0 };

    randomize();
    set_array_random(a, SIZE);

    int idx_a = 10, idx_b = 20, n = 10;

    printf("array a : \n");
    print_array(a, SIZE);

    // output ->
    //  array a :
    //  938 112 735 848   6 658 857 414 751 635
    //  542 156 398 167 477 251 965 644 599 847
    //  350 804 667 912 361 786 566  52 116 187
    //  305 970 912  47 411 242 866 127 776 868

    copy_array(b + idx_b, a + idx_a, n);

    printf("array b : \n");
    print_array(b, SIZE);
    // output ->
    //  array b :
    //    0   0   0   0   0   0   0   0   0   0
    //    0   0   0   0   0   0   0   0   0   0
    //  542 156 398 167 477 251 965 644 599 847
    //    0   0   0   0   0   0   0   0   0   0
  }
*/

/*
  #include "../headers/nutility.h"

  #define SIZE 20

  void bubble_sort(int* p, int size)
  {
    for (int i = 0; i < size - 1; ++i){
      for (int k = 0; k < size - i - 1; ++k){
        if (p[k] > p[k + 1])
          swap(p + k, p + k + 1);
      }
    }
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //  405  39 408 262 430 125 185 797 612 198
    //  392 455 529 995 461 998  82  11 248 771

    bubble_sort(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //   11  39  82 125 185 198 248 262 392 405
    //  408 430 455 461 529 612 771 797 995 998

    set_array_random(a, SIZE);
    bubble_sort(a, SIZE - 10);  // sort first line(10 elements)
    print_array(a, SIZE);
    // output ->
    //    8  48  83 172 240 331 356 417 512 586
    //  575   7 771 537 941 587  24 348 365 846

    set_array_random(a, SIZE);
    bubble_sort(a + 10, SIZE - 10);  // sort second line(10 elements)
    print_array(a, SIZE);
    // output ->
    //  515 813  21 432   3 295 608 164 492 556
    //   17 152 247 534 573 723 730 843 859 902
  }
*/

/*
  #include "../headers/nutility.h"

  #define SIZE 20

  void swap_arrays(int* p_array1, int* p_array2, int size)
  {
    while (size--)
      swap(p_array1++, p_array2++);
  }

  int main(void)
  {
    int a[SIZE];
    int b[SIZE];

    randomize();
    set_array_random(a, SIZE);
    set_array_random(b, SIZE);

    print_array(a, SIZE);
    print_array(b, SIZE);
    // output ->
    //  470 843 424 350 878 287  36 778 439 776
    //  710  46  74 378 377 352 692 322 238 101
    //  ---------------------------------------
    //   38 868 501 190 644  10  35 668 224 526
    //  492 399 967 682 746 685 972  86 646 705
    //  ---------------------------------------

    swap_arrays(a, b, SIZE);
    print_array(a, SIZE);
    print_array(b, SIZE);
    // output ->
    //   38 868 501 190 644  10  35 668 224 526
    //  492 399 967 682 746 685 972  86 646 705
    //  ---------------------------------------
    //  470 843 424 350 878 287  36 778 439 776
    //  710  46  74 378 377 352 692 322 238 101
    //  ---------------------------------------
  }
*/

/*
  void func(int* p, int size);
  void func(int p[], int size);

  // there is an alternative syntax
  // but this syntax is only for functions, 
  // which have pointers as parameters
*/

/*
                      ------------------
                      | pointer idioms |
                      ------------------
*/

/*
  "++", "--", "&", "*" operators are in the same priority level
  and they are right associative

  // ------------------------------------------------------

  "++" -> increment operator
  "--" -> decrement operator

  "++" oparators operand, needs to be an LValue expression
  "--" operators operand, needs to be an LValue expression

  "++x", "x++", "x--", "--x" are all RValue expressions

  "x++" , "x--" expressions will generate the value of "x"
  "++x" expression will generate the value of "x + 1"
  "--x" expression will generate the value of "x - 1"

  // ------------------------------------------------------

  "&" -> address of operator
  "&" operators operand, needs to be an LValue expression
  "&x" expression is an RValue expression

  // ------------------------------------------------------

  "*" -> dereference(içerik) operator
  "*" operators operand, needs to be an address(pointer).
  "*x" is an LValue expression

  // ------------------------------------------------------
*/

/*
  int main(void)
  {
    int x = 5;
    ++x;    // "++" operators operand needs to be an L value
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-4], 5          : int x = 5;
  //    add DWORD PTR [rbp-4], 1          : ++x;
  //  ----> because "x" have a memory location(L value)
  //  ----> it can be incremented
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void)
  {
    int x = 5;
    int* ptr = &x;
    ++ptr;
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-12], 5           : int x = 5;
  //    lea rax, [rbp-12]                   : -- rax = &x
  //    mov QWORD PTR [rbp-8], rax          : int* ptr = &x;
  //    add QWORD PTR [rbp-8], 4            : ++ptr;
  // ---->  because "ptr" have a memory location(L value) 
  // ---->  it can be incremented
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void)
  {
    int x = 5;
    ++&x; // syntax error
    // error: lvalue required as increment operand
    
    // "++" and "&" operators are right associative

    // -->  "&" operators operand, needs to be an L value "x"   [+]
    //      "x" is L value
    //      "&x" is an R value expression

    // -->  "++" operators operand, needs to be an L value "&x" [-]
    //      "&x" is R value expression
  }
*/

/*
  int main(void)
  {
    int x = 5;
    &x++; // syntax error
    // error: lvalue required as unary '&' operand

    // "++" and "&" operators are right associative

    // --> "++" operators operand, needs to be an L value "x" [+]
    //     "x" is L value
    //     "x++" is an R value expression

    // --> "&" operators operand, needs to be an L value "x++" [-]
    //     "x++" is R value expression
  }
*/

/*
  int main(void)
  {
    int x = 5;
    &++x; // syntax error
    // error: lvalue required as unary '&' operand

    // "++" and "&" operators are right associative

    // --> "++" operators operand, needs to be an L value "x" [+]
    //     "x" is L value
    //     "++x" is an R value expression

    // --> "&" operators operand, needs to be an L value "++x" [-]
    //     "++x" is R value expression
  }
*/

/*
  int main(void)
  {
    int a[5] = { 0, 1, 2, 3, 4 };
    int* p = a;

    *p++; // "*p++" is an LValue expression

    // "++" and "*" operators are right associative

    // --> "++" operators operand, needs to be an L value "p" [+]
    //     "p" is L value
    //     "p++" is an address

    // --> "*" operators operand, needs to be an address "p++" [+]
    //     "p++" is an address
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-32], 0       : int a[0] = 0;
  //    mov DWORD PTR [rbp-28], 1       : int a[1] = 1;
  //    mov DWORD PTR [rbp-24], 2       : int a[2] = 2;
  //    mov DWORD PTR [rbp-20], 3       : int a[3] = 3;
  //    mov DWORD PTR [rbp-16], 4       : int a[4] = 4;
  //    lea rax, [rbp-32]               : -- rax = &a[0]
  //    mov QWORD PTR [rbp-8], rax      : int* p = &a[0];
  //    mov rax, QWORD PTR [rbp-8]      : -- rax = &a[0]
  //    add rax, 4                      : -- rax = &a[1](&a[0] + 4)
  //    mov QWORD PTR [rbp-8], rax      : p = &a[1];
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  #include "../headers/nutility.h"
  int main(void)
  {
    int a[2] = { 10, 20 };
    int* p = a;

    *p++ = 999;  
    // "p++" expressions value is the value of "p"(&a[0])
    
    print_array(a, 2);  // output -> 999 20

    // side effect has been applied -> p's value is &a[1]

    *p = 333;
    print_array(a, 2);  // output -> 999 333
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-16], 10        : int a[0] = 10;
  //    mov DWORD PTR [rbp-12], 20        : int a[1] = 20;
  //    lea rax, [rbp-16]                 : -- rax = &a[0]
  //    mov QWORD PTR [rbp-8], rax        : int* p = &a[0];
  //    mov rax, QWORD PTR [rbp-8]        : -- rax = &a[0]
  //    lea rdx, [rax+4]                  : -- rdx = &a[1]
  //    mov QWORD PTR [rbp-8], rdx        : p = &a[1];
  //    mov DWORD PTR [rax], 999          : &a[0] = 999;
  //    mov rax, QWORD PTR [rbp-8]        : -- rax = &a[1]
  //    mov DWORD PTR [rax], 333          : &a[1] = 333;
  //    mov eax, 0  
  //    pop rbp
  //    ret
*/

/*

  *p = 500; 
  ++p;
  // Those 2 statements are equivalent to the statement below

  *p++ = 500; 
*/

/*
  int main(void)
  {
    int a[5] = { 0, 1, 2, 3, 4 };
    *a++ = 777; // syntax error
    // error: lvalue required as increment operand

    // "a" is an LValue expression, because of array decay
    // "&a[0]" is an RValue expression (does not have a memory location)

    // --> "++" operators operand, needs to be an L value "&a[0]" [-]
    //     "&a[0]" is RValue expression
  }
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int a[5] = { 10, 20 };
    int* p = a;

    *++p = 999;
    print_array(a, 2); // output -> 10 999

    // "++" and "*" operators are right associative

    // --> "++" operators operand, needs to be an L value "p" [+]
    //     "p" is L value
    //     "++p" is an address

    // --> "*" operators operand, needs to be an address "++p" [+]
    //     "++p" is an address

    *p = 333;
    print_array(a, 2); // output -> 10 333

  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-16], 10      : int a[0] = 10;
  //    mov DWORD PTR [rbp-12], 20      : int a[1] = 20;
  //    lea rax, [rbp-16]               : -- rax = &a[0]
  //    mov QWORD PTR [rbp-8], rax      : int* p = &a[0];
  //    add QWORD PTR [rbp-8], 4        : p = &a[1](&a[0] + 4)
  //    mov rax, QWORD PTR [rbp-8]      : -- rax = &a[1]
  //    mov DWORD PTR [rax], 999        : &a[1] = 999;
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  // will copy reverse of the array to another array (reverse copy)

  #include "../headers/nutility.h"

  #define SIZE 20

  void reverse_copy(int *p_dest, const int *p_source, int size)
  {
    p_dest += size; 
    // p_dest is the address of the end of the array

    while (size--)
      *--p_dest = *p_source++;
  }

  // in the first iteration, p_dest will become 
  // the last element of the array (prefix decrement) : idx[size - 1] 
  // and p_source will be the first element of the array : idx[0]
  // after the assignment, p_source will become 
  // the second element of the array(postfix increment) : idx[1] 

  int main(void)
  {
    int a[SIZE];
    int b[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    reverse_copy(b, a, SIZE); 

    print_array(b, SIZE);
  }
*/

/*
  int main(void)
  {
    int a[5] = { 10, 20, 30, 40, 50 };

    int* p = a;

    *p++;   // will dereferece p and then  increment p
    (*p)++; // if p = &a[1], "(*p)++" will increment a[1] element
  }
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int a[5] = { 10, 20, 30, 40, 50 };
    int* p = a;

    ++*p;   // ++(*(&a[0]))   ===> ++a[0]
    print_array(a, 5);    // output -> 11 20 30 40 50

    (*p)++; // (*(&a[0]))++   ===> a[0]++
    print_array(a, 5);    // output -> 12 20 30 40 50
  }
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int a[5] = { 10, 20, 30, 40, 50 };

    ++*a;   // ++(*(&a[0]))   ===> ++a[0]
    print_array(a, 5);    // output -> 11 20 30 40 50
  }
*/

/*
  #include "../headers/nutility.h"

  void foo(int* p, int size)
  {
    while(size--)
      ++*p++;     // (++(*(p++))) 
  }
  // in first iteration p will be incremented(postfix) but 
  // side effect will be applied in the second iteration 
  // so p is &a[0]
  // we will dereference p -> *(&a[0]) and will get a[0]
  // and ++a[0] (prefix increment) will be applied

  // first iteration ++a[0]

  int main(void)
  {
    int a[5] = { 10, 20, 30, 40, 50 };
    foo(a, 5);

    print_array(a, 5);  // output -> 11 21 31 41 51
  } 
*/

/*
              ------------------------------------------
              | comparison between addresses(pointers) |
              ------------------------------------------
*/

/*
  Comparison operators
  --------------------
  ">" ">=" "<" "<=" operators are in 6th priority level (relational)
  "==" "!="         operators are in 7th priority level (equality)
*/

/*
  two address is same when:
    - both are pointing to the same object.
    - both are pointing at the end of the same array.
      (ikisi de aynı dizinin bittiği yerin adresi ise)
    - both are NULL pointer.
*/

/*
  // - both are pointing to the same object.

  int main(void)
  {
    int x = 10;
    int y = 20;

    int* p1 = &x;
    int* p2 = &y;
    int* p3 = &x;

    if (p1 == p2)
      printf("p1 and p2 are equal\n");
    else
      printf("p1 and p2 are not equal\n");

    // output -> p1 and p2 are not equal

    if (p1 == p3)
      printf("p1 and p3 are equal\n");
    else
      printf("p1 and p3 are not equal\n");

    // output -> p1 and p3 are equal
  }
*/

/*
  int main(void)
  {
    int a[5]  = { 10, 20, 30, 40, 50 };

    // &a[4] ==> (a + 4) ==> is the last element's address

    // &a[5] or (a + 5) is the address to the end of the array 
    // holding this address in pointer -> VALID
    // using this address in comparison operations -> VALID
    // dereferencing this address -> Undefined Behavior(ub)
    
    int* p = a + 5;   // VALID
    *p = 999;         // ub -> no object at this address
    a[5] = 999;       // ub -> no object at this address
    &a[5];            // VALID
  }
*/

/*
  // - both are pointing at the end of the same array.

  int main(void)
  {
    int a[5] = { 10, 20, 30, 40, 50 };

    int* p = a;
    int* pend = a + 5;

    while (p != pend){
      printf("%d ", *p);
      ++p;
    }
    // output -> 10 20 30 40 50
  }
*/

/*
  #include "../headers/nutility.h"

  #define SIZE 10

  void printArray(const int* ps, const int* pe)
  {
    while (ps != pe)
      printf("%3d ", *ps++);
  }
  // range(aralık)
  // [ps, pe) -> ps is included, pe is excluded

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 123 434 287 745 880 114 145 776 408 678

    printArray(a, a + SIZE);
    // output -> 123 434 287 745 880 114 145 776 408 678
  }
*/

/*
  void foo(int* ps, int* pe)
  {
    while(ps != pe)
      ++ps;
  }

  int main(void)
  {
    int a[5] = { 0 };

    foo(a, a + 5);      // VALID
    foo(a + 4, a + 2);  // undefined behavior(ub)

    // first argument needs to be less than 
    // or equal to the second argument
  }
*/

/*
  #define SIZE  20

  int main(void)
  {
    int a[SIZE] = { 0 };

    int* p1 = a + 5;
    int* p2 = a + 12;

    if (p2 > p1)
      printf("p2 is greater than p1\n");
    else
      printf("p2 is less than p1\n");
    
    // output -> p2 is greater than p1
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 20;

    int* p1 = &x;
    int* p2 = &y;

    if (p1 < p2) // this code is not logical
      ;
    // x and y's addresses are dependent on the compiler
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 10;

    int* p1 = &x;
    int* p2 = &y;


    if (p1 == p2)
      printf("p1 and p2 are equal\n");
    else
      printf("p1 and p2 are not equal\n");

    // output -> p1 and p2 are not equal

    if (*p1 == *p2)
      printf("*p1 -> (x) and *p2 -> (y) are equal\n");
    else
      printf("*p1 -> (x) and *p2 -> (y) are not equal\n");

    // output -> *p1 -> (x) and *p2 -> (y) are equal
  }
*/

/*
  int main(void)
  {
    char s1[] = "hello";    // s1 ==> &s1[0]  (array decay)
    char s2[] = "hello";    // s2 ==> &s2[0]  (array decay)

    if (s1 == s2)   // if (&s1[0] == &s2[0]) -> always false 
      printf("s1 and s2 are equal\n");
    else
      printf("s1 and s2 are not equal\n");

    // output -> s1 and s2 are not equal
  }
*/

/*
  int main(void)
  {
    int a[20] = { 0 };

    int* p1 = a - 1;    // DO NOT WRITE!
    int* p2 = a + 21;   // DO NOT WRITE!

    int* p3 = a + 20;   // write but not dereference it
    // pointer to the end of the array
  } 
*/

/*
  int main(void)
  {
    int x = 10;   // can be used as 1 element array

    int* p = &x + 1;  // VALID 
    *p = 56;      // undefined behavior(ub)
    int a = *p;   // undefined behavior(ub)
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int* p = &x + 1;

    printf("%d\n", *--p);   // output -> 10
  }
*/

/*
  #include "../headers/nutility.h"

  #define SIZE 20

  void ReverseArray(int* p, int size)
  {
    int* p_last = p + size - 1;

    while (p < p_last)
      swap(p++, p_last--);
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //  521 356 380 410 417 283 347 455 165 259
    //  988 231  61 212 656 108 274 955 993  33

    ReverseArray(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //   33 993 955 274 108 656 212  61 231 988
    //  259 165 455 347 283 417 410 380 356 521
  }
*/

/*
                ----------------------------------
                | functions that returns pointer |
                ----------------------------------
                |   adres döndüren fonksiyonlar  |
                ----------------------------------
*/

/*
  int* foo(void); // function that returns a pointer to int
  int bar(void);  // function that returns an int

  int main(void)
  {
    int x = bar();
    int* ptr = foo();
  }
*/

/*
  int* foo(void);

  int main(void)
  {
    int* ptr = foo();
    *ptr; 
    // "*ptr" is the object that foo function returns its address
  }
*/

/*
  int g_x = 10;

  int* foo(void)
  {
    return &g_x;
  }

  int main(void)
  {
    int* ptr = foo();
    printf("g_x = %d\n", g_x);  // output -> g_x = 10

    *ptr = 999;
    printf("g_x = %d\n", g_x);  // output -> g_x = 999
  }
*/

/*
  int* foo();

  int main(void)
  {
    int x = 10;
    int a[] = { 1, 2, 3 };

    int* p1 = &x; 
    // p1 is initialized with the address of int
    int* p2 = p1; 
    // p2 is initialized with another pointer
    int* p3 = a;  
    // p3 is initialized with the identifier of an array
    int* p4 = foo();
    // p4 is initialized with the return value of a function
  }
*/

/*
  int g_x = 10;

  int* foo(void)
  {
    return &g_x;
  }

  int main(void)
  {
    printf("g_x = %d\n", g_x);  // output -> g_x = 10

    // "()" function call operator is in 1st priority level
    // "*"  dereference operator is in 2nd priority level

    *foo() = 777;   // *(foo()) ==> *(&g_x) ==> g_x
    printf("g_x = %d\n", g_x);  // output -> g_x = 777
  }
*/

/*
  #include "../headers/nutility.h"

  int a[5] = { 10, 20, 30, 40, 50 };

  int* foo(void)
  {
    return a;
  }

  int main(void)
  {
    print_array(a, 5);  // output -> 10 20 30 40 50

    // "()" function call operator is in 1st priority level
    // "[]" subscript operator is in 1st priority level
    // "()" and "[]" operators are left associative

    foo()[0]++;
    print_array(a, 5);  // output -> 11 20 30 40 50

    foo()[3] = 999;
    print_array(a, 5);  // output -> 11 20 30 999 50
  }
*/

/*
  int* foo(void)
  {
    int x = 0;  // x is local variable -> automatic storage duration 
    return &x;  
  }

  int main(void)
  {
    int* p = foo(); 
    // warning: function returns address of local variable

    // foo() is returning the address of a local variable
    // p is a dangling pointer, 
    // the object that p points to is destroyed 
    // at the end of the function's execution

    *p = 999;  // undefined behavior(ub)
  }
*/

/*
  char* foo(void)
  {
    char str[] = "hello world we are live from Istanbul";
    // str is local variable -> automatic storage duration
    return str;
  }

  int main(void)
  {
    char* p = foo();
    // warning: function returns address of local variable

    puts(p);  // undefined behavior(ub)
  }
*/

/*
  char g_str[] = "hello world we are live from Istanbul";
  // str is global variable -> static storage duration

  char* foo(void)
  {
    return g_str;
  }

  char* bar(void)
  {
    static char s_str[] = "reality or simulation";
    // str is local static variable -> static storage duration

    return s_str;
  }

  int main(void)
  {
    char* p1 = foo();
    puts(p1);  
    // output -> hello world we are live from Istanbul

    char* p2 = bar();
    puts(p2);
    // output -> reality or simulation
  }
*/

/*
  int* foo(void)
  {
    int x = 45;
    int* p = &x;
    return p; 
    // p's value is the address of x
    // x is local variable -> automatic storage duration
    // x will destroyed at the end of the function execution
  }

  int main(void)
  {
    int* p1 = foo();
    // p is a dangling pointer

    *p1 = 999;  // undefined behavior(ub)
  }
*/

/*
  int* foo(int* ptr)
  {
    return ptr; 
    // returning the address that comes as an argument
  }

  int main(void)
  {
    int x = 10;

    int* p = foo(&x);   // p is holding the address of x
    *p = 8888;

    printf("x = %d\n", x);  // output -> x = 8888
  }
*/

/*
  #include "../headers/nutility.h"

  int* foo(int* ptr)
  {
    return ptr + 3;
    // returning &a[3] ==> (a + 3)
  }

  int main(void)
  {
    int a[5] = { 10, 20, 30, 40, 50 };

    int* p = foo(a);  // argument is &a[0]
    *p += 300;
    print_array(a, 5);  // output -> 10 20 30 340 50
  }
*/

/*
  functions can return these addresses without creating ub.
    1. static storage duration objects addresses
      - global variable addresses
      - local static variable addresses
      - string literals (static storage duration array addresses)
    2. address that comes as an argument
    3. dynamic storage duration object addresses
*/

/* 
  Question : "ptr" is a pointer variable 
  that points to an element inside an array called "a".
  What is the index of the element that "ptr" points to?

  Answer : (ptr - a)
*/

/*
  // Change the value of the max element of the array to -1

  #include "../headers/nutility.h"

  #define SIZE 10

  int* getMaxElement(const int* p, int size)
  {
    int* pmax = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] > *pmax)
        pmax = (int*)(p + i);
    }
    return pmax;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output ->   5 181 372 697 224 704 993 357 639 849

    int* p = getMaxElement(a, SIZE);
    printf("max element : %d and its index is %lld\n", *p, p - a);
    // output -> max element : 993 and its index is 6

    *p = -1;
    print_array(a, SIZE);
    // output ->   5 181 372 697 224 704  -1 357 639 849
  }
*/

/*
  #include "../headers/nutility.h"

  #define SIZE 10

  int* getMaxElement(const int* p, int size)
  {
    int* pmax = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] > *pmax)
        pmax = (int*)(p + i);
    }
    return pmax;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 511  16  39 959 351 524 903 614  31 170

    *getMaxElement(a, SIZE) = -1;
    print_array(a, SIZE);
    // output -> 511  16  39  -1 351 524 903 614  31 170
  }
*/

/*
  // Swap the max element with the first element of the array

  #include "../headers/nutility.h"

  #define SIZE 10

  int* getMaxElement(const int* p, int size)
  {
    int* pmax = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] > *pmax)
        pmax = (int*)(p + i);
    }
    return pmax;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 184 964  42  34 234 230 476 187 547 620

    swap(a, getMaxElement(a, SIZE));
    // a ===> &a[0]
    // getMaxElement(a, SIZE) ===> &a[max_elem_idx]

    print_array(a, SIZE);
    // output -> 964 184  42  34 234 230 476 187 547 620
  }
*/

/*
  #include "../headers/nutility.h"

  #define SIZE 10

  int* getMaxElement(const int* p, int size)
  {
    int* pmax = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] > *pmax)
        pmax = (int*)(p + i);
    }
    return pmax;
  }

  int* getMinElement(const int* p, int size)
  {
    int* pmin = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] < *pmin)
        pmin = (int*)(p + i);
    }
    return pmin;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 625 206 873 549 445  50 673 221 387 831

    int* pmax = getMaxElement(a, SIZE);
    int* pmin = getMinElement(a, SIZE);

    printf("max element : %d, index = %lld\n", *pmax, pmax - a);
    // output -> max element : 873, index = 2
    printf("min element : %d, index = %lld\n", *pmin, pmin - a);
    // output -> min element : 50, index = 5
  }
*/

/*
  // Swap min and max elements of the array

  #include "../headers/nutility.h"

  #define SIZE 10

  int* getMaxElement(const int* p, int size)
  {
    int* pmax = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] > *pmax)
        pmax = (int*)(p + i);
    }
    return pmax;
  }

  int* getMinElement(const int* p, int size)
  {
    int* pmin = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] < *pmin)
        pmin = (int*)(p + i);
    }
    return pmin;
  }

  int main(void)
  {
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 928   0 841 213 661 788 219 128 869 117

    swap(getMaxElement(a, SIZE), getMinElement(a, SIZE));

    print_array(a, SIZE);
    // output ->   0 928 841 213 661 788 219 128 869 117 
  }
*/

/*
  // call print_array function a way that 
  // begins with max element
  // ends with the end of the array 
  #include "../headers/nutility.h"

  #define SIZE 10

  int* getMaxElement(const int* p, int size)
  {
    int* pmax = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] > *pmax)
        pmax = (int*)(p + i);
    }
    return pmax;
  }

  int main(void)
  {
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 297 367  57 198  91 920 616 784 178 748

    int* pmax = getMaxElement(a, SIZE);

    print_array(pmax, SIZE - (pmax - a));
    // output -> 920 616 784 178 748

    // integer - address -> NOT VALID
    // address - address = integer
  }
*/

/*
  // call print_array function a way that 
  // begins with the first element
  // ends with the max element
  #include "../headers/nutility.h"

  #define SIZE 10

  int* getMaxElement(const int* p, int size)
  {
    int* pmax = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] > *pmax)
        pmax = (int*)(p + i);
    }
    return pmax;
  }

  int main(void)
  {
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 865 813 463 910 355 811 894 958 610 329

    int* pmax = getMaxElement(a, SIZE);
    print_array(a, pmax - a + 1);
    // output -> 865 813 463 910 355 811 894 958
  }
*/

/*
  // call print_array function a way that 
  // prints all elements between min and max elements
  #include "../headers/nutility.h"

  #define SIZE 10

  int* getMaxElement(const int* p, int size)
  {
    int* pmax = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] > *pmax)
        pmax = (int*)(p + i);
    }
    return pmax;
  }

  int* getMinElement(const int* p, int size)
  {
    int* pmin = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] < *pmin)
        pmin = (int*)(p + i);
    }
    return pmin;
  }

  int main(void)
  {
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 482 646 687 125 730 299 323 759 341 224

    int* pmax = getMaxElement(a, SIZE);
    int* pmin = getMinElement(a, SIZE);

    if (pmin < pmax)
      print_array(pmin, pmax - pmin + 1);
    else
      print_array(pmax, pmin - pmax + 1);

    // output -> 125 730 299 323 759
  }
*/

/*
  selection sort O(n^2)

  482 646 687 125 730 299 323 759 341 224
  125 646 687 482 730 299 323 759 341 224
  125 224 687 482 730 299 323 759 341 646
  125 224 299 482 730 687 323 759 341 646
  125 224 299 323 730 687 482 759 341 646
  125 224 299 323 341 687 482 759 730 646
  125 224 299 323 341 482 687 759 730 646
  125 224 299 323 341 482 646 759 730 687
  125 224 299 323 341 482 646 687 730 759

  (n - 1) * (n) = n^2 - n = O(n^2)
*/

/*
  #include "../headers/nutility.h"
  #define   SIZE  10

  int* getMinElement(const int* p, int size)
  {
    int* pmin = (int*)p;

    for(int i = 1; i < size; ++i){
      if (p[i] < *pmin)
        pmin = (int*)(p + i);
    }
    return pmin;
  }

  void selection_sort(int* p, int size)
  {
    for (int i = 0; i < size - 1; ++i){
      swap(p + i, getMinElement(p + i, size - i));
    }
    
  }

  int main(void)
  {
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 133 803 439 619 433 924 821 191 469 824

    selection_sort(a, SIZE);
    print_array(a, SIZE);
    // output -> 133 191 433 439 469 619 803 821 824 924
  }
*/

/*
                ------------------------------
                | valid and invalid pointers |
                ------------------------------
*/

/*
  pointer variable can be in 2 different state.
    - valid pointer   -> pointer değişken geçerli durumda
    - invalid pointer -> pointer değişken geçersiz durumda

  invalid pointer can not be used in any operation other than 
  assignment operation(assigning a valid pointer to it)
  
  dereferencible pointer -> valid pointer and when it is dereferenced
  it will not cause undefined behavior(ub)

  if a pointer is pointing an object that its life time is not over
  (still alive) then the pointer is a valid pointer
*/

/*
  int main(void)
  {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* ptr;

    ptr = a + 10;

    --ptr;    // is a valid operation
    printf("%d\n", *ptr);  // output -> 10

    ptr -= 2; // is a valid operation
    printf("%d\n", *ptr);   // output -> 8

    ptr = a + 10;
    int val = ptr - (a + 3);
    printf("val = %d\n", val);  // val = 7;

    ptr = a + 10;
    *ptr; // undefined behavior(ub)
    // ptr is a valid but not a dereferencing pointer 
    // when it is pointing to the end of the array
  }
*/

/*
  int main(void)
  {
    int* ptr; // invalid pointer
    // because of "ptr" is an automatic storage duration object
    // it has indeterminate(garbage) value.
    // this kind of pointers are called "wild pointer"

    // the only way to make a pointer valid is to assign a 
    // valid address to it
  }
*/

/*
  int* foo(void)
  {
    int x = 10;
    return &x;
  }

  int main(void)
  {
    int* ptr = foo(); // invalid pointer
    // because of the address that foo function returns,
    // is the address of a local variable;
    // the object that "ptr" points to 
    // is destroyed at the end of the "foo" function's execution
    // so "ptr" becomes a "dangling pointer"
  }
*/

/*
  int main(void)
  {
    int* ptr;         // "ptr" is invalid -> wild pointer
    int x = 15;       // "ptr" is invalid -> wild pointer
                      // "ptr" is invalid -> wild pointer
    if (x > 10){      // "ptr" is invalid -> wild pointer
      int y = 45;     // "ptr" is invalid -> wild pointer
      ptr = &y;       // "ptr" is valid
      // code ...     // "ptr" is valid   
      // code ...     // "ptr" is valid
    }                 // "ptr" is invalid -> dangling pointer
                      // "ptr" is invalid -> dangling pointer
    // code ...       // "ptr" is invalid -> dangling pointer
    ptr = &x;         // "ptr" is valid
  }
*/

/*
  int main(void)
  {
    int* ptr;
    int a[5] = { 0 };

    ptr = a + 5;  // "ptr" is a valid but not dereferencible pointer
    ptr++;        // "ptr" is invalid pointer
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int arr[20] = { 0 };

    int* ptr = &x;  // "ptr" is a valid pointer
    ptr = arr + 20; // "ptr" is a valid but not dereferencible pointer
    ptr = NULL;     // "ptr" is a valid pointer (null pointer)
  }
*/

/*
                        ----------------
                        | null pointer |
                        ----------------
*/

/*
  - `NULL` is not a keyword.
  - `NULL` is NOT an identifier from compiler's point of view.
    (NULL derleyici açısından bir isim değildir.)
  - `NULL` is a macro.(symbolic constant)
  - `NULL` macro is defined in some header files of C standart library
    (stdio.h, stdlib.h, time.h, stddef.h, string.h ...)
  - null pointer is an address constant. 
    (constant expression and an address)
  - null pointer is an address that can be assign to or initialize 
    all pointer types.

  - if a pointer is a null pointer, it is a valid pointer but
    it is not pointing to any object.
    (geçerli bir pointer olmasına rağmen hiçbir nesnenin adresi değil.)
    (hiçbir nesnenin adresi olmayacağı garantisi var.)
  
  - dereferencing a null pointer is undefined behavior(ub)
    (null pointer dereference)
*/

/*
  int main(void)
  {
    int* i_ptr = NULL;
    i_ptr = NULL;

    double* d_ptr = NULL;
    d_ptr = NULL;
    
    char* c_ptr = NULL;
    c_ptr = NULL;
  }
*/

/*
  int main(void)
  {
    int* ptr = NULL;
  }

  // compiled with x86-64 clang 19.1.0 -O0 -std=c11
  // main:
  //  push rbp
  //  mov rbp, rsp
  //  mov qword ptr [rbp - 8], 0  : int* ptr = NULL
  //  xor eax, eax
  //  pop rbp
  //  ret
*/


/*
  int main(void)
  {
    int* ptr = NULL;

    *ptr;   // dereferencing a null pointer undefined behavior(ub)
    ptr[3]; // *(ptr + 3) -> undefined behavior(ub)

    sizeof(*ptr); // not undefined behavior(ub) 
    // no operation code is generated for the operand of sizeof operator 
    // unevaluated context 
  }
*/

/*
  int main(void)
  {
    int* ptr = NULL;

    if (ptr == NULL){}
    if (ptr != NULL){}
  }
*/

/*
  int main(void)
  {
    int x = 34;

    int* p1 = NULL;
    int* p2 = &x;

    if (p1 == p2)
      printf("p1 and p2 are equal\n");
    else
      printf("p1 and p2 are not equal\n");
    
    // output -> p1 and p2 are not equal

    p2 = NULL;

    if (p1 == p2)
      printf("p1 and p2 are equal\n");
    else
      printf("p1 and p2 are not equal\n");

    // output -> p1 and p2 are equal
  }
*/

/*
  - pointer expression(an address) can be used 
    in a conditional expression (logical expression)

  - logical interpretation of a pointer expression
    is that if the pointer is a null pointer or not
    (eğer lojik ifade beklenen bir yerde, pointer ifadesi
    kullanılmışsa, lojik yorumlama pointer ifadesinin 
    NULL pointer olup olmadığı sorgulamasıdır.)
*/

/*
  int main(void)
  {
    int x = 10;
    int* ptr = &x;

    //  ---------------------------------------------------

    if (ptr != NULL){}
    if (ptr){}
    // Those 2 lines are equivalent.

    while (ptr == NULL){}
    while (!ptr){}
    // Those 2 lines are equivalent.

    //  ---------------------------------------------------

    int* p1, *p2;

    if (p1 && p2){}
    if (p1 != NULL && p2 != NULL){}
    // Those 2 lines are equivalent.

    //  ---------------------------------------------------

    ptr ? 5 : 10;
    ptr != NULL ? 5 : 10;
    // Those 2 lines are equivalent.

    //  ---------------------------------------------------
  }
*/

/*
  // if a static storage duration object (pointer) is not 
  // initalized with an address, it will be a null pointer.

  int* g_p3;  
  // global variable(pointer) - static storage duration object
  // NULL pointer

  int main(void)
  {
    int* p1;
    // local variable(pointer) - automatic storage duration object
    // indeterminate(garbage) value

    static int* s_p2;
    // static local variable(pointer) - static storage duration object
    // NULL pointer


    if (s_p2 == NULL)
      printf("s_p2 is a null pointer\n");
    else
      printf("s_p2 is not a null pointer\n");

    // output -> s_p2 is a null pointer

    if (!g_p3)
      printf("g_p3 is a null pointer\n");
    else
      printf("g_p3 is not a null pointer\n");
    
    // output -> g_p3 is a null pointer
  }
*/

/*
  int main(void)
  {
    int arr[10];      // array of integers
    int* p_arr[10];   // array of pointers

    // ---------------------------------------------------------

    int arr_2[5] = { 1, 2, 3 };
    // last 2 elements are zero initialized

    printf("arr_2[3] = %d, arr_2[4] = %d\n", arr_2[3], arr_2[4]);
    // output -> arr_2[3] = 0, arr_2[4] = 0

    // ---------------------------------------------------------

    int x, y, z;
    int* p_arr_2[5] = { &x, &y, &z };
    // last 2 elements are NULL pointer

    if (p_arr_2[3] == NULL && p_arr_2[4] == NULL)
      printf("last 2 elements are NULL pointer\n");
    else
      printf("last 2 elements are not NULL pointer\n");

    // output ->last 2 elements are NULL pointer

    // ---------------------------------------------------------
  }
*/

/*
  #include <time.h>

  int main(void)
  {
    int x = 5;
    int* p = &x;

    // -------------------------------------------------------

    p = x;    // assigning integer to pointer 
    p = 34;   // assigning integer to pointer
    // error: assignment to 'int *' from 'int' makes pointer 
    // from integer without a cast

    // -------------------------------------------------------

    p = 0;            // VALID
    int* ptr_2 = 0;   // VALID

    // implicit 0 to NULL pointer conversion 
    // (null pointer conversion)

    int x = 10;
    p = x;            // NOT VALID (might syntax error) 
    // error: assignment to 'int *' from 'int' 
    // makes pointer from integer without a cast

    // need to assign integer constant for null pointer conversion.
    // tam sayı sabiti 0 kullanılmalıdır.

    // -------------------------------------------------------

    time(0);    // do not need to include any header file
    time(NULL); // need to include header file that defined NULL macro
    // Those 2 lines are equivalent.

    // time function's parameter variable is a pointer
    // we are passing null pointer to its parameter variable.

    // -------------------------------------------------------
  } 
*/

/*
  <---------------------- SCENARIO_1 ---------------------->

  - In C standart and 3rd party libraries, some functions
    returns an address after their operations are done.
    If those functions is not able to succeed the operation
    they will return a null pointer.
    (When the function is failed, it will return a null pointer)

    FILE* fopen(???);  
    if "fopen" function fails, it will return a null pointer

    void* malloc(size_t);
    if "malloc" function fails, it will return a null pointer
*/

/*
  int main(void)
  {
    //  -------------------------------------------------------

    FILE* fp = fopen("deneme.txt", "r");

    if (fp == NULL)
      printf("deneme.txt file could not be opened\n");
    else
      printf("deneme.txt file is opened\n");
    
    // output -> deneme.txt file could not be opened

    //  -------------------------------------------------------

    fp = fopen("main.c", "r");

    if (!fp)
      printf("main.c file could not be opened\n");
    else
      printf("main.c file is opened\n");

    // output -> main.c file is opened

    //  -------------------------------------------------------
  }
*/

/*
  <---------------------- SCENARIO_2 ---------------------->

  - Some functions, are searching a value in a data structure.
    If the value is found, they will return the address of the
    element. If the value is not found(unsuccessful search), 
    they will return a null pointer.

    strchr(const char* ntbs, int character);
    // if the character is not found, it will return a null pointer

    strchr, strrchr, strstr, strpbrk, memchr ...
*/

/*
  #include <string.h>

  #define SIZE 100

  int main(void)
  {
    char str[SIZE] = "hello world";

    // -------------------------------------------------------

    char* c_p = strchr(str, 'z');
    
    if (c_p != NULL)
      printf("character 'z' is found in the string\n");
    else
      printf("character 'z' is not found in the string\n");

    // output -> character 'z' is not found in the string

    // -------------------------------------------------------

    c_p = strchr(str, 'o');

    if (c_p){
      printf("character 'o' is found in the string\n");
      printf("index of 'o' is %lld\n", c_p - str);
      puts(c_p);
    }
    else
      printf("character 'o' is not found in the string\n");

    // output -> 
    //  character 'o' is found in the string
    //  index of 'o' is 4
    //  o world

    // -------------------------------------------------------
  }
*/

/*
  #include "../headers/nutility.h"

  #define SIZE 10

  // if the key is found in the array, 
  // it will return the address of the element
  // if the key is not found in the array,
  // it will return a null pointer
  int* search_in_array(const int* p_array, int size, int key)
  {
    while(size--){
      if(*p_array == key){
        return (int*)p_array;   // const cast -> const int* to int*
      }
      ++p_array;
    }

    return NULL;
  }

  int main(void)
  {
    int a[SIZE];
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int key;
    printf("enter a key : ");
    scanf("%d", &key);

    int* ptr = search_in_array(a, SIZE, key);

    if (ptr){
      printf("key is found in the array\n");
      printf("index of the key is %lld\n", ptr - a);
      *ptr = -1;
      print_array(a, SIZE);
    }
    else
      printf("key is not found in the array\n");

    // input ->  
    //  41 467 334 500 169 724 478 358 962 464
    //  enter a key : 500
    // output -> 
    //  key is found in the array
    //  index of the key is 3
    //   41 467 334  -1 169 724 478 358 962 464


    // input ->
    //  41 467 334 500 169 724 478 358 962 464
    //  enter a key : 999
    // output -> key is not found in the array
  }
*/

/*
  <---------------------- SCENARIO_3 ---------------------->

  - Some functions are accepting an address to an object or a 
    null pointer as an argument. Function will act differently
    according to the argument that is passed to it.
      -> acting different when the argument is a null pointer
      -> acting different when the argument is an address of an object

    so not a null pointer dereferencing happening when 
    the argument passed is a null pointer.

    time_t time(time_t* ptr);   -> out param
    - time(0);
    - time(NULL);


  - When a function with a pointer argument has been used,
    first thing to check is, if NULL pointer passed to that function
    will be an undefined behavior or it will have a special 
    meaning for that function.

    Bir fonksiyonun pointer argümanı aldığı durumda, 
    ilk yapılması gereken şey, o fonksiyona NULL pointer
    geçilmesinin tanımsız davranış mı yoksa o fonksiyon için
    özel bir anlamı olup olmadığını kontrol etmektir.
*/

/*
  #include <time.h>

  int main(void)
  {
    // -------------------------------------------------------

    time_t sec;
    time(&sec);
    printf("seconds since 1.1.1970 : %lld\n", (long long)sec);
    // output -> seconds since 1.1.1970 : 1727961306

    // -------------------------------------------------------

    printf("seconds since 1.1.1970 : %lld\n", (long long)time(NULL));
    // output -> seconds since 1.1.1970 : 1727961306

    // -------------------------------------------------------
  }
*/

/*
  int main(void)
  {
    FILE* p_file = fopen("main.c", "r");

    // -------------------------------------------------------

    fflush(p_file); 
    // will flush the buffer of the file stream
    // if we want only flush to one file stream

    // -------------------------------------------------------

    fflush(NULL);   
    // will flush all of the output streams
    // if we want to flush all of the output streams

    // -------------------------------------------------------
  }
*/

/*
  #include "../headers/nutility.h"

  // void print_array(const int* p_array, int size){
  //   for (int i = 0; i < size; ++i){
  //     if (i && i % 10 == 0)
  //       putchar('\n');
  //     printf("%3d ", p_array[i]);    ---------------------->
  //   }
  // }

  // in "print_array" functions code pointer argument is dereferenced.
  // "p_array[i]" is dereferencing the pointer

  int main(void)
  {
    int* ptr = NULL;
    print_array(ptr, 10);   // null pointer dereferencing(ub)
  }
*/

/*
  < ---------------------- SCENARIO_4 ---------------------- >
  - pointer variable's value can be used as a flag 
    -> if nullptr, false
    -> if not nullptr, true
*/

/*
  int g_x = 34;

  int main(void)
  {
    int* p = NULL;

    if (1){
      p = &g_x;
    }

    if (p){ // using pointer's value as a flag
      // code..
    }   
  }
*/

/*
                    -----------------------
                    | more pointer idioms |
                    -----------------------
*/

/*
  - p bir yazıyı gösteriyor ise ve 
    p'nin gösterdiği yazı boş değil ise

  if (p != NULL && *p != '\0') {}
  if (p && *p) {}

    when p = NULL -> *p will be undefined behavior 
    because of the short circuit when p = NULL,
    *p will not be evaluated

  --------------------------------------------------------

  - p bir yazıyı göstermiyor ise veya 
    p'nin gösterdiği yazı boş ise

  if (p == NULL || *p == '\0') {}
  if (!p || !*p) {}

    when p = NULL -> *p will be undefined behavior 
    because of the short circuit when p = NULL,
    *p will not be evaluated
*/

/*
  way to change ptr's value to the address of the end of the string
  it should also be correct when the string is empty

  ptr ==>     'h'
              'e'
              'l'
              'l'
              'o'
              '\0'        <== ptr will be pointing here
*/

/*
  <---------------------- IDIOM_1 ---------------------->

  while(*ptr != '\0')
    ++ptr;

  while(*ptr)
    ++ptr;

  <---------------------- IDIOM_2 ---------------------->

  while(*ptr++)
    ; // null statement
  --p;

  <---------------------- IDIOM_3 ---------------------->

  while(*++ptr)
    ; // null statement

  -> this idiom will be UB when the string is empty.

  <---------------------- IDIOM_4 ---------------------->

  #include <string.h> // strlen

  ptr += strlen(ptr);

  <---------------------- IDIOM_5 ---------------------->

  #include <string.h> // strchr

  ptr = strchr(ptr, '\0');
*/

/*
                      ------------------
                      | Pointer Arrays |
                      ------------------
*/

/*
  int* foo(void);

  int main(void)
  {
    int* ptr_arr[10]; 
    // ptr_arr[0] .... ptr_arr[9] types are int*

    int x = 10;
    int* ptr = &x;
    int b_arr[10];

    ptr_arr[2] = &x;
    ptr_arr[3] = ptr;
    ptr_arr[4] = b_arr;
    ptr_arr[5] = foo();

    // "ptr_arr" data type is `int* [10]`
  }
*/

/*
  int g_x, g_y, g_z, g_t;

  int main(void)
  {

    int* ptr_arr_1[10] = { &g_x, &g_y, &g_z, &g_t };  // VALID
    int* ptr_arr_2[] = { &g_x, &g_y, &g_z, &g_t };    // VALID
  }
*/

/*
  int g_x, g_y, g_z;

  int main(void)
  {

    int* ptr_arr[10] = { &g_x, &g_y, &g_z };

    *ptr_arr[0] = 999;
    printf("g_x = %d\n", g_x);  // output -> g_x = 999

    ++*ptr_arr[2];
    printf("g_z = %d\n", g_z);  // output -> g_z = 1

    **ptr_arr = 100;
    printf("g_x = %d\n", g_x);  // output -> g_x = 100
  }
*/

/*
  #include "../headers/nutility.h"

  int g_x, g_y, g_z;

  int g_iarr[] = { 10, 20, 30, 40, 50 };

  int main(void)
  {

    int* ptr_arr[10] = { &g_x, g_iarr, &g_y, &g_z };

    printf("adrress of ptr_arr[1] = %p\n", (void*)ptr_arr[1]);
    // output -> adrress of ptr_arr[1] = 00007FF788A94010

    ++ptr_arr[1];
    printf("adrress of ptr_arr[1] = %p\n", (void*)ptr_arr[1]);
    // output -> adrress of ptr_arr[1] = 00007FF788A94014

    // ptr_arr[1] is now pointing to the 
    // second element of the g_iarr array

    ++*ptr_arr[3];
    print_array(g_iarr, 5);   //  output -> 10 21 30 40 50

    // -------------------------------------------------------
  }
*/

/*
  int x, y, z, t;

  int main(void)
  {
    // -------------------------------------------------------
    
    int* const p[] = { &x, &y, &z, &t };

    // p is a constant pointer to int array (top-level const)
    // changing pointers in the array is not allowed
    
    int m_x = 12;
    p[2] = &m_x;  // syntax error
    // error: assignment of read-only location 'p[2]'

    *p[1] = 45;   // VALID
    printf("y = %d\n", y);  // output -> y = 45

    // -------------------------------------------------------

    const int* p2[] = { &x, &y, &z, &t }; 
    // int const* p2[] = { &x, &y, &z, &t };

    // p2 is a pointer to constant int array (low-level const)
    // changing the value of the object that the pointers 
    // are pointing to is not allowed

    p2[1] = NULL; // VALID

    int m_y = 45;
    p2[1] = &m_y; // VALID

    *p2[1] = 32; // syntax error
    // error: assignment of read-only location '*p2[1]'

    // -------------------------------------------------------

    const int * const p3[] = { &x, &y, &z, &t };
    // int const * const p3[] = { &x, &y, &z, &t };

    // p3 is a constant pointer to constant int array
    // changing the value of the object that the pointers
    // are pointing to is not allowed
    // changing the pointers in the array is not allowed

    p3[0] = NULL; // syntax error
    // error: assignment of read-only location 'p3[0]'

    int m_z = 56;
    p3[2] = &m_z; // syntax error
    // error: assignment of read-only location 'p3[2]'

    *p3[3] = 100; // syntax error
    // error: assignment of read-only location '*(const int *)p3[3]'

    // -------------------------------------------------------
  }
*/

/*
  #include <stddef.h> // size_t
  #include "../headers/nutility.h"

  int main(void)
  {
    const char* const p_days[] = {  "monday", "tuesday", "wednesday", 
                  "thursday", "friday", "saturday", "sunday" };

    // -------------------------------------------------------

    for(size_t i = 0; i < asize(p_days); ++i)
      puts(p_days[i]);

    // output ->
    //  monday
    //  tuesday
    //  wednesday
    //  thursday
    //  friday
    //  saturday
    //  sunday

    // -------------------------------------------------------

    for(size_t i = 0; i < asize(p_days); ++i)
      printf("%p %s\n", p_days[i], p_days[i]);

    // output ->
    //  00007FF7DDFD5050 monday
    //  00007FF7DDFD5057 tuesday
    //  00007FF7DDFD505F wednesday
    //  00007FF7DDFD5069 thursday
    //  00007FF7DDFD5072 friday
    //  00007FF7DDFD5079 saturday
    //  00007FF7DDFD5082 sunday

    // -------------------------------------------------------
  }
*/

/*
  const char* const g_p_days[] = {  "monday", "tuesday", "wednesday", 
                "thursday", "friday", "saturday", "sunday" };
  // g_p_days array is a static storage duration object
  // g_p_days array will be initialized only once


  void foo()
  {
    const char* const p_days[] = {  "monday", "tuesday", "wednesday", 
                "thursday", "friday", "saturday", "sunday" };
    // p_days array is an automatic storage duration object
    // p_days array will be initialized each time 
    // "foo" function is called

    static const char* const s_p_days[] = {  "monday", "tuesday", 
        "wednesday", "thursday", "friday", "saturday", "sunday" };
    // s_p_days array is a static storage duration object
    // s_p_days array will be initialized only once 
  }

  // p_days, g_p_days and s_p_days array's elements are 
  // string literals(char arrays) and they are all 
  // static storage duration objects
*/

/*
  int main(void)
  {
    const char* const p_days[] = { "", "monday", "tuesday", 
        "wednesday", "thursday", "friday", "saturday", "sunday" };
    // "p_days" array can be used as a lookup table

    int day_no = 3;
    printf("day %d is %s", day_no, p_days[day_no]);
    // output -> day 3 is wednesday
  }
*/

/*
  #include <stddef.h> // size_t
  #include <string.h> // strcmp
  #include "../headers/nutility.h"

  // how to check if a string is a valid day name

  int main(void)
  {
    char* const p_days[] = { "monday", "tuesday", "wednesday", 
          "thursday", "friday", "saturday", "sunday" };

    char buf[20] = "saturday";
    // char buf[20] = "istanbul";

    size_t i;

    // -------------------- WAY_1 --------------------
    for(i = 0; i < asize(p_days); ++i)
      if (!strcmp(buf, p_days[i]))
        break;
    // -----------------------------------------------

    // ------------- WAY_2(idiomatic way) ------------
    for(i = 0; i < asize(p_days) && strcmp(buf, p_days[i]); ++i)
      ; // null statement
    // -----------------------------------------------

    if (i < asize(p_days))
      printf("%s is %zu day\n", buf, i + 1);
    else
      printf("invalid day name\n");

    // input -> "saturday"
    // output -> saturday is 6 day

    // input -> "istanbul"
    // output -> invalid day name
  }
*/

/*
  // how to print the elements and their addresses one by one

  #include <stddef.h> // size_t
  #include "../headers/nutility.h"  

  int main(void)
  {
    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      printf(" %p %s\n", p_names[i], p_names[i]);

    // output ->
    //  00007FF730DD5091 ata
    //  00007FF730DD5095 emrecan
    //  00007FF730DD509D adem
    //  00007FF730DD50A2 burhan
    //  00007FF730DD50A9 korhan
    //  00007FF730DD50B0 demir
    //  ...
  }
*/

/*
  // write random elements

  #include "../headers/nutility.h"
  #include <stdlib.h> // rand

  int main(void)
  {
    randomize();

    for(int i = 0; i < 5; ++i)
      printf("%s ", p_names[rand() % PNAMES_SIZE]);
    
    // output -> cemal sefer hakki hilmi pelinsu
  }
*/

/*
  // write elements an their lengths

  #include "../headers/nutility.h"
  #include <string.h> // strlen

  int main(void)
  {
    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      printf("%s %zu\n", p_names[i], strlen(p_names[i]));
    // output ->
    //  ata 3
    //  emrecan 7
    //  adem 4
    //  burhan 6
    //  korhan 6
    //  demir 5
    //  ...
  }
*/

/*
  // write elements that have specific lengths

  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <string.h> // strlen

  int main(void)
  {
    size_t wanted_len = 9;

    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      if(strlen(p_names[i]) == wanted_len)
        printf("%s ", p_names[i]);
      
    // output -> necmettin alparslan nasrullah
  }
*/

/*
  // write element's first characters

  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <string.h> // strlen

  int main(void)
  {
    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      putchar(*p_names[i]);

    printf("\n---------------------------------------\n");

    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      putchar(p_names[i][0]);   

    // Those 2 for loops are equivalent.

    // p_names[i] ==> *(p_names + i)
    // *p_names[i] ==> *(*(p_names + i))
    // p_names[i][0] ==> *(*(p_names + i) + 0) ==> *(*(p_names + i))
  }
*/

/*
  **address -> double dereferencing(indirection)
*/

/*
  // write element's last characters

  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <string.h> // strlen

  int main(void)
  {
    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      putchar(p_names[i][strlen(p_names[i]) - 1]);


    printf("\n---------------------------------------\n");
    // we need to make sure that the string is not empty

    size_t len;
    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      if ((len = strlen(p_names[i])) > 0)
        putchar(p_names[i][len - 1]);
  }
*/

/*
  // write elements that have a specific character inside of it

  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <string.h> // strchr

  int main(void)
  {
    int ch = 'p';

    int counter = 0;
    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      if (strchr(p_names[i], ch)){
        printf("%s ", p_names[i]);
        ++counter;
      }

    printf("\ntotal %d elements\n", counter);

    // output ->
    //  poyraz rupen edip recep sarp perihan alparslan polat 
    //  pelinsu petek abdulmuttalip pelin galip suphi tayyip 
    //  pinat pakize papatya polathan
    //  total 19 elements
  }
*/

/*
  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <string.h> // strchr

  int main(void)
  {
    int counter = 0;
    for (int c = 'a'; c <= 'z'; ++c){
      printf("elements that have '%c' character inside of it : \n", c);
      counter = 0;
      for (size_t i = 0; i < PNAMES_SIZE; ++i)
        if (strchr(p_names[i], c)){
          printf("%s ", p_names[i]);
          ++counter;
        }

      printf("\ntotal %d elements\n", counter);
      (void)getchar();
    }
  }
*/

/*
  // print elements that have a specific substring inside of it

  #include <string.h> // strstr
  #include "../headers/nutility.h"

  int main(void)
  {
    char str[] = "un";

    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      if (strstr(p_names[i], str))
        printf("%s ", p_names[i]);

    // output ->  haldun kunter ferhunde yunus tuncer cuneyt 
    //            gunay tunc ceyhun tayfun orkun
  }
*/

/*
  // print elements that does not have 
  // any of the specific characters inside of it

  #include <string.h> // strpbrk
  #include "../headers/nutility.h"

  int main(void)
  {
    char str[] = "aeoi";

    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      if (!strpbrk(p_names[i], str))
        printf("%s ", p_names[i]);

    // output ->  muslum cumhur utku turgut durmus yunus 
    //            gul ugur su yusuf gurbuz tunc ufuk
  }
*/

/*
  // HOMEWORK - dizideki yazılardan içinde herhangi bir karakterden
  // birden fazla olanlar yazdırılacak.

  #include "../headers/nutility.h"
  #include <string.h> // strlen, memset
  #include <stddef.h> // size_t

  #define LETTER_COUNT 26

  void place_chars_in_alphabet( int* alphabet, 
                                size_t alphabet_size, 
                                const char* str)
  {
    memset(alphabet, 0, alphabet_size);

    for(size_t i = 0; i < strlen(str); ++i)
      ++alphabet[str[i] - 'a'];
  }

  int has_repeated_char(int* alphabet)
  {
    for(int i = 0; i < LETTER_COUNT; ++i)
      if (alphabet[i] > 1)
        return 1;

    return 0;
  }

  int main(void)
  {
    int alphabet[LETTER_COUNT] = { 0 };

    for(size_t i = 0; i < PNAMES_SIZE; ++i)
    {
      place_chars_in_alphabet(alphabet, sizeof alphabet , p_names[i]);

      if (has_repeated_char(alphabet))
        printf("%s ", p_names[i]);
    }
  }
*/

/*
  #include "../headers/nutility.h"
  #include <string.h>
  #include <stddef.h> // size_t

  int main(void)
  {
    for(size_t i = 0; i < PNAMES_SIZE; ++i)
      *p_names[i] = '*';   // syntax error
      // error: assignment of read-only location '*p_names[i]'
      
    // if p_names's type was char* p_names[] -> undefined behavior(ub)
    // because of string literals are immutable objects
    // changing characters of a string literal is UB
  }
*/

/*
  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <stdlib.h> // rand

  int main(void)
  {
    for(int i = 0; i < 100; ++i)
    {
      size_t idx1 = rand() % PNAMES_SIZE;
      size_t idx2 = rand() % PNAMES_SIZE;

      char* temp = p_names[idx1];
      p_names[idx1] = p_names[idx2];
      p_names[idx2] = temp;

      // changing elements places in the array VALID operation
    }
  }
*/

/*
  // sort the array alphabetically

  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <string.h> // strcmp

  int main(void)
  {
    for (size_t i = 0; i < PNAMES_SIZE - 1; ++i)
      for (size_t k = 0; k < PNAMES_SIZE - 1 - i; ++k)
        if (strcmp(p_names[k], p_names[k + 1]) > 0)
        {
          const char* temp = p_names[k];
          p_names[k] = p_names[k + 1];
          p_names[k + 1] = temp;
        }

    for (size_t i = 0; i < PNAMES_SIZE ; ++i)
      printf("%s ", p_names[i]);

    // output -> abdi abdullah abdulmuttalip adem adnan afacan 
    // agah ahmet akin alev ali alican alparslan ...
  }
*/

/*
  // sort the array by the length of the elements ascending

  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <string.h> // strcmp

  int main(void)
  {
    size_t len1, len2;
    for (size_t i = 0; i < PNAMES_SIZE - 1; ++i)
      for (size_t k = 0; k < PNAMES_SIZE - 1 - i; ++k){
        len1 = strlen(p_names[k]);
        len2 = strlen(p_names[k + 1]);

        if ((len1 > len2) || 
            (len1 == len2 && strcmp(p_names[k], p_names[k + 1]) > 0))
        {
          const char* temp = p_names[k];
          p_names[k] = p_names[k + 1];
          p_names[k + 1] = temp;
        }
      }

    for (size_t i = 0; i < PNAMES_SIZE ; ++i)
      printf("%s ", p_names[i]);

    // output -> su ali ata can cem ece eda efe ege gul naz abdi 
    // adem agah akin alev anil arda asim atif atil ayla ayse ...
  }
*/

/*
  void func(void)
  {
    char* p_names1[] = {
    "ata", "emrecan", "adem", "burhan", "korhan", "demir", "bilal", 
    "emrecan", "celik", "zahide", "dost", "lale", "baran", "saniye", 
    "poyraz", "saadet", "aynur", "yeliz", "berivan", "mukerrem", "melih", 
    "necati", "cezmi", "muslum", "azize", "atif", "rupen", "alev", 
    "haldun", "hulusi", "yelda", "billur", "yasemin", "tarcan", "yasar", 
    "tarkan", "refik", "berk", "kenan", "izzet", "adnan", "sefa", 
    "kazim", "gursel", "huseyin", "suheyla", "binnaz", "nusret", 
    "aykut", "efecan", "esra", "tonguc", "kunter", "yurdanur", 
    "abdi" };

    static char* p_names2[] = {
    "ata", "emrecan", "adem", "burhan", "korhan", "demir", "bilal", 
    "emrecan", "celik", "zahide", "dost", "lale", "baran", "saniye", 
    "poyraz", "saadet", "aynur", "yeliz", "berivan", "mukerrem", "melih", 
    "necati", "cezmi", "muslum", "azize", "atif", "rupen", "alev", 
    "haldun", "hulusi", "yelda", "billur", "yasemin", "tarcan", "yasar", 
    "tarkan", "refik", "berk", "kenan", "izzet", "adnan", "sefa", 
    "kazim", "gursel", "huseyin", "suheyla", "binnaz", "nusret", 
    "aykut", "efecan", "esra", "tonguc", "kunter", "yurdanur", 
    "abdi", };

    static const char* p_names3[] = {
    "ata", "emrecan", "adem", "burhan", "korhan", "demir", "bilal", 
    "emrecan", "celik", "zahide", "dost", "lale", "baran", "saniye", 
    "poyraz", "saadet", "aynur", "yeliz", "berivan", "mukerrem", "melih", 
    "necati", "cezmi", "muslum", "azize", "atif", "rupen", "alev", 
    "haldun", "hulusi", "yelda", "billur", "yasemin", "tarcan", "yasar", 
    "tarkan", "refik", "berk", "kenan", "izzet", "adnan", "sefa", 
    "kazim", "gursel", "huseyin", "suheyla", "binnaz", "nusret", 
    "aykut", "efecan", "esra", "tonguc", "kunter", "yurdanur", 
    "abdi", };

    static const char* const p_names4[] = {
    "ata", "emrecan", "adem", "burhan", "korhan", "demir", "bilal", 
    "emrecan", "celik", "zahide", "dost", "lale", "baran", "saniye", 
    "poyraz", "saadet", "aynur", "yeliz", "berivan", "mukerrem", "melih", 
    "necati", "cezmi", "muslum", "azize", "atif", "rupen", "alev", 
    "haldun", "hulusi", "yelda", "billur", "yasemin", "tarcan", "yasar", 
    "tarkan", "refik", "berk", "kenan", "izzet", "adnan", "sefa", 
    "kazim", "gursel", "huseyin", "suheyla", "binnaz", "nusret", 
    "aykut", "efecan", "esra", "tonguc", "kunter", "yurdanur", 
    "abdi", };
  }

  int main(void)
  {
    func();

    // --------------------- p_names1 array ---------------------

    // everytime "func" has been called 
    //  p_names1 array will be initialized. 
    // p_names1 array is a local variable of the function "func"
    //  -> automatic storage duration
    // p_names1 array's elements are string literals
    //  -> static storage duration

    // p_names1 array's elements are string literals, attempting 
    // to change the characters of the elements of the array is UB

    // because of p_names1 array is not top-level const 
    // its elements(string literals) can be changed with another 
    // char* element.

    // --------------------- p_names2 array ---------------------

    // p_names2 array will only be initialized once 
    //  when "func" is called 
    // p_names2 array is a static array 
    //  -> static storage duration
    // p_names2 array's elements are string literals
    //  -> static storage duration

    // p_names2 array's elements are string literals, attempting 
    // to change the characters of the elements of the array is UB

    // because of p_names2 array is not top-level const 
    // its elements(string literals) can be changed with another 
    // char* element.

    // --------------------- p_names3 array ---------------------

    // because of p_names3 array is low-level const array
    // attempting to change characters of the elements of the 
    // array will be syntax error

    // because of p_names3 array is not top-level const 
    // its elements(string literals) can be changed with another 
    // const char* element.

    // --------------------- p_names4 array ---------------------

    // because of p_names4 array is low-level const array
    // attempting to change characters of the elements of the array
    // will be syntax error

    // because of p_names4 array is top-level const 
    // attempting to change the elements(const char*) of the array 
    // will be syntax error
  }
*/

/*
  int main(void)
  {
    const char* p_names[] = {
    "ata", "emrecan", "adem", "burhan", "korhan", "demir", "bilal", 
    "emrecan", "celik", "zahide", "dost", "lale", "baran", "saniye", 
    "poyraz", "saadet", "aynur", "yeliz", "berivan", "mukerrem", "melih", 
    "necati", "cezmi", "muslum", "azize", "atif", "rupen", "alev", 
    "haldun", "hulusi", "yelda", "billur", "yasemin", "tarcan", "yasar", 
    "tarkan", "refik", "berk", "kenan", "izzet", "adnan", "sefa", 
    "kazim", "gursel", "huseyin", "suheyla", "binnaz", "nusret", 
    "aykut", "efecan", "esra", "tonguc", "kunter", "yurdanur", 
    "abdi", NULL };

    // sometimes pointer array's last element is NULL

    int i = 0;

    while(p_names[i])
      printf("%s ", p_names[i++]);

    // output -> ata emrecan adem burhan korhan demir bilal emrecan 
    // celik zahide dost lale baran saniye poyraz saadet aynur yeliz 
    // berivan mukerrem melih necati cezmi muslum azize atif rupen ...
  }
*/

/*
  int main(void)
  {
    const char* p_names[3] = { "ata", "emrecan"  "adem" };
    // sometimes ','(comma) is forgotten when initializing the array
    // p_names[2] is now NULL
    // // {"ata", "emrecanadem", NULL}

    // when its being forgotten and the last element of the array
    // has been dereferenced it will be undefined behavior(ub)
    // (null pointer dereferencing)
  }
*/

/*
  // copy elements of the array to a buffer as concatenated

  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <string.h> // strcpy, strcat

  int main(void)
  {
    char* p[] = {"ata", "emrecan", "adem", "burhan"};
    char buf[100];
    
    buf[0] = '\0';  
    // strcat is will concatenate from null character

    for(size_t i = 0; i < asize(p); ++i)
      strcat(buf, p[i]);

    puts(buf);  // output -> ataemrecanademburhan
  }
*/

/*
                      ----------------------
                      | pointer to pointer |
                      ----------------------
*/

/*
  //  <----- check pointer_to_int.png ----->

  int main(void)
  {
    int x = 10;
    int* p = &x;

    printf("&x = %p\n", (void*)&x); // output -> &x = 0000004CB4FFF9EC
    // address of "x"

    printf("p  = %p\n", (void*)p);  // output -> p  = 0000004CB4FFF9EC
    // value of "p"

    printf("&p = %p\n", (void*)&p); // output -> &p = 0000004CB4FFF9E0
    // address of "p"
  }
*/

/*
  // <----- check pointer_to_pointer.png ----->

  int main(void)
  {
    int x = 10;
    int* p = &x;
    int** pp = &p;

    &x;     
    // "&x" expression's data type is `int*` 
    // &x is a pointer int

    p;      
    // "p" expression's data type is `int*` 
    // p is a pointer to int

    &p;     
    // "&p" expression's data type is `int**`
    // &p is a pointer to pointer to int

    pp;
    // "pp" expression's data type is `int**`
    // pp is a pointer to pointer to int
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 99;

    int* p = &x;
    printf("%d\n", *p);   // output -> 10

    int** pp = &p;
    *pp = &y;
    printf("%d\n", *p);   // output -> 99
  }
*/

/*
  int main(void)
  {
    int x = 10;

    int* p = &x;
    int** pp = &p;

    printf("x  = %d\n", x);   // output -> x  = 10

    **pp = 99;
    printf("x  = %d\n", x);   // output -> x  = 99

    ++**pp;   // ++(*(*pp))
    // 3 operators here (++, *, *) all of them are right associative
    // unary pointer operators

    printf("x  = %d\n", x);   // output -> x  = 100
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int* p = &x;
    int** pp = &p;
  }

  - bir ismin(identifier)'ın oluşturduğu ifadeler     L value'dur.
  - adres operatorü(&) ile oluşturulan tüm ifadeler   R value'dur.
  - içerik operatörü(*) ile oluşturulan tüm ifadeler  L value'dur.
  _________________________________________________________________
  |_______________________________________________________________|
  |                                                               |
  | expression            data type       value category (L / R)  |
  | ------------------------------------------------------------- |
  | x(identifier)           int                 L value           |
  | ------------------------------------------------------------- |
  | &x                      int*                R value           |
  | ------------------------------------------------------------- |
  | p(identifier)           int*                L value           |
  | ------------------------------------------------------------- |
  | *p                      int                 L value           |
  | ------------------------------------------------------------- |
  | &p                      int**               R value           |
  | ------------------------------------------------------------- |
  | pp(identifier)          int**               L value           |
  | ------------------------------------------------------------- |
  | *pp                     int*                L value           |
  | ------------------------------------------------------------- |
  | **pp                    int                 L value           |
  | ------------------------------------------------------------- |
  | &pp                     int***              R value           |
  |_______________________________________________________________|
  |_______________________________________________________________|
*/

/*
  int main(void)
  {
    for (int i = 1; i <= 10; ++i)
    {
      printf("int");
      int n = i;
      while(n--)
        putchar('*');
      printf("p%d = &p%d;", i, i - 1);
      putchar('\n');
    }

    // output ->
    //  int*p1 = &p0;
    //  int**p2 = &p1;
    //  int***p3 = &p2;
    //  int****p4 = &p3;
    //  int*****p5 = &p4;
    //  int******p6 = &p5;
    //  int*******p7 = &p6;
    //  int********p8 = &p7;
    //  int*********p9 = &p8;
    //  int**********p10 = &p9;
  }
*/

/*
  int main(void)
  {
    int x = 99;
    int*p1 = &x;
    int**p2 = &p1;
    int***p3 = &p2;
    int****p4 = &p3;
    int*****p5 = &p4;
    int******p6 = &p5;
    int*******p7 = &p6;
    int********p8 = &p7;
    int*********p9 = &p8;
    int**********p10 = &p9;

    ++**********p10;

    printf("x = %d\n", x);  // output -> x = 100
  }
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int a[5] = { 10, 20, 30, 40, 50 };

    int* p = a;
    int** pp = &p;

    // *pp[3]   ===> *(pp[3]) ===> *(*(pp + 3))
    // (*pp)[3] ===> (p)[3]   ===> *(p + 3)

    ++(*pp)[3];
    print_array(a, 5);  // output ->  10  20  30  41  50

    (*pp)[2]++;
    print_array(a, 5);  // output ->  10  20  31  41  50
  }
*/

/*
  int g_x = 11;

  void foo(int** ptr)
  {
    *ptr = &g_x;
  }

  int main(void)
  {
    int* p; 

    foo(&p);
    printf("%d\n", *p);  // output -> 11

    *p = 22;
    printf("%d\n", *p);  // output -> 22
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int* p = &x;

    // -------------------------------------------------------

    foo(p);  
    // from "x"'s perspective this call is a pass(call) by reference
    //  -> "foo" function CAN change the value of "x"
    //  -> by dereferencing
    // from "p"'s perspective this call is a pass(call) by value
    //  -> "foo" function CAN NOT change the value of "p"

    // -------------------------------------------------------

    bar(&p);
    // from "x"'s perspective this call is a pass(call) by reference
    //  -> "bar" function CAN change the value of "x"
    //  -> by double dereferencing
    // from p's perspective this call is a pass(call) by reference
    //  -> "bar" function CAN change the value of "p"
    //  -> by dereferencing

    // -------------------------------------------------------
  }
*/

/*
  int g = 11;

  void foo(int* ptr)
  {
    *ptr = 22;   // changing the value of "x"
  }

  void bar(int** ptr)
  {
    **ptr = 33;  // changing the value of "x"
    *ptr = &g;    // changing the value of "p"
  }

  int main(void)
  {
    int x = 11;
    int* p = &x;

    // -------------------------------------------------------

    foo(p);
    printf("x = %d\n", x);      // output -> x = 22

    printf("&x = %p\n", &x);    // output -> &x = 000000E8525FF8BC
    printf("p  = %p\n", p);     // output -> p  = 000000E8525FF8BC

    // -------------------------------------------------------

    bar(&p);

    printf("x = %d\n", x);      // output -> x = 33

    printf("&x = %p\n", &x);    // output -> &x = 000000E8525FF8BC
    printf("p  = %p\n", p);     // output -> p  = 00007FF6CCB74010
    printf("&g = %p\n", &g);    // output -> &g = 00007FF7EB9E4010

    // -------------------------------------------------------
  }
*/

/*
  void pswap(int** ptr1, int** ptr2)
  {
    int* p_temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = p_temp;
  }

  int main(void)
  {
    int x = 11;
    int y = 22;

    int* p1 = &x;
    int* p2 = &y;

    printf("*p1 = %d  *p2 = %d\n", *p1, *p2);  
    // output -> *p1 = 11  *p2 = 22

    pswap(&p1, &p2);
    // swapping pointer variables   

    printf("*p1 = %d  *p2 = %d\n", *p1, *p2);
    // output -> *p1 = 22  *p2 = 11
  }
*/

/*
  // write a function that takes an address and the size of an array
  // and will send the address of the max and min elements of the array

  #include "../headers/nutility.h"

  #define   SIZE  10 

  void get_min_max_addresses( const int* p_arr, 
                              size_t size, 
                              int** ptr_min, 
                              int** ptr_max)
  {
    *ptr_min = *ptr_max = (int*)p_arr;

    for (size_t i = 0; i < size; ++i)
    {
      if (p_arr[i] < **ptr_min)
        *ptr_min = (int*)(p_arr + i);
      else if (p_arr[i] > **ptr_max)
        *ptr_max = (int*)(p_arr + i);
    }
  }

  int main(void)
  {
    int arr[SIZE];

    randomize();
    set_array_random(arr, SIZE);
    print_array(arr, SIZE);
    // output -> 122 481 452 903 770 410 851 738 712 411

    int* p_min, *p_max;
    get_min_max_addresses(arr, SIZE, &p_min, &p_max);

    printf("min_elem = %d, index = %lld\n", *p_min, p_min - arr);
    printf("max_elem = %d, index = %lld\n", *p_max, p_max - arr);
    // output ->
    //  min_elem = 122, index = 0
    //  max_elem = 903, index = 3

    swap(p_min, p_max);
    print_array(arr, SIZE);
    // output -> 903 481 452 122 770 410 851 738 712 411

    // ---------------------------------------------------

    // printing elements from min to max elements
    if (p_min < p_max)
      print_array(p_min, p_max - p_min + 1);
    else
      print_array(p_max, p_min - p_max + 1);
    // output -> 903 481 452 122
  }
*/

/*
  #include "../headers/nutility.h"

  void foo_1(int** ptr_1, int** ptr_2)
  {
    int x = **ptr_1;
    **ptr_1 = **ptr_2;
    **ptr_2 = x;
  }

  void foo_2(int** ptr_1, int** ptr_2)
  {
    swap(*ptr_1, *ptr_2); // "swap" function is in <nutility.h>
  }

  int main(void)
  {
    int x = 22, y = 33;
    int* p1 = &x, *p2 = &y;

    printf("x = %d, y = %d\n", x, y);  
    // output -> x = 22, y = 33

    foo(&p1, &p2);
    printf("x = %d, y = %d\n", x, y);  
    // output -> x = 33, y = 22
  }
*/

/*
  void foo(int** ptr_1, int** ptr_2)
  {
    int temp_x = **ptr_1;
    **ptr_1 = **ptr_2;
    **ptr_2 = temp_x;
  }

  int main(void)
  {
    int x = 22, y = 33;
    int* p1 = &x, *p2 = &y;

    foo(&p1, &p2);
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  foo:
  //    push rbp
  //    mov rbp, rsp
  //  ------------------------------------------------------------
  //  -------------------- int** ptr_1 = &p1; --------------------
  //  -------------------- int** ptr_2 = &p2; --------------------
  //  ------------------------------------------------------------
  //    mov QWORD PTR [rbp-24], rdi         : int** ptr_1 = &p1;
  //    mov QWORD PTR [rbp-32], rsi         : int** ptr_2 = &p2;
  //  ------------------------------------------------------------
  //  ------------------  int temp_x = **ptr_1; ------------------
  //  ------------------------------------------------------------
  //    mov rax, QWORD PTR [rbp-24]         : rax = ptr_1   (int**)
  //    mov rax, QWORD PTR [rax]            : rax = *ptr_1  (int*)
  //    mov eax, DWORD PTR [rax]            : eax = **ptr_1 (int)
  //    mov DWORD PTR [rbp-4], eax          : int temp_x = **ptr_1;
  //  ------------------------------------------------------------
  //  -------------------- **ptr_1 = **ptr_2; --------------------
  //  ------------------------------------------------------------
  //    mov rax, QWORD PTR [rbp-32]         : rax = ptr_2   (int**)
  //    mov rdx, QWORD PTR [rax]            : rdx = *ptr_2  (int*)
  //    mov rax, QWORD PTR [rbp-24]         : rax = ptr_1   (int**)
  //    mov rax, QWORD PTR [rax]            : rax = *ptr_1  (int*)
  //    mov edx, DWORD PTR [rdx]            : edx = **ptr_2 (int)
  //    mov DWORD PTR [rax], edx            : **ptr_1 = **ptr_2;  
  //  ------------------------------------------------------------
  //  --------------------  **ptr_2 = temp_x; --------------------
  //  ------------------------------------------------------------
  //    mov rax, QWORD PTR [rbp-32]         : rax = ptr_2   (int**)
  //    mov rax, QWORD PTR [rax]            : rax = *ptr_2  (int*)
  //    mov edx, DWORD PTR [rbp-4]          : edx = temp_x
  //    mov DWORD PTR [rax], edx            : **ptr_2 = temp_x;
  //  ------------------------------------------------------------
  //    nop
  //    pop rbp
  //    ret
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    sub rsp, 32
  //    mov DWORD PTR [rbp-4], 22           : int x = 22;
  //    mov DWORD PTR [rbp-8], 33           : int y = 33;
  //    lea rax, [rbp-4]                    : rax = &x
  //    mov QWORD PTR [rbp-16], rax         : int* p1 = &x;
  //    lea rax, [rbp-8]                    : rax = &y
  //    mov QWORD PTR [rbp-24], rax         : int* p2 = &y;
  //    lea rdx, [rbp-24]                   : rdx = &p2
  //    lea rax, [rbp-16]                   : rax = &p1
  //    mov rsi, rdx                        : rsi = &p2
  //    mov rdi, rax                        : rdi = &p1
  //    call foo
  //    mov eax, 0
  //    leave
  //    ret
*/

/*
  #include <stddef.h> // size_t

  void foo(int**, size_t arr_size);

  int main(void)
  {
    int* p_arr[10];

    foo(p_arr, 10); 
    foo(&p_arr[0], 10);

    // if we want to send the address(first element's address) 
    // of the array to a function, we need to send the address of 
    // the first int*(pointer to int) element's address
    // so address of the int* ===> int** (pointer to pointer to int)
  }
*/

/*
  void print_pointees_1(int* const* ptr_arr, size_t size)
  {
    // ----------------------------------------------------

    for (size_t i = 0; i < size; ++i)
      printf("%d ", *ptr_arr[i]);
    putchar('\n');

    // '[]' subscript operator's precedence is higher than 
    // '*'  dereferencing operator  ====> '[]' > '*'

    // ----------------------------------------------------

    for (size_t i = 0; i < size; ++i)
      printf("%d ", **(ptr_arr + i));
    putchar('\n');
    // ptr_arr[i]   ===> *(ptr_arr + i)
    // *ptr_arr[i]  ===> *(*(ptr_arr + i))  ===> **(ptr_arr + i)

    // ----------------------------------------------------
  }

  void print_pointees_2(int* const* ptr_arr, size_t size)
  {
    while (size--)
      printf("%d ", **ptr_arr++);
    putchar('\n');

    // '*' and '++' operators have the same precedence
    // they both are right associative operators
    // **ptr_arr++ ===> *(*(ptr_arr++))

    // the value that "ptr_arr++" expression generates is "ptr_arr"
  }

  int main(void)
  {
    int x = 10, y = 20, z = 30, t = 40;

    int* p_arr[4] = { &x, &y, &z, &t };

    print_pointees_1(p_arr, 4);
    // output -> 
    //  10 20 30 40
    //  10 20 30 40

    print_pointees_2(p_arr, 4); 
    // output -> 10 20 30 40
  }
*/

/*
  #include <stddef.h>   // size_t
  #include <string.h>   // strcmp
  #include "../headers/nutility.h"

  void print_names_1(const char** p_arr_names, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
      printf("%s ", p_arr_names[i]);
    putchar('\n');
  }

  void print_names_2(const char** p_arr_names, size_t size)
  {
    while (size--)
      printf("%s ", *p_arr_names++);
    putchar('\n');
  }

  void cp_swap(const char** c_ptr1, const char** c_ptr2)
  {
    const char* p_temp = *c_ptr1;
    *c_ptr1 = *c_ptr2;
    *c_ptr2 = p_temp;
  }

  void sort_names(const char** p_arr_names, size_t size)
  {
    for(size_t i = 0; i < size - 1; ++i)
      for (size_t k = 0; k < size - 1 - i; ++k)
        if (strcmp(p_arr_names[k], p_arr_names[k + 1]) > 0)
          cp_swap(p_arr_names + k, p_arr_names + k + 1);
  }

  int main(void)
  {
    print_names_1(p_names, PNAMES_SIZE);
    // output -> 
    //  ata emrecan adem burhan korhan demir 
    //  bilal emrecan celik zahide dost lale baran ...

    sort_names(p_names, PNAMES_SIZE);
    print_names_2(p_names, PNAMES_SIZE);
    // output ->
    //  abdi abdullah abdulmuttalip adem adnan afacan agah 
    // ahmet akin alev ali alican alparslan ...
  }
*/

/*
              -----------------------------------
              | `const` correctness in pointers |
              -----------------------------------
*/

/*
  // `const` anahtar sözcüğü ney'den önce geliyorsa const olan o'dur.

  int main(void)
  {
    int x = 10;
    int y = 20;

    // -------------------------------------------------------

    int* const p1 = &x;
    // `const` "p1"'den önce geliyor. `const` olan "p1"

    // "p1" ifadesi atama operatörünün
    // sol operandı olursa sentaks hatası olacak.

    p1 = &y;   // syntax error
    *p1 = 12;  // VALID

    // -------------------------------------------------------

    int const *p2 = &x;
    // `const` "*p2" den önce geliyor. `const` olan "*p2"

    // "*p2" ifadesi atama operatörünün
    // sol operandı olursa sentaks hatası olacak.

    p2 = &y;  // VALID
    *p2 = 12; // syntax error

    // -------------------------------------------------------
    // -------------------------------------------------------

    int* p3 = &x;
    int* p4 = &y;

    // -------------------------------------------------------

    int** const pp1 = &p3;
    // `const` "pp1"'den önce geliyor. `const` olan "pp1"

    // "pp1" ifadesi atama operatörünün
    // sol operandı olursa sentaks hatası olacak.

    pp1 = &p4;  // syntax error
    *pp1 = p4;  // VALID
    **pp1 = 12; // VALID

    // -------------------------------------------------------

    int* const *pp2 = &p3;
    // `const` "*pp2" den önce geliyor. const olan "*pp2"

    // "*pp2" ifadesi atama operatörünün
    // sol operandı olursa sentaks hatası olacak.

    pp2 = &p4;  // VALID
    *pp2 = p4;  // syntax error
    **pp2 = 12; // VALID

    // -------------------------------------------------------

    int const **pp3 = &p3;
    // `const` "**pp3" den önce geliyor. const olan "**pp3"

    // "**pp3" ifadesi atama operatörünün 
    // sol operandı olursa sentaks hatası olacak.

    pp3 = &p4;  // VALID
    *pp3 = p4;  // VALID
    **pp3 = 12; // syntax error

    // -------------------------------------------------------
  }
*/

/*
  #include <stddef.h> // size_t

  int g_x = 10;

  void print_pointees(int* const* iptr_arr, size_t size) 
  {
    *iptr_arr = &g_x;   // syntax error
    iptr_arr[2] = &g_x; // syntax error
    // iptr_arr[2] ===> *(iptr_arr + 2)
  }

  // int* const* iptr_arr ===> `const` "*iptr_arr" den önce,
  // dolayısıyla `const` olan "*iptr_arr"
  // "*iptr_arr" ifadesi atama operatörünün sol operandı olursa
  // sentaks hatası olacak.

  int main(void)
  {
    int x = 1, y = 2, z = 4;
    int* ip_arr[3] = { &x, &y, &z };

    print_pointees(ip_arr, 3);
    // this function will guarantee that it
    // will not change the elements of the array (ppinters)

    // fonksiyon dizinin içindeki pointerları 
    // DEĞİŞTİRMEME garantisi veriyor.
  }
*/

/*
  int main(void)
  {
    int arr[5] = { 10, 20, 30, 40, 50 };
    
    // -------------------------------------------------------

    // "arr"  expression's data type is int*
    // "&arr" expression's data type is int(*)[5]

    // arr  ===> int* (array decay)
    // &arr ===> int(*)[5] (address of an array)

    // -------------------------------------------------------

    int* p1 = arr;      // VALID
    int* p2 = &arr[0];  // VALID
    int* p3 = &arr;     // syntax error
    // error: initialization of 'int *' 
    // from incompatible pointer type 'int (*)[5]

    int(*p4)[5] = &arr; // VALID

    // -------------------------------------------------------
  }
*/

/*
  int main(void)
  {
    int arr[5] = { 10, 20, 30, 40, 50 };

    int* p1 = arr;
    int(*p2)[5] = &arr;

    printf("%p\n", arr);    // output -> 00000065A47FF710
    printf("%p\n", &arr);   // output -> 00000065A47FF710
    printf("%p\n", p1);     // output -> 00000065A47FF710
    printf("%p\n", p2);     // output -> 00000065A47FF710
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  // main:
  //  push rbp
  //  mov rbp, rsp
  //  mov DWORD PTR [rbp-48], 10      : int elem_1(&arr[0]) = 10; 
  //  mov DWORD PTR [rbp-44], 20      : int elem_2(&arr[1]) = 20;
  //  mov DWORD PTR [rbp-40], 30      : int elem_3(&arr[2]) = 30;
  //  mov DWORD PTR [rbp-36], 40      : int elem_4(&arr[3]) = 40;
  //  mov DWORD PTR [rbp-32], 50      : int elem_5(&arr[4]) = 50;
  //  lea rax, [rbp-48]               : rax = &arr[0]
  //  mov QWORD PTR [rbp-8], rax      : int* p1 = &arr[0]
  //  lea rax, [rbp-48]               : rax = &arr[0]
  //  mov QWORD PTR [rbp-16], rax     : int(*p2)[5] = &arr[0]
  //  mov eax, 0
  //  pop rbp
  //  ret
*/

/*
  int main(void)
  {
    int arr[5] = { 10, 20, 30, 40, 50 };

    int* p1 = arr;
    int(*p2)[5] = &arr;


    // "*arr" expression's data type is int
    // "*p1" expression's data type is int

    // "*&arr" expression's data type is int[5]
    // "*p2" expression's data type is int[5]
  }
*/

/*
  int main(void)
  {
    int arr[4] = { 10, 20, 30, 40};

    // -------------------------------------------------------

    int* p1 = arr;

    for (int i = 0; i < 5; ++i){
      printf("%p %p\n", arr + i, p1);
      ++p1;
    }

    // output ->
    //  000000E306DFFD50 000000E306DFFD50
    //  000000E306DFFD54 000000E306DFFD54
    //  000000E306DFFD58 000000E306DFFD58
    //  000000E306DFFD5C 000000E306DFFD5C
    //  000000E306DFFD60 000000E306DFFD60
    // increasing 0x04 = 4(decimal)

    putchar('\n');

    // -------------------------------------------------------


    int (*p2)[4] = &arr;

    for (int i = 0; i < 5; ++i){
      printf("%p %p\n", &arr + i, p2);
      ++p2;
    }
    
    // output ->
    //  000000E306DFFD50 000000E306DFFD50   
    //  000000E306DFFD60 000000E306DFFD60
    //  000000E306DFFD70 000000E306DFFD70
    //  000000E306DFFD80 000000E306DFFD80
    //  000000E306DFFD90 000000E306DFFD90
    // increasing 0x10 = 16(decimal) -> (4 * 0x04)
    
    // -------------------------------------------------------
  }
*/

/*
  int main(void)
  {
    int arr[5] = { 10, 20, 30, 40, 50 };

    int (*p)[5] = &arr;
    // *p     ===> arr
    // *p[5]  ===> arr[5] ===> *(arr + 5)

    // **p    ===> arr[0]
    // ++**p  ===> ++arr[0] ===> ++(*(arr + 0))

    for (int i = 0; i < 5; ++i)
      printf("%d ", (*p)[i]);
    putchar('\n');

    // output -> 10 20 30 40 50
  }
*/

/*
  #include "../headers/nutility.h"

  void foo(int (*p)[5])
  {
    print_array(*p, 5);   // output ->   1   2   3   4   5
  }

  int main(void)
  {
    int arr[5] = { 1, 2, 3, 4, 5 };
    foo(&arr);
  }
*/

/*
  int main(void)
  {
    int arr[5] = { 1, 2, 3, 4, 5 };
    int(*p)[5] = &arr;

    int* ptr  = *p;
    int* ptr2 = arr;
    int* ptr3 = &(*p)[0];
    // Those 3 lines are equivalent.
  }
*/

/*
  int main(void)
  {
    int arr[20];
    int* ptr = arr;
    int (*ptr2)[20] = &arr;

    // -------------------------------------------------------

    printf("%zu\n", sizeof(ptr));   // output -> 8
    // "ptr" identifier expression's data type is int*
    printf("%zu\n", sizeof(*ptr));  // output -> 4
    // "*ptr" expression's data type is int

    // -------------------------------------------------------

    printf("%zu\n", sizeof(ptr2));  // output -> 8
    // "ptr2" identifier expression's data type is int*
    printf("%zu\n", sizeof(*ptr2)); // output -> 80
    // "*ptr2" expression's data type is int[20]

    // -------------------------------------------------------

    printf("%zu\n", sizeof(*ptr2));     // output -> 80
    printf("%zu\n", sizeof(int[20]));   // output -> 80
    printf("%zu\n", sizeof(arr));       // output -> 80

    // -------------------------------------------------------
  }
*/

/*
  void foo_1(int* p);
  void foo_2(int p[]);
  void foo_3(int p[10]);
  // Those 3 lines are equivalent.

  void bar_1(int** p);
  void bar_2(int* p[]);
  void bar_3(int* p[10]);
  // Those 3 lines are equivalent.
*/

/*
                        -----------------
                        | void pointers |
                        -----------------
*/

/*
  - `void` is a type like `int` and `double` 
  - can not declare a variable from type `void`
  - can not declare an array holds `void` elements
  - `void` type can not be a `sizeof` operators operand
  - type of an expression(bir ifadenin türü) can be `void`

  - `void*` is a pointer type
  - `void*` is an object pointer type not a function pointer type
*/

/*
  int main(void)
  {
    void x; // syntax error
    // error: variable or field 'x' declared void

    void arr[5];  // syntax error
    // error: declaration of 'arr' as array of voids
  }
*/

/*
  int main(void)
  {
    sizeof(void); // syntax error
    // incomplete type 'void' is not allowed
  }
*/  

/*
  void foo(int);    
  int bar(int);

  int main(void)
  {
    foo(12);
    // "foo(12)" is an expression and its data type is `void`

    (void)bar(12);
    // "bar(12)" is an expression and its data type is `int`
    // casting an expression to `void` type
    // is used to express that bar's return value will be discarded.
  }
*/

/*
  void foo(int);
  // void function (function does not have a return value)

  int bar(void);
  // function does not have a parameter variable

  void baz() {}
  // functions does not give any information about its parameters

  int main(void)
  {
    baz(1);
    baz(1, 2);
    baz(1, 2, 3);
    // because of the function does not give
    // any information about its parameters 
    // those calls will not be a syntax error
  }
*/

/*
  void foo(int);

  int main(void)
  {
    if (foo(2)){} // syntax error
    // error: void value not ignored as it ought to be
  }
*/

/*
  // void* türünden bir değişkene harhangi bir türden 
  // bir nesnenin adresi atanabilir.
  
  float* foo(void);

  int main(void)
  {
    int ival = 5;
    double dval = 3.4;
    char str[] = "hello";
    
    // -------------------------------------------------------

    int* i_ptr;

    i_ptr = &ival;  // VALID
    i_ptr = &dval;  // VALID but WRONG
    i_ptr = str;    // VALID but WRONG
    i_ptr = foo();  // VALID but WRONG

    // -------------------------------------------------------

    void* v_ptr;
    i_ptr = &ival;

    v_ptr = &ival;  // VALID
    v_ptr = &dval;  // VALID
    v_ptr = str;    // VALID
    v_ptr = foo();  // VALID
    v_ptr = &v_ptr; // VALID

    v_ptr = i_ptr;  // VALID
    v_ptr = &i_ptr; // VALID

    // -------------------------------------------------------
  }
*/

/*
  // void* değişkenlere sadece adres atayınız.
  // tam sayı, gerçek sayı değerler atamayınız.

  int main(void)
  {
    void* v_ptr;
    int x = 34;

    v_ptr = x;    // VALID but WRONG
  }
*/

/*
  // when a function's parameter variable type is void*
  // it means that the function can take 
  // the address of any type of object.
  void foo(void* vp);
*/

/*
  - void* herhangi bir türden nesnenin adresini tutar fakat
    adresini tuttuğu nesnenin hangi türden olduğunu bilmez.
  - void* ile bir nesnenin adresini kullanabiliriz, fakat
    void pointer'ı dereference ederek o nesneye erişemeyiz.
*/

/*
  int main(void)
  {
    int x = 10;
    void* v_ptr = &x;

    *v_ptr = 20; // syntax error
    // warning: dereferencing 'void *' pointer
    // error: invalid use of void expression
  }
*/

/*
  // void* hangi türden nesnenin adresinin tuttuğunu bilmediği için 
  // pointer aritmetiğinden de faydalanamayız.

  int main(void)
  {
    int arr[10] = { 0 };
    void* vp = arr;

    ++vp; // syntax error
    // warning: wrong type argument to increment 

    vp + 1; // syntax error
    // warning: pointer of type 'void *' used in arithmetic

    void* vp1 = arr;
    void* vp2 = arr + 10;

    size_t size = vp2 - vp1; // syntax error
    // warning: pointer of type 'void *' used in subtraction
  }
*/

/*
  int main(void)
  {
    int ival = 5;
    double dval = 3.4;
    int arr[10] = { 0 };
    
    void* vp;

    vp = &ival;           // VALID
    vp = &dval;           // VALID
    vp = arr;             // VALID
    vp = "hello world";   // VALID  
    vp = NULL;            // VALID
  }
*/

/*
  int main(void)
  {
    int x = 5;

    void* vp = &x;

    if (vp == NULL)
      printf("vp is null pointer\n");
    else
      printf("vp is NOT null pointer\n");
    // output -> vp is NOT null pointer

    // -------------------------------------------------------

    vp = NULL;

    if (vp == NULL)
      printf("vp is null pointer\n");
    else
      printf("vp is NOT null pointer\n");
    // output -> vp is null pointer
  }
*/

/*
  int main(void)
  {
    int x = 5;
    double dval = 3.4;
    void* vp = &x;

    // -------------------------------------------------------

    if (vp == &x)
      printf("vp is equal to &x\n");
    else
      printf("vp is NOT equal to &x\n");
    // output -> vp is equal to &x

    // -------------------------------------------------------

    vp = &dval;

    if (vp == &dval)
      printf("vp is equal to &dval\n");
    else
      printf("vp is NOT equal to &dval\n");
    // output -> vp is equal to &dval

    // -------------------------------------------------------
  }
*/

/*
  int main(void)
  {
    int x = 5;

    void* vp = &x;  // VALID
    // implicit conversion from int* to void* (int* -> void*)

    int* ip = vp;   // VALID in C, syntax error in C++
    // implicit conversion from void* to int* (void* -> int*)
  }
*/

/*
  #include <stddef.h> // size_t

  int main(void)
  {
    double d1 = 34.23764;
    double d2;

    const char* p1 = (const char*)&d1;
    char* p2 = (char*)&d2;
    size_t n = sizeof(double);

    while (n--)
      *p2++ = *p1++;

    printf("%f\n", d1);   // output -> 34.237640
    printf("%f\n", d2);   // output -> 34.237640
  }
*/

/*
  #include "../headers/nutility.h"

  // copy_T is a generic function
  void copy_T(void* vp_dest, const void* vp_src, size_t n)
  {
    const char* p_src = vp_src;
    // const char* p_src = (const char*)vp_src;

    char* p_dest = vp_dest;
    // char* p_dest = (char*)vp_dest;

    while (n--)
      *p_dest++ = *p_src++;
  }

  int main(void)
  {
    // -------------------------------------------------------

    double d1 = 2893.12331;
    double d2;
    copy_T(&d2, &d1, sizeof(double));

    printf("%f\n", d2); // output -> 2893.123310

    // -------------------------------------------------------

    int i1 = 92383;
    int i2;
    copy_T(&i2, &i1, sizeof(int));

    printf("%d\n", i2); // output -> 92383

    // -------------------------------------------------------

    int a[] = { 1, 2, 3, 4, 5 };
    int b[5];
    copy_T(b, a, sizeof a);

    print_array(b, 5);  // output -> 1 2 3 4 5

    // -------------------------------------------------------
  }
*/

/*
  #include "../headers/nutility.h"

  // swap_T is a generic function
  void swap_T(void* vp1, void* vp2, size_t size)
  {
    char* p1 = vp1;
    char* p2 = vp2;

    while (size--)
    {
      char temp = *p1;
      *p1++ = *p2;
      *p2++ = temp;
    }
  }

  int main(void)
  {
    // -------------------------------------------------------

    int x = 5, y = 457;

    printf("x = %d, y = %d\n", x, y);   
    // output -> x = 5, y = 457

    swap_T(&x, &y, sizeof(int));

    printf("x = %d, y = %d\n", x, y);
    // output -> x = 457, y = 5

    // -------------------------------------------------------

    double d1 = 3.4, d2 = 5.6;

    printf("d1 = %f, d2 = %f\n", d1, d2);
    // output -> d1 = 3.400000, d2 = 5.600000

    swap_T(&d1, &d2, sizeof(double));

    printf("d1 = %f, d2 = %f\n", d1, d2);
    // output -> d1 = 5.600000, d2 = 3.400000

    // -------------------------------------------------------

    int arr1[5] = { 1, 2, 3, 4, 5 };
    int arr2[5] = { 10, 20, 30, 40, 50 };

    print_array(arr1, 5);  // output -> 1 2 3 4 5
    print_array(arr2, 5);  // output -> 10 20 30 40 50

    swap_T(arr1, arr2, sizeof(int[5]));

    print_array(arr1, 5);  // output -> 10 20 30 40 50
    print_array(arr2, 5);  // output -> 1 2 3 4 5

    // -------------------------------------------------------
  }
*/

/*
  // Write a generic function that reverse an array
  // { 1, 2, 3, 4, 5 } ===> { 5, 4, 3, 2, 1 }

  #include <stddef.h> // size_t
  #include "../headers/nutility.h"

  #define   SIZE  10

  void reverse_arr1_T(void* vp_arr, size_t arr_size, size_t elem_size)
  {
    char* p = vp_arr;

    for (size_t i = 0; i < arr_size / 2; ++i)
    {
      swap_T( p + i * elem_size, 
              p + (arr_size - 1 - i) * elem_size, 
              elem_size);
    }
  }

  void reverse_arr2_T(void* vp_arr, size_t arr_size, size_t elem_size)
  {
    char* p_first = vp_arr;
    char* p_last = p_first + (arr_size - 1) * elem_size;

    while(p_first < p_last)
    {
      swap_T(p_first, p_last, elem_size);
      p_first += elem_size;
      p_last -= elem_size;
    }
  }
    
  int main(void)
  {
    // -------------------------------------------------------

    int arr[SIZE];

    randomize();
    set_array_random(arr, SIZE);
    print_array(arr, SIZE);
    // output ->  848 573 894 227 690 847 619 553 525 677

    reverse_arr1_T(arr, SIZE, sizeof arr[0]);
    reverse_arr1_T(arr, SIZE, sizeof *arr);
    reverse_arr1_T(arr, SIZE, sizeof(int));
    // Those 3 lines are equivalent.

    print_array(arr, SIZE);
    // output ->  677 525 553 619 847 690 227 894 573 848

    // -------------------------------------------------------

    double d_arr[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };

    for (size_t i = 0; i < asize(d_arr); ++i)
      printf("%f ", d_arr[i]);
    // output -> 
    //  1.100000 2.200000 3.300000 4.400000 5.500000 6.600000 7.700000

    putchar('\n');

    reverse_arr2_T(d_arr, asize(d_arr), sizeof d_arr[0]);

    for (size_t i = 0; i < asize(d_arr); ++i)
      printf("%f ", d_arr[i]);
    // output ->
    //  7.700000 6.600000 5.500000 4.400000 3.300000 2.200000 1.100000

    // -------------------------------------------------------
  }
*/

/*
  Write a generic function that sort an array ascending
    - we can write a sort algorithm 
    - we can find out addresses of the contigious elements.
    - we can swap those elements
    - we CAN NOT find out which of them is greater
      cause we don't know the type of array elements
      (function pointers will solve this problem)
      -> if type is int will be pass a funtion pointer that 
        is pointing to the function that compares two integers
      -> if type is double will be pass a funtion pointer that
        is pointing to the function that compares two doubles

      so generic sort function can call those functions by 
      using function pointers.
*/

/*
  void** vpp;
  - vpp değişkenine herhangi bir türden değişkenin adresini atayamayız.
  - vpp generic bir pointer değildir.
  - "*vpp" ifadesi atama operatörünün sol operandı olabilir.
  - void**, void* türünden bir nesnenin adresi olan türdür.

  void* vp;
  - vp değişkenine herhangi bir türden değişkenin adresini atayabiliriz.
  - vp generic bir pointerdır.
  - "*vp" ifadesi atama operatörünün sol operandı olamaz. Sentaks hatası.
    
*/

/*
  int main(void)
  {
    int ival = 10;
    double dval = 3.4;

    void* vp = &ival;
    void** vpp = &vp;

    *vpp = &dval;
    if (vp == &dval)
      printf("vp is equal to &dval\n");
    else
      printf("vp is NOT equal to &dval\n");
    // output -> vp is equal to &dval
  }
*/

/*
  void foo(void**);

  int main(void)
  {
    int x = 10;
    void* vp = &x;

    // -------------------------------------------------------

    foo(&vp);   
    // foo fonksiyonu vp değişkeninin değerini değiştirebilir.

    // -------------------------------------------------------

    void** vpp = &vp;
    **vpp = 34; // syntax error     
    // error: invalid use of void expression
    // warning: dereferencing 'void *' pointer
    // **vpp ===> *vp (dereferencing void pointer)

    // -------------------------------------------------------

    void* vp_arr[10];
    // farklı türlerin adreslerini tutabilen dizi.

    void* vp1, *vp2, *vp3;
    void** vpp_arr[] = { &vp1, &vp2, &vp3 };

    // -------------------------------------------------------
  }
*/

/*
                    ---------------------
                    | function pointers |
                    ---------------------
*/

/*
  bir fonksiyonun adresi, ilgili fonksiyonun
    - geri dönüş değeri türü
    - parametre sayısı
    - parametre türleri
  ile ilişkilidir.
*/

/*
  int f1(int);
  int f2(int);
  // f1 and f2 function's addresses are same types.

  double f3(double);
  double f4(double, double);
  int f5(double)
  // f3 and f4 and f5 function's addresses are different types.
*/

/*
  #include <stddef.h> // size_t 

  int f1(int);
  // int(*)(int) is the type of f1 function's address.

  int f2(int, int);
  // int(*)(int, int) is the type of f2 function's address.

  double f3(double);
  // double(*)(double) is the type of f3 function's address.

  size_t strlen(const char*);
  // size_t(*)(const char*) is the type of strlen function's address.
*/

/*
  ------------------------------------------------------------------
  | function                | int f1(int)                          |
  | function type           | int(int)                             |
  | function pointer type   | int(*)(int)                          |
  |----------------------------------------------------------------|
  | function                | double f2(double, double)            |
  | function type           | double(double, double)               |  
  | function pointer type   | double(*)(double, double)            |
  |----------------------------------------------------------------|
  | function                | size_t strlen(const char*)           |
  | function type           | size_t(const char*)                  |
  | function pointer type   | size_t(*)(const char*)               |
  |----------------------------------------------------------------|
  | function                | int strcmp(const char*, const char*) |
  | function type           | int(const char*, const char*)        | 
  | function pointer type   | int(*)(const char*, const char*)     | 
  ------------------------------------------------------------------
*/

/*
  C dilinde bir fonksiyonun adresini elde etmek için
    1. fonksiyon ismini adres operatörünün(&) operandı yapmak.
    2. fonksiyon ismini kullanmak.
      (implicit function to pointer conversion)
*/

/*
  int foo(int, int);

  int main(void)
  {
    &foo; 
    // "&foo" is an expression and its data type is int(*)(int,int)

    foo;  // function to pointer conversion
    // "foo" is an expression and its data type is int(*)(int,int)
  }
*/

/*
  int f1(int, int);
  int f2(int, int);

  void f3(int, int);

  int main(void)
  {
    // -------------------------------------------------------

    int(*fp)(int, int) = f1;
    // "fp" is a function pointer variable.

    int(*fp2)(int, int) = &f2;
    // "fp2" is a function pointer variable.

    fp2 = f1;   // function to pointer conversion
    fp2 = &f1;
    // Those 2 lines are equivalent.

    // -------------------------------------------------------

    int(*fp3)(int, int) = f3;   // syntax error
    fp3 = f3;                   // syntax error
    // error: assignment to 'int (*)(int,  int)' 
    // from incompatible pointer type 'void (*)(int,  int)'

    // -------------------------------------------------------
  }
*/

/*
  typedef int(*FPTR)(int, int);

  int foo(int, int);
  int bar(int, int);
  int baz(int, int);

  int main(void)
  {
    // -------------------------------------------------------

    FPTR fp1 = foo;
    int(*fp2)(int, int) = foo;
    // Those 2 lines are equivalent.

    // -------------------------------------------------------

    FPTR fp3, fp4;
    fp3 = bar;
    fp4 = fp3;  // VALID

    // -------------------------------------------------------
  }
*/

/*
  typedef int(*FPTR)(int, int);

  int (*g_fp)(int, int);  
  FPTR g_fp2;
  // global pointer variable
  // static storage duration object.

  void func(void)
  {
    int (*fp)(int, int);
    FPTR fp2;
    // local pointer variable
    // automatic storage duration object.

    static int (*s_fp)(int, int);
    static FPTR s_fp2;
    // local pointer variable
    // static storage duration object.
  }

  void foo(int(*fp_param)(int, int), FPTR fp_param2)
  {
    // fp_param is a function pointer parameter variable
    // automatic storage duration object.
  }
*/

/*
  // Initialize a variable called "fp" with foo's address
  // Initialize a varibale called "fpp" with fp's address
 
  int foo(int, int);

  int main(void)
  {
    int(*fp)(int, int) = foo;
    // "fp" is a function pointer variable.

    int(**fpp)(int, int) = &fp;
    // "fpp" is a pointer to a function pointer 
    // "fpp" is an object pointer.
  }
*/

/*
  typedef int(*FPTR)(int, int);

  int foo(int, int);

  int main(void)
  {
    FPTR fp = foo;
    // "fp" is a function pointer variable.

    FPTR* fpp = &fp;
    // "fpp" is a pointer to a function pointer
    // "fpp" is an object pointer.
  }
*/

/*
  // Write an array that holds 10 function pointers  
  // with the type of foo's address type.

  int foo(int, int);

  int main(void)
  {
    int(*fp_arr[10])(int);  
    // "fp_arr" is an array that holds 10 function pointers
  }
*/

/*
  typedef int(*FPTR)(int);

  int f1(int);
  int f2(int);
  int f3(int);
  int f4(int);

  int main(void)
  {
    int(*fp_arr_1[4])(int)  = { f1, f2, f3, f4 };
    int(*fp_arr_2[4])(int)  = { &f1, &f2, &f3, &f4 };
    int(*fp_arr_3[])(int)   = { f1, f2, f3, f4 };
    FPTR fp_arr_4[4] = { &f1, &f2, &f3, &f4 };
    // Those 4 lines are equivalent.
  }
*/

/*
  void foo(void)
  {
    printf("void foo(void) is called\n");
  }

  int main(void)
  {
    foo();    // output -> void foo(void) is called
    // "()" is a function call(fonksiyon çağrı) operator

    // "foo" identifier(function designator) is 
    // function call operator's operand
    // "foo" will be implictly converted to a function pointer

    // operand of the function call operator is a function address,
    // in this case "foo" function's address

    (&foo)();   // output -> void foo(void) is called
    // "()" precedence is higher than "&"


    void(*fp)(void) = foo;
    fp();       // output -> void foo(void) is called
  }
*/

/*
  void f1(void){ printf("f1 is called\n"); }
  void f2(void){ printf("f2 is called\n"); }
  void f3(void){ printf("f3 is called\n"); }

  int main(void)
  {
    void(*fp)(void);

    fp = &f1;
    fp();   // output -> f1 is called

    fp = f2;
    fp();   // output -> f2 is called

    fp = f3;
    fp();   // output -> f3 is called
  }
*/

/*
  void foo(void){ printf("foo is called\n"); }

  int main(void)
  {
    // -------------------------------------------------------

    void(*fp)(void) = foo;

    // dereferencing a function pointer is VALID

    fp();       // output -> foo is called
    (*fp)();    // output -> foo is called
    // *fp ==> f1  ---  (*fp)() ==> f1()
    // precedence of "()" is higher than "*"

    // -------------------------------------------------------

    foo();       // output -> foo is called
    (*foo)();    // output -> foo is called
    (&foo)();    // output -> foo is called 

    // -------------------------------------------------------
  }
*/

/*
  void f1(void){ printf("f1 is called\n"); }
  void f2(void){ printf("f2 is called\n"); }

  void foo(void(*fp_param)(void))
  {
    // fp_param();
    (*fp_param)();
  }

  int main(void)
  { 
    foo(f1);    // output -> f1 is called
    foo(&f1);   // output -> f1 is called

    foo(f2);    // output -> f2 is called
    foo(&f2);   // output -> f2 is called
  }
*/

/*
  #include <ctype.h>  
  // isupper, islower, isdigit, isxdigit, ispunct

  void print_chars(int(*fp_ctest)(int))
  {
    for (int i = 0; i < 128; ++i)
      if (fp_ctest(i))
        putchar(i);

    putchar('\n');
  }

  int main(void)
  {
    print_chars(isupper); 
    // output -> ABCDEFGHIJKLMNOPQRSTUVWXYZ
    print_chars(islower);
    // output -> abcdefghijklmnopqrstuvwxyz
    print_chars(isdigit);
    // output -> 0123456789
    print_chars(isxdigit);
    // output -> 0123456789ABCDEFabcdef
    print_chars(ispunct);
    // output -> !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
  }
*/

/*
  void print_int_decimal(const void* vp)
  {
    int val = *(const int*)vp;
    printf("(%d)\n", val);
  }

  void print_int_hex(const void* vp)
  {
    int val = *(const int*)vp;
    printf("(%#x)\n", val);
  }

  void print_double(const void* vp)
  {
    double val = *(const double*)vp;
    printf("(%f)\n", val);
  }

  void print_T(const void* vp, void(*fp)(const void*))
  {
    fp(vp);
  }

  int main(void)
  {
    int ival = 10;
    double dval = 3.4;

    print_T(&ival, print_int_decimal);  // output -> (10)
    print_T(&ival, print_int_hex);      // output -> (0xa)
    print_T(&dval, print_double);       // output -> (3.400000)
  }
*/

/*
  // ------------------------------------------------

  typedef int (*FPTYPE_1)(const char*, const char*);

  int foo_1(int, int);

  int (*bar_1(void))(int, int)
  {
    return foo_1;
  }

  FPTYPE_1 bar_1_2(void)
  {
    return foo_1;
  }

  // ------------------------------------------------

  typedef int (*FPTYPE_2)(const char*, const char*);

  int foo_2(const char*, const char*);

  int (*bar_2(void))(const char*, const char*)
  {
    return foo_2;
  }

  FPTYPE_2 bar_2_2(void)
  {
    return foo_2;
  }

  // ------------------------------------------------
*/

/*
  int g_arr[5] = { 1, 2, 3, 4, 5 };

  // --------------------------------------------------

  // Write a function that returns first element of g_arr

  int* foo(void)
  {
    return g_arr;
  }

  // --------------------------------------------------

  // Write a function that returns whole g_arr(return array pointer)

  int (*bar_1(void))[5]
  {
    return &g_arr;
  }

  typedef int INTARR5[5];
  typedef int(*P_INTARR5)[5];

  P_INTARR5 BAR_2(void)
  {
    return &g_arr;
  }

  INTARR5* BAR_3(void)
  {
    return &g_arr;
  }

  // --------------------------------------------------
*/

/*
  void foo() {}
  void bar(void) {}

  int main(void)
  {
    foo();        // VALID
    foo(1);       // VALID
    foo(1, 2);    // VALID
    foo(1, 2, 3); // VALID

    bar();        // VALID
    bar(1);       // syntax error
    // error: too many arguments to function 'bar'
  }
*/

/*
  void f1(void);
  void f2(int);
  void f3(int, int);
  void f4(int, int, int);
  void f5(double);
  void f6(double, double);

  int main(void)
  {
    // --------------------------------------------------

    void(*fp1)() = f1;  // VALID
    fp1 = f2;           // VALID
    fp1 = &f3;          // VALID
    fp1 = f4;           // VALID
    fp1 = &f5;          // VALID
    fp1 = f6;           // VALID

    // --------------------------------------------------

    void(*fp2)(void) = f1;  // VALID

    fp2 = f2; // syntax error
    // error: initialization of 'void (*)(void)' 
    // from incompatible pointer type 'void (*)(int)'

    // --------------------------------------------------
  }
*/

/*
  //  <----- check default.h & default.c ---->

  #include "default.h"

  void f3(void){ printf("f3 function is called\n"); }

  int main(void)
  {
    f1();   // output -> f2 function is called

    FP_TYPE default_fp = set_f1(f3);
    // f1 function's default behavior has been changed.
    // "default_fp" function pointer variable points to
    // default function that f1 is calling befor

    f1();   // output -> f3 function is called

    set_f1(default_fp);
    // f1 function's default behavior has been changed back
    // to its original behavior.

    f1();   // output -> f2 function is called
  }
*/

/*
                  ---------------------------
                  | function pointer arrays |
                  ---------------------------
*/

/*
  int f1(int, int);
  int f2(int, int);
  int f3(int, int);
  int f4(int, int);
  int f5(int, int);

  int main(void)
  {
    int(*fp_arr[5])(int, int);

    fp_arr[2] = f1;
    fp_arr[3] = f2;
    fp_arr[4] = f3;
    fp_arr[0] = f4;
    fp_arr[1] = f5;

    int(*fp_arr_2[])(int, int) = { f1, f2 };

    int(*fp_arr_3[])(int, int) = { [2] = f2 };
  }
*/

/*
  void f1(int x, int y)
  {
    printf("f1 is called x = %d, y = %d\n", x, y);
  }

  void f2(int x, int y)
  {
    printf("f2 is called x = %d, y = %d\n", x, y);
  }

  void f3(int x, int y)
  {
    printf("f3 is called x = %d, y = %d\n", x, y);
  }

  int main(void)
  {
    void(*fp_arr[])(int, int) = { f1, f2, f3 };

    for (int i = 0; i < 3; ++i)
      fp_arr[i](i, i);

    // output ->
    //  f1 is called x = 0, y = 0
    //  f2 is called x = 1, y = 1
    //  f3 is called x = 2, y = 2
  }
*/

/*
  Kullanım alanı :
  - lojik ilişki içindeki fonksiyonların adreslerini bir dizide tutmak
    ve bu diziye bir indeks oluşturarak, client kodun istediği 
    fonksiyonu çağırmak. (jumptable)

  Örneğin bir otomasyon programında tuşlar var ve kullanıcı bir tuşa
  bastığında bir event'in gerçekleşmesi gerekiyor.
  Eventler fonksiyonlar şeklinde ifade edilmiş. Bu fonksiyonların
  adresleri bir fonksiyon pointer dizisinde tutulmuş. Kullanıcı 
  hangi tuşa bastıysa o tuş fonksiyon pointer dizisinde gerekli 
  indekse dönüştürülüp o indeksteki fonksiyon çağırılıyor.
    Her tuş bir fonksiyon adresine map edilmiş durumda.
*/

/*
  #include <ctype.h>

  void print_menu(void)
  {
    printf(
      "[1] isupper\n"
      "[2] islower\n"
      "[3] isalpha\n"
      "[4] isdigit\n"
      "[5] isalnum\n"
      "[6] isxdigit\n"
      "[7] ispunct\n"
      );
  }

  int get_option(void)
  {
    print_menu();
    int option;

    printf("Enter an option : ");
    scanf("%d", &option);
    return option;
  }

  int(*g_fp_arr[])(int) = {
    NULL,
    &isupper,
    &islower,
    &isalpha,
    &isdigit,
    &isalnum,
    &isxdigit,
    &ispunct,
  };

  int main(void)
  {
    printf("Enter a character : ");
    int ch = getchar();

    int op = get_option();

    if (g_fp_arr[op](ch))
      printf("Character is in the set\n");
    else
      printf("Character is NOT in the set\n");

    // input -> Enter a character : A
    // input -> Enter an option : 1 ----> (isupper)
    // output -> Character is in the set

    // input -> Enter a character : 5
    // input -> Enter an option : 1 ----> (isupper)
    // output -> Character is NOT in the set

    // input -> Enter a character : F
    // input -> Enter an option : 6 ----> (isxdigit)
    // output -> Character is in the set
  }
*/

/*
  #include <ctype.h>
  #include <string.h> // strcmp
  #include <stddef.h> // size_t
  #include "../headers/nutility.h"

  typedef int(*FP_CTEST)(int);

  FP_CTEST g_fp_arr[] = {
    &isupper,
    &islower,
    &isalpha,
    &isdigit,
    &isalnum,
    &isxdigit,
    &ispunct,
  };

  const char* const fp_names[] = {
    "isupper",
    "islower",
    "isalpha",
    "isdigit",
    "isalnum",
    "isxdigit",
    "ispunct",
  };

  int main(void)
  {
    int ch;
    printf("Enter a character : ");
    ch = getchar();

    char function_name[40];
    printf("Enter a function name : ");
    scanf("%s", function_name);

    size_t i = 0;
    for (;i < asize(fp_names) && strcmp(function_name, fp_names[i]); ++i)
      ; // null statement

    if (i == asize(fp_names))
      printf("Invalid function name\n");
    else if (g_fp_arr[i](ch))
      printf("Character is in the set\n");
    else
      printf("Character is NOT in the set\n");

    // input -> Enter a character : A
    // input -> Enter a function name : isupper
    // output -> Character is in the set

    // input -> Enter a character : 5
    // input -> Enter a function name : isupper
    // output -> Character is NOT in the set

    // input -> Enter a character : 9
    // input -> Enter a function name : isdigit
    // output -> Character is in the set

    // input -> Enter a character : 9
    // input -> Enter a function name : isfunction
    // output -> Invalid function name
  }
*/

/*
  void Jump(void) { printf("Jump is called\n"); }         // Space
  void Run(void)  { printf("Run is called\n"); }          // Shift
  void Forward(void) { printf("Forward is called\n"); }   // W
  void Backward(void) { printf("Backward is called\n"); } // S
  void Left(void) { printf("Left is called\n"); }         // A
  void Right(void) { printf("Right is called\n"); }       // D

  void(*g_fp_arr[])(void) = {
    Jump, Run, Forward, Backward, Left, Right };
*/

/*
  void f1(void);
  void f2(int);
  void f3(int, int);
  void f4(int, int, int);
  void f5(double);
  void f6(double, double);

  int main(void)
  {
    void(*fp_arr[])() = { f1, &f2, f3, &f4, f5, &f6 };
  }
*/

/*
  // <----- check register.h & register.c ---->

  #include "register.h"

  void f1(void) { printf("f1 function is called\n"); }
  void f2(void) { printf("f2 function is called\n"); }
  void f3(void) { printf("f3 function is called\n"); }
  void f4(void) { printf("f4 function is called\n"); }
  void f5(void) { printf("f5 function is called\n"); }

  int main(void)
  {
    register_fn(f1);
    register_fn(f2);
    register_fn(f3);
    register_fn(f4);
    register_fn(f5);

    call_registered_fns();
    // output ->
    //  f5 function is called
    //  f4 function is called
    //  f3 function is called
    //  f2 function is called
    //  f1 function is called
  }
*/

/*
  #include <stdlib.h> // exit, atexit

  void f1(void) { printf("f1 function is called\n"); }
  void f2(void) { printf("f2 function is called\n"); }
  void f3(void) { printf("f3 function is called\n"); }
  void f4(void) { printf("f4 function is called\n"); }
  void f5(void) { printf("f5 function is called\n"); }

  int main(void)
  {
    atexit(f1);
    atexit(f2);
    atexit(f3);
    atexit(f4);
    atexit(f5);

    printf("[0] main started\n");
    exit(1);
    printf("[1] main continues\n");

    // output ->
    //  [0] main started
    //  f5 function is called
    //  f4 function is called
    //  f3 function is called
    //  f2 function is called
    //  f1 function is called
  }
*/

/*
                        ------------------
                        | pointer errors |
                        ------------------
*/

/*
  int main(void)
  {
    int* p;   // wild(invalid) pointer
    *p = 110; // undefined behavior(ub)
  }
*/

/*
  int main(void)
  {
    int* p1, p2;
    // p1's type is int*
    // p2's type is int

    int x = 10;
    p1 = &x;
    p2 = p1;  // implicit conversion from int* to int
    // error: assignment to 'int' from 'int *' 
    // makes integer from pointer without a cast

    int* p3, *p4;
    // p3's type is int*
    // p4's type is int*
  }
*/

/*
  #define   IPTR  int*   

  int main(void)
  {
    int x = 10;

    IPTR p3, p4;      
    // preprocessor replaces IPTR with int* --> int* p3, p4
    // p3's type is int*
    // p4's type is int

    p3 = &x;
    p4 = p3;  // implicit conversion from int* to int
    // error: assignment to 'int' from 'int *' 
    // makes integer from pointer without a cast
  }
*/

/*
  typedef int* IPTR;

  int main(void)
  {
    int x = 10;

    IPTR p3, p4;
    // p3's type is int*
    // p4's type is int*

    p3 = &x;
    p4 = p3;
  }
*/

/*
  typedef int* IPTR;

  int main(void)
  {
    int x = 10;

    const IPTR p1 = &x;    // top level const
    int* const p2 = &x;
    // Those 2 lines are equivalent.
  }
*/