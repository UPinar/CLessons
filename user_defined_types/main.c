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
  #include "../headers/date.h"

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
  #include "../headers/date.h"

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
  #include "../headers/date.h"

  int main(void)
  {
    Date_t dt;

    date_set_today(&dt);
    date_print(&dt);  // output -> 15 Kasim 2024 Cuma
  }
*/

/*
  #include "../headers/date.h"
  #include "../headers/nutility.h"
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
  #include "../headers/date.h"

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
  #include "../headers/date.h"

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
  #include "../headers/date.h"

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
  #include "../headers/date.h"

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
  #include "../headers/date.h"

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
  #include "../headers/date.h"
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
  #include "../headers/date.h"

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
  #include "../headers/date.h"

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

/*
        ---------------------------------------------------------
        | composition (yapının elemanının yapı türünden olması) |
        ---------------------------------------------------------
*/

/*
  struct AStruct {
    int m_x, m_y, m_z;
  };

  struct BStruct {
    double m_d1, m_d2;
    struct AStruct m_AStruct;   // composition
  };

  int main(void)
  {
    printf("sizeof(struct AStruct) = %zu\n", sizeof(struct AStruct));
    // output -> sizeof(struct AStruct) = 12

    printf("sizeof(struct BStruct) = %zu\n", sizeof(struct BStruct));
    // output -> sizeof(struct BStruct) = 32 (4 byte alignment)
  }
*/

/*
  // incomplete types can not an element of a structure

  struct AStruct;

  struct BStruct {
    double m_d1, m_d2;
    struct AStruct m_AStruct;   // syntax error
    // error: field 'm_AStruct' has incomplete type
  };
*/

/*
  struct AStruct {
    int m_x, m_y, m_z;
  };

  struct BStruct {
    double m_d1, m_d2;
    struct AStruct m_AStruct;   // composition
  };

  int main(void)
  {
    struct AStruct a1;
    struct BStruct b1;

    b1.m_AStruct = a1;
    // "b1.m_AStruct" is an LValue expression 
    // its data type is "struct AStruct"
  }
*/

/*
  struct AStruct {
    int m_x, m_y, m_z;
  };

  struct BStruct {
    double m_d1, m_d2;
    struct AStruct m_AStruct;
  };

  int main(void)
  {
    struct BStruct b1 = { 1.11, 2.22, { 3, 4, 5 } };
    struct BStruct b2 = { 6.66, 7.77, 8, 9, 10 };

    struct BStruct b3 = { 
        .m_d1 = 11.11, 
        .m_d2 = 22.22, 
        .m_AStruct = { 33, 44, 55 } 
    };
  }
*/

/*
  struct AStruct {
    int m_x, m_y, m_z;
  };

  struct BStruct {
    double m_d1, m_d2;
    struct AStruct m_AStruct;
  };

  int main(void)
  {
    struct BStruct b1;
    struct BStruct* p_b1 = &b1;

    p_b1->m_AStruct.m_x = 11;
    // "->" and "." operators are in same precedence level
    // they are left associative operators
  }
*/

/*
  struct AStruct {
    int m_x, m_y, m_z;
  };

  struct BStruct {
    double m_d1, m_d2;
    struct AStruct* mp_AStruct;
  };

  int main(void)
  {
    struct BStruct b1;

    b1.mp_AStruct->m_x = 11;
    // "->" and "." operators are in same precedence level
    // they are left associative operators

    struct BStruct* p_b1 = &b1;
    p_b1->mp_AStruct->m_y = 22;
  }
*/

/*
  struct Data {
    int m_x, m_y;
    struct Data m_data; // syntax error
    // error: field 'm_data' has incomplete type
  };

  // because of struct Data's definition is not completed yet
  // struct Data is an incomplete type.
*/

/*
  // self-referential structures

  struct Data {
    int m_x, m_y;
    struct Data* mp_Data;
  };

  // `struct Data` type has a `struct Data*` type member
*/

/*
  struct Data {
    int m_a, m_b;

    struct Point {
      int m_x, m_y;
    } m_Point;
  };
  // there are 2 structure type definitions in this code block
  // `struct Data` and `struct Point` definitions.

  // `struct Data` is an enclosing structure
  // `struct Point` is a nested structure
*/

/*
  struct Data {
    int m_a, m_b;

    struct {
      int m_x, m_y;
    } m_NestedStruct;
  };

  // struct tag does not need to be used in this context.

  // `struct Data` type has 
  //  - 2 int type members(m_a, m_b)
  //  - anonymous structure type member(m_NestedStruct)
*/

/*
  struct Data {
    int m_a, m_b;

    struct Point {
      int m_x, m_y;
    } m_Point;
  };

  int main(void)
  {
    struct Data d1;

    printf("sizeof(struct Point) = %zu\n", sizeof(struct Point));
    // output -> sizeof(struct Point) = 8

    printf("sizeof(struct Data) = %zu\n", sizeof(struct Data));
    // output -> sizeof(struct Data) = 16
  }
*/

/*
  // nested type is visible, 
  // in every scope that enclosing type is visible

  struct Data {
    int m_a, m_b;

    struct Point {
      int m_x, m_y;
    } m_Point;
  };

  int main(void)
  {
    struct Point p1 = { 1, 2 };
  }
*/

/*
  struct Data {
    int m_a, m_b;

    struct {  
      int m_x, m_y;
    };  // anonymous structure type
  };

  struct Data_2 {
    int m_a, m_b;
    int m_x, m_y;
  };

  int main(void)
  {
    // ---------------------------------------------------------

    printf("sizeof(struct Data) = %zu\n", sizeof(struct Data));
    // output -> sizeof(struct Data) = 16

    // seems like `struct Data` does not have
    // named anonymous structure type member
    // but the sizeof(struct Data) is 16 bytes

    struct Data d1;
    d1.m_x = 11;    
    // reaching anonymous structure type member's data members  
    d1.m_y = 22;
    // reaching anonymous structure type member's data members

    // ---------------------------------------------------------

    printf("sizeof(struct Data_2) = %zu\n", sizeof(struct Data_2));
    // output -> sizeof(struct Data_2) = 16

    struct Data_2 d2;
    d2.m_x = 33;
    d2.m_y = 44;

    // ---------------------------------------------------------
  }
*/

/*
  // ---------------------------------------------------------

  #include "../headers/date.h"

  struct Employee {
    int m_id;
    char m_name[32];
    char m_address[64];
    Date_t m_birth_date;
  };

  // ---------------------------------------------------------

  struct Point {
    double m_x, m_y;
  };

  struct Triangle {
    struct Point m_Point1, m_Point2, m_Point3;
  };

  struct Line {
    struct Point m_Point_arr[6];
  };

  // ---------------------------------------------------------
*/

/*
                    -------------------------
                    | <person> module tests |
                    -------------------------
*/

/*
  #include "../headers/person.h"
  #include "../headers/nutility.h"

  int main(void)
  {
    randomize();
    Person_t p;

    for(int i = 0; i < 5; ++i) {
      person_set_random(&p);
      person_print(&p);
    }
    // output ->
    //  22774 tuncer         telek          02 Kasim 1966 Carsamba
    //  14990 sadiye         reis           01 Mayis 2002 Carsamba
    //  2662  nasrullah      samanci        05 Ekim 1979 Cuma
    //  16683 umit           maganda        28 Aralik 2009 Pazartesi
    //  32173 ciler          supuren        14 Nisan 1988 Persembe
  }
*/

