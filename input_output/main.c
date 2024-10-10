 #include <stdio.h>

/*
                  ======================
                  | standart C library |
                  ======================
*/

/*
  Standart C library includes 
  1. standart C functions
  2. macros
  3. user-defined types
*/

/*
  #include <math.h>

  int main(void){
    for (int i = 0; i < 100; ++i){
      printf("%d %f\n", i, sqrt(i));
    }
  }

  // 2 standart C functions has been called in this code
  // printf and sqrt
*/

/*
  #include <math.h>

  // double pow(double base, double exp);

  int main(void){
    double base, exp;

    printf("write down base and exponential values: ");
    scanf("%lf%lf", &base, &exp);

    printf("%f to the power of %f equals %f", base, exp, pow(base, exp));
  }

  // output ->
  //  write down base and exponential values: 12.3 5.2
  //  12.300000 to the power of 5.200000 equals 465057.421651
*/

/*
          ================================================
          | call(pass) by value, call(pass) by reference |
          ================================================
*/

/*
  void foo(int x){
    x = 6554;
  }

  int main(void){
    int a = 4;

    foo(a); // call by value (pass by value)
    printf("a = %d\n", a);  // output -> a = 4
  }

  // compiled with, x86-64 gcc 14.1 -O0 -std=c11
  // foo:
  //   push rbp
  //   mov rbp, rsp
  //   mov DWORD PTR [rbp-4], edi
  //   mov DWORD PTR [rbp-4], 6554
  //   nop
  //   pop rbp
  //   ret
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   sub rsp, 16
  //   mov DWORD PTR [rbp-4], 4
  //   mov eax, DWORD PTR [rbp-4]
  //   mov edi, eax
  //   call foo
  //   mov eax, 0
  //   leave
  //   ret
*/

/*
  void foo(int* x){
    *x = 6554;  // dereferencing(*) operator
  }

  int main(void){
    int a = 4;

    // address of(&) operator
    foo(&a); // call by reference(pass by reference)

    printf("a = %d\n", a);  // output -> a = 6554
  }

  // compiled with, x86-64 gcc 14.1 -O0 -std=c11
  //   foo:
  //   push rbp
  //   mov rbp, rsp
  //   mov QWORD PTR [rbp-8], rdi
  //   mov rax, QWORD PTR [rbp-8]
  //   mov DWORD PTR [rax], 6554
  //   nop
  //   pop rbp
  //   ret
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   sub rsp, 16
  //   mov DWORD PTR [rbp-4], 4
  //   lea rax, [rbp-4]
  //   mov rdi, rax
  //   call foo
  //   mov eax, 0
  //   leave
  //   ret
*/

/*
  void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  int main(void){
    int x = 45, y = 93;
    printf("x = %d y = %d\n", x, y);  // output -> x = 45 y = 93

    swap(&x, &y);
    printf("x = %d y = %d\n", x, y);  // output -> x = 93 y = 45
  }

  // swap:
  //   push rbp
  //   mov rbp, rsp
  //   mov QWORD PTR [rbp-24], rdi  -> int* a = &x
  //   mov QWORD PTR [rbp-32], rsi  -> int* b = &y
  //   mov rax, QWORD PTR [rbp-24]  
  //   mov eax, DWORD PTR [rax]     
  //   mov DWORD PTR [rbp-4], eax   -> int temp  = *a
  //   mov rax, QWORD PTR [rbp-32]
  //   mov edx, DWORD PTR [rax]     
  //   mov rax, QWORD PTR [rbp-24]
  //   mov DWORD PTR [rax], edx     -> *a = *b
  //   mov rax, QWORD PTR [rbp-32]
  //   mov edx, DWORD PTR [rbp-4]
  //   mov DWORD PTR [rax], edx     -> *b = temp
  //   nop
  //   pop rbp
  //   ret
  // main:
  //   push rbp
  //   mov rbp, rsp
  //   sub rsp, 16
  //   mov DWORD PTR [rbp-4], 45    -> int x = 45;
  //   mov DWORD PTR [rbp-8], 93    -> int y = 93;
  //   lea rdx, [rbp-8]             
  //   lea rax, [rbp-4]             
  //   mov rsi, rdx                 
  //   mov rdi, rax                 
  //   call swap                    -> swap(&x, &y)
  //   mov eax, 0
  //   leave
  //   ret
*/

