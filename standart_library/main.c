#include <stdio.h>

/*
                      ====================
                      | Standart Library |
                      ====================
*/

/*
              --------------------------------------
              | string operations (yazı işlemleri) |
              --------------------------------------
*/

/*
  - if a function will not change the string(read-only) 
    it does not need the size of the string(char[]).
    it can execute its operation using '\0'(null) character.
*/

/*
  #include <stdio.h>  // puts, putchar

  #define SIZE 100

  // puts function's implementation
  void Puts_2(const char* p)
  {
    while(*p)
      putchar(*p++);
    putchar('\n');
  }

  // puts function's implementation
  void Puts(const char* p)
  {
    for(int i = 0; p[i] != '\0'; ++i)
      putchar(p[i]);
    putchar('\n');
  }

  int main(void)
  {
    char str[SIZE] = "hello world";

    puts(str);    // output -> hello world
    Puts(str);    // output -> hello world
    Puts_2(str);  // output -> hello world
  }
*/

/*
  eğer fonksiyon 
    - adresini aldığı diziye bir yazı yerleştirecek ise
    - adresini aldığı dizideki yazıyı büyütme ihtimali 
      olacak şekilde değiştirecek ise

  void stringcopy(char* p_dest, const char* p_source);
    eğer fonksiyon size parametresi istemiyorsa, 
    sorumluluk fonksiyonu çağıran koda bırakılmış olur.
    1. parametreye adresi geçilen dizinin boyutunun
    2. parametreye geçilen dizinin boyutu + minimum 1 karakter  
    olması gerekir.

  strlen  -> yazının uzunluğunu döndüren fonksiyon
  strchr  -> yazıda karakter arayan foksiyon  (baştan sona)
  strrchr -> yazıda karakter arayan fonksiyon (sondan başa)
  strstr  -> yazı içinde yazı arayan fonksiyon
  strcpy  -> bir yazıyı bir yere kopayalayan fonksiyon
  strcat  -> bir yazının sonuna bir yazıyı ekleyen fonksiyon
  strcmp  -> iki yazıyı karşılaştıran fonksiyon
  ...
  strspn, strcspn, strncpy, strncat, strncmp, strpbrk, strtok,
*/

/*
  #include <string.h> // strlen

  // strlen function's implementation
  size_t Strlen_1(const char* p)
  {
    size_t len = 0;
    for (int i = 0; p[i] != '\0'; ++i)
      ++len;

    return len;
  }

  size_t Strlen_2(const char* p)
  {
    size_t len = 0;

    for(; p[len] != '\0'; ++len)
      ;

    return len;
  }

  size_t Strlen_3(const char* p)
  {
    size_t len = 0;

    while (p[len])
      ++len;

    return len;
  }

  size_t Strlen_4(const char* p)
  {
    const char* p_start = p;
    while(*p)
      ++p;

    return (size_t)(p - p_start);
    // "p - p_start" expression's type is ptrdiff_t
  }

  void rputs(const char* p)
  {
    for (int i = (int)(strlen(p) - 1); i >= 0; --i)
      putchar(p[i]);
    putchar('\n');
  }

  int main(void)
  {
    // ---------------------------------------------------

    char str_1[] = "hello world";

    size_t len = strlen(str_1);
    printf("len = %zu\n", len);  // output -> len = 11

    rputs(str_1);  // output -> dlrow olleh

    // ---------------------------------------------------

    char str_2[] = "";

    len = strlen(str_2);
    printf("len = %zu\n", len);  // output -> len = 0

    // ---------------------------------------------------

    char str_3[] = "hello";

    len = strlen(str_3);

    for (size_t i = 0; i < len; ++i)
      puts(str_3 + i);

    // output ->
    //  hello
    //  ello
    //  llo
    //  lo
    //  o

    // ---------------------------------------------------

    size_t len_1 = Strlen_1(str_3);
    printf("len_1 = %zu\n", len_1);  // output -> len_1 = 5
    size_t len_2 = Strlen_2(str_3);
    printf("len_2 = %zu\n", len_2);  // output -> len_2 = 5
    size_t len_3 = Strlen_3(str_3);
    printf("len_3 = %zu\n", len_3);  // output -> len_3 = 5
    size_t len_4 = Strlen_4(str_3);
    printf("len_4 = %zu\n", len_4);  // output -> len_4 = 5

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h> // strchr

  #define SIZE 100

  // strchr function's implementation
  char* Strchr(const char* p, int ch)
  {
    while (*p != '\0'){
      if (*p == ch)
        return (char*)p;
      ++p;
    }

    if (ch == '\0')
      return (char*)p;

    return NULL;
  }

  int main(void)
  {
    // ---------------------------------------------------

    char str[SIZE] = "shot";

    char ch = 'o';
    char* p = strchr(str, ch);

    if (p != NULL){
      printf("found idx = %d\n", (int)(p - str));
      *p = '*';
      puts(str);
    }
    else
      printf("character not found\n");

    // output ->
    //  found idx = 2
    //  sh*t

    // ---------------------------------------------------

    ch = 'k';

    if (strchr(str, ch) != NULL)
      puts("found");
    else
      puts("not found");
    // output -> not found

    // ---------------------------------------------------

    ch = '\0';
    p = strchr(str, ch);    // get the address of null character
    *p = '!';               // change the null character with '!'
    *(p + 1) = '\0';        // put a null character after '!'

    puts(str);  // output -> sh*t!

    // ---------------------------------------------------

    char str_1[] = "hello world";
    char* p_1 = strchr(str_1, 'w');
    char* p_2 = strchr(str_1, '\0');
    char* p_3 = strchr(str_1, 'x');

    if (p_1 != NULL)
      printf("found\n");
    else
      printf("character not found\n");
    // output -> found

    if (p_2 != NULL)
      printf("found\n");
    else
      printf("character not found\n");
    // output -> found

    if (p_3 != NULL)
      printf("found\n");
    else
      printf("character not found\n");
    // output -> character not found

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h>  // strrchr

  char* strchr(const char* p, int c);
  // search starting from the beginning of the string

  char* strrchr(const char* p, int c);
  // search starting from the end of the string


  // strrchr function's implementation
  char* Strrchr(const char* p, int ch)
  {
    char* p_found = NULL;

    while(*p){
      if (*p == ch)
        p_found = (char*)p;
      
      ++p;
    }

    if (ch == '\0')
      return (char*)p;

    return p_found;
  }

  int main(void)
  {
    char str[] = "hello world";

    // ---------------------------------------------------

    char* p_1 = strchr(str, 'o');

    if (p_1)
      printf("found in %d index\n", (int)(p_1 - str));
    else
      printf("character not found\n");

    // output -> found in 4 index

    // ---------------------------------------------------

    char* p_2 = strrchr(str, 'o');  

    if (p_2)
      printf("found in %d index\n", (int)(p_2 - str));
    else
      printf("character not found\n");

    // output -> found in 7 index

    // ---------------------------------------------------

    char* p_3 = Strrchr(str, 'o');

    if (p_3)
      printf("found in %d index\n", (int)(p_2 - str));
    else
      printf("character not found\n");

    // output -> found in 7 index

    // ---------------------------------------------------
  }
*/

