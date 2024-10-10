#include <stdio.h>

/*
                  --------------------------------------
                  | Type Conversions (Tür Dönüşümleri) |
                  --------------------------------------
*/

/*
  1. implicit type conversions (örtülü tür dönüşümleri)
    we did not give any command for compiler to convert the type 
    but compiler is doing the conversion because of the language rules

    a. assignment type conversions (atama tür dönüşümleri)
      source type will be converted to target type then assignment will be done
    b. arithmetic type conversions (aritmetik tür dönüşümleri)

  2. explicit type conversions (açık tür dönüşümleri)
    we give the command to the compiler to convert the type by using 
    an operator
*/

/*
                      -----------------------------
                      | implicit type conversions |
                      -----------------------------
*/

/*
  int main(void){
    int i1 = 10;
    int i2 = 3;

    double dval = i1 / i2; // (int / int = int) 
    printf("dval = %f\n", dval); 
    // output -> dval = 3.000000
  }
*/

/*
  assignment type conversions (implicit)
  --------------------------------------
  1.
  int x = expr;   if expr's type and x's type are different

  2.
  x = y;          if y's type and x's type are different

  3. 
  void foo(int);
  foo(arg);       if arg's type and foo's parameter type are different

  4.
  int bar(void){
    return expr;  if expr's type and bar's return type are different
  }
*/

/*
  arithmetic type conversions (implicit)
  --------------------------------------
  a + b
    -> operation will never be done with different types
    -> "a" can be converted to "b"s type or "b" can be converted to "a"s type
    or both can be converted to a common type

  x > y
  +x
  !x

  -> arithmetic type conversion are done 
  according to not losing any information

  -> every type have ranks  
    (floating types > integral types)  
    long double > double > float 
    long long > long > int > short > char > _Bool

    double + int -> double
    double + long double -> long double
    float + int -> float
    double + char -> double
    float + long long -> float

  -> if there is no floating type operand and there are some operands have 
    short > char > _Bool types,
    those operands will promoted to int (integral promotion)

  AFTER INTEGRAL PROMOTION IS DONE 

  -> if one operand have an higher rank than the other
  and the higher rank is unsigned , operation will be done with unsigned type

    unsigned long long + long  -> unsigned long long
    unsigned long + int        -> unsigned long

  -> if both operands have the same rank and one of them is unsigned
  operation will be done with unsigned type

    unsigned int + int    -> unsigned int
    unsigned long + long  -> unsigned long

  -> ranks are different, higher rank is signed, lower rank is unsigned
  if higher signed rank can hold every value that lower unsigned rank 
  can hold then operation will be done in higher signed type 
  else operation will be done with higher ranks unsigned type

    long long(8) + unsinged int(4) -> long long
      (long long can hold unsigned int -> long long)
    long(4) + unsigned int(4)      -> unsigned long 
      (long can not hold unsinged int -> unsigned long)
*/

/*
  int main(void){
    char c1 = 3;
    char c2 = 5;

    c1 + c2; // char + char -> int
    // both(char) will be promoted to int and 
    // operation will be done ===> int + int -> int

    short x1 = -3;
    short x2 = 12;

    x1 + x2; // short + short -> int
    // both(short) will be promoted to int and 
    // operation will be done ===> int + int -> int
  }
*/

/*
  int main(void){
    int x = 5;
    unsigned int y = 3;

    x * y; // int * unsigned int -> unsigned int
    // rank : int = unsigned int
    // if ranks are same unsigned will be choosen 
    // so operation will be done with unsigned int

    long k = 5;
    unsigned int m = 3;
    
    k * m; // long * unsigned int -> unsigned long
    // rank : long > unsigned int
    // long can not hold all values of unsigned int
    // so operation will be done with unsigned long

    long long m = 5;
    unsigned long n = 3;

    m * n;  // long long * unsigned long -> long long
    // rank : long long > unsigned long
    // long long(8 byte) can hold all values of unsigned long(4 byte)
    // so operation will be done with long long
  }
*/

/*
  int main(void){
    int x = -1;
    unsigned int y = 2;

    if (x > y)
      printf("x is greater than y\n");
    else
      printf("y is greater than x\n");

    // output -> x is greater than y

    // rank : int = unsigned int
    // if ranks are same unsigned will be choosen
    // x will be converted to unsigned int
    // -1 -> bit(32) -> 1111 1111 1111 1111 1111 1111 1111 1111

    // if (4294967295 > 2)
    //   printf("x is greater than y\n");
    // else
    //   printf("y is greater than x\n");
  }
*/

/*
  // if an operation is done in one of the signed types 
  // and if there is an overflow in the operation
  // it will be undefined behavior(UB)

  int main(void){
    int x = 2147483647;
    int y = 2147483647;

    x + y; // int + int -> int
    // 2147483647 + 2147483647 = 4294967294
    // 4294967294 is not in the range of int
    // so it will be undefined behavior(UB)
  }
*/

