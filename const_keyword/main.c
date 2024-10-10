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

/*
  int main(void)
  {
    int x = 10;
    int y = 20;

    const int* p = &x;

    // *p = 30;  // syntax error
    // error: assignment of read-only location '*p'

    // "p" is giving a promise that it will not let "x" to be changed


    x = 12; // VALID, assignment to x is not logic error 
    // x is not const qualified, so changing its value is expected.
  }
*/

/*
  int main(void)
  {
    const int x = 10;
    &x; 
    // "&x" is an expression, it's data type is "const int*"

    const int* ptr = &x;
    // "ptr" is an expression, its data type is "const int*"
  }
*/

/*
  int main(void)
  {
    const int a[4] = { 0 };

    a; // (array to pointer conversion)
    // "a" is an expression, its data type is "const int*" 
  }
*/

/*
  - conversion from T* to const T* is VALID
  - conversion from const T* to T* is INVALID(ub)
*/

/*
  int main(void)
  {
    const int x = 10;
    // x is const qualified so it cannot be changed

    int* ptr = &x;  
    // ptr is not giving a promise that it will not change "x"
    // undefine behavior(ub)
  }
*/

/*
  int main(void)
  {
    int x = 5;
    // x is not const qualified so it can be changed

    const int* ptr = &x;  // VALID -> no logic, or syntax error 
    // ptr is giving a promise that it will not change "x"
  }
*/

/*
  int main(void)
  {
    // --------------------------------------------------------

    const int x = 5;
    const int* p = &x;  
    // p is giving a promise that it will not change "x"
    // x is const qualified so it cannot be changed
    // VALID (const int* ==> const int*)

    // --------------------------------------------------------

    const int y = 10;
    int* q = &y;
    // y is const qualified so it cannot be changed
    // q is not giving a promise that it will not change "y"
    // INVALID (can cause ub) (const int* ==> int*)

    // warning: initialization discards 'const' qualifier 
    // from pointer target type

    // --------------------------------------------------------

    int z = 5;
    const int* r = &z;
    // r is giving a promise that it will not change "z"]
    // z is not const qualified so it can be changed
    // VALID (int* ==> const int*)

    // --------------------------------------------------------
  }
*/

/*
  int main(void)
  {
    const int a[] = { 1, 2, 3, 4, 5 };
    const int* p = a;
    // VALID (const int* ==> const int*)

    int *q = a;
    // INVALID (const int* ==> int*)
  }
*/

/*
  - there are some scenarios that conversion from (const T* ==> T*) 
    needs to be done. In those scenarios we will be use typecast 
    operator. (const cast)
*/

/*
  int main(void)
  {
    int x = 45;
    const int* c_ptr = &x;


    int* ptr = (int*)c_ptr; 
    // conversion from (const int* ==> int*) with typecast operator

    // "x" is not const qualified, change in its value is valid.
    // normally "c_ptr" is giving a promise that it will not change "x"

    // When we initialize "ptr"(int*) with "c_ptr(const int*)",
    // we are initializing "ptr" with x's address.

    // Becuase "x" is not const qualified,
    // for "ptr" to change "x" is perfectly valid.
  }
*/