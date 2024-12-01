#include <stdio.h>

/*
              ========================================
              | Bitwise Operations (Bitsel İşlemler) |
              ========================================
*/

/*
            ------------------------------------------
            | bitwise operators (bitsel operatörler) |
            ------------------------------------------
*/

/*
  - bitsel operatörler, operandları olan tamsayıların 
    bitleri üzerinde işlem yaparlar.
  - bitsel operatörlerin hepsi için operandlar tamsayı olmalıdır.
*/

/*
                  operator precedence levels 
              <--- check ../operators/main.c  --->
  ----------------------------------------------------------------
  ----------------------------------------------------------------
  2.  ~       bitwise NOT                     [RIGHT ASSOCIATIVE]
  ----------------------------------------------------------------
  5.  >>      bitwise right shift     
      <<      bitwise left shift
      (bitwise shift operators)               [LEFT ASSOCIATIVE]
  ----------------------------------------------------------------
  8.  &       bitwise AND                     [LEFT ASSOCIATIVE]
  ----------------------------------------------------------------
  9.  ^       bitwise XOR                     [LEFT ASSOCIATIVE]
  ----------------------------------------------------------------
  10. |       bitwise OR                      [LEFT ASSOCIATIVE]
  ----------------------------------------------------------------
  14. &=      assignment by bitwise AND
      ^=      assignment by bitwise XOR       
      |=      assignment by bitwise OR
      >>=     assignment by bitwise left shift 
      <<=     assignment by bitwise right shift 
      (bitwise compound assignment operators)   [RIGHT ASSOCIATIVE]
  ----------------------------------------------------------------
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    print_bits(34);
    // output -> 00000000000000000000000000100010

    print_bits(65535);
    // output -> 00000000000000001111111111111111

    print_bits(4096);
    // output -> 00000000000000000001000000000000
  }
*/

/*
                    ---------------------
                    | bitwise NOT ('~') |
                    ---------------------
*/

/*
  - unary prefix operator
  - operand needs to be an integer
  - right associative
*/

/*
  int main(void)
  {
    char c = 24;

    printf("%zu\n", sizeof(c));   // output -> 1
    printf("%zu\n", sizeof(+c));  // output -> 4
    // "+c" expression's data type is int
    // (char ---> int) integral promotion

    printf("%zu\n", sizeof(~c));   // output -> 4
    // "~c" expression's data type is int
    // (char ---> int) integral promotion
  }
*/

/*
  int main(void)
  {
    int x = 23;

    ~x;
    // "~x" expression did not create any side effect
    // x's value is not changed

    printf("%d\n", x);  // output -> 23
  }
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    unsigned int x = 65535;

    print_bits(x);    // output -> 00000000000000001111111111111111
    print_bits(~x);   // output -> 11111111111111110000000000000000
    print_bits(~~x);  // output -> 00000000000000001111111111111111
    // "~~x" expression is same as "~(~x)" expression

    printf("%u\n", ~x);   // output -> 4294901760
  }
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int x = -1;

    print_bits(x);  // output -> 11111111111111111111111111111111
    print_bits(~x); // output -> 00000000000000000000000000000000

    x = 0;
    print_bits(x);  // output -> 00000000000000000000000000000000
    print_bits(~x); // output -> 11111111111111111111111111111111
  }
*/

/*
                  ---------------------------
                  | bitwise shift operators |
                  ---------------------------
*/

/*
  - binary infix operators
  - shift operation will be done on the left operand
  - both operators does not have any side effect. 
  - integral promotion will be done on the left operand.
*/

/*
                ------------------------------
                |  bitwise left shift ('<<') |
                ------------------------------
*/

/*
  RIGHT OPERAND
    - is negative
    - equal or greater than the number of bits in the left operand
    it will be undefined behavior(UB)

  LEFT OPERAND
  - if left operand is UNSIGNED
    right feed (sağdan yapılan besleme) will be done with 0's.

  - if left operand is SIGNED and POSITIVE
    right feed (sağdan yapılan besleme) will be done with 0's.

  - if left operand is SIGNED and NEGATIVE 
    the result is undefined behaviour(UB)
*/

/*
  // if left operand is signed and negative, 
  // bitshift left operation is undefined behaviour(UB)

  int main(void)
  {
    int x = -3;
    x << 2;   // undefined behaviour(UB)
  }
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int N = 3;
    int x = 65535;

    printf("x = %d\n", x);  // output -> x = 65535

    print_bits(x);        
    // output -> 00000000000000001111111111111111
    print_bits(x << N);   
    // output -> 00000000000001111111111111111000

    printf("x  = %d\n", x); // output -> x = 65535
  } 
*/

/*
  // left shift by 1 means, multiply by 2
  // left shift by 2 means, multiply by 4
  // ...

  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 56;
    printf("x = %d\n", x);  // output -> x = 56

    x <<= 1;  // multiply by 2
    printf("x = %d\n", x);  // output -> x = 112

    x <<= 2;  // multiply by 4
    printf("x = %d\n", x);  // output -> x = 448

    x <<= 3;  // multiply by 8
    printf("x = %d\n", x);  // output -> x = 3584
  } 
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    unsigned int x = 1;

    while(x != 0) {
      print_bits(x);
      x <<= 1;
    };

    // output ->
    //  00000000000000000000000000000001
    //  00000000000000000000000000000010
    //  00000000000000000000000000000100
    //  00000000000000000000000000001000
    //  00000000000000000000000000010000
    //  00000000000000000000000000100000
    //  00000000000000000000000001000000
    //  00000000000000000000000010000000
    //  00000000000000000000000100000000
    //  00000000000000000000001000000000
    //  00000000000000000000010000000000
    //  00000000000000000000100000000000
    //  00000000000000000001000000000000
    //  00000000000000000010000000000000
    //  00000000000000000100000000000000
    //  00000000000000001000000000000000
    //  00000000000000010000000000000000
    //  00000000000000100000000000000000
    //  00000000000001000000000000000000
    //  00000000000010000000000000000000
    //  00000000000100000000000000000000
    //  00000000001000000000000000000000
    //  00000000010000000000000000000000
    //  00000000100000000000000000000000
    //  00000001000000000000000000000000
    //  00000010000000000000000000000000
    //  00000100000000000000000000000000
    //  00001000000000000000000000000000
    //  00010000000000000000000000000000
    //  00100000000000000000000000000000
    //  01000000000000000000000000000000
    //  10000000000000000000000000000000
  }
*/

