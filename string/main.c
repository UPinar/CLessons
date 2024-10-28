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
    // undefined behavior(UB)
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
    // there is no null character at the end of the array
    // it is not NTBS

    char str3[5] = { 'H', 'E', 'L', 'L', 'O' };
    // this arrays SIZE is 5 
    // there is no null character at the end of the array
    // it is not NTBS

    puts(str);  // VALID
    puts(str2); // undefined behavior(UB)
    puts(str3); // undefined behavior(UB)
  }
*/

/*
  int main(void){
    char str[10]; 
    // this array can hold max 9 character string 
    // this array can hold min 0 character string(empty string) 
    // in empty string all characters are null characters
  }
*/

/*
  int main(void){
    char str[] = {'h', 'e', 'l', 'l', 'o'};
    // char array's size is 5 
    // there is no null character at the end of the array

    puts(str);  // undefined behavior(UB)
  }
*/

/*
  int main(void){
    char str[] = "Hello";
    // char array's size is 6 (including null('\0') character)

    puts(str);  // VALID
    // output -> Hello


    char str2[5] = "World"; // VALID in C, INVALID in C++
    // char array's size is 5 
    // but not NTBS(does not include '\0' character)

    puts(str2); // undefined behavior(UB)
  }
*/

/*
  int main(void){
    // ----------- SCENARIO'S ARE NOT NTBS ------------
    // ----------------- SCENARIO 1
    char str[20];

    str[0] = 'H';
    str[1] = 'E';
    str[2] = 'L';
    str[3] = 'L';
    str[4] = 'O';

    // ----------------- SCENARIO 2
    char str2[] = {'W', 'O', 'R', 'L', 'D'};

    // ----------------- SCENARIO 3
    char str3[5] = {'H', 'E', 'L', 'L', 'O'};

    // ----------------- SCENARIO 4
    char str4[5] = "WORLD";
  }
*/

/*
  // getting string from standart input

  #define   SIZE  100

  int main(void){
    char str[SIZE];

    printf("Enter a string: ");
    scanf("%s", str);  
    printf("You entered: (%s)\n", str);

    // input -> Enter a string : Hello World
    // output -> You entered : (Hello)
  }
*/

/*
  #define   SIZE  100

  int main(void){
    char name[SIZE];
    long long age;

    printf("Write your name and age: ");
    scanf("%s%lld", name, &age); 
    printf("You entered: (%s)-(%lld)\n", name, age);

    // input -> Write your name and age: World 4540000000
    // output -> You entered: (World)-(4540000000)
  }
*/

/*
  char türden bir diziye, standart inputtan gelen,
  boşluk karakterleri dahil bir yazıyı nasıl alabiliriz?

  1. scanf' özel formatlama niteliklerini kullanırız.
  2. C99 ile dilden kaldırılan (derleyici destekliyor ise) 
    ismi gets olan fonksiyona çağrı yaparız.
  3. C11 standardı ile derleyicilerin opsiyonel olarak desteklediği 
    gets_s fonksiyonunu kullanırız.
  4. standart kütüphanenin ismi fgets olan (dosya işlemleri ile ilgili) 
    fonksiyonunu kullanırız.
*/

/*
  int main(void){
    char str[100];

    printf("Enter a string: ");
    gets(str);
    // warning: call to 'gets' declared with attribute warning: 
    // Using gets() is always unsafe - use fgets() instead

    printf("You entered: (%s)\n", str);
    // input -> Enter a string: Hello World we are live from Istanbul
    // output -> You entered: (Hello World we are live from Istanbul)
  }
*/

/*
  #define   SIZE  100

  int main(void){
    char str[SIZE];

    printf("Enter a string: ");
    int len = 0;
    int ch;

    while ((ch = getchar()) != '\n'){
      str[len++] = (char)ch;
    }

    str[len] = '\0';

    printf("You entered: (%s) - Length: (%d)\n", str, len);
    // input -> Enter a string: Hello World 
    // output -> You entered: (Hello World) - Length: (11)
  }
*/

