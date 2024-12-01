#include <stdio.h>

/*
                  =============================
                  | Dynamic Memory Management |
                  =============================
*/

/*
  ---------------------------------------------------------
  
  dynamic storage duration : 
    - nesne compile time'da değil, run-time'da yerini(storage) edinir.
    - nesnenin hayatı bitirilmek istendiğinde run-time'da 
      geri verilir(free edilir).

  ---------------------------------------------------------

  memory allocation(bellek edinimi - bellek tahsisi)
  memory deallocation(bellek geri verme) - free(serbest bırakma)

  - bu işlemleri yapan fonksiyonlar işletim sistemi fonksiyonları
  - standart C kütüphanesi işletim sisteminden bağımsız 
    bir arayüz ve taşınabilirlik sağlayan standart C fonksiyonu sunar.

  ---------------------------------------------------------

  In a system,
    automatic storage duration objects  -> stack
    static storage duration objects     -> data segment
    dynamic storage duration objects    -> heap

  ---------------------------------------------------------

  malloc : (memory allocation)
    - dinamik bellek alanı edinmek için kullanılır.
    - edinilen bellek alanının adresini geri döndürür.
    - bellek içindeki değerler çöp(garbage value) değerdedir.
  calloc : (clean-clear allocation) 
    - edinilen bellek alanındaki değerleri sıfırlayarak edinir.
    - edinilen bellek alanının adresini geri döndürür.
    - malloc + memset
  realloc :
    - bazen daha önce dinamik olarark edinilmiş bellek 
    bloğunun artan ihtiyaç sebebiyle büyütülmesi için kullanılır.
    - bazen daha önce dinamik olarak edinilmiş bellek
    alanının bir kısmının geri verlimesi(küçültülmesi) için kullanılır.
  free :
    - kullanılmayacak dinamik bellek alanının 
    geri verilmesi için kullanılır.

  standart C fonksiyonları <stdlib.h> modülünde tanımlıdır.

  ---------------------------------------------------------

  dinamik bellek yönetimi kullanılan temalar : 
  
    - öyle bir diziye ihtiyacımız var ki, bu dizinin boyutu 
      programın çalışma zamanında belli olacak.
    - program çalışırken bir serverdan dosyalar geliyor, 
      ve dosyalarda metinler var. Bu metinleri bellek alanında 
      tutup üstünde işlem yapmak istiyoruz. Gelecek metinler
      programın çalışma zamanında belli oluyor, dolayısıyla 
      bellek alanının çalışma zamanında elde edinilmesi gerekiyor.
    - bağlı listede(singly linked list) ne zaman yeni bir öğe(node) 
      eklenilirrse o zaman bellek alanı edinilmesi gerekiyor.

  ---------------------------------------------------------
*/

// ---------------------------------------------------------
// -----------------------| malloc |------------------------
// ---------------------------------------------------------

/*
  - malloc başarılı olma garantisi olan bir fonksiyon değildir.
  
  - malloc'a çağrı yapıldığında başarılı olup olmadığı kontrol
    edilmelidir.
    başarılı ise edinilen bellek bloğunun adresi
    başarısız ise NULL geri döndürür

  - malloc ile edinilen bellek bloğu ardışıktır(contiguous).

  - malloc ile edinilen blok ardışık olduğu için bir dizi olarak
    kullanılabilir.

  - malloc ile bir bellek bloğu edinilmek istendiğinde, 
    istenilen bellek bloğunun yanında bir HEADER bloğu da
    edinilir. Bu ek HEADER bloğu edinilen bellek bloğuna dair 
    bilgileri içerir. (edinilen bloğun adresi, boyutu)
*/

/*
  #include <stdlib.h> // malloc
  #include <stddef.h> // size_t

  // malloc funtion's prototype
  void* malloc(size_t size);
*/

/*
  #include <stdlib.h>   // malloc, exit, EXIT_FAILURE, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;

    int* p = malloc(N * sizeof(int)); // 20 * 4 = 80 byte

    if (!p){
      fprintf(stderr, "Memory allocation failed!\n");
      exit(EXIT_FAILURE);
    }

    randomize();
    set_array_random(p, N);
    print_array(p, N);
    // output ->
    //  154  16 659 458 405 874 216 214 239 293
    //   14 179 635 438 513 637 519 190 922  93

    free(p);
  }
*/

/*
  #include <stdlib.h>   // malloc
  #include <stddef.h>   // size_t

  void dynamic_alloc(size_t N)
  {
    int* p = malloc(N * sizeof(int));

    // when "dynamic_alloc" function's execution is completed
    // p pointer will be lost and
    // there won't be any chance to free the memory block
    // so it will cause memory leak
  }

  int main(void)
  {
    for (int i = 0; i < 1000000; ++i)
      dynamic_alloc(1000);

    // Some time(lots of call to "dynamic_alloc" function) later 
    // malloc will fail because of not enough memory to allocate
    // the reason why is memory leak.
  }
*/

/*
  #include <stdlib.h>   // malloc, exit, EXIT_FAILURE, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;

    int* p = malloc(N * sizeof(int)); // 20 * 4 = 80 byte

    if (!p){
      fprintf(stderr, "Memory allocation failed!\n");
      exit(EXIT_FAILURE);
    }

    print_array(p, N);  // undefined behavior(UB)
    // because of malloc function's returned memory block 
    // have garbage values.

    free(p);
  }
*/

/*
  iki defa malloc çağrısı yapıldığında, elde edilen iki 
  bellek bloğu ardışık DEĞİLDİR. 
  Ardışık olabilir fakat olmak zorunda değil.
  Böyle bir ihtiyaç halinde realloc fonksiyonu çağrılmalıdır.
*/