/*
  // those type of constants(only 1 bit is set) are called 
  // "bitmask" constants

  int main(void)
  {
    int N = 2;
    1u <= N; // (2^2)

    N = 3;
    1u <= N; // (2^3)

    N = 4;
    1u <= N; // (2^4)
  }
*/

/*
                ------------------------------
                | bitwise right shift ('>>') |
                ------------------------------
*/

/*
  RIGHT OPERAND 
    - is negative
    - equal or greater than the number of bits in the left operand
    it will be undefined behavior(UB)

  LEFT OPERAND
  - if left operand is UNSIGNED 
    left feed (sağdan yapılan besleme) will be done with 0's.

  - if left operand is SIGNED and POSITIVE
    left feed (soldan yapılan besleme) will be done with 0's.

  - if left operand is SIGNED and NEGATIVE
    left feed (soldan yapılan besleme) is IMPLEMENTATION DEFINED

    left feed (soldan yapılan besleme) CAN be done with 1's.
    it is called "arithmetic right shift"
    left feed (soldan yapılan besleme) CAN be done with 0's.
    it is called "logical right shift"
*/

/*
  // if left operand is UNSIGNED 
  // left feed will be done with 0's.

  #include "../headers/nutility.h"

  int main(void)
  {
    unsigned int x = ~0u;

    print_bits(x); 
    // output -> 11111111111111111111111111111111

    print_bits(x >> 5);  
    // output -> 00000111111111111111111111111111
  }
*/

/*
  // if left operand is SIGNED and POSITIVE
  // left feed will be done with 0's.

  #include <limits.h>
  #include "../headers/nutility.h"

  int main(void)
  {
    int x = INT_MAX;

    print_bits(x);  
    // output -> 01111111111111111111111111111111

    print_bits(x >> 5);
    // output -> 00000011111111111111111111111111
  }
*/

/*
  // if left operand is SIGNED and NEGATIVE
  // left feed is --- IMPLEMENTATION DEFINED ---

  #include "../headers/nutility.h"

  int main(void)
  {
    int x = -1;

    print_bits(x);
    // output -> 11111111111111111111111111111111

    print_bits(x >> 5);
    // output -> 11111111111111111111111111111111

    // implementation defined
    // gcc compiler is using arithmetic right shift
  }
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int x = -1;

    x >>= 5;

    if (x == -1)
      printf("arithmetic right shift\n");
    else 
      printf("logical right shift\n");
    // output -> arithmetic right shift 
    // implementation defined
  }
*/

/*
  #include <limits.h>
  #include "../headers/nutility.h"

  int main(void)
  {
    unsigned int x = (unsigned)~INT_MAX;

    print_bits(x);
    // output -> 10000000000000000000000000000000

    while (x) {
      print_bits(x);
      x >>= 1;
    }

    // output ->
    //  10000000000000000000000000000000
    //  10000000000000000000000000000000
    //  01000000000000000000000000000000
    //  00100000000000000000000000000000
    //  00010000000000000000000000000000
    //  00001000000000000000000000000000
    //  00000100000000000000000000000000
    //  00000010000000000000000000000000
    //  00000001000000000000000000000000
    //  00000000100000000000000000000000
    //  00000000010000000000000000000000
    //  00000000001000000000000000000000
    //  00000000000100000000000000000000
    //  00000000000010000000000000000000
    //  00000000000001000000000000000000
    //  00000000000000100000000000000000
    //  00000000000000010000000000000000
    //  00000000000000001000000000000000
    //  00000000000000000100000000000000
    //  00000000000000000010000000000000
    //  00000000000000000001000000000000
    //  00000000000000000000100000000000
    //  00000000000000000000010000000000
    //  00000000000000000000001000000000
    //  00000000000000000000000100000000
    //  00000000000000000000000010000000
    //  00000000000000000000000001000000
    //  00000000000000000000000000100000
    //  00000000000000000000000000010000
    //  00000000000000000000000000001000
    //  00000000000000000000000000000100
    //  00000000000000000000000000000010
    //  00000000000000000000000000000001
  }
*/

/*
                ------------------------------
                | bitwise AND ('&') operator |
                ------------------------------
*/

/*
  - binary infix operator
  - 1 etkisiz eleman  (identity element)
  - 0 yutan eleman    (absorbing element)
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 65535, y = 182736432;

    print_bits(x);
    print_bits(y);
    printf("--------------------------------&\n");
    print_bits(x & y);

    // output -> 
    //  00000000000000001111111111111111
    //  00001010111001000101011000110000
    //  --------------------------------&
    //  00000000000000000101011000110000
  }
*/

/*
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 34, y = 98102;

    print_bits(x);
    print_bits(y);
    printf("--------------------------------&\n");
    print_bits(x & y);

    // output -> 
    //  00000000000000000000000000100010
    //  00000000000000010111111100110110
    //  --------------------------------&
    //  00000000000000000000000000100010

    // -------------------------------------------------

    if (x && y)
      printf("Logical AND is true\n");
    else
      printf("Logical AND is false");

    if (x & y)
      printf("Bitwise AND is true\n");
    else
      printf("Bitwise AND is false");

    // output -> Logical AND is true
    // output -> Bitwise AND is true

    // both operations GENERALLY giving the same result,
    // so it is hard to understand when '&&' is used
    // instead of '&', so need to be very careful.

    // -------------------------------------------------
  }
*/

