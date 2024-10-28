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
    using short curcuit behavior in if statement for 
    not getting undefined behavior in a[i] expression.


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

/*  
  How to get out of a loop (bir döngüden nasıl çıkılır?)
    1. when control expression is wrong
    2. return statement
    3. break statement
    4. goto statement
    5. exit() / abort() functions
*/ 

/*
  int return_func(int x){
    // code 

    while(1){
      if (expr)
        return x + 56;  
        // return statement will also ends functions execution
    }
  }

  int break_func(int x){
    // code 

    while(1){
      if (expr)
        break;
    }
    // function will continue its execution from here
  }

  int goto_func(int x){
    // code 

    while(1){
      if (expr)
        goto out;
    }
    
  out:
    // function will continue its execution from here
  }
*/

/*
          --------------------------------------------
          | infinite loop idiom(sonsuz döngü)[while] |
          --------------------------------------------
*/

/*
  int main(void){
    int i = 5;

    while(i < 26){
      if (i % 5 == 0){
        printf("%d", i);
        ++i;
      }
    }
  }
  // output -> 5 -> infinite loop
*/

/*
  int main(void){
    int i = 5;

    while(i < 26){
      if (i % 5 == 0)
        printf("%d ", i);
        ++i;
    }
  }
  // output -> 5 10 15 20 25

  int main_act(void){
    int i = 5;

    while(i < 26){
      if (i % 5 == 0)
        printf("%d ", i);

      ++i;
    }
  }
*/

/*
  int main(void){
    int i = 5;

    while(i < 26)
      if (i % 5 == 0)
        printf("%d ", i);
        ++i;
    
  }
  // output -> 5 5 5 5 5 ...... infinite loop

  int main_act(void){
    int i = 5;

    while(i < 26)
      if (i % 5 == 0)
        printf("%d ", i);

    ++i;
  }
*/

/*
  while(1){
    // idiomatic way for infinite loop
  }
*/

/*
                  -------------------
                  | break statement |
                  -------------------
*/

/*
  int main(void){
    break;  // syntax error
    // break statement not within loop or switch
  }
*/

/*
  // <---- Check break_statement.png ---->

  while (control_expr1){
    // statement 1
    // statement 2
    // statement 3
    if (control_expr2)
      break;
    // statement 4
    // statement 5
  }
  // statement x;

  // when if statement is true, statement 1 - 2 - 3 - x 
  // when if statement is false, statement 1 - 2 - 3 - 4 - 5 
*/

/*
  while (expr1){
    // statement 1
    // statement 2
    // statement 3
  }

  while (1){
    if (!expr1){
      break;
    }
    // statement 1
    // statement 2
    // statement 3
  }

  // Those 2 while loops are same
*/

/*
  while (1){
    // statement 1
    // statement 2
    // statement 3
    if (!expr1){
      break;
    }
  }

  do {
    // statement 1
    // statement 2
    // statement 3
  } while(expr1);

  // Those 2 loops are same
*/

/*
  // compiled with Microsoft (R) C/C++ Optimizing Compiler 

  #include <conio.h>

  int getchar(void);  // echoing, lined buffer

  // those functions are for MSVC compiler NOT C Standart functions
  int _getch(void);   // not echoing, not lined buffer(new line need)
  int _getche(void);  // echoing, not lined buffer

  int main(void){
    printf("Istanbul(i) or Ankara(a) : ");
    int ch = getchar();

    if (ch == 'i')
      printf("Istanbul it is\n");
    else if (ch = 'a')
      printf("Ankara it is\n");
    else
      printf("Invalid\n");

    // output -> 
    //  Istanbul(i) or Ankara(a) : a
    //  Ankara it is

    printf("Istanbul(i) or Ankara(a) : ");
    ch = _getch();

    if (ch == 'i')
      printf("Istanbul it is\n");
    else if (ch = 'a')
      printf("Ankara it is\n");
    else
      printf("Invalid\n");

    // output -> Istanbul(i) or Ankara(a) : Ankara it is 
    // when "a" entered in console, 
    // did not echo and did not want new line

    printf("Istanbul(i) or Ankara(a) : ");
    ch = _getche();

    if (ch == 'i')
      printf("Istanbul it is\n");
    else if (ch = 'a')
      printf("Ankara it is\n");
    else
      printf("Invalid\n");

    // output -> Istanbul(i) or Ankara(a) : iIstanbul it is
    // when "i" entered in console, 
    // it echoed but did not want new line
  }
*/

