#include <stdio.h>

/*
                        ====================
                        | Yazılar(Strings) |
                        ====================
            C dilinde yazıların kullanılması ve işlenmesi
*/

/*
  Null-terminated byte stream  (NTBS) 

  - yazının uzunluğunu ayrı bir değişkende tutmak yerine,
    yazının son karakterinden sonra yazının sonunu belirleyen 
    ama yazıya ait olmayan özel bir değeri kodlamak.

  - instead of holding string's length in a variable,
    we can use a special value that is not a part of the string
    to determine the end of the string.

    '\0'    0 (null character)

    '1'     49
    '2'     50
    ...
    '9'     57

    'A'     65
    'B'     66
    ...
    'Z'     90

    'a'     97
    'b'     98
    ...
    'z'     122

    - in ASCII 0 number's code is 48
    - in ASCII null characters code is 0
*/

/*
  int main(void){
    printf("0 character    = %d\n", '0');
    printf("null character = %d\n", '\0');

    // output ->
    //  0 character    = 48
    //  null character = 0
  }
*/

/*
  int main(void){
    char s[100];

    s[0] = 'H';
    s[1] = 'E';
    s[2] = 'L';
    s[3] = 'L';
    s[4] = 'O';
    s[5] = '\0';

    for (int i = 0; s[i] != '\0'; ++i){
      printf("%c", s[i]);
    }
    // output -> HELLO
  }
*/

/*
  int main(void){
    char s[100];

    s[0] = 'H';
    s[1] = 'E';
    s[2] = 'L';
    s[3] = 'L';
    s[4] = 'O';
    // there is no guarantee that this array's 5th index is null character
    // because of we did not initialize it and char array is automatic storage
    // duration so element's values are indetermined(garbage) value


    for (int i = 0; s[i] != '\0'; ++i){
      printf("%c", s[i]);
    }
    // undefined behaviour(UB)
  }
*/

/*
  int main(void){
    char s[100];

    s[0] = 'H';
    s[1] = 'E';
    s[2] = 'L';
    s[3] = 'L';
    s[4] = 'O';
    s[5] = '\0';

    for (int i = 0; s[i] != '\0'; ++i){
    // for (int i = 0; s[i] != 0; ++i){       VALID
    // for (int i = 0; s[i]; ++i){            VALID
      printf("%c", s[i]);
    }
    // output -> HELLO

    putchar('\n');

    int i = 0;
    while (s[i])
      putchar(s[i++]);
    // output -> HELLO
  }
*/

/*
  char g_s[100];  // global variable -> static storage duration

  int main(void){

    g_s[0] = 'H';
    g_s[1] = 'E';
    g_s[2] = 'L';
    g_s[3] = 'L';
    g_s[4] = 'O';
    // it is guaranteed that this array's 5th index is null character

    for (int i = 0; g_s[i] != '\0'; ++i)
      printf("%c", g_s[i]);
    // output -> HELLO

    putchar('\n');

    static char s_s[100];  // static variable -> static storage duration
    s_s[0] = 'W';
    s_s[1] = 'O';
    s_s[2] = 'R';
    s_s[3] = 'L';
    s_s[4] = 'D';
    // it is guaranteed that this array's 5th index is null character

    for (int i = 0; s_s[i] != '\0'; ++i)
      printf("%c", s_s[i]);
    // output -> WORLD    
  }
*/

/*
  int main(void){
    char s[100];

    s[0] = 'H';
    s[1] = 'E';
    s[2] = 'L';
    s[3] = 'L';
    s[4] = 'O';
    s[5] = '\0';

    // for (int i = 0; s[i] != '\0'; ++i)
    //   putchar(s[i]);
    // purchar('\n'); 
    // printf("WORLD\n") 

    // output -> 
    //  HELLO
    //  WORLD

    // int puts(const char*) 
    // prints the string and add a newline character

    puts(s);
    printf("WORLD\n");
    // output -> 
    //  HELLO
    //  WORLD
  }
*/

/*
  int main(void){
    char s1[100];

    s1[0] = 'H';
    s1[1] = 'E';
    s1[2] = 'L';
    s1[3] = 'L';
    s1[4] = 'O';
    s1[5] = '\0';

    char s2[100];
    s2[0] = 'W';
    s2[1] = 'O';
    s2[2] = 'R';
    s2[3] = 'L';
    s2[4] = 'D';
    s2[5] = '\0';

    // puts() function can not write 2 strings but printf() can

    printf("%s\n%s", s1, s2);
    // output -> 
    //  HELLO
    //  WORLD
  }
*/

/*
  int main(void){
    char str[100] = { 'H', 'E', 'L', 'L', 'O' };
    // there is a null character in the 5th index
    // from 5th to 99th index are null characters
    // it is NTBS

    char str2[] = { 'H', 'E', 'L', 'L', 'O' };
    // this arrays SIZE is 5 
    // there is no null character in the end of the array
    // it is not NTBS

    char str3[5] = { 'H', 'E', 'L', 'L', 'O' };
    // this arrays SIZE is 5 
    // there is no null character in the end of the array
    // it is not NTBS

    puts(str);  // VALID
    puts(str2); // undefined behaviour(UB)
    puts(str3); // undefined behaviour(UB)
  }
*/