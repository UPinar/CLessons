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

  #define SIZE 100

  // strcmp function's prototype
  int strcmp(const char* p_first, const char* p_second);

  // strcmp function's implementation
  char* Strcmp_1(const char* p_first, const char* p_second)
  {
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
  }
*/