/*
  #include <conio.h>

  int main(void){
    printf("Write your 4 digit passcode: ");
    int c1 = _getch();  putchar('*');
    int c2 = _getch();  putchar('*');
    int c3 = _getch();  putchar('*');
    int c4 = _getch();  putchar('*');

    printf("\npasscode for debug %c%c%c%c\n", c1, c2, c3, c4);

    // output -> 
    //  Write your 4 digit passcode: ****
    //  passcode for debug 1234
  }
*/

/*
  // to lock keyboard for only hexadecimal numbers

  #include <ctype.h>

  int main(void){
    int cnt = 5;

    printf("Write 5 hex characters: ");
    int ch;

    while(cnt--){
      while(1){
        ch = _getch();
        if (isxdigit(ch))
          break;
      }
      putchar(ch);
    }
    // output -> Write 5 hex characters: 1aC87
  }
*/

/*
  // to lock keyboard for only hexadecimal numbers (IDIOMATIC WAY)

  #include <ctype.h>

  int main(void){
    int cnt = 5;

    printf("Write 5 hex characters: ");
    int ch;

    while(cnt--){
      while(!isxdigit(ch = _getch()))
        ; // null statement
      putchar(ch);
    }
    // output -> Write 5 hex characters: 12ACc
  }
*/

/*
  #include <conio.h>
  #include <stdlib.h>

  int main(void){

    int ch;
    int val;
    int cnt = 0;
    int sum = 0;
    int min, max;

    while (1){
      printf("integer or not (i) (n) : ");

      while ((ch = _getch()) != 'i' && ch != 'n')
        ;
      printf("%c\n", ch);

      if (ch == 'n')
        break;

      val = (rand() % 2  ? 1 : -1) * rand();
      printf("%d\n", val);

      if (cnt == 0)
        min = max = val;
      else
        if (val < min)
          min = val;
        else
          max = val;

      ++cnt;
      sum += val;
    }

    if (cnt == 0){
      printf("no integer input\n");
      return 0;
    }
    printf("count = %d\n", cnt);
    printf("average = %d\n", sum / cnt);
    printf("min value = %d\n", min);
    printf("max value = %d\n", max);
  }

  // output ->
  //  ...
  //  integer or not (i) (n) : i
  //  -30333
  //  integer or not (i) (n) : i
  //  4664
  //  integer or not (i) (n) : i
  //  7711
  //  integer or not (i) (n) : i
  //  6868
  //  integer or not (i) (n) : n
  //  count = 25
  //  average = 4787
  //  min value = -30333
  //  max value = 6868
*/

/*
                  ----------------------
                  | continue statement |
                  ----------------------
*/

/*
  int main(void){
    continue; // syntax error
    // continue statement not within a loop
  }
*/

/*
  while(expr1){
    statement1;
    statement2;
    statement3;
    
    if (c_ex)
      continue;
    statement4;
    statement5;
  }

  while(expr1){
    statement1;
    statement2;
    statement3;
    
    if (!c_ex){
      statement4;
      statement5;
    }
  }
  // Those 2 loops are same
*/

/*
                ----------------------
                | do while statement |
                ----------------------
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

  int dowhile_ndigit(int x){
    int digit_count = 0;

    do {
      ++digit_count;
      x /= 10;
    } while (x != 0);

    return digit_count;
  }
*/

/*
  int main(void){
    int x;
    do {
      printf("Write an integer between 0 - 100: ");
      scanf("%d", &x);
    } while (!(x > 0 && x < 100));

    printf("x = %d\n", x);
  }

  // output ->
  //  Write an integer between 0 - 100: 827
  //  Write an integer between 0 - 100: -12
  //  Write an integer between 0 - 100: 0
  //  Write an integer between 0 - 100: 100
  //  Write an integer between 0 - 100: 23
  //  x = 23
*/

/*
  <----  FIRST WAY ----> using goto statement

  loop1 (){
    statementx;
    statementx;
    statementx;

    loop2 (){
      statementy;
      statementy;
      statementy;
      
      loop3 (){
        statementz;
        statementz;
        statementz;

        if (c_exp)
        goto out;
          break;  // we want to go to statementk from here
      }
      statementy;
      statementy;
    }
    statementx;
    statementx;
  }

  out:
    statementk
    statementk


  <----  SECOND WAY ----> using flag variable

    int flag = 0;

    loop1 (){
    statementx;
    statementx;
    statementx;

    loop2 (){
      statementy;
      statementy;
      statementy;
      
      loop3 (){
        statementz;
        statementz;
        statementz;

        if (c_exp){
          flag = 1;
          break;  // we want to go to statementk from here
        }
      }
      if (flag)
        break;

      statementy;
      statementy;
    }
    if (flag)
      break;

    statementx;
    statementx;
  }

  statementk
  statementk
*/