/*
  // if an operation is done in one of the unsigned types 
  // and if there is an overflow in the operation
  // data will be lost but will not be undefined behavior(UB)

  #include <limits.h>

  int main(void){
    long long int a = 2000000000;   // 2'000'000'000
    long long int b = 1000;   
    printf("long long int max value in hex = %llx\n", LLONG_MAX);
    // output -> 7fffffffffffffff
    printf("a * b = %llx\n", a * b); 
    // output -> a * b = 1d1a94a2000

    unsigned int x = 2000000000;  // 2'000'000'000
    unsigned int y = 1000;
    printf("unsigned int max value in hex = %x\n", UINT_MAX);
    // output -> unsigned int max value in hex = ffffffff

    printf("x * y = %x\n", x * y);
    // output -> x * y = a94a2000

    // normally (x * y) = 0x1d1a94a2000
    // but because of overflow, upper bits will be lost
    // (x * y) = 0xa94a2000 // lower 32 bits of the result
    // NO Undefined Behavior
  }
*/

/*
  int main(void){
    char c = 10;
    +c; // R value expression and integral promotion happened
  }
*/

/*
  int main(void){
    int x = 10;

    double dval = (x > 5 ? 5 : 5.) / 2;
    // ternary operators 2nd and 3rd operands 
    // will be converted to a common type
    // 2nd operand is int, 3rd operand is double
    // (x > 5 ? 5 : 5.) expressions type is be double
    // double / int -> double
    printf("dval = %f\n", dval); // output -> dval = 2.500000
  }
*/

/*
  a(int), b(int), c(double)
  "*" multiplication operator is left associative

  a * b * c         (int * int) * double -> double    
   if overflow happens undefined behavior(UB) 
  
  c * b * a         (double * int) * int -> double
   overflow risk is lower because double(8 byte) can hold more values 
*/

/*
  int main(void){
    int ival = 10;
    double dval = ival * 3.4;
  }

  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-4], 10         : ival = 10
  //    pxor xmm1, xmm1                   : xmm1 = 0 -> (clearing xmm1)
  //    cvtsi2sd xmm1, DWORD PTR [rbp-4]  : xmm1 = (double)ival
  //    movsd xmm0, QWORD PTR .LC0[rip]   : xmm0 = 3.4
  //    mulsd xmm0, xmm1                  : xmm0 = xmm0 * xmm1
  //    movsd QWORD PTR [rbp-16], xmm0    : dval = xmm0
  //    mov eax, 0
  //    pop rbp
  //    ret
  //  .LC0:
  //    .long -858993459
  //    .long 1074318540

  // CVTSI2SD — 
  // (CVT)convert (SI)signed integer (2)to (SD)Scalar dobule 
  // Convert Doubleword Integer to Scalar Double Precision Floating-Point Value
*/

/*
  int main(void){
    double dval = 4.5;
    int ival = dval;
    // ival is target type, dval is source type
    // conversion will always be done from source type to -> target type
  }

  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    movsd xmm0, QWORD PTR .LC0[rip]     : xmm0 = 4.5
  //    movsd QWORD PTR [rbp-8], xmm0       : dval = xmm0
  //    movsd xmm0, QWORD PTR [rbp-8]       : xmm0 = dval
  //    cvttsd2si eax, xmm0                 : eax = (int)dval
  //    mov DWORD PTR [rbp-12], eax         : ival = eax
  //    mov eax, 0
  //    pop rbp
  //    ret
  //  .LC0:
  //    .long 0
  //    .long 1074921472

  // CVTTSD2SI — 
  // (CVT)Convert (T)Trunctation (SD)Scalar Double (2)to (SI)Signed Integer

  // Convert With Truncation Scalar Double Precision Floating-Point Value 
  // to SignedInteger
*/

/*
  int main(void){
    int x = 1756980; // 0x1acf34

    unsigned short us = x;
    // us = 0x1acf34 & 0xffff = 0xcf34 
    // lower 16 bits of x will be assigned to us

    printf("us = %hu\n", us); 
    // 0xcf34 = 0b1100111100110100 = 53044
    // output -> us = 53044

    short s = x;
    // from higher ranked signed type to lower ranked signed type
    // how this assignment will be done is Implementation Defined

    // generally compilers will do the assignment by keeping 
    // the lower 16 bits as same as unsigned short assignment

    printf("s = %hd\n", s); 
    // 0xcf34 -> 0b1100111100110100 -> -12492
    // output -> s = -12492  

    // because of short is 4 byte and the most significant bit is 1
    // so the value will be negative
  }
*/

