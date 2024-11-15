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
  x->y
    -> left operand should be an address to a structure variable.
    -> right operand should be a structure member.

  compiler will convert "x->y" expression to "(*x).y"
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

/*
  struct Point {
    int m_x, m_y, m_z;
  };

  int main(void)
  {
    struct Point point_arr[] = {
      { 1, 1, 1 },
      { 2, 2, 2 },
      { 3, 3, 3 },
    };

    point_arr->m_y = 11;
    (&point_arr[0])->m_y = 11;
    // Those 2 lines are equivalent.
    // "point_arr" will decay to a pointer (array to pointer conversion)


    (point_arr + 2)->m_z = 22;
    (&point_arr[2])->m_z = 22;
    point_arr[2].m_z = 22;
    // Those 3 lines are equivalent.
  }
*/

/*
  struct Point {
    int m_x, m_y, m_z;
  };

  int main(void)
  {
    struct Point p1 = { 1, 1, 1 };

    (&p1)->m_x++;

    printf("p1 = [%d, %d, %d]\n", p1.m_x, p1.m_y, p1.m_z);
    // output -> p1 = [2, 1, 1]
  }
*/

/*
  struct Point {
    int m_x, m_y, m_z;
  } g_p1; 
  // "g_p1" is a global Point structure variable.

  struct Point* foo(void)
  {
    return &g_p1;
  }

  int main(void)
  {
    printf("g_p1 = [%d, %d, %d]\n", g_p1.m_x, g_p1.m_y, g_p1.m_z);
    // output -> g_p1 = [0, 0, 0]

    foo()->m_y++;

    printf("g_p1 = [%d, %d, %d]\n", g_p1.m_x, g_p1.m_y, g_p1.m_z);
    // output -> g_p1 = [0, 1, 0]
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
    - '&'       : address of operator
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

/*
  struct Data {
    int m_x, m_y;
    double m_d;
  };

  int main(void)
  {
    struct Data dx;

    struct Data* p_data = &dx;
    // "&dx" is an LValue expression, 
    // its data type is `struct Data*`
  }
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
  };

  int main(void)
  {
    struct Data dx;

    printf("&dx     = %p\n", (void*)&dx);
    printf("&dx + 1 = %p\n", (void*)(&dx + 1));
    // output -> 
    // &dx     = 0000004B8EDFF780
    // &dx + 1 = 0000004B8EDFF790

    // the difference between "&dx" and "&dx + 1" 
    // is 16(0x10) bytes which is equal to sizeof(struct Data)
  }
*/

/*
  struct Data {
    int m_x, m_y;
    double m_d;
  };

  int main(void)
  {
    struct Data d1 = { 1, 5, 3.14 };

    printf("d1 = [%d, %d, %f]\n", d1.m_x, d1.m_y, d1.m_d);
    //  output -> d1 = [1, 5, 3.140000]

    // -----------------------------------------------

    struct Data d2;
    d2 = d1;  // assignment

    printf("d2 = [%d, %d, %f]\n", d2.m_x, d2.m_y, d2.m_d);
    // output -> d2 = [1, 5, 3.140000]
  
    // -----------------------------------------------

    struct Data d3 = d1;  // initialization

    printf("d3 = [%d, %d, %f]\n", d3.m_x, d3.m_y, d3.m_d);
    // output -> d3 = [1, 5, 3.140000]

    // -----------------------------------------------
  }
*/

/*
  struct Data_1 {
    int m_x, m_y;
    double m_d;
  };

  struct Data_2 {
    int m_x, m_y;
    double m_d;
  };

  int main(void)
  {
    struct Data_1 dx = { 1, 5, 3.14 };
    struct Data_2 dy;

    dx = dy;  // syntax error
    // error: incompatible types when assigning 
    // to type 'struct Data_1' from type 'struct Data_2'

    // assignment operator's left and right operands 
    // should be of the same type.
  }
*/