/*
  #include "nutility.h"

  #define   SIZE  100

  int main(void){
    char str[SIZE];

    printf("Enter a string: ");
    sgets(str); // defined in "nutility.c"

    printf("You entered: (%s)\n", str);
    // input -> Enter a string: Hello Galaxy 
    // output -> You entered: (Hello Galaxy)
  }
*/

/*
  // finding length of a string
  int main(void){
    char str[100] = "Hello World";

    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
      ++len;

    printf("Length of the string: %d\n", len);
    // output -> Length of the string: 11

    int len2 = 0;
    for (; str[len2] != '\0'; ++len2)
      ; // null statement

    printf("Length of the string: %d\n", len2);
    // output -> Length of the string: 11
  }
*/

/*
  // Yazıyı tersten yazdırma (Printing string in reverse order)

  int main(void){
    char str[] = "hello world";

    int i = 0;

    while (str[i])
      ++i;
    // i's index is null character's index

    printf("i = %d\n", i);  // i = 11

    for (--i; i >= 0;)
      putchar(str[i--]);
    putchar('\n');
    // output -> dlrow olleh
  }
*/

/*
  // Yazıyı ters çevirme (reversing string)

  int main(void){
    char str[] = "hello galaxy";

    int len = 0;
    while (str[len])
      ++len;

    for (int i = 0; i < len / 2; ++i){
      char temp = str[i];
      str[i] = str[len - 1 - i];
      str[len - 1 - i] = temp;
    }

    printf("%s\n", str);  // output -> yxalag olleh
  }
*/

/*
  Palindrom
  ---------
  - en iyi mese bese mi yine?
  - Ana, Naci Dede ne dedi Canan'a?
  - Tras neden sart?
  - Para hazir. Ama Riza harap!
  - at sahibi gibi hasta
  - A man, a plan, a canal, Panama
*/

/*
  // -------------- HOMEWORK 
  // do not use another array
  // do not change array's elements
  // check if the string is palindrom

  #include <ctype.h>  // tolower(), isalpha()

  #define   asize(x)  (sizeof(x) / sizeof(x[0]) )

  int is_palindrom(const char* p, int size){
    int start_idx = 0;
    int end_idx = size - 1;

    while (start_idx < end_idx)
    {
      while (!isalpha(p[start_idx]))
        ++start_idx;

      while (!isalpha(p[end_idx]))
        --end_idx;

      if (start_idx >= end_idx)
        return 1;

      if (tolower(p[start_idx]) != tolower(p[end_idx]))
        return 0;

      ++start_idx;
      --end_idx;
    }
    return 1;
  }

  int main(){
    char str[] = "A man, a plan, a canal, Panama";
    char str2[] = "Hello World";
    char str3[] = "Para hazir. Ama Riza harap!";
    char str4[] = "Tras neden sart?";

    printf("Result: %d\n", is_palindrom(str, asize(str)));
    // output -> Result: 1
    printf("Result: %d\n", is_palindrom(str2, asize(str2)));
    // output -> Result: 0
    printf("Result: %d\n", is_palindrom(str3, asize(str3)));
    // output -> Result: 1
    printf("Result: %d\n", is_palindrom(str4, asize(str4)));
    // output -> Result: 1
  }
*/

/*
  // s3 dizisinde s1 ile s2 yazılarının birleşimini oluşturunuz.

  int main(){
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[100];

    int i;
    for (i = 0; str1[i] != '\0'; ++i)
      str3[i] = str1[i];

    for(int k = 0; str2[k] != '\0'; ++k)
      str3[i++] = str2[k];

    str3[i] = '\0';

    printf("(%s) + (%s) = (%s)\n", str1, str2, str3);
    // output -> (Hello) + (World) = (HelloWorld)
  }
*/