/*
  #include <stddef.h> // size_t
  #include <stdlib.h> // malloc, free, qsort
  #include <time.h>   // clock, CLOCKS_PER_SEC

  #include "../headers/person.h"
  #include "../headers/nutility.h"

  void set_person_array(Person_t* p_person, size_t size)
  {
    while (size--)
      person_set_random(p_person++);
  }

  void print_person_array(const Person_t* p_person, size_t size)
  {
    while (size--)
      person_print(p_person++);
  }

  int person_compare_qsort(const void* vp1, const void* vp2)
  {
    const Person_t* p1 = vp1;
    const Person_t* p2 = vp2;

    return person_compare(p1, p2);
  }

  int main(void)
  {
    size_t N = 1000000;

    Person_t* p_Person = malloc(N * sizeof(Person_t));

    if (!p_Person) {
      printf("Memory allocation error!\n");
      return 1;
    }

    randomize();
    set_person_array(p_Person, N);

    clock_t start = clock();
    qsort(p_Person, N, sizeof(*p_Person), &person_compare_qsort);
    clock_t end = clock();

    printf("Elapsed time: %f seconds\n", 
            (double)(end - start) / CLOCKS_PER_SEC);

    print_person_array(p_Person, N);
    free(p_Person);

    // output ->
    // ....
    //  31788 kamile         akgunes        10 Agustos 2016 Carsamba
    //  28440 lamia          akgunes        30 Ekim 2023 Pazartesi
    //  32417 yasemin        akgunes        06 Nisan 1994 Carsamba
    //  8644  zahide         akgunes        04 Aralik 1996 Carsamba
    //  1130  zahide         akgunes        07 Nisan 2015 Sali
  }
*/

// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------

/*
  #include <limits.h> // INT_MIN
  #include <stdlib.h> // qsort

  #include "../headers/nutility.h"

  int int_compare_qsort_UB(const void* vp1, const void* vp2)
  {
    int i1 = *(const int*)vp1;
    int i2 = *(const int*)vp2;

    return i1 - i2;  
    // (345 - (INT_MIN)) cause overflow -> UB
  }

  int int_compare_qsort_NO_UB(const void* vp1, const void* vp2)
  {
    int i1 = *(const int*)vp1;
    int i2 = *(const int*)vp2;

    return (i1 > i2) - (i1 < i2);
  }

  int main(void)
  {
    int arr[] = { -5, -355, -98, 345, INT_MIN, 11, -4763 };

    // qsort(arr, asize(arr), sizeof(*arr), &int_compare_qsort_UB);
    qsort(arr, asize(arr), sizeof(*arr), &int_compare_qsort_NO_UB);

    for (size_t i = 0; i < asize(arr); ++i)
      printf("%d ", arr[i]);
    // output -> -2147483648 -4763 -355 -98 -5 11 345
  }
*/

/*
  #include <stddef.h> // size_t
  #include <stdlib.h> // malloc, free, qsort

  #include "../headers/person.h"
  #include "../headers/nutility.h"

  int person_compare_qsort(const void* vp1, const void* vp2)
  {
    const Person_t* p1 = vp1;
    const Person_t* p2 = vp2;

    return person_compare(p1, p2);
  }

  typedef int(*fn_PersonCompare)(const Person_t*, const Person_t*);
  typedef int(*fn_PersonCompare_qsort)(const void*, const void*);

  int main(void)
  {
    size_t N = 1000000;
    Person_t* p_Person = malloc(N * sizeof(Person_t));

    if (!p_Person) {
      printf("Memory allocation error!\n");
      return 1;
    }

    // ---------------------------------------------------------

    qsort(p_Person, 
          N, 
          sizeof(*p_Person), 
          &person_compare_qsort);

    // correct function pointer type
    // int(*)(const void* vp1, const void* vp2)

    // ---------------------------------------------------------

    qsort(p_Person, 
          N, 
          sizeof(*p_Person), 
          &person_compare); // syntax error
    
    // error: passing argument 4 of 'qsort' 
    // from incompatible pointer type

    // wrong function pointer type
    // int(*)(const Person_t*, const Person_t*)

    // ---------------------------------------------------------

    qsort(p_Person, 
          N, 
          sizeof(*p_Person), 
          (fn_PersonCompare_qsort)&person_compare); 
    // undefined behaviour (UB)
    
    // conversion from `int(*)(const Person_t*, const Person_t*)` to 
    //  `int(*)(const void*, const void*)` is undefined behavior(UB)

    // conversion from `fn_PersonCompare` to `fn_PersonCompare_qsort`
    // is undefined behavior(UB)

    // --------------------------------------------------------------

    free(p_Person);
  }
*/

/*
                        -----------------
                        | HANDLE system |
                        -----------------
*/

/*
              <--- check singly_linked_list.png --->
*/

/*
  // ---------------------------------------------------------

  reaching with a known index 
    -> dynamic array      -> 0(1)
    -> singly linked list -> O(n)

  searching an element
    -> dynamic array      -> O(n)
    -> singly linked list -> O(n)

  inserting an element to a known address
    -> dynamic array      -> O(n)
    -> singly linked list -> O(1)

  deleting an element from a known address
    -> dynamic array      -> O(n)
    -> singly linked list -> O(1)

  // ---------------------------------------------------------

  (-)singly linked-list
    every time a new element will be added `malloc` will be called.
    and `malloc` will allocate memory for HEADER part.
  (+)dynamic array
    reallocation can be done in amortized O(1) time complexity.

  (-)in `int` linked list, int + int* will be allocated in a Node
  (+)in `int` dynamic array, only `int` will be allocated in element.

  (-)singly linked list is not cache friendly.
  (+)dynamic array is cache friendly.

  (+)SIMD operations can be used with dynamic arrays.
  (-)SIMD operations can not be used with singly linked lists.

  (-)fragmentation is a problem for dynamic array
  (+)fragmentation is not a problem for singly linked list

  (+) swapping algorithms is NOT expensive singly linked list
    -> swapping only pointers(copying pointers)
  (-) swapping algorithms is expensive in dynamic array
    -> swapping elements(copying structures(elements))

  // ---------------------------------------------------------
*/

/*
  #include "../headers/person_list.h"
  #include "../headers/person.h"
  #include "../headers/nutility.h"

  int main(void)
  {

    randomize();

    Person_t p;
    for (int i = 0; i < 5; ++i) {
      person_set_random(&p);
      list_push_front(&p);
    }

    printf("List size: %zu\n", list_get_size());
    // output -> List size: 5

    list_print();
    // output ->
    //  3236  ege            acgoze         13 Kasim 1963 Carsamba
    //  9082  temel          orhancan       21 Ocak 1997 Sali
    //  23813 zahide         kalpsiz        20 Haziran 2000 Sali
    //  13740 ceyhun         gurkas         07 Subat 2009 Cumartesi
    //  32315 nedim          lombak         26 Agustos 1998 Carsamba

    list_make_empty();
  }
*/

/*
  #include "../headers/person_list.h"
  #include "../headers/person.h"
  #include "../headers/nutility.h"

  int main(void)
  {

    randomize();

    Person_t p;
    for (int i = 0; i < 3000000; ++i) { // 3'000'000
      person_set_random(&p);
      list_push_front(&p);
    }

    printf("List size: %zu\n", list_get_size());

    list_print();
    list_make_empty();
  }
*/