/*
  #include <string.h> // memcpy

  struct Data {
    int m_x, m_y;
    double m_d;
  };

  int main(void)
  {
    struct Data d1 = { 1, 5, 3.14 };
    struct Data d2;

    memcpy(&d2, &d1, sizeof(struct Data));

    printf("d1 = [%d, %d, %f]\n", d1.m_x, d1.m_y, d1.m_d);
    // output -> d1 = [1, 5, 3.140000]
    printf("d2 = [%d, %d, %f]\n", d2.m_x, d2.m_y, d2.m_d);
    // output -> d2 = [1, 5, 3.140000]
  }
*/

/*  
            ---------------------------------------
            | structure variable's initialization |
            ---------------------------------------
*/

/*
  struct Data {
    double m_d1, m_d2;
    int m_i1, m_i2;
  };

  int main(void)
  {
    struct Data d2 = {}; // syntax error
    // warning: ISO C forbids empty initializer braces before C23

    struct Data d3 = { 1.1, 2.2, 3, 4, 5 }; // syntax error
    // warning: excess elements in struct initializer
  }
*/

/*
  struct Data {
    double m_d1, m_d2;
    int m_i1, m_i2;
  };

  int main(void)
  {
    // -----------------------------------------------

    struct Data d1 = { 1.11, 2.22, 33, 44 };

    printf("d1 = [%f, %f, %d, %d]\n", 
            d1.m_d1, d1.m_d2, d1.m_i1, d1.m_i2);
    // output -> d1 = [1.110000, 2.220000, 33, 44]

    // -----------------------------------------------

    struct Data d2 = { 1.11, 2.22, 33 };

    printf("d2 = [%f, %f, %d, %d]\n", 
            d2.m_d1, d2.m_d2, d2.m_i1, d2.m_i2);
    // output -> d2 = [1.110000, 2.220000, 33, 0]

    // -----------------------------------------------

    struct Data d3 = { 1.11, 2.22 };

    printf("d3 = [%f, %f, %d, %d]\n", 
            d3.m_d1, d3.m_d2, d3.m_i1, d3.m_i2);
    // output -> d3 = [1.110000, 2.220000, 0, 0]

    // -----------------------------------------------

    struct Data d4 = { 1.11 };

    printf("d4 = [%f, %f, %d, %d]\n", 
            d4.m_d1, d4.m_d2, d4.m_i1, d4.m_i2);

    // output -> d4 = [1.110000, 0.000000, 0, 0]

    // -----------------------------------------------

    struct Data d5 = { 0 };

    printf("d5 = [%f, %f, %d, %d]\n", 
            d5.m_d1, d5.m_d2, d5.m_i1, d5.m_i2);

    // output -> d5 = [0.000000, 0.000000, 0, 0]

    // -----------------------------------------------
  }
*/

/*
  struct Data {
    int m_x;
    int m_arr[3];
    double m_d;
  };

  int main(void)
  {
    // -----------------------------------------------

    struct Data d1 = { 10, { 1, 2, 3 }, 3.14 };

    printf("d1 = [%d, { %d, %d, %d }, %f]\n", 
            d1.m_x, d1.m_arr[0], d1.m_arr[1], d1.m_arr[2], d1.m_d);
    // output -> d1 = [10, { 1, 2, 3 }, 3.140000]

    // -----------------------------------------------

    struct Data d2 = { 10, 1, 2, 3, 3.14 }; // VALID but warning
    // warning: missing braces around initializer

    printf("d2 = [%d, { %d, %d, %d }, %f]\n", 
            d2.m_x, d2.m_arr[0], d2.m_arr[1], d2.m_arr[2], d2.m_d);
    // output -> d2 = [10, { 1, 2, 3 }, 3.140000]

    // -----------------------------------------------
  }
*/

