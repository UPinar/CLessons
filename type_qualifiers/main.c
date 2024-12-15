#include <stdio.h>

/*
                        ===================
                        | Type Qualifiers |
                        ===================
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
    - aldığı adresteki değeri okuyup, çağıran koda 
      bu adresi değiştirerek 
      herhangi bir değer iletmiyor ise IN param.   
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
  - bir değişken "volatile" anahtar sözcüğü ile tanımlandığında,
    bu değişkenin program dışı kaynaklar tarafından 
    değiştirilebileceğini belirtir.

  memory mapped I/O : registerlar bellekteki adreslere 
  map edilmiş olabilir. 

    #define   ADR_REG   (int*)0x1111FFFF

    program dışından bu adrese bir değer yazıldığında,
    int* p = ADR_REG;
    "*p" ifadesi yazılan değer okunabilir. 

  - interruplar bir değişkenin değerini değiştirebilir.
  - işletim sisteminden gelen bir sinyali işleyen fonksiyonun
    içinde global bir değişkenin değeri değiştirilebilir.

  - derleyici değişkenlerin değerlerinin program dışından 
    değiştirilebileceğini bilmez, dolayısıyla buna istinaden 
    optimizasyonlarını yapar.

  - "volatile" anahtar sözcüğü türün bir parçasıdır. 

  - değişken "volatile" anahtar sözcüğü ile tanımlandığında,
    bu değişkenin değeri derleyici tarafından optimize edilmez.
    her okuma işleminde, değişkenin değeri bellekten tekrar okunur.
*/

/*
  int main(void)
  {
    volatile int x1 = 11;
    int volatile x2 = 22;
    // x1 and x2's data types are volatile int
  }
*/

/*
  int g_x = 5;

  int main(void)
  {
    // --------------------------------------------------

    int* volatile p1 = &g_x;
    // p1 is a volatile pointer to an integer

    // when p1 wanted to use, 
    // it must be read from memory(fetch)
    // without compiler optimization

    // --------------------------------------------------

    volatile int* p2 = &g_x;
    // p2 is a pointer to a volatile integer

    // when *p2(g_x) wanted to use, 
    // it must be read from memory(fetch)
    // without compiler optimization
    
    // --------------------------------------------------

    volatile int* volatile p3 = &g_x;
    // p3 is a volatile pointer to a volatile integer

    // when p3 wanted to use, 
    // it must be read from memory(fetch)
    // without compiler optimization

    // when *p3(g_x) wanted to use, 
    // it must be read from memory(fetch)
    // without compiler optimization

    // --------------------------------------------------
  }
*/

/*
  int main(void)
  {
    int a = 11;
    int x = a + 10;
    int y = a + 20;
  }

  // compiled with x86-64 gcc 14.2 -O1
  //  .LC0:
  //    .string "x = %d, y = %d\n"
  //  main:
  //    sub     rsp, 8
  //    mov     edx, 31                 : int y = 31;
  //    mov     esi, 21                 : int x = 21;
  //    mov     edi, OFFSET FLAT:.LC0
  //    mov     eax, 0
  //    call    printf
  //    mov     eax, 0
  //    add     rsp, 8
  //    ret

  // "x" and "y" are not read from memory, 
  // because of there is not any change in code related with "a"
  // variable's value, compiler optimizes the code.
  // and directly setting "x" and "y" variable's values 
  // without memory fetch operation.
*/

/*
  int main(void)
  {
    volatile int a = 11;
    int x = a + 10;
    int y = a + 20;

    printf("x = %d, y = %d\n", x, y);
  }

  // compiled with x86-64 gcc 14.2 -O1
  //  .LC0:
  //    .string "x = %d, y = %d\n"
  //  main:
  //    sub     rsp, 24
  //    mov     DWORD PTR [rsp+12], 11    
  //    mov     esi, DWORD PTR [rsp+12]     : (read from memory 1)
  //    mov     edx, DWORD PTR [rsp+12]     : (read from memory 2) 
  //    add     edx, 20                     : "printf" 3rd argument
  //    add     esi, 10                     : "printf" 2nd argument
  //    mov     edi, OFFSET FLAT:.LC0       : "printf" 1st argument 
  //    mov     eax, 0                      : zeroing ret val reg
  //    call    printf                      : "printf" call
  //    mov     eax, 0
  //    add     rsp, 24
  //    ret

  // for assigning "x" and "y" values,
  // compiler reads "a" variable's value from memory twice.
  // because volatile keyword is a way of telling to compiler that
  // some other program can change "a" variable's value,
  // it must be read from memory every time it is used.
*/