/*
  // when a number is bitwise ANDed with (itself - 1)
  // the result is the number with the rightmost 1 bit cleared.

  // bir sayıyı kendisinin bir eksiği ile 
  // BİTSEL VE işlemine tabi tuttuğumuzda
  // sayının en sağdaki biti sıfırlanır.

  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 254;


    print_bits(x);
    print_bits(x - 1);
    printf("--------------------------------&\n");
    print_bits(x & (x - 1));

    // output ->
    //  00000000000000000000000011111110
    //  00000000000000000000000011111101
    //  --------------------------------&
    //  00000000000000000000000011111100
  }
*/

/*
  // to check if the number is power of 2

  #include "../headers/nutility.h"

  int main(void)
  {
    // ------------------------------------------------------

    int x = 4096;

    if (x != 0 && (x & (x - 1)) == 0)
      printf("x is power of 2\n");
    else
      printf("x is not power of 2\n");

    // output -> x is power of 2

    print_bits(x);
    print_bits(x - 1);
    printf("--------------------------------&\n");
    print_bits(x & (x - 1));

    // output ->
    //  00000000000000000001000000000000
    //  00000000000000000000111111111111
    //  --------------------------------&
    //  00000000000000000000000000000000

    // ------------------------------------------------------

    x = 4097;

    if (x && !(x & (x - 1)))
      printf("x is power of 2\n");
    else
      printf("x is not power of 2\n");
    // output -> x is not power of 2

    print_bits(x);
    print_bits(x - 1);
    printf("--------------------------------&\n");
    print_bits(x & (x - 1));

    // output ->
    //  00000000000000000001000000000001
    //  00000000000000000001000000000000
    //  --------------------------------&
    //  00000000000000000001000000000000

    // ------------------------------------------------------
  }
*/

/*
  // kernighan's algorithm (counting the set bits)

  #include "../headers/nutility.h"

  int set_bit_count(int x)
  {
    int cnt = 0;
    while (x) {
      x &= x - 1;
      ++cnt;
    }
    return cnt;
  }

  int main(void)
  {
    // ------------------------------------------------------

    int x = 4097;
    print_bits(x);  
    // output -> 00000000000000000001000000000001
    printf("set bit count = %d\n", set_bit_count(x));
    // set bit count = 2

    // ------------------------------------------------------

    x = 65535;
    print_bits(x);
    // output -> 00000000000000001111111111111111
    printf("set bit count = %d\n", set_bit_count(x));
    // set bit count = 16

    // ------------------------------------------------------

    x = 16;
    print_bits(x);
    // output -> 00000000000000000000000000010000
    printf("set bit count = %d\n", set_bit_count(x));
    // set bit count = 1

    // ------------------------------------------------------
  }
*/

/*
                -----------------------------
                | bitwise OR ('|') operator |
                -----------------------------
*/

/*
  - binary infix operator
  - 1 yutan eleman    (absorbing element)
  - 0 etkisiz eleman  (identity element)
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 65535, y = 182736432;

    print_bits(x);
    print_bits(y);
    printf("--------------------------------|\n");
    print_bits(x | y);

    // output ->
    //  00000000000000001111111111111111
    //  00001010111001000101011000110000
    //  --------------------------------|
    //  00001010111001001111111111111111
  }
*/

/*
                ------------------------------
                | bitwise XOR ('^') operator |
                ------------------------------
*/

/*
  ----------------------
  |  x  |  y  |  x ^ y |
  ----------------------
  |  0  |  0  |   0    |
  |  0  |  1  |   1    |
  |  1  |  0  |   1    |
  |  1  |  1  |   0    |
  ----------------------
*/

/*
  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 65535, y = 182736432;

    print_bits(x);
    print_bits(y);
    printf("--------------------------------^\n");
    print_bits(x ^ y);

    // output ->
    //  00000000000000001111111111111111
    //  00001010111001000101011000110000
    //  --------------------------------^
    //  00001010111001001010100111001111
  }
*/

/*
  // XOR'ing an integer with itself will result in 0

  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 98102;

    print_bits(x);
    print_bits(x);
    printf("--------------------------------^\n");
    print_bits(x ^ x);

    // output ->
    //  00000000000000010111111100110110
    //  00000000000000010111111100110110
    //  --------------------------------^
    //  00000000000000000000000000000000
  }
*/

/*
  // XOR'ing an integer with the same value twice will result 
  // in the original value

  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 98102;
    int y = 12734;

    // ------------------------------------------------------

    printf("x = %d\n", x);
    printf("x ^= y ---> x = %d\n", x ^= y);
    printf("x ^= y ---> x = %d\n", x ^= y);
    // output ->
    //  x = 98102
    //  x ^= y ---> x = 85640
    //  x ^= y ---> x = 98102

    // ------------------------------------------------------

    print_bits(x);
    print_bits(y);
    printf("--------------------------------^\n");
    print_bits(x ^ y);
    x  ^= y;

    print_bits(y);
    printf("--------------------------------^\n");
    print_bits(x ^ y);
    x ^= y;

  
    // output ->
    //  00000000000000010111111100110110        : x       ---> SAME
    //  00000000000000000011000110111110        : y
    //  --------------------------------^
    //  00000000000000010100111010001000        : x ^= y
    //  00000000000000000011000110111110        : y
    //  --------------------------------^ 
    //  00000000000000010111111100110110        : x ^= y  ---> SAME
  }
*/

/*
  // XOR swap algorithm

  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 65535;
    int y = 20;

    print_bits(x);  
    // output -> 00000000000000001111111111111111
    print_bits(y);
    // output -> 00000000000000000000000000010100

    x ^= y, y ^= x, x ^= y;

    printf("x = %d\n", x);  // output -> x = 20
    printf("y = %d\n", y);  // output -> y = 65535
  }
*/

/*
  int main(void)
  {
    int a = 67;
    int b = 23;

    int x = a;  
    printf("x = %d\n", x);  // output -> x = 67

    x = a ^ b ^ x;
    printf("x = %d\n", x);  // output -> x = 23

    x = a ^ b ^ x;
    printf("x = %d\n", x);  // output -> x = 67
  }
*/

