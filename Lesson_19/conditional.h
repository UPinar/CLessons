#if 0   
  int foo(int);
#endif
// condition = 0  (false)
// preprocessor will not copy foo() functions declaration
// also any other code inside #if and #endif


#if 1
  int bar(int);
#endif
// condition = 1  (true)
// preprocessor will copy bar() functions declaration
// also any other code inside #if and #endif