/*
  // s1 dizisinin sonuna s2 yazısını ekleyiniz. (concatenate - append) 

  #define   SIZE  100

  int main(void){
    char s1[SIZE] = "Hello";
    char s2[SIZE] = "World";

    printf("s1 = (%s), s2 = (%s)\n", s1, s2);
    // output -> s1 = (Hello), s2 = (World)

    int i = 0;
    while (s1[i])
      ++i;

    int k = 0;
    while (s2[k])
      s1[i++] = s2[k++];

    s1[i] = '\0';

    printf("s1 = (%s), s2 = (%s)\n", s1, s2);
    // output -> s1 = (HelloWorld), s2 = (World)
  }
*/

/*
  // --------------- HOMEWORK
  // iki kelimenin arasinda sadece 1 bosluk karakter olacak
  // ikinci bir dizi kullanilmayacak
  // kelimelerin uzunluklari ayni olmak zorunda degil
  // kelimelerin yerleri degistirilecek
  // code will change strings places

  #define SIZE 100

  int main(){
    char str[SIZE] = "Hello Universe";

    printf("(%s)\n", str);    // output -> (Hello Universe)

    int i = 0;
    int first_word_length = 0;
    int total_length = 0;
    while (str[i]){
      if (str[i] == ' ')
        first_word_length = i;
        
      ++i;
    }
    total_length = i;

    i = 0;
    while (i <= first_word_length){
      char temp = str[0];

      // shift all characters to left
      for (int k = 0; str[k] != '\0'; ++k)
        str[k] = str[k + 1];
      
      // put first character to the end
      str[total_length - 1] = temp;
      ++i;
    }

    i = 0;
    int last_index = total_length - 1;
    while (i < first_word_length){
      char temp = str[last_index - i];
      str[last_index - i] = str[last_index - i - 1];
      str[last_index - i - 1] = temp;
      ++i;
    }

    printf("(%s)\n", str);      // output -> (Universe Hello)
  }
*/

/*
  #define   SIZE  100

  int main(void){
    char s1[SIZE] = "Hello World";
    char s2[SIZE] = "";

    printf("s1 = (%s), s2 = (%s)\n", s1, s2);
    // output -> s1 = (Hello World), s2 = ()

    int i = 0;
    while (s1[i] != '\0'){
      s2[i] = s1[i];
      ++i;
    }

    s2[i] = '\0';

    printf("s1 = (%s), s2 = (%s)\n", s1, s2);
    // output -> s1 = (Hello World), s2 = (Hello World)
  }
*/

/*
  #define   SIZE  100

  int main(void){
    char s1[SIZE] = "Hello World";
    char s2[SIZE] = "";

    printf("s1 = (%s), s2 = (%s)\n", s1, s2);
    // output -> s1 = (Hello World), s2 = ()

    int i = 0;
    for (i = 0; s1[i] != '\0'; ++i)
      s2[i] = s1[i];

    s2[i] = '\0';

    printf("s1 = (%s), s2 = (%s)\n", s1, s2);
    // output -> s1 = (Hello World), s2 = (Hello World)
  }
*/

/*
  #define   SIZE  100

  int main(void){
    char s1[SIZE] = "Hello World";
    char s2[SIZE] = "";

    printf("s1 = (%s), s2 = (%s)\n", s1, s2);
    // output -> s1 = (Hello World), s2 = ()

    int i = 0;
    while (s2[i] = s1[i])   // while ((s2[i] = s1[i]) != '\0') 
      ++i;

    // value that assignment operator generate is 
    // the value of the left operand
    // when (s2[i] = s1[i]) -> (s2[i] = '\0)
    // while(0) -> false : loop will break
 
    printf("s1 = (%s), s2 = (%s)\n", s1, s2);
    // output -> s1 = (Hello World), s2 = (Hello World)
  }
*/

/*
                  -------------------------
                  | remove copy algorithm |
                  -------------------------
*/

