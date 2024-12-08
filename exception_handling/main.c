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

/*
  #include <stdlib.h>   // abort

  void foo(int* p_arr, int arr_size)
  {
    if (p_arr == NULL)
    {
      fprintf(stderr, "Error: p_arr is NULL\n");
      fprintf(stderr, "File: %s, Line: %d\n", __FILE__, __LINE__);
      abort();
    }

    // code line count will be increased.
    // hard to understand if this code is written for validation.
    // codes are for debugging purposes, but will increase the
    // compilation time.

    for (int i = 0; i < arr_size; ++i) 
      printf("%d ", p_arr[i]);
  }

  int main(void)
  {
    int arr[10] = { 0 };

    int* p = arr;
    p = NULL;

    foo(p, 10);
    // output ->
    //  Error: p_arr is NULL
    //  File: main.c, Line: 124
  }
*/

/*
  // one of implementation of ASSERT macro

  #ifndef NDEBUG      // NOT_DEBUG                                       
  #define ASSERT(EXPR) ((EXPR)                                  \
    ? (void)0                                                   \
    : (void)printf("Assertion failed: %s, file %s, line %d\n",  \
                    #EXPR, __FILE__, __LINE__),                 \
            abort())                                      
  #else
  #define ASSERT(EXPR) ((void)0)
  #endif
*/

/*
  #include <stdlib.h>   // abort

  #ifndef NDEBUG                                       
  #define ASSERT(EXPR) ((EXPR)                                  \
    ? (void)0                                                   \
    : (void)printf("Assertion failed: %s, file %s, line %d\n",  \
                    #EXPR, __FILE__, __LINE__),                 \
            abort())                                      
  #else
  #define ASSERT(EXPR) ((void)0)
  #endif

  int main(void)
  {
    int x = 5;
    ASSERT(x != 5);
    // output -> Assertion failed: x != 5, file main.c, line 167
  }
*/

/*
  #include <stdlib.h>   // abort

  #define NDEBUG  // to disable ASSERT macro

  #ifndef NDEBUG                                       
  #define ASSERT(EXPR) ((EXPR)                                  \
    ? (void)0                                                   \
    : (void)printf("Assertion failed: %s, file %s, line %d\n",  \
                    #EXPR, __FILE__, __LINE__),                 \
            abort())                                      
  #else
  #define ASSERT(EXPR) ((void)0)
  #endif

  int main(void)
  {
    int x = 5;
    ASSERT(x != 5); 
    // ASSERT(expression) ===> "(void)0"
    // "ASSERT(x != 5);" statement will become "(void)0;"
  }
*/

/*
  #include <assert.h>

  int main(void)
  {
    assert(5 != 5);
    // output -> Assertion failed: 5 != 5, file main.c, line 215
  }
*/

/*
  #define NDEBUG
  #include <assert.h>

  int main(void)
  {
    assert(5 != 5);
  }
*/

/*
  #include <assert.h>

  void set_month(int mon)
  {
    assert(mon > 0 && mon < 13);
  }

  int main(void)
  {
    set_month(15);
    set_month(0);
    // output -> 
    //  Assertion failed: mon > 13 && mon < 1, file main.c, line 258

    set_month(5); // holds
  }
*/

/*
  // assert macro is giving less information so 
  // it can be customized.

  #include <assert.h> 

  #define   ASSERT_MSG(MSG, EXPR)   assert((MSG, (EXPR)))
  // warning: left-hand operand of comma expression has no effect 

  int main(void)
  {
    int x = 0;

    ASSERT_MSG("value must be different from 0", x != 0);
    // output -> 
    // Assertion failed: 
    //  ("value must be different from 0", (x != 0)), 
    //  file main.c, line 260
  }
*/

/*
  // no guarantee that assert macro will be evaluated as 
  // true or false, so code that include side effect 
  // should not be used in assert macro.

  #include <assert.h>

  int main(void)
  {
    int count = 5;

    assert(--count > 0);

    // when NDEBUG is defined, assert macro will be disabled.
    // so if the logic is dependent on the count variable,
    // the program will not work as expected.
  }
*/

/*
  #include <assert.h>

  void foo(int x, double d)
  {
    assert(x > 0 && d < 4.5);   
  } 

  void better_foo(int x, double d)
  {
    assert(x > 0);
    assert(d < 4.5);
  }

  int main(void)
  {
    foo(3, 6.6);
    // output -> 
    //  Assertion failed: x > 0 && d < 4.5, file main.c, line 294
    // which condition failed can not be understood.

    better_foo(3, 6.6); 
    // output -> Assertion failed: d < 4.5, file main.c, line 300
  }
*/

/*
  - eğer bir fonksiyon üstlendiği işi yapamadığında 
    kendisini çağıran fonksiyona bir şekilde bilgi vermesi
    gerekiyor. (error handling)

    - fonksiyonun geri dönüş değerinin bu amaçla kullanılması
      fputc (On failure, returns EOF(-1))
      fseek (​0​ upon success, on failure nonzero value)

    - fonksiyonun geri dönüş değeri bir yapı türünden 
      olabilir.
        struct Result {
          int m_error_code;
          int m_return_val;
        };
    - out parametre kullanılabilir.
      void foo(int x, int y, int* p_error); 

    - <errno.h> 
      - errno (C11 required it to be defined as a macro)
*/

