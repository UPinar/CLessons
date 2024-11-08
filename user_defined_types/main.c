#include <stdio.h>

/*
                      ======================
                      | User-Defined Types |
                      ======================
*/

/*
  - structures    (yapı)
  - unions        (birlik)
  - enumerations  (numaralandırma)
*/

/*
                          --------------
                          | structures |
                          --------------
*/

/*
  - `struct` is a keyword
  - `AStruct` is an identifier called structure tag.
  - struct needs to be defined with minimum one structure member.

  struct AStruct {
    int m_x, m_y;
    double m_d;
  };

  - m_x, m_y, m_d are structure members.
*/

/*
  struct AStruct {};
  // warning: struct has no members 

  int main(void){}
*/

/*
  struct AStruct {
    int m_x, m_y;
    double m_d;
  };

  void foo(struct AStruct);

  int main(void)
  {
    struct AStruct a1;  
    // "a1" is a structure variable.
  }
*/

/*
  struct AStruct {
    int m_x, m_y;
    double m_d;
  }; // struct declaration

  // compiler will not allocate a memory
  // for the structure declaration.

  // compiler will allocate a memory 
  // when a structure variable is declared.
*/

/*
                <--- check struct.png --->

  struct AStruct {
    int m_x, m_y;
    double m_d;
  };

  AStruct's variables order is m_x, m_y, m_d
  AStruct's address is same as m_x's address.
*/

/*
  struct AStruct {
    int m_x, m_y;
    double m_d;
  };

  int main(void)
  {
    struct AStruct a1;

    printf("address of a1    : %p\n", (void*)&a1);
    printf("address of a1.m_x: %p\n", (void*)&a1.m_x);
    printf("address of a1.m_y: %p\n", (void*)&a1.m_y);
    printf("address of a1.m_d: %p\n", (void*)&a1.m_d);

    // output ->
    //  address of a1    : 0000004CC77FFCD0
    //  address of a1.m_x: 0000004CC77FFCD0
    //  address of a1.m_y: 0000004CC77FFCD4
    //  address of a1.m_d: 0000004CC77FFCD8
  }
*/

/*
  // struct members can be 
  // - int, double (primitive types)
  // - arrays
  // - pointers
  // - function pointers
  // ...

  struct AStruct {
    int m_x, m_y;
    double m_d;
    int m_arr[10];
    int m_mdarr[10][5];
    int* mp_x;
    void (*mp_func)(void);
  };
*/

/*
  struct AStruct {
    int m_x;
  };

  struct BStruct {
    int m_x, m_y;
  };

  struct CStruct {
    int m_x, m_y;
    double m_d;
  };

  int main(void)
  {
    printf("sizeof(int) = %zu\n", sizeof(int));
    // output -> sizeof(int) = 4

    printf("sizeof(struct AStruct) = %zu\n", sizeof(struct AStruct));
    // output -> sizeof(struct AStruct) = 4

    printf("sizeof(struct BStruct) = %zu\n", sizeof(struct BStruct));
    // output -> sizeof(struct BStruct) = 8

    printf("sizeof(struct CStruct) = %zu\n", sizeof(struct CStruct));
    // output -> sizeof(struct CStruct) = 16
  }
*/

/*
  // file1.h
  // ---------------

  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };  // struct declaration

  // if source files will use Data structure's declaration
  // then Data structure's declaration should be in header file.

  // if source files will not use Data structure's declaration
  // it will only used in implementation file
  // its declaration should be in source(.cpp) file.
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };

  struct Data g_data;           // global variable 
  // "g_data" identifier is in file scope.
  // g_data is a static storage duration object.
  // "g_data" variable have an external linkage.


  static struct Data g_data2;   // global variable
  // "g_data2" identifier is in file scope.
  // g_data2 is a static storage duration object.
  // "g_data2" variable have an internal linkage.


  void foo(void)
  {
    struct Data local_data;         // local variable
    // "local_data" identifier is in block scope.
    // local_data is an automatic storage duration object.
    // "local_data" variable have no linkage.

    static struct Data local_data2; // static local variable
    // "local_data2" identifier is in block scope.
    // local_data2 is a static storage duration object.
    // "local_data2" variable have no linkage.
  }

  void bar(struct Data param_data)  // function parameter variable
  {
    // "param_data" identifier is in "bar" function's block scope.
    // param_data is an automatic storage duration object.
    // "param_data" variable have no linkage.
  }
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };

  int main(void)
  {
    struct Data d1;
    struct Data* p_data = &d1;
  }
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };

  int main(void)
  {
    struct Data d1 = { 11, 22, 3.14, "hello" };
  }
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };

  struct Data g_data;
  // struct variables are initialized with 0.

  int main(void)
  {
    struct Data d1;
    // struct variables have garbage(indeterminate) values.
  }
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };

  int main(void)
  {
    struct Data d_arr[10];
    // an array of 10 "Data" structures.
  }
*/

