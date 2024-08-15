#include <stdio.h>

/*
                  ----------------------------------
                  | operators (operatörler, işleç) |
                  ----------------------------------
*/

/*
  a + b -> a and b expressions are operands of "+" operator
  !x    -> x expression is operand of "!" operator


  unary operator  (have 1 operand)
  binary operator (have 2 operands)
  The ternary operator  (koşul operatörü)
    a > b ? a : b   -> "?" and ":" are tokens of ternary operator


  a + b -> binary (infix) operator
  !x    -> unary (prefix) operator
  y++   -> unary (postfix) operator


  operator return, generates a value
  10 + 20 -> addition operator generates 30
  a > b (generates signed int 1 or 0)
  In C language, every operator generates a value

  
  --> constraints
    - can be related with operand(s) types 
    - can be related wit operand(s) value categories (L, R value)
*/

/*
  // modulus operators constraint related with its operands types 
  int main(void){
    double d1 = 282.1827;
    double d2 = 19.234;

    d1 % d2;  // syntax error 
    // invalid operands to binary % (have 'double' and 'double')
  }
*/

/*
  // assignment operators constraint related with its operands
  // value category 
  int main(void){
    int x =  56;

    45 = x; // syntax error
    // lvalue required as left operand of assignment
  }
*/

/*
        -----------------------------------------------------
        | operator priority, precedence (operatör önceliği) |
        -----------------------------------------------------
*/

/*

  ----------------------------------------------------------------
  |                     OPERATOR PRIORITY LIST                   |
  ----------------------------------------------------------------
  1.  ()      function call operator
      []      subscript operator
      .       dot operator    (member-selection operators)
      ->      arrow operator  (member-selection operators)      
  ----------------------------------------------------------------
  2.  !       logical NOT
      ~       bitwise NOT
      +       sign operator (plus)
      -       sign operator (minus)
      ++      increment operator              [RIGHT ASSOCIATIVE]
      --      decrement operator
      &       address-of operator
      *       dereferencing operator
      sizeof  sizeof operator
      (type)  type-cast operator
  ----------------------------------------------------------------
  3.  *       multplication operator
      /       division operator
      %       modulus operator
  ----------------------------------------------------------------
  4.  +       addition operator
      -       substraction operator
  ----------------------------------------------------------------
  5.  >>      bitwise right shift
      <<      bitwise left shift
  ----------------------------------------------------------------
  6.  >       greater than
      >=      greater or equal
      <       less than
      <=      less or equal     (relational / comparison operators)
  ----------------------------------------------------------------
  7.  ==      equal to 
      !=      not equal         (comparison operators)
  ----------------------------------------------------------------
  8.  &       bitwise AND
  ----------------------------------------------------------------
  9.  ^       bitwise XOR
  ----------------------------------------------------------------
  10. |       bitwise OR
  ----------------------------------------------------------------
  11. &&      logical AND
  ----------------------------------------------------------------
  12. ||      logical OR
  ----------------------------------------------------------------
  13. ? :     ternary operator                  [RIGHT ASSOCIATIVE]
  ----------------------------------------------------------------
  14. =       assignment operator
      +=      assignment by sum
      -=      assignment by difference
      *=      assignment by product
      /=      assignment by quotient
      %=      assignment by remainder           [RIGHT ASSOCIATIVE]
      &=      assignment by bitwise AND
      ^=      assignment by bitwise XOR
      |=      assignment by bitwise OR
      >>=     assignment by bitwise left shift 
      <<=     assignment by bitwise right shift 
  ----------------------------------------------------------------
  15. ,       comma operator
  ----------------------------------------------------------------
*/

/*
                -----------------------------------------
                | operator associativity (öncelik yönü) |
                -----------------------------------------
*/

/*
  -> 2, 13, 14 in the operator priority list are right associative
  -> Others are left associative

  ~!x++     ->  (~(!(x++)))

  ++  -> 2. 
  !   -> 2.
  ~   -> 2.
  all operators have the same priority and they are right associative

  x & y & z & t -> (((x & y) & z) & t)
  & operator is in 8th in priority list and it is left associative
*/