/*
  // copying a string but not specific character

  #define   SIZE  100

  int main(void){
    char s1[SIZE] = "ablam ankara'dan adanaya vardi.";
    char s2[SIZE];
    int c = 'a';

    int write_idx = 0;

    for(int i = 0; s1[i] != '\0'; ++i){
      if (s1[i] != c)
        s2[write_idx++] = s1[i];
    }
    s2[write_idx] = '\0';

    printf("s1 = (%s)\n", s1);  
    // output -> s1 = (ablam ankara'dan adanaya vardi.)
    printf("s2 = (%s)\n", s2);
    // output -> s2 = (blm nkr'dn dny vrdi.)
  }
*/

/*
  // copying a string but not number characters

  #include <ctype.h>

  #define   SIZE  100

  int main(void){
    char s1[SIZE] = "3b14m 9nk4r4'd4n 3d8n4y7 v4rd1.";
    char s2[SIZE];

    int write_idx = 0;

    for(int i = 0; s1[i] != '\0'; ++i){
      if (!isdigit(s1[i]))
        s2[write_idx++] = s1[i];
    }
    s2[write_idx] = '\0';

    printf("s1 = (%s)\n", s1);  
    // output -> s1 = (3b14m 9nk4r4'd4n 3d8n4y7 v4rd1.)
    printf("s2 = (%s)\n", s2);
    // output -> s2 = (bm nkr'dn dny vrd.)
  }
*/

/*
  // removing specific character from a string

  #define   SIZE  100

  int main(void){
    char str[SIZE] = "ablam ankara'dan adanaya vardi.";

    printf("str = (%s)\n", str);
    // str = (ablam ankara'dan adanaya vardi.)

    int c = 'a';
    int write_idx = 0;

    for(int i = 0; str[i] != '\0'; ++i){
      if (str[i] != c)
        str[write_idx++] = str[i];
    }
    str[write_idx] = '\0';

    printf("str = (%s)\n", str);
    // str = (blm nkr'dn dny vrdi.)
  }
*/

/*
                          -------------------
                          | count algorithm |
                          -------------------
                  counting characters inside a string
*/

/*
  #define   SIZE  100

  int main(void){
    char str[SIZE] = "ablam ankara'dan adanaya vardi.";
    int ch = 'a';

    printf("str = (%s)\n", str);
    // output -> str = (ablam ankara'dan adanaya vardi.)

    int count = 0;
    for(int i = 0; str[i] != '\0'; ++i){
      if (str[i] == ch)
        ++count;
    }
    printf("'%c' character is found %d times \n", ch, count);
    // output -> 'a' character is found 11 times 
  }
*/

/*
  #define   SIZE  100

  int main(void){
    char str[SIZE] = "Ankara Aydin";
    int ch = 'a'; // character is not 'A' it is 'a'

    printf("str = (%s)\n", str);
    // output -> str = (Ankara Aydin)

    int count = 0;
    for(int i = 0; str[i] != '\0'; ++i){
      if (str[i] == ch)
        ++count;
    }
    printf("'%c' character is found %d times \n", ch, count);
    // output -> 'a' character is found 2 times 
  }
*/

/*
  // checking case insensitive character count

  #include <ctype.h>  // toupper()

  #define   SIZE  100

  int main(void){
    char str[SIZE] = "Ankara Aydin";
    int ch = 'a'; 

    printf("str = (%s)\n", str);
    // output -> str = (Ankara Aydin)

    int count = 0;
    for(int i = 0; str[i] != '\0'; ++i){
      if (toupper(str[i]) == toupper(ch))
        ++count;
    }
    printf("'%c' character is found %d times \n", ch, count);
    // output -> 'a' character is found 4 times 
  }
*/

/*
                    ----------------------
                    | count_if algorithm |
                    ----------------------
*/