/*
  // Homework - implementation of strstr function

  #include <string.h>  // strlen

  #define SIZE 100

  char* Strstr(const char* p_str, const char* p_key)
  {
    const char* p_tempkey = p_key;

    while(*p_str)
    {
      if (*p_str == *p_key){
        ++p_key, ++p_str;

        if (*p_key == '\0')
          return (char*)p_str - strlen(p_tempkey);
      }
      else
        if (p_key != p_tempkey)
          p_key = p_tempkey;
        else
          ++p_str;
    }

    return NULL;
  }

  int main(void)
  {
    char str[SIZE] = "hello world";
    char str_key[SIZE] = "wor";

    printf("(%s) is searched in (%s)\n", str_key, str);

    char* p_found = Strstr(str, str_key);
    if(p_found){
      printf("found in %d index\n", (int)(p_found - str));
      puts(p_found);
    }
    else
      printf("not found\n");

    // output ->
    //  (wor) is searched in (hello world)
    //  found in 6 index
    //  world
  }
*/

/*
  #include <string.h>  // strpbrk

  #define SIZE 100

  // strpbrk function's prototype
  char* strpbrk(const char* p_str, const char* p_keys);

  // strpbrk function's implementation
  char* Strpbrk_1(const char* p_str, const char* p_keys)
  {
    for(int i = 0; p_str[i] != '\0'; ++i){
      if(strchr(p_keys, p_str[i]) != NULL)
        return (char*)(p_str + i);
    }

    return NULL;
  }

  char* Strpbrk_2(const char* p_str, const char* p_keys)
  {
    while(*p_str){
      if(strchr(p_keys, *p_str))
        return (char*)p_str;
      ++p_str;
    }

    return NULL;
  }

  int main(void)
  {
    // ---------------------------------------------------

    char str[SIZE] = "eskisehir izmir ankara";
    char keys[] = "prtnl";

    printf("one of (%s) characters, searched in (%s)\n", keys, str);

    char* p_found = strpbrk(str, keys);
    if(p_found)
      printf("found %c in %d index\n", *p_found, (int)(p_found - str));
    else
      printf("not found\n");

    // output ->
    //  one of (prtnl) characters, searched in (eskisehir izmir ankara)
    //  found r in 8 index

    // ---------------------------------------------------

    char* p_found_1 = Strpbrk_1(str, keys);
    if(p_found_1)
      printf("found %c in %d index\n", 
              *p_found_1, 
              (int)(p_found_1 - str));
    else
      printf("not found\n");
    // output -> found r in 8 index


    char str_1[SIZE] = "121234124abcdefghjkmosuvyz";
    p_found_1 = Strpbrk_1(str_1, keys);
    if(p_found_1)
      printf("found %c in %d index\n", 
              *p_found_1, 
              (int)(p_found_1 - str_1));
    else
      printf("not found\n");
    // output -> not found

    // ---------------------------------------------------

    char str_2[SIZE] = "hello world we are live from 1stanbul";
    char digits[] = "0123456789";

    p_found_1 = Strpbrk_2(str_2, digits);
    if(p_found_1)
      printf("found %c in %d index\n", 
              *p_found_1, 
              (int)(p_found_1 - str_2));
    else
      printf("not found\n");
    // output -> found 1 in 29 index

    // ---------------------------------------------------
  }
*/

/*
  - C dilinde bir diziye yazı yerleştiren ya da bir dizideki yazıyı
    değiştiren fonksiyonlar, üstünde işlem yaptıkları yazının
    adresini(alınan adresi) döndürürler.

    char* strcpy(char* p_dest, const char* p_source);
    char* strcat(char* p_dest, const char* p_source);
    char* strrev(char* p_str);
*/

/*
  #include <string.h>  // strcpy

  #define SIZE 100

  // strcpy function's prototype
  char* strcpy(char* p_dest, const char* p_source);

  // strcpy function's implementation
  char* Strcpy(char* p_dest, const char* p_source)
  {
    char* p_ret = p_dest;

    // while(*p_dest++ = *p_source++)
    while((*p_dest++ = *p_source++) != '\0')
      ; // null statement

    return p_ret;
  }

  int main(void)
  {
    char s1[SIZE] = "hello world";
    char s2[SIZE];
    char s3[SIZE];

    strcpy(s2, s1);
    puts(s2);  // output -> hello world
    puts(s1);  // output -> hello world

    puts(Strcpy(s3, s1));  // output -> hello world
  }
*/

