#include <stdio.h>

/*
  data structures (veri yapıları) : how datas are stored in memory
  <--- check data_structures.png --->

  algorithms (algoritmalar) : how those datas will be processed
*/

/*
  algorithms computational complexity (algoritmanın karmaşıklığı) :
    relation between the data count inside data structure and 
    the increase in the number of operations that will be done

  <--- check computational_complexity.png --->

  constant-time algorithms: 
    number of the data inside data structure does not affect 
    the number of operations
  linear-complexity :
    number of the data inside data structure affects 
    the number of operations linearly
  big-o notation : 
    O(1)        -> constant-time algorithms
    O(log n)    -> logarithmic-complexity
    O(n)        -> linear-complexity
    O(n log n)  
    O(n^2)      
    O(2^n)      -> exponential-complexity
    O(n!)       -> factorial-complexity

  If there are two phases of an algorithm and the first phase is O(n)
  and the second phase is O(n^2) then the algorithm's complexity is O(n^2)
  O(n^2) > O(n) ----> O(n) + O(n^2) = O(n^2)
*/

/*
  for (int i 0; i < n; ++i){
      // O(n)
  }

  for (int i 0; i < 2 * n; ++i){
      // O(n)
  }

  for (int i 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      // O(n^2)
    }
  }

  if a value exists in an array
  23 83 12 45 67 34 89 12 56 78   // linear search O(n)

  2 5 7 8 9 12 15 18 23 25 27 29  // binary search O(log n)
  split the array into two parts and compare the middle value
*/

/*
                    ====================
                    | arrays (diziler) |
                    ====================
*/

/*
  -> C arrays are fixed arrays data structure.
  -> Number of the elements are constant and cannot be changed.
  -> datas are stored contiguously in memory.
  -> reaching to an element with its index is O(1)[constant-time].
*/

/*
  #define   SIZE  100

  int main(void){
    // int arr[constant expression(sabit ifadesi)];

    int arr[20];        // arr identifiers type is int[20]
    double b[50];       // b's type is double[50]

    int arr2[20 + 30];  // valid 
    int arr3[SIZE];     // valid

    int x = 10;
    int a[x]; // if compiler supports C11, this is valid
    // C99 - VLA(variable length array)
    // C11 - VLA(variable length array) =>  OPTIONAL

    int arr4[];         // syntax error (EMPTY)
    int arr5[0];        // syntax error (O)
    int arr6[-5];       // syntax error (NEGATIVE)
    
    int arr7[1];        // valid
  }
*/

/*
  int main(void){
    int x[10];
    int y[20];
    int z[30];

    int a[10], b[20], c[30];    
    // declaring arrays with comma separated list is valid 
  }
*/

/*
  int main(void){
    int i;
    int j[5];
    int k;
    int m[10];

    int a, b[5], c, d[10];
    // declaring variables and arrays(also a varible) 
    // with comma separated list is valid
  }
*/

/*
  int g_ival;                   // zero value
  int g_arr[20];                // elements have zero values

  void foo(void){
    int local_ival;             // garbage value
    int local_arr[20];          // elements have garbage values

    static int static_ival;     // zero value
    static int static_arr[20];  // elements have zero values
  }
*/

/*
  // in C and C++ languages, function's parameter variable 
  // can not be an array type

  void foo(int a[]);  
  // parameter variable's type is int* (pointer to int)

  // in C and C++ languages, function's return values type 
  // can not be an array type 
*/

/*
  // array decay
  // array to pointer conversion

  // when an array's idenfier is used in an expression,
  // the array identifier is converted to the address of its first element
  // except some exceptions

  // bir dizinin ismi(identifier), bir ifade içinde kullanıldığında
  // bazı istisnalar haricinde derleyici tarafından 
  // o dizinin ilk elemanının adresine dönüştürülür

  int main(void){
    int arr[10];

    arr;  // &arr[0];
  }
*/

/*
  // expression which have been created with an address operator
  // are R value expressions
  int main(void){
    int a_arr[10];
    int b_arr[10];

    a_arr = b_arr;            // syntax error
    // error: assignment to expression with array type
    &a_arr[0] = b_arr;        // syntax error
    // error: lvalue required as left operand of assignment

    // Those 2 lines are same

    // a_arr becomes an R value expression, when array decay occurs
  }
*/

/*
  int main(void){
    int a[10];    
    // int a[10] is not an expression it is a declaration
    a[5];         
    // a[5] is an expression


    int b[10];    
    // [] token in this declaration is not an operator, it is declarator
    b[5];         
    // [] token in this expression is an operator(subscript operator)


    int x = 10;
    int* ptr = &x;  
    // int* ptr is a declaration, * token is a declarator
    *ptr = 20;      
    // *ptr is an expression, * token is an operator(dereference operator)
  }
*/