/*
                  -----------------
                  | for statement |
                  -----------------
*/

/*
  for (;;)
    statement;

  for (ex1;;)           VALID
  for (ex1;ex2;)        VALID
  for (ex1; ex2; ex3)   VALID
*/

/*
  int foo(void);
  int bar(void);
  int baz(void);
  int bom(void);

  int main(void){

    for (foo(); bar(); baz())
      bom();

    // all function calls are expressions, this for loop is VALID
  }
*/

/*
  int main(void){

    int i;

    for (i = 0; i < 10; ++i)
      printf("%d ", i);
    // output -> 0 1 2 3 4 5 6 7 8 9
  }
*/

/*
  int main(void){

    int i = 0;

    for (; i < 10; ++i)
      printf("%d ", i);
    // output -> 0 1 2 3 4 5 6 7 8 9
  }
*/

/*
  int main(void){

    int i = 0;

    for (; i < 10;){
      printf("%d ", i);
      ++i;
    }
    // output -> 0 1 2 3 4 5 6 7 8 9
  }
*/

/*
  int main(void){

    int i = 0;

    for (;1;){
      printf("%d ", i);
      ++i;
    }
    // output -> 
    //  0 1 2 3 4 5 6 7 8 9 10 11 12 
    //  13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 
    //  ... inifinite

    for (;;){
      printf("%d ", i);
      ++i;
    }
    // output -> 
    //  0 1 2 3 4 5 6 7 8 9 10 11 12 
    //  13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 
    //  ... inifinite

    // If 2nd(control) expression is empty, 
    // it will act like(same as) logic true(1)
  }
*/

/*
            ------------------------------------------
            | infinite loop idiom(sonsuz döngü)[for] |
            ------------------------------------------
*/

/*
  int main(void){
    for(;;)
      printf("x-o-");

    // output -> 
    //  x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o-x 
    //  ... infinite
  }
*/

/*
  int main(void){
    int i;

    for (i = 0; i < 10; ++i)
      printf("%d\n", i);

    i = 23;   // VALID (block scope)
    

    for (int a = 0; a < 10; ++a){
      printf("%d\n", a);
    }

    a = 33;   // syntax error -> identifier "a" is undefined
  }
*/

/*
  int main(void){

    for (int i = 0, k = 0; i < 10; ++i)
      printf("%d\n", i);
    // can define more than 1 variable with same type
    // in for loop
  }
*/

/*
  int main(void){

  for (int i = 0; i < 10; ++i){
    int i = 67; // VALID 
  }

  // <-------- WHAT COMPILER SEES ------->
  for (int i = 0; i < 10; ++i){
    {
      int i = 67;  
    }  // inner i
  } // outer i
  // <-------- WHAT COMPILER SEES ------->
}
*/

/*
  int main(void){
    for (int i = 0; i < 5; ++i){
        int i = 67;
        i += 2;
    }
  }

  // compiled with x86-64 gcc 14.1 -O0 -std=c11
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-4], 0    -> outer : int i = 0
  //    jmp .L2
  //  .L3:
  //    mov DWORD PTR [rbp-8], 67   -> inner : int i = 67
  //    add DWORD PTR [rbp-8], 2    -> inner : i += 2;
  //    add DWORD PTR [rbp-4], 1    -> outer : ++i
  //  .L2:
  //    cmp DWORD PTR [rbp-4], 4    -> outer : if (i < 5)
  //    jle .L3
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  int main(void){
    for (int i = 0; i < 5; ++i){
      int i = 67;
      printf("%d ", i);
    }
    // output -> 67 67 67 67 67
  }
*/

/*
  int main(void){
    for (int i = 1; i < 10000; i *= 2){
      printf("%d ", i);
    }
    // output ->
    //  1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192  
  }
*/