/*
  #include <string.h> // strcpy, strlen

  #define SIZE 100

  int main(void)
  {
    char s1[SIZE] = "hello world ";
    char s2[SIZE] = "we are live from 1stanbul";
    char s3[SIZE];

    strcpy(s3, s1);
    strcpy(s3 + strlen(s3), s2);

    printf("s1 = (%s)\n", s1);
    printf("s2 = (%s)\n", s2);
    printf("s3 = (%s)\n", s3);

    // output ->
    //  s1 = (hello world )
    //  s2 = (we are live from 1stanbul)
    //  s3 = (hello world we are live from 1stanbul)
  }
*/

/*
  #include <string.h>  // strcpy

  int main(void)
  {
    char s1[] = "lorem ipsum dolor sit amet";
    char s2[10];

    if (sizeof(s2) > strlen(s1))
      strcpy(s2, s1);

    // if not runtime error will occur
  }
*/

/*
          --------------------------------------------
          | overlapped blocks and `restrict` keyword |
          --------------------------------------------
*/

/*
  - overlapped blocks(kesişen(çakışan) bloklar)

  C standart library string functions 
    -> either guarantees that operations on overlapped strings
        will work without any problem
    -> or it will be an undefined behavior(ub)

  strcpy function's documentation is telling that 
  operations on overlapped blocks are undefined behavior(ub)

  https://en.cppreference.com/w/c/string/byte/strcpy
    -> `The behavior is undefined if the strings overlap.`

  --------------------------------------------------------------

  - `restrict` keyword is added in C99 standard 

  -> until C99
  char *strcpy( char* p_dest, const char* p_source ); 

  -> since C99
  char *strcpy( char* restrict p_dest, const char* restrict p_source );

  -> `restrict` keyword guarantees that
      the only pointer that points to *p_dest is p_dest.
    
  if a functions parameter variables are `restrict` pointers
  passing overlapped blocks to the function is undefined behavior(ub)

  --------------------------------------------------------------
*/

/*
  #include <string.h>  // strcpy

  #define SIZE 100

  int main(void)
  {
    char str[SIZE] = "0123456789";

    if (strlen(str) > 3)
      strcpy(str + 3, str); // undefined behavior(ub)
  }
*/

/*
  s1 -> 'h', 'e', 'l', 'l', 'o', '\0'
  s2 -> 'w', 'o', 'r', 'l', 'd', '\0'

  strcat(s1, s2) ->
    'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd', '\0'

  copying s2 string to s1 string's null character's address
*/

/*
  #include <string.h>  // strcpy, strcat, strlen, strchr

  #define SIZE 100

  // strcat(concatenate) function's prototype
  char* strcat(char* p_dest, const char* p_source);

  // strcat function's implementation
  char* Strcat_1(char* p_dest, const char* p_source)
  {
    char* p_ret = p_dest;

    while(*p_dest)
      ++p_dest;

    while((*p_dest++ = *p_source++) != '\0')
      ; // null statement

    return p_ret;
  }

  char* Strcat_2(char* p_dest, const char* p_source)
  {
    strcpy(p_dest + strlen(p_dest), p_source);
    return p_dest;
  }

  char* Strcat_3(char* p_dest, const char* p_source)
  {
    strcpy(strchr(p_dest, '\0'), p_source);
    return p_dest;
  }

  int main(void)
  {
    // ---------------------------------------------------

    char s1[SIZE] = "hello ";
    char s2[SIZE] = "world";

    strcat(s1, s2);
    puts(s1);   // output -> hello world
    puts(s2);   // output -> world

    strcat(s2, s1);
    puts(s2);   // output -> worldhello world

    // ---------------------------------------------------

    char s3[SIZE] = "Hello ";
    char s4[SIZE] = "Galaxy";
    char s5[SIZE];

    strcat(strcpy(s5, s3), s4);
    puts(s5);   // output -> Hello Galaxy

    // ---------------------------------------------------
  }
*/

/*
        ----------------------------------------------------
        | strings comparison (yazıların karşılaştırılması) |
        ----------------------------------------------------
*/

/*
  #define SIZE 100

  int main(void)
  {
    char s1[SIZE] = "hello";
    char s2[SIZE] = "world";

    if (s1 == s2) {}  // always false
    // this is not a comparison between strings
    // this is a comparison between the addresses
  }
*/

/*
  - yazıların büyüklük küçüklük karşılaştırması 
  - lexicographical compare algorithm

  -----------------------------------------------------

  3, 6, 7                   a[3]
  2, 5, 1, 8 ......         b[10000]

  with lexographical compare algorithm a > b
  -> a[0] = 3, b[0] = 2  ==> a[0] > b[0]  ==> a > b

  -----------------------------------------------------

  2 4 7 9       a[4]
  2 4 9 1       b[4]

  with lexographical compare algorithm b > a
  -> a[2] = 7, b[2] = 9  ==> a[2] < b[2]  ==> b > a    

  -----------------------------------------------------

  3 7 1         a[3]
  3 7 1 2       b[4]

  with lexographical compare algorithm b > a
  -> a[3] = 2 and there is no element in b[3] ==> b > a

  -----------------------------------------------------

  for two strings(char arrays) to be equal
    - their lengths must be equal
    - all characters in same indices must be equal

  -----------------------------------------------------

  "elma"    > "armut"
  "masa"    > "MASA"
  "cansel"  > "can"

  -----------------------------------------------------
*/