/*
  #include "../headers/person_list.h"
  #include "../headers/person.h"
  #include "../headers/nutility.h"

  int main(void)
  {

    randomize();

    Person_t p;
    for (int i = 0; i < 5; ++i) {
      person_set_random(&p);
      list_push_front(&p);
    }

    while (!list_is_empty()){
      printf("List size: %zu\n", list_get_size());
      list_print();
      list_pop_front();
    }
    // output ->
    //  List size: 5
    //  11352 eda            komurcu        24 Aralik 1940 Sali
    //  8584  cebrail        dosteli        12 Haziran 2023 Pazartesi
    //  1754  gizem          kurban         15 Eylul 2013 Pazar
    //  9726  helin          kosnuk         21 Nisan 1970 Sali
    //  1124  kaan           yangin         29 Aralik 1968 Pazar
    //  ---------------------------------------------------
    //  List size: 4
    //  8584  cebrail        dosteli        12 Haziran 2023 Pazartesi
    //  1754  gizem          kurban         15 Eylul 2013 Pazar
    //  9726  helin          kosnuk         21 Nisan 1970 Sali
    //  1124  kaan           yangin         29 Aralik 1968 Pazar
    //  ---------------------------------------------------
    //  List size: 3
    //  1754  gizem          kurban         15 Eylul 2013 Pazar
    //  9726  helin          kosnuk         21 Nisan 1970 Sali
    //  1124  kaan           yangin         29 Aralik 1968 Pazar
    //  ---------------------------------------------------
    //  List size: 2
    //  9726  helin          kosnuk         21 Nisan 1970 Sali
    //  1124  kaan           yangin         29 Aralik 1968 Pazar
    //  ---------------------------------------------------
    //  List size: 1
    //  1124  kaan           yangin         29 Aralik 1968 Pazar
    //  ---------------------------------------------------
  }
*/

/*
  Problem in this approach is that, we can not create 
  more than one list. Handle system will solve this problem.
*/

/*
  #include "../headers/handle_person_list.h"
  #include "../headers/nutility.h"
  #include "../headers/person.h"

  int main(void)
  {

    randomize();
    Person_t p;

    List_Handle h1_list = list_create();
    for(int i = 0; i < 3; ++i) {
      person_set_random(&p);
      list_push_front(h1_list, &p);
    }

    List_Handle h2_list = list_create();
    for(int i = 0; i < 5; ++i) {
      person_set_random(&p);
      list_push_front(h2_list, &p);
    }

    List_Handle h3_list = list_create();
    for(int i = 0; i < 8; ++i) {
      person_set_random(&p);
      list_push_front(h3_list, &p);
    }

    printf("List size: %zu\n", list_get_size(h1_list));
    list_print(h1_list);
    printf("List size: %zu\n", list_get_size(h2_list));
    list_print(h2_list);
    printf("List size: %zu\n", list_get_size(h3_list));
    list_print(h3_list);

    // output ->
    //  List size: 3
    //  10466 mehmet         kirboga        19 Haziran 1951 Sali
    //  4069  binnaz         efelik         04 Mayis 1951 Cuma
    //  10091 sevim          engerek        25 Eylul 1945 Sali
    //  ---------------------------------------------------
    //  List size: 5
    //  17757 burhan         kalpten        16 Haziran 2017 Cuma
    //  10485 orkun          fitrat         26 Subat 1988 Cuma
    //  14492 sadegul        yaygara        22 Agustos 1948 Pazar
    //  3087  petek          emirkulu       07 Kasim 2016 Pazartesi
    //  22235 mert           ordulu         26 Ocak 1958 Pazar
    //  ---------------------------------------------------
    //  List size: 8
    //  4988  devrim         karasaban      21 Mayis 1947 Carsamba
    //  25567 cebrail        yilmaz         20 Haziran 1947 Cuma
    //  29762 murat          gumus          10 Nisan 2012 Sali
    //  12821 emrecan        osmaneli       08 Temmuz 2016 Cuma
    //  25689 gulden         yorgun         09 Agustos 1946 Cuma
    //  7353  atif           haselici       29 Aralik 1988 Persembe
    //  16237 akin           konca          23 Mayis 2020 Cumartesi
    //  17726 julide         elebasi        23 Nisan 1996 Sali
    //  ---------------------------------------------------

    list_destroy(h1_list);
    list_destroy(h2_list);
    list_destroy(h3_list);
  }
*/

/*
  #include "../headers/handle_person_list.h"
  #include "../headers/nutility.h"
  #include "../headers/person.h"
  #include <stdlib.h> // rand

  #define   LIST_COUNT  1000

  int main(void)
  {
    randomize();

    List_Handle list_arr[LIST_COUNT];

    Person_t person;
    for (int i = 0; i < LIST_COUNT; ++i){
      list_arr[i] = list_create();

      int N = rand() % 10 + 5;
      while (N--){
        person_set_random(&person);
        list_push_front(list_arr[i], &person);
      }
    }

    int idx = 10;
    printf("List size: %zu\n", list_get_size(list_arr[idx]));
    list_print(list_arr[idx]);
    // output ->
    //  List size: 6
    //  20647 derya          osmaneli       13 Ekim 2009 Sali
    //  19015 hasan          boztas         23 Aralik 2008 Sali
    //  5368  nurdan         yangin         05 Subat 1982 Cuma
    //  21773 ercument       miskinoglu     09 Subat 1944 Carsamba
    //  18929 burak          onaran         02 Subat 2020 Pazar
    //  2645  ege            aylak          20 Mart 1997 Persembe
    //  ---------------------------------------------------

    idx = 12;
    printf("List size: %zu\n", list_get_size(list_arr[idx]));
    list_print(list_arr[idx]);
    // output ->
    //  List size: 11
    //  15375 muslum         esteberli      10 Ekim 1972 Sali
    //  32570 akin           sefiloglu      02 Ekim 2020 Cuma
    //  30381 sabriye        celik          10 Haziran 1940 Pazartesi
    //  24726 sami           karaelmas      05 Aralik 1989 Sali
    //  17145 baran          esnedur        09 Mayis 1974 Persembe
    //  23690 agah           uluocak        22 Temmuz 2010 Persembe
    //  8211  aslihan        lalezar        25 Temmuz 1961 Sali
    //  3603  necmi          sonuzun        16 Ekim 2012 Sali
    //  12723 demir          safkan         14 Nisan 2001 Cumartesi
    //  14666 kerim          sallabas       11 Eylul 2000 Pazartesi
    //  26624 tayyar         arcan          26 Ekim 1944 Persembe
    //  ---------------------------------------------------

    idx = 455;
    printf("List size: %zu\n", list_get_size(list_arr[idx]));
    list_print(list_arr[idx]);
    // output ->
    //  List size: 13
    //  31400 emine          aylak          09 Mayis 1959 Cumartesi
    //  12011 nefes          karaduman      27 Ekim 1984 Cumartesi
    //  27216 sefa           tantana        10 Temmuz 1968 Carsamba
    //  30974 su             candamar       22 Nisan 1962 Pazar
    //  183   yeliz          cuhadar        28 Mart 1995 Sali
    //  13016 yelda          karasaban      20 Ekim 1946 Pazar
    //  20500 temel          degirmenci     06 Kasim 2023 Pazartesi
    //  6490  zahide         firatonu       12 Ekim 2013 Cumartesi
    //  29585 korhan         sessiz         03 Haziran 1945 Pazar
    //  6146  aslican        kirboga        31 Ocak 2016 Pazar
    //  14767 cesim          otaci          01 Subat 1946 Cuma
    //  8171  ugur           uraz           03 Kasim 1992 Sali
    //  26856 lamia          elmali         06 Haziran 1990 Carsamba
    //  ---------------------------------------------------

    idx = 999;
    printf("List size: %zu\n", list_get_size(list_arr[idx]));
    list_print(list_arr[idx]);
    // output ->
    //  List size: 6
    //  21433 sarp           ademoglu       02 Mart 2007 Cuma
    //  11150 muruvvet       saferikli      27 Ocak 2011 Persembe
    //  31083 hande          cansiz         15 Mart 1999 Pazartesi
    //  23757 candan         karaorman      01 Subat 1948 Pazar
    //  23326 teoman         kapan          04 Haziran 2013 Sali
    //  5604  tugra          erdogan        11 Kasim 1944 Cumartesi
    //  ---------------------------------------------------
  }
*/

/*
                    ------------------------
                    | alignment (hizalama) |
                    ------------------------
*/