/*
                    ------------------------
                    | arithmetic operators |
                    ------------------------
                      + - ++ -- * / % + -
*/

/*
  // + and - operators (addition, substraction) [additive operators]
  #include <limits.h>

  int main(void){
    int x = 2000000000; // 2'000'000'000
    int y = 2000000000; // 2'000'000'000
    printf("%d + %d = %d\n", x, y, x + y);  // Undefined Behaviour(ub)


    unsigned int a = 3000000000; // 3'000'000'000
    unsigned int b = 3000000000; // 3'000'000'000
    printf("%u + %u = %u\n", a, b, a + b);  
    // output -> 3000000000 + 3000000000 = 1'705'032'704
    // overflow happened but code is VALID

    printf("%u", (6000000000 % UINT_MAX) - 1); 
    // output -> 1'705'032'704

    // ! WARNING !
    // In SIGNED integer types, overflow happening when addition 
    // and substraction IS Undefined Behaviour(UB)

    // In UNSIGNED integer types overflow happening when addition 
    // and substraction IS NOT Undefined Behaviour(UB)

    // x + y  -> R value expression
    // x - y  -> R value expression
  }
*/

/*
  // sign operators
  int main(void){

    // +x   -> R value expression
    // -x   -> R value expression

    int x = 10;
    +x = 20; // syntax error
    // lvalue required as left operand of assignment


    int y = 15;
    printf("y = %d", y);  // output -> y = 15
    y = -y;
    printf("y = %d", y);  // output -> y = -15


    char c = 12;
    +c; // this expressions type is int not char -> integral promotion
  }
*/

/*
  multiplicative operators (left associative)
   * multiplication
   / division
   % modulus

  x * y    -> R value expression
  x / y    -> R value expression
  x % y    -> R value expression

  5 / 2   expressions type is int and value is 2
  7 / 10  expressions type is int and value is 0

  x / y -> for integral types undefined behaviour(UB) when y = 0
  
  x % y -> modulus operator's operands must be integral types

  ! WARNING !
    In SIGNED integer types, overflow happening when multiplication 
    IS Undefined Behaviour(UB)
*/

/*
  int main(void){
    int hour, n;

    printf("what time is it now : ");
    scanf("%d", &hour);
    printf("how many hours later : ");
    scanf("%d", &n);
    printf("now time is %d and %d hours later, time will be %d\n",
    hour, n, (hour + n) % 24);
  }
*/

/*
  int main(void){
    int x = 8723;

    printf("binler basamagi = %d\n", x / 1000);
    printf("yuzler basamagi = %d\n", x / 100 % 10); 
    printf("yuzler basamagi = %d\n", x % 1000 / 100);
    // "/"(division) and "%"(modulus) operators are in same 
    // priority and they are left associative
    printf("onlar basamagi  = %d\n", x / 10 % 10);
    printf("onlar basamagi  = %d\n", x % 100 / 10);
    printf("birler basamagi = %d\n", x % 10);

    // output ->
    //  binler basamagi = 8
    //  yuzler basamagi = 7
    //  yuzler basamagi = 7
    //  onlar basamagi  = 2
    //  onlar basamagi  = 2
    //  birler basamagi = 3
  }
*/

/*
  increment(++) and decrement(--) operators
  ++x -> prefix increment,  R value expression
  ++x -> postfix increment, R value expression
  --x -> prefix decrement,  R value expression
  ++x -> postfix decrement, R value expression

  These operators operand must be L value expression
  Those operators both have side effects.
*/

/*
  int main(void){
    ++23; // syntax error
    // output -> lvalue required as increment operand

    int x = 36;
    (x + 5)--;  // syntax error
    //  output -> lvalue required as decrement operand
  }
*/

