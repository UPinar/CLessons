#include <stdio.h>

/*
                      ===================
                      | String Literals |
                      ===================
*/

/*
  - tokenizing aşamasında string literallerim ayrı tokenlar olarak
    ayrılırlar.

  - derleyici ("hello") çift tırnak içinde bir yazı ile karşılaştığında
    bu yazıyı bir diziye dönüştürür. 
    Bu dizinin boyutu yazıdaki karakter sayısı + 1'dir.
    (karakter sayısı + 1)

  - Kod içinde string literal'inin kullanıldığı ifadede, 
    string literalini, oluşturduğu dizinin adresine dönüştürür.

  - C'de string literalleri elemanları `char` olan diziler.
  - C++'da string literalleri elemanları `const char` olan diziler.
*/

/*
  int main(void)
  {
    int arr[10] =  { 0 };

    arr;
    // "arr" is an LValue expression

    "hello world";
    // "hello world" is an LValue expression

    char str[6] = "hello";
    str; 
    // "str" is an LValue expression
  }
*/

/*
  int main(void)
  {
    "hello";  
    // "hello" is an LValue expression 
    // its data type is `char[6]`
  }
*/

/*
  int main(void)
  {
    char* ptr = "hello";
    // "hello" expression's type is char[6]
    // compiler will convert array to a pointer 
    // so "hello" char[6] array will converted to char* pointer
  }
*/

/*
  #include <string.h> // strlen

  int main(void)
  {
    *"hello world"; // VALID 
    // dereferencing a pointer(array decay)

    putchar(*"ISTANBUL");   // output -> I
    putchar("ISTANBUL"[3]); // output -> A

    printf("%zu\n", strlen("Istanbul"));  // output -> 8
    // strlen function have a const char* parameter
  }
*/

/*
  int main(void)
  {
    "hello world";  
    // string literals in C are static storage duration arrays
    // will stay in the memory until the program ends

    printf("Istanbul"); 
    // "Istanbul" string literal will be stored in the memory
    // until the program ends
  }
*/

/*
  // warning: function returns address of local variable
  char* get_name(void)
  {
    char str[100] = "hello";  
    // str is an automatic storage duration array(local variable)

    return str;
  }

  // function returns address of static storage duration array
  char* get_name_2(void)
  {
    return "hello"; 
    // "hello" is a string literal which is 
    // a static storage duration array
  }
*/

/*
  char* get_weekday_name(int day_number)
  {
    switch(day_number){
    case 1: return "Monday";
    case 2: return "Tuesday";
    case 3: return "Wednesday";
    case 4: return "Thursday";
    case 5: return "Friday";
    case 6: return "Saturday";
    case 7: return "Sunday";
    }

    return NULL;
  }

  int main(void)
  {
    for (int i = 1; i <= 7; ++i)
      printf("%d -> %s\n", i, get_weekday_name(i));

    // output ->
    //  1 -> Monday
    //  2 -> Tuesday
    //  3 -> Wednesday
    //  4 -> Thursday
    //  5 -> Friday
    //  6 -> Saturday
    //  7 -> Sunday
  }
*/

/*
  int main(void)
  {
    for (int i = 1; i <= 10; ++i){
      char* ptr = "istanbul ankara izmir";
      printf("%p\n", ptr);
    }
    // output ->
    //  00007FF77B995050
    //  00007FF77B995050
    //  00007FF77B995050
    //  00007FF77B995050
    //  00007FF77B995050
    //  00007FF77B995050
    //  00007FF77B995050
    //  00007FF77B995050
    //  00007FF77B995050
    //  00007FF77B995050
  }
*/

/*
  int main(void)
  {
    char* p = "hello";
    puts(p);  // output -> hello


    p[0] = 'H'; // undefined behaviour(UB)
    // string literals are read-only data
    // trying to modify a string literal is UB
  }
*/

/*
  #include <string.h> // strcpy, strcat

  int main(void)
  {
    // ---------------------------------------------------

    char* ptr = "hello";

    strcpy(ptr, "world");   // undefined behaviour(UB)
    // trying to modify a string literal is UB

    // if a string literal will sent to a function
    // it should be sent as a const char* parameter
    // because string literals are read-only data

    // ---------------------------------------------------

    char str[100];
    strcpy(str, "Istanbul");  
    // second parameter is accepting const char* type
    strcat(str, " Ankara");
    // second parameter is accepting const char* type

    puts(str);  // output -> Istanbul Ankara

    // ---------------------------------------------------
  }
*/

/*
  int main(void)
  {
    char* p = "hello world";

    *p = 'H'; // undefined behaviour(UB)
    // not a syntax error but UB, trying to modify a string literal

    const char* p2 = "hello world";
    // better defining p2 as a const char* type
    // for prevent UB and also for compatability with C++
  }
*/

/*
  int main(void)
  {
    // ---------------------------------------------------

    char str_1[] = "World";
    char str_2[] = { 'W', 'o', 'r', 'l', 'd', '\0' };
    // Those 2 lines are equivalent.
    // str_1 is an automatic storage duration array

    str_1[0] = 'w'; // VALID

    // ---------------------------------------------------

    char* p = "Universe";
    // "Universe" is a string literal and it is 
    // a static storage duration array

    p[0] = 'u'; // undefined behaviour(UB)
    *p = 'u';   // undefined behaviour(UB)

    // ---------------------------------------------------
  }
*/

/*
  int main(void)
  {
    char* p1 = "hello world";
    char* p2 = "hello world";
    // when same string literals 
    // used as a static storage duration array more than once
    // depends on the compiler, it will store that literal once or more
    // inside the read only memory (unspecified behaviour)

    if (p1 == p2) {} // unspecified behaviour
  }
*/