/*
  int main(void){
    int a[10];

    // a[0] is the 1st element of the array
    // a[1] is the 2nd element of the array
  }
*/

/*
  // how to reach an element in an array

  #define SIZE 100

  int main(void){
    int a[10];
    // a[0] ... a[9]

    double b[SIZE];
    // b[0] ... b[SIZE - 1]
  }
*/

/*
  int main(void){
    int a[10];
    int x = 5;
    int y = 10;
    int z = 45;

    a[x] = 7;   // 5 is VALID index for a array
    a[y] = 8;   // 10 is NOT VALID index for a array
    a[z] = 9;   // 45 is NOT VALID index for a array

    // no syntax error but undefined behavior(UB)
    // pointer error
  }
*/

/*
  int foo(void);

  int main(void){
    int a[10];

    a[foo()] = 5;
    // if foo() returns other than 0 to 9 
    // it will be undefined behavior(UB)
  }
*/

/*
  int main(void){
    int a[10];

    a[4]; // is an l value expression, corresponds to an object

    a[4] = 5;
    int x = a[4];
    ++a[4];
    a[4]--;
    scanf("%d", &a[4]);

    // [] operator is higher precedence than ++ and -- and = and & operators
    // [] operator have the highes precedence
    // check OPERATOR PRIORITY LIST in Operators Lesson
  }
*/

/*
  #define   SIZE  10  
  // using symbolic constant for array size

  int main(void){
    int a[SIZE];

    for (int i = 0; i < SIZE; ++i)
      a[i] = i;

    for (int i = 0; i < SIZE; ++i)
      printf("%d ", a[i]);

    return 0;
  }
*/

/*
                    ------------------------
                    | array initialization |
                    ------------------------
*/

/*
  #define  SIZE  10

  int main(void){
    int a[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    for (int i = 0; i < SIZE; ++i)
      printf("a[%d] = %d\n", i, a[i]);

    // output ->
    //  a[0] = 1
    //  a[1] = 3
    //  a[2] = 5
    //  a[3] = 7
    //  a[4] = 9
    //  a[5] = 11
    //  a[6] = 13
    //  a[7] = 15
    //  a[8] = 17
    //  a[9] = 19
  }
*/

/*
  int main(void){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // syntax error
    // error : too many initializer values

    int d[10] = {};                         // syntax error
    // error : expected an expression

    int b[10] = {1, 2, 3, 4, 5};            // VALID
    // b[5] ... b[9] have zero values
    // {1, 2, 3, 4, 5, 0, 0, 0, 0, 0}

    int c[10] = {0};                        // VALID
    // c[0] ... c[9] have zero values
    // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  }
*/

/*
  int main(void){
    int a[10] = {1, 2, 3, 4, 5,};   // trailing comma ","
    int a[10] = {1, 2, 3, 4, 5};   
    // Those 2 lines are same
  }
*/

/*
  int main(void){
    int a[] = {1, 2, 3, 4, 5};    // a's type is int[5]
    int b[5] = {1, 2, 3, 4, 5}; 
    // Those 2 lines are same
  }
*/

/*
                --------------------------------
                | designated initializer (C99) |
                --------------------------------
*/

/*
  #define SIZE 10

  int main(void){
    // 4 ==> 9
    // 2 ==> 13
    // 6 ==> 55

    int a[SIZE] = { [4] = 9, [2] = 13, [6] = 55 };
    // other elements have zero values

    for (int i = 0; i < SIZE; ++i)
      printf("a[%d] = %d\n", i, a[i]);

    // output ->
    //  a[0] = 0
    //  a[1] = 0
    //  a[2] = 13
    //  a[3] = 0
    //  a[4] = 9
    //  a[5] = 0
    //  a[6] = 55
    //  a[7] = 0
    //  a[8] = 0
    //  a[9] = 0
  }
*/

/*
  int main(void){
    int b[] = { [4] = 9, [2] = 13, [6] = 55 }; // b's type is int[7] 
    // array size is not specified 
    // size will be 7 because 
    // the largest index in designated initializer is 6
  }
*/

/*
  #define SIZE 10

  int main(void){
    int a[SIZE] = { [4] = 9, 77, [8] = 13, [6] = 55 };
    // after designated initializer, normal initializer is used 
    // check 77 after [4] = 9

    for (int i = 0; i < SIZE; ++i)
      printf("a[%d] = %d\n", i, a[i]);

    // output ->
    //  a[0] = 0
    //  a[1] = 0
    //  a[2] = 0
    //  a[3] = 0
    //  a[4] = 9
    //  a[5] = 77
    //  a[6] = 55
    //  a[7] = 0
    //  a[8] = 13
    //  a[9] = 0
  }
*/