/*
  -----------------------------------------------------

  - a function that returns exact result of the 
    comparison between two strings

  int compare(x, y);
    - there are 3 possible results for the comparison

  x > y     -> function will return positive value
  x < y     -> function will return negative value
  x == y    -> function will return zero

  -----------------------------------------------------

  if (!strcmp(s1, s2))            s1 == s2
  if (strcmp(s1, s2) == 0)        s1 == s2
  if (strcmp(s1, s2))             s1 != s2
  if (strcmp(s1, s2) != 0)        s1 != s2

  if (strcmp(s1, s2) > 0)         s1 > s2
  if (strcmp(s1, s2) < 0)         s1 < s2

  if (strcmp(s1, s2) >= 0)        s1 >= s2
  if (strcmp(s1, s2) <= 0)        s1 <= s2

  -----------------------------------------------------
*/

/*
  #include <string.h> // strcmp
  #include <ctype.h>  // toupper

  #define SIZE 100

  // strcmp function's prototype
  int strcmp(const char* p_first, const char* p_second);

  // strcmp function's implementation
  int Strcmp_1(const char* p_first, const char* p_second)
  {
    while(*p_first == *p_second)
    {
      if (*p_first == '\0')
        return 0;

      ++p_first, ++p_second;
    }

    return *p_first - *p_second;
  }

  // case insensitive strcmp function's implementation
  int Stricmp_1(const char* p_first, const char* p_second)
  {
    while(tolower(*p_first) == tolower(*p_second))
    {
      if (*p_first == '\0')
        return 0;

      ++p_first, ++p_second;
    }

    return tolower(*p_first) - tolower(*p_second);
  }

  int main(void)
  {
    // ---------------------------------------------------

    char s1[SIZE] = "hello";
    char s2[SIZE] = "world";
    char s3[SIZE] = "hello";

    if (!strcmp(s1, s2))
      printf("s1 and s2 are equal\n");
    else
      printf("s1 and s2 are not equal\n");
    // s1 and s2 are not equal

    if (!strcmp(s1, s3))
      printf("s1 and s3 are equal\n");
    else
      printf("s1 and s3 are not equal\n");
    // s1 and s3 are equal

    // ---------------------------------------------------
    
    int cmp_result = strcmp(s1, s2);

    if (cmp_result > 0)
      printf("(%s) > (%s)\n", s1, s2);
    else if (cmp_result < 0)
      printf("(%s) < (%s)\n", s1, s2);
    else
      printf("(%s) = (%s)\n", s1, s2);
    // output -> (hello) < (world)

    cmp_result = strcmp(s1, s3);
    if (cmp_result > 0)
      printf("(%s) > (%s)\n", s1, s3);
    else if (cmp_result < 0)
      printf("(%s) < (%s)\n", s1, s3);
    else
      printf("(%s) = (%s)\n", s1, s3);
    // output -> (hello) = (hello)

    // ---------------------------------------------------

    char s4[SIZE] = "istanbul";
    char s5[SIZE] = "ISTANBUL";

    cmp_result = Strcmp_1(s4, s5);

    if (cmp_result == 0)
      printf("(%s) = (%s)\n", s4, s5);
    else 
      printf("(%s) != (%s)\n", s4, s5);
    // output -> (istanbul) != (ISTANBUL)

    // ---------------------------------------------------

    cmp_result = Stricmp_1(s4, s5);
    if (cmp_result == 0)
      printf("(%s) = (%s)\n", s4, s5);
    else 
      printf("(%s) != (%s)\n", s4, s5);
    // output -> (istanbul) = (ISTANBUL)

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h>  // strcmp

  #define SIZE 100

  // boolean int functions -> true: non-zero, false: zero
  int ends_with(const char* p_source, const char* p_key)
  {
    size_t len_source = strlen(p_source);
    size_t len_key = strlen(p_key);

    if (len_key > len_source)
      return 0;

    return !strcmp(p_source + len_source - len_key, p_key);
  }

  int main()
  {
    char str[SIZE] = "hello galaxy";
    char end[] = "axy";

    if (ends_with(str, end))
      printf("(%s) ends with (%s)\n", str, end);
    else
      printf("(%s) does not end with (%s)\n", str, end);
    // output -> (hello galaxy) ends with (axy) 
  }
*/

/*
            ------------------------------------------
            | generic functions in <string.h> module |
            ------------------------------------------
*/

/*
  -----------------------------------------------------------

  - memset
  bir bellek bloğundaki bütün byte'lara aynı tam sayı değerini yazar.
  void* memset(void* vp, int val, size_t block_size);

  -----------------------------------------------------------

  - memcpy
  bir bellek bloğunu bir yerden başka bir yere kopyalar.
  void* memcpy(void* vp_dest, const void* vp_source, size_t block_size);

  -----------------------------------------------------------

  - memmove
  bir bellek bloğunu bir yerden başka bir yere kopyalar.
  memcpy fonksiyonundan farkı, verdikleri garantiler aynı değil.
  void* memmove(void* vp_dest, const void* vp_source, size_t block_size);

  -----------------------------------------------------------

  - memchr (generic linear search)
  bir bellek bloğunda bir karakter arar.
  void* memchr(const void* vp, int val, size_t block_size);

  -----------------------------------------------------------

  - memcmp
  iki bellek bloğunu karşılaştırır.
  int memcmp(const void* vp1, const void* vp2, size_t block_size);

  -----------------------------------------------------------
*/