/*
  #include <errno.h>

  int main(void)
  {
    printf("errno = %d\n", errno);  // output -> errno = 0

    FILE* p_file = fopen("abcdefxyz.txt", "rb");
    printf("errno = %d\n", errno);  // output -> errno = 2
  }
*/

/*
                    -----------------------
                    | perror in <stdio.h> |
                    -----------------------
*/

/*
  // perror function prototype  
  void perror(const char* p)
  {
    printf("%s: %s, p, strerror(errno)));
  }
*/

/*
  #include <errno.h>  // errno
  #include <stdio.h>  // perror

  int main(void)
  {
    printf("errno = %d\n", errno);  // output -> errno = 0
    FILE* f = fopen("abcdefxyz.txt", "rb");

    if (!f)
      perror("file can not be opened");
    // output -> file can not be opened: No such file or directory

    printf("errno = %d\n", errno);  // output -> errno = 2
  }
*/

/*
                  --------------------------
                  | strerror in <string.h> |
                  --------------------------
*/

/*
  // strerror function prototype  
  char* strerror(int error_number);

  - returns static storage duration objects(char array) address
*/

/*
  #include <errno.h>  // errno
  #include <string.h> // strerror

  int main(void)
  {
    printf("errno = %d\n", errno);  // output -> errno = 0
    FILE* f = fopen("abcdefxyz.txt", "rb");

    if (!f){
      fprintf(stderr, 
              "file can not be opened: %s\n", 
              strerror(errno));
    }
    // output -> file can not be opened: No such file or directory

    printf("errno = %d\n", errno);  // output -> errno = 2

    errno = 0;
  }
*/

/*
  #include <string.h> // strerror
  #include <errno.h>  // errno

  int main(void)
  {
    for (int i = 0; i < 43; ++i)
      printf("errno val %2d : %s\n", i, strerror(i));  
    
    // output ->
    //  errno val  0 : No error
    //  errno val  1 : Operation not permitted
    //  errno val  2 : No such file or directory
    //  errno val  3 : No such process
    //  errno val  4 : Interrupted function call
    //  errno val  5 : Input/output error
    //  errno val  6 : No such device or address
    //  errno val  7 : Arg list too long
    //  errno val  8 : Exec format error
    //  errno val  9 : Bad file descriptor
    //  errno val 10 : No child processes
    //  errno val 11 : Resource temporarily unavailable
    //  errno val 12 : Not enough space
    //  errno val 13 : Permission denied
    //  errno val 14 : Bad address
    //  errno val 15 : Unknown error
    //  errno val 16 : Resource device
    //  errno val 17 : File exists
    //  errno val 18 : Improper link
    //  errno val 19 : No such device
    //  errno val 20 : Not a directory
    //  errno val 21 : Is a directory
    //  errno val 22 : Invalid argument
    //  errno val 23 : Too many open files in system
    //  errno val 24 : Too many open files
    //  errno val 25 : Inappropriate I/O control operation
    //  errno val 26 : Unknown error
    //  errno val 27 : File too large
    //  errno val 28 : No space left on device
    //  errno val 29 : Invalid seek
    //  errno val 30 : Read-only file system
    //  errno val 31 : Too many links
    //  errno val 32 : Broken pipe
    //  errno val 33 : Domain error
    //  errno val 34 : Result too large
    //  errno val 35 : Unknown error
    //  errno val 36 : Resource deadlock avoided
    //  errno val 37 : Unknown error
    //  errno val 38 : Filename too long
    //  errno val 39 : No locks available
    //  errno val 40 : Function not implemented
    //  errno val 41 : Directory not empty
    //  errno val 42 : Illegal byte sequence
  }
*/

/*
  // EDOM macro (33) : domain error
  //   - a value passed to out of function's domain 
  //     errno will be set to EDOM.

  #include <errno.h>  // errno
  #include <math.h>   // sqrt

  int main(void)
  {
    printf("errno = %d\n", errno);  
    // output -> errno = 0

    double dval = sqrt(-1.0);

    if (errno == EDOM)
      printf("errno = EDOM(%d)", errno);
    // output -> errno = EDOM(33)

    errno = 0;
  }
*/

/*
  // ERANGE macro (34) : result too large

  #include <errno.h>    // errno
  #include <stdlib.h>   // strtol

  int main(void)
  {
    printf("errno = %d\n", errno);  
    // output -> errno = 0

    long lval = strtol("0xFFFFFFFF", NULL, 0);
    // 0xFFFFFFFF exceeds the range of long type.

    if (errno == ERANGE)
      printf("errno = ERANGE(%d)", errno);
    // output -> errno = ERANGE(34)

    errno = 0;
  }
*/

/*
                      -------------------
                      | non-local jumps |
                      -------------------
*/

/*
            --------------------------------------
            | setjmp and longjmp function macros |
            --------------------------------------
*/

/*
  // non-local jumps can also be used for error handling.

  #include <setjmp.h> // setjmp, longjmp

  jmp_buf jmp1;

  void bar()
  {
    printf("bar called\n");
    longjmp(jmp1, 10);
  }

  void foo(void)
  {
    printf("foo called\n");
    bar();
  }

  int main(void)
  {
    if (setjmp(jmp1)) 
      printf("jumped here\n");
    else
      foo();

    // output ->
    //  foo called
    //  bar called
    //  jumped here
  }
*/