/*
  01010011
  10111000
  --------^
  11101011

  - 1 is flipping (toggling) the bit of the first operand
  - 0 is not changing the bit of the first operand
*/

/*
  Tip : iki adet varsa birbirini sıfırlar.

  --------------------------------
  A ^ A == AA --> 0
  --------------------------------
  A ^ B  = AB 
  AB ^ B = ABB --> A
  --------------------------------
  x ^= y, y ^= x, x ^= y;

  X = X ^ Y = XY          (X = XY)
  Y = Y ^ XY = YXY --> X  (Y = X)
  X = XY ^ X = XYX --> Y  (X = Y)
  --------------------------------
*/

/*
                  -------------------------
                  | bitwise manipulations |
                  -------------------------
*/

/*
  1. to set(turn-on) an individual bit 
     belirli bir biti set etmek  

  2. to clear(reset)(turn-off) an individual bit 
     belirli bir biti sıfırlamak

  3. to flip (toggle) an individual bit 
     belirli bir biti tersine çevirmek

  4. to get an individual bit
     belirli bir bitin değerini sorgulamak
*/

/*
  // to set an individual bit

  #include "../headers/nutility.h"

  int main(void)
  {
    int x = 0;

    int N = 5;
    print_bits(x | (1 << N));  
    // output -> 00000000000000000000000000100000

    N = 12;
    print_bits(x | (1 << N));
    // output -> 00000000000000010000000000000000

    N = 31;
    print_bits(x | (1 << N));
    // output -> 10000000000000000000000000000000

    N = 0;
    print_bits(x | (1 << N));
    // output -> 00000000000000000000000000000001
  }
*/

/*
  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <stdlib.h> // rand

  int main(void)
  {
    int x = 0;

    randomize();

    size_t counter = 0;

    do {
      x |= 1 << rand() % 32;

      ++counter;
      if (counter %10 == 0)
        print_bits(x);
    } while (x != -1);

    // output ->
    //  10010010000100010100000001000010    : 10
    //  10011011011100010101010101000010    : 20
    //  10011111011100010101010101110011    : 30
    //  10011111011101011111010111110111    : 40
    //  10111111111101011111011111110111    : 50
    //  10111111111101011111011111110111    : 60
    //  11111111111101111111111111110111    : 70
    //  11111111111111111111111111110111    : 80 

    printf("all bits are set after %zu iterations\n", counter);
    // output -> all bits are set after 82 iterations
    print_bits(x);  // output -> 11111111111111111111111111111111
  }
*/

/*
  // to clear an individual bit 

  #include "../headers/nutility.h"

  int main(void)
  {
    int x = -1;

    int N = 5;
    print_bits(x & ~(1 << N));
    // output -> 11111111111111111111111111011111

    N = 12;
    print_bits(x & ~(1 << N));
    // output -> 11111111111111111110111111111111

    N = 31;
    print_bits(x & ~(1 << N));
    // output -> 01111111111111111111111111111111

    N = 0;
    print_bits(x & ~(1 << N));
    // output -> 11111111111111111111111111111110
  }
*/

/*
  #include "../headers/nutility.h"
  #include <stddef.h> // size_t
  #include <stdlib.h> // rand

  int main(void)
  {
    int x = -1;

    randomize();

    size_t counter = 0;

    do {
      x &= ~(1 << (rand() % 32));

      ++counter;
      if (counter %10 == 0){
        print_bits(x);
      }
    } while (x);

    // output ->
    //  11111011101101111011110101111001  : 10
    //  10101011101001111010110001111000  : 20
    //  00101000001001111010100001111000  : 30
    //  00101000001000111010100000011000  : 40   
    //  00101000001000101010100000001000  : 50
    //  00100000001000100010100000000000  : 60
    //  00000000001000100000100000000000  : 70
    //  00000000000000100000000000000000  : 80
    //  00000000000000100000000000000000  : 90
    //  00000000000000100000000000000000  : 100

    printf("all bits are cleared after %zu iterations\n", counter);
    // output -> all bits are set after 104 iterations
    print_bits(x);  // output -> 00000000000000000000000000000000
  }
*/

/*
  // to flip an individual bit

  #include "../headers/nutility.h"

  int main(void)
  {
    // -------------------------------------------------

    int x = 0;

    int N = 5;
    print_bits(x ^ (1 << N));
    // output -> 00000000000000000000000000100000

    N = 12;
    print_bits(x ^ (1 << N));
    // output -> 00000000000000000001000000000000

    N = 31;
    print_bits(x ^ (1 << N));
    // output -> 10000000000000000000000000000000

    N = 0;
    print_bits(x ^ (1 << N));
    // output -> 00000000000000000000000000000001 

    // -------------------------------------------------

    x = -1;

    N = 5;
    print_bits(x ^ (1 << N));
    // output -> 11111111111111111111111111011111

    N = 12;
    print_bits(x ^ (1 << N));
    // output -> 11111111111111111110111111111111

    N = 31;
    print_bits(x ^ (1 << N));
    // output -> 01111111111111111111111111111111

    N = 0;
    print_bits(x ^ (1 << N));
    // output -> 11111111111111111111111111111110

    // -------------------------------------------------
  }
*/