/*
  struct Data {
    int m_x;
    int m_arr[3];
    double m_d;
  };

  int main(void)
  {
    struct Data d1 = { 10, 1, 2, 3.14 };  // VALID but warning
    // warning: conversion from 'double' to 'int' 
    // changes value from '3.1400000000000001e+0' to '3' 
    // warning: missing initializer for field 'm_d' of 'struct Data'

    printf("d1 = [%d, %d, %d, %d, %f]\n", 
            d1.m_x, d1.m_arr[0], d1.m_arr[1], d1.m_arr[2], d1.m_d);
    // output -> d1 = [10, 1, 2, 3, 0.000000]
  }
*/

/*
  struct AStruct {
    int m_x;
    int m_arr[3];
    double m_d;
  };

  struct BStruct {
    int m_x, m_y;
    struct AStruct m_AStruct;
  };

  int main(void)
  {
    printf("sizeof(struct AStruct) = %zu\n", sizeof(struct AStruct));
    // output -> sizeof(struct AStruct) = 24
    printf("sizeof(struct BStruct) = %zu\n", sizeof(struct BStruct));
    // output -> sizeof(struct BStruct) = 32

    struct BStruct b1 = { 11, 22, { 1, { 2, 3, 4 }, 3.14 } };

    struct BStruct bstruct_arr[3] =
      { { 11, 22, { 1, { 2, 3, 4 }, 3.14 } },
        { 33, 44, { 2, { 3, 4, 5 }, 6.28 } },
        { 55, 66, { 3, { 4, 5, 6 }, 9.42 } } };
  }
*/

/*
  #include <string.h> // strcpy

  struct Employee {
    int m_id;
    char m_name[32];
    char m_surname[32];
    double m_salary;
  };

  int main(void)
  {
    struct Employee e1 = { 1, "hello", "world", 11.11 };

    printf("e1 = [%d, %s, %s, %f]\n", 
            e1.m_id, e1.m_name, e1.m_surname, e1.m_salary);
    // output -> e1 = [1, hello, world, 11.110000]

    strcpy(e1.m_surname, "galaxy");

    printf("e1 = [%d, %s, %s, %f]\n", 
            e1.m_id, e1.m_name, e1.m_surname, e1.m_salary);
    // output -> e1 = [1, hello, galaxy, 11.110000]
  }
*/

/*
  struct Employee {
    int m_id;
    char m_name[32];
    char m_surname[32];
    double m_salary;
  };

  int main(void)
  {
    struct Employee e1 = {
      .m_id = 1,
      .m_name = "hello",
      .m_surname = "world",
      .m_salary = 11.11
     };
     // using designated initializer in struct variable initialization

    printf("e1 = [%d, %s, %s, %f]\n", 
            e1.m_id, e1.m_name, e1.m_surname, e1.m_salary);
    // output -> e1 = [1, hello, world, 11.110000]
  }
*/

// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------

/*
  struct {
    int m_x, m_y, m_z;
  } s1, s2 = { 111, 222, 333}, s3 = { 1111, 2222, 3333 };

  // s1, s2 and s3 are structure variables of an anonymous structure.

  int main(void)
  {
    s1.m_x = 11, s1.m_y = 22, s1.m_z = 33;

    printf("s1 = [%d, %d, %d]\n", s1.m_x, s1.m_y, s1.m_z);
    // output -> s1 = [11, 22, 33]
    printf("s2 = [%d, %d, %d]\n", s2.m_x, s2.m_y, s2.m_z);
    // output -> s2 = [111, 222, 333]
    printf("s3 = [%d, %d, %d]\n", s3.m_x, s3.m_y, s3.m_z);
    // output -> s3 = [1111, 2222, 3333]


    s3 = s1;
    printf("s3 = [%d, %d, %d]\n", s3.m_x, s3.m_y, s3.m_z);
    // output -> s3 = [11, 22, 33]
  }
*/

/*
  - anonymous structure, yapı değişken(structure variable) sayısının
    önceden belli olduğu ve daha fazla bu türden değişken tanımlanması 
    istenilmediği için kullanılır.
    Yapı türünün ismi olmadığı için bu türden bir değişken sadece
    yapı türünün tanımlandığı yerde yaratılabilir.

    struct {
      int m_x, m_y, m_z;
    } s1;

  - anonymous structure yapısının bir ismi olmadığı için 
    bu türde s1'den başka değişken tanımlanamaz.
*/