/*
  #include <stdlib.h>   // malloc, exit, EXIT_FAILURE, free

  // malloc function wrapper that controls the return value
  void* malloc_wrapper_1(size_t N)
  {
    void* vp = malloc(N);

    if (!vp){
      fprintf(stderr, "Memory allocation failed!\n");
      exit(EXIT_FAILURE);
    }

    return vp;
  }

  // malloc function wrapper that controls the return value
  // and writes error message that has been passed as argument
  void* malloc_wrapper_2(size_t N, const char* p_err_msg)
  {
    void* vp = malloc(N);

    if (!vp){
      fprintf(stderr, "%s\n", p_err_msg);
      exit(EXIT_FAILURE);
    }

    return vp;
  }

  int main(void)
  {
    size_t N = 20;

    int* p1 = malloc_wrapper_1(N * sizeof(int));

    int* p2 = malloc_wrapper_2( N * sizeof(int), 
                                "memory block allocation failed!");

    free(p1);
    free(p2);
  }
*/

/*
  1) 10'000 defa 20 byte'lık bellek alanı edinmek.
  2) 20 defa 10'000 byte'lık bellek alanı edinmek.

  1 ->  10'000 * 20 = 200'000 byte
  2 ->  20 * 10'000 = 200'000 byte

  eğer edinilen her bellek alanı için tutulan HEADER bloğu 12 byte ise

  1 -> 10'000 * 12  = 120'000  + 200'000  = 320'000 byte
  2 -> 20 * 12      = 240 + 200'000       = 200'240 byte
*/

/*
  #include <stdlib.h>   // malloc
  #include <stddef.h>   // size_t

  int main(void)
  {
    // ---------------------------------------------------------

    size_t N = 0;
    void* vp = malloc(N);   // this is NOT undefined behavior
    // implementation-defined
    
    // compiler can generate code 2 different way
    // 1. malloc will fail and return NULL
    // 2. malloc will return an address which is not NULL

    *vp; // undefined behavior(UB)
    // if vp is NULL(1), dereferencing null pointer is UB
    // if vp is not NULL(2), dereferencing that address which 
    // does not have a valid memory block is UB

    // ---------------------------------------------------------
  }
*/

/*
  #include <stdlib.h>   // malloc
  #include <stddef.h>   // size_t

  int main(void)
  {
    size_t N = 0;
    void* vp = malloc(N);  

    if (vp == NULL)
      printf("malloc implementation 1");
    else  
      printf("malloc implementation 2 returned %p", vp);
    // output -> malloc implementation 2 returned 0000018683399A30

    free(vp);
  }
*/

/*
  #include <stdlib.h>   // malloc, exit, EXIT_FAILURE, free
  #include <string.h>   // memset

  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;
    int* p = malloc(N * sizeof(int));

    if (!p){
      fprintf(stderr, "Memory allocation failed!\n");
      exit(EXIT_FAILURE);
    }

    memset(p, 0, N * sizeof(int));
    print_array(p, N);
    // output ->
    //  0   0   0   0   0   0   0   0   0   0
    //  0   0   0   0   0   0   0   0   0   0

    free(p);
  }
  // This is basically `calloc` functions behaviour
  // allocating memory and setting all bytes to zero
*/

/*
  #include <stdlib.h>   // malloc, free

  int main(void)
  {
    size_t N = 20;

    int* p = malloc(N * sizeof(*p));
    // NO syntax error
    // NO undefined behavior(UB)

    // when "p" identifier on the right side of assignment(=) operator
    // gets in to namelookup phase
    // "p" identifier on the left will be found 
    // so NO syntax error

    // `sizeof` operator cretes unevaluated context
    // there won't be any code generated for "*p" expression
    // so NO undefined behavior(UB)

    free(p);
  }
*/

// ---------------------------------------------------------
// -------------------------| free |------------------------
// ---------------------------------------------------------

/*
  - free fonksiyonu argüman olarak sadece bellek bloğunun 
    adresini ister, bellek bloğunun boyutunu(size) istemez.

  - malloc ile bir bellek bloğu edinildiğinde, arkaplanda bir 
    veri yapısı o bellek bloğunun adresini ve boyutunu tutar.
  - free fonksiyonu bu veri yapısında arama yaparak geri 
    verilmek istenilen bellek bloğunun adresini bulup 
    birlikte tutulan boyut bilgisini kullanarak bellek bloğunu
    geri verir. 

  - free fonksiyonun veri yapısında yaptığı arama programda 
    ek bir maliyet oluşturur.
*/

/*
  #include <stdlib.h>   // free

  // free function's prototype
  void free(void* p);
*/

/*
  free fonksiyonu hataları :
  --------------------------

  - dinamik olarak edinilmemiş bir bloğu free etme girişimi 
    tanımsız davranış(UB) oluşturur.

  - free ile dinamik bellek bloğunun bir kısmını deallocate
    etme girişimi tanımsız davranış(UB) oluşturur.
    Bu seneryo için realloc fonksiyonu kullanılmalıdır.

  - bir bellek bloğu free edildikten sonra, bu bellek bloğunun 
    adresini tutan pointer invalid hale gelir(dangling pointer).
    Dangling pointer kullanımı tanımsız davranış(UB) oluşturur.
    Ancak bu pointera yeni bir değer atanarak kullanılmalıdır.
    -> bu hatanın özel bir biçimi double free (double deletion) 
      hatasıdır.

  - bir dinamik bellek bloğunu free etmemek memory leak oluşturur.
    -> bu hataya sebep olan başka bir durum pointer'ın
      değerini değiştirmek.
*/