/*
  // count if character is a digit

  #include <ctype.h> // isdigit()

  #define   SIZE  100

  int main(void){
    char str[SIZE] = "3b14m 9nk4r4'd4n 3d8n4y7 v4rd1.";

    printf("str = (%s)\n", str);
    // output -> str = (3b14m 9nk4r4'd4n 3d8n4y7 v4rd1.)

    int count = 0;
    for(int i = 0; str[i] != '\0'; ++i){
      if (isdigit(str[i]))
        ++count;
    }
    printf("There are %d digits\n", count);
    // output -> There are 13 digits
  }
*/

/*
  // count if alphabetical characters in string
  // ASCII character codes 

  #include <ctype.h> // isalpha(), toupper()

  #define  SIZE  300

  int main(void){
    char str[SIZE] =  "Hello World we are live from Istanbul. "
                      "Weather is kind of rainy today. "
                      "Istanbul is the most crowded city in the World.";

    int counts[26] = {0};
    // counts[0] ---> A counter
    // counts[1] ---> B counter
    // ...
    // counts[25] ---> Z counter

    int idx = 0;
    for (int i = 0; str[i] != '\0'; ++i){
      if (isalpha(str[i]))
        ++counts[toupper(str[i]) - 'A'];
    }

    for (int i = 0; i < 26; ++i)
      if (counts[i])
        printf("%c : %d\n", 'A' + i, counts[i]);

    // output ->
    //  A : 6
    //  B : 2
    //  C : 2
    //  D : 6
    //  E : 9
    //  F : 2
    //  H : 4
    //  I : 9
    //  K : 1
    //  L : 7
    //  M : 2
    //  N : 5
    //  O : 8
    //  R : 7
    //  S : 5
    //  T : 8
    //  U : 2
    //  V : 1
    //  W : 5
    //  Y : 3
  }
*/

/*
  // yazida kelime saymak (counting words in a string)

  #include <ctype.h>  // isspace()

  #define   SIZE      300
  #define   INWORD    1
  #define   OUTWORD   0

  // ___Hello___World___we___are___live___from___Istanbul___
  //   xx      xx      xx   xx    xx     xx     xx    
  // in "xx" locations(from space to word) 
  // we need to increase word count

  int main(void){
    char str[SIZE] =  "   Hello   World we are  live from   Istanbul "
                      "Weather  is kind   of  rainy       today "
                      "Istanbul   is the  most crowded   city in the World  ";

    int word_flag = OUTWORD;
    int word_count = 0;

    for (int i = 0; str[i] != '\0'; ++i){
      if (isspace(str[i]))
        word_flag = OUTWORD;
      else if (word_flag == OUTWORD){
        ++word_count;
        word_flag = INWORD;
      }
    }

    printf("Word count: %d\n", word_count);
    // output -> Word count: 22
  }
*/

/*
  // writing our own seperator function

  #include <ctype.h>  // isspace()

  #define   SIZE      300
  #define   INWORD    1
  #define   OUTWORD   0

  int is_seperator(int c){
    return isspace(c) || c == '.' || c == ',' || c == '!' || c == '?';
  }

  int main(void){
    char str[SIZE] =  "   Hello   World,we are  live...from   Istanbul "
                      "Weather,is kind   of  rainy       today "
                      "Istanbul,is,the,most crowded   city!!!in the World";

    int word_flag = OUTWORD;
    int word_count = 0;

    for (int i = 0; str[i] != '\0'; ++i){
      if (is_seperator(str[i]))
        word_flag = OUTWORD;
      else if (word_flag == OUTWORD){
        ++word_count;
        word_flag = INWORD;
      }
    }

    printf("Word count: %d\n", word_count);
    // output -> Word count: 22
  }
*/

