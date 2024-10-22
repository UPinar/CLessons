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
  #include "nutility.h"

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

  #include "nutility.h"

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

  #include "nutility.h"

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

  #include "nutility.h"
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

  #include "nutility.h"

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

  #include "nutility.h"

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

  #include "nutility.h"

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

  #include "nutility.h"

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

  #include "nutility.h"
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

  #include "nutility.h"
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
  #include "nutility.h"
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

  #include "nutility.h"

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

  #include "nutility.h"
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
  #include "nutility.h"

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

/*
  HOMEWORK - Maximum Subsequence Sum Problem - O(n) complexity

  // subsequence ->
  // 526 523  45 427
  // 427
  // 427 514
  // 323 317 982
  // 526 523  45 427 514  18  42 323 317 982 (whole array also subsequence)
  // 526 523 514 -> this is not a subsequence

  // minimum 1 negative number is guaranteed in the array
*/

/*
  #include "nutility.h"
  #include <stdlib.h>
  #include <limits.h>

  #define   SIZE  10

  int set_sum_max(int* sum_max, int a, int b, int c){
    int sum_total = a + b + c;

    if (*sum_max < sum_total)
      *sum_max = sum_total;
  }

  int max_subsequence_sum(const int* pa, int size){
    int sum_first = 0;
    int sum_second = 0;
    int negative_val = 0;
    int sum_max = INT_MIN;
    
    int is_first_negative_appeared = 0;

    for (int i = 0; i < size; ++i){
      if (is_first_negative_appeared)
      {
        if (pa[i] < 0){
          set_sum_max(&sum_max, sum_first, sum_second, negative_val);

          sum_first = sum_second;
          sum_second = 0;
          negative_val = pa[i];
        }
        else{
          sum_second += pa[i];
        } 
      }
      else {
        if (pa[i] < 0){  
          negative_val = pa[i];
          is_first_negative_appeared = 1;
        }
        else
          sum_first += pa[i];
      }

      // check if it is the last element
    	if (i == SIZE - 1)
        set_sum_max(&sum_max, sum_first, sum_second, negative_val);
    }

    return sum_max;
  }

  int main(void){

    int a[SIZE];

    randomize();

    int is_negative_exist = 0;
    for (int i = 0; i < SIZE; ++i){
      a[i] = (rand() % 2 ? 1 : -1) * (rand() % 1000);

      // make sure that there is at least 1 negative number in the array
      if (is_negative_exist == 0 && a[i] < 0)
        is_negative_exist = 1;

      if (is_negative_exist == 0 && i == SIZE - 1 && a[i] > 0) {
        printf("There is no negative number in the array\n");
        a[i] = rand() % 1000 * -1;
      }
    }

    print_array(a, SIZE);
    int max_sum = max_subsequence_sum(a, SIZE);
    printf("max subsequence sum = %d\n", max_sum);

    // output ->
    //  223 -702 463 -71 991 -973 -21 -985 701 645
    //  ---------------------------------------
    //  max subsequence sum = 1383
  }
*/

/*
  HOMEWORK - Partition Algorithm - O(n) complexity

  // evens at the beginning, odds at the end
  // 526 523  45 427 514  18  42 323 317 982
  // 526 514  18  42 982  45 427 323 317 523
  //                       *  
  // return the partition point(first odd number's index)
*/

/*
  #include "nutility.h"

  #define SIZE 10

  // CHATGPT answer
  int partition(int* pa, int size){
    int i = 0;
    int j = size - 1;

    while (i < j){
      while (i < size && pa[i] % 2 == 0)
        ++i;

      while (j >= 0 && pa[j] % 2 != 0)
        --j;

      if (i < j){
        int temp = pa[i];
        pa[i] = pa[j];
        pa[j] = temp;
      }
    }

    return i;
  }

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int partition_idx = partition(a, SIZE);
    printf("partition index = %d\n", partition_idx);

    print_array(a, SIZE);
  }
*/