/*
  #include <string.h>  // memset
  #include "../nutility.h"

  #define SIZE 10

  // memset function's prototype
  void* memset(void* vp, int val, size_t block_size);

  // memset function's implementation
  void* memset_T(void* vp, int val, size_t block_size)
  {
    char* p = vp;

    while(block_size--)
      *p++ = (char)val;

    return vp;
  }

  int main(void)
  {
    // ---------------------------------------------------

    int x = 10;
    printf("x = %d\n", x);  // output -> x = 10

    int* p = memset(&x, 0, sizeof x);
    printf("x = %d\n", x);  // output -> x = 10

    // ---------------------------------------------------

    if (p == &x)
      printf("p == &x\n");

    // memset function's return value is the address 
    // that has been pass to the function as the first parameter

    // ---------------------------------------------------

    int arr[SIZE];
    randomize();
    set_array_random(arr, SIZE);

    print_array(arr, SIZE);
    // output -> 259 521 270 751 716 348 697 310 466 919

    memset(arr, 0, sizeof arr);
    memset(arr, 0, sizeof arr[0] * SIZE);
    print_array(arr, SIZE);
    // output ->  0   0   0   0   0   0   0   0   0   0

    // ---------------------------------------------------

    char str[100] = "hello world live from Istanbul";
    puts(str);
    // output -> hello world live from Istanbul

    memset(str + 6, '*', 5);
    puts(str);
    // output -> hello ***** live from Istanbul

    strcpy(str + 6, "*****"); 
    puts(str);
    // output -> hello *****

    // ---------------------------------------------------

    char str_2[100] = "hello universe live from Istanbul";
    puts(str_2);
    // output -> hello universe live from Istanbul

    memset_T(str_2 + 6, '*', 8);
    puts(str_2);
    // output -> hello ******** live from Istanbul

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h>  // memset
  #include <stddef.h>  // size_t
  #include "../nutility.h"

  #define   SIZE  20

  int main(void)
  {
    // ---------------------------------------------------

    int x;
    memset(&x, 255, sizeof x);
    // x = 1111'1111 1111'1111 1111'1111 1111'1111
    printf("x = %d\n", x);  // output -> x = -1

    // ---------------------------------------------------

    unsigned int y;
    memset(&y, 255, sizeof y);
    // y = 1111'1111 1111'1111 1111'1111 1111'1111
    printf("y = %u\n", y);  // output -> y = 4294967295

    // ---------------------------------------------------

    int z;  
    memset(&z, 1, sizeof z);
    // z = 0000'0001 0000'0001 0000'0001 0000'0001
    printf("z = %d\n", z);  // output -> z = 16843009

    // ---------------------------------------------------

    int arr[SIZE];
    randomize();
    set_array_random(arr, SIZE);
    print_array(arr, SIZE);
    // output ->
    //  247 913 755 587 368 826 774  61 523 533
    //  117  42 540 168 706 744 620 502 788  55

    int idx = 5;
    size_t n = 6;

    memset(arr + idx, 0, n * sizeof(int));
    print_array(arr, SIZE);
    // output ->
    //  247 913 755 587 368   0   0   0   0   0
    //    0  42 540 168 706 744 620 502 788  55

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h>  // memcpy
  #include "../nutility.h"

  #define   SIZE  10

  // memcpy function's prototype
  void* memcpy( void* restrict vp_dest, 
                const void* restrict vp_source, 
                size_t block_size);

  // memcpy function's implementation
  void* memcpy_T( void* restrict vp_dest, 
                  const void* restrict vp_source, 
                  size_t block_size)
  {
    char* p_dest = vp_dest;
    const char* p_source = vp_source;

    while(block_size--)
      *p_dest++ = *p_source++;

    return vp_dest;
  }

  int main(void)
  {
    // ---------------------------------------------------

    int x = 12;
    int y;

    memcpy(&y, &x, sizeof x);
    printf("x = %d, y = %d\n", x, y);  
    // output -> x = 12, y = 12

    // ---------------------------------------------------

    int arr_1[SIZE];
    int arr_2[SIZE];

    randomize();
    set_array_random(arr_1, SIZE);
    print_array(arr_1, SIZE);
    // output -> 311 718 539 908 583 988 393  42 350 111

    memcpy(arr_2, arr_1, sizeof arr_1);
    print_array(arr_2, SIZE);
    // output -> 311 718 539 908 583 988 393  42 350 111

    // ---------------------------------------------------

    char str_1[] = "hello world";
    char str_2[] = "----- *****";

    puts(str_2);   // output -> ----- *****

    memcpy(str_2 + 6, str_1 + 6, 5);
    puts(str_2);   // output -> ----- world

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h>  // memcpy, memmove
  #include "../nutility.h"

  #define   SIZE  100

  // because of the memcpy function's parameter variables 
  // are restrict pointers, passing overlapped blocks to the function 
  // is undefined behavior(ub)

  // memmove function's prototype
  void* memmove(void* vp_dest, const void* vp_source, size_t block_size);

  int main(void)
  {
    int arr[SIZE];
    set_array_random(arr, SIZE);

    // ---------------------------------------------------

    memcpy(arr + 20, arr, 40 * sizeof(int));
    // block that we are reading from [0-40) and 
    // block that we are writing to [20-60) are overlapped
    // undefined behavior(UB)

    // ---------------------------------------------------

    memmove(arr + 20, arr, 40 * sizeof(int));
    // memmove function guarantees that operations 
    // on overlapped blocks will not cause undefined behavior(UB)
    
    // ---------------------------------------------------
  }
*/

/*
  #include <string.h>  // strcpy, memcpy, memmove, 

  int main(void)
  {
    char str[100] = "mara";

    strcpy(str + 3, str);               // undefined behavior(UB)
    memcpy(str + 3, str, strlen(str));  // undefined behavior(UB)

    memmove(str + 3, str, strlen(str));    // VALID
    puts(str);  // output -> marmara
  }
*/

/*
  #include <string.h>  // memchr

  // memchr function's prototype
  void* memchr(const void* vp, int val, size_t block_size);

  // memchr function's implementation
  void* memchr_T(const void* vp, int val, size_t block_size)
  {
    const char* p = vp;

    while(block_size--){
      if (*p == val)
        return (char*)p;
      ++p;
    }

    return NULL;
  }

  int main(void)
  {
    // ---------------------------------------------------

    unsigned char buf[] = { 1, 3, 5, 0, 2, 6, 4, 8, 9, 2 };

    unsigned char* p1 = memchr(buf, 0, sizeof buf);
    if (p1)
      printf("found in %d index\n", (int)(p1 - buf));
    else
      printf("not found\n");
    // output -> found in 3 index

    // ---------------------------------------------------

    char str[] = "hello world hello galaxy hello universe";

    char* p2 = memchr(str + 5, 'h', 20);
    // search will be applied to the block [5-25)

    if (p2)
      printf("found in %d index\n", (int)(p2 - str));
    else
      printf("not found\n");
    // output -> found in 12 index

    // ---------------------------------------------------
  }
*/