/*
                  ========================
                  | constants (sabitler) |
                  ========================
*/

/*
  constants have data types.

  -> integer constants 
    1. int 
    2. unsigned int
    3. long
    4. unsigned long
    5. long long
    6. unsigned long long

    !! short or char or _Bool CAN NOT be a constant type !!!

  -> floating constants 
    1. float
    2. double
    3. long double
*/

/*
  int main(void){
    876;      // int 
    0X1AC4;   // int

    0XACU;    // unsigned int
    536u;     // unsinged int

    78546L;   // long
    0xAB43L;  // long
    // ! do not use lowecase "l" for long constants, looks like "1"

    34UL;       // unsigned long
    0X1728ULL;  // unsigned long long

    0;    // int
    0L;   // long
    0UL;  // unsigned long
  }
*/

/*
  int main(void){
    3.4;  // double
    5.;   // double
    0.6;  // double
    .3;   // double  

    8.2f; // float
    9.3F; // float

    23F;  // syntax error (need ".")

    65.L; // long double
  }
*/

/*
  // scientific notations (üstel notasyon)

  int main(void){
    2.3e3;    // 2.3 * 10 ^ 3
    2.3e+3;   // 2.3 * 10 ^ 3
    2.3e-3;   // 2.3 * 10 ^ -3

    2e4f;     // 2 * 10 ^ 4 (float) -> 20000.0
  }
*/

/*
  <-- Check what_constants_become_standart.png -->

  #include <limits.h>

  int main(void){
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(long int) = %d\n", sizeof(long int));
    printf("sizeof(long long int) = %d\n", sizeof(long long int));

    // output -> 
    //  sizeof(int) = 4
    //  sizeof(long int) = 4
    //  sizeof(long long int) = 8

    printf("INT_MAX = %d\n", INT_MAX);    // output -> 2'147'483'647
    printf("LONG MAX = %d\n", LONG_MAX);  // output -> 2'147'483'647

    // decimal (int) constant will become long long int because 
    // long int is also 4 byte in this compiler 

    // 2147483647 + 2 = 2147483649
    2147483649; // type of the constant is long long int
  }
*/

/*
  #include <limits.h>

  int main(void){
    printf("INT_MAX_HEX = %X", INT_MAX); 
    // output -> INT_MAX_HEX = 7FFFFFFF

    // 0X7FFF'FFFF + 0X0000'0001 = 0X8000'0000

    0X7FFFFFFF; // the type of hexadecimal constant is int
    0X80000000; // the type of hexadecimal constant is unsigned int
  }
*/

/*
                  -----------------------
                  | character constants |
                  -----------------------
  -> in C, character constants type is int, in C++ it is char
*/

/*
  0
  1
  2
  ...
  48  0     -> 0011'0000  5th and 6th bit is set, lower 4 bit = 0
  49  1     -> 0011'0001  5th and 6th bit is set, lower 4 bit = 1
  ...
  56  8     -> 0011'1000  5th and 6th bit is set, lower 4 bit = 8
  57  9     -> 0011'1001  5th and 6th bit is set, lower 4 bit = 9
  ...
  65  'A'   -> 0100'0001  when 5th bit is set, 
                          will become lowercase 'a'
  66  'B'   -> 0100'0010  when 5th bit is set, 
                          will become lowercase 'b'
  ...
  90  'Z'
  ...
  97  'a'   -> 0110'0001 when 5th bit is clear, 
                        will become uppercase 'A'
  98  'b'   -> 0110'0010 when 5th bit is clear, 
                        will become uppercase 'B'
  ...

  first 32(0-31) and the last character(127) are control characters
*/