/*
  // to get an individual bit

  #include "../headers/nutility.h"
  #include <limits.h>

  int main(void)
  {
    int x = INT_MAX;
    print_bits(x);  // output -> 01111111111111111111111111111111

    // -------------------------------------------------

    int N = 5;

    if (x & (1 << N))
      printf("bit %d is set\n", N);
    else
      printf("bit %d is not set\n", N);
    // output -> bit 5 is set

    // -------------------------------------------------

    N = 31;

    if (x & (1 << N))
      printf("bit %d is set\n", N);
    else
      printf("bit %d is not set\n", N);
    // output -> bit 31 is not set

    // -------------------------------------------------

    x = 65535;
    print_bits(x);  
    // output -> 00000000000000001111111111111111

    for (int i = 0; i < 32; ++i) 
      printf("bit %d is %d\n", i, (x & (1 << i)) >> i);
    
    // output ->
    //  bit 0 is 1
    //  bit 1 is 1
    //  bit 2 is 1
    //  bit 3 is 1
    //  bit 4 is 1
    //  bit 5 is 1
    //  bit 6 is 1
    //  bit 7 is 1
    //  bit 8 is 1
    //  bit 9 is 1
    //  bit 10 is 1
    //  bit 11 is 1
    //  bit 12 is 1
    //  bit 13 is 1
    //  bit 14 is 1
    //  bit 15 is 1
    //  bit 16 is 0
    //  bit 17 is 0
    //  bit 18 is 0
    //  bit 19 is 0
    //  bit 20 is 0
    //  bit 21 is 0
    //  bit 22 is 0
    //  bit 23 is 0
    //  bit 24 is 0
    //  bit 25 is 0
    //  bit 26 is 0
    //  bit 27 is 0
    //  bit 28 is 0
    //  bit 29 is 0
    //  bit 30 is 0
    //  bit 31 is 0

    // -------------------------------------------------
  }
*/

/*
  int main(void)
  {
    int x = 82373;

    if (x & 1)
      printf("x is odd\n");
    else
      printf("x is even\n");
    // output -> x is odd
  }
*/

/*
  #include <limits.h>

  static void print_bits_2(unsigned int val)
  {
    for (int i = sizeof(int) * CHAR_BIT - 1; i >= 0; --i)
      putchar( ((val >> i) & 1) ? '1' : '0');
    putchar('\n');
  }

  int main(void)
  {
    print_bits_2(65535);
    // output -> 00000000000000001111111111111111

    print_bits_2(4096);
    // output -> 00000000000000000001000000000000

    print_bits_2(INT_MAX);
    // output -> 01111111111111111111111111111111

    print_bits_2(~0);
    // output -> 11111111111111111111111111111111
  }
*/

/*
  // bitwise manipulation over more than one bit

  #include "../headers/nutility.h"

  #define   MASK1    0x20   // 32
  #define   MASK2    0x10   // 16
  #define   MASK3    0x02   // 2

  int main(void)
  {
    int x = -1;

    print_bits(x);  
    // output ->11111111111111111111111111111111

    print_bits(x & MASK1);  
    // output -> 00000000000000000000000000100000

    print_bits(x & (MASK1 | MASK2));
    // output -> 00000000000000000000000000110000

    print_bits(x & (MASK1 | MASK2 | MASK3));
    // output -> 00000000000000000000000000110010
  }
*/

/*
  int set_bit_count(int x)
  {
    int cnt = 0;

    while (x){
      x &= x - 1;
      ++cnt;
    }

    return cnt;
  }

  int main(void)
  {
    for (int i = 0; i < 256; ++i)
    {
      if (i && i % 16 == 0)
        printf("\n");
      printf("%d, ", set_bit_count(i));
    }
  }

  // output ->
  //  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
  //  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  //  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  //  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  //  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  //  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  //  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  //  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  //  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  //  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  //  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  //  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  //  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  //  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  //  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  //  4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
*/

/*
  // using lookup table to get the number of set bits

  #include <limits.h>
  #include "../headers/nutility.h"

  // bit count lookup table
  const int arr [] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
  };

  int main(void)
  {
    // -------------------------------------------------

    // arr[x & 255] -> bit count of the lowest 8 bits
    // arr[(x >> 8) & 255] -> bit count of the next 8-16 bits
    // arr[(x >> 16) & 255] -> bit count of the next 16-24 bits
    // arr[(x >> 24) & 255] -> bit count of the highest 8 bits

    // -------------------------------------------------

    int x = INT_MAX;
    print_bits(x);  // output -> 01111111111111111111111111111111


  printf("total bit count = %d\n",
      arr[x & 255] + arr[(x >> 8) & 255] + 
        arr[(x >> 16) & 255] + arr[(x >> 24) & 255]);
    // output -> total bit count = 31

    // -------------------------------------------------

    x = 65535;  
    print_bits(x);  // output -> 00000000000000001111111111111111

    printf("total bit count = %d\n",
      arr[x & 255] + arr[(x >> 8) & 255] + 
        arr[(x >> 16) & 255] + arr[(x >> 24) & 255]);
    // output -> total bit count = 16

    // -------------------------------------------------
  }
*/

/*
  #include "../headers/nutility.h"
  #include <limits.h>

  #define BITCOUNT(x)                                \
              ( set_bit_arr[(x) & 255]          +    \
                set_bit_arr[((x) >> 8) & 255]   +    \
                set_bit_arr[((x) >> 16) & 255]  +    \
                set_bit_arr[((x) >> 24) & 255] )             

  int main(void)
  {
    // -------------------------------------------------

    int x = INT_MAX;
    print_bits(x);
    // output -> 01111111111111111111111111111111

    printf("total bit count = %d\n", BITCOUNT(x));
    // output -> total bit count = 31

    // -------------------------------------------------

    x = 65535;
    print_bits(x);
    // output -> 00000000000000001111111111111111

    printf("total bit count = %d\n", BITCOUNT(x));
    // output -> total bit count = 16

    // -------------------------------------------------

    x = 255;
    print_bits(x);
    // output -> 00000000000000000000000011111111

    printf("total bit count = %d\n", BITCOUNT(x));
    // output -> total bit count = 8

    // -------------------------------------------------

    x = 0;
    print_bits(x);
    // output -> 00000000000000000000000000000000

    printf("total bit count = %d\n", BITCOUNT(x));
    // output -> total bit count = 0

    // -------------------------------------------------

    x = -1;
    print_bits(x);
    // output -> 11111111111111111111111111111111

    printf("total bit count = %d\n", BITCOUNT(x));
    // output -> total bit count = 32

    // -------------------------------------------------
  }
*/