/*
  int foo(int);

  int main(void){
    int arr[10];

    for (int k = 0; k < 10; ++k){
      arr[k] = foo(k);
    }

    int sval = 56;

    for (int i = 0; i < 10; ++i){
      if (arr[i] == sval)
        break;
    }
    // when the code comes here, we don't know how we get out of loop
    // 1. can be equal to 10, if logical expression (i < 10) becomes 0
    // 2. can be between 0 and 9 when arrays indexed value equals sval
  }

  // <---- FIRST WAY ---->
  int FLAG_VARIABLE_main(void){
    int arr[10];

    for (int k = 0; k < 10; ++k){
      arr[k] = foo(k);
    }

    int sval = 56;
    int flag = 0; // flag variable

    for (int i = 0; i < 10; ++i){
      if (arr[i] == sval){
        flag = 1;
        break;
      }
    }
    if (flag)
      printf("value is inside array in %d'th index", i);
    else
      printf("value is not inside array");
  }

  // <---- SECOND WAY ---->
  int LOOP_VARIABLE_main(void){
    int arr[10];

    for (int k = 0; k < 10; ++k){
      arr[k] = foo(k);
    }

    int sval = 56;
    
    int i;  // loop variable 
    for (i = 0; i < 10; ++i){
      if (arr[i] == sval)
        break;
    }
    if (i < 10)
      printf("value is inside array in %d'th index", i);
    else
      printf("value is not inside array");
  }

  // <---- IDIOMATIC WAY ---->
  int IDIOMATIC_main(void){
    int arr[10];

    for (int k = 0; k < 10; ++k){
      arr[k] = foo(k);
    }

    int sval = 56;
    
    int i;
    for (i = 0; i < 10 && arr[i] != sval; ++i)
      ; // null statement

    if (i < 10)
      printf("value is inside array in %d'th index", i);
    else
      printf("value is not inside array");
  }

*/

/*
  // https://en.wikipedia.org/wiki/Collatz_conjecture
  int main(void){
    unsigned long long uval;

    printf("first positive integer of the sequence: ");
    scanf("%llu", &uval);

    for (unsigned long long i = uval; i != 1;){
      printf("%llu ", i);
      if (i % 2 == 0)
        i /= 2;
      else
        i = 3 * i + 1;
    }

    // input -> first positive integer of the sequence: 65
    // output -> 
    //  65 196 98 49 148 74 37 112 56 28 14 7 
    //  22 11 34 17 52 26 13 40 20 10 5 16 8 4 2

    // input -> first positive integer of the sequence: 6784
    // output -> 
    //  6784 3392 1696 848 424 212 106 53 160 80 40 20 10 5 16 8 4 2
  }
*/

/*
  // -> 1/0! + 1/1! + 1/2! + ...
  // convergence to the number e (e sayısına yakınsama)
  // https://en.wikipedia.org/wiki/E_(mathematical_constant)

  int factorial(int x){
    int result = 1;

    for (int i = 1; i <= x; ++i){
      result *= i;
    }
    return result;
  }

  void calculate_sum(int count){
    double sum = 0.;

    for (int i = 0; i < count; ++i)
      sum += 1. / factorial(i);

    printf("count = %2d, sum = %f\n", count, sum);
  }

  int main(void){
    for (int i = 0; i < 13; ++i)
      calculate_sum(i);
    // should be max 12, 13! will overflow
    
    // output ->
    //  count =  0, sum = 0.000000
    //  count =  1, sum = 1.000000
    //  count =  2, sum = 2.000000
    //  count =  3, sum = 2.500000
    //  count =  4, sum = 2.666667
    //  count =  5, sum = 2.708333
    //  count =  6, sum = 2.716667
    //  count =  7, sum = 2.718056
    //  count =  8, sum = 2.718254
    //  count =  9, sum = 2.718279
    //  count = 10, sum = 2.718282
    //  count = 11, sum = 2.718282
    //  count = 12, sum = 2.718282
  }
*/

/*
  // -> 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11
  // convergence to pi/4
  // https://en.wikipedia.org/wiki/Pi

  void calculate_sum(int count){
    double sum = 0.;

    for (int i = 0; i < count; ++i){
      if (i % 2 == 0)
        sum += 1. / (2 * i + 1);  
      else
        sum -= 1. / (2 * i + 1); 
    }
      
    printf("count = %4d, sum = %f\n", count, 4 * sum);
  }

  int main(void){
    for (int i = 0; i < 10000; ++i)
      calculate_sum(i);
    
    // output ->
    //  count =    0, sum = 0.000000
    //  count =    1, sum = 4.000000
    //  count =    2, sum = 2.666667
    //  ...
    //  count =  166, sum = 3.135569
    //  count =  167, sum = 3.147581
    //  count =  168, sum = 3.135640
    //  ...
    //  count =  995, sum = 3.142598
    //  count =  996, sum = 3.140589
    //  count =  997, sum = 3.142596
    //  ...
    //  count = 9998, sum = 3.141493
    //  count = 9999, sum = 3.141693
  }
*/

