#include <stdio.h>

/*
                  ----------------------------
                  | Storage Class Specifiers |
                  ----------------------------
*/

/*
                        ------------------
                        | `auto` keyword |
                        ------------------
*/

/*
  local variable can have an
    - automatic storage duration
    - static storage duration

  `auto` keyword is used to specify the automatic storage duration
  but because local variables have automatic storage duration by default
  `auto` keyword is not required.
*/

/*
  void foo(void)
  {
    auto int x = 10;    // automatic storage duration
    static int y = 20;  // static storage duration
  }

  // local variable's default storage class specifier is `auto`
  // so no need to specify `auto` keyword
*/

/*
  void foo(void)
  {
    auto int x = 10;
    static int y = 20;

    printf("x = %d, y = %d\n", x, y);
    
    x += 10;
    y += 10;
  }

  int main()
  {
    for(int i = 0; i < 5; i++)
      foo();
    // output ->
    //  x = 10, y = 20
    //  x = 10, y = 30
    //  x = 10, y = 40
    //  x = 10, y = 50
    //  x = 10, y = 60
  }
*/

/*
  void foo(auto int param){}  // syntax error
  // error: storage class specified for parameter 'param'

  // because that parameter variables can not have
  // a static storage duration 
  // `auto` keyword is not allowed for parameter variables
*/

/*
  auto int g_x = 10;  // syntax error
  // error: file-scope declaration of 'g_x' specifies 'auto'

  // global variables have a static storage duration 
  // so `auto` keyword is not allowed for global variables
*/

/*
                      ----------------------
                      | `register` keyword |
                      ----------------------
*/

/*
  - there is no reason to use `register` keyword 
    with modern compilers.
*/

/*
  int main(void)
  {
    register int a = 12;
    int b = 22 - ++a;
  }

  // compiled with x86-64 gcc 14.2 -std=c11 -O0
  //  main:
  //    push rbp
  //    mov rbp, rsp
  //    push rbx   
  //      -> rbx register will be used to store the value of a
  //    mov ebx, 12                       : ebx = 12    -> ebx = a;
  //    add ebx, 1                        : ++ebx       -> ++a;
  //    mov eax, 22                       : eax = 22
  //    sub eax, ebx                      : eax = eax - ebx 
  //    mov DWORD PTR [rbp-12], eax       : int b = eax
  //    mov eax, 0                        : set return value to 0 
  //    mov rbx, QWORD PTR [rbp-8]        
  //      -> setting rbx to its original value
  //    leave
  //    ret
*/

/*
  void foo(register int a){}  
  // `register` keyword can also be used with parameter variables
*/

/*
  int main(void)
  {
    register int x = 10;

    int* p = &x;  // syntax error
    // error: address of register variable 'x' requested
  }
*/

/*
                      --------------------
                      | `static` keyword |
                      --------------------
*/

/*
  `static` keyword does have 2 meaning in C,
    1. when used in local namespace 
    2. when used in global namespace
*/

/*
  static int x;   -> global namespace

  void foo(void)
  {
    static int y;  -> local namespace
  }
*/

/*
  int g_x = 10;   
  // static storage duration
  // global variable 

  void foo(void)
  {
    static int x = 10;
    // static storage duration
    // static local variable

    int y = 10;
    // automatic storage duration
    // automatic local variable
  }
  // when foo is called for the first time, 
  // "x" is initialized once(lifetime begins) 
  // and its lifetime will end at the end of the program

  // "y"'s lifetime starts at the beginning of foo's scope  
  // and ends at the end of foo scope
*/

/*
  - eğer bir statik ömürlü değişkene ihtiyaç duyulup, 
    o değişkene birden fazla fonksiyonun erişebilmesi gerekiyorsa
    o değişken global değişken olmalıdır.
*/