/*
  - işlemcilerin bellekte tutulan değişkenlere düşük maliyette
    erişebilmeleri için, değişkenler bellekte 
    belirli tam sayıların katları olan adreslerde tutuluyorlar.
*/

/*
  // alignment requirement for int type is 4 bytes
  // alignment requirement for double type is 8 bytes
  // alignment requirement for short type is 2 bytes

  #include <stdint.h> // uintptr_t

  int main(void)
  {
    int i1 = 5, i2 = 10, i3 = 15;
    double d1 = 3.33, d2 = 4.44;
    short s1, s2, s3, s4;

    printf("%d\n", (uintptr_t)&i1 % 4 == 0);  // output -> 1
    printf("%d\n", (uintptr_t)&i2 % 4 == 0);  // output -> 1
    printf("%d\n", (uintptr_t)&i3 % 4 == 0);  // output -> 1

    printf("%d\n", (uintptr_t)&d1 % 8 == 0);  // output -> 1
    printf("%d\n", (uintptr_t)&d2 % 8 == 0);  // output -> 1

    printf("%d\n", (uintptr_t)&s1 % 2 == 0);  // output -> 1
    printf("%d\n", (uintptr_t)&s2 % 2 == 0);  // output -> 1
    printf("%d\n", (uintptr_t)&s3 % 2 == 0);  // output -> 1
    printf("%d\n", (uintptr_t)&s4 % 2 == 0);  // output -> 1
  }
*/

/*
  // "_Alignof" operator used for determining 
  // alignment requirement of a type in compile time.

  int main(void)
  {
    printf("%zu\n", _Alignof(short));  // output -> 2
    printf("%zu\n", _Alignof(int));    // output -> 4
    printf("%zu\n", _Alignof(double)); // output -> 8
  }
*/

/*
  // alignment requirement and sizeof are different things.

  int main(void)
  {
    printf("_Alignof(int[100]) = %zu\n", _Alignof(int[100]));  
    // output -> _Alignof(int[100]) = 4

    printf("sizeof(int[100]) = %zu\n", sizeof(int[100]));
    // output -> sizeof(int[100]) = 400
  }
*/

/*
  // for structure types, alignment requirement is
  // the maximum alignment requirement of its members.

  typedef struct {
    int m_x, m_y, m_z;
    double m_d1, m_d2;
    char m_c1, m_c2;
  } Data_t;

  int main(void)
  {
    printf("_Alignof(Data_t) = %zu\n", _Alignof(Data_t));
    // output -> _Alignof(Data_t) = 8

    printf("sizeof(Data_t) = %zu\n", sizeof(Data_t));
    // output -> sizeof(Data_t) = 32

    // because of double type's alignment requirement is 8 bytes
    // alignment requirement of Data_t is 8 bytes.
  }
*/

/*
  #include <stdalign.h>   // "alignof" is a macro

  // _Alignof keyword deprecated in C23 standart
  // C23 standart -> alignof is a keyword
  // https://en.cppreference.com/w/c/language/_Alignof

  typedef struct {
    int m_x, m_y, m_z;
    double m_d1, m_d2;
    char m_c1, m_c2;
  } Data_t;

  int main(void)
  {
    printf("alignof(Data_t) = %zu\n", alignof(Data_t));
    // output -> alignof(Data_t) = 8

    printf("sizeof(Data_t) = %zu\n", sizeof(Data_t));
    // output -> sizeof(Data_t) = 32
  }
*/

/*
  SIMD operasyonlarının verimli olabilmesi için  
  bazen türlerin belli sayıların katı olan adreslerde
  tutulması gerekebilir.
  bunun için "_Alignas" keyword kullanılır.
*/

/*
  // _Alignas keyword(since C11)
  // alignas keyword(since C23)
  // alignas macro in <stdalign.h> header

  #include <stdint.h> // uintptr_t

  int main(void)
  {
    // ----------------------------------------------
    _Alignas(64) int x = 10;
    printf("%d\n", (uintptr_t)&x % 64 == 0);  // output -> 1
    // x will be stored in an address that is multiple of 64

    alignas(128) char buffer[1024];
    printf("%d\n", (uintptr_t)buffer % 128 == 0);
    // buffer will be stored in an address that is multiple of 128
  }
*/

/*
  typedef struct {
    char c1;
    int i1;
    char c2;
    long long l1;
    char c3;
  } Data;

  // 1000 - c1
  // 1001 - padding
  // 1002 - padding
  // 1003 - padding
  // 1004 - i1
  // 1005 - i1
  // 1006 - i1
  // 1007 - i1
  // 1008 - c2
  // 1009 - padding
  // 100A - padding
  // 100B - padding
  // 100C - padding --> 100C % 8 != 0 
  // 100D - padding
  // 100E - padding
  // 100F - padding
  // 1010 - l1      --> alignment requirement of long long is 8 bytes
  // 1011 - l1
  // 1012 - l1
  // 1013 - l1
  // 1014 - l1
  // 1015 - l1
  // 1016 - l1
  // 1017 - l1
  // 1018 - c3
  // 1019 - padding
  // 101A - padding
  // 101B - padding
  // 101C - padding
  // 101D - padding
  // 101E - padding
  // 101F - padding

  int main(void)
  {
    printf("sizeof(Data) = %zu\n", sizeof(Data));
    // output -> sizeof(Data) = 32

    // char(1) + int(4) + char(1) + long long(8) + char(1) = 15
    // because of the alignment requirements of data members 
    // 17 padding bytes will be added to the structure.
  }
*/

/*
  #pragma pack(1) 
  // alignment requirement for each type will be 1(byte alignment)
  // this is bad for efficiency
  // but it is good for memory

  typedef struct {
    char c1;
    int i1;
    char c2;
    long long l1;
    char c3;
  } Data;


  int main(void)
  {
    printf("sizeof(Data) = %zu\n", sizeof(Data));
    // output -> sizeof(Data) = 15
  }
*/

/*
  // better using an order from the highest alignment requirement 
  // to lowest when declaring data members of the struct.

  typedef struct {
    long long l1;
    int i1;
    char c1;
    char c2;
    char c3;
  } Data;


  int main(void)
  {
    printf("sizeof(Data) = %zu\n", sizeof(Data));
    // output -> sizeof(Data) = 16
  }
*/

/*
                      ------------------
                      | offsetof macro |
                      ------------------
*/

/*
  typedef struct {
    char m_c1;
    int m_i1;
    char m_c2;
  } Data_t;

  // 1000 : m_c1
  // 1001 : padding
  // 1002 : padding
  // 1003 : padding
  // 1004 : m_i1
  // 1005 : m_i1
  // 1006 : m_i1
  // 1007 : m_i1
  // 1008 : m_c2
  // 1009 : padding
  // 100A : padding
  // 100B : padding

  int main(void)
  {
    printf("sizeof(Data_t) = %zu\n", sizeof(Data_t));
    // sizeof(Data_t) = 12

    Data_t d1 = { .m_c1 = 65, .m_i1 = 817283, .m_c2 = 78 };

    char* cp = &d1.m_c1;
    printf("c1 = %d\n", *cp);  // output -> c1 = 65

    ++cp;
    int* ip = (int*)cp; 
    printf("i1 = %d\n", *ip);  // undefined behaviour (UB)

    // "++cp" expression the address of padding bytes
    // so dereferencing indeterminate value
    // is an undefined behaviour(UB)
  }
*/