/*
                  --------------------------
                  | side effect (yan etki) |
                  --------------------------
*/

/*
  int main(void){
    int x = 10;

    x + 5;  // addition operator did not have a side effect  

    x = 6;  
    // assignment operator have side effect. 
    // Becuase it is changing the value of "x" variable.

    x *= 3; // assigment by product operator have side effect
    // x's new value will be 3 times x.

    !x;   // logical NOT operator did not have side effect.
  }
*/
  

/*
  int main(void){
    int x = 34;

    printf("x = %d\n", x);  // output -> x = 34
    ++x;
    printf("x = %d\n", x);  // output -> x = 35
    x++;
    printf("x = %d\n", x);  // output -> x = 36
    x = x + 1;
    printf("x = %d\n", x);  // output -> x = 37
    x += 1;
    printf("x = %d\n", x);  // output -> x = 38
  }
*/

/*
  int main(void){
    int x = 34;

    printf("x = %d\n", x);  // output -> x = 34
    --x;
    printf("x = %d\n", x);  // output -> x = 33
    x--;
    printf("x = %d\n", x);  // output -> x = 32
    x = x - 1;
    printf("x = %d\n", x);  // output -> x = 31
    x -= 1;
    printf("x = %d\n", x);  // output -> x = 30
  }
*/

/*
  int main(void){
    int x = 34;
    printf("x++ = %d\n", x++);  // output -> x++ = 34

    x = 34
    printf("x-- = %d\n", x--);  // output -> x-- = 34

    // x++ -> this expressions value is 34, not 35
    // postfix increment and decrement will generate the value itself
  }
*/

/*
  int main(void){
    int x = 34;
    printf("++x = %d\n", ++x);  // output -> ++x = 35

    x = 34;
    printf("--x = %d\n", --x);  // output -> --x = 33

    // ++x -> this expressions value is 35
    // prefix increment will generate variable's value + 1

    // --x -> this expressions value is 33
    // prefix decrement will generate variable's value - 1
  }
*/

/*
  void iprint(int i){
    printf("i = %d\n", i);
  }

  int main(void){
    int x = 34;
    iprint(x++);  // output -> i = 34

    x = 34;
    iprint(++x);  // output -> i = 35
  }
*/

/*
  int main(void){
    int x = 34;
    int y;

    y = x++;

    printf("y = %d\n", y);  // output -> y = 34
    printf("x = %d\n", x);  // output -> x = 35
  }
*/

/*
  int main(void){
    int x = 34;
    int y;

    y = ++x;

    printf("y = %d\n", y);  // output -> y = 35
    printf("x = %d\n", x);  // output -> x = 35
  }
*/

/*
  int main(void){
    int x = 23;
    int y = 7;

    printf("%d\n", x-- % ++y);    // output -> 7
    // x = 22, y = 8 in here

    printf("%d\n", x % y);        // output -> 6
  }
*/

/*
  int main(void){
    int x = 11;

    printf("%d\n", x++);  // output -> 11
    printf("%d\n", ++x);  // output -> 13
    printf("%d\n", x);    // output -> 13
  }
*/

/*
  // some idioms related with increment, decrement operators

  void foo(int);

  int main(void){
    int x, y;

    // Example 1 
    x = y;
    y = y + 1;
    // Those 2 lines are equal to 
    x = y++;


    // Example 2
    foo(x);
    x = x + 1;
    // Those 2 lines are equal to 
    foo(x++);


    // Example 3
    int arr[] = { 0 };
    int i = 0;

    while (i < 100)
      arr[i++] = 0;   // in the first tour in loop i will be 0


    // Example 4
    x = 45;
    
    x = x + 1;
    y = x;
    // Those 2 lines are equal to
    y = ++x;
  }
*/

/*
                    --------------------------------
                    | maximal munch (en uzun atom) |
                    --------------------------------
*/

/*
  when there is not any whitespace characters between tokens
  compiler will find and use the longest valid token sequence

  x>>=++y
  x    -> identifier
  >>=  -> operator 
  ++   -> operator
  y    -> identifier

*/