/*
  #include <stdlib.h>   // free

  int main(void)
  {
    // ------------------------------------------

    int arr[100];
    free(arr); // undefined behavior(UB)

    // ------------------------------------------

    int arr2[100];
    int* p = arr2;
    free(p); // undefined behavior(UB)

    // ------------------------------------------
  }
*/

/*
  #include <stdlib.h>   // malloc, free

  int main(void)
  {
    size_t N = 1000;
    int* p = malloc(N * sizeof(int));

    free(p + N / 2); // undefined behavior(UB)
  }
*/

/*
  #include <stdlib.h>   // malloc, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;
    int* p1 = malloc(N * sizeof(int));

    randomize();
    set_array_random(p1, N);

    int* p2 = p1;   
    // both p1 and p2 is pointing same dynamic memory block

    free(p1); 
    // p1 and p2 pointers become dangling pointers.

    print_array(p2, N); // undefined behavior(UB)
    // using dangling pointer causes undefined behavior(UB)
  }
*/

/*
  #include <stdlib.h>   // malloc, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;
    int* p1 = malloc(N * sizeof(int));

    randomize();
    set_array_random(p1, N);

    int* p2 = p1;   

    free(p1); 
    // p1 and p2 pointers become dangling pointers.

    free(p2); // undefined behavior(UB)
    // double free(double deletion)
  }
*/

/*
  #include <stdlib.h>   // malloc
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;
    int* p1 = malloc(N * sizeof(int));

    randomize();
    set_array_random(p1, N);

    int arr[100];
    int* p2 = arr;
    p1 = p2;
    // p1 pointer's value changed
    // there is no chance to free the memory block 
    // that p1 was pointing to.
  }
*/

/*
  #include <stdlib.h>   // malloc, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;
    int* p = malloc(N * sizeof(int));

    randomize();
    set_array_random(p, N);

    free(p);
    p = NULL; 
    // idiomatic usage that decreases the risk of 
    // using dangling pointer
  }
*/

/*
  #include <stdlib.h>   // free

  void Free(void* vp)
  {
    if (vp == NULL)
      return;
  }

  int main(void)
  {
    int* p = NULL;

    free(p);  // it is NOT undefined behavior
    // no-op(no operation) function call
  }
*/

// ---------------------------------------------------------
// -----------------------| calloc |------------------------
// ---------------------------------------------------------

/*
  #include <stdlib.h> // calloc
  
  // calloc function's prototype
  void* calloc(size_t elem_count, size_t elem_size);
*/

/*
  #include <stdlib.h>   // calloc, free, exit, EXIT_FAILURE, 
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;
    int* p = calloc(N, sizeof(int));

    if (!p){
      fprintf(stderr, "Memory allocation failed!\n");
      exit(EXIT_FAILURE);
    }

    print_array(p, N);
    // output ->
    //  0   0   0   0   0   0   0   0   0   0
    //  0   0   0   0   0   0   0   0   0   0

    free(p);
  }
*/

// ---------------------------------------------------------
// -----------------------| strdup |------------------------
// ---------------------------------------------------------

/*
  #include <string.h>   // strdup, _strrev(non-standard)
  #include <stdlib.h>   // free

  #define   SIZE  100

  // strdup function's prototype
  char* strdup(const char* p);    // (C23)

  int main(void)
  { 
    char str[SIZE] = "hello world";
    char* pd = strdup(str); 
    // allocate dynamic memory and copy the string

    printf("str = %s\n", pd); // output -> hello world
    printf("pd = %s\n", pd);  // output -> hello world

    _strrev(pd);  // non-standard function
    printf("pd = %s\n", pd);  // output -> pd = dlrow olleh

    free(pd);
    pd = NULL;
  }
*/

/*
  #include <stdlib.h>   // malloc
  #include <string.h>   // strlen, strcpy , _strrev(non-standard)

  #define   SIZE  100

  // strdup function's implementation
  char* Strdup(const char* p)
  {
    char* pd = malloc(strlen(p) + 1);

    if (!pd)
      return NULL;

    return strcpy(pd, p);
  }

  int main(void)
  {
    char str[SIZE] = "hello world";
    char* pd = Strdup(str); 

    printf("str = %s\n", pd); // output -> hello world
    printf("pd = %s\n", pd);  // output -> hello world

    _strrev(pd);
    printf("pd = %s\n", pd);  // output -> pd = dlrow olleh

    free(pd);
    pd = NULL;
  }
*/

// ---------------------------------------------------------
// ---------------- concatenation of strings ---------------
// ---------------------------------------------------------

/*
  #include <string.h>   // strlen, strcpy, strcat
  #include <stdlib.h>   // malloc, free

  #define   SIZE  100

  // there is NO standard function does this operation
  char* Strconcat(const char* p1, const char* p2)
  {
    char* pd = malloc(strlen(p1) + strlen(p2) + 1);

    if (!pd)
      return NULL;

    return strcat(strcpy(pd, p1), p2);
  }

  int main(void)
  {
    char str1[SIZE] = "hello world";
    char str2[SIZE] = "we are live from Istanbul";

    char* str3 = Strconcat(str1, str2);

    printf("str1 = %s\n", str1);
    // output -> str1 = hello world
    printf("str2 = %s\n", str2);
    // output -> str2 = we are live from Istanbul
    printf("str3 = %s\n", str3);
    // output -> str3 = hello worldwe are live from Istanbul

    free(str3);
    str3 = NULL;
  }
*/