/*
  int flag = 1;

  int main(void)
  {
    while(flag) {
      // code...
    }

    // "flag"'s value changed by an interrupt, 
    // or a signal handler but loop won't be terminated.
    // Because of there is not any code that changes "flag" 
    // variable's value from the compiler's perspective,
    // compiler will not read "flag" variable's value from memory
    // every time it is used.
  }
*/

/*
  volatile int flag = 1;

  int main(void)
  {
    while(flag) {
      // code...
    }

    // flag will be read from memory every time 
    // that it will be compared with 0.
    // This will increase the cost of the loop.
  }
*/

/*
  #include <signal.h>
  #include <Windows.h>
  #include <stdlib.h>

  volatile int keep_running = 1;

  void handle_sigint(int sig);

  int main(void)
  {
    signal(SIGINT, handle_sigint);  // Handle Ctrl+C signal

    // keep_running will always be read from memory
    while (keep_running) {
      printf("Running...\n");
      Sleep(1000);
    }

    printf("Exiting...\n");
    return 0;
  }

  void handle_sigint(int sig)
  {
    printf("signal %d recieved\n", sig);
    keep_running = 0;
  }

  // output ->
  //  Running...
  //  Running...
  //  Running...
  //  Running...
  //  signal 2 recieved   ---> Ctrl+C pressed
  //  Exiting...
*/

/*
  int main(void)
  {
    // --------------------------------------------------

    const int cival = 10;

    int* p = &cival;  // INVALID
    // conversion from 'const int*' to 'int*' is invalid

    int* p2 = (int*)&cival;  // VALID
    // changing "cival"'s value by using p2 
    // will cause undefined behavior(UB)

    // --------------------------------------------------

    volatile int vival = 20;

    int* p3 = &vival;  // INVALID
    // conversion from 'volatile int*' to 'int*' is invalid

    volatile int* p4 = &vival;  // VALID

    int* p5 = (int*)&vival;     // VALID
    // changing "vival"'s value by using p5 
    // will cause undefined behavior(UB)

    // --------------------------------------------------
  }
*/

/*
  // compiler optimization can be disabled 
  // by using volatile keyword

  #include <time.h>
  #include <stdio.h>

  int main(void)
  {
    clock_t c1 = clock();
    double d = 0.0;

    // --------------------------------------------------

    for (int i = 0; i < 10000; ++i)
      for (int k = 0; k < 10000; ++k)
        d += d * i * k;   
    // reads from and writes to non-volatile variable

    printf( "modified non-volatile variable 100millon times\n"
            "time elapsed: %.2f seconds\n",
            (double)(clock() - c1) / CLOCKS_PER_SEC);
      
    // --------------------------------------------------

    c1 = clock();
    volatile double vd = 0.0;

    for (int i = 0; i < 10000; ++i) {
      for (int k = 0; k < 10000; ++k) {
        double prod = vd * i * k;   
        // reads from volatile variable
        vd += prod;         
        // reads from and write to volatile variable
      }
    }

    printf( "modified volatile variable 100millon times\n"
            "time elapsed: %.2f seconds\n",
            (double)(clock() - c1) / CLOCKS_PER_SEC);

    // --------------------------------------------------

    // output -> (compiled with x86-64 gcc 14.2 -O2)
    //  modified non-volatile variable 100millon times
    //  modified non-volatile variable 100millon times
    //  time elapsed: 0.00 seconds    
    //  modified volatile variable 100millon times
    //  time elapsed: 0.56 seconds

    // because of variable "d"'s value 
    // is not used after the loop,
    // compiler optimized the code and deleted the loop.
  }
*/

/*
  int g_x = 10;

  int main(void)
  {
    // --------------------------------------------------

    const volatile int x = 10;
    // x is a constant volatile integer

    // program can not change x's value
    // but intterupts or signals can change x's value
    
    // --------------------------------------------------
    
    const volatile int* p = &g_x;

    // every time p is dereferenced, 
    // g_x's value will be read from memory
    // and it can not be changed by the program

    // --------------------------------------------------
  }
*/

