#include <stdio.h>

/*
                    ========================
                    | C99 standard changes |
                    ========================
*/

/*
                -------------------------------
                | variable length array (VLA) |
                -------------------------------
*/

/*
  C99 - VLA (standart)
  C11 - VLA (optional)
*/

/*
  conditional compiling macro for VLA -> __STDC_NO_VLA__ (MSVC)

  #ifndef __STDC_NO_VLA__
    // VLA is supported
  #endif
*/

/*
  int main(void)
  {
    int N = 11;

    // --------------------------------------------------

    int i_arr[N]; // VALID

    // --------------------------------------------------

    int i_arr2[N] = { 1, 2, 3, 4, 5 };  // syntax error
    // error: variable-sized object may not be initialized 
    // except with an empty initializer

    // initializing syntax is not allowed for VLA

    // --------------------------------------------------
  }
*/

/*
  // there is no guarantee that sizeof operator will generate
  // a compile-time constant value for VLA

  void func(int N)
  {
    int i_arr[N];

    printf("sizeof(i_arr) = %zu\n", sizeof(i_arr));
    // "sizeof(i_arr)" expression 
    // will be calculated at runtime

    printf("i_arr size = %zu\n", sizeof(i_arr) / sizeof(i_arr[0])); 
  }

  int main(void)
  {
    func(11);
    // output ->
    //  sizeof(i_arr) = 44
    //  i_arr size = 11
  }
*/

/*
  #include <stddef.h> // size_t

  void func(int N)
  {
    int i_arr[N];

    for (int i = 0; i < N; ++i)
      i_arr[i] = i;

    for (int i = 0; i < N; ++i)
      printf("%d ", i_arr[i]);

    printf("\n");
  }

  int main(void)
  {
    func(7);  // output -> 0 1 2 3 4 5 6
    func(9);  // output -> 0 1 2 3 4 5 6 7 8
    func(11); // output -> 0 1 2 3 4 5 6 7 8 9 10
  }
*/

/*
  // VLA must be automatic storage duration object

  void func(int N)
  {
    static int i_arr[N]; // syntax error
    // error: storage size of 'i_arr' isn't constant
  }
*/

/*
  #include <stddef.h>   // size_t
  #include <stdlib.h>   // malloc, free exit, EXIT_FAILURE, qsort
  #include <stdio.h>    // fprintf
  #include <string.h>   // memcpy
  #include "../headers/nutility.h"

  int cmp_double_qsort(const void* vp1, const void* vp2)
  {
    typedef const double* C_DPTR;

    return  *(C_DPTR)vp1 > *(C_DPTR)vp2 
              ? 1 
              : *(C_DPTR)vp1 < *(C_DPTR)vp2 ? -1 : 0;
  }

  double get_median(const double* pa, size_t arr_size)
  {
    double* pd = malloc(arr_size * sizeof(double));

    if (!pd) {
      fprintf(stderr, "memory allocation failed\n");
      exit(EXIT_FAILURE);
    }

    memcpy(pd, pa, arr_size * sizeof(double));
    qsort(pd, arr_size, sizeof(*pd), &cmp_double_qsort);
    double result = pd[arr_size / 2];

    free(pd);
    return result;
  }

  int main(void)
  {
    double d_arr[] = { 
      3.14, 2.71, 1.41, 1.61, 1.73, 1.21, 1.51, 1.91 };

    double median = get_median(d_arr, asize(d_arr));

    printf("median = %f\n", median);
    // output -> median = 1.730000
  }
*/