/*
  #include <stddef.h> // offsetof

  typedef struct {
    char m_c1;    // 0
    int m_i1;     // 4
    char m_c2;    // 8
  } Data_t;

  // 1000 : m_c1      -> 0
  // 1001 : padding
  // 1002 : padding
  // 1003 : padding
  // 1004 : m_i1      -> 4
  // 1005 : m_i1
  // 1006 : m_i1
  // 1007 : m_i1
  // 1008 : m_c2      -> 8
  // 1009 : padding
  // 100A : padding
  // 100B : padding

  int main(void)
  {
    printf("offsetof(Data_t, m_c1) = %zu\n", 
            offsetof(Data_t, m_c1));
    // output -> offsetof(Data_t, m_c1) = 0

    printf("offsetof(Data_t, m_i1) = %zu\n", 
            offsetof(Data_t, m_i1));
    // output -> offsetof(Data_t, m_i1) = 4

    printf("offsetof(Data_t, m_c2) = %zu\n", 
            offsetof(Data_t, m_c2));
    // output -> offsetof(Data_t, m_c2) = 8
  }
*/

/*
  #include <stddef.h> // offsetof

  #pragma pack(1) // byte alignment

  typedef struct {
    char m_c1;    // 0
    int m_i1;     // 1
    char m_c2;    // 5
  } Data_t;

  // 1000 : m_c1      -> 0
  // 1004 : m_i1      -> 1
  // 1005 : m_i1
  // 1006 : m_i1
  // 1007 : m_i1
  // 1008 : m_c2      -> 5

  int main(void)
  {
    printf("offsetof(Data_t, m_c1) = %zu\n", 
            offsetof(Data_t, m_c1));
    // output -> offsetof(Data_t, m_c1) = 0

    printf("offsetof(Data_t, m_i1) = %zu\n", 
            offsetof(Data_t, m_i1));
    // output -> offsetof(Data_t, m_i1) = 1

    printf("offsetof(Data_t, m_c2) = %zu\n", 
            offsetof(Data_t, m_c2));
    // output -> offsetof(Data_t, m_c2) = 5
  }
*/

/*
  #define OFFSETOF(s, m)    ((size_t)&(((s*)0)->m))
  // s : structure
  // m : data member
*/

/*
  #include <stddef.h> // offsetof

  typedef struct {
    char m_c1;
    int m_i1;
    char m_c2;
  } Data_t;

  // 1000 : m_c1
  // 1001 : padding
  // 1002 : padding
  // 1003 : padding
  // 1004 : m_i1
  // 1005 : m_i1
  // 1006 : m_i1
  // 1007 : m_i1
  // 1008 : m_c2
  // 1009 : padding
  // 100A : padding
  // 100B : padding

  int main(void)
  {
    Data_t d1 = { .m_c1 = 65, .m_i1 = 817283, .m_c2 = 78 };

    char* cp = &d1.m_c1;
    printf("d1.m_c1 = %d\n", *cp);  
    // output -> d1.m_c1 = 65

    int* ip = (int*)(cp + offsetof(Data_t, m_i1)); 
    printf("d1.m_i1 = %d\n", *ip);
    // output -> d1.m_i1 = 817283
  }
*/

/*
              ---------------------------------
              | comparison of structure types |
              ---------------------------------
*/

/*
  #include <string.h> // memcmp

  typedef struct {
    char m_c1;
    int m_i1;
    char m_c2;
  } Data_t;

  int main(void)
  {
    printf("sizeof(Data_t) = %zu\n", sizeof(Data_t));

    Data_t d1 = { .m_c1 = 65, .m_i1 = 817283, .m_c2 = 78 };
    Data_t d2 = { .m_c1 = 65, .m_i1 = 817283, .m_c2 = 78 };

    // ----------------------------------------------

    if (d1.m_c1 == d2.m_c1 && 
        d1.m_i1 == d2.m_i1 && 
        d1.m_c2 == d2.m_c2)
      printf("d1 and d2 are equal\n");
    else
      printf("d1 and d2 are not equal\n");

    // output -> d1 and d2 are equal

    // ----------------------------------------------

    if (!memcmp(&d1, &d2, sizeof(Data_t)))
      printf("d1 and d2 are equal\n");
    else
      printf("d1 and d2 are not equal\n");

    // output -> d1 and d2 are not equal
    // also checking for the padding bytes which are
    // not initialized in the structure(have garbage values).

    // ----------------------------------------------
  }
*/

/*
  // before doing comparison in structure types 
  // we need to clear the memory with memset

  #include <string.h> // memset, memcmp

  typedef struct {
    char m_c1;
    int m_i1;
    char m_c2;
  } Data_t;

  int main(void)
  {
    Data_t d1, d2;
    memset(&d1, 0, sizeof(d1));
    memset(&d2, 0, sizeof(d2));

    // compound literal
    d1 = (Data_t){ .m_c1 = 65, .m_i1 = 817283, .m_c2 = 78 };
    d2 = (Data_t){ .m_c1 = 65, .m_i1 = 817283, .m_c2 = 78 };

    // ----------------------------------------------

    if (d1.m_c1 == d2.m_c1 && 
        d1.m_i1 == d2.m_i1 && 
        d1.m_c2 == d2.m_c2)
      printf("d1 and d2 are equal\n");
    else
      printf("d1 and d2 are not equal\n");

    // output -> d1 and d2 are equal

    // ----------------------------------------------

    if (!memcmp(&d1, &d2, sizeof(Data_t)))
      printf("d1 and d2 are equal\n");
    else
      printf("d1 and d2 are not equal\n");

    // output -> d1 and d2 are equal

    // ----------------------------------------------
  }
*/

/*
  // macro for clearing structure types

  #include <string.h> // memset, memcmp

  #define clear_struct(x)     (memset(&(x), 0, sizeof(x)))

  typedef struct {
    char m_c1;
    int m_i1;
    char m_c2;
  } Data_t;

  int main(void)
  {
    Data_t d1, d2;
    clear_struct(d1);
    clear_struct(d2);

    // compound literal
    d1 = (Data_t){ .m_c1 = 65, .m_i1 = 817283, .m_c2 = 78 };
    d2 = (Data_t){ .m_c1 = 65, .m_i1 = 817283, .m_c2 = 78 };

    if (!memcmp(&d1, &d2, sizeof(Data_t)))
      printf("d1 and d2 are equal\n");
    else
      printf("d1 and d2 are not equal\n");
    // output -> d1 and d2 are equal
  }
*/

/*
                          ----------
                          | unions |
                          ----------
*/

/*
  typedef union Data {
    int m_x, m_y;
    double m_d;
    char m_carr[8];
  } Data_t;

  int main(void)
  {
    Data_t d1;
    Data_t* dp = &d1;

    d1.m_x = 11;
    dp->m_x = 22;
  }
*/