/*
  int main(void){
    int x = 20;
    int y = 30;

    int z = x+++y;    // x++ + y

    printf("x = %d\n", x);  // output -> x = 21
    printf("y = %d\n", y);  // output -> y = 30
    printf("z = %d\n", z);  // output -> z = 50
  }
*/

/*
  int main(void){
    int x = 20;

    // Question : is ++++x expression is syntax error in C?
    // ++++x
    // ++ -> operator
    // ++ -> operator
    // x  -> identifier

    ++(++x);  // syntax error
    // increment operators operand can not be R value expression
    // (++x) is an R value expression so code is syntax error
  }
*/

/*
  int main(void){
    int x = 20;

    // Question : is +++x expression is syntax error in C?
    // +++x
    // ++ -> operator
    // +  -> operator
    // x  -> identifier

    ++(+x);  // syntax error
    // increment operators operand can not be R value expression
    // (+x) is also an R value expression so code is syntax error
  }
*/

/*
                    ------------------------
                    | comparison operators |
                    ------------------------
                        > >= < <= == !=
*/

/*
  comparison operators generates signed int values 
  if true,  will generate 1
  if false, will generate 0
*/

/*
  int signum_function(int x)
  {
    if (x > 0)
      return 1;
    else if (x < 0)
      return -1;
    else 
      return 0;
  }

  int main(void){

    int x = 12;
    int y = -15;
    int z = 0;

    printf("signum(%d) = %d\n", x, (x > 0) - (x < 0));
    printf("signum(%d) = %d\n", x, signum_function(x));

    printf("signum(%d) = %d\n", y, (y > 0) - (y < 0));
    printf("signum(%d) = %d\n", y, signum_function(y));

    printf("signum(%d) = %d\n", z, (z > 0) - (z < 0));
    printf("signum(%d) = %d\n", z, signum_function(z));

    // output ->
    //  signum(12) = 1
    //  signum(12) = 1
    //  signum(-15) = -1
    //  signum(-15) = -1
    //  signum(0) = 0
    //  signum(0) = 0
  }
*/

/*
  int main(void){
    int x = 12, y = 45, z = 67, t = 34;
    int ival = 39;
    int ival_2 = 14;
    int ival_3 = 3;

    int cnt = (x > ival) + (y > ival) + (z > ival) + (t > ival);
    printf("%d of them is greater than %d\n", cnt, ival);
    // output -> 2 of them is greater than 39

    cnt = (x > ival_2) + (y > ival_2) + (z > ival_2) + (t > ival_2);
    printf("%d of them is greater than %d\n", cnt, ival_2);
    // output -> 3 of them is greater than 14

    cnt = (x > ival_3) + (y > ival_3) + (z > ival_3) + (t > ival_3);
    printf("%d of them is greater than %d\n", cnt, ival_3);
    // output -> 4 of them is greater than 3
  }
*/

/*
  #include <math.h>

  double foo(void);

  int main(void){
    double dval = foo();

    if (dval == 3.4)  // will not generate wanted result

    if (fabs(dval - 3.4) < 1E-4);
    if (fabs(dval - 3.4) < 0.0001);
    // will generate wanted result
  }
*/

/*
                    ---------------------
                    | logical operators |
                    ---------------------
                            ! && ||
*/

/*
  logical NOT(!)
  --------------
  p             TRUE    FALSE
  NOT p         FALSE   TRUE

  logical AND(&&)
  ----------------
  p1        p2        p1 && p2
  TRUE      TRUE      TRUE
  TRUE      FALSE     FALSE
  FALSE     TRUE      FALSE
  FALSE     FALSE     FALSE

  logical OR(||)
  ---------------
  p1        p2        p1 || p2
  TRUE      TRUE      TRUE
  TRUE      FALSE     TRUE
  FALSE     TRUE      TRUE
  FALSE     FALSE     FALSE


  XOR -> There is no logical XOR operator but there is bitwise xor(^)
  operator
  p1        p2        p1 ^ p2
  TRUE      TRUE      FALSE
  TRUE      FALSE     TRUE
  FALSE     TRUE      TRUE
  FALSE     FALSE     FALSE
*/