/*
  struct {
    int m_x, m_y, m_z;
  } s1, *p_s;

  // s1 is a structure variable of an anonymous structure.
  // p_s is a pointer to an anonymous structure.
*/

/*
  struct {
    int m_x, m_y, m_z;
  } elem1;

  struct {
    int m_x, m_y, m_z;
  } elem2;

  int main(void)
  {
    elem1 = elem2; // syntax error
    // error: incompatible types when assigning to type 
    // 'struct <anonymous>' from type 'struct <anonymous>'

    // different anonymous structures types are not same!
  }
*/

/*
  struct Data {
    int m_arr[20][50];
  };

  int main(void)
  {
    printf("sizeof(struct Data) = %zu\n", sizeof(struct Data));
    // output -> sizeof(struct Data) = 4000
    printf("sizeof(struct Data*) = %zu\n", sizeof(struct Data*));
    // output -> sizeof(struct Data*) = 8
  }
*/

/*
  struct Data {
    int m_arr[100];
  };

  int main(void)
  {
    // -----------------------------------------------

    int i_arr1[100] = { 0 };
    int i_arr2[100] = { 0 };

    i_arr1 = i_arr2; // syntax error
    // error: assignment to expression with array type

    // -----------------------------------------------

    // trick to copy array elements (making copyable arrays)

    struct Data d1 = { 0 };
    struct Data d2 = { 0 };

    d1 = d2; // VALID

    // -----------------------------------------------
  }
*/

/*
              ---------------------------------------
              | structures and typedef declarations |
              ---------------------------------------
*/

/*
  // type alias to struct Data as Data

  struct Data {
    int m_x, m_y, m_z;
  };

  typedef struct Data Data;

  int main(void)
  {
    struct Data d1 = { 1, 2, 3 };
    Data d2 = { 4, 5, 6 };

    printf("d1 = [%d, %d, %d]\n", d1.m_x, d1.m_y, d1.m_z);
    // output -> d1 = [1, 2, 3]
    printf("d2 = [%d, %d, %d]\n", d2.m_x, d2.m_y, d2.m_z);
    // output -> d2 = [4, 5, 6]

    d1 = d2;
    printf("d1 = [%d, %d, %d]\n", d1.m_x, d1.m_y, d1.m_z);
    // output -> d1 = [4, 5, 6]
  }
*/

/*
  struct Data {
    int m_x, m_y, m_z;
  };

  typedef struct Data Data;
  // type alias to struct Data as Data

  typedef struct Data* p_Data_t;  
  // type alias to struct Data* as p_Data_t

  typedef Data* p_Data_t2;
  // Data is a type alias to struct Data
  // Data* is a type alias to struct Data*

  int main(void)
  {
    Data d1;
    p_Data_t p_d1 = &d1;
    p_Data_t2 p_d2 = &d1;
  }
*/

/*
  struct Data {
    int m_x, m_y, m_z;
  };

  // ---------------------------------------------------------

  typedef struct Data Data_t, *p_Data_t;
  // type alias to struct Data as Data_t
  // type alias to struct Data* as p_Data_t

  // ---------------------------------------------------------

  typedef struct Data Data_t2;
  typedef Data_t2* p_Data_t2;
  // type alias to struct Data as Data_t2
  // type alias to struct Data* as p_Data_t2

  // ---------------------------------------------------------

  int main(void)
  {
    Data_t d1;
    p_Data_t p_d1 = &d1;

    Data_t2 d2;
    p_Data_t2 p_d2 = &d2;
  }
*/

/*
  typedef struct Data {
    int m_x, m_y, m_z;
  } Data_t, *p_Data_t;

  // type alias to struct Data as Data_t
  // type alias to struct Data* as p_Data_t
*/