/*
  HOMEWORK - Donald Knuth Question
  // find a code that does only 2 operations in the loop

  #include "nutility.h"

  #define   SIZE  20

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int key;
    printf("Enter a value for search: ");
    scanf("%d", &key);

    int i;
    for (i = 0; i < SIZE; ++i)
      if (a[i] == key)
        break;

    // There are 3 operations in this loop 
    // 1. i < SIZE
    // 2. a[i] == key
    // 3. ++i

    if (i < SIZE)
      printf("found, index = %d\n", i);
    else
      printf("not found\n", key);

    return 0;
  }
*/

/*
              -----------------------------------------------
              | sorting algorithms (sıralama algoritmaları) |
              -----------------------------------------------
*/

/*
  -----------------------------------------------------------------------
  sıralama(sorting) : bir kritere bağlı olarak, kriteri gerçekleştirecek 
  şekilde dizinin elemanlarını yeniden konumlandırmak.

  - sıralama algoritması ile sıralama kriteri(sorting criteria) 
    birbirleriyle karıştırılmamalıdır.
  - farklı sıralama algoritmaları aynı sıralama kriteri ile kullanılabilir.
  - aynı sıralama algoritması farklı sıralama kriterleri ile farklı 
  sıralamalar yapabilir.

   5  7  -4  6  -9   2   3  -1
   ---------------------------
  -9 -4  -1  2   3   5   6   7   (ascending order)
  -1  2   3 -4   5   6   7  -9   (ascending order of absolutes)
  same algorithm, different sorting criteria


  -----------------------------------------------------------------------
  - best case scenario, average case scenario, worst case scenario
  quick sort -> 
    O(n log n)  best
    O(n log n)  average
    O(n^2)      worst

  selection sort -> 
    O(n^2)      best
    O(n^2)      average
    O(n^2)      worst

  insertion sort -> 
    O(n)        best
    O(n^2)      average
    O(n^2)      worst

  those notations are computational complexity.

  -----------------------------------------------------------------------
  memory complexity : 
    bubble sort algorithm is only using the array itself
    but some algorithms are using extra memory space (1 more array size)

  -----------------------------------------------------------------------
  3 5 7 9 12 18 45 42 57 68 90 (almost sorted)
                 x  x 

  - two algorithms complexity can be same but in some scenarios like
    almost sorted array above, one algorithm can sort it in best case
    but the other one can sort it in worst case
  - complexity is not the only criteria to choose an algorithm
  -----------------------------------------------------------------------
  sıralama algoritmasının stable olup olmaması 

    23 Ahmet
  35 Mehmet
  16 Hüsnü
    23 Gizem
  55 İhsan
    23 Turgut
  48 Halime
    23 Necati
  18 Yeşim
  5  Hakan

  unstable sort -> (relative positions(izafi konumları) are not preserved)
  -----------------
    5  Hakan
    16 Hüsnü
    18 Yeşim
      23 Turgut
      23 Necati
      23 Gizem 
      23 Ahmet
    35 Mehmet
    48 Halime
    55 İhsan

  stable sort -> (relative positions(izafi konumları) are preserved)
  -----------------
      5  Hakan
    16 Hüsnü
    18 Yeşim
      23 Ahmet
      23 Gizem
      23 Turgut           
      23 Necati                       
    35 Mehmet
    48 Halime
    55 İhsan

  558 330 761 538 574 996 551 613 467 909   // even-odd partition
  558 330 538 574 996 761 551 613 467 909   // partition is stable
  -----------------------------------------------------------------------
*/