/*
                      ----------------------
                      | `restrict` keyword |
                      ----------------------
*/

/*
  - restrict qualifier yalnızca pointer değişkenleri
    niteleyebilir. Bunun dışında kullanım sentaks hatasıdır.

  - restrict pointer, kullanıldığı scope'ta, 
    kendi gösterdiği nesneyi gösteren başka bir pointer 
    olmadığını belirtir. 

  - genel olarak fonksiyonların parametre değişkenleri 
    için kullanılır.
  
  - restrict pointer'ın restrict garantisi sağlanmaz ise 
    tanımsız davranış(undefined behavior) oluşur.

  char *strcpy( char *restrict dest, const char *restrict src );
    since C99
*/

/*
  int main(void)
  {
    restrict int x = 5; // syntax error
    // error: invalid use of 'restrict'
  }
*/

/*
  int g_x = 11;

  int main(void)
  {
    restrict int* p1 = &g_x;  // syntax error
    // error: invalid use of 'restrict'

    int* restrict p2 = &g_x;  // VALID 
  }
*/

/*
  void foo(int* restrict p1, int* restrict p2);

  // it is guaranteed that objects that p1 and p2 points to
  // are different objects.
*/

/*
  double g_d1 = 1.0;
  double g_d2 = 1.0;

  void func(void);

  int main(void)
  {
    double sum = 0.0;

    // ---------------------------------------------------

    double* dp1 = &g_d1;

    for (int i = 0; i < 10; ++i) {
      sum += *dp1;
      func();
    }

    // compiler did not see the code of the "func"
    // because of "func" function's code can change 
    // the value of "g_d1" variable 
    // by dereferencing "dp1" pointer,
    // "sum += *dp1;" statement can not be optimized.

    // ---------------------------------------------------

    double* restrict dp2 = &g_d2;

    for (int i = 0; i < 10; ++i) {
      sum += *dp2;
      func();
    }

    // because of "dp2" is a restrict pointer
    // compiler thinks there won't be any code
    // that can dereference "dp2" pointer
    // so it can optimize the code.

    // ---------------------------------------------------
  }
*/

/*
  // ---------------------------------------------------

  void func(int* p1, int* p2, const int* p3)
  {
    *p1 += *p3;
    *p2 += *p3;
  }

  // because of the pointer aliasing scenario,
  // compiler can not optimize this code.

  // p1 and p3 might point to the same object and
  // if compiler optimizes this code,
  // it will use the same value(*p3) for the both assignment 
  // without reading the value of *p3 for the second time from memory.
  // but after the first assignment, 
  // becaause of the value of *p3 will also be changed,
  // program will not work as expected.

  // ---------------------------------------------------

  void func2(int* p1, int* p2, const int* restrict p3)
  {
    *p1 += *p3;
    *p2 += *p3;
  }

  // because of the "p3" is a restrict pointer,
  // compiler can optimize this code.

  // because of the restrict keyword,
  // compiler knows that there is no other pointer
  // that points to the same object(*p3) that p3 points to.
  // so it can use the same value(*p3) for the both assignment.

  // ---------------------------------------------------
*/

/*
  void func(int* restrict p1, int* restrict p2);

  int main(void)
  {
    int x = 10;
    int i_arr[10] = { 0 };

    func(&x, &x);         // undefined behavior(UB)
    func(i_arr, i_arr);   // undefined behavior(UB)
  }
*/

/*
  // ---------------------------------------------------

  void multiply_arrays(int* dest, int* src1, int* src2, size_t N)
  {
    for (size_t i = 0; i < N; ++i)
      dest[i + 1] = src1[i] * src2[i];
  }

  // compiler can not optimize this code
  // because of the pointer aliasing scenario
  // there might be a chance that those pointers
  // are pointing to the same object.
  // so compiler can not done SIMD optimization.

  // ---------------------------------------------------

  void multiply_arrays2(int* restrict dest, 
                        int* restrict src1, 
                        int* restrict src2, 
                        size_t N)
  {
    for (size_t i = 0; i < N; ++i)
      dest[i + 1] = src1[i] * src2[i];
  }

  // compiler can optimize this code
  // and can use SIMD instructions 
  // when generating the assembly code.

  // ---------------------------------------------------
*/