/*
  bit vector : 
    bir tam sayının bitlerinin boolean değerler olarak kullanılması.

  8 bit -> 8 boolean değer
*/

/*
  #define   READ_ONLY     0x01
  #define   ARCHIVE       0x02
  #define   SYSTEM        0x04
  #define   HIDDEN        0x08
  #define   DIRECTORY     0x10

  typedef struct {
    char m_file_name[32];
    size_t m_len;
    unsigned m_file_flags;
  } File_Info_t;

  int main(void)
  {
    File_Info_t fi;

    // -------------------------------------------------

    // to check if the file is hidden or not
    if (fi.m_file_flags & HIDDEN)
      printf("file is hidden\n");
    else
      printf("file is not hidden\n");

    // -------------------------------------------------

    // to set the file to read-only
    fi.m_file_flags |= READ_ONLY;

    // -------------------------------------------------

    // to clear the read-only flag
    fi.m_file_flags &= ~READ_ONLY;

    // -------------------------------------------------

    // to change the read-only flag
    fi.m_file_flags ^= READ_ONLY;

    // -------------------------------------------------

    // to make the file hidden, read-only and system
    fi.m_file_flags |= (READ_ONLY | HIDDEN | SYSTEM);

    // -------------------------------------------------
  }
*/

/*
  // HOMEWORK : 
  //  all elements have a pair except one element
  //  return the element that has no pair

  #include "../headers/nutility.h"

  int main(void)
  {
    int arr[] = { 1, 2, 1, 2, 3, 4, 3, 4, 5, 6, 7, 6, 7 };

    int x = -1;
    int temp = x;

    for (size_t i = 0; i < asize(arr); ++i)
      x ^= arr[i];
    
    printf("the element that has no pair is %d\n", x ^ temp);
  }
*/

/*
  void foo(int x, int y, int is_a, int is_b, int is_c, int is_d);
  void better_foo(int x, int y, int is_flags);
*/

/*
  #include <ctype.h>
  #include "ctype_impl.h"

  int main(void)
  {
    // creating a lookup table
    int flag = 0;

    for (int i = 0; i < 128; ++i)
    {
      flag = 0;
      if (i && i % 8 == 0)
        printf("\n");

      if (isupper(i)) flag |= UPPER;
      if (islower(i)) flag |= LOWER;
      if (isdigit(i)) flag |= DIGIT;
      if (isxdigit(i)) flag |= XDIGIT;
      if (ispunct(i)) flag |= PUNCT;
      if (isspace(i)) flag |= SPACE;
      if (isprint(i)) flag |= PRINT;
      if (iscntrl(i)) flag |= CNTRL;
      printf("%3d, ", flag);
    }
  }
*/

/*
  #include "ctype_impl.h"

  int main()
  {
    // ------------------------------------------------------

    int ch = 65;
    if (ISUPPER(ch))
      printf("%c is an uppercase letter\n", ch);
    else
      printf("%c is not an uppercase letter\n", ch);
    // output -> A is an uppercase letter

    // ------------------------------------------------------

    ch = 97;
    if (ISDIGIT(ch))
      printf("%c is a digit\n", ch);
    else
      printf("%c is not a digit\n", ch);
    // output -> a is not a digit

    // ------------------------------------------------------

    ch = 70;
    if (ISXDIGIT(ch))
      printf("%c is an hex digit\n", ch);
    else
      printf("%c is not an hex digit\n", ch);
    // output -> F is an hex digit

    // ------------------------------------------------------

    ch = 41;
    if (ISPUNCT(ch))
      printf("%c is a punctuation character\n", ch);
    else
      printf("%c is not a punctuation character\n", ch);
    // output -> ) is a punctuation character

    // ------------------------------------------------------
  }
*/

/*
                        -------------
                        | bitfields |
                        -------------
*/

/*
  - bir tamsayı değişkenin belirli sayıda bitten oluşan 
    kısmını sanki bir tam sayı değişkenmiş gibi kullanmak
    için kullanılan bir özelliktir.

  - değişkenlere hızlı erişim sağlar.
  - bellek tasarrufu sağlar.
*/

/*
  uint16_t x;

  a, b, c, d, e are representing 5 different fields

  x : edddddcccbbbbaaa

  ------------------------------------------------------

  to get the value of the field b (reading)

  x             : edddddcccbbbbaaa
  x >>= 3       : 000edddddcccbbbb
  x &= 15       : 000000000000bbbb

  ------------------------------------------------------

  to set the value of the field b (writing)
  int val;

  x               : edddddcccbbbbaaa
  x &= ~(15 << 3) : edddddccc0000aaa
  x |= (val << 3) : edddddccc____aaa

  ------------------------------------------------------
*/

/*
  if a structure members will be used as a bitfield, 
  the type of the members must be from the following list
    - int
    - signed int
    - unsigned int
    - _Bool

  - `int` and `signed int` are DIFFERENT in bitfields.
*/

/*
  int N = 5;
  const int CN = 10;

  struct Data {
    unsigned int mb_a : 2;   
    // mb_a is a bitfield member of Data structure holds 2 bits

    unsigned int mb_b : N;   // syntax error
    // error: bit-field 'mb_b' width not an integer constant
    // must be a constant expression

    unsigned int mb_c : CN;  // syntax error
    // error: bit-field 'mb_c' width not an integer constant
    // must be a constant expression
  };
*/

/*
  struct Data {
    unsigned int mb_x  : 4;     // [0, 15]
    signed int mb_y    : 4;     // [-8, 7]
    int mb_z           : 4;     // implementation defined
    // (signed or unsigned)  [-8, 7] or [0, 15]
  };
*/

/*
  struct Data {
    _Bool mb_a : 1;  
    // _Bool type bitfield member must be 1 bit
  };
*/

/*
  struct Data {
    int m_x, m_y;   // non-bitfield member 
    int mb_z : 4;   // bitfield member
  };
  // generally in production codes, 
  // whole members are bitfield or non-bitfield members
*/