/*
                  ------------------------------
                  | member selection operators |
                  ------------------------------
*/

/*
                      -----------------------
                      | '.' -> dot operator |
                      -----------------------
*/

/*
  x.y 
    -> left operand should be a structure variable.
    -> right operand should be a structure member.
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };

  int main(void)
  {
    struct Data d1;
    // "d1" is an LValue expression.
    // "d1" expression's data type is `struct Data`

    d1.m_x = 10;
    // "d1.m_x" is an LValue expression.
    // "d1.m_x" expression's data type is `int`

    d1.m_d = 3.14;
    // "d1.m_d" is an LValue expression.
    // "d1.m_d" expression's data type is `double`

    char* p1 = d1.m_str;    // d1.m_str will decay to a pointer.
    char* p2 = &d1.m_str[0];
    // Those 2 lines are equivalent.
  }
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };

  int main(void)
  {
    struct Data d1;
    struct Data* p_data = &d1;

    (*p_data).m_x = 10; 
    (*p_data).m_d = 3.14;
    // '.' operator has higher precedence than '*' operator.
  }
*/

/*

                    --------------------------
                    | '->' -> arrow operator |
                    --------------------------
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  };

  int main(void)
  {
    struct Data d1;
    struct Data* p_data = &d1;

    p_data->m_x = 10;
    (*p_data).m_x = 10;
    // Those 2 lines are equivalent.

    p_data->m_d = 3.14;
    (*p_data).m_d = 3.14;
    // Those 2 lines are equivalent.
  }
*/

// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------

/*
  struct xyz {
    int xyz;
  };

  // structure tag identifier is "xyz"
  // "struct identifier" have has a structure member named "xyz"

  int main(void)
  {
    struct xyz xyz;
    // "xyz" is a structure variable of type "struct xyz"

    xyz.xyz = 10;
  }
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  } g_x, g_y;

  // "g_x" and "g_y" are global variables of type "struct Data"

  struct Data g_1;
  struct Data g_2;
  // "g_1" and "g_2" are global variables of type "struct Data"
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  } *gp_data1;

  // "gp_data1" is a pointer to "struct Data"

  struct Data* gp_data2;
  // "gp_data2" is a pointer to "struct Data"
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  } g_x, *gp_data1;

  // "g_x" is a global variable of type "struct Data" 
  // "gp_data1" is a pointer to "struct Data"


  struct Data g_y;
  struct Data* gp_data2;
  // "g_y" is a global variable of type "struct Data"
  // "gp_data2" is a pointer to "struct Data"
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
    char m_str[12];
  } g_x, *gp_data1 = &g_x;

  struct Data g_y;
  struct Data* gp_data2 = &g_y;
*/

/*
  // functions CAN NOT be a structure member

  struct Data {
    int m_x, m_y;
    void foo(void); // syntax error
    // error: field 'foo' declared as a function
  };
*/

/*
  struct Data {
    int m_x, m_y;
    int (*mp_func)(int);
  };

  int foo(int);
  int bar(int);

  int main(void)
  {
    struct Data d1;
    d1.mp_func = foo;
    d1.mp_func = &bar;
  }
*/

/*
  structure variables CAN ONLY be an operand of these operators
    - `sizeof`  : sizeof operator
    - '.'       : dot operator
    - '->'      : arrow operator
    - '='       : assignment operator
*/

/*
  struct Data {
    int m_x, m_y;
  };

  int main(void)
  {
    struct Data d1;

    printf("sizeof(d1) = %zu\n", sizeof(d1));
    // output -> sizeof(d1) = 8

    printf("sizeof(struct Data) = %zu\n", sizeof(struct Data));
    // output -> sizeof(struct Data) = 8

    // "sizeof d1" is a constant expression
    // its data type is `size_t`
  }
*/