/*
  // size of a union is the size of its largest data member

  typedef struct {
    int m_x;
  } struct_Data_t;

  typedef union {
    int m_x;
  } union_Data_t;

  typedef struct {
    int m_x, m_y;
  } struct_Data2_t;

  typedef union {
    int m_x, m_y;
  } union_Data2_t;

  typedef struct {
    int m_x, m_y, m_z;
  } struct_Data3_t;

  typedef union {
    int m_x, m_y, m_z;
  } union_Data3_t;

  typedef struct {
    double m_d;
    int m_x, m_y, m_z;
  } struct_Data4_t;

  typedef union {
    double m_d;
    int m_x, m_y, m_z;
  } union_Data4_t;

  typedef struct {
    double m_d1, m_d2;
    int m_x, m_y, m_z;
  } struct_Data5_t;

  typedef union {
    double m_d1, m_d2;
    int m_x, m_y, m_z;
  } union_Data5_t;

  typedef struct {
    char m_carr[16];
    double m_d1, m_d2;
    int m_x, m_y, m_z;
  } struct_Data6_t;

  typedef union {
    char m_carr[16];
    double m_d1, m_d2;
    int m_x, m_y, m_z;
  } union_Data6_t;

  int main(void)
  {
    // ----------------------------------------------

    printf("sizeof(struct_Data_t) = %zu\n", 
            sizeof(struct_Data_t));
    // output -> sizeof(struct_Data_t) = 4

    printf("sizeof(union_Data_t) = %zu\n", 
            sizeof(union_Data_t));
    // output -> sizeof(union_Data_t) = 4

    // ----------------------------------------------

    printf("sizeof(struct_Data2_t) = %zu\n", 
            sizeof(struct_Data2_t));
    // output -> sizeof(struct_Data2_t) = 8

    printf("sizeof(union_Data2_t) = %zu\n", 
            sizeof(union_Data2_t));
    // output -> sizeof(union_Data2_t) = 4

    // ----------------------------------------------

    printf("sizeof(struct_Data3_t) = %zu\n", 
            sizeof(struct_Data3_t));
    // output -> sizeof(struct_Data3_t) = 12

    printf("sizeof(union_Data3_t) = %zu\n", 
            sizeof(union_Data3_t));
    // output -> sizeof(union_Data3_t) = 4

    // ----------------------------------------------

    printf("sizeof(struct_Data4_t) = %zu\n", 
            sizeof(struct_Data4_t));
    // output -> sizeof(struct_Data4_t) = 24
  
    printf("sizeof(union_Data4_t) = %zu\n", 
            sizeof(union_Data4_t));
    // output -> sizeof(union_Data4_t) = 8

    // ----------------------------------------------

    printf("sizeof(struct_Data5_t) = %zu\n", 
            sizeof(struct_Data5_t));
    // output -> sizeof(struct_Data5_t) = 32

    printf("sizeof(union_Data5_t) = %zu\n", 
            sizeof(union_Data5_t));
    // output -> sizeof(union_Data5_t) = 8

    // ----------------------------------------------

    printf("sizeof(struct_Data6_t) = %zu\n", 
            sizeof(struct_Data6_t));
    // output -> sizeof(struct_Data6_t) = 48

    printf("sizeof(union_Data6_t) = %zu\n", 
            sizeof(union_Data6_t));
    // output -> sizeof(union_Data6_t) = 16

    // ----------------------------------------------
  }
*/

/*
  // union's data member's addresses are same.
  // when a data member change all data members changes.

  typedef union {
    char m_str[16];
    double m_d1;
    int m_x;
    char m_c;
  } Data_t;

  int main(void)
  {
    Data_t d1;

    printf("&d1        = %p\n", (void*)&d1);  
    printf("&d1.m_str  = %p\n", (void*)&d1.m_str);
    printf("&d1.m_d1   = %p\n", (void*)&d1.m_d1);
    printf("&d1.m_x    = %p\n", (void*)&d1.m_x);
    printf("&d1.m_c    = %p\n", (void*)&d1.m_c);
    // output ->
    //  &d1        = 000000A2F2BFFC70
    //  &d1.m_str  = 000000A2F2BFFC70
    //  &d1.m_d1   = 000000A2F2BFFC70
    //  &d1.m_x    = 000000A2F2BFFC70
    //  &d1.m_c    = 000000A2F2BFFC70
  }
*/

/*
  typedef struct {
    char m_str[16];
    double m_d1;
    int m_x;
    char m_c;
  } sData_t;

  typedef union {
    char m_str[16];
    double m_d1;
    int m_x;
    char m_c;
  } uData_t;

  int main(void)
  {
    sData_t sd1 = { "hello", 3.14, 123, 'A' };


    uData_t ud1 = { "hello" };  
    // initializing union's first element

    uData_t ud2 = {.m_c = 'B'};
    // initializing union's elements by using designated initializer
  }
*/

/*
  // unions are used for representing an object 
  // in different ways.

  // öyle bir tamsayı türüne ihtiyaç var ki 
  // 4 bytelık 1 tamsayı 
  // 2 bytelık 2 tamsayı 
  // 1 bytelık 4 tamsayı  olarak kullanılabilecek.

  #include <stdint.h> // uint32_t, uint16_t, uint8_t

  typedef struct {
    uint16_t m_high;
    uint16_t m_low;
  } Word_t;

  typedef union {
    uint32_t m_extended;
    Word_t m_word;
    uint8_t m_byte_arr[4];
  } u_MyInt_t;

  int main(void)
  {
    // ----------------------------------------------

    printf("sizeof(Word_t) = %zu\n", sizeof(Word_t));
    // output -> sizeof(Word_t) = 4

    printf("sizeof(u_MyInt_t) = %zu\n", sizeof(u_MyInt_t));
    // output -> sizeof(u_MyInt_t) = 4

    // ----------------------------------------------

    u_MyInt_t i1 = { .m_extended = 287497727 };
    // 287497727 = 0X1122DDFF

    // - Little indian system -

    printf("%X\n", i1.m_extended);      // output -> 1122DDFF
    printf("%X\n", i1.m_word.m_high);   // output -> DDFF
    printf("%X\n", i1.m_word.m_low);    // output -> 1122
    printf("%X\n", i1.m_byte_arr[0]);   // output -> FF
    printf("%X\n", i1.m_byte_arr[1]);   // output -> DD
    printf("%X\n", i1.m_byte_arr[2]);   // output -> 22
    printf("%X\n", i1.m_byte_arr[3]);   // output -> 11

    i1.m_byte_arr[0] = 0x33;
    i1.m_byte_arr[1] = 0x44;

    printf("%X\n", i1.m_extended);      // output -> 11224433
    printf("%X\n", i1.m_word.m_high);   // output -> 4433
    printf("%X\n", i1.m_word.m_low);    // output -> 1122

    // ----------------------------------------------
  }
*/

/*
  // using anonymous structure inside union

  #include <stdint.h> // uint32_t, uint16_t, uint8_t

  typedef union {
    uint32_t m_extended;
    struct {
      uint16_t m_high;
      uint16_t m_low;
    };
    uint8_t m_byte_arr[4];
  } u_MyInt_t;

  int main(void)
  {
    u_MyInt_t i1;

    i1.m_high = 0xAABB;
    i1.m_low  = 0xCCDD;

    printf("%X\n", i1.m_extended);      // output -> CCDDAABB
  }
*/

/*
  #include <stdint.h>   // uint16_t, uint32_t, uint64_t
  #include <inttypes.h> // PRIu64

  typedef union {
    struct {
      uint16_t m_d;
      uint16_t m_m;
      uint32_t m_y;
    };
    uint64_t m_value;
  } Date_t;

  int main(void)
  {
    printf("sizeof(Date_t) = %zu\n", sizeof(Date_t));
    // output -> sizeof(Date_t) = 8

    Date_t d1 = { .m_d = 01, .m_m = 01, .m_y = 2001 };
    
    printf("%" PRIu64 "\n", d1.m_value);
    // output -> 8594229624833

    // Date is mapped to a distinct integer value
    // which in this case is 8594229624833

    d1.m_m = 12, d1.m_d = 12, d1.m_y = 2012;

    printf("%" PRIu64 "\n", d1.m_value);
    // output -> 8641474985996

    // mapped integer value is changed to 8641474985996
  }
*/

/*
  // öyle veriler var ki birinden birinin tutulması mantıklı.
  // bu durum için union kullanılır.

  // erkekler için askerlik bilgileri
  // kadınlar için kızlık soyadı tutulacak.

  // -- union kullanılmazsa. 
  // örneğin kadınlar için kızlık soyadı tutulacak,
  // askerlik bilgileri boş bırakılacak.
  // erkekler için askerlik bilgileri tutulacak,
  // kızlık soyadı boş bırakılacak.

  struct Person_1 {
    int m_id;
    int m_gender;
    char m_name[32];
    struct {
      int m_status;
      char m_location[32];
    };
    char m_maiden_name[32];
  };

  struct Person_2 {
    int m_id;
    int m_gender;
    char m_name[32];
    union {
      struct {
        int m_status;
        char m_location[32];
      };
      char m_maiden_name[32];
    };
  };

  int main(void)
  {
    printf("sizeof(struct Person_1) = %zu\n", 
            sizeof(struct Person_1));
    // output -> sizeof(struct Person_1) = 108

    printf("sizeof(struct Person_2) = %zu\n", 
            sizeof(struct Person_2));
    // output -> sizeof(struct Person_2) = 76
  }
*/