/*
  int isprime(int x){
    if (x < 2)
      return 0;

    if (x % 2 == 0) return x == 2;
    if (x % 3 == 0) return x == 3;
    if (x % 5 == 0) return x == 5;

    for (int i  = 7; i * i <= x; i += 2){
      if (x % i == 0)
        return 0;
    }

    return 1;
  }

  int main(void){

    int low = 0, high = 100;

    for (int i = low; i < high; ++i){
      if (isprime(i)){
        printf("%d ", i);
      }
    }
    // output -> 
    //  2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 
    //  59 61 67 71 73 79 83 89 97
  }
*/

/*
  // https://github.com/necatiergin/
  // C_PROGRAMLAMA_DILI_ODEVLERI/blob/main/049.md

  int main(void)
  {
    int i = 1;

    do
    {
      printf("%d\n", i);
      i++;
      if (i < 15)
        continue;

      // continue statement will send program flow to HERE!!!  
    } while (0);  
    // output -> 1
  }
*/

/*
  // https://github.com/necatiergin/
  // C_PROGRAMLAMA_DILI_ODEVLERI/blob/main/051.md

  //  Aşağıdaki koda tek bir karakter ekleyeceksiniz ya da 
  //  koddan tek bir karakteri değiştireceksiniz. 
  //  Yapılan değişiklikten sonra oluşan C programı derlenip 
  //  çalıştırıldığında standart çıkış akımına 5 kez 'necati' yazacak

  //  Change 1 character or add 1 character, there are 3 answers.
  // <---- CODE ---->
  int main(void)
  {
    int n = 5;

    for (int i = 0; i < n; i--)
      printf("necati\n");
  }

  // <---- WAY 1 ---->
  int main(void)
  {
    int n = 5;

    for (int i = 0; i < n; n--)
      printf("necati\n");
  }

  // <---- WAY 2 ---->
  int main(void)
  {
    int n = 5;

    for (int i = 0; -i < n; i--)
      printf("necati\n");
  }

  // <---- WAY 3 ---->
  int main(void)
  {
    int n = 5;

    for (int i = 0; i + n; i--)
      printf("necati\n");
  }
*/

/*
                      --------------------
                      | switch statement |
                      --------------------
*/

/*
  switch statement is an alternative to some of else if ladder
  
  all switch statements can be replaced with else if ladder
  but not all else if ladders can be replaced with switch statement

  -> easy to read
  -> easy to write
  -> compiler can optimize switch statements better(depending on the case)
  -> decrease coding errors
*/

/*
  switch (integer_expr) 
  {
    case integral_constant_expr1: 
      statement1;
    case integral_constant_expr2:
      statement2;
    case integral_constant_expr3:
      statement3;
    case integral_constant_expr4:
      statement4;
  }

  when "integer_expr" value is equal to "integral_constant_expr1",
  program will execute all of those 
    statement1, 
    statement2, 
    statement3, 
    statement4
  until it reaches break statement or end of switch statement

  when "integer_expr" value is equal to "integral_constant_expr3",
  program will execute 
    statement3, 
    statement4
  until it reaches break statement or end of switch statement

  //--------------------//
  //--------------------//

  switch (integer_expr) 
  {
    case integral_constant_expr1: 
      statement1;
    case integral_constant_expr2:
      statement2;
      break;
    case integral_constant_expr3:
      statement3;
    case integral_constant_expr4:
      statement4;
  }

  statement5;

  when "integer_expr" value is equal to "integral_constant_expr1",
  program will execute all of those 
    statement1, 
    statement2
  then will go to out of switch statement because of break statement 
  and statement5 will be executed 
*/

/*
  int foo(int);
  double bar(int);

  int main(void){
    int ival = foo(123);

    switch (foo(123)){ // VALID
      // code
    }

    switch (bar(ival)){ // syntax error
      // coode
    }
    // error: switch quantity not an integer
  }
*/

/*
  #define SIZE 100

  int foo();

  int main(void){

    switch (foo(123))
    { 
      case 'A':       // type int, integral constant expression   VALID
      case 10 + 20:   // type int, constant expression            VALID
      case SIZE:      // type int, constant expression            VALID

      case "hello":   // type const char*                         NOT VALID
      case 3.14:      // type double                              NOT VALID
      case 30:        // case label must be unique (10 + 20 = 30) compile-time
    }
  }
*/

/*
  int main(void){
    switch(printf("hello world\n")){
      // no case label in switch statement is VALID
    }
    // output -> hello world
  }
*/

/*
  int main(void){
    int x = 1;

    switch(x){
      case 1: printf("1\n");
      case 2: printf("2\n");
      case 3:
    }
    // gcc  -> https://godbolt.org/z/Gx1fha7ns (NO ERROR)
    
    // msvc -> https://godbolt.org/z/51GKE4dTs (syntax error)
    //  error C2143: syntax error: missing ';' before '}'


    // ; null statement should be used 
    switch(x){
      case 1: printf("1\n");
      case 2: printf("2\n");
      case 3:
        ; // null statement
    }
  }
*/

