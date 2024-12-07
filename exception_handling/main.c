#include <stdio.h>

/*
                      ======================
                      | Exception Handling |
                      ======================
*/

/*
  - programming errors (writing wrong code)
    assertions is being used for this type of errors.
    - static assertions (compile-time assertions)
    - dynamic assertions (runtime assertions)

  - runtime errors (exception)
*/

/*
                      ---------------------
                      | static assertions |
                      ---------------------
*/

/*
  // before _Static_assert, some tricks is being used.
  // ------------------------------------------------------

  int arr2[sizeof(int) > 4];          // error
  // warning: ISO C forbids zero-size array 'arr2' 
  // if the condition is true, an array will be declared.

  typedef int xyz_[sizeof(int) > 4];  // error
  //  warning: ISO C forbids zero-size array 'xyz_'
  // if the condition is true, only a typedef will be declared.
  // better than the previous one.
*/

/*
  // for the program to work without problem, 
  // int type's size must be greater than 2 bytes.
  // this information can be obtained in compile-time.

  int main(void)
  {
    _Static_assert( sizeof(int) > 2, 
                  "int type's size must be greater than 2 bytes.");
    // holds

    _Static_assert( sizeof(int) > 4, 
                  "int type's size must be greater than 4 bytes.");
    // error: static assertion failed: 
    // "int type\'s size must be greater than 4 bytes."
  }
*/

/*
                      ----------------------
                      | dynamic assertions |
                      ----------------------
*/

/*
  // for the program to run without problem, 
  // the return value of a function must be different from 0.
  // this information can be obtained in runtime.

  #include <assert.h> // assert macro

  int func1(void)
  {
    return 5;
  }

  int func2(void)
  {
    return 0;
  }

  int main(void)
  {
    int x = 11;

    int y = func1();
    assert(y != 0);

    y = func2();
    assert(y != 0);
    // Assertion failed: y != 0, file main.c, line 77

    int a = x / y;
    // if y is 0, it will be an undefined behavior.
  }
*/

/*
  // for the program to run without problem,
  // argument passed to a function must be different from NULL
  // this information can be obtained in runtime.

  #include <assert.h> // assert

  void func(int* ptr)
  {
    assert(ptr != NULL);
    // Assertion failed: ptr != NULL, file main.c, line 100
  }

  int main(void)
  {
    func(NULL);
  }
*/