/*
            --------------------------------------
            | tagged union - discriminated union |
            --------------------------------------
*/

/*
  a variable that can be used as a
  - name
  - date
  - floating point
  - an integer
*/

/*
  #include "../headers/date.h"

  typedef union {
    char m_name[32];
    Date_t m_date;
    double m_dval;
    int m_ival;
  } Data_t;

  int main(void)
  {
    Data_t d1 = { .m_name = "hello world" };
    date_set(&d1.m_date, 1, 1, 2001);
    d1.m_dval = 3.14;
    d1.m_ival = 11111111;

    // we can not know if d1 is used as a name, as a  date, 
    // as a floating point, or as an integer? 
  }
*/


/*
  #include "../headers/date.h"
  #include "../headers/nutility.h"

  #include <stdlib.h> // rand
  #include <string.h> 

  #define   NAME    0
  #define   DATE    1
  #define   DOUBLE  2
  #define   INT     3
  #define   SIZE    10

  typedef struct {
    union {
      char m_name[32];
      Date_t m_date;
      double m_dval;
      int m_ival;
    };
    int m_type;
  } Tagged_t;


  void set_tagged(Tagged_t* p)
  {
    switch (rand() % 4) {
    case NAME: {
      strcpy(p->m_name, get_random_name()); 
      p->m_type = NAME;
      break;
    }
    case DATE: {
      date_set_random(&p->m_date); 
      p->m_type = DATE;
      break;
    }
    case DOUBLE: {
      p->m_dval = get_random_double(); 
      p->m_type = DOUBLE;
      break;
    }
    case INT: {
      p->m_ival = rand(); 
      p->m_type = INT;
      break;
    }
    }
  }

  void print_tagged(const Tagged_t* p)
  {
    switch (p->m_type) {
    case NAME: {
      printf("Type is m_name: ");
      printf("%s\n", p->m_name); 
      break;
    }
    case DATE: {
      printf("Type is m_date: ");
      date_print(&p->m_date); 
      break;
    }
    case DOUBLE: {
      printf("Type is m_dval: ");
      printf("%f\n", p->m_dval); 
      break;
    }
    case INT: {
      printf("Type is m_ival: ");
      printf("%d\n", p->m_ival); 
      break;
    }
    }
  }

  int main(void)
  {
    randomize();

    Tagged_t t1;

    for(int i = 0; i < 10; ++i){
      set_tagged(&t1);
      print_tagged(&t1);
    }

    // output ->
    //  Type is m_dval: 30.000000
    //  Type is m_ival: 18191
    //  Type is m_date: 26 Eylul 1974 Persembe
    //  Type is m_name: hikmet
    //  Type is m_dval: 16.000000
    //  Type is m_name: korhan
    //  Type is m_date: 23 Haziran 1968 Pazar
    //  Type is m_name: ismail
    //  Type is m_dval: 70.000000
    //  Type is m_name: soner

    // ----------------------------------------------

    Tagged_t t_arr[SIZE]; // mixed array 

    for (size_t i = 0; i < SIZE; ++i){
      set_tagged(&t_arr[i]);
      print_tagged(&t_arr[i]);
    }  
    // output ->
    //  Type is m_dval: 64.000000
    //  Type is m_name: gizem
    //  Type is m_date: 30 Nisan 2016 Cumartesi
    //  Type is m_ival: 16384
    //  Type is m_date: 27 Eylul 1962 Persembe
    //  Type is m_ival: 23157
    //  Type is m_ival: 22710
    //  Type is m_date: 01 Mayis 2008 Persembe
    //  Type is m_date: 17 Nisan 1967 Pazartesi
    //  Type is m_date: 21 Agustos 2005 Pazar

    // ----------------------------------------------
  }
*/

/*
                        ----------------
                        | enumarations |
                        ----------------
*/

/*
  problem domain'inde öyle varlıklar var ki, bu varlıklar
  önceden seçilmiş bir veri kümesindeki değerlerden birine 
  sahip olmak zorunda.

  örneğin 
    - haftanın günü 
    - iskambil kağıdının rengi
    - iskambil kağıdının değeri
    - kontrol cihazının durumu (ON - OFF - STANDBY)

  bu tür veriler için enumaration araç seti kullanılır.

  - enum türleri static veri sisteminde tam sayı türlerinin 
    bir alt kümesidir, aynı zamanda bir user-defined türdür.

  syntax : enum <enum_Tag(optional)> { <enumerator_list> };

  - enumaration constant (enumarator)
*/

/*
  enum Color { Red, Green, Blue };
  // `enum Color` is an integer type, its type is `enum Color`

  typedef enum Color Color_t;
*/

/*
  typedef enum { Red, Green, Blue } Color_t;
  // Red, Green, Blue are constants and their type is `int`
  // if not specified, Red = 0, Green = 1, Blue = 2
*/

/*
  typedef enum { Red, Green, Blue } Color_t;

  void func(Color_t);
  Color_t func2(void);

  struct Data_t {
    Color_t m_color;
  };  

  int main(void)
  {
    Color_t c1 = Blue;
    printf("%d\n", c1);       // output -> 2

    printf("%d\n", Red);      // output -> 0
    printf("%d\n", Green);    // output -> 1
    printf("%d\n", Blue);     // output -> 2
  }
*/

/*
  typedef enum { Red, Green, Blue } Color_t;

  const char* get_color_str(Color_t c)
  {
    static const char* const str_arr[] = { "Red", "Green", "Blue" };
    return str_arr[c];
  } 

  int main(void)
  {
    Color_t c1 = Blue;
    printf("%s\n", get_color_str(c1));  // output -> Blue

    c1 = Red;
    printf("%s\n", get_color_str(c1));  // output -> Red
  }
*/

/*
  typedef enum {
    Monday      = 1, 
    Tuesday     = 3, 
    Wednesday   = 5, 
    Thursday    = 7,  
    Friday      = 9, 
    Saturday    = 11, 
    Sunday      = 13
  } Weekday_t;

  int main(void)
  {
    printf("%d\n", Monday);     // output -> 1
    printf("%d\n", Tuesday);    // output -> 3
    printf("%d\n", Wednesday);  // output -> 5
    printf("%d\n", Thursday);   // output -> 7
    printf("%d\n", Friday);     // output -> 9
    printf("%d\n", Saturday);   // output -> 11
    printf("%d\n", Sunday);     // output -> 13
  }
*/

/*
  typedef enum {
    Monday = 5,
    Tuesday,     
    Wednesday,   
    Thursday,     
    Friday,      
    Saturday,     
    Sunday     
  } Weekday_t;

  int main(void)
  {
    printf("%d\n", Monday);     // output -> 5
    printf("%d\n", Tuesday);    // output -> 6
    printf("%d\n", Wednesday);  // output -> 7
    printf("%d\n", Thursday);   // output -> 8
    printf("%d\n", Friday);     // output -> 9
    printf("%d\n", Saturday);   // output -> 10
    printf("%d\n", Sunday);     // output -> 11
  }
*/

/*
  typedef enum {
    Monday      = 5,
    Tuesday,     
    Wednesday   = 52,   
    Thursday,     
    Friday      = 77,      
    Saturday,     
    Sunday     
  } Weekday_t;

  int main(void)
  {
    printf("%d\n", Monday);     // output -> 5
    printf("%d\n", Tuesday);    // output -> 6
    printf("%d\n", Wednesday);  // output -> 52
    printf("%d\n", Thursday);   // output -> 53
    printf("%d\n", Friday);     // output -> 77
    printf("%d\n", Saturday);   // output -> 78
    printf("%d\n", Sunday);     // output -> 79
  }
*/