/*
  Bubble Sort
  -------------
  909 558 330 761 538 574 996 551 613 467   - comparison : 909 - 558
  558 909 330 761 538 574 996 551 613 467   - comparison : 909 - 330
  558 330 909 761 538 574 996 551 613 467   - comparison : 909 - 761
  558 330 761 909 538 574 996 551 613 467   - comparison : 909 - 538
  558 330 761 538 909 574 996 551 613 467   - comparison : 909 - 574  
  558 330 761 538 574 909 996 551 613 467   - comparison : 909 - 996
  558 330 761 538 574 909 551 996 613 467   - comparison : 996 - 551
  558 330 761 538 574 909 551 613 996 467   - comparison : 996 - 613
  558 330 761 538 574 909 551 613 467 996   - comparison : 996 - 467  
  
  - 996(1 element) is in its place (n - 1) comparison has been done 
  - (n - 1) elements more to be sorted
  - total = (n - 1) * (n - 1) comparison will be done
  - O(n^2) complexity

  558 330 761 538 574 909 551 613 467 996   - comparison : 558 - 330
  330 558 761 538 574 909 551 613 467 996   - comparison : 558 - 761
  330 558 538 761 574 909 551 613 467 996   - comparison : 761 - 538
  330 558 538 574 761 909 551 613 467 996   - comparison : 761 - 574
  330 558 538 574 761 909 551 613 467 996   - comparison : 761 - 909
  330 558 538 574 761 551 909 613 467 996   - comparison : 909 - 551
  330 558 538 574 761 551 613 909 467 996   - comparison : 909 - 613
  330 558 538 574 761 551 613 467 909 996   - comparison : 909 - 467
  (330 558 538 574 761 551 613 467 909 996   - comparison : 909 - 996)

  after 2'nd iteration done we don't need to compare 909 with 996 again
  ...
*/

/*
  #include "nutility.h"

  #define   SIZE  100

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    for (int i = 0; i < SIZE - 1; ++i){
      for (int k = 0; k < SIZE - 1 - i; ++k){
        // buble sort algorithm ascending order
        if (a[k] > a[k + 1]){
          int temp = a[k];
          a[k] = a[k + 1];
          a[k + 1] = temp;
        }

        // buble sort algorithm descending order (different sorting criteria)
        // if (a[k] < a[k + 1]){
        //    int temp = a[k];
        //    a[k] = a[k + 1];
        //    a[k + 1] = temp;
        //  }
      }
    }

    print_array(a, SIZE);
  }
*/

/*
  #include "nutility.h"
  #include <stdlib.h>
  #include <math.h>

  #define   SIZE  10

  void set_array_random_include_negatives(int* pArr, int size){
    while (size--)
      *pArr++ = (rand() % 2 ? 1 : -1) * (rand() % 1000);
  }

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random_include_negatives(a, SIZE);
    print_array(a, SIZE);
    // output -> -49 327 789  35 717 -118 840  58 458 -715

    for (int i = 0; i < SIZE - 1; ++i){
      for (int k = 0; k < SIZE - 1 - i; ++k){
        if (abs(a[k]) > abs(a[k + 1])){
          int temp = a[k];
          a[k] = a[k + 1];
          a[k + 1] = temp;
        }
      }
    }

    print_array(a, SIZE);
    // output -> 35 -49  58 -118 327 458 -715 717 789 840
  }
*/

/*
  // sorting criteria : 
  //  odd numbers at the beginning, even numbers at the end
  //  odds and evens are sorted in ascending order

  #include "nutility.h"

  #define   SIZE  10

  int main(void){
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);
    // output -> 607 732 147 322 782 647 477 380 872  79

    for (int i = 0; i < SIZE - 1; ++i){
      for (int k = 0; k < SIZE - 1 - i; ++k){
        if (  (a[k] % 2 == 0 && a[k + 1] % 2 == 1) ||
              (a[k] % 2 == a[k + 1] % 2 && a[k] > a[k + 1]))
        {
          int temp = a[k];
          a[k] = a[k + 1];
          a[k + 1] = temp;
        }
      }
    }

    print_array(a, SIZE);
    // output ->  79 147 477 607 647 322 380 732 782 872
  }
*/

