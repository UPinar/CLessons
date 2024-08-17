#include <stdio.h>

/*
              ------------------------------------------
              | control statements (kontrol deyimleri) | 
              ------------------------------------------
*/

/*
  int x = 5;  // this is declaration statement
  y = 4;      // this is NOT a declaration statement

  x;        // expression statement, DID NOT create side effect
  5;        // expression statement, DID NOT create side effect
  x + 5;    // expression statement, DID NOT create side effect
  x = 5;    // expression statement, create side effect
  ++x;      // expression statement, create side effect
  foo();    // expression statement, create side effect

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

  else belongs to inner if so it should be written like
  for human readability, but both ways will act same.
  Because C is an atomic language
  
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