/*
  // get_median function using VLA  

  #include <stddef.h>   // size_t
  #include <stdlib.h>   // qsort
  #include <string.h>   // memcpy
  #include "../headers/nutility.h"

  int cmp_double_qsort(const void* vp1, const void* vp2)
  {
    typedef const double* C_DPTR;

    return  *(C_DPTR)vp1 > *(C_DPTR)vp2 
              ? 1 
              : *(C_DPTR)vp1 < *(C_DPTR)vp2 ? -1 : 0;
  }

  double get_median(const double* pa, size_t arr_size)
  {
    double d_arr[arr_size];

    memcpy(d_arr, pa, arr_size * sizeof(double));
    qsort(d_arr, arr_size, sizeof(*d_arr), &cmp_double_qsort);
    double result = d_arr[arr_size / 2];

    return result;
  }

  int main(void)
  {
    double d_arr[] = { 
      3.14, 2.71, 1.41, 1.61, 1.73, 1.21, 1.51, 1.91 };

    double median = get_median(d_arr, asize(d_arr));

    printf("median = %f\n", median);
    // output -> median = 1.730000
  }
*/

/*
  void func(int N)
  {
    int i_arr[N];
    int(*p)[N] = &i_arr;    
    // p is a pointer to an array of N integers

    for (int i = 0 ; i <= N; ++i)
      (*p)[i] = i;

    for (int i = 0; i < N; ++i)
      printf("%d ", (*p)[i]);
    printf("\n");
  }

  void foo()
  {
    int i_arr[4] = { 11, 22, 33, 44 };
    int(*p)[4] = &i_arr;
    // p is a pointer to an array of 4 integers

    for (int i = 0; i < 4; ++i)
      printf("%d ", (*p)[i]);
    printf("\n");
  }

  int main(void)
  {
    foo();    // output -> 11 22 33 44
    func(5);  // output -> 0 1 2 3 4
  }
*/

/*
  void func(int row, int col)
  {
    int matrix[row][col];

    int val = 0;

    for (int i = 0; i < row; ++i)
      for (int k = 0; k < col; ++k) 
        matrix[i][k] = val++;

    for (int i = 0; i < row; ++i) {
      for (int k = 0; k < col; ++k) {
        printf("%d ", matrix[i][k]);
      }
      printf("\n");
    }
  }

  int main(void)
  {
    func(3, 4);
    // output ->
    //  0 1 2 3
    //  4 5 6 7
    //  8 9 10 11
  }
*/

/*
  #include <stdlib.h>   // malloc, free, exit, EXIT_FAILURE, rand
  #include <stdio.h>    // fprintf
  #include <stddef.h>   // size_t

  // "p[][]" matrix notation is NOT VALID
  void func_1(size_t row, size_t col)
  {
    int* p = malloc(row * col * sizeof(int));
    if (!p) {
      fprintf(stderr, "memory allocation failed\n");
      exit(EXIT_FAILURE);
    }

    // "p[]" expressions data type is int
    // "p[][]" expression is a syntax error

    for (size_t i = 0; i < row; ++i)
      for (size_t k = 0; k < col; ++k)
        p[i * col + k] = rand() % 10;

    for (size_t i = 0; i < row; ++i) {
      for (size_t k = 0; k < col; ++k)
        printf("%d ", p[i * col + k]);
      printf("\n");
    }

    free(p);
  }

  // "p[][]" matrix notation is VALID
  void func_2(int row, int col)
  {
    int(*p)[row][col] = malloc(sizeof(*p));
    // p is a pointer to a 2D array of integers
    if (!p) {
      fprintf(stderr, "memory allocation failed\n");
      exit(EXIT_FAILURE);
    }
  
    for (int i = 0; i < row; ++i)
      for (int k = 0; k < col; ++k)
        (*p)[i][k] = rand() % 10;

    for (int i = 0; i < row; ++i) {
      for (int k = 0; k < col; ++k)
        printf("%d ", (*p)[i][k]);
      printf("\n");
    }

    free(p);
  }

  int main(void)
  {
    func_1(3, 4);
    // output ->
    //  1 7 4 0
    //  9 4 8 8
    //  2 4 5 5
  
    func_2(3, 4);
    // output ->
    //  1 7 1 1
    //  5 2 7 6
    //  1 4 2 3
  }
*/

/*
                        ---------------------
                        | compound literals |
                        ---------------------
*/