/*
  typedef struct {
    int m_x, m_y, m_z;
  } Data_t;

  int main(void)
  {
    // only way to create a variable of that anonymous structure type
    // is using Data_t type alias.

    Data_t d1 = { 1, 2, 3 };

    struct Data_t d2 = { 4, 5, 6 }; // syntax error
    // error: variable 'd2' has initializer but incomplete type
    // error: storage size of 'd2' isn't known
  }
*/

/*
  #include <stdlib.h> // malloc, free

  typedef struct {
    int m_x, m_y, m_z;
  } *p_Data_t;

  int main(void)
  {
    p_Data_t p_d1 = NULL;

    // there is no way to create a structure variable
    // that "p_d1" pointer variable can point to.

    // can not declare a static storage or automatic storage duration
    // variable of that anonymous structure type
    // only can declare a dynamic storage duration variable

    p_d1 = malloc(sizeof(*p_d1));

    // "*p_d1" expression is undefined behavior(UB)
    // sizeof operator's operand will not be evaluated

    free(p_d1);
  }
*/

/*
                  ----------------------------
                  | structures and functions |
                  ----------------------------
*/

/*
  typedef struct Data {
    int m_x, m_y, m_z;
  } Data_t;

  -----------------------------------------------------------

  - function's parameter variable can be a structure type.
    This is rarely used because of data should be copied 
    when a function is called.

    void func(Data_t data); -> rarely used(because of data copy)

  -----------------------------------------------------------

  - function's parameter variable can be a pointer to a structure type.

    void func_1(const Data_t* p_data);  // IN param
    void func_2(Data_t* p_data);        // OUT param / IN-OUT param

  -----------------------------------------------------------

  - function's return type can be a structure type.

    Data_t func_1(void);    -> rarely used(because of data copy)

  -----------------------------------------------------------

  - function's return type can be a pointer to a structure type.
    -> can return static storage duration object's address.
    -> can return dynamic storage duration object's address.
    -> can return the same address that this function is called with.

    Data_t* func_2(void);
    const Data_t* func_3(void);

  -----------------------------------------------------------
*/

/*
  typedef struct {
    int m_id;
    char m_name[32];
    char m_surname[32];
    double m_salary;
  } Employee_t;

  void print_employee_1(Employee_t e)
  {
    printf("Employee: [ %d, %s, %s, %f ]\n", 
            e.m_id, e.m_name, e.m_surname, e.m_salary);
  }

  void print_employee_2(const Employee_t* p_e)
  {
    printf("Employee: [ %d, %s, %s, %f ]\n", 
            p_e->m_id, p_e->m_name, p_e->m_surname, p_e->m_salary);
  }

  // This function can not change the original structure variable.
  // it will copy the structure variable to the function's parameter.
  // then it will change the copied structure variable.
  void modify_employee_1(Employee_t e)
  {
    e.m_salary *= 2;
  }

  // This function can change the original structure variable.
  void modify_employee_2(Employee_t* p_e)
  {
    p_e->m_salary *= 2;
  }

  int main(void)
  {
    Employee_t e1 = { 1, "hello", "world", 11.11 };

    // ---------------------------------------------------------

    printf("sizeof(Employee_t) = %zu\n", sizeof(Employee_t));
    // output -> sizeof(Employee_t) = 80

    print_employee_1(e1);   // call by value
    // output -> Employee: [ 1, hello, world, 11.110000 ]

    // 80 bytes of data will be copied to the "print_employee_1"
    // function's parameter variable.

    // ---------------------------------------------------------

    printf("sizeof(Employee_t*) = %zu\n", sizeof(Employee_t*));
    // output -> sizeof(Employee_t*) = 8

    print_employee_2(&e1);  // call by reference
    // output -> Employee: [ 1, hello, world, 11.110000 ]

    // 8 bytes of data will be copied to the "print_employee_2"
    // function's parameter variable.

    // ---------------------------------------------------------

    modify_employee_1(e1);    // call by value
    print_employee_2(&e1);
    // output -> Employee: [ 1, hello, world, 11.110000 ]

    modify_employee_2(&e1);  // call by reference
    print_employee_2(&e1);
    // output -> Employee: [ 1, hello, world, 22.220000 ]

    // ---------------------------------------------------------
  }
*/

