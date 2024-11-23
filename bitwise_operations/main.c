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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
    ------------------------------------------------------------
    | bitwise right shift ('>>') AND bitwise left shift ('<<') |
    ------------------------------------------------------------
*/

/*
  - binary infix operators
  - shift operation will be done on the left operand
  - both operators does not have any side effect. 
*/