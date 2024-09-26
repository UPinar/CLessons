#include <stdio.h>

/*
                      =================
                      | const keyword |
                      =================
*/

/*
  -> variable can be mutable(değişebilir) or immutable(değişmez).
  qualifier : niteleyici
*/

/*
  int main()
  {
    int x = 10;         // mutable variable
    const int y = 20;   // immutable variable
  }

  // compiled by x86-64 clang 19.1.0 -std=c11 -O0
  //  main:
  //  push rbp
  //  mov rbp, rsp
  //  mov dword ptr [rbp - 4], 10     : x = 10
  //  mov dword ptr [rbp - 8], 20     : y = 20
  //  xor eax, eax
  //  pop rbp
  //  ret
*/

/*
  int main(void)
  {
    const int y = 20;
    y = 50; // syntax error
    // error: assignment of read-only variable 'y'
  }
*/

/*
  int main()
  {
    const int y = 20;  
    // "y" is non-modifiable LValue expression
  }
*/

/*
  int main(void)
  {
    const int a[5] = {1, 2, 3, 4, 5};

    int x = a[3] + a[1];  // for reading purpose -> VALID
    a[2]++;               // for writing purpose -> syntax error
    // error: increment of read-only location 'a[2]'
  }
*/

/*
  int main(void)
  {
    int const x = 10; 
    const int y = 20;
    // const keyword can be placed 
    // before or after the data type
  }
*/

/*
  const int g_cint = 10;  // global constant variable

  void foo(void)
  {
    const int x = 76;           // local constant variable
    static const int y = 90;    // local static constant variable
  }
*/

/*
  
    - if variable is not supposed to be changed
*/

/*
  int main(void)
  {
    int daytabs[] = 
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // lookup table for days in month

    // If we did not make this array const qualified, 
    // code that change this array will NOT give any error
    // but be a logic error

    int mon = 1;
    daytabs[mon]++;   // valid but logic error


    const int daytabs_2[] = 
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    daytabs_2[mon]++;  // syntax error
    // error: increment of read-only location 'daytabs_2[mon]'
  }
*/

/*
  int main(void)
  {
    double pi = 3.14159265359;
    // pi is a constant so better be const qualified
  }
*/

/*
  Question : Why should we use const keyword?

  - when we try to change a variable that is not supposed to be changed
    will become a syntax error.
  - for people to read and understand what the code is doing
  - compiler can optimize the code better, 
    if it gets a guarantee that a variable will not change
*/

/*
  int main(void)
  {
    const int x = 10;

    int* ptr = (int*)&x;
    *ptr = 777;   // undefined behavior(ub)

    // attempting to change the value of a constant variable 
    // is undefined behavior
  }
*/

/*
  #define MAX 1000

  int main(void)
  {
    const int max = 1000;

    // compiler will not see an identifier named MAX, 
    // preprocessor will replace MAX with 1000
    // so MAX does not have any scope

    // max variable's address can be used 
    // but MAX does not have any address

    int arr_1[MAX] = {0};   // valid
    int arr[max] = { 0 };   // syntax error 

    // "max" is not a constant expression
  }
*/

/*
  void foo(int val)
  {
    const int cint_1 = 100;
    const int cint_2 = 200;
    const int cint_3 = 300;

    switch (val){
    case cint_1:;   // syntax error
    case cint_2:;   // syntax error
    case cint_3:;   // syntax error
    }
    //  error: case label does not reduce to an integer constant
  }
*/

/*
                      --------------------
                      | pointers & const |
                      --------------------
*/

/*
  // read from identifiers left to the line start
  int main(void)
  {
    int x = 10;

    int* const p1 = &x;    
    // const pointer to int
    // top-level const pointer  - right const

    const int* p2 = &x;   // pointer to const int
    int const* p3 = &x;   // pointer to const int
    // low-level const pointer  - left const 
    // Those 2 lines are equivalent

    const int* const p4 = &x;  // const pointer to const int
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 20;

    int* const c_ptr = &x;  // constant pointer to int

    // - Giving a promise that this pointer will not change
    // - pointer değişkenin değeri değişmeyecek sözünü veriyoruz.

    // - Not giving a promise that the variable it points to 
    //  will not change
    // - pointer'ın gösterdiği değişkenin değişmeyeceğine 
    //  dair bir söz vermiyoruz.

    *c_ptr = 30;  // valid

    c_ptr = &y;   // syntax error
    // error: assignment of read-only variable 'c_ptr'
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 20;

    const int* ptr = &x;  // pointer to const int
    // int const* ptr = &x;

    // - Giving a promise that the variable it points to will not change
    // - pointerin gösterdiği değişkenin değişmeyeceği sözünü veriyoruz.

    // - Not giving a promise that the pointer itself will not change
    // - pointer'ın değişmeyeceğine dair bir söz vermiyoruz.

    ptr = &y;   // valid

    *ptr = 30;  // syntax error
    // error: assignment of read-only location '*ptr'
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 20;

    const int* const ptr = &x;  // const pointer to const int

    // - Giving a promise that the variable it points to will not change
    // - pointerin gösterdiği değişkenin değişmeyeceği sözünü veriyoruz.

    // - Giving a promise that the variable it points to will not change
    // - pointerin gösterdiği değişkenin değişmeyeceği sözünü veriyoruz.

    ptr = &y;   // syntax error
    // error: assignment of read-only variable 'ptr'

    *ptr = 30;  // syntax error
    // error: assignment of read-only location '*(const int *)ptr'
  }
*/

/*
  void set(T* p);     
  // set function
  // setter
  // mutator

  void get*(const T* p);
  // get function
  // getter
  // accessor
*/

/*
  void printArray(const int* p, int size);
  - this function is telling that it will not change the array
*/

/*
  void printArray(int* p, int size){}

  int main(void)
  {
    const int daytabs[] = 
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printArray(daytabs, 13);
    // warning : passing argument 1 of 'printArray' discards 
    // 'const' qualifier from pointer target type
  }
*/