/*
  // <---- Check chars.txt ---->

  #include <ctype.h>

  int main(void){
    
    FILE* f = fopen("chars.txt", "w");

    for (int i = 0; i < 128; ++i){
      if (iscntrl(i)){
        fprintf(f, "%3d control character\n", i);
      }
      else
        fprintf(f, "%3d      %c\n", i, i);
    }
  }
*/

/*
  48-57                   -> digit(numeric) characters
  65-90 & 97-122          -> alphabetic characters 
  48-57 & 65-90 & 97-122  -> alphanumeric characters

  if a character have graphic           -> printable character
  if a character did not have graphic   -> control character
  if printable but not alphanumeric     -> punctuation character

  32 (space character)  is printable but not graphic -> ' '
*/

/*
  int main(void){

    int x = '+';
    printf("x = %d\n", x);  // output -> x = 43

    for (int i = '0'; i <= '9'; ++i){
      printf("%d\n", i);
    }
    // output ->
    //  48
    //  49
    //  50
    //  51
    //  52
    //  53
    //  54
    //  55
    //  56
    //  57
  }
*/

/*
  -> Alphabetic characters doesn't have to be consecutive
  -> Numeric characters has to be consecutive
*/

/*
  escape sequence (kaçış sekansı)
  -------------------------------
  '\0'  -> null 
  '\a'  -> alert 
  '\b'  -> backspace 
  '\n'  -> newline
  '\r'  -> carriage return
  '\t'  -> horizontal tab
  '\v'  -> vertical tab
  '\f'  -> form feed
  '\\'  -> backslash
  '\''  -> single quote
  '\"'  -> double quote 
  '"'   -> double quote 
  '\?'  -> question mark
  '?'   -> question mark
*/

/*
  int main(void){
    printf("null              %d\n", '\0');  
    printf("alert             %d\n", '\a'); 
    printf("backspace         %d\n", '\b'); 
    printf("newline           %d\n", '\n'); 
    printf("carriage return   %d\n", '\r'); 
    printf("horizontal tab    %d\n", '\t');
    printf("vertical tab      %d\n", '\v'); 
    printf("form feed         %d\n", '\f'); 
    printf("backslash         %d\n", '\\'); 
    printf("single quote      %d\n", '\''); 
    printf("double quote      %d\n", '"'); 
    printf("double quote      %d\n", '\"'); 
    printf("question mark     %d\n", '\?'); 
    printf("question mark     %d\n", '?'); 

    // output ->
    //  null              0
    //  alert             7
    //  backspace         8
    //  newline           10
    //  carriage return   13
    //  horizontal tab    9
    //  vertical tab      11
    //  form feed         12
    //  backslash         92
    //  single quote      39
    //  double quote      34
    //  double quote      34
    //  question mark     63
    //  question mark     63
  }
*/

/*
  int main(void){
    '\x41'; // its type is (int)65  -> HEX
    '\x1B'; // its type is (int)27  -> HEX
    '\x5B'; // its type is (int)91  -> HEX

    '\043'; // its type is (int)35  -> OCTAL
    '\045'; // its type is (int)37  -> OCTAL
  }
*/

/*
  int main(void){

    int x = 'A';  
    int y = '\b';   
    int y = '\x1a';  // HEX
    int y = '\054';  // OCT
  }
*/


/*
                  =============================
                  | Input & Output Operations |
                  =============================
*/

/*
  <-- Check input_output_stream.png -->

  when a program starts some streams automatically created by system
    1. standart input stream    -> keyboard(default)
    2. standart output stream   -> monitor(default)
    2. standart error stream    -> monitor(default)
*/