/*
  typedef struct {
    int m_id;
    char m_name[32];
    char m_surname[32];
    double m_salary;
  } Employee_t;

  Employee_t create_random_employee_1(void);

  Employee_t* create_random_employee_2(void);

  int main(void)
  {
    Employee_t e1 = create_random_employee_1();
    // minimum 80 bytes(1 block) of data 
    // will be copied to the "e1" variable.

    Employee_t* p_e2 = create_random_employee_2();
    // 8 bytes of data will be copied to the "p_e2" variable.
  }
*/

/*
  typedef struct {
    int m_id;
    char m_name[32];
    char m_surname[32];
    double m_salary;
  } Employee_t;

  Employee_t* create_random_employee_2(void)
  {
    Employee_t e = { 1, "hello", "world", 11.11 };

    return &e;  
    // returning address of a local variable
  }

  int main(void)
  {
    Employee_t* p_e = create_random_employee_2();
    // p_e is a dangling pointer
    // "*p_e" expression will create undefined behavior(UB)
  }
*/

/*
                ---------------------------------
                | complete and incomplete types |
                ---------------------------------
*/

/*
  ----------------------------------------------------------

  - incomplete type :
    derleyici türün varlığından haberdar ancak türle ilgili
    tüm bilgilere sahip değil.

    struct Employee;   
    -> "struct Employee" is an incomplete type

  -> typedef declarations
  -> function declarations
  -> extern variable declarations
  -> pointer variable definitions.
    -> pointer variable structure members 

  ----------------------------------------------------------

  - complete type :
    derleyici türle ilgili tüm bilgilere sahip.

    struct Data {
      int m_x, m_y, m_z;
    };  
    -> "struct Data" is a complete type

  -> variable declarations
  -> can be a sizeof operator's operand
  -> pointer dereferencing

  ----------------------------------------------------------
*/

/*
  // some.h
  // ---------

  struct Data;
  // code
  // code
  
  // ..    -> "struct Data" is an incomplete type for compiler

  // code
  // code

  struct Data {
    int m_x, m_y, m_z;
  };  

  // code

  // ..    -> "struct Data" is a complete type for compiler

  // code
  // code
*/

/*
  struct Data;  // "struct Data" is an incomplete type

  typedef struct Data Data_t; 
  typedef struct Data* p_Data_t;
  typedef Data_t* p_Data_t2;
*/

/*
  struct Data;    // "struct Data" is an incomplete type
  struct Data_2;  // "struct Data_2" is an incomplete type

  struct Data foo(struct Data);
  // foo function's non defining declaration

  struct Data* bar(struct Data*);
  // bar function's non defining declaration

  struct Data_2* baz(struct Data*);
  // baz function's non defining declaration
*/

/*
  struct Data;  // incomplete type

  extern struct Data g_data;
  // g_data struct Data türünden, fakat başka bir modülde 
  // bildirimi yapılmış(yeri hafızada ayrılmış) bir değişkendir.

  extern struct Data g_data_array[];
  // g_data_array elemanları struct Data türünden 
  // fakat başka bir modülde hafızadaki yeri ayrılan bir dizidir.
*/

/*
  struct Data;  // incomplete type

  struct Data* create_data(void);
  void process_data(struct Data* p_data);

  int main(void)
  {
    struct Data* p_data = NULL;
    // derleyici zaten object pointer türünün kaç byte olduğunu biliyor,
    // dolayısıyla struct Data* türünden bir değişken tanımlanabilir.

    p_data = create_data();
    process_data(p_data);
    // no problem calling those functions in compile time phase
    // if those functions are not defined it will be a linking error.
  }
*/

/*
  struct Data; // incomplete type

  struct Employee {
    int m_id;
    struct Data* p_data;
  };
*/

/*
  struct Data;  // incomplete type

  int main(void)
  {
    struct Data d1; // syntax error
    // error: storage size of 'd1' isn't known
  }
*/