/*
  int main(void){
    int ival = 0x1acf34;  
    unsigned short us = ival;
    short s = ival;
  }

  // compiled with : x86-64 gcc 14.2 -O0 -std=c11
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-4], 1756980    : ival = 0x1acf34
  //    mov eax, DWORD PTR [rbp-4]        : eax = ival
  //    mov WORD PTR [rbp-6], ax          : us = ax
  //    mov eax, DWORD PTR [rbp-4]        : eax = ival
  //    mov WORD PTR [rbp-8], ax          : s = ax
  //    mov eax, 0    
  //    pop rbp
  //    ret

  // eax is 4 byte(DWORD) register, ax is 2 byte(WORD) register
  // those two assignments assembly codes are same
*/

/*
  #include <limits.h>

  int main(void){
    unsigned int x = -1;
    printf("x = %u\n", x);
    printf("Unsigned int max value = %u\n", UINT_MAX);
    // output ->
    //  x = 4294967295
    //  Unsigned int max value = 4294967295
  }
*/

/*
  #include <limits.h>

  int main(void){
    printf("signed int max value   = %d\n", INT_MAX);
    printf("unsigned int max value = %u\n", UINT_MAX);
    // OUTPUT ->
    //  signed int max value   = 2147483647
    //  unsigned int max value = 4294967295

    unsigned int x = 3147483647u; // 2147483647 + 1000000000
    int y = x;  // data loss will be happen (implementation defined)

    unsigned int a = 1147483647u; // 2147483647 - 1000000000
    int b = a;  // NO data loss - int can hold the value
  }
*/

/*
  // implicit conversion from floating type to integral type

  int main(void){
    double dval = 3.14;
    int ival = dval;
    // ival will become 3

    double dval2 = 2837494578592783.2918;
    int ival2 = dval2;
    // assignment will cause undefined behavior(UB)

    // 1. first floating part will be removed
    // 2. if the integral part of floating type is in the range 
    // of the target type it will be assigned to the target type
    // 3. if the integral part of the floating type is not in the range 
    // of the target type, it will be undefined behavior(UB)
  }
*/

/*
  int main(void){
    unsigned short x = 10;
    int y = 20;

    x + y;
    // int can hold unsigned short type's whole range
    // integral promotion will be done from unsigned short to int
    // int + int -> int


    // IN DOS compilers short and int types are 2 byte
    // integral promotion will be done from unsigned short to unsigned int
    // unsigned int + int -> unsigned int
  }
*/

/*
                    ----------------------
                    | type-cast operator |
                    ----------------------
*/

/*
  -> unary right associative operator
  (target_type)expr


  "(double)ival" expressions type is double
  "(double)ival" is an R value expression

  Want (ival1 / ival2) to be done in double type
    (double)ival1 / ival2
    ival1 / (double)ival2
  both will work but generally first one is used
*/

/*
  int main(void){
    int ival = 10;
  
    (double)ival = 3.14; // syntax error
    // error: lvalue required as left operand of assignmen 
  }
*/

/*
  int main(void){
    int x = 10;
    int y = 3;

    double d1 = x / y; 
    double d2 = (double)x / y;
    double d3 = x / (double)y;
    double d4 = (double)(x / y);

    printf("d1 = %f\n", d1); // output -> d1 = 3.000000
    printf("d2 = %f\n", d2); // output -> d2 = 3.333333
    printf("d3 = %f\n", d3); // output -> d3 = 3.333333
    printf("d4 = %f\n", d4); // output -> d4 = 3.000000
  }
*/

/*
  int main(void){
    char c1, c2;

    // getchar() returns an int value
    // c1's type is char

    c1 = getchar();
    // this assignment will cause data loss, 
    // and if that is what we want

    c2 = (char)getchar();
    // better using type-cast operator to make it clear
  }
*/

/*
  double foo(void);

  int main(void){
    float fval;
    fval = (float)foo();
  }
*/

/*
  double foo(void);

  int main(void){
    int x;

    x = (int)foo(); 
    // if integral type of foo's return value is not in the range of int
    // will cause undefined behavior(UB)
  }
*/

/*
  // char  (implementation defined)
  // signed char
  // unsigned char

  int main(void){
    char c = 178;   // 0xb2  0b1011 0010
    // if 0xB2 is assigned to signed char it will be a negative number
    // so when the promotion happens will be sign extended 
    // 0xB2 -> 0xFFFFFFB2

    if (c == 178){
      printf("c is equal to 178\n");
    }
    else{
      printf("c is not equal to 178\n");
    }
    printf("c = %d\n", c);

    // output -> 
    //  c is not equal to 178
    //  c = -78
  }
*/

/*
  int main(void){
    signed char c1 = 0xB2;
    int ival = c1;
  }

  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov BYTE PTR [rbp-1], -78     : c1 = 0xB2
  //    movsx eax, BYTE PTR [rbp-1]   : eax = (int)c1
  //    mov DWORD PTR [rbp-8], eax    : ival = eax
  //    mov eax, 0  
  //    pop rbp
  //    ret

  // MOVSX/MOVSXD — Move With Sign-Extension
  // OPCODE : 0F BE /r  -- INSTRUCTION :MOVSX r32, r/m8
*/