/*
  int g_x = 10; // global variable

  void foo(void)
  {
    int x = 10;         // automatic local variable
    static int y = 10;  // static local variable

    printf("x = %d, y = %d, g_x = %d\n", x, y, g_x);
    ++x, ++y, ++g_x;
  }

  int main(void)
  {
    for(int i = 0; i < 5; i++){
      foo();
      ++g_x;
    }
    // output ->
    //  x = 10, y = 10, g_x = 10
    //  x = 10, y = 11, g_x = 12
    //  x = 10, y = 12, g_x = 14
    //  x = 10, y = 13, g_x = 16
    //  x = 10, y = 14, g_x = 18
  }
*/

/*
  void foo(void)
  {
    static int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    for(int i = 0; i < 10; i++)
      printf("%d ", arr[i]);

    printf("\n");

    for(int i = 0; i < 10; i++)
      arr[i]++;
  }

  int main(void)
  {
    for(int i = 0; i < 5; i++)
      foo();
    // output ->
    //  1 1 1 1 1 1 1 1 1 1
    //  2 2 2 2 2 2 2 2 2 2
    //  3 3 3 3 3 3 3 3 3 3
    //  4 4 4 4 4 4 4 4 4 4
    //  5 5 5 5 5 5 5 5 5 5
  }
*/

/*
  #include <string.h> // strcat

  void foo(void)
  {
    static char str[100] = "hello";
    puts(str);
    strcat(str, "_world");
  }

  int main(void)
  {
    for(int i = 0; i < 5; i++)
      foo();
    // output ->
    //  hello
    //  hello_world
    //  hello_world_world
    //  hello_world_world_world
    //  hello_world_world_world_world
  }
*/

/*
  void foo(void)
  {
    static int x = 5;
    int static y = 10;  
    // storage type specifier and type specifier can be swapped
  }
*/

/*
  void foo(void)
  {
    static int x = 10, y = 10;
    // when storage class specifiers or type qualifiers
    // are used with comma seperated lists 
    // they qualify all the variables in the list

    printf("x = %d, y = %d\n", x, y);
    ++x, ++y;
  }

  int main(void)
  {
    for(int i = 0; i < 5; i++)
      foo();
    // output ->
    //  x = 10, y = 10
    //  x = 11, y = 11
    //  x = 12, y = 12
    //  x = 13, y = 13
    //  x = 14, y = 14
  }
*/

/*
  int main(void)
  {
    const int x = 5, y = 9;

    ++y; // syntax error
    // error: increment of read-only variable 'y'
  }
*/

/*
  int main(void)
  {
    const int x = 5, *p = &x;
    int y = 10;

    p = &x; // VALID
    *p = 22; // syntax error
    // "p" is a pointer to a const int (low-level const)
  }
*/

/*
  static yerel değişkenlerin kullanıldığı temalar:

  1. bazı fonksiyonlar, kendilerini çağıran koda bir değer aktarmak 
    için static yerel değişkenlerine bir değer yazıp çağıran koda 
    bu statik yerel değişkenin adresini döndürürler.
    (fonksiyonun bunu dokümante etmesi gerekir.)
    örneğin, <time.h> --> ctime ve asctime fonksiyonları

  2. bazı fonksiyonlara çağrı yapıldığında fonskiyonun daha önceki
    yapılan çağrılardan elde edilen değerleri kullanması gerekir.
      - fonksiyon kaç kere çağrıldığını logluyor.
      - fonksiyonun ilk defa çağrıldığında belli bir işlem 
        yapması gerekiyor.
    örneğin, strtok

  3. lookup table, bir değerin olup olmadığını sınamak ya da
    indeks ile erişim sağlamak.
*/

/*
  #include <stdlib.h> // rand

  #define   SIZE  20

  int* get_val_arr(int N)
  {
    if (N > SIZE)
      return NULL;
    
    static int arr[SIZE];

    for (int i = 0; i < N; ++i)
      arr[i] = rand() % 1000;

    return arr;
  }

  int main(void)
  {
    int* p_arr = get_val_arr(10);

    for (int i = 0; i < SIZE; ++i)
      printf("%d ", p_arr[i]);
    // output -> 
    //  41 467 334 500 169 724 478 358 962 464 0 0 0 0 0 0 0 0 0 0
  }
*/