/*
  #include <stddef.h> // size_t

  struct Data;  // incomplete type

  int main(void)
  {
    size_t N = sizeof(struct Data); // syntax error
    // error: invalid application of 'sizeof' 
    // to incomplete type 'struct Data'
  }
*/

/*
  // dereferencing a pointer to an incomplete type is syntax error

  struct Data;  // incomplete type

  struct Data* foo(void);

  int main(void)
  {
    struct Data* p_data = foo();

    *p_data;
    // "*p_data" expression is syntax error
    // error: invalid use of undefined type 'struct Data'

    p_data->m_x = 5;
    // "p_data->" expression is syntax error
    // error: invalid use of undefined type 'struct Data'

  }
*/

/*
  struct Data;  // incomplete type

  struct Employee {
    int m_id;
    struct Data m_data; // syntax error
    // error: field 'm_data' has incomplete type
  };
*/

/*
  struct Data_1 foo(struct Element_1);

  // compiler will assume that 
  // "struct Data_1" and "struct Element_1" are incomplete types.

  struct Data_2* p_data;
  struct Element_2* p_elem;

  // compiler will assume that
  // "struct Data_2" and "struct Element_2" are incomplete types.

  typedef struct Data_3 Data_t;
  typedef struct Element_3* p_Element_t;

  // compiler will assume that
  // "struct Data_3" and "struct Element_3" are incomplete types.
*/

/*
  Question : Why incomplete types are used?
    - when header files include each other, dependencies are 
    increased and compilation time is increased. 
    Incomplete types can be used in header files
    to reduce dependencies.
*/

/*
                    -----------------------
                    | <date> module tests |
                    -----------------------
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt;

    date_set(&dt, 1, 1, 2001);
    date_print(&dt);  // output -> 01 Ocak 2001 Pazartesi

    date_set(&dt, 2, 2, 2002);
    date_print(&dt);  // output -> 02 Şubat 2002 Cumartesi
  }
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt;

    date_set_by_string(&dt, "03-03-2003");
    date_print(&dt);  // output -> 03 Mart 2003 Pazartesi

    date_set_by_string(&dt, "04-04-2004");
    date_print(&dt);  // output -> 04 Nisan 2004 Pazar

    if (!date_set_by_string(&dt, "29-02-1993")){
      printf("Date is invalid!\n");
      return 1;
    }
    // output -> Date is invalid!
  }
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt;

    date_set_today(&dt);
    date_print(&dt);  // output -> 15 Kasim 2024 Cuma
  }
*/

