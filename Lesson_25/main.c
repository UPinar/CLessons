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

/*
  #include "utility.h"

  #define SIZE 50

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
  }  
  // output ->
  //   30  99 374 755 285 119 467 875 278 943
  //  903 813 451 248 265 424 621 177 179 137
  //   78 153 963 684   1 719 521   3 269 593
  //  562 349 862 697 565 520 412 781 804 226
  //  768 654 181 340 980 100 241 313 746 623
  //  ---------------------------------------
*/

/*
  // write a code that prints sum 

  #include "utility.h"

  #define SIZE 50

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    int sum = 0;
    for (int i = 0; i < SIZE; ++i)
      sum += a[i];

    printf("sum = %d\n", sum);
    // output -> sum = 27178 (can be change because of randomize)

    // if sum's value will be greater than int's max value
    // it will cause undefined behavior(UB) [Tanımsız Davranış]

    // O(n) complexity
  }
*/

/*
  // write a code that prints mean 

  #include "utility.h"

  #define SIZE 50

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);

    int sum = 0;
    for (int i = 0; i < SIZE; ++i)
      sum += a[i];

    printf("mean = %f\n", (double)sum / SIZE);
    // mean = 551.240000
  }
*/

/*
  // write a code that prints standard deviation

  #include "utility.h"
  #include <math.h>

  #define SIZE 50

  int main(void){
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);

    int sum = 0;

    for (int i = 0; i < SIZE; ++i)
      sum += a[i];

    double mean = (double)sum / SIZE;
    double sum_square = 0.;

    for (int i = 0; i < SIZE; ++i)
      sum_square += (a[i] - mean) * (a[i] - mean);

    double std_dev = sqrt(sum_square / SIZE);
    printf("standart deviation = %f\n", std_dev);
    // output -> standart deviation = 263.529259

    // O(n * 2) -> O(n) complexity
  }
*/

/*
  // mean of the odd elements in an array

  #include "utility.h"

  #define SIZE 50

  int main(void){
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);

    int sum_odd = 0;
    int count_odd = 0;

    for (int i = 0; i < SIZE; ++i){
      if (a[i] % 2 != 0){
        sum_odd += a[i];
        ++count_odd;
      }
    }

    // printf("mean of the odd elements = %f\n", (double)sum_odd / count_odd);

    // if there is no odd element in the array
    // if count_odd will be 0, it was divided by 0
    // it will cause undefined behavior(UB) [Tanımsız Davranış]


    if (count_odd)
      printf("mean of the odd elements = %f\n", (double)sum_odd / count_odd);
    else
      printf("there is no odd element in the array\n");

    // output -> mean of the odd elements = 470.692308
    // O(n) complexity
  }
*/

/*
  // max_element and its index in an array

  #include "utility.h"

  #define SIZE 20

  int main(void){
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int max = a[0];
    int max_index = 0;

    for (int i = 1; i < SIZE; ++i){
      if (a[i] > max){
        max = a[i];
        max_index = i;
      }
    }

    printf("max element = %d max elements index = %d\n", max, max_index);
    // output ->
    //  156 171 258 442 164 680 195 753 694 714
    //  197 197 227 138 501 369 328 933 705 630
    //  ---------------------------------------
    //  max element = 933 max elements index = 17
  }
*/

/*
  // minmax_element of an array

  #include "utility.h"

  #define SIZE 20

  int main(void){
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int min = a[0];
    int max = a[0];


    for (int i = 1; i < SIZE; ++i){
      if (a[i] > max)
        max = a[i];
      else if (a[i] < min)
        min = a[i];
    }

    printf("min element = %d\n", min);
    printf("max element = %d\n", max);
    // output ->
    //  554 757 231 815 590 221 466  74 492 314
    //  152 571 426 174 200 696 323 586 445 824
    //  ---------------------------------------
    //  min element = 74
    //  max element = 824
  }
*/

/*
  // max and the runner-up element of an array

  #include "utility.h"

  #define SIZE 30

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int max = a[0];
    int runner_up = a[1];

    if (a[0] < a[1]){
      max = a[1];
      runner_up = a[0];
    }

    for (int i = 2; i < SIZE; ++i){
      if (a[i] > max){
        runner_up = max;
        max = a[i];
      }
      else if (a[i] > runner_up)
        runner_up = a[i];
    }

    printf("max element = %d\n", max);
    printf("runner-up element = %d\n", runner_up);
    // output ->
    //   50 559 790 764  73 423 177 870 160 547
    //  947 977 719 983 131 686 732 194 947 451
    //  61 786  80 448 693 473 527 466  28 231
    //  ---------------------------------------
    //  max element = 983
    //  runner-up element = 977
  }
*/


