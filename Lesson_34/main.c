#include <stdio.h>

/*
                    --------------------
                    | Standart Library |
                    --------------------
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