/*
  #include "nutility.h"
  #include <stdlib.h>
  #include <time.h>

  #define   SIZE    50000000

  // bubble sort algorithm
  // O(n^2) -> 10'000 elements    : 0.158000 seconds
  // O(n^2) -> 100'000 elements   : 22.783000 seconds
  // O(n^2) -> 1'000'000 elements : 22sec * 100 / 60 = 36.67 minutes (guess)
  // O(n^2) -> 5'000'000 elements : 36.67 * 25  / 60 =  15.28 hours (guess)

  // O(n log n) -> 5'000'000 elements   : 0.351000 seconds
  // O(n log n) -> 50'000'000 elements  : 3.419000 seconds


  int icmp(const void* vp1, const void* vp2){
    return *(const int*)vp1 - *(const int*)vp2;
  }

  int main(void){
    // memory allocation on heap segment
    int* p = (int*)malloc(SIZE * sizeof(int));
    if (!p){
      printf("memory allocation failure\n");
      return 1;
    }

    set_array_random(p, SIZE);

    clock_t start = clock();

    // bubble sort algorithm O(n^2)
    // for (int i = 0; i < SIZE - 1; ++i){
    //   for (int k = 0; k < SIZE - 1 - i; ++k){
    //     if (p[k] > p[k + 1]){
    //       int temp = p[k];
    //       p[k] = p[k + 1];
    //       p[k + 1] = temp;
    //     }
    //   }
    // }

    // O(n log n) algorithm
    qsort(p, SIZE, sizeof(int), icmp);

    clock_t end = clock();

    printf( "sorting end %f seconds\n", 
            (double)(end - start) / CLOCKS_PER_SEC);

    free(p);
  }
*/

/*
  merge algorithm O(n)

    | index a
   61 243 293 451 524 797 814 832 845 965

   194 347 365 382 416 469 529 532 630 754
    | index b

  a bittiyse b'den yaz, b bittiyse a'dan yaz,
  ikisi de bitmemişse küçüğü yaz
*/

/*
  #include "nutility.h"

  #define   SIZE    10 

  int main(void){
    int a[SIZE];
    int b[SIZE];
    int c[2 * SIZE];

    randomize();
    set_array_random(a, SIZE);
    set_array_random(b, SIZE);
    sort_array(a, SIZE);
    sort_array(b, SIZE);

    print_array(a, SIZE);
    // output -> 110 185 265 269 305 318 330 333 478 693
    print_array(b, SIZE);
    // output ->   3 204 373 491 545 692 707 768 781 888

    // merge algorithm

    int idx_a = 0;
    int idx_b = 0;

    for(int i = 0; i < 2 * SIZE; ++i){
      if (idx_a == SIZE)
        c[i] = b[idx_b++];
      else if (idx_b == SIZE)
        c[i] = a[idx_a++];
      else if (a[idx_a] < b[idx_b])
        c[i] = a[idx_a++];
      else
        c[i] = b[idx_b++];
    }

    print_array(c, 2 * SIZE);  
    // output ->
    //    3 110 185 204 265 269 305 318 330 333
    //  373 478 491 545 692 693 707 768 781 888
  }
*/

/*
  binary search : O(log n)

  //  61 243 293 451 524 797 814 832 845 965
  //  | index_first                       | index_last
*/

/*
  #include "nutility.h"

  #define   SIZE    10 

  int main(void){
    int a[SIZE];

    set_array_random(a, SIZE);
    sort_array(a, SIZE);
    print_array(a, SIZE);

    int key;
    printf("Enter a value for search: ");
    scanf("%d", &key);

    int idx_first = 0;
    int idx_last  = SIZE - 1;
    int idx_mid;

    while(idx_first <= idx_last){
      idx_mid = (idx_first + idx_last) / 2;

      if (a[idx_mid] == key)
        break;

      if(a[idx_mid] > key)
        idx_last = idx_mid - 1;
      else
        idx_first = idx_mid + 1;
    }

    if (idx_first > idx_last)
      printf("not found\n");
    else
      printf("found, index = %d\n", idx_mid);

    // output ->
    //  41 169 334 358 464 467 478 500 724 962
    //  ---------------------------------------
    //  Enter a value for search: 962
    //  found, index = 9

    //  41 169 334 358 464 467 478 500 724 962
    //  ---------------------------------------
    //  Enter a value for search: 982
    //  not found
  }
*/

