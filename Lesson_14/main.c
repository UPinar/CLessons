#include <stdio.h>

/*
              ==========================================
              | control statements (kontrol deyimleri) | 
              ==========================================
*/

/*
  int x = 5;  // this is declaration statement
  y = 4;      // this is NOT a declaration statement

  x;        // expression statement, DID NOT create side effect
  5;        // expression statement, DID NOT create side effect
  x + 5;    // expression statement, DID NOT create side effect
  x = 5;    // expression statement, creates side effect
  ++x;      // expression statement, creates side effect
  foo();    // expression statement, creates side effect

  {
    x++;
    ++y;
    ++z;    
  }         // compound statement (from opening to closing brace)

  ;         // null statement
  ;;;;;;    // null statements
*/

/*
  (flow) control statements
  --------------------------

  1. They have predetermined syntax.
  2. At least 1 keyword use needed.
  3. Ability to change programs flow direction.

  -> if statement

  -> while statement
  -> do while statement
  -> for statement

  -> continue statement
  -> break statement

  -> switch statement
  -> goto statement

  -> return statement
*/

/*
                    ----------------
                    | if statement |
                    ----------------
*/

/*
  if (expr1)  -> expr1 is a conditional expression

  if (x)                  ==> if (x != 0)
  if (x == 0)             ==> if (!x)
  if (x - 5) 

  if (x > 10)
  if (x > 10 && x < 20)
  if (x > 10 || y < 20)

  if (foo() != 0)         ==> if (foo())
  if (isprime(x) != 0)    ==> if (isprime(x))
  if (isprime(x) == 0)    ==> if (!isprime(x))

  if (x++ > 10) // if paranthesis generates a sequence point
    foo(x)  


  if ((x = foo()) != -1)  ==>         x = foo();
    bar(x);                           if (x != -1)
                                        bar();

  
  if (foo(), bar())       ==>         foo();
    ++x;                              if (bar() != 0)
                                        ++x;    
  
  
  GENERAL MISTAKES
  ----------------

  if (x != 5 || x != 19)  // always true
  if (x != 5 && x != 19) 

  if (10 < x < 20)        // always true  
  if (x > 10 && x < 20)

  if (dx > 4,5)           // always true
  if (dx > 4.5)

  if (dy < 5,0)           // always false
  if (dy < 5.0)

  if (x = 5)              // always true
  if (x == 5)
  if (5 == x)             // better
  if (5 = x)              // syntax error

  int foo(void);
  if (foo)    // always true, will not call the function
  if (foo())  // will call the function

  if (dval == 0.65412)    // comparison in floating types 
  if (fabs(dval) - 0.65412 < 0.0001)
*/

/*
  int main(void){
    int x = 5;

    if (x > 10);
      printf("TRUE\n"); 

    // because of there is a terminator token at the end of the if 
    // statements paranthesis it will exactly be like

    if (x > 10)
      ; // null statement
    printf("TRUE\n");
  }
*/

/*
  int main(void){
    int x = 10;

    if (x > 10) // syntax error : expected expression before 'else'
    else 
      printf("FALSE\n");

    
    // <--- FIRST WAY --->
    if (x > 10) 
      ;
    else 
      printf("FALSE\n");

    
    // <--- SECOND WAY --->
    if (x > 10)
    {}
    else
      printf("FALSE\n");

    // <--- BETTER WAY --->
    if (x <= 10)  // if (!(x > 10))
      printf("FALSE\n");
  }
*/

/*
  if (i < size && a[i] != 0)  
    using short curcuit behaviour in if statement for 
    not getting undefined behaviour in a[i] expression.


  if (foo() && bar() && baz() && i > 0)
    (i > 0) condition is much more cheaper than function calls
  if (i > 0 && foo() && bar() && baz())     BETTER
*/

/*
  dangling else
  -------------

  if (x > 10)
    if (y > 20)
      ++x;
  else
    ++y;

  "else" belongs to inner if so it should be written like below
  for human readability, but both ways will act same.
  Because C is an atomic language.
  
  if (x > 10)
    if (y > 20)
      ++x;
    else
      ++y;
*/

/*
  else if ladder 
  cascaded if 
  ---------------

  if (exp1)
    ++a;
  else
    if (exp2)
      ++b;
    else
      if (exp3)
        ++c;
      else
        if (exp4)
          ++d;
        else
          ++e;

  C is an atomic language and this can be written as

  if (exp1)
    ++a;          -> exp1 TRUE
  else if (exp2)      
    ++b;          -> exp1 FALSE - exp2 TRUE
  else if (exp3)
    ++c;          -> exp1, exp2 FALSE - exp3 TRUE
  else if (exp4)
    ++d;          -> exp1, exp2, exp3 FALSE - exp4 TRUE
  else
    ++e;          -> exp1, exp2, exp3, exp4 FALSE
*/