/*
  think about an integer(4 byte) have a value of = 1'456'871
  its bytes are 
  -> 00000000'00010110'00111010'11100111 

  if we give those exact 4 byte to stream, that will called 
  unformatted 

  if we give bytes of the character codes of 1'456'87, it will be 
  formatted.

  1 -> 49 -> 00110001
  4 -> 52 -> 00110100
  5 -> 53 -> 00110101
  6 -> 54 -> 00110110
  8 -> 56 -> 00111000
  7 -> 55 -> 00110111
  1 -> 49 -> 00110001

  // printf is formatted output function
  // scanf is formatted input function
*/

/*
  tam sayılar için formatlama tercihleri:
  ---------------------------------------
  1. kullanılacak sayı sistemi
  2. sayı sistemi tabanı ön eki gösterilsin mi?
  3. sayı sistemi hex ise harf karakterleri büyük mü küçük mü olsun ?
  4. pozitif tam sayıların yazımında + karakteri gösterilsin mi ?
  5. yazma alanı genişliği (output width)
    a. doldurma karakteri (fill character)
    b. saga / sola dayali (left / right aligned)


  gerçek sayılar (floating) için formatlama tercihleri:
  -----------------------------------------------------
  1. fixed or scientific notation, depends on number 
  2. nokta gösterilsin mi?
  3. noktadan sonra kaç basamak gösterilsin ?
*/

/*
  int main(void){

    int x = 723434;

    printf("x = %d\n", x);    // output -> x = 723434
    printf("x = %x\n", x);    // output -> x = b09ea
    printf("x = %o\n", x);    // output -> x = 2604752
    printf("x = %#x\n", x);   // output -> x = 0xb09ea
    printf("x = %#X\n", x);   // output -> x = 0XB09EA
  }
*/

/*
                  ---------------------
                  | printf() function |
                  ---------------------
*/

/*
  int printf(const char* pfmt, ...);
  // function declaration(prototype)
  // printf is writing standart output stream(default -> monitor)
  // return value is how many character has been written to stream
*/

/*
  // array(dizi)
  int main(void){

    char str[20];  
    // {'u', 'y', 'g', 'a', 'r', '\0'} -> null terminated byte stream
  }
*/

/*
  // functions parameter variables can not be array in C
  // arrays should be send to function with call by reference

  void foo(char* arr);

  int main(void){
    char char_arr[10];

    foo(&char_arr[0]);

    // when array identifier has been used in an expression
    // compiler will convert array identifier to the 
    // address of the first element of the array
    // it has been called "array decay"
    foo(char_arr);    // array decay (call by reference)
  }
*/

/*
  int foo(int*, ...);  
  // call by ref -> to write(modify) the variable or array

  int bar(const int*, ...);
  // call by ref -> to read(not modify) the variable or array
*/


/*
  int main(void){

    "hello";  // this is an array have 6 elements 
    // {'h', 'e', 'l', 'l', 'o', '\0'}

    printf("hello");  // we are sending an address of the char array

    "hello\nworld\n"; // '\n' characters length is 1
    // {'h', 'e', 'l', 'l', 'o', '\n', 
    //    'w', 'o','r', 'l', 'd', '\n', '\0'}
  }
*/

/*
  int main(void){
    
    printf("\x42\x41\x42\x41"); // output -> BABA
    // decimal 66, 65, 66, 65
  }
*/

/*
  // output wanted ->
  // x = 368 
  // y = 20

  int main(void){
    int x = 368;
    int y = 20;

    printf("x = %d\ny = %d", x, y);
  }
*/

/*
  // output wanted -> 42 * 42 + 34 * 34 = 2920 

  int main(void){
    int x = 42;
    int y = 34;

    printf("%d * %d + %d * %d = %d\n", x, x, y, y, x * x + y * y);
  }
*/