/*
  #include <string.h>   // strlen, strcpy, strcat
  #include <stdlib.h>   // malloc, free

  #define   SIZE  100

  char* Strconcat(const char* p1, const char* p2)
  {
    char* pd = malloc(strlen(p1) + strlen(p2) + 1);

    if (!pd)
      return NULL;

    return strcat(strcpy(pd, p1), p2);
  }

  int main(void)
  {
    char* str = Strconcat(Strconcat("hello ", "world"), "galaxy");
    // ------------------ MEMORY LEAK ------------------

    // pointer to the memory block that is returned by
    // `Strconcat("hello ", "world")` 
    // is lost because it directly passed to next function 
    // as an argument so NO chance to free that memory block

    printf("str = %s\n", str);
    // output -> str = hello worldgalaxy

    free(str);
    str = NULL;
  }
*/

/*
  #include <stddef.h>   // size_t
  #include <stdlib.h>   // malloc, free, qsort
  #include "../headers/nutility.h"  

  int fn_compare_int(const void* vp1, const void* vp2)
  {
    return *(const int*)vp1 - *(const int*)vp2;
  }

  int* create_random_array(size_t size)
  {
    int* pd_arr = (int*)malloc(size * sizeof(int));

    if (!pd_arr)
      return NULL;

    return set_array_random_2(pd_arr, size);
  }

  int main(void)
  {
    size_t N = 20;

    int* p_arr = create_random_array(N);
    print_array(p_arr, N);
    // output -> 
    //   41 467 334 500 169 724 478 358 962 464
    //  705 145 281 827 961 491 995 942 827 436

    qsort(p_arr, N, sizeof(*p_arr), &fn_compare_int);

    print_array(p_arr, N);
    // output ->
    //   41 145 169 281 334 358 436 464 467 478
    //  491 500 705 724 827 827 942 961 962 995

    free(p_arr);
    p_arr = NULL;
  }
*/

/*
  #include "../headers/nutility.h"
  #include <stdlib.h>   // malloc, free

  #define ARRAY_COUNT 3

  int* create_random_array(size_t size)
  {
    int* pd_arr = (int*)malloc(size * sizeof(int));

    if (!pd_arr)
      return NULL;

    return set_array_random_2(pd_arr, size);
  }

  int main(void)
  {
    int* array_of_p_arr[ARRAY_COUNT];

    for (size_t i = 0; i < ARRAY_COUNT; ++i)
      array_of_p_arr[i] = create_random_array(i * 2 + 5);

    for (size_t i = 0; i < ARRAY_COUNT; ++i)
      print_array(array_of_p_arr[i], i * 2 + 5);
    
    // output ->
    //   41 467 334 500 169
    //  ---------------------------------------
    //  724 478 358 962 464 705 145
    //  ---------------------------------------
    //  281 827 961 491 995 942 827 436 391
    //  ---------------------------------------

    for(size_t i = 0; i < ARRAY_COUNT; ++i)
      free(array_of_p_arr[i]);
  }
*/

/*
  We want to create a password generator

  - (1) address can be passed by the caller and
    we can generate the password in that address (out param)
  constraints:
    -> user needs to create a buffer (1)

  - returning the address of the generated password
    (no argument is passed)
    - (2) password array will be a static local array
    - (3) password array will be a dynamic array
  constraints:
    -> user does not need to create a buffer (2 and 3)
    -> if static local array is used, every call will return 
        the same address (2)
    -> if dynamic array is used, user will get different addresses
        but need to free the memory block every time (3)
*/

/*
  // (1) password implementation

  #include <stdlib.h>   // rand
  #include "../headers/nutility.h"

  #define   SIZE      100
  #define   PSW_LEN   16

  char* get_random_password(char* p)
  {
    char* p_ret = p;

    for (size_t i = 0; i < PSW_LEN; ++i)
      *p++ = (char)(rand() % 26) + 'A';
    *p = '\0';

    return p_ret;
  }

  int main(void)
  {
    randomize();  

    char password[SIZE];
    get_random_password(password);
    puts(password); // output -> PHQGHUMEAYLNLFDX
  }
*/

/*
  // (2) password implementation

  #include <stdlib.h>   // rand
  #include "../headers/nutility.h"

  #define   SIZE          100
  #define   PSW_LEN       16
  #define   PSW_ARR_SIZE  5

  char* get_random_password(void)
  {
    static char password[SIZE];
    char* p = password;

    for (size_t i = 0; i < PSW_LEN; ++i)
      *p++ = (char)(rand() % 26) + 'A';
    *p = '\0';

    printf("address = %p, password = %s\n", password, password);

    return password;
  }

  int main(void)
  {
    randomize();  

    char* psw_arr[PSW_ARR_SIZE];

    for (size_t i = 0; i < PSW_ARR_SIZE; ++i)
      psw_arr[i] = get_random_password();
    // output ->
    //  address = 00007FF6039FA0A0, password = YWELTEPDXNBYRMXA
    //  address = 00007FF6039FA0A0, password = MTNQEMBROFIDDAQK
    //  address = 00007FF6039FA0A0, password = EIFTCQMRKTSZFQVO
    //  address = 00007FF6039FA0A0, password = VNWHLIEOSXZRKGUI
    //  address = 00007FF6039FA0A0, password = BUAUVGCMVEOVSFMB

    // MTNQEMBROFIDDAQK overrides YWELTEPDXNBYRMXA
    // EIFTCQMRKTSZFQVO overrides MTNQEMBROFIDDAQK
    // VNWHLIEOSXZRKGUI overrides EIFTCQMRKTSZFQVO
    // BUAUVGCMVEOVSFMB overrides VNWHLIEOSXZRKGUI

    // every call to get_random_password will
    // override the previous password
    // because of static local array is used
    // password will be always been created at the same address

    for (size_t i = 0; i < PSW_ARR_SIZE; ++i)
      puts(psw_arr[i]);
    // output ->
    //  BUAUVGCMVEOVSFMB
    //  BUAUVGCMVEOVSFMB
    //  BUAUVGCMVEOVSFMB
    //  BUAUVGCMVEOVSFMB
    //  BUAUVGCMVEOVSFMB
  }
*/