/*
  void foo(int x)
  {
    static int call_count = 0;
    ++call_count;

    printf("foo called %d times. x = %d \n", call_count, x);
  }

  int main(void)
  {
    for (int i = 0; i < 5; i++)
      foo(i);
    // output ->
    //  foo called 1 times. x = 0
    //  foo called 2 times. x = 1
    //  foo called 3 times. x = 2
    //  foo called 4 times. x = 3
    //  foo called 5 times. x = 4
    return 0;
  }
*/

/*
  void foo(void)
  {
    static int first_call_flag = 1;

    if (first_call_flag){
      printf("foo called for the first time\n");
      first_call_flag = 0;
    }
    else
      printf("foo called again\n"); 
  }

  int main(void)
  {
    for (int i = 0; i < 5; i++)
      foo();
    // output ->
    //  foo called for the first time
    //  foo called again
    //  foo called again
    //  foo called again
    //  foo called again
  }
*/

/*
  #include <stdlib.h>   // rand
  #include <stddef.h>   // size_t
  #include "../nutility.h"

  #define   UNIQUE_RAND_MAX   20

  int unique_rand(void)
  {
    static int flags[UNIQUE_RAND_MAX] = { 0 };
    static int call_count = 0;

    if (call_count == UNIQUE_RAND_MAX)
      return -1;


    int val;

    while (flags[val = rand() % UNIQUE_RAND_MAX])
      ; // null statement

    ++call_count;
    flags[val] = 1;
    return val;
  }

  int main(void)
  {
    randomize();

    size_t N = UNIQUE_RAND_MAX + 3;

    for (size_t i = 0; i < N; ++i)
      printf("%d ", unique_rand());

    // output -> 
    // 1 7 14 0 9 4 18 2 5 11 15 16 13 12 6 19 3 8 17 10 -1 -1 -1
  }
*/

/*
  // reaching with index
  void foo(int N)
  {
    // lookup table
    static const char* const p_days[] = { 
      "", "pazartesi", "sali", "carsamba", "persembe", 
      "cuma", "cumartesi", "pazar" };
  }

  // to check if string is a valid day
  void bar(const char* str)
  {
    // lookup table
    static const char* const p_days[] = { 
      "", "pazartesi", "sali", "carsamba", "persembe", 
      "cuma", "cumartesi", "pazar" };
  }
*/

/*
  #define ISLEAP(y) ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

  void get_day_count(int month, int year)
  {
    static const int day_tabs[][13] = {
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
      { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };

    return day_tabs[ISLEAP(year)][month];
  }
*/

/*
                      ---------------------
                      | linkage(bağlantı) |
                      ---------------------
*/

/*
  - linkage, birden fazla kaynak dosya(source file) 
    söz konusu olduğunda, bu kaynak dosyalar arasında kullanılan 
    isimlere yönelik bir özelliktir.
      - external linkage  (dış bağlantı)
      - internal linkage  (iç bağlantı)
      - no linkage        (bağlantısız)

  - değişken isimleri ve fonksiyon isimleri için bağlantı özelliği
    vardır.
*/

/*
  // --------------------------------------------------

  eğer bir isim birden fazla kaynak dosyada kullanılıyor ve
  bu isim bağlama zamanında(linking phase) bütün kaynak dosyalarında
  aynı varlığa ilişkin ise, bu isim dış bağlantıya(external linkage) 
  sahiptir.

  i.e. "printf" identifier has external linkage.

  // --------------------------------------------------

  farklı kaynak dosyalarında bulunan aynı isimli global değişkenler
  veya fonksiyon isimleri,
  programın çalışma zamanında farklı varlıklara ilişkin iseler,
  bu isim iç bağlantıya(internal linkage) sahiptir.

  - global bir değişken olup dış bağlantıya sahip değil ise 
    iç bağlantıya sahiptir.

  // --------------------------------------------------

  kullanılan isim kendi kaynak dosyasında bile her yerde bilinmiyor
  ise, bu isim bağlantısız(no linkage) bir isme sahiptir.
  - yerel değişkenlerin bağlantısı yoktur.

  // --------------------------------------------------

  // source1.c
  // ---------------- 
    "x" is same identifier
    "y" is different identifier
  
  // source2.c
  // ----------------
    "x" is same identifier
    "y" is different identifier

  // source3.c
  // ----------------
    "x" is same identifier
    "y" is different identifier

  "x" has external linkage
  "y" has internal linkage

  // --------------------------------------------------
*/