/*
  #include <math.h>

  int main(void){
    int a = 5, b = 4, c = 2;
    double delta = b * b - 4 * a * c;

    if (delta < 0){
      printf("no real root \n");
    }
    else if (delta == 0){
      printf("there is one root : %f\n", -b / (2 * a));
    }
    else{
      printf("two real root\n");

      double root_delta = sqrt(delta);
      printf("root1 = %f\n", (-b - root_delta) / (2 * a));
      printf("root2 = %f\n", (-b + root_delta) / (2 * a));
    }
  }
*/

/*
                    -------------------
                    | loop statements | 
                    -------------------
    (break and continue statement will be used)
*/

/*
  while (expr)
    statement;  ---> while statements body
  ----------------------------------------------------
  while (expr)
    statement1;
    statement2; 
    statement3;
  ---> while statements body is statement1
      statement2 and statement3 is not inside while statements body
  ----------------------------------------------------
  while (expr)
  {
    statement1;
    statement2; 
    statement3;
  } 
  ---> while statements body is a compound statement
      it includes statement1, statament2 and statement3
  ----------------------------------------------------
  while (expr)
    statement1, statement2, statement3;

  ---> if statements are expression statements, comma operator
    can be used and made all to one statement.
  ---> statement1, statament2 and statement3 
    are inside while statements body
  ----------------------------------------------------
  while(x < 10;) // this is a statement not an expression SYNTAX ERROR
  ----------------------------------------------------
  void foo(int);
  while(foo(12))  // expressions type is void SYNTAX ERROR
  ----------------------------------------------------

  there is no guarantee that body of the while statement 
  will be done once.
*/

/*
  int main(void){
    int i = 0;

    while(i < 10){
      printf("%d ", i);
      ++i;
    }
    // output -> 0 1 2 3 4 5 6 7 8 9
  }
*/

/*
  int main(void){
    int i = 0;

    while(i < 10)
      printf("%d ", i), ++i;
    
    // output -> 0 1 2 3 4 5 6 7 8 9
  }
*/

/*
  int main(void){
    int i = 0;

    while(i < 10)
      printf("%d ", i++); // post-increment
    
    // output -> 0 1 2 3 4 5 6 7 8 9
  }
*/

/*
  int main(void){
    int i = 0;

    while(i < 10)
      printf("%d ", ++i); // pre-increment
    
    // output -> 1 2 3 4 5 6 7 8 9 10
  }
*/

/*
  int main(void){
    int ch;

    printf("Write a word : ");

    while((ch = getchar()) != '\n'){
      printf("%c %d\n", ch, ch);
    }
    // input -> Write a word : ISTANBUL
    // output ->
    //  I 73
    //  S 83
    //  T 84
    //  A 65
    //  N 78
    //  B 66
    //  U 85
    //  L 76
  }
*/

/*
  // armstrong numbers
  abc -> (a^3) + (b^3) + (c^3) = abc  
  153 -> 1 + 125 + 27
  370 -> 27 + 343 + 0
  371 -> 27 + 343 + 1
  407 -> 64 + 343

  abcd -> (a^4) + (b^4) + (c^4) + (d^4) = abcd
*/

/*
  int main(void){
    int i  = 100;

    int d1, d2, d3;
    while(i < 1000){
      d1 = i / 100;
      d2 = i / 10 % 10;
      d3 = i % 10;

      if (i == (d1 * d1 * d1 ) + (d2 * d2 * d2) + (d3 * d3 * d3))
        printf("%d ", i);
      ++i;
    }
    // output -> 153 370 371 407
  }
*/

/*
  int main(void){
    int i  = 1000;

    int d1, d2, d3, d4;
    while(i < 10000){
      d1 = i / 1000;
      d2 = i / 100 % 10;
      d3 = i / 10 % 10;
      d4 = i % 10;

      if (i ==  (d1 * d1 * d1 * d1) + 
                (d2 * d2 * d2 * d2) + 
                (d3 * d3 * d3 * d3) +
                (d4 * d4 * d4 * d4))
        printf("%d ", i);

      ++i;
    }
    // output -> 1634 8208 9474
  }
*/

/*
  int ndigit(int x){
    if (x == 0)
      return 1;

    int digit_count = 0;
    while(x != 0){
      ++digit_count; 
      x /= 10;
    }
    return digit_count;
  }

  int main(void){
    int number1 = 345;
    int number2 = 110129394;
    int number3 = 0;

    printf("%d have %d digits.\n", number1, ndigit(number1));
    printf("%d have %d digits.\n", number2, ndigit(number2));
    printf("%d have %d digits.\n", number3, ndigit(number3));
    // output ->
    //  345 have 3 digits.
    //  110129394 have 9 digits.
    //  0 have 1 digits.
  }
*/

/*
  // 762345 -> 7 + 6 + 2 + 3 + 4 + 5 = 27
  int sumdigit(int x){
    int digit_sum  = 0;
    while(x){
      digit_sum += x % 10;
      x /= 10;
    }
    return digit_sum;
  }

  int main(void){

    int number1 = 762345;
    int number2 = 110129394;
    int number3 = 0;
    printf("%d numbers digits sum =  %d\n", number1, sumdigit(number1));
    printf("%d numbers digits sum =  %d\n", number2, sumdigit(number2));
    printf("%d numbers digits sum =  %d\n", number3, sumdigit(number3));
    // output ->
    //  762345 numbers digits sum =  27
    //  110129394 numbers digits sum =  30
    //  0 numbers digits sum =  0 
  }
*/