/*
  int main(void){
    int x;

    printf("Bir tam sayi giriniz: ");
    scanf("%d", &x);

    printf("x = %d\n", x);
    printf("x = %o\n", x);    // octal
    printf("x = %x\n", x);    // hex
    printf("x = %X\n", x);    // uppercase hex
    printf("x = %#X\n", x);   // 0X + uppercase hex

    // output ->
    //  Bir tam sayi giriniz: 8278
    //  x = 8278
    //  x = 20126
    //  x = 2056
    //  x = 2056
    //  x = 0X2056
  }
*/

/*
  signed long         %ld
  signed long long    %lld
  unsigned int        %u
  unsigned long       %lu
  double, float       %f
  string(char array)  %s
*/

/*
  int main(void){
    char str[100] = "Istanbul, Ankara, Izmir";

    printf("cities = %s\n", str);
    // output -> cities = Istanbul, Ankara, Izmir

    printf(str);  
    // output -> Istanbul, Ankara, Izmir
  }
*/

/*
  int main(void){
    int x = 11;
    int y = 222;
    int z = 3333;

    int ret_x = printf("%d + %d = %d\n", x, x, x + x);
    // output -> 11 + 11 = 22
    printf("ret_x = %d\n", ret_x);  // output -> ret_x = 13

    int ret_y = printf("%d + %d = %d\n", y, y, y + y);
    // output -> 222 + 222 = 444
    printf("ret_y = %d\n", ret_y);  // output -> ret_y = 16

    int ret_z = printf("%d + %d = %d\n", z, z, z + z);
    // output -> 3333 + 3333 = 6666
    printf("ret_z = %d\n", ret_z);  // output -> ret_z = 19

    // return value of printf() function is character count
    // has been written to standart output 
    // return value will generally discarded in programs
  }
*/

/*
  -> in printf() function, if format specifier count is GREATER than 
  variadic arguments count, it will be undefined behaviour

  printf("a = %d, b = %d\n", a);  
  // format specifier count = 2, variadic argument count = 1 (UB)

  -> in printf() function, if format specifier count is LESS than 
  variadic arguments count, it is valid 

  printf("a = %d, b = %d\n", a, b, c);  
  // format specifier count = 2, variadic argument count = 3 VALID

  -> in printf() function, if format specifier type is differ from
  variadic argument type, it will be undefined behaviour

  unsigned int x = 476;
  printf("x = %f", x);  // (UB)
*/

/*
  // if we want to use '%' character in standart output 
  // we will need "%%" 

  int main(void){
    printf("%%\n"); // output -> %

    double vat = 18.;
    printf("kdv = %%%.2f\n", vat); // output -> kdv = %18.00
  }
*/

/*
  // output wanted 17%5=2

  int main(void){
    int x =  17;
    int y = 5;

    printf("%d%%%d=%d", x, y, x % y); // output -> 17%5=2
  }
*/

/*
                  --------------------
                  | scanf() function |
                  --------------------
*/

/*
  scanf is a formatted input function
  scanf is also a variadic function like printf

  scanf is a function that is not guaranteed to be succeed so
  return value of the scanf is an information about its success

  int scanf(const char*, ...);  // function declaration
*/

/*
  int main(void){
    int x;

    printf("write a value : ");
    int ret = scanf("%d", &x);
    printf("ret = %d", ret);

    // input -> 678 
    // output -> ret = 1

    // input -> abc
    // output -> ret = 0
  }
*/

/*
  printf  -> double -> %f   float %f 
  scanf   -> double -> %lf  float %f 
*/

/*
  int main(void){
    int x;

    printf("write a value : ");
    scanf("%x", &x);
    printf("x = %d\n", x);

    // input -> 111 (1 * 16^2 + 1 * 16^1 * 1 * 16^0)
    // output -> x = 273
  }
*/

/*
  scanf function is using white space characters as a seperator
  when we press ENTER in keyboar it will add new line character to 
  scanf() functions buffer -> line buffered function
*/

/*
  int main(void){
    int x;

    printf("write a value : ");
    scanf("%d", &x);
    printf("x = %d", x);

    // input -> 675ankara
    // output -> 675 

    // but program has still have "ankara" string in the buffer
  }
*/