/*
  int main(void){
    int x = 1;

    switch (x){
      case 1: 
      case 2:
      case 3: printf("1 2 3\n");
      // when the lase case label has a statement VALID
      // output -> 1 2 3
    }
  }
*/

/*
  int main(void){
    
    for (int i = 1; i < 10; ++i){
      switch (i){
        case 1: printf("day = %d, monday\n", i);       break;
        case 2: printf("day = %d, tuesday\n", i);      break;
        case 3: printf("day = %d, wednesday\n", i);    break;
        case 4: printf("day = %d, thursday\n", i);     break;
        case 5: printf("day = %d, friday\n", i);       break;
        case 6: printf("day = %d, saturday\n", i);     break;
        case 7: printf("day = %d, sunday\n", i);       break;
        default: printf("day = %d, invalid\n", i);   
      }
    }

    // output ->
    //  day = 1, monday
    //  day = 2, tuesday
    //  day = 3, wednesday
    //  day = 4, thursday
    //  day = 5, friday
    //  day = 6, saturday
    //  day = 7, sunday
    //  day = 8, invalid
    //  day = 9, invalid
  }
*/

/*
  int main(void){
    
    for (int i = 1; i < 10; ++i){
      switch (i){
        case 1: printf("day = %d, monday\n", i);       break;
        case 2: printf("day = %d, tuesday\n", i);      break;
        case 3: printf("day = %d, wednesday\n", i);    break;
        default: printf("day = %d, invalid\n", i);     break;
        case 4: printf("day = %d, thursday\n", i);     break;
        case 5: printf("day = %d, friday\n", i);       break;
        case 6: printf("day = %d, saturday\n", i);     break;
        case 7: printf("day = %d, sunday\n", i);       break;
      }
    }

    // default case can be anywhere in switch statement but 
    // generally used at the end of switch statement

    // output ->
    //  day = 1, monday
    //  day = 2, tuesday
    //  day = 3, wednesday
    //  day = 4, thursday
    //  day = 5, friday
    //  day = 6, saturday
    //  day = 7, sunday
    //  day = 8, invalid
    //  day = 9, invalid
  }
*/

/*
  int get_menu_option(void);

  switch(get_menu_option()){
    case ADD_RECORD : add_record(); break;
    case DEL_RECORD : del_record(); break;
    case UPD_RECORD : upd_record(); break;
  }

  switch(get_text_font){
    case TIMES_NEW_ROMAN : set_times_new_roman(); break;
    case ARIAL : set_arial(); break;
    case COURIER_NEW : set_courier_new(); break;
  }

  switch(get_card_suit){
    case HEARTS : set_hearts(); break;
    case DIAMONDS : set_diamonds(); break;
    case CLUBS : set_clubs(); break;
    case SPADES : set_spades(); break;
  }

  switch(get_card_face){
    case ACE : set_ace(); break;
    case KING : set_king(); break;
    case QUEEN : set_queen(); break;
    case JACK : set_jack(); break;
    case TEN : set_ten(); break;
    case NINE : set_nine(); break;
    case EIGHT : set_eight(); break;
    case SEVEN : set_seven(); break;
    case SIX : set_six(); break;
    case FIVE : set_five(); break;
    case FOUR : set_four(); break;
    case THREE : set_three(); break;
    case TWO : set_two(); break;  
  }

  // generally case values are symbolic constants(macros) 
  // or enumeration constants
*/

/*
  if (x == 5 || x == 7)
    statement1;
  else if (x == 9 || x == 13 || x == 17)
    statement2;
  else if (x == 19 || x == 23)
    statement3;

  switch(x){
    case 5:
    case 7: statement1; break;
    case 9:
    case 13:
    case 17: statement2; break;
    case 19:
    case 23: statement3; break;
  }
*/