/*
  // HOMEWORK : Implement a generic strstr function

  #include <stddef.h>  // size_t
  #include <string.h>  // memcmp

  void* memmem_T( const void* vp_source_block,
                  size_t source_block_size, 
                  const void* vp_sub_block,
                  size_t sub_block_size)
  {
    const char* p_source = vp_source_block;
    const char* p_sub = vp_sub_block;

    while(source_block_size >= sub_block_size)
    {
      if (memcmp(p_source, p_sub, sub_block_size) == 0)
        return (void*)p_source;

      ++p_source;
      --source_block_size;
    }

    return NULL;
  }

  int main(void)
  {
    // ---------------------------------------------------
    
    char str[] = "world hello galaxy hello universe";
    char sub_str[] = "hello";

    char* p1 = memmem_T(str, strlen(str), sub_str, strlen(sub_str));
    if (p1)
      printf("found in %d index\n", (int)(p1 - str));
    else
      printf("not found\n");
    // output -> found in 6 index

    // ---------------------------------------------------

    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    int sub[] = { 2, 4, 6 };

    int* p2 = memmem_T(arr, sizeof arr, sub, sizeof sub);

    if (p2)
      printf("found in %d index\n", (int)(p2 - arr));
    else
      printf("not found\n");
    // output -> found in 5 index

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h>   // memcmp
  #include <stdlib.h>   // rand
  #include "../nutility.h"

  #define   SIZE  10

  // memcmp function's prototype
  int memcmp(const void* vp1, const void* vp2, size_t block_size);

  // memcmp function's implementation
  int memcmp_T(const void* vp1, const void* vp2, size_t block_size)
  {
    const unsigned char* p1 = vp1;
    const unsigned char* p2 = vp2;

    while(block_size--){
      if (*p1 != *p2)
        return *p1 > *p2 ? 1 : -1;
      ++p1, ++p2;
    }

    return 0;
  }

  int main(void)
  {
    // comparison between blocks will be applied 
    // assumed that blocks are holding unsigned integral types

    int a[SIZE];
    int b[SIZE];

    // ---------------------------------------------------

    randomize();
    set_array_random(a, SIZE);

    memcpy(b, a, sizeof a);

    if (!memcmp(a, b, sizeof a))
      printf("a and b are equal\n");
    else
      printf("a and b are not equal\n");
    // output -> a and b are equal

    // ---------------------------------------------------

    ++a[rand() % SIZE];

    if (!memcmp(a, b, sizeof a))
      printf("a and b are equal\n");
    else
      printf("a and b are not equal\n");
    // output -> a and b are not equal

    // ---------------------------------------------------
  }
*/

/*
                          --------------
                          | Endianness |
                          --------------
*/

/*
  int main(void)
  {
    int x = 15;   // 0x00'00'00'0F
    printf("%p\n", &x);  // output -> 00000050FC9FF90C

    // in Big Endian Architecture, LSByte is at the highest address
    // 00000050FC9FF90C     0x00    0b0000'0000 (Most Significant Byte) 
    // 00000050FC9FF90D     0x00    0b0000'0000  
    // 00000050FC9FF90E     0x00    0b0000'0000
    // 00000050FC9FF90F     0x0F    0b0000'1111 (Least Significant Byte)

    // in Little Endian Architecture, LSByte is at the lowest address
    // 00000050FC9FF90C     0x0F    0b0000'1111 (Least Significant Byte)
    // 00000050FC9FF90D     0x00    0b0000'0000
    // 00000050FC9FF90E     0x00    0b0000'0000
    // 00000050FC9FF90F     0x00    0b0000'0000 (Most Significant Byte)
  }
*/

/*
  - from big endian to little endian 2 byte swap operation needed
  - from little endian to big endian 2 byte swap operation needed
*/

/*
  // how to find out the architecture of the system is 
  // little endian or big endian

  int main(void)
  {
    int x = 1;    // 0x00'00'00'01

    // if Little Endian -> 
    // 0b0000'0001
    // 0b0000'0000
    // 0b0000'0000
    // 0b0000'0000

    // if Big Endian ->
    // 0b0000'0000
    // 0b0000'0000
    // 0b0000'0000
    // 0b0000'0001

    // if the first byte is 1, then the system is little endian
    // if the last byte is 1, then the system is big endian
    
    // ---------------------------------------------------

    char* p = (char*)&x;
    // p is pointing the first byte of the integer x
    // if little indian architecture, *p will be 1
    // if big indian architecture, *p will be 0

    if (*p)
      printf("little endian\n");
    else
      printf("big endian\n");
    // output -> little endian

    // ---------------------------------------------------

    if ( *(char*)&x )
      printf("little endian\n");
    else
      printf("big endian\n");
    // output -> little endian

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h>  // memcmp

  int main(void)
  {
    int x = -856;  // 0xFF'FF'FC'A8
    int y = 981;   // 0x00'00'03'D5

    printf("&x = %p\n", &x);  // output -> &x = 0000008806DFF8BC
    printf("&y = %p\n", &y);  // output -> &y = 0000008806DFF8B8

    // Little Endian Architecture

    // -- y --
    // 0000008806DFF8B8     0xD5    0b1101'0101
    // 0000008806DFF8B9     0x03    0b0000'0011
    // 0000008806DFF8BA     0x00    0b0000'0000
    // 0000008806DFF8BB     0x00    0b0000'0000

    // -- x --
    // 0000008806DFF8BC     0xA8    0b1010'1000
    // 0000008806DFF8BD     0xFC    0b1111'1100
    // 0000008806DFF8BE     0xFF    0b1111'1111
    // 0000008806DFF8BF     0xFF    0b1111'1111
    

    if (memcmp(&y, &x, sizeof(int)) > 0)
      printf("y > x\n");
    // output -> y > x    

    // 0000008806DFF8B8 and 0000008806DFF8BC will be compared
    // 0xD5 > 0xA8
    // y > x
  }
*/