/*
  // (3) password implementation

  #include <stdlib.h>   // rand, free
  #include <string.h>   // strdup
  #include "../headers/nutility.h"

  #define   SIZE          100
  #define   PSW_LEN       16
  #define   PSW_ARR_SIZE  5

  char* get_random_password(void)
  {
    char password[SIZE];
    char* p = password;

    for (size_t i = 0; i < PSW_LEN; ++i)
      *p++ = (char)(rand() % 26) + 'A';
    *p = '\0';

    return strdup(password);  // dynamic memory allocation
  }

  int main(void)
  {
    randomize();  

    char* psw_arr[PSW_ARR_SIZE];

    for (size_t i = 0; i < PSW_ARR_SIZE; ++i)
      psw_arr[i] = get_random_password();

    for (size_t i = 0; i < PSW_ARR_SIZE; ++i)
      puts(psw_arr[i]);
    // output ->
    //  VGMYUCRWACMALFJI
    //  EJJFBPMBACGYSQQJ
    //  NBXBAMSXBNWBRKLD
    //  XYQWBOSXFNQDYPYA
    //  KRWRHIWNZQOBAXXX

    for (size_t i = 0; i < PSW_ARR_SIZE; ++i)
      free(psw_arr[i]);
  }
*/

/*
  ------------------------------------------------------

  void func(T*);
  - eğer bir fonksiyonun parametresi bir pointer ise,
    bu fonksiyona NULL göndermek tanımsız davranış mı
    yoksa sunulan bir opsiyon mu?

  ------------------------------------------------------

  T* func(void);
  - fonksiyonun geri dönüş değeri bir adres ise,
    bu fonksiyonun geri dönüş değeri NULL olabilir mi?
  - fonksiyon static ömürlü bir nesne adresi mi döndürüyor?
  - fonksiyon dinamik ömürlü bir nesne adresi mi döndürüyor?

  ------------------------------------------------------

  T* func(T*);
  - fonksiyon benden aldığı adresi bana geri mi döndürüyor?

  ------------------------------------------------------
*/

// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------

/*
  -------------------------------------------------------
              <--- check dynamic_array.png --->
  -------------------------------------------------------
  we want to hold int pointers(int*) in a dynamic array

    int** p_pint_arr = malloc(N * sizeof(int*));

  -------------------------------------------------------

  we want to hold int arrays in an array 
    int[ROW_SIZE][COL_SIZE];
  but ROW_SIZE and COL_SIZE will be determined at runtime

  we can create 
    - dynamic allocated int* array(with a size of ROW_SIZE)
      which will hold the addresses of dynamically allocated
      int arrays(with a size of COL_SIZE)   
    
    - first we need to allocate int* array
      then we need to allocate int arrays 

    - first we need to free int arrays
      then we need to free int* array
    
    - int[10][20] multi-dimensional arrays elements are contiguous
      dynamically allocated arrays elements are not contiguous

  -------------------------------------------------------
*/

/*
  ----------------- Implementation 1 -----------------

  #include <stddef.h>   // size_t
  #include <stdlib.h>   // malloc, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t ROW_SIZE = 10, COL_SIZE = 20;  

    int** intptrarr_to_intarr = malloc(ROW_SIZE * sizeof(int*));
    // pointer(int*) array is allocated

    if (!intptrarr_to_intarr)
      return EXIT_FAILURE;

    for (size_t i = 0; i < ROW_SIZE; ++i) {
      intptrarr_to_intarr[i] = malloc(COL_SIZE * sizeof(int));
      // int arrays are allocated

      if (!intptrarr_to_intarr[i])
        return EXIT_FAILURE;
    }

    randomize();

    // -------------------------------------------------------
    // setting elements of matrix
    for(size_t i = 0; i < ROW_SIZE; ++i)
      for (size_t k = 0; k < COL_SIZE; ++k)
        intptrarr_to_intarr[i][k] = rand() % 10;

    // -------------------------------------------------------
    // printing elements of matrix
    
    for(size_t i = 0; i < ROW_SIZE; ++i) {
      for (size_t k = 0; k < COL_SIZE; ++k)
        printf("%d ", intptrarr_to_intarr[i][k]);
      putchar('\n');
    } 
    // output ->
    //  0 4 0 0 5 0 6 1 7 2 4 2 5 7 6 3 3 4 4 7
    //  8 4 8 0 9 7 7 7 7 3 8 3 2 9 7 8 7 8 8 2
    //  7 8 6 1 8 3 8 9 8 6 3 8 5 2 5 6 1 4 0 3
    //  5 6 0 9 9 6 7 6 4 3 6 8 3 1 2 1 5 5 8 4
    //  0 6 0 4 8 6 3 9 3 4 3 1 8 8 0 8 8 4 0 3
    //  2 2 5 6 7 7 7 8 5 9 7 3 4 6 9 2 4 0 0 4
    //  6 8 4 6 7 4 6 0 3 7 0 0 4 9 6 8 6 4 3 5
    //  2 4 9 7 0 3 4 4 4 0 2 6 8 0 7 3 3 8 5 2
    //  0 7 1 9 1 9 5 0 5 2 7 4 5 6 4 2 9 0 5 1
    //  5 4 8 6 5 3 9 7 0 1 4 1 8 4 8 7 2 6 4 1

    // -------------------------------------------------------
    // freeing dynamic allocated memory

    for (size_t i = 0; i < ROW_SIZE; ++i)
      free(intptrarr_to_intarr[i]); // freeing int arrays

    free(intptrarr_to_intarr);  // freeing int* array

    // -------------------------------------------------------
  }
*/