/*
  // compiler will generate jump table (switch statement optimization)

  int main(void){
    int x = 1;
    switch (x){
        case 1:     x = 11;   break;
        case 2:     x = 12;   break;
        case 3:     x = 13;   break;
        case 4:     x = 14;   break;
        case 5:     x = 15;   break;
        default:    x = 55;   break;
    }
  }

  // compiled with x86-64 gcc 14.2 -O0 -std=c11
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    mov DWORD PTR [rbp-4], 1         
  //    cmp DWORD PTR [rbp-4], 5          
  //    ja .L2                            --> checking default case
  //    mov eax, DWORD PTR [rbp-4]        --> eax = x
  //    mov rax, QWORD PTR .L4[0+rax*8]   --> check jump-table using x's value
  //    jmp rax   
  //  .L4:      --> jump table
  //    .quad .L2
  //    .quad .L8
  //    .quad .L7
  //    .quad .L6
  //    .quad .L5
  //    .quad .L3
  //  .L8:
  //    mov DWORD PTR [rbp-4], 11
  //    jmp .L9
  //  .L7:
  //    mov DWORD PTR [rbp-4], 12
  //    jmp .L9
  //  .L6:
  //    mov DWORD PTR [rbp-4], 13
  //    jmp .L9
  //  .L5:
  //    mov DWORD PTR [rbp-4], 14
  //    jmp .L9
  //  .L3:
  //    mov DWORD PTR [rbp-4], 15
  //    jmp .L9
  //  .L2:
  //    mov DWORD PTR [rbp-4], 55
  //    nop
  //  .L9:
  //    mov eax, 0
  //    pop rbp
  //    ret
*/

/*
  void print_date(int day, int mon, int year){
    printf("%02d", day);

    switch(day){
      case 1: 
      case 21: 
      case 31: 
        printf("st "); break;
      case 2: 
      case 22: 
        printf("nd "); break;
      case 3: 
      case 23: 
        printf("rd "); break;
      default: 
        printf("th "); break;
    }

    switch (mon){
      case 1:   printf("Jan "); break;
      case 2:   printf("Feb "); break;
      case 3:   printf("Mar "); break;
      case 4:   printf("Apr "); break;
      case 5:   printf("May "); break;
      case 6:   printf("Jun "); break;
      case 7:   printf("Jul "); break;
      case 8:   printf("Aug "); break;
      case 9:   printf("Sep "); break;
      case 10:  printf("Oct "); break;
      case 11:  printf("Nov "); break;
      case 12:  printf("Dec "); break;
    }

    printf("%d\n", year);
  }

  int main(void){
    int day = 1, mon = 1, year = 2001;
    print_date(day, mon, year); // output -> 01st Jan 2001

    day = 2, mon = 2, year = 2002;
    print_date(day, mon, year); // output -> 02nd Feb 2002

    day = 3, mon = 3, year = 2003;
    print_date(day, mon, year); // output -> 03rd Mar 2003

    day = 4, mon = 4, year = 2004;
    print_date(day, mon, year); // output -> 04th Apr 2004
  }
*/

/*
  int foo(void);

  int main(void){
    const int a = 5;    // not a constant expression
    const int b = 7;

    switch (foo()){
      case a:   // syntax error
      case b:   // syntax error
        ;
    }
    // error : case label does not reduce to an integer constant
  }
*/

/*
  int main(void){
    int x = 5;

    switch (x)
      case 4: printf("4\n"); 
      case 5: printf("5\n");   // syntax error
      // error: case label not within a switch statement

      // we need compound statement for multiple case labels
  }
*/

/*
  switch (x){
    case 1: foo();  // fallthrough
    case 2: bar();  break;
    case 3: baz();  break;
    case 4: bom();  break;
  }

  // if x == 1, foo(), bar() will be executed (by our choice)
  // if x == 2, bar() will be executed ...
*/

/*
  int isleap(int x){
    return x % 4 == 0 && (x % 100 != 0 || x % 400 == 0);
  }

  // 5 9 1987
  int total_day_in_year(int d, int m, int y){
    int sum = d;

    switch(m - 1){
      case 11: sum += 30;   // fallthrough
      case 10: sum += 31;   // fallthrough
      case 9: sum += 30;    // fallthrough
      case 8: sum += 31;    // fallthrough
      case 7: sum += 31;    // fallthrough
      case 6: sum += 30;    // fallthrough
      case 5: sum += 31;    // fallthrough
      case 4: sum += 30;    // fallthrough
      case 3: sum += 31;    // fallthrough
      case 2: sum += isleap(y) ? 29 : 28;   // fallthrough
      case 1: sum += 31;
    }

    return sum;
  }

  int main(void){
    int d = 5, m = 9, y = 1987;
    printf("%dth day of the year\n", total_day_in_year(d, m, y));
    // output -> 248th day of the year
  }
*/

/*
                        ------------------
                        | goto statement |
                        ------------------
*/

/*
  long jump (uzak sıçrama)
    function flow will jump to another function

  near(local) jump (yerel/yakın sıçrama)
    function flow will jump to another location in the same function
    same stack frame

  labels are in function scope
*/

