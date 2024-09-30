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

  int main(){
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

  int main()
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

  int main()
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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"
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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"
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
  #include "../nutility.h"

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

  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

  int main(void)
  {
    int a[5] = { 10, 20, 30, 40, 50 };

    ++*a;   // ++(*(&a[0]))   ===> ++a[0]
    print_array(a, 5);    // output -> 11 20 30 40 50
  }
*/

/*
  #include "../nutility.h"

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
  #include "../nutility.h"

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
    foo(a + 4, a + 2);  // undefined behaviour(ub)

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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

  #include "../nutility.h"

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
  #include "../nutility.h"

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

  #include "../nutility.h"

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
  #include "../nutility.h"

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

  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