/*
  void func(const int* p_arr, int size);

  int main(void)
  {
    // --------------------------------------------------

    int arr[] = { 1, 2, 3, 4, 5 };

    func(arr, 5);
    // people that read this code will think that "arr" 
    // identifier will be used later in the code.

    // --------------------------------------------------

    // but the only reason that an array will be used,
    // is passing it to a function as an argument
    // in this case, compound literals can be used.

    func((int[]){ 1, 2, 3, 4, 5 }, 5);
    //  "(int[]){ 1, 2, 3, 4, 5 }" is a compound literal

    // --------------------------------------------------
  }
*/

/*
  #include "../headers/nutility.h"

  #include <time.h>

  void func(const int* p){}

  int main(void)
  {
    func(&(int){ 5 });

    struct tm* p = localtime(&(time_t){ time(0) });

    print_array((int[5]){ 11, 22, 33, 44, 55 }, 5);
    // output ->  11  22  33  44  55

    int* p_arr = (int[]){ 11, 22, 33, 44, 66 };
    *p_arr = 99;
    p_arr[2] = 77;

    print_array(p_arr, 5);
    // output -> 99  22  77  44  66
  }
*/

/*
  #include "../headers/person.h"

  void func(const Person_t* p){}

  int main(void)
  {
    
    (int[]){ [2] = 33, [7] = 88 };

    (Person_t){ .m_name         = "hello",
                .m_surname      = "world",
                .m_id           = 1111,
                .m_birth_date   = { 1990, 1, 1 } };

    func(&(Person_t){ 1111, "n", "s", { 2000, 20, 20 } });

    char* str = (char[]){ "hello world" };
  }
*/

/*
  void print_arr(const int* p, int size)
  {
    for (int i = 0; i < size; ++i)
      printf("%d ", p[i]);
    printf("\n");
  }

  void func(int x, int y, int z)
  {
    print_arr((int[]){ x, y, z }, 3);
  }

  int main(void)
  {
    func(11, 22, 33);   // output -> 11 22 33
  }
*/

/*
  typedef struct {
    int m_x, m_y, m_z;
  } Point_t;

  void func(int i1, int i2, int i3)
  {
    Point_t p;
    // code...
    p = (Point_t){ i1, i2, i3 };
  }
*/

/*
  void print(const int* p, int size)
  {
    for (int i = 0; i < size; ++i)
      printf("%d ", p[i]);
    printf("\n");
  }

  int main(void)
  {
    int* p_arr;

    if (p_arr == NULL) {
      p_arr = (int[]){ 11, 22, 33, 44, 55 };
    }

    print(p_arr, 5);    // undefined behavior(UB)
    // warning: dangling pointer 'p_arr' 
    // to an unnamed temporary may be used 
  }
*/

/*
  typedef struct {
    int m_x, m_y;
  } Point_t;

  void draw_pixel_1(Point_t);
  void draw_pixel_2(const Point_t* p);

  void draw_line(void)
  {
    for(int i = 0; i < 10; ++i) 
    {
      draw_pixel_1((Point_t){ i, i });
      draw_pixel_2(&(Point_t){ i, i });
    }
  }
*/

/*
                    -------------------------
                    | flexible array member |
                    -------------------------
*/

/*
  #include <stdlib.h>   // malloc

  typedef struct {
    char m_name[32];
    char m_surname[32];
    int m_id;
    int* m_grades_arr;
  } Student_t;

  int main(void)
  {
    Student_t* ps = malloc(sizeof(Student_t));
    
    int N = 5;
    ps->m_grades_arr = malloc(N * sizeof(int));
    // hard to manage this code.
  }
*/

/*
  typedef struct {
    char m_name[32];
    char m_surname[32];
    int m_id;
    int m_grades_arr[];
  } Student_t;

  int main(void)
  {
    printf("sizeof(Student_t) = %zu\n", sizeof(Student_t));
    // output -> sizeof(Student_t) = 68

    // 32 + 32 + 4 = 68
    // m_grades_arr is a flexible array member
    // not a data member of the structure directly
  }
*/

/*
  typedef struct {
    char m_name[32];
    char m_surname[32];
    int m_grades_arr[];     // syntax error
    int m_id;
  } Student_t;

  //  error: flexible array member not at end of struct
*/