/*
  int main(void){
    // code
    goto hello; // VALID

  hello:

    // code 
    goto hello; 
  }
  // hello(label) identifier is in function scope
  // inside main function hello label is valid in everywhere
*/

/*
  int main(void){
  hello:  // hello label is in function scope
    ;

    int hello = 1;  // hello variable is in block scope
  }
  // VALID CODE
*/

/*
  while(expr_1){
    if (expr_2)
      goto out;

    statement1;
    statement2;
    statement3;
  out:
    ;
  }

  while(expr_1){
    if (expr_2)
      continue;

    statement1;
    statement2;
    statement3;
  }

  // Both this code blocks are same
*/

/*
  // goto will exit all of the loops in this scenario

  loop(){

    loop(){

      loop(){

        if (c_exp)
          goto out;
      }
    }
  }

  out:
    statement_x;
*/

/*
  // goto will both exit from switch and the for loop in this scenario

  for(;;){
    statement;

    switch(int_ex){
      case 1: statement; break;
      case 2: statement; break;
      case 3: 
        statement;
        goto out;
    }
  }

  out:
    statement_x;
*/

/*
  // TODO : THIS WILL BE IMPLEMENTED LATER IN THIS COURSE
  // goto will also used in ERROR HANDLING
  // goto is used for giving back resources and memory
*/

/*
                        ----------------
                        | nested loops |
                        ----------------
*/

/*
  loop(){
    loop(){
      loop(){
        statement;
      }
    }
  }
*/

/*
  int main(void){
    for (int i = 0; i < 5; ++i){
      for (int j = 0; j < 10; ++j){
        printf("(%d %d) ", i, j);
      }
      printf("\n");
    }
  }
  // output ->
  //  (0 0) (0 1) (0 2) (0 3) (0 4) (0 5) (0 6) (0 7) (0 8) (0 9)
  //  (1 0) (1 1) (1 2) (1 3) (1 4) (1 5) (1 6) (1 7) (1 8) (1 9)
  //  (2 0) (2 1) (2 2) (2 3) (2 4) (2 5) (2 6) (2 7) (2 8) (2 9)
  //  (3 0) (3 1) (3 2) (3 3) (3 4) (3 5) (3 6) (3 7) (3 8) (3 9)
  //  (4 0) (4 1) (4 2) (4 3) (4 4) (4 5) (4 6) (4 7) (4 8) (4 9)
*/

/*
  int main(void){
    int i, k;
    for (i = 0; i < 5; ++i){
      for (k = 0; k < 10; ++k){
      }
    }
    printf("(%d %d)\n", i, k);  // output -> (5 10)
  }
*/

/*
  int main(void){
    int i, k;
    for (i = 0; i < 5; ++i)
      for (k = 0; k < 10; ++k); // there is a null statement here
        printf("(%d %d)\n", i, k);  // output -> (5 10)
  }
*/

/*
  int main(void){
    int count = 0;
    for (int i = 0; i < 10; ++i){
      for (int j = 0; j < 20; ++j){
        for (int k = 0; k < 7; ++k){
          ++count;
        }
      }
    }
    printf("count = %d\n", count);  // output -> count = 1400
    // 10 * 20 * 7 = 1400
  }
*/

/*
  int main(void){
    // <--- armstrong number_1 --->
    for (int i = 100; i < 1000; ++i){
      int d1 = i / 100;
      int d2 = i / 10 % 10;
      int d3 = i % 10;

      if (d1 * d1 * d1 + d2 * d2 * d2 + d3 * d3 * d3 == i)
        printf("%d ", i);
    }
    // output -> 153 370 371 407

    printf("\n");

    // <--- armstrong number_2 --->
    int ival = 100;
    for (int i = 1; i <= 9; ++i){
      for (int j = 0; j <= 9; ++j){
        for (int k = 0; k <= 9; ++k){
          if (i * i * i + j * j * j + k * k * k == ival){
            printf("%d ", ival);
          }
            ++ival;
        }
      }
    }
    // output -> 153 370 371 407
  }
*/

/*
  // if n = 5
  //  *
  //  **
  //  ***
  //  ****
  //  *****

  void print_start(int n)
  {
    while (n--)
      putchar('*');
    printf("\n");
  }

  int main(void){
    int n = 5;

    // <--- WAY 1 --->
    for (int i = 1; i <= n; ++i){
      for (int j = 0; j < i; ++j){
        putchar('*');
      }
      printf("\n");
    }

    // <--- WAY 2 --->
    for (int i = 1; i <= n; ++i)
      print_start(i);
    // increasing readability with using function for inner loop
  } 
*/