/*
  logic operators operands can be integral types, floating types and
  also adresses.

  in logical interpretation, expressions value will be calculated
    if value non-zero -> TRUE
    if value zero     -> FALSE


  Places where logical expression will be used
  ---------------------------------------------
  !expr
  expr1 && expr2
  expr ? op2 : op3
  if (expr)
  while (expr)
  do... while(expr)
  for(;expr;)
*/

/*
  !op (logical NOT), does not have a side effect
  !op expressions type is int, its value can be 1 or 0
*/

/*
  int main(void){
    int x = 10, y = 0;

    printf("!(%d) = %d\n", x, !x);  // output -> !(10) = 0
    printf("!(%d) = %d\n", y, !y);  // output -> !(0) = 1
  }
*/

/*
  // logical NOT operator is right associative
  int main(void){
    int x = 1, y = 0, z = 45, t = -3;

    printf("!!%d = !(!%d) = %d\n", x, x, !!x);  
    // output -> !!1 = !(!1) = 1
    printf("!!%d = !(!%d) = %d\n", y, y, !!y); 
    // output -> !!0 = !(!0) = 0
    printf("!!%d = !(!%d) = %d\n", z, z, !!z); 
    // output -> !!45 = !(!45) = 1
    printf("!!%d = !(!%d) = %d\n", t, t, !!t); 
    // output -> !!-3 = !(!-3) = 1
  }
*/

/*
  op1 && op2 (logical AND) operator is binary infix operator
  both operands will get in logical interpretation
*/

/*
  int main(void){

    int x = 10, y = 23;
    printf("(%d) && (%d) = %d\n", x, y, x && y); 
    // output -> (10) && (23) = 1
    printf("(%d) || (%d) = %d\n", x, y, x || y);
    // output -> (10) || (23) = 1

    y = 0;
    printf("(%d) && (%d) = %d\n", x, y, x && y); 
    // output -> (10) && (0) = 0
    printf("(%d) || (%d) = %d\n", x, y, x || y);
    // output -> (10) || (0) = 1

    x = 0;
    printf("(%d) && (%d) = %d\n", x, y, x && y); 
    // output -> (0) && (0) = 0
    printf("(%d) || (%d) = %d\n", x, y, x || y);
    // output -> (0) || (0) = 0
  }
*/

/*
  De Morgan's Law of Union
  -------------------------
  !(ex1 && ex2)  ->    !ex1 || !ex2
  !(ex1 || ex2)  ->    !ex1 && !ex2
*/

/*
  int main(void){

    int x = 10, y = 20;

    if (x && y)
      printf("logical AND - TRUE\n");
    else
      printf("logical AND - FALSE\n");
    
    if (x & y)
      printf("bitwise AND - TRUE\n");
    else
      printf("bitwise AND - FALSE\n");

    // generally 9/10 logical and bitwise operations results are same
    // that is why accidently using bitwise AND is dangerous!!
    // logical AND - TRUE
    // bitwise AND - FALSE
  }
*/

/*
          --------------------------------------------------
          | short circuit behaviour (kısa devre davranışı) |
          --------------------------------------------------
*/

/*
  exp1 && exp2  
    if exp1 is FALSE exp2 WILL NOT BE calculated

  exp1 || exp2
    if exp1 is TRUE exp2 WILL NOT BE calculated
*/

/*
  int main(void){
    int x = 0;
    int y = 555;

    int z = x && ++y;
    // short circuit behaviour happens

    printf("z = %d\n", z);  // output -> z = 0
    printf("y = %d\n", y);  // output -> y = 555
  }
*/