/*
  int main(void){
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0; i < 10; ++i)
      printf("%d-%d ", i[a], a[i]);
    
    // output -> 1-1 2-2 3-3 4-4 5-5 6-6 7-7 8-8 9-9 10-10

    // a[i] compiler will generate ->  *(a + i)
    // i[a] compiler will generate ->  *(i + a)

    // a bir dizi ismi olmak üzere, 
    // (a + i) a dizisinin i indisli elemanının adresi

    // (a + i) -> &a[i] 
    // (i + a) -> &a[i]

    // dereferencing operator (*) will reach the object in that address
    // *(a + i) -> a[i]
  }
*/

/*
  // yazıdan sayıya dönüşüm
  
  #define   SIZE  100

  int main(void){
    char str[SIZE] = "123456";


    for(int i = 0; str[i] != '\0'; ++i)
      printf("%d\n", str[i]);

    // output ->
    //  49 -> (ASCII code of '1')
    //  50
    //  51
    //  52
    //  53
    //  54

    for (int i = 0; str[i] != '\0'; ++i)
      printf("%d\n", str[i] - '0');

    // output ->
    //  1
    //  2
    //  3
    //  4
    //  5
    //  6


    int ival = 0;
    for (int i = 0; str[i] != '\0'; ++i){
      ival = ival * 10 + str[i] - '0';
    }

    printf("ival = %d\n", ival);  
    // output -> ival = 123456
  }
*/

/*
  #define   SIZE  100

  int main(void){
    char str[SIZE] = "11111111"; // binary

    int ival = 0;
    for (int i = 0; str[i] != '\0'; ++i){
      ival = ival * 2 + str[i] - '0';
    }

    printf("ival = %d\n", ival);  
    // output -> ival = 255
  }
*/

/*
  #include <ctype.h>  // isdigit(), isxdigit(), toupper()

  #define   SIZE  100

  int main(void){
    char str[SIZE] = "1Ac"; // HEX 0-9 A-F a-f

    int ival = 0;

    for (int i = 0; str[i] != '\0'; ++i){
      if (isdigit(str[i]))
        ival = ival * 16 + str[i] - '0';
      else if (isxdigit(str[i]))
        ival = ival * 16 + toupper(str[i]) - 'A' + 10;
    }

    printf("ival = %d\n", ival);  
    // output -> ival = 428
  }
*/

/*
  // sayıdan yazıya dönüşüm

  #define   SIZE  100

  int main(void){
    int ival = 781234;
    char str[SIZE];

    int temp = ival;
    int len = 0;

    while (temp != 0){
      str[len++] = temp % 10 + '0';
      temp /= 10;
    }
    str[len] = '\0';

    printf("(%d) (%s)\n", ival, str);
    // output -> (781234) (432187)

    char ch;
    for (int i = 0; i < len / 2; ++i){
      ch = str[i];
      str[i] = str[len - 1 - i];
      str[len - 1 - i] = ch;
    }
    printf("(%d) (%s)\n", ival, str);
    // output -> (781234) (781234)
  }
*/

/*
  int is_strings_equal(const char* p1, const char* p2){
    while (*p1 == *p2){
      if (*p1 == '\0')
        return 1;
      ++p1;
      ++p2;
    }
    return 0;
  }

  int main(void){
    char s1[] = "Hello World we are live from Istanbul";
    char s2[] = "Hello World we are live from Istanbul";
    char s3[] = "Hello World we are live from Izmir";

    // int i = 0;
    // int flag = 0;
    // while (s1[i] == s2[i]){
    //   if (s1[i] == '\0'){   // both strings are equal becuase 
    //     flag = 1;           // when "s1[i] == s2[i]" expression is true  
    //     break;
    //   }
    //   ++i;
    // }

    if (is_strings_equal(s1, s2))
      printf("s1 and s2 are equal\n");
    else
      printf("s1 and s2 are not equal\n");
    
    // output -> s1 and s2 are equal

    if (is_strings_equal(s1, s3))
      printf("s1 and s3 are equal\n");
    else
      printf("s1 and s3 are not equal\n");
    
    // output -> s1 and s3 are not equal
  }
*/