/*
  #include "nutility.h"

  #define   SIZE    200 

  int main(void){
    int a[SIZE];

    set_array_random(a, SIZE);
    sort_array(a, SIZE);

    int key = 2222; // not in the array [0-1000)

    int idx_first = 0;
    int idx_last  = SIZE - 1;
    int idx_mid;
    int count = 0;

    while(idx_first <= idx_last){
      ++count;
      idx_mid = (idx_first + idx_last) / 2;

      if (a[idx_mid] == key)
        break;

      if(a[idx_mid] > key)
        idx_last = idx_mid - 1;
      else
        idx_first = idx_mid + 1;
    }

    printf("size = %d, count = %d\n", SIZE, count);
    // output -> size = 100, count = 7
    // output -> size = 200, count = 8
    // output -> size = 2000, count = 11
    // output -> size = 4000, count = 12
  }
*/

/*
                  ----------------------------
                  | multi-dimensional arrays |
                  ----------------------------
*/

/*
  #include "../nutility.h"

  int main(void)
  {
    int arr[10];  
    // arr's element type is int

    size_t arr_size = asize(arr);
    printf("arr_size = %zu\n", arr_size);
    // output -> arr_size = 10

    int md_arr[10][20];
    // md_arr's element type is int[20]

    size_t md_arr_size = asize(md_arr);
    printf("md_arr_size = %zu\n", md_arr_size);
    // output -> md_arr_size = 10
  }
*/

/*
  int main(void)
  {
    // elemanları double[5] türünden olan 10 elemanlı bir dizi
    double md_arr[10][5];

    // elemenalar char*[20] türünden olan 5 elemanlı bir dizi
    char* md_arr2[5][20];
  }
*/

/*
  int main(void)
  {
    int arr[10][20];

    for(int i = 0; i < 10; ++i)
      arr[i]; 
    // döngünün her turunda arr[i] int[20] türünden farklı dizi olacak
  }
*/

/*
  typedef int INT_ARR20[20];

  int main(void)
  {
    // ----------------------------------------------

    int arr_1[10][20];
    INT_ARR20 arr_2[10];
    // Those 2 lines are equivalent.

    // ----------------------------------------------

    INT_ARR20 arr_3[11], arr_4[22];

    int arr_5[11][20];  // arr_3 and arr_5 are equivalent
    int arr_6[22][20];  // arr_4 and arr_6 are equivalent

    // ----------------------------------------------
  }
*/

/*
  int main(void)
  {
    int arr[5];   
    // "arr"'s data type is int[5]
    // "arr"'s element's type is int

    int md_arr[4][8];
    // "md_arr"'s data type is int[4][8]
    // "md_arr"'s element's type is int[8]
  }
*/

/*
  int main(void)
  {
    int arr_1[10];
    int arr_2[10];
    int arr_3[10];
    int arr_4[10];
    int arr_5[10];
    // arr_1 to arr_5 are not guaranteed to be contiguous in memory.


    int md_arr[5][10];
    // md_arr's element's(int[10]) are contiguous in memory.
  }
*/

/*
  int main(void)
  {
    int md_arr[5][10];

    printf("sizeof(md_arr) = %zu\n", sizeof(md_arr));
    // output -> sizeof(md_arr) = 200

    printf("sizeof(md_arr[0]) = %zu\n", sizeof(md_arr[0]));
    // output -> sizeof(md_arr[0]) = 40

    printf("sizeof(md_arr[0][0]) = %zu\n", sizeof(md_arr[0][0]));
    // output -> sizeof(md_arr[0][0]) = 4
  }
*/

/*
  #include "../nutility.h"

  int main(void)
  {
    int md_arr[5][10];

    printf("%zu\n", asize(md_arr));     // output -> 5
    // 5 elemanlı, elemanları int[10] türünden olan bir dizi

    printf("%zu\n", asize(md_arr[0]));  // output -> 10
    // 10 elemanlı, elemanları int türünden olan bir dizi
  }
*/

/*
  // We need to hold the grades of each student
  // There are 5 schools 
  // each school has 8 classes 
  // each class has 20 students

  int main(void)
  {
    int grades[5][8][20];
  }
*/