/*
        ----------------------------------------------------
        | qsort and bsearch functions in <stdlib.h> module |
        ----------------------------------------------------
*/

/*
  #include <stdlib.h> // qsort
  #include "../nutility.h"
  #include <math.h>   // abs

  #define   SIZE  20

  // qsort is a generic function that sorts an array
  // qsort function's prototype
  void qsort( void* vp_arr, 
              size_t arr_size, 
              size_t elem_size, 
              int(*fp_compare)(const void*, const void*));

  int compare_ASC(const void* vp1, const void* vp2)
  {
    int lhs = *(const int*)vp1;
    int rhs = *(const int*)vp2;

    if ( lhs > rhs)
      return 1;
    else if ( lhs < rhs)
      return -1;

    return 0;
  }

  int compare_DESC(const void* vp1, const void* vp2)
  {
    int lhs = *(const int*)vp1;
    int rhs = *(const int*)vp2;

    if ( lhs < rhs)
      return 1;
    else if ( lhs > rhs)
      return -1;

    return 0;
  }

  int compare_ASC_ABS(const void* vp1, const void* vp2)
  {
    int lhs = *(const int*)vp1;
    int rhs = *(const int*)vp2;

    if (abs(lhs) > abs(rhs))
      return 1;
    else if (abs(lhs) < abs(rhs))
      return -1;

    return 0;
  }

  int compare_ASC_ABS_2(const void* vp1, const void* vp2)
  {
    return abs(*(const int*)vp1) - abs(*(const int*)vp2);
  }
  // compare_ASC_ABS can be written as above but
  // minus operation can cause overflow and
  // signed integral type overflow is an undefined behavior(UB)

  void set_array_half_negatives(int* p, int size)
  {
    while (size--)
      *p++ = (rand() % 2 ? 1 : -1) * rand() % 1000;
  }

  int main(void)
  {

    int arr[SIZE];
    set_array_random(arr, SIZE);

    // -------------------------------------------------------
    
    print_array(arr, SIZE);
    // output ->
    //   41 467 334 500 169 724 478 358 962 464
    //  705 145 281 827 961 491 995 942 827 436

    // -------------------------------------------------------

    qsort(arr, SIZE, sizeof arr[0], &compare_ASC);

    print_array(arr, SIZE);
    // output ->
    //   41 145 169 281 334 358 436 464 467 478
    //  491 500 705 724 827 827 942 961 962 995

    // -------------------------------------------------------

    qsort(arr, SIZE, sizeof arr[0], &compare_DESC);

    print_array(arr, SIZE);
    // output ->
    //  995 962 961 942 827 827 724 705 500 491
    //  478 467 464 436 358 334 281 169 145  41

    // -------------------------------------------------------

    int arr_2[SIZE];
    set_array_half_negatives(arr_2, SIZE);

    print_array(arr_2, SIZE);
    // output ->
    //  604 -153 -382 716 -895 726 538 912 299 894
    //  811 -333 664 711 868 644 -757 859 741 778

    qsort(arr_2, SIZE, sizeof arr_2[0], &compare_ASC_ABS);
    print_array(arr_2, SIZE);
    // output ->
    //  -153 299 -333 -382 538 604 644 664 711 716
    //  726 741 -757 778 811 859 868 894 -895 912

    // -------------------------------------------------------
  }
*/

/*
  #include "../nutility.h"
  #include <stdlib.h> // qsort
  #include <stddef.h> // size_t

  int compare_double_ASC(const void* vp1, const void* vp2)
  {
    double lhs = *(const double*)vp1;
    double rhs = *(const double*)vp2;

    if (lhs > rhs) return 1;
    else if (lhs < rhs) return -1;
    return 0;
  }

  int main(void)
  {
    double d_arr[] = {1.2, 0.5, 3.4, 2.1, 6.8, -3.4, 5.4, -7.2 };
    qsort(d_arr, asize(d_arr), sizeof d_arr[0], &compare_double_ASC);

    for (size_t i = 0; i < asize(d_arr); ++i)
      printf("%f\n", d_arr[i]);

    // output ->
    //  -7.200000
    //  -3.400000
    //  0.500000
    //  1.200000
    //  2.100000
    //  3.400000
    //  5.400000
    //  6.800000
  }
*/