/*
  typedef struct {
    char m_name[32];
    char m_surname[32];
    int m_id;
    int m_exam_grades_arr[];    // syntax error
    int m_quiz_grades_arr[];
  } Student_t;

  // error: flexible array member not at end of struct
*/

/*
  #include <stdlib.h>   // malloc, free, exit, EXIT_FAILURE
  #include <string.h>   // strcpy
  #include <stddef.h>   // size_t

  typedef struct {
    char m_name[32];
    char m_surname[32];
    int m_id;
    int m_grades_arr[];
  } Student_t;

  int main(void)
  {
    int exam_count = 5;

    Student_t* p_s1 = 
      malloc(sizeof(Student_t) + (size_t)exam_count * sizeof(int));
    if (!p_s1) {
      fprintf(stderr, "memory allocation failed\n");
      exit(EXIT_FAILURE);
    }

    p_s1->m_id = 1111;
    strcpy(p_s1->m_name, "hello");
    strcpy(p_s1->m_surname, "world");

    for (int i = 0; i < exam_count; ++i)
      p_s1->m_grades_arr[i] = rand() % 100;

    // --------------------------------------------------

    Student_t s2 = *p_s1;
    // data members are copied but not the flexible array member

    printf("id = %d\n", s2.m_id);
    printf("name = %s\n", s2.m_name);
    printf("surname = %s\n", s2.m_surname);

    for (int i = 0; i < exam_count; ++i)
      printf("grade[%d] = %d\n", i, s2.m_grades_arr[i]);
    // undefined behavior(UB) 
    // trying to reach flexible array members which 
    // are not copied to the new object

    // --------------------------------------------------

    free(p_s1);
  }
*/

/*
  #include <stdlib.h>   // malloc, free, exit, EXIT_FAILURE
  #include <string.h>   // strcpy, memcpy
  #include <stddef.h>   // size_t

  typedef struct {
    char m_name[32];
    char m_surname[32];
    int m_id;
    int m_grades_arr[];
  } Student_t;

  int main(void)
  {
    int exam_count = 5;
    size_t student_storage_size = 
      sizeof(Student_t) + (size_t)exam_count * sizeof(int);
    

    Student_t* p_s1 = malloc(student_storage_size);

    if (!p_s1) {
      fprintf(stderr, "memory allocation failed\n");
      exit(EXIT_FAILURE);
    }

    p_s1->m_id = 1111;
    strcpy(p_s1->m_name, "hello");
    strcpy(p_s1->m_surname, "world");

    for (int i = 0; i < exam_count; ++i)
      p_s1->m_grades_arr[i] = rand() % 100;

    // --------------------------------------------------

    Student_t* p_s2 = malloc(student_storage_size);
    if (!p_s2) {
      fprintf(stderr, "memory allocation failed\n");
      exit(EXIT_FAILURE);
    }

    memcpy(p_s2, p_s1, student_storage_size);

    printf("id = %d\n", p_s2->m_id);
    printf("name = %s\n", p_s2->m_name);
    printf("surname = %s\n", p_s2->m_surname);

    for (int i = 0; i < exam_count; ++i)
      printf("%d ",p_s2->m_grades_arr[i]);

    // output ->
    //  id = 1111
    //  name = hello
    //  surname = world
    //  41 67 34 0 69

    // --------------------------------------------------

    free(p_s1);
    free(p_s2); 
  }
*/

/*
                      --------------------
                      | inline functions |
                      --------------------
*/

/*
  inline expansion : (derleyici optimizasyon tekniği)
    derleyicinin, tanımını gördüğü bir fonksiyonu, 
    linker'ın kullanabilmesi için object code'a 
    bir referans olarak yazmak yerine fonksiyonun işlevini 
    gerçekleştirmek için kullanacağı makina komutlarını
    fonksiyon çağrısının yapıldığı yere yerleştirmesidir.

    - fonksiyona giriş çıkış kodları için maliyet oluşmaz.
    - fonksiyon çağrısı sebebiyle akışın bölünmemesi
      derleyicinin daha geniş kod alanında optimizasyon 
      yapabilmesine olanak sağlar.

  - "inline" keyword (function specifier) 

  - fonksiyon "inline" specifier'ı ile betimlenmese bile
    derleyici inline expansion optimizasyonunu yapabilir. 
  - fonksiyon "inline" specifier'ı ile betimlense bile
    derleyici inline expansion optimizasyonunu yapmak zorunde 
    değildir.

  - inline fonksiyonlar başlık dosyasında tanımlanabilirler.
*/