/*
  #include <stddef.h>   // size_t
  #include <stdlib.h>   // malloc, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t ROW_SIZE = 10, COL_SIZE = 20;  

    int** intptrarr_to_intarr = malloc(ROW_SIZE * sizeof(int*));
    // pointer(int*) array is allocated

    if (!intptrarr_to_intarr)
      return EXIT_FAILURE;

    for (size_t i = 0; i < ROW_SIZE; ++i) {
      intptrarr_to_intarr[i] = malloc(COL_SIZE * sizeof(int));
      // int arrays are allocated

      if (!intptrarr_to_intarr[i])
        return EXIT_FAILURE;
    }

    randomize();

    // setting elements of matrix
    for(size_t i = 0; i < ROW_SIZE; ++i)
      for (size_t k = 0; k < COL_SIZE; ++k)
        intptrarr_to_intarr[i][k] = rand() % 10;

    // ----------------------------------------------------
    // ----------------------------------------------------

    int* ptr = intptrarr_to_intarr[0];  
    // ptr is pointing to the first element of the first row

    size_t N = ROW_SIZE * COL_SIZE;

    while (N--)
      printf("%d ", *ptr++);  // undefined behaviour(UB)

    // dynamic allocated int* array is contigious  
    // but dynamic allocated int arrays are NOT contiguous
    // so, by increasing "ptr" more than COL_SIZE times
    // will cause undefined behavior(UB)

    // ----------------------------------------------------
    // ----------------------------------------------------

    for (size_t i = 0; i < ROW_SIZE; ++i)
      free(intptrarr_to_intarr[i]); // freeing int arrays

    free(intptrarr_to_intarr);  // freeing int* array

    // -------------------------------------------------------
  }
*/

/*
  // ----------------- Implementation 2 -----------------

  #include <stddef.h>   // size_t
  #include <stdlib.h>   // malloc, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t ROW_SIZE = 3, COL_SIZE = 5;  
    size_t TOTAL_SIZE = ROW_SIZE * COL_SIZE;

    int* p_intarr = malloc(TOTAL_SIZE * sizeof(int));

    if (!p_intarr)
      return EXIT_FAILURE;  

    randomize();

    // ----------------------------------------------------
    // setting elements of matrix

    // ---------- WAY 1 ---------- (seems like a matrix)
    for (size_t i = 0; i < ROW_SIZE; ++i)
      for (size_t k = 0; k < COL_SIZE; ++k)
        p_intarr[i * COL_SIZE + k] = rand() % 10;

    // ---------- WAY 2 ----------
    for (size_t i = 0; i < TOTAL_SIZE; ++i)
      p_intarr[i] = rand() % 10;

    // ----------------------------------------------------
    // printing elements of matrix

    // ---------- WAY 1 ----------
    for (size_t i = 0; i < ROW_SIZE; ++i) {
      for (size_t k = 0; k < COL_SIZE; ++k)
        printf("%d ", p_intarr[i * COL_SIZE + k]);
      putchar('\n');
    }
    // output ->
    //  3 5 3 3 8
    //  6 8 7 6 1
    //  1 3 4 8 2

    // ---------- WAY 2 ----------

    int* ptr = p_intarr;
    size_t N = TOTAL_SIZE;

    while (N--)
      printf("%d ", *ptr++);
    // output -> 3 5 3 3 8 6 8 7 6 1 1 3 4 8 2
    

    // ----------------------------------------------------
    // freeing dynamic allocated memory
    free(p_intarr);

    // ----------------------------------------------------
  }
*/

/*
  // ----------------- Implementation 3 -----------------

  #include <stddef.h>   // size_t
  #include <stdlib.h>   // malloc, free
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t ROW_SIZE = 3, COL_SIZE = 5;  
    size_t TOTAL_SIZE = ROW_SIZE * COL_SIZE;

    int* p_intarr = malloc(TOTAL_SIZE * sizeof(int));

    if (!p_intarr)
      return EXIT_FAILURE;  

    // setting elements of matrix
    for (size_t i = 0; i < ROW_SIZE; ++i)
      for (size_t k = 0; k < COL_SIZE; ++k)
        p_intarr[i * COL_SIZE + k] = rand() % 10;

    // ----------------------------------------------------

    // creating a dynamic pointer array that holds the addresses
    // of the beginning of each row of contiguous int array
    // to use matrix notation [ROW][COLUMN] with 2 subscript operator

    int** intptrarr_to_rows = malloc(ROW_SIZE * sizeof(int*));

    for (size_t i = 0; i < ROW_SIZE; ++i)
      intptrarr_to_rows[i] = p_intarr + i * COL_SIZE;
      // intptrarr_to_rows[i] = &p_intarr[i * COL_SIZE];

    // ----------------------------------------------------

    // using matrix notation [ROW][COLUMN] with 2 subscript operator
    for (size_t i = 0; i < ROW_SIZE; ++i) {
      for (size_t k = 0; k < COL_SIZE; ++k)
        printf("%d ", intptrarr_to_rows[i][k]);
      putchar('\n');
    }
    // output ->
    //  1 7 4 0 9
    //  4 8 8 2 4
    //  5 5 1 7 1

    // ----------------------------------------------------

    // freeing dynamic allocated memory
    free(p_intarr);
    free(intptrarr_to_rows);

    // ----------------------------------------------------
  }
*/