/*
  typedef enum {
    Monday      = 99,
    Tuesday,     
    Wednesday   = 55,   
    Thursday,     
    Friday      = 11,      
    Saturday,     
    Sunday     
  } Weekday_t;

  int main(void)
  {
    printf("%d\n", Monday);     // output -> 99
    printf("%d\n", Tuesday);    // output -> 100
    printf("%d\n", Wednesday);  // output -> 55
    printf("%d\n", Thursday);   // output -> 56
    printf("%d\n", Friday);     // output -> 11
    printf("%d\n", Saturday);   // output -> 12
    printf("%d\n", Sunday);     // output -> 13
  }
*/

/*
  typedef enum {
    Monday      = 99,
    Tuesday,     
    Wednesday   = -55,   
    Thursday,     
    Friday      = -11,      
    Saturday,     
    Sunday     
  } Weekday_t;

  int main(void)
  {
    printf("%d\n", Monday);     // output -> 99
    printf("%d\n", Tuesday);    // output -> 100
    printf("%d\n", Wednesday);  // output -> -55
    printf("%d\n", Thursday);   // output -> -54
    printf("%d\n", Friday);     // output -> -11
    printf("%d\n", Saturday);   // output -> -10
    printf("%d\n", Sunday);     // output -> -9
  }
*/

/*
  // more than one enumerator can have the same value

  typedef enum {
    Monday      = 1,
    Tuesday,     
    Wednesday,      
    Thursday,     
    Friday      = 1,      
    Saturday,     
    Sunday     
  } Weekday_t;

  int main(void)
  {
    printf("%d\n", Monday);     // output -> 1
    printf("%d\n", Tuesday);    // output -> 2
    printf("%d\n", Wednesday);  // output -> 3
    printf("%d\n", Thursday);   // output -> 4
    printf("%d\n", Friday);     // output -> 1
    printf("%d\n", Saturday);   // output -> 2
    printf("%d\n", Sunday);     // output -> 3
  }
*/

/*
  typedef enum {
    Small   = 10,
    Medium  = 20,
    Large   = 30,
    XLarge  = 40
  } Count_t;

  int main(void)
  {
    int count_arr[Medium] = { 0 };
  }
*/

/*
  typedef enum Color {
    Red, Green, Blue
  } Color_t;

  void pick_red(void);
  void pick_green(void);
  void pick_blue(void);

  void color_picker(Color_t c)
  {
    switch (c) {
    case Red:
      pick_red(); break;
    case Green:
      pick_green(); break;
    case Blue:
      pick_blue(); break;
    }
  }
*/

/*
  // https://i-p-c-s.org/faq/suit-ranking.php

  // for ninety-nine card game
  // order of suits -> (Club > Heart > Spade > Diamond)
  // for bridge card game
  // order of suits -> (Spade > Heart > Diamond > Club)

  #define BRIDGE
  // #define NINETY_NINE

  #ifdef NINETY_NINE
    typedef enum {
      Club, 
      Heart, 
      Spade, 
      Diamond
    } Suit_t;
  #elif defined(BRIDGE)
    typedef enum {
      Spade, 
      Heart, 
      Diamond, 
      Club
    } Suit_t;
  #endif
*/

/*
  #ifdef BLACKJACK
  typedef enum {
    Two     = 2,
    Three   = 3,
    Four    = 4,
    Five    = 5,
    Six     = 6,  
    Seven   = 7,
    Eight   = 8,
    Nine    = 9,
    Ten     = 10,
    Jack    = 10,
    Queen   = 10,
    King    = 10,
    Ace     = 11
  } Face_t;
  #endif  
*/

/*
  typedef enum {
    Two   ,
    Three ,
    Four  ,
    Five  ,
    Six   ,  
    Seven ,
    Eight ,
    Nine  ,
    Ten   , 
    Jack  , 
    Queen , 
    King  , 
    Ace   
  } Face_t;

  typedef enum {
    Club, 
    Heart, 
    Spade, 
    Diamond
  } Suit_t;

  typedef struct {
    Face_t m_face;
    Suit_t m_suit;
  } Card_t;
*/

/*
  typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
  } Weekday_t;

  struct Date {
    int m_year;
    int m_month;
    int m_day;
    Weekday_t m_wday;
  };
*/

/*
  typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
  } Weekday_t;

  typedef enum {
    CLUB,
    HEART,
    SPADE,
    DIAMOND
  } Suit_t;

  int main(void)
  {
    Weekday_t wd = 3; // VALID
    // control is applied for `int` type

    int ival = 23;
    wd = ival; // VALID
    // conversion from `int` to `Weekday_t` is valid.

    wd = DIAMOND; // VALID (logic error)
  }
*/

/*
  // identifier's(which are enumaration constants) scope
  // is same with the enumaration type itself.
  // in "screen.h" file 
  //  screen_color enumaration type is in file scope
  // in "traffic_light.h" file 
  //  traffic_light enumaration type is in file scope

  // screen.h
  // ----------------
  enum screen_color {
    WHITE,
    GREY,
    BLACK,
    RED,
    GREEN,
    BLUE,
  };

  // traffic_light.h
  // ----------------
  enum traffic_light {
    RED,
    YELLOW,
    GREEN,
  };

  // main.c
  // ----------------

  //  #include "screen.h"
  //  #include "traffic_light.h"

  // syntax error
  //  error: redeclaration of enumerator 'RED'
  //  note: previous definition of 'RED' 
  //  with type 'enum screen_color'
  //  error: redeclaration of enumerator 'GREEN'
  //  note: previous definition of 'GREEN' 
  //  with type 'enum screen_color'
*/

/*
  // to solve the problem of name collision

  // screen.h
  // ----------------
  enum screen_color {
    screen_color_WHITE,
    screen_color_GREY,
    screen_color_BLACK,
    screen_color_RED,
    screen_color_GREEN,
    screen_color_BLUE,
  };

  // traffic_light.h
  // ----------------
  enum traffic_light {
    traffic_light_RED,
    traffic_light_YELLOW,
    traffic_light_GREEN,
  };

  // main.c
  // ----------------

  //  #include "screen.h"
  //  #include "traffic_light.h"
*/

/*
  void foo(void)
  {
    enum Color { RED, GREEN, BLUE };
    // `enum Color` type is in foo function scope 
  }

  int main(void)
  {
    enum Color c1;  // syntax error
    // error: storage size of 'c1' isn't known

    c1 = RED;       // syntax error
    // error: 'RED' undeclared (first use in this function)
  }
*/

/*
  #define   ARRAY_SIZE    100
  // macros don't have scope

  enum { ARRAY_SIZE_2 = 100 };  
  // ARRAY_SIZE_2 enumaration constant can be used 
  // in this enumaration type's scope which is file scope.

  int global_arr[ARRAY_SIZE_2];

  void foo(void)
  {
    enum { ARRAY_SIZE_3 = 100 };
    // ARRAY_SIZE_3 enumaration constant can be used 
    // in this enumaration type's scope which is function scope.

    int local_arr[ARRAY_SIZE_3];
  }
*/

/*
  enum Color { 
    RED, 
    GREEN, 
    BLUE, 
    NO_OF_COLORS 
  };

  // NO_OF_COLORS enumaration constant's value is 3
  // which is the number of colors.

  // when a new color is added to the enumaration type
  // NO_OF_COLORS value will increase by one.

  int main(void)
  {
    for (int i = 0; i < NO_OF_COLORS; ++i)
      printf("%d\n", i);

    // can be used in a loop to iterate over the colors

    int arr[NO_OF_COLORS] = { 0 };
    // can be used to create an array to store the number of colors
  }
*/