/*
  - dış bağlantıya ait isimler projede tek bir tanıma sahip
    olmak zorundadır.
    identifiers have an external linkage must have a single definition

  - iç bağlantıya ait isimler projede birden fazla tanıma sahip
    olabilirler.
    identifiers have an internal linkage can have multiple definitions
*/

/*
  // source1.c 
  // ----------------
  int g_x = 10;             // (default)external linkage
  void print(int x) {}      // (default)external linkage

  static int g_y = 20;      // internal linkage
  static void foo(void) {}  // internal linkage

  // "print" and "g_x" identifiers
  // have external linkage.

  // "foo" and "g_y" identifiers
  // have internal linkage.
*/


/*
  #include "../nutility.h"

  // "nutility.c" source file has a function called "randomize"
  // and it has external linkage

  void randomize(void){}  // function definition
  // "randomize" function has external linkage
  // "randomize" function also defined in "main.c" source file 

  int main(){}

  // linker error 
  // multiple definition of 'randomize'
*/

/*
  // --------------------------------------------------

  // file1.h (header file)
  // ----------------
  extern int g_x;           // `extern` declaration

  void foo(int);            // non-defining declaration
  extern void bar(int);     // non-defining declaration
  // `extern` keyword is optional for function declarations

  // --------------------------------------------------

  // file1.c (source file)
  // ----------------
  int g_x = 10;       // external linkage

  void foo(int x){}   // external linkage
  void bar(int x){}   // external linkage

  // --------------------------------------------------

  // file2.c (source file)
  // ----------------
  #include "file1.h"

  g_x = 12;
  foo(11);
  bar(22);

  // --------------------------------------------------

  // "file2.c" kaynak dosyası "file1.h" başlık dosyasını 
  // include ettiğinde, "g_x" isminin `extern` bildirimini de 
  // kendi kaynak dosyasına yapıştırıyor.
  // Compiler(derleyici) file2.c kaynak dosyasını
  // derlerken "g_x" isimli değişkenin `extern` bildirimini görüp
  // bu değişken için herhangi bir bellek alanı ayırmıyor.
  // "g_x" isimli değişkenin, projedeki başka bir kaynak dosyasında
  // tanımlanmış olduğunu varsayıyor.

  // fonksiyon bildirimlerinde `extern` keyword kullanımı
  // zorunlu değildir. 

  // --------------------------------------------------
*/

/*
  // --------------------------------------------------

  // file1.h (header file)
  // ----------------
  extern const int primes_arr[];  // `extern` declaration

  // --------------------------------------------------

  // file1.c (source file)
  // ----------------

  const int primes_arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
  // "primes" identifier has external linkage

  // --------------------------------------------------

  // file2.c (source file)
  // ----------------
  #include "file1.h"

  int x = primes_arr[3];

  // --------------------------------------------------
*/


/*
  // --------------------------------------------------

  // file1.c (source file)
  // ----------------

  static int g_x = 10;       // internal linkage
  static void foo(void){}    // internal linkage

  // --------------------------------------------------

  // file2.c (source file)
  // ----------------

  static int g_x = 15;       // internal linkage
  static void foo(void){}    // internal linkage

  // --------------------------------------------------

  // file3.c (source file)
  // ----------------

  static int g_x = 20;        // internal linkage
  static void foo(void){}     // internal linkage

  // --------------------------------------------------

  "file1.c", "file2.c" ve "file3.c" kaynak dosyalarında
  tanımlanan "g_x" isimli değişkenlerin ve "foo" isimli fonksiyonların
  hepsi farklı varlıklara ilişkin isimlerdir(internal linkage).

  // --------------------------------------------------
*/