/*
  -------------------------------------------------------

  Implementation 1 :
    int pointer array that holds the addresses of 
    dynamically allocated int arrays

  -> Use more memory. 
    dynamic pointer array memory(ROW_SIZE) + HEADER
    dynamic int arrays memory(COL_SIZE * ROW_SIZE) +  ROW_SIZE * HEADER
      
  -> Can be used with matrix notation [ROW][COLUMN] with 
    2 subscript operator

  -> can NOT be used as a multi-dimensional array
    because int arrays are not contiguous

  -> less likely to cause fragmentation problem (malloc failed)

  -------------------------------------------------------
  
  Implementation 2 :
    dynamically allocated single int array that holds 
    all elements of the matrix.

  -> Use less memory
    - dynamic int array memory(COL_SIZE * ROW_SIZE) + HEADER 

  -> Can NOT be used with matrix notation [ROW][COLUMN] with 
    2 subscript operator

  -> can be used as a multi-dimensional array 
    because all elements are contiguous.

  -> more likely to cause fragmentation problem (malloc failed)

  -------------------------------------------------------

  Implementation 3 :
    dynamically allocated single int array that holds
    all elements of the matrix and dynamic pointer array
    that holds the addresses of the beginning of each row.

  -> Use more memory than Implementation 2 
  -> Use less memory than Implementation 1
    - dynamic pointer array memory(ROW_SIZE) + HEADER
    - dynamic int array memory(COL_SIZE * ROW_SIZE) + HEADER

  -> Can be used with matrix notation [ROW][COLUMN] with 
    2 subscript operator

  -> can be used as a multi-dimensional array
    because int array is contiguous.
  
  -> more likely to cause fragmentation problem (malloc failed)

  -------------------------------------------------------
*/

/*
              <--- check fragmentation.png --->

  fragmentasyon : inside heap some parts have been allocated 
  and some parts have not been allocated and there are some
  free blocks between allocated blocks.

    total free bytes = 80.000 byte
    wanted to allocate 50.000 byte(contiguous)

    -> malloc can be failed because of fragmentation
    it can not find available contiguous memory block

  bellek tahsilatının ne şekilde ortaya çıkacağı belli ise 
  ona uygun bir bellek tahsilatı yapılabilir.

  Örneğin bellek tahsilatlar ufak ufak yapılacak(8 - 10 byte)
  bu durumda sistemin sunduğu allocation algoritması 
  bizim için uygun olmaz.
*/

// ---------------------------------------------------------
// -----------------------| realloc |-----------------------
// ---------------------------------------------------------

/*
  #include <stdlib.h>   // realloc

  // realloc function's prototype
  void* realloc(void* vp, size_t new_size);
*/

/*
  1. realloc başarılı olur ve ilk parametreye 
    geçilen adresi geri döndürür. 
    Bellek bloğu bulunduğu adreste new_size(geçilen ikinci parametre) 
    boyutuna getirilir.
    eski bellek bloğu (old_size - new_size) kadar büyütülür.

  2. realloc fonksiyonu başka bir adreste new_size kadar yeni bir 
    bellek bloğu edinir. 
    Eski bellek bloğundaki byte'ları yeni bellek bloğuna kopyalar.
    Eski bellek bloğu free edilir.
    Yeni bellek bloğu adresi geri döndürülür.
    Eski bellek bloğunu gösteren pointerlar dangiling pointer olur.

  3. realloc fonksiyonu başarısız olur. NULL geri döner.
    Eski bellek bloğu değişmez ve kullanılabilir halde kalır.
*/

/*
  #include <stdlib.h>   // malloc, realloc, free
  #include <stddef.h>   // size_t
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;

    // -------------------------------------------------

    int* p = (int*)malloc(N * sizeof(int));
    if (p == NULL)
      return 1;

    randomize();
    set_array_random(p, N);
    print_array(p, N);
    // output ->
    //  542 870 480 196 416 855 109 940 586 385
    //  667 288 379 825 432 299 919  55 981 717

    // -------------------------------------------------

    size_t N_add = 20;

    p = realloc(p, (N + N_add) * sizeof(int));
    // if realloc fails, p will be NULL
    // and old memory block address will be lost
    // but because of we will terminate the program 
    // after the failure of realloc, there win't be a memory leak.
    if (p == NULL)
      return 1;

    set_array_random(p + N, N_add);
    print_array(p, N + N_add);
    // output ->
    //  542 870 480 196 416 855 109 940 586 385
    //  667 288 379 825 432 299 919  55 981 717
    //  262 950  27 174  37  87 993 790 179 635
    //  204 160 726 768 833 688 862  70 391 979

    free(p);

    // -------------------------------------------------
  }
*/

/*
  // increased memory block with using realloc function 
  // will have garbage values inside.

  #include <stdlib.h>   // malloc, realloc, free
  #include <stddef.h>   // size_t
  #include "../headers/nutility.h"

  int main(void)
  {
    size_t N = 20;
    size_t N_increased_size = 40;

    int* p = (int*)malloc(N * sizeof(int));
    if (p == NULL)
      return 1;

    randomize();
    set_array_random(p, N);

    p = realloc(p, (N_increased_size) * sizeof(int));
    if (p == NULL)
      return 1;

    print_array(p, N_increased_size);  // undefined behavior(UB)
  }
*/

/*
  #include <stdlib.h>   // malloc, realloc, free
  #include <stddef.h>   // size_t

  int main(void)
  {
    size_t N = 20;
    size_t N_add = 10;

    int* p = (int*)malloc(N * sizeof(int));
    if (p == NULL)
      return 1;

    printf("address of p with malloc = %p\n", (void*)p);
    // output -> address of p with malloc = 000001B5BEDF99C0

    p = realloc(p, (N + N_add) * sizeof(int));
    if (p == NULL)
      return 1;

    printf("address of p with realloc = %p\n", (void*)p);
    // output -> address of p with realloc = 000001B5BEDF7420

    // because of address of p is changed,
    // realloc function allocated new memory block
    // and copied the old memory block to the new memory block
  }
*/