/*
  int main(void){
    int x = 10;
    int y = 555;

    int z = x && ++y;
    // no short circuit behaviour in this code

    printf("z = %d\n", z);  // output -> z = 1
    printf("y = %d\n", y);  // output -> y = 556
  }
*/

/*
  int main(void){
    int x = 10;
    int y = 555;

    int z = x || ++y;
    // short circuit behaviour happens

    printf("z = %d\n", z);  // output -> z = 1
    printf("y = %d\n", y);  // output -> y = 555
  }
*/

/*
  int main(void){
    int arr[10] = { 0 };

    for (int i = 0; i < 10 && arr[i] == 5; ++i){
      // using short circuit behaviour in the expression 
      // there is no way that reaching out of arrays boundries.
      // because of the left operand of logical AND
    }
  }
*/

/*
  int foo(void);
  int bar(void);

  int main(void){
    if (foo() && bar()){
      // there is no guarantee that bar() function will be called
      // if foo() functions return value is 0 
    }
  }
*/

/*
  int foo(void) { printf("foo has been called\n"); return 0;}
  int bar(void) { printf("bar has been called\n"); return 5;}
  int baz(void) { printf("baz has been called\n"); return -2;}

  int main(void){
    printf("First\n");
    foo() && bar();

    printf("Second\n");
    bar() && baz();

    // output ->
    //  First
    //  foo has been called     -> bar() has not been called
    //  Second
    //  bar has been called
    //  baz has been called
  }
*/

/*
  int main(void){
    // think about there is only "<" comparison operator in a language

    int x = 10, y = 12;
    printf("%d < %d = %d\n", x, y, x < y);  
    printf("%d > %d = %d\n", x, y, y < x);  
    printf("%d >= %d = %d\n", x, y, !(x < y));  
    printf("%d <= %d = %d\n", x, y, !(y < x));  
    printf("%d == %d = %d\n", x, y, !(y < x) && !(x < y));  
    printf("%d != %d = %d\n", x, y, (y < x) || (x < y));  

    // output ->
    //  10 < 12 = 1
    //  10 > 12 = 0
    //  10 >= 12 = 0
    //  10 <= 12 = 1
    //  10 == 12 = 0
    //  10 != 12 = 1

    x = 6, y = 6;
    printf("%d < %d = %d\n", x, y, x < y);  
    printf("%d > %d = %d\n", x, y, y < x);  
    printf("%d >= %d = %d\n", x, y, !(x < y));  
    printf("%d <= %d = %d\n", x, y, !(y < x));  
    printf("%d == %d = %d\n", x, y, !(y < x) && !(x < y));  
    printf("%d != %d = %d\n", x, y, (y < x) || (x < y));  

    // output ->
    //  6 < 6 = 0
    //  6 > 6 = 0
    //  6 >= 6 = 1
    //  6 <= 6 = 1
    //  6 == 6 = 1
    //  6 != 6 = 0
  }
*/

/*
  if (10 < x < 20) -> always true
  "<" operator is left associative

  if ((10 < x) < 20) -> (10 < x) can only generate 1 or 0
  if (1 < 20) -> true
  if (0 < 20) -> true
  if (10 < x < 20) -> always true

  if (x > 10 && x < 20) is the way to control 
*/

/*
  // logical XOR can be expressed like this 

  int main(void){
    int x = 12, y = -5;
    printf("%d logical XOR %d = %d\n", x, y, !!x != !!y);
    // output -> 12 logical XOR -5 = 0

    x = 0, y = 0;
    printf("%d logical XOR %d = %d\n", x, y, !!x != !!y);
    // output -> 0 logical XOR 0 = 0

    x = 11, y = 0;
    printf("%d logical XOR %d = %d\n", x, y, !!x != !!y);
    // output -> 11 logical XOR 0 = 1

    x = 0, y = 99;
    printf("%d logical XOR %d = %d\n", x, y, !!x != !!y);
    // output -> 0 logical XOR 99 = 1
  }
*/