/*
  // file1.h
  // -------
  inline int func_1(int x, int y)
  {
    return x * x + y * y;
  }

  // file2.h
  // -------
  extern int func_1(int x, int y);

  // file2.c
  // -------
  int func_1(int x, int y)
  {
    return x * x + y * y;
  }

  // main.c
  // ------
  // #include "file1.h"
  // #include "file2.h"

  int main(void)
  {
    func_1(3, 4);
    // function's definition inside file1.h 
    // is for compiler to do inline expansion

    // if compiler doesn't do inline expansion
    // compiler will assume that "func_1" is defined externally
    // in another module and will generate a call to it.
    // will not call the "func_1" inside file1.h 
  }
*/

/*
  // file1.h
  // -------
  static inline func_1(int x, int y)
  {
    return x * x + y * y;
  }

  // main.c
  // ------
  // #include "file1.h"

  int main(void)
  {
    func_1(3, 4);
    // if compiler doesn't do inline expansion
    // "func_1" function which is defined in file1.h
    // will be an internal linkage function

    // if "main.c", "first.c" and "second.c" source files
    // includes "file1.h" header file,
    // "func_1" function will be defined in each source file
    // internally.
  }
*/

/*
  // file1.h
  // -------
  extern inline func_1(int x, int y)
  {
    return x * x + y * y;
  }

  // main.c
  // ------
  // #include "file1.h"

  int main(void)
  {
    func_1(3, 4);
    // if compiler doesn't do inline expansion
    // every source file that includes "file1.h" header file
    // will have a definition of "func_1" function externally.

    // if all source files that includes "file.h"
    // are calling "func_1" 
    // and compiler did not do inline expansion
    // linker will generate a multiple definition error !!
  }
*/

/*
                      -------------------
                      | variadic macros |
                      -------------------
*/

/*
  #include <stdio.h>    // fprintf

  #define   e_printf(...)   fprintf(stderr, __VA_ARGS__)

  int main(void)
  {
    int x = 10, y = 20;
    double d = 3.14;

    e_printf("x = %d, y = %d, d = %f\n", x, y, d);
    fprintf(stderr, "x = %d, y = %d, d = %f\n", x, y, d);
    // Those 2 lines are equivalent.

    // output -> x = 10, y = 20, d = 3.140000
  }
*/

/*
  #include <stdio.h>    // puts

  #define   print_list(...)   puts(#__VA_ARGS__)

  int main(void)
  {
    print_list();   
    puts("");

    print_list(world, galaxy, universe);
    puts("world, galaxy, universe");

    print_list(istanbul, "ankara", "izmir");
    puts("istanbul, \"ankara\", \"izmir\"");
  }
*/

// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------
// -----------------------------------------------------

/*
  void func1(const int arr[]);
  void func2(const int* arr);
  // Those 2 lines are equivalent. (low level const)

  void foo1(int arr[const]);
  void foo2(int* const arr);
  // Those 2 lines are equivalent. (top level const)
*/

/*
  // "func" is expecting minimum 10 element array address
  // to passed as an argument.
  void func(const int arr[static 10])
  {
    for (int i = 0; i < 10; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }

  int main(void)
  {
    int i_arr1[5]  = { 11, 22, 33, 44, 55 };
    int i_arr2[20] = { 11, 22, 33, 44, 55 };

    func(i_arr1);   // undefined behaviour(UB)
    // warning: 'func' reading 40 bytes from a region of size 20 

    func(i_arr2);   // VALID
    // output -> 11 22 33 44 55 0 0 0 0 0
  }
*/