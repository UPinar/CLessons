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
  #include "../nutility.h"

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
  #include "../nutility.h"

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

  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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
  #include "../nutility.h"

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