/*
  - reallocation takes time ->
    because of copying the old memory block to the new memory block
    calling `realloc` function is expensive operation.
  
  - reallocation invalidates pointers -> 
    if the memory block is reallocated, the old memory block is freed
    and the pointers that is pointing to the old memory block becomes
    dangling pointers.
*/

/*
  realloc(NULL, size) is equivalent to malloc(size)

  - döngüsel bir yapı içinde bir bellek bloğununun sürekli
    büyütülmesi gerekiyor, bunun için önce malloc'a çağrı yapılması
    gerekir. sonra realloc çağrısı yapılır.
    Bu ilk malloc çağrısı yerine realloc(NULL, size) çağrısı yapılabilir.
*/

/*
  #include <stdlib.h>   // rand, malloc, realloc, free, 
  #include <conio.h>    // _getch
  #include "../headers/nutility.h"

  int main(void)
  {
    int val;

    int* p = NULL;
    size_t N = 0;
    size_t total_elem_size = 20;

    randomize();

    while (total_elem_size--) 
    {
      p = realloc(p, (N + 1) * sizeof(int));

      if (!p){
        printf("Memory allocation failed!\n");
        return 1;
      }

      val = rand() % 1000;
      printf("number : %d\n", val);

      p[N++] = val;
    }

    printf("total number of elements : %zu\n", N);
    print_array(p, N);

    // output -> 
    //  number : 185
    //  number : 490
    //  number : 899
    //  number : 369
    //  number : 882
    //  number : 616
    //  number : 136
    //  number : 682
    //  number : 528
    //  number : 613
    //  number : 652
    //  number : 285
    //  number : 319
    //  number : 38
    //  number : 887
    //  number : 297
    //  number : 197
    //  number : 861
    //  number : 375
    //  number : 908
    //  total number of elements : 20
    //  185 490 899 369 882 616 136 682 528 613
    //  652 285 319  38 887 297 197 861 375 908
  }
*/

/*
                --------------------------------
                | dynamic array data structure |
                --------------------------------
*/

/*
  - dynamic array elements are contigious.

  - reaching Nth element is O(1) with pointer arithmetic.

  - inserting from back is O(1) [amortized constant time]
    it is related with the capacity of the dynamic array.
      - when the capacity is full(size == capacity), 
        reallocation is needed and it is O(N) operation. 
      - when the capacity is not full(size < capacity) 
        inserting from back is O(1) operation.
    because of reallocation is rarely done inserting from back
    is O(1) [amortized constant time] operation.

  - when reallocation is done, pointers that is pointing to the 
    old memory block can become dangling pointers.

  - when elements are deleted, size will decrease but capacity
    will remain same so it might block new allocations in heap.

  - because of elements are contigious, caching is more efficient.
    cache hit rate is higher. (cache friendly)

  - inserting from middle is O(N) operation because of 
    shifting(copying) the elements.
*/

/*
  // HOMEWORK : implement dynamic array data structure,
    elements are string.

    // isimlerin bir yerde tutulmasi gerekiyor 
    // adreslerinin de bir yerde tutulmasi gerekiyor
*/

/*
  #include "../headers/nutility.h"  
  #include <stdlib.h>   // rand, calloc
  #include <string.h>   // strcmp, strdup

  const char* get_random_string()
  {
    return p_names[rand() % PNAMES_SIZE];
  }

  int is_name_entered_before( char** p_str_arr, 
                              size_t p_str_arr_size, 
                              const char* str)
  {
    for (size_t i = 0; i < p_str_arr_size; ++i)
      if (strcmp((p_str_arr)[i], str) == 0)
        return 1;

    return 0;
  }

  void do_reallocation(char*** p, size_t* p_str_arr_capacity)
  {
    printf("called with capacity : %zu\n", *p_str_arr_capacity);

    size_t new_capacity = *p_str_arr_capacity * 2;
    printf("new capacity : %zu\n", new_capacity);

    *p = realloc(*p, new_capacity * sizeof(char*));

    if (*p == NULL)
      exit(EXIT_FAILURE);
    
    *p_str_arr_capacity = new_capacity;
  }

  int compare_str(const void* vp1, const void* vp2)
  {
    return strcmp(*(const char**)vp1, *(const char**)vp2);
  }

  int main(void)
  {
    size_t N = 200;

    size_t p_str_arr_capacity = 20;
    size_t p_str_arr_size = 0;

    char** p_str_arr = calloc(p_str_arr_capacity, sizeof(char*));

    randomize();

    while (N--) 
    {
      const char* str = get_random_string();
      printf("ismi girin : %s\n", str);

      if (is_name_entered_before(p_str_arr, p_str_arr_size, str)){
        printf("bu isim daha once girilmisti.\n");
        continue;
      }

      // if capacity is full, do reallocation
      if (p_str_arr_size == p_str_arr_capacity)
        do_reallocation(&p_str_arr, &p_str_arr_capacity);

      // insert a pointer to dynamic string to the dynamic array
      p_str_arr[p_str_arr_size++] = strdup(str);
    }

    // shrink the capacity to the size
    p_str_arr = realloc(p_str_arr, p_str_arr_size * sizeof(char*));

    // sort the strings that dynamic array elements(pointers) points to
    qsort(p_str_arr, p_str_arr_size, sizeof(char*), &compare_str);

    printf("toplam isim sayisi : %zu\n", p_str_arr_size);

    printf("girdiginiz isimler : \n");
    for (size_t i = 0; i < p_str_arr_size; ++i)
      printf("%s ", p_str_arr[i]);

    // free the memory blocks that dynamic array elements point to
    for (size_t i = 0; i < p_str_arr_size; ++i)
      free(p_str_arr[i]);

    free(p_str_arr);
  }
*/