/*
  typedef struct Data {
    unsigned int mb_a : 6;    // [0, 63]
    unsigned int mb_b : 6;    // [0, 63]
    unsigned int mb_c : 6;    // [0, 63]
  } Data_t;

  int main(void)
  {
    Data_t d1 = { 11, 22, 33 };
    Data_t d2 = { .mb_a = 33, .mb_b = 44, .mb_c = 55 };

    Data_t* p_d = &d1;

    d1.mb_a = 44;
    p_d->mb_b = 55;
  }
*/

/*
  - storage(allocation) unit
    generally its sizeof is an `int` type's sizeof
    
    if storage unit is 32 bit, bitfield members must be 
    less than 32 bits.
*/

/*
  struct Data {
    unsigned int mb_a : 32; // VALID
    unsigned int mb_b : 33; // syntax error
    // error: width of 'mb_b' exceeds its type
  };
*/

/*
  // size of the structure type will be multiples 
  // of storage(allocation) unit size.

  typedef struct {
    unsigned int mb_a : 2;
    unsigned int mb_b : 1;
    unsigned int mb_c : 4;
  } Data_t;

  typedef struct {
    unsigned int mb_a : 7;
    unsigned int mb_b : 7;
    unsigned int mb_c : 7;
    unsigned int mb_d : 7;
    unsigned int mb_e : 4;
  } Data2_t;

  typedef struct {
    unsigned int mb_a : 7;
    unsigned int mb_b : 7;
    unsigned int mb_c : 7;
    unsigned int mb_d : 7;
    unsigned int mb_e : 7;
  } Data3_t;


  int main(void)
  {
    // ------------------------------------------------------

    // 2 + 1 + 4 = 7 bits
    // 7 bits < 32 bits(4 bytes)

    printf("sizeof(Data_t) = %zu\n", sizeof(Data_t));
    // output -> sizeof(Data_t) = 4

    // ------------------------------------------------------

    // 7 + 7 + 7 + 7 + 4 = 32 bits
    // 32 bits == 32 bits(4 bytes)

    printf("sizeof(Data2_t) = %zu\n", sizeof(Data2_t));
    // output -> sizeof(Data2_t) = 4

    // ------------------------------------------------------

    // 7 + 7 + 7 + 7 + 7 = 35 bits
    // 35 bits > 32 bits(4 bytes)

    printf("sizeof(Data3_t) = %zu\n", sizeof(Data3_t));
    // output -> sizeof(Data3_t) = 8

    // ------------------------------------------------------
  }
*/

/*
  typedef struct {
    unsigned int mb_a : 4;    // [0, 15]
    unsigned int mb_b : 3;    // [0, 7]
  } Data_t;

  int main(void)
  {
    Data_t d1;

    d1.mb_a = 17;  
    // mb_a bitfield member can not hold 17 which is out of range
    // because of type is `unsigned int` it WILL NOT be UB

    // 1111 + 0001 = 0000 (15 + 1 = 16)
    // 0000 + 0001 = 0001 (16 + 1 = 17)

    printf("d1.mb_a = %u\n", d1.mb_a);
    // output -> d1.mb_a = 1
  }
*/

/*
  typedef struct {
    unsigned int mb_a : 4;
    unsigned int mb_b : 3;
  } Data_t;

  // where mb_a bitfield member will be stored 
  // inside that storage(allocation) unit
  // is dependent on the compiler. (implementation defined)

  int main(void)
  {
    Data_t d1;

    printf("sizeof(Data_t) = %zu\n", sizeof(Data_t));
    // output -> sizeof(Data_t) = 4

    d1.mb_a = 15;

    // SCENARIO 1
    // 1111 0000
    // 0000 0000
    // 0000 0000
    // 0000 0000

    // SCENARIO 2
    // 0000 1111
    // 0000 0000
    // 0000 0000
    // 0000 0000

    // SCENARIO 3
    // 0000 0000
    // 0000 0000
    // 0000 0000
    // 0000 1111

    // SCENARIO 4
    // 0000 0000
    // 0000 0000
    // 0000 0000
    // 1111 0000

    // can be each of the above scenarios
    // so portability is a problem when bitfield members are used.
  }
*/

/*
  typedef struct {
    unsigned int mb_a : 4;
    unsigned int mb_b : 5;
  } Data_t;

  // think about a scenario that mb_a bits 
  // will be stored like below in the storage unit
  // (implementation defined)

  // aaaa 0000
  // 0000 0000
  // 0000 0000
  // 0000 0000

  // in this situation, mb_b bits will be store like below

  // aaaa bbbb    -> 1 byte
  // b000 0000    -> 1 byte
  // 0000 0000
  // 0000 0000

  // for compiler to read `mb_a` bits, it should read 1 byte
  // for compiler to read `mb_b` bits, it should read 2 byte
  // for 5 bits, reading 2 byte will increase the cost.


  typedef struct {
    unsigned int mb_a : 4;
    unsigned int      : 4;    // 4 padding bits
    unsigned int mb_b : 5;
  } Data2_t;

  // when Data2_t is used, mb_a and mb_b bits will be stored 
  // in different bytes like below 

  // aaaa 0000
  // bbbb b000
  // 0000 0000
  // 0000 0000
*/

/*
  typedef struct {
    unsigned int mb_a : 4;
    unsigned int mb_b : 5;
  } Data_t;

  typedef struct {
    unsigned int mb_a : 4;
    unsigned int      : 0;
    unsigned int mb_b : 5;
  } Data2_t;

  // mb_a and m_b will be stored in different allocation units.

  int main(void)
  {
    printf("sizeof(Data_t) = %zu\n", sizeof(Data_t));
    // output -> sizeof(Data_t) = 4

    printf("sizeof(Data2_t) = %zu\n", sizeof(Data2_t));
    // output -> sizeof(Data2_t) = 8
  }
*/