/*
  int get_mid(int x, int y, int z){
    if (!((x > y && x > z) || (x < y && x < z)))
      return x;
    
    if (!((y > x && y > z) || (y < x && y < z)))
      return y;

    return z;
  }
*/

/*
                    ------------------------
                    | assignment operators |
                    ------------------------
                =  += -= *=  /=  %= &= ^= |= >>= <<=
*/

/*
  = (assignment operator) have side effect and will generate a value.
  Lots of idioms using value generated by assignment operator

  Generated value by assignment operators, is the value 
  that assigned to the object.
  x = 5 expressions value is 5, because 5 is assigned to x variable.
  y = 0 expressions value is 0
*/

/*
  int main(void){
    int x = 5;  // this is not an assigment operator
    // this is initialization syntax

    x = 12; // this is assignment operator
  }
*/

/*
  int main(void){
    int x; 

    x = 12; 
    // in this code we are discarding the value generated by 
    // assignment operator
  }
*/

/*
  int main(void){
    int x = 5;
    double dval = 5.9;

    x = dval;  // x will be 5
    // the value generated by assignment operator is 5
  }
*/

/*
  int main(void){
    int x;

    printf("%d\n", x = 7);  // output -> 7
    // x = 7 expressions value is 7

    printf("%d\n", x = 0);  // output -> 0
    // x = 0 expressions value is 0
  }
*/

/*
  int foo(void);

  int main(void){
    int x;
    int a = 6;

    x = foo();
    if (x > 10)
      ++a;
  }

  int main_2(void){
    int x;
    int a = 6;

    if ((x = foo()) > 10){  
      ++a;
    }
  }
  // Those 2 main functions are same, in main_2 value generated 
  // by the assignment operator has been used in if statement
*/

/*
  #include <stdlib.h>

  int main(void){
    int n = 10;
    void* vp;

    if ((vp = malloc(n * sizeof(int))) != NULL){

    }
  }
*/

/*
  int main(void){
    int c;

    // <---- FIRST WAY ---->
    c = getchar();
    while(c != '\n'){
      printf("%c %d\n", c, c);
      c = getchar();
    }

    // input -> hello world
    // output ->
    //  h 104
    //  e 101
    //  l 108
    //  l 108
    //  o 111
    //    32 (space character)
    //  w 119
    //  o 111
    //  r 114
    //  l 108
    //  d 100


    // <---- SECOND WAY ---->
    while(1){ // infinite loop idiom
      c = getchar();
      if (c == '\n')
        break;
        printf("%c %d\n", c, c);
    }
    // input -> Istanbul
    // output ->
    //  I 73
    //  s 115
    //  t 116
    //  a 97
    //  n 110
    //  b 98
    //  u 117
    //  l 108


    // <---- THIRD WAY ---->
    while ((c = getchar()) != '\n')
      printf("%c %d\n", c, c);

    // input -> Underground
    //  U 85
    //  n 110
    //  d 100
    //  e 101
    //  r 114
    //  g 103
    //  r 114
    //  o 111
    //  u 117
    //  n 110
    //  d 100
  }
*/

/*
  int foo(void){
    return 5;
  }

  int bar(void){
    return 7;
  }

  int main(void){
    int x, y, z, t;

    // <---- FIRST WAY ---->
    t = foo();
    z = t;
    y = z;
    x = y;

    printf("x = %d\n", x);  // output -> x = 5
    printf("y = %d\n", y);  // output -> y = 5
    printf("z = %d\n", z);  // output -> z = 5
    printf("t = %d\n", t);  // output -> t = 5

    // <---- SECOND WAY ---->
    x = y = z = t = bar();
    // assignment operator is right associative

    printf("x = %d\n", x);  // output -> x = 7
    printf("y = %d\n", y);  // output -> y = 7
    printf("z = %d\n", z);  // output -> z = 7
    printf("t = %d\n", t);  // output -> t = 7
  }
*/