/*
  int main(void){
    int x;

    printf("write a value : ");
    scanf("%d", &x);
    printf("x = %d\n", x);
    // input -> 675hello
    // output -> x = 675 

    // "675" characters extracted from the input buffer
    // program has still have "ankara" characters the buffer

    int y;
    scanf("%x", &y);
    printf("y = %d\n", y);

    // "a" character which is inside buffer will be used as an input 
    // output -> y = 10

    // "a" character extracted from the input buffer
    // program has still have "nkara" characters in the buffer
  }
*/

/*
  // space characters can be used as seperator in scanf() function
  // to get different values from standart input

  int main(void){
    int x, y;

    printf("Write 2 numbers : ");
    scanf("%d%d", &x, &y);

    printf("x = %d y = %d\n", x, y);

    // input  -> Write 2 numbers : 18 189
    // output -> x = 18 y = 189
  }
*/

/*
  int main(void){
    int x;
    double d;

    printf("Enter values : ");
    scanf("%d%lf", &x, &d);

    printf("x = %d d = %f\n", x, d);

    // input  -> Enter values : 561 45.891
    // output -> x = 561 d = 45.891000

    // input  -> Enter values : 56.987
    // output -> x = 56 d = 0.987000  
  }
*/


/*
  Warning! scanf() functions return value must be tested!
  Because scanf() function could not set variables if input is not
  written correct.
*/

/*
  // If scanf() is not succeed to set a variable, it is not extracting
  // characters from the buffer.

  int main(void){
    int x, y, z;

    printf("Write 3 numbers : ");
    int ret = scanf("%d%d%d", &x, &y, &z);

    printf("ret = %d\n", ret);

    // input  -> Write 3 numbers : 20 56 89
    // output -> ret = 3

    // input  -> Write 3 numbers : 20 56 hello
    // output -> ret = 2

    // input  -> Write 3 numbers : 20 hello world
    // output -> ret = 1

    // input  -> Write 3 numbers : hello 20 36
    // output -> ret = 0
    // buffer is not extracted "hello" characters from buffer
    // when it has failed for the first time
  }
*/

/*
  // If scanf()'s buffer is empty, function will return -1

  int main(void){
    int x, y, z;

    printf("Write 3 numbers : ");
    int ret = scanf("%d%d%d", &x, &y, &z);

    printf("ret = %d\n", ret);

    // input  -> Write 3 numbers : 20 56 89
    // output -> ret = 3

    // input  -> Write 3 numbers : ^Z
    //            ^Z
    //            ^Z
    // output -> ret = -1
    // In windows need to send ^Z and ^M for 3 times in a row 
    // to send EOF(End Of File)
  }
*/

/*
  int max3(int a, int b, int c){
    int max = a;

    if (b > max)
      max = b;

    if (c > max)
      max = c;

    return max;
  }

  int main(void){
    printf("3 sayi giriniz : ");

    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);

    printf("%d %d %d sayilarinin en buyugu %d\n", x, y, z, max3(x, y, z));
  }
*/

/*
  int main(void){

    int x, y, z;

    (void)scanf("%d%d%d", &x, &y, &z);
    // if we want to discard the return value of scanf()
    // and we want the reader to understand that we will discard
    // the return value we can use type-cast operator to 
    // cast the return value to type void

    // type-cast operator -> tür dönüştürme operatörü
  }
*/

/*
  int main(void){

    int x = 65;
    printf("%c\n", x);  // output -> A

    // %c format specifier will convert the integer value to 
    // character literal

    for (int i = 33; i < 127; ++i){
      printf("%c", i);
    }
    // output ->
    // !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ
    // [\]^_`abcdefghijklmnopqrstuvwxyz{|}~

    for (int i = 33; i < 127; ++i){
      printf("%3d  %#X  %c\n", i, i, i);
    }
  }
*/

