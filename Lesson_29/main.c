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