/*
  int main(void){
    int x = 0;

    while(x++ < 5); // while statements body have a null statement
      printf("%d ", x);

    // output -> 6
  }

  // CAN BE WRITTEN LIKE THIS
  int main(void){
    int x = 0;

    while(x++ < 5)
      ; 

    printf("%d ", x);

    // output -> 6
  }
*/

/*
  int main(void){
    double d = 4.5;

    while(d < 7,0){    // always false --> while(0)
      printf("%f\n", d);
      d += .3;
    }
    // output -> 
    // if "," comma operator has been used instead of "."


    while(d < 7.0){    
      printf("%f\n", d);
      d += .3;
    }
    // output ->
    //  4.500000
    //  4.800000
    //  5.100000
    //  5.400000
    //  5.700000
    //  6.000000
    //  6.300000
    //  6.600000
    //  6.900000
  }
*/

/*
    ------------------------------
    | n kere dönen döngü idiyomu | -> loop idiom that loops n times
    ------------------------------
*/

/*
  int main(void){
    int n = 5;
    while (n-- > 0)
      printf("x "); 
    // output -> x x x x x

    putchar('\n');

    n = 5;
    while (n--)
      printf("o "); 
    // output -> o o o o o
  }
*/

/*
  // function will calculate (base ^ exp)
  int power(int base, int exp){
    int result = 1;

    while(exp--)
      result *= base;

    return result;
  }

  int main(void){
    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5;

    printf("%d to the power of %d = %d\n", c, a, power(c, a));
    printf("%d to the power of %d = %d\n", d, e, power(d, e));
    printf("%d to the power of %d = %d\n", f, b, power(f, b));
    // output ->
    //  2 to the power of 0 = 1
    //  3 to the power of 4 = 81
    //  5 to the power of 1 = 5
  }
*/

/*
  void clear_standart_input_buffer(void){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF) 
      ; // null statement


    //  while((ch = getchar()) != '\n' && ch != -1) 
    //  { }
  }

  int main(void){
    int number;
    printf("write a number : ");
    scanf("%d", &number);
    printf("number = %d\n", number);

    // input -> write something : 726Hello
    // output -> number = 726
    // number = 726 and "Hello" character codes are in the buffer

    clear_input_buffer();

    printf("write a number : ");
    scanf("%d", &number);
    printf("number = %d\n", number);
    // input -> write something : 817
    // output -> number = 817
  }
*/

/*
  // write "Hello" to standart output 
  // without using ";(semi-colon) in the code"

  int main(void){
    // <--- FIRST WAY --->
    if (printf("Hello\n"))
    {}

    // <--- SECOND WAY --->
    while (!printf("Hello\n"))
    {}

    // <--- THIRD WAY --->
    switch (printf("Hello\n"))
    {}
  }
*/

/*
  int main(void){
    int ch;
    int temp = 0;

    printf("Write a positive number : ");

    while ((ch = getchar()) != '\n')
      temp  = temp * 10 + ch - '0';

    int number;
    number = temp;
    printf("number = %d\n", number);

    // input -> Write a positive number : 27364
    // output -> number = 27364
  }
*/

/*
  int main(void){
    int ch;
    int temp = 0;

    printf("Write an octal number : ");

    while ((ch = getchar()) != '\n')
      temp  = temp * 8 + ch - '0';

    int number;
    number = temp;
    printf("number = %d\n", number);

    // input -> Write an octal number : 213 
    //  (2 * 64) + (1 * 8) + (3 * 1) = 128 + 8 + 3 = 139
    // output -> number = 139

    // input -> Write an octal number : 111 
    //  (1 * 64) + (1 * 8) + (1 * 1) = 64 + 8 + 1 = 73
    // output -> number = 73
  }
*/

/*
  int main(void){
    int ch;
    int temp = 0;

    printf("Write binary number : ");

    while ((ch = getchar()) != '\n')
      temp  = temp * 2 + ch - '0';

    int number;
    number = temp;
    printf("number = %d\n", number);

    // input -> Write binary number : 11111111 
    // output -> number = 255

    // input -> Write binary number : 1011 
    // output -> number = 11
  }
*/

/*
  #include <ctype.h>

  int main(void){
    int ch;
    int temp = 0;

    printf("Write an hexadecimal number : ");

    while ((ch = getchar()) != '\n'){
      if (isdigit(ch))
        temp  = temp * 16 + ch - '0';
      else if(isxdigit(ch))   // 0-9 a-f A-F
        temp = temp * 16 + toupper(ch) - 'A' + 10;
    }

    int number;
    number = temp;
    printf("number = %d\n", number);

    // input -> Write an hexadecimal number : 1aB
    // output -> number = 427

    // input -> Write an hexadecimal number : 172AFb
    // output -> number = 1'518'331
  }
*/