/*
  #include <string.h> // strcpy, strcat, strrchr, strcmp

  #define SIZE 100

  int main(void)
  {
    char old_file_name[SIZE];
    char new_file_name[SIZE];

    printf("Enter a file name: ");
    scanf("%s", old_file_name);

    // ---------------------------------------------------

    // (1)  if file does not have an extension 
    //      change the file extension to ".txt"

    // (2)  if file's extension is ".jpg"
    //      change the file extension to ".gif"

    // (3)  if file's extension is ".xls"
    //      delete the file extension

    strcpy(new_file_name, old_file_name);
    char* p = strrchr(new_file_name, '.');

    if(!p)
      strcat(new_file_name, ".txt");
    else if(!strcmp(p, ".jpg"))
      strcpy(p, ".gif");
    else if(!strcmp(p, ".xls"))
      *p = '\0';
      // strcpy(p, ""); -> null string literal
    
    printf("(%s) ==> (%s)\n", old_file_name, new_file_name);

    // input  -> Enter a file name: notes
    // output -> (notes) ==> (notes.txt)

    // input  -> Enter a file name: notes.jpg
    // output -> (notes.jpg) ==> (notes.gif)

    // input  -> Enter a file name: file.xls
    // output -> (file.xls) ==> (file)

    // ---------------------------------------------------
  }
*/

/*
  int main(void)
  {
    const char* p = "";   // null string literal
    // null string literal is char[1] array
    // its first and last element is '\0'
  }
*/

/*
  #include <string.h> // strlen

  void foo(char p[])
  {
    printf("[8] -> %zu\n", sizeof(p));
  }

  int main(void)
  {
    char str[] = "hello";
    char* p = "world";

    printf("[1] -> %zu\n", sizeof(str));    // output -> [1] -> 6
    // "sizeof(str)" is a constant expression (compile time constant)

    printf("[2] -> %zu\n", strlen(str));    // output -> [2] -> 5
    // strlen function is executed at run-time

    printf("[3] -> %zu\n", sizeof(*str));   // output -> [3] -> 1
    // when sizeof operators operand is an expression
    // it will check the size of the type of the expression
    // "*str" is an expression and its data type is char

    printf("[4] -> %zu\n", sizeof(p));      // output -> [4] -> 8
    
    printf("[5] -> %zu\n", sizeof(p++));    // output -> [5] -> 8
    // no operation code will be generated for p++ expression

    printf("[6] -> %zu\n", strlen(p));      // output -> [6] -> 5

    printf("[7] -> %zu\n", sizeof(p[900])); // output -> [7] -> 1
    // "p[900]" is an expression and its data type is char
    // because of no operation code will be generated 
    // for p[900] expression, it won't be an UB

    foo("Istanbul Ankara Izmir");           // output -> [8] -> 8

    printf("[9] -> %zu\n", sizeof(""));     // output -> [9] -> 1

    printf("[10] -> %zu\n", strlen(""));    // output -> [10] -> 0
  }
*/

/*
  int main(void)
  {
    char str[] = "hello";

    str + " world"; // syntax error
    // error: invalid operands to binary + (have 'char *' and 'char *')

    // adding 2 pointers is not a valid operation
  }
*/

/*
  int main(void)
  {
    printf("%d\n", 2["elma"] - 1["elma"]);          // output -> 1
    printf("%d\n", *(2 + "elma") - *(1 + "elma"));  // output -> 1
    printf("%d\n", 'm' - 'l');                      // output -> 1
    // Those 3 lines are equivalent.
  }
*/

/*
  int main(void)
  {
    char *p = "\x42\x41\x42\x41";
    puts(p);  // output -> BABA

    char *p2 = "\062\060\062\064";
    puts(p2); // output -> 2024
  }
*/

/*
  int main(void)
  {
    char* p = "\"hello\"";
    puts(p);    // output -> "hello"

    char* p2 = "\\hello\\";
    puts(p2);   // output -> \hello\

    char* p3 = "\"\\hello\\\"";
    puts(p3);   // output -> "\hello\" 
  }
*/

/*
  int main(void)
  {
    // ---------------------------------------------------

    char *p = "monday \
  tuesday \
  wednesday \
  thursday \
  friday";
    puts(p);
    // output -> monday tuesday wednesday thursday friday

    char *p2 =  "monday  \
                tuesday";
    puts(p2);
    // output -> monday                 tuesday

    // ---------------------------------------------------

    char *p3 =  "monday " 
                "tuesday " 
                "wednesday " 
                "thursday " 
                "friday ";
    puts(p3);
    // output -> monday tuesday wednesday thursday friday

    // ---------------------------------------------------
  }
*/

/*
  #include <string.h> // strcpy, strcat

  int main(void)
  {
    char str_1[100];
    char str_2[100];

    strcpy(str_1, "hello world");
    puts(str_1);  // output -> hello world

    strcat(str_2, "hello world"); // undefined behaviour(UB)
    // strcat will copy to the address of the null character,
    // because of str_2 is an automatic storage duration array
    // an is not been initialized, it has indetermined(garbage)
    // values inside it.
  }
*/

/*
  #include <string.h> // strcpy, strcat

  int main(void)
  {
    char str_1[100] = "";
    char str_2[100] = "";   // null string literal

    strcpy(str_1, "hello world");
    puts(str_1);  // output -> hello world

    strcat(str_2, "hello world"); 
    puts(str_2);  // output -> hello world
  }
*/