/*
  // Write a generic sort function that sorts an array

  #include <stddef.h> // size_t
  #include "../nutility.h"

  #define  SIZE  20

  void bubble_sort_T( void* vp_arr,
                      size_t arr_size,
                      size_t elem_size,
                      int(*fp_compare)(const void*, const void*))
  {
    char* p_arr = vp_arr;

    void* lhs_elem;
    void* rhs_elem;

    for (size_t i = 0; i < arr_size - 1; ++i){
      for (size_t k = 0; k < arr_size - 1 - i; ++k){

        lhs_elem  = p_arr + k * elem_size;
        rhs_elem  = p_arr + (k + 1) * elem_size;

        if (fp_compare(lhs_elem, rhs_elem) > 0)
          swap_T(lhs_elem, rhs_elem, elem_size);
      }
    }
  }

  int compare_ASC(const void* vp1, const void* vp2)
  {
    int lhs = *(const int*)vp1;
    int rhs = *(const int*)vp2;

    if ( lhs > rhs)
      return 1;
    else if ( lhs < rhs)
      return -1;

    return 0;
  }

  int compare_DESC(const void* vp1, const void* vp2)
  {
    int lhs = *(const int*)vp1;
    int rhs = *(const int*)vp2;

    if ( lhs < rhs)
      return 1;
    else if ( lhs > rhs)
      return -1;

    return 0;
  }

  int main(void)
  {
    int arr[SIZE];
    randomize();
    set_array_random(arr, SIZE);
    print_array(arr, SIZE);
    // output ->
    //  807 488 667 988 116 170 658 765 321 553
    //  829 904 701 528 853 761 468 820 195 790


    bubble_sort_T(arr, SIZE, sizeof arr[0], &compare_ASC);
    print_array(arr, SIZE);
    // output ->
    //  116 170 195 321 468 488 528 553 658 667
    //  701 761 765 790 807 820 829 853 904 988


    bubble_sort_T(arr, SIZE, sizeof arr[0], &compare_DESC);
    print_array(arr, SIZE);
    // output ->
    //  988 904 853 829 820 807 790 765 761 701
    //  667 658 553 528 488 468 321 195 170 116
  }
*/

/*
  #include <string.h> // memcmp
  #include "../nutility.h"

  #define   SIZE  20  

  void* search_T( const void* vp_arr, 
                  size_t arr_size, 
                  size_t elem_size, 
                  const void* vp_key)
  {
    const char* p_arr = vp_arr;
    const char* p_key = vp_key;

    while (arr_size--)
    {
      if (!memcmp(p_arr, p_key, elem_size))
        return (void*)p_arr;

      p_arr += elem_size;
    }

    return NULL;
  }

  int main()
  {
    int arr[SIZE];
    set_array_random(arr, SIZE);
    print_array(arr, SIZE);
    // output ->
    //   41 467 334 500 169 724 478 358 962 464
    //  705 145 281 827 961 491 995 942 827 436

    int key = 145;
    int* p_key = search_T(arr, SIZE, sizeof *arr, &key);

    if (p_key)
      printf("key found at index %zu\n", p_key - arr);
    else
      printf("key not found\n");

    // output -> key found at index 11
  }
*/

/*
  #include <stdlib.h>   // bsearch
  #include "../nutility.h"

  #define   SIZE  20  

  // we know that array elements can not cause overflow or underflow
  // elements : [0 - 1000)
  int compare_ASC(const void* vp1, const void* vp2)
  {
    return *(const int*)vp1 - *(const int*)vp2;
  }

  int main()
  {
    int arr[SIZE];
    set_array_random(arr, SIZE);

    qsort(arr, SIZE, sizeof arr[0], &compare_ASC);
    print_array(arr, SIZE);
    // output ->
    //   41 145 169 281 334 358 436 464 467 478
    //  491 500 705 724 827 827 942 961 962 995

    int key1 = 705;
    int key2 = 711;

    // -------------------------------------------------------

    int* p_key1 = bsearch(&key1, arr, SIZE, sizeof arr[0], compare_ASC);

    if (p_key1)
      printf("key1 = %d found at index %zu\n", key1, p_key1 - arr);
    else
      printf("key1 = %d, not found\n", key1);
    // output -> key1 = 705 found at index 12

    // -------------------------------------------------------

    int* p_key2 = bsearch(&key2, arr, SIZE, sizeof arr[0], compare_ASC);

    if (p_key2)
      printf("key2 = %d found at index %zu\n", key2, p_key2 - arr);
    else
      printf("key2 = %d, not found\n", key2);
    // output -> key2 = 711, not found

    // -------------------------------------------------------
  }
*/

/*
  #include <stddef.h> // size_t
  #include <stdlib.h> // rand

  #include "../nutility.h"

  #define SIZE 40

  void set_arr_random(int* p_arr, size_t size)
  {
    while(size--)
      *p_arr++ = rand() % 10;
  }

  int compare_ASC(const void* vp1, const void* vp2)
  {
    return *(const int*)vp1 - *(const int*)vp2;
  }

  int main()
  {
    int arr[SIZE];
    set_arr_random(arr, SIZE);

    qsort(arr, SIZE, sizeof arr[0], &compare_ASC);
    print_array(arr, SIZE);
    // output ->
    //  0   1   1   1   1   1   1   1   2   2
    //  2   2   2   2   3   4   4   4   4   4
    //  5   5   5   5   5   6   6   6   7   7
    //  7   7   7   8   8   8   8   9   9   9

    int key = 5;
    int* p_key = bsearch(&key, arr, SIZE, sizeof arr[0], compare_ASC);

    printf("key = %d found at index %zu\n", key, p_key - arr);
    // output -> key = 5 found at index 24

    // bsearch is not giving the first occurence of the key
    //  0   1   1   1   1   1   1   1   2   2
    //  2   2   2   2   3   4   4   4   4   4
    //  5   5   5   5  [5]  6   6   6   7   7
    //  7   7   7   8   8   8   8   9   9   9
  }
*/

/*
  // HOMEWORK : sort const char* array lexicographically 
  //            with qsort algorithm

  #include "../nutility.h"
  #include <stdlib.h> // qsort
  #include <string.h> // strcmp

  int compare_str(const void* vp1, const void* vp2)
  {
    const char* p1 = *(const char**)vp1;
    const char* p2 = *(const char**)vp2;

    return strcmp(p1, p2);
  }

  int main(void)
  {
    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      printf("%s ", p_names[i]);

    qsort(p_names, PNAMES_SIZE, sizeof p_names[0], &compare_str);

    printf("\n------------------------------------\n");

    for (size_t i = 0; i < PNAMES_SIZE; ++i)
      printf("%s ", p_names[i]); 
  }
*/