/*
                  ----------------------
                  | getchar() function |
                  ----------------------
    unformatted input function
    its declaration is inside <stdio.h> header file
*/

/*
  int getchar(void);  
  // line-buffered input function (satır-tamponlu fonksiyon)
  // needs to end with new line character (ENTER)
*/

/*
  int main(void){
    printf("write a character : ");
    int ch = getchar();

    printf("ch = %d\n", ch);

    // input -> Istanbul
    // output -> ch = 73

    // input -> a
    // output -> 97

    // input -> A
    // output -> 65
  }
*/

/*
  int main(void){
    printf("write something : ");

    int ch = getchar();
    printf("ch = %d\n", ch);
    ch = getchar();
    printf("ch = %d\n", ch);
    ch = getchar();
    printf("ch = %d\n", ch);
    ch = getchar();
    printf("ch = %d\n", ch);

    // input -> Istanbul
    // output ->
    //  ch = 73
    //  ch = 115
    //  ch = 116
    //  ch = 97

    // "nbul" characters are still in the buffer.
  }
*/

/*
  // getchar() and scanf() are using the same buffer.

  int main(void){
    int ival;
    double dval;
    char sep;

    printf("write something : ");    // 1234*34.67
    scanf("%d", &ival);
    sep = getchar();
    scanf("%lf", &dval);

    printf("ival = %d, sep = %d, dval = %f\n", ival, sep, dval);

    // input -> write something : 1234*34.67
    // output -> ival = 1234, sep = 42, dval = 34.670000
  }
*/

/*
  // getchar() returns -1 when buffer is empty

  int main(void){
    printf("write a character : ");    
    int c = getchar();
    printf("ch = %d\n", c); 
    // input -> ^Z (ctrl + z) for Windows (ctrl + d) for Linux
    // output -> ch = -1
  }
*/

/*
  int main(void){
    int c;

    printf("Write a number : ");

    while ((c = getchar()) != '\n'){
      printf("%d --> %d\n", c,  c - '0');
    }

    // input -> Write a number : 654321
    // output ->
    //  54 --> 6
    //  53 --> 5
    //  52 --> 4
    //  51 --> 3
    //  50 --> 2
    //  49 --> 1
  }
*/

/*
  int main(void){
    int c;

    printf("Write a number : ");

    int x = 0;
    while ((c = getchar()) != '\n'){
      x = x * 10 + (c - '0');
    }

    printf("written number = %d", x);

    // input -> Write a number : 654321
    // output -> written number = 654321
  }
*/

/*
  // Write a number and check if it can be divisible by 3
  // the number can be larger than limits of "int" type.

  int main(void){
    int x;
    printf("write a number : ");

    int digit_sum = 0;
    int c;

    while ((c = getchar()) != '\n'){
      digit_sum += c - '0';
    }

    if (digit_sum % 3 == 0)
      printf("Number is divisible by 3\n");
    else
      printf("Number is NOT divisible by 3\n");
  }
*/

/*
  int main(void){
    printf("true(t) or false(f) : ");

    int ch = getchar();

    if (ch == 't')
      printf("TRUE\n");
    else if (ch == 'f')
      printf("FALSE\n");
    else
      printf("UNDEFINED\n");
  }
*/

/*
                  ----------------------
                  | putchar() function |
                  ----------------------
    unformatted output function
    its declaration is inside <stdio.h> header file
    int putchar(int); 
*/

/*
  int main(void){
    putchar(65);  // output -> A 
    // if the program is using ASCII output will be "A"
    // but not guaranteed

    putchar('A'); // output -> A
    // better using character constant 'A'
  }
*/

/*
  int main(void){
    for (int i = 65; i <= 90; ++i)
      putchar(i);
    // output -> ABCDEFGHIJKLMNOPQRSTUVWXYZ

    printf("\n");  

    for (int i = 65; i <= 90; ++i)
      printf("%c", i);
    // output -> ABCDEFGHIJKLMNOPQRSTUVWXYZ
  }
*/