/*
  #include "../date.h"
  #include "../nutility.h"
  #include <stddef.h> // size_t

  #define   SIZE    10

  void date_set_array(Date_t* p_date, size_t size)
  {
    while (size--)
      date_set_random(p_date++);
  }

  void date_print_array(const Date_t* p_date, size_t size)
  {
    while (size--)
      date_print(p_date++);
  }

  int main(void)
  {
    Date_t dt_arr[SIZE];

    randomize();
    date_set_array(dt_arr, SIZE);
    date_print_array(dt_arr, SIZE);

    // output ->
    //  26 Haziran 1998 Cuma
    //  18 Temmuz 1948 Pazar
    //  03 Subat 1979 Cumartesi
    //  25 Temmuz 1983 Pazartesi
    //  01 Agustos 1952 Cuma
    //  16 Ekim 1997 Persembe
    //  19 Mart 2017 Pazar
    //  16 Aralik 1993 Persembe
    //  01 Nisan 2003 Sali
    //  28 Nisan 1941 Pazartesi
  }
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt;

    printf("Enter a date : ");

    if (date_scan(&dt))
      date_print(&dt);
    else {
      printf("Invalid date!\n");
      return 1;
    }

    // input -> Enter a date : 14 11 2024
    // output -> 14 Kasim 2024 Persembe

    // input -> Enter a date : 29 02 2023
    // output -> Invalid date!

    // input -> Enter a date : 31 12 2100
    // output -> 31 Aralik 2100 Cuma
  }
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt;

    date_set(&dt, 1, 1, 2001);
    date_print(&dt);
    // output -> 01 Ocak 2001 Pazartesi

    date_set_year(&dt, 2002);
    date_print(&dt);
    // output -> 01 Ocak 2002 Sali

    date_set_month(&dt, 3);
    date_print(&dt);
    // output -> 01 Mart 2002 Cuma

    date_set_day(&dt, 4);
    date_print(&dt);
    // output -> 04 Mart 2002 Pazartesi
}
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt;

    date_set(&dt, 22, 11, 2032);

    printf("%d year's, %d month's, %d day.\n", 
            date_get_year(&dt), 
            date_get_month(&dt), 
            date_get_day_of_month(&dt));
    // output -> 2032 year's, 11 month's, 22 day.
  }
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt1, dt2, dt3;

    date_set(&dt1, 31, 12, 2024); // leap year
    printf("%d\n", date_get_day_of_year(&dt1)); // output -> 366

    date_set(&dt2, 31, 12, 2023); // not leap year
    printf("%d\n", date_get_day_of_year(&dt2)); // output -> 365

    date_set(&dt3, 30, 1, 2020);
    printf("%d\n", date_get_day_of_year(&dt3)); // output -> 30
  }
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt1;

    date_set_today(&dt1);
    printf("%d\n", date_get_day_of_week(&dt1)); 
    // output -> 5 (Friday)

    Date_t dt2;
    date_set(&dt2, 10, 11, 1938);
    printf("%d\n", date_get_day_of_week(&dt2)); 
    // output -> 4 (Thursday)
  }
*/

/*
  #include "../date.h"
  #include <stdlib.h> // malloc, free
  #include <time.h>   // clock

  void date_set_array(Date_t* p_date, size_t size)
  {
    while (size--)
      date_set_random(p_date++);
  }

  void date_print_array(const Date_t* p_date, size_t size)
  {
    while (size--)
      date_print(p_date++);
  }

  int compare_date(const void* vp1, const void* vp2)
  {
    const Date_t* p1 = vp1;
    const Date_t* p2 = vp2;

    return date_compare(p1, p2);
  }

  int main(void)
  {
    size_t N = 100000;  // 100'000

    Date_t* p_date = (Date_t*)malloc(N * sizeof(Date_t));
    if (!p_date) {
      printf("Memory allocation error!\n");
      return 1;
    }

    date_set_array(p_date, N);

    printf("[0] - Sorting dates started\n");
    clock_t start = clock();
    qsort(p_date, N, sizeof(Date_t), &compare_date);
    clock_t end = clock();
    printf("[1] - Sorting dates finished\n");
    printf("Elapsed time: %f seconds\n", 
            (double)(end - start) / CLOCKS_PER_SEC);

    // output ->
    //  [0] - Sorting dates started
    //  [1] - Sorting dates finished
    //  Elapsed time: 0.024000 seconds

    date_print_array(p_date, N);

    free(p_date);
  }
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt;
    date_set(&dt, 3, 2, 1998);
    date_print(&dt);    // output -> 03 Subat 1998 Sali

    Date_t dt2;
    date_set_today(&dt2);
    date_print(&dt2);   // output -> 15 Kasim 2024 Cuma

    int N = date_diff(&dt, &dt2);
    printf("Difference between dates: %d days\n", N);
    // output -> Difference between dates: 9782 days
  } 
*/

/*
  #include "../date.h"

  int main(void)
  {
    Date_t dt;
    date_set(&dt, 1, 1, 2001);
    date_print(&dt);  
    // output -> 01 Ocak 2001 Pazartesi

    int N = 1000;
    Date_t dt2;
    Date_t dt3;

    date_N_days_after(&dt2, &dt, N);
    date_print(&dt2); 
    // output -> 28 Eylul 2003 Pazar

    date_N_days_before(&dt3, &dt, N);
    date_print(&dt3); 
    // output -> 07 Nisan 1998 Sali
  } 
*/