/*
  // examples from DOS operating system(16 bit)
  // allocation unit is 16 bit

  // ------------------------------------------------------

  struct DOS_Date {
    unsigned int mb_day   : 5;  // [0, 31]
    unsigned int mb_mon   : 4;  // [0, 15]
    unsigned int mb_year  : 7;  // [0, 127]
  };

  // mb_year will store 1980 + year -> [1980, 2107]

  // ------------------------------------------------------

  struct DOS_Time {
    unsigned int mb_hour  : 5;    // [0, 31]
    unsigned int mb_min   : 6;    // [0, 63]
    unsigned int mb_sec   : 5;    // [0, 31]
  };

    // mb_sec will store 2 * sec -> [0, 58]

  // ------------------------------------------------------
*/

/*
  struct Question {
    unsigned int mb_option  : 3;  // [0, 7]  --> (A, B, C, D, E)
    unsigned int mb_correct : 1;  // [0, 1]  --> (false, true)
  };

  // holding 1 question in 4 bits.
*/

/*
  typedef struct {
    unsigned int mb_day   : 5;  // [0, 31]
    unsigned int mb_mon   : 4;  // [0, 15]
    unsigned int mb_year  : 7;  // [0, 127]
    unsigned int mb_hour  : 5;  // [0, 31]
    unsigned int mb_min   : 6;  // [0, 63]
    unsigned int mb_sec   : 5;  // [0, 31]
  } DateTime_t;

  void print_datetime(const DateTime_t* p_dt)
  {
    printf("%02u/%02u/%04u %02u:%02u:%02u\n",
      p_dt->mb_day, 
      p_dt->mb_mon, 
      p_dt->mb_year + 1980,
      p_dt->mb_hour, 
      p_dt->mb_min, 
      p_dt->mb_sec * 2);
  }

  int main(void)
  {
    printf("sizeof(DateTime_t) = %zu\n", sizeof(DateTime_t));
    // output -> sizeof(DateTime_t) = 4

    // 5 + 4 + 7 + 5 + 6 + 5 = 32 bits

    DateTime_t dt = { 30, 11, 2024 - 1980, 00, 14, 20 };
    print_datetime(&dt);
    // output -> 30/11/2024 00:14:40
  }
*/

/*
  #include <stdint.h> // uint32_t

  typedef union {
    struct {
      unsigned int mb_day   : 5;  // [0, 31]
      unsigned int mb_mon   : 4;  // [0, 15]
      unsigned int mb_year  : 7;  // [0, 127]
      unsigned int mb_hour  : 5;  // [0, 31]
      unsigned int mb_min   : 6;  // [0, 63]
      unsigned int mb_sec   : 5;  // [0, 31]
    };
    uint32_t m_value;

  } DateTime_t;

  void print_datetime(const DateTime_t* p_dt)
  {
    printf("%02u/%02u/%04u %02u:%02u:%02u\n",
      p_dt->mb_day, 
      p_dt->mb_mon, 
      p_dt->mb_year + 1980,
      p_dt->mb_hour, 
      p_dt->mb_min, 
      p_dt->mb_sec * 2);
  }

  int main(void)
  {
    printf("sizeof(DateTime_t) = %zu\n", sizeof(DateTime_t));
    // output -> sizeof(DateTime_t) = 4

    DateTime_t dt = { {30, 11, 2024 - 1980, 00, 14, 20} };

    // ------------------------------------------------------

    print_datetime(&dt);
    // output -> 30/11/2024 00:14:40
    printf("%u\n", dt.m_value); // output -> 2713737598

    // ------------------------------------------------------

    dt.m_value = 2713738293;
    print_datetime(&dt);
    // output -> 21/01/2026 00:14:40

    // ------------------------------------------------------

    dt.m_value = 2713737598;
    print_datetime(&dt);
    // output -> 30/11/2024 00:14:40

    // ------------------------------------------------------
  }
*/

/*
  #include <stdint.h> // uint32_t

  typedef union {
    struct {
      unsigned int mb_bit0   : 1;
      unsigned int mb_bit1   : 1;
      unsigned int mb_bit2   : 1;
      unsigned int mb_bit3   : 1;
      unsigned int mb_bit4   : 1;
      unsigned int mb_bit5   : 1;
      unsigned int mb_bit6   : 1;
      unsigned int mb_bit7   : 1;
      unsigned int mb_bit8   : 1;
      unsigned int mb_bit9   : 1;
      unsigned int mb_bit10  : 1;
      unsigned int mb_bit11  : 1;
      unsigned int mb_bit12  : 1;
      unsigned int mb_bit13  : 1;
      unsigned int mb_bit14  : 1;
      unsigned int mb_bit15  : 1;
      unsigned int mb_bit16  : 1;
      unsigned int mb_bit17  : 1;
      unsigned int mb_bit18  : 1;
      unsigned int mb_bit19  : 1;
      unsigned int mb_bit20  : 1;
      unsigned int mb_bit21  : 1;
      unsigned int mb_bit22  : 1;
      unsigned int mb_bit23  : 1;
      unsigned int mb_bit24  : 1;
      unsigned int mb_bit25  : 1;
      unsigned int mb_bit26  : 1;
      unsigned int mb_bit27  : 1;
      unsigned int mb_bit28  : 1;
      unsigned int mb_bit29  : 1;
      unsigned int mb_bit30  : 1;
      unsigned int mb_bit31  : 1;
    };
    uint32_t m_value;
  } Bits_t;

  int main(void)
  {
    Bits_t b1 = { .m_value = 0 };

    // ------------------------------------------------------

    b1.mb_bit4 = 1;
    printf("%u\n", b1.m_value); // output -> 16

    // ------------------------------------------------------

    b1.m_value = 15;
    printf("%u\n", b1.mb_bit0); // output -> 1
    printf("%u\n", b1.mb_bit1); // output -> 1
    printf("%u\n", b1.mb_bit2); // output -> 1
    printf("%u\n", b1.mb_bit3); // output -> 1
    printf("%u\n", b1.mb_bit4); // output -> 0

    // ------------------------------------------------------
  }
*/