/*
  // HOMEWORK
  // Write a code that prints unique elements in an array
  // complexity O(n)

  #include "utility.h"
  #include <stdlib.h>
  #include <string.h>

  #define SIZE 1000

  int main(void){
    int arr[SIZE];

    randomize();

    for (int i = 0; i < SIZE; ++i){
      arr[i] = rand() % 500;
    }

    int uniqueArr[SIZE];
    int notUniqueArr[SIZE];

    memset(uniqueArr, -1, SIZE * sizeof(int));
    memset(notUniqueArr, -1, SIZE * sizeof(int));

    unsigned int flag_unique = 0;
    int element; 

    for (int i = 0; i < SIZE; ++i){
      flag_unique = 0;
      element = arr[i];

      // element is not unique and already inside notUniqueArr 
      // flag_unique = 1
      for (int j = 0; j < SIZE; ++j){
        if (notUniqueArr[j] == -1) 
          break;
        else if (notUniqueArr[j] == element){
          flag_unique = 1;  
          break;
        }
      }

      // element is not unique and exists inside uniqueArr
      // flag_unique = 2;
      for (int j = 0; j < SIZE; ++j){
        if (uniqueArr[j] != -1 && uniqueArr[j] == element){
          flag_unique = 2;  
          break;
        }
      }

      switch (flag_unique)
      {
      case 0:
        for (int k = 0; k < SIZE; ++k){
          if (uniqueArr[k] == -1){
            uniqueArr[k] = element;
            break;
          }
        }
        break;
      case 1:
        break;
      case 2:
        for (int k = 0; k < SIZE; ++k){
          if (uniqueArr[k] == element){
            uniqueArr[k] = -1;
            break;
          }
        }
        for (int k = 0; k < SIZE; ++k){
          if (notUniqueArr[k] == -1){
            notUniqueArr[k] = element;
            break;
          }
        }
        break;
      }
    }

    // print unique values 
    for (int i = 0; i < SIZE; ++i){
      if (uniqueArr[i] != -1)
        printf("%d ", uniqueArr[i]);
    }
  }
*/

/*
  // searching an element in an array

  #include "utility.h"
  #define SIZE 20

  // complexity of linear search agorithm is O(n)
  void linear_search(const int* pa, int key){
    int i;
    for (i = 0; i < SIZE && pa[i] != key; ++i)
      ; // null statement

    if (i < SIZE)
      printf("found, index = %d\n", i);
    else
      printf("not found\n", key);
  }

  int main(void){
    int a[SIZE];
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //   41 467 334 500 169 724 478 358 962 464
    //  705 145 281 827 961 491 995 942 827 436
    //  --------------------------------------- 

    int key = 334;
    linear_search(a, key);
    // output -> found, index = 2

    int key_2 = 100;
    linear_search(a, key_2);
    // output -> key = 100 not found

    int key_3 = 436;
    linear_search(a, key_3);
    // output -> found, index = 19
  }
*/

/*
  #include "utility.h"
  #include <stdlib.h>

  #define URAND_MAX  20

  // when this function is called, it will generate [0 - URAND_MAX) 
  // unique rand
  // this function can only be generated URAND_MAX unique random numbers
  // if there is not any unique number, it will return -1
  int urand(void){
    static _Bool flagsArr[URAND_MAX];
    static int count = 0;

    if (count == URAND_MAX)
      return -1;

    int elem;

    //// <---- WAY 1 --->
    // for(;;){
    //   elem = rand() % URAND_MAX;
    //   if (flagsArr[elem] == 0)
    //     break;
    // }

    //// <---- WAY 2 --->
    while (flagsArr[elem = rand() % URAND_MAX])
      ;

    flagsArr[elem] = 1;
    ++count;
    return elem;
  }

  int main(void){
    randomize();

    for (int i = 0; i < URAND_MAX; ++i)
      printf("%d ", urand());

    printf("%d", urand());

    // output -> 14 1 9 2 8 7 10 17 13 0 15 4 5 3 18 6 16 12 11 19 -1
  }
*/

/*
  // reverse algorithm

  #include "utility.h"

  #define SIZE  20

  int main(void){
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output ->
    //  196 465  79 466 368 678 792 276 690 736
    //  597  39 629 522 783  22   9 999 831 116

    for (int i = 0; i < SIZE / 2; ++i){
      int temp = a[i];
      a[i] = a[SIZE - 1 - i];
      a[SIZE - 1 - i] = temp;
    }

    print_array(a, SIZE);
    // output ->
    //  116 831 999   9  22 783 522 629  39 597
    //  736 690 276 792 678 368 466  79 465 196
  }
*/

/*
  // output should be
  // 4 9 8 13 19 7 18 7 9 13
  // ****
  // ********* 
  // ******** 
  // *************
  // ******************* 
  // *******
  // **************** 
  // ******* 
  // ********* 
  // ************* 

  #include "utility.h"
  #include <stdlib.h>

  #define   SIZE  10

  int main(void){
    int a[SIZE];
    randomize();

    for (int i = 0; i < SIZE; ++i){
      a[i] = rand() % 20 + 1;
      printf("%d ", a[i]);
    }
    printf("\n");

    // <---- WAY 1 --->
    // for (int i = 0; i < SIZE; ++i){
    //   for (int j = 0; j < a[i]; ++j)
    //     putchar('*');
    //   putchar('\n');
    // }

    // <---- WAY 2 ---> 
    // (if there is no problem with changing array element's values)

    for (int i = 0; i < SIZE; ++i){
      while(a[i]--)
        putchar('*');
      putchar('\n');
    }
  }
*/

/*
  // HOMEWORK <---- check homework_2.png ---> 
  #include "utility.h"

  #define   SIZE  20

  int main(void){
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    print_array(a, SIZE);

    // for (int i = 0; i < SIZE; ++i){
    //   a[i] = rand() % 20 + 1;   

    unsigned int max_elem = 20;

    while (max_elem--)
    {
      for (int i = 0; i < SIZE; ++i){
        if (a[i] > max_elem){
          putchar('*');
        }
        else
          putchar(' ');
      }

      if (max_elem)
        putchar('\n');
    }
  }
*/


