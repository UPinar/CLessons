#include <stdio.h>

/*
                        -------------------
                        | Type Qualifiers |
                        -------------------
*/

/*
                        -------------------
                        | `const` keyword |
                        -------------------
*/

/*
  - lojik açıdan değeri değişmemesi gerekn değişkenler `const`
    yapılmalıdır. Yanlışlıkla değiştirmeye çalışan kod sentaks
    hatası verir.
  - `const` olan değişken dizi olabilir, pointer olabilir, user 
    defined type olabilir.

  - global değişkenler `const` olabilir.
  - local değişkenler `const` olabilir.
  - static local değişkenler `const` olabilir.

  - `const` değişkenler derleyiciye daha iyi 
    optimizasyon yapma imkanı verir.

  - `const` değişkenler multithread programlamada
    senkronizasyon maaliyetini ortadan kaldırır.
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 20;

    int* const p1 = &x;
    // p1 is a constant pointer to an integer
    // top level const

    *p1 = 30; // VALID
    p1 = &y;   // syntax error
    // error: assignment of read-only variable 'p'
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 20;

    const int* p1 = &x;
    int const* p2 = &x;
    // p1 and p2 are pointers to a constant integer
    // low level const

    p1 = &y;   // VALID
    p2 = &y;   // VALID

    *p1 = 30;   // syntax error
    // error: assignment of read-only location '*p1'
    *p2 = 30;   // syntax error
    // error: assignment of read-only location '*p2'
  }
*/

/*
  int main(void)
  {
    int x = 10;
    int y = 20;

    const int* const p = &x;
    // p is a constant pointer to a constant integer

    p = &y;    // syntax error
    // assignment of read-only variable 'p'

    *p = 30;   // syntax error
    // error: assignment of read-only location '*(const int *)p'
  }
*/

/*
  typedef int* IPTR;

  int main(void)
  {
    int x = 10;
    int y = 20;

    const IPTR p = &x;
    // p is a constant pointer to an integer
    // top level const

    *p = 30;  // VALID

    p = &y;   // syntax error
    // error: assignment of read-only variable 'p'
  }
*/

/*
  int g_x, g_y, g_z;

  int main(void)
  {
    // --------------------------------------------------

    int* const p_arr[] = { &g_x, &g_y, &g_z };
    // p_arr is an array of constant pointer to integer

    p_arr[1] = &g_z;  // syntax error
    // error: assignment of read-only location 'p_arr[1]'

    // --------------------------------------------------

    const int* p_arr_2[] = { &g_x, &g_y, &g_z };
    // p_arr_2 is an array of pointer to constant integer

    p_arr_2[1] = NULL;  // VALID

    *p_arr_2[1] = 30;   // syntax error
    // error: assignment of read-only location '*p_arr_2[1]'

    // --------------------------------------------------

    const int* const p_arr_3[] = { &g_x, &g_y, &g_z };
    // p_arr_3 is an array of constant pointer to constant integer

    p_arr_3[1] = NULL;  // syntax error
    // error: assignment of read-only variable 'p_arr_3[1]'

    *p_arr_3[1] = 30;   // syntax error
    // error: assignment of read-only location 
    // '*(const int *)p_arr_3[1]'

    // --------------------------------------------------
  }
*/

/*
  int g_x, g_y, g_z;

  int main(void)
  {
    int* p1 = &g_x;
    int* p2 = &g_y;
    const int* p3 = &g_z;

    // --------------------------------------------------

    int** const pp = &p1;
    // pp is a constant pointer to a pointer to an integer

    pp = &p2;  // syntax error
    // error: assignment of read-only variable 'pp'

    *pp = &g_z;  // VALID
    **pp = 30;   // VALID

    // --------------------------------------------------

    int* const* pp2 = &p1;
    // pp2 is a pointer to a constant pointer to an integer

    pp2 = &p2;  // VALID

    *pp2 = &g_z;  // syntax error
    // error: assignment of read-only location '*pp2'

    **pp2 = 30;  // VALID

    // --------------------------------------------------

    int* const * const pp3 = &p1;
    // pp3 is a constant pointer to a constant pointer to an integer

    pp3 = &p2;  // syntax error
    // error: assignment of read-only variable 'pp3'

    *pp3 = &g_z;  // syntax error
    // error: assignment of read-only location '*(int * const*)pp3'

    **pp3 = 30;  // VALID

    // --------------------------------------------------

    const int* const * const pp4 = &p3;
    // pp4 is a 
    // constant pointer to a constant pointer to a constant integer

    pp4 = &p2;  // syntax error
    // error: assignment of read-only variable 'pp4'

    *pp4 = &g_z;  // syntax error
    // error: assignment of read-only location 
    // '*(const int * const*)pp4'

    **pp4 = 30;  // syntax error
    // error: assignment of read-only location 
    // '*(const int *)*(const int * const*)pp4'

    // --------------------------------------------------
  }
*/

/*
  // conversion from (const T* ===> T*)
  // will cause undefined behavior(UB)

  int main(void)
  {
    const int x = 5;

    int* p = (int*)&x;
    *p = 10;  // undefined behavior(UB)
  }
*/

/*
  void foo(T*)        -> setter, mutator function
    - aldığı adresteki değeri değiştirip çağıran koda bir
      değer iletiyor ise OUT param.
    - aldığı adresteki değerden okuma yapıp hem de çağıran koda
      bu adresi değiştirerek bir değer iletiyor ise IN-OUT param.
    
  void foo(const T*)  -> getter, accessor function
    - aldığı adresteki değeri okuyup çağıran koda 
      bu adresi değiştirerek herhangi bir değer iletmiyor is IN param.   
*/

/*
  int* foo(void);
  const int* bar(void);

  int main(void)
  {
    // --------------------------------------------------

    int* p1 = foo();
    *p1 = 10;
    *foo() = 20;

    // --------------------------------------------------

    int* p2 = bar();
    // warning: initialization discards 'const' qualifier 
    // from pointer target type

    const int* p3 = bar();
    *bar() = 30;  // syntax error
    // error: assignment of read-only location '*bar()'

    // --------------------------------------------------
  }
*/

/*
                      ----------------------
                      | `volatile` keyword |
                      ----------------------
*/

/*
  int g_x = 5;

  int main(void)
  {
    // --------------------------------------------------

    int* volatile p1 = &g_x;
    // p1 is a volatile pointer to an integer

    // when p1 wanted to use, it must be read from memory(fetch)
    // without compiler optimization

    // --------------------------------------------------

    volatile int* p2 = &g_x;
    // p2 is a pointer to a volatile integer

    // when *p2(g_x) wanted to use, it must be read from memory(fetch)
    // without compiler optimization
    
    // --------------------------------------------------

    volatile int* volatile p3 = &g_x;
    // p3 is a volatile pointer to a volatile integer

    // when p3 wanted to use, it must be read from memory(fetch)
    // without compiler optimization
    // when *p3(g_x) wanted to use, it must be read from memory(fetch)
    // without compiler optimization

    // --------------------------------------------------
  }
*/
