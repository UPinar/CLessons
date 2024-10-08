#include <stdio.h>

/*
                  ------------------------------
                  | C language characteristics |
                  ------------------------------
            ----> Check c_language_charecteristics.png <----
*/

/*
  * C is an IMPERATIVE language.

  -> Imperative goes to a restaurant and orders a 6oz. steak 
  (cooked rare), fries (with ketchup), a side-salad,
  and a Coke (with no ice). The waiter delivers exactly what 
  he asked for, and he's charged $14.50. 
    [C, C++, Java]
  -> Declarative goes to a restaurant and tells the waiter that 
  he only wants to pay around 12 dollars for dinner, 
  and he's in the mood for steak. The waiter returns with a 6oz.
  steak (cooked medium), a side of mashed potatoes, steamed 
  broccoli, a dinner roll, and a glass of water. 
  He's charged $11.99. 
    [SQL and HTML]

  * C is an ARTIFICIAL language

  -> It's syntax is not very humanish, Cobol is not an 
  artificial language it's syntax is like human speaking
    Cobol example : INSPECT WS-STRING REPLACING ALL 'A' BY 'X'.
  Artificial languages are hard to read at the beginning 
  but much more EFFICIENT and EXPRESSIVE.

  C++ and Objective-C languages have been created by using 
  C language.
*/

/*
                        ---------------
                        | C Standarts |
                        ---------------

  C89/C90     first standart
  C95         minor
  C99         major
  C11         minor
  C17         minor
  C23     
*/

/*

                        -------------
                        | C program |
                        -------------
                ----> Check c_program.png <----
*/

/*
  1.  text editor
  2.  preprocessor (önişlemci)    -> preprocessing phase
  3.  compiler (derleyici)        -> compilation phase 
  4.  linker (bağlayıcı)          -> linking phase

  -----------
  text file : extension is only for user to find the file easily, 
    HTML, JSON, C source codes are text files.
  -----------

  1. text editors job is creating source code.
    --> source code/file(kaynak kod) has been created.

  2. preprocessors job is fulfilling preprocessor directives.
    -> preprocessor directives has different syntax 
    starts with # -> #define, #include ... 
    input is text file, output is also a text file.
    --> translation unit has been created.

  3. compilers job is converting C source code to 
  object code/file.
    -> in compiling phase, if a source code has been using 
    functions from another source code, compiler adds 
    references for linker to be able to link those 
    object codes that compiler has been created in compiling.

    --> object code/file(amac-hedef kod) has been created.

  4. linkers job is linking object codes to create executable 
    file.
      --> executable code/file(calistirilabilir kod) has been 
      created.


  a. preprocessing time
  b. compile time
  c. link time
  d. run time
*/

/*
                    ------------------------
                    | compiler - derleyici |
                    ------------------------
*/

/*
  1. tokenizing / lexical analysis
    -> is the code have a valid syntax rules ?
      syntax error (diagnostic)(bulgu iletisi)
      invalid code (geçersiz kod) - valid code
      illegal code - legal code

  2. optimizer (compiler optimizations)
    -> all conditions are same but different compilers have 
    been used. if one of the program is running faster than 
    the other one, that is because of the compiler's optimizer 
    module.

  3. logic control [not mandatory - customizable]
      -> for avoiding common logic errors (warning - diagnostic)

      if (x == y) -> if (x = y)
      x += y      -> x + y


  * static code analyzer tools job is, finding logic errors 
  in the code not compiling!
*/

/*
                  ----------------------------------
                  | tokenizing(atomlarina ayirmak) |
                  ----------------------------------
*/

/*
  * every token has a category
    1. keyword (anahtar sozcuk)     
    2. identifier/name (isim)

      A...Z   (latin roman character set) 
      a...z   (latin roman character set) 
      0 - 9   (arabic numerals)           
      _       (underscore)                

      * keywords can not be used as an identifier
      * numbers can not be the first character in an identifier.
      * C is case-sensitive language.
    3. operator
      +
      ++  >=
      >>=
      sizeof -> both operator and keyword
    4. constant(sabit)
      a. integer constants
        41      -> decimal      
        041     -> octal   
        0x41    -> hexadecimal
        0b (binary) is compiler extension in C, standart in C++
      b. floating constants
    5. string literal
      "hello"
    6. delimiter


  example --> x = a + b; 
  ----------------------
  x   --> identifier
  =   --> operator
  a   --> identifier
  +   --> operator
  b   --> identifier 
  ;   --> delimiter

  example --> "x = a + b;"
  ------------------------
  "x = a + b;" --> string literal
*/

/*
                      --------------
                      | some terms |
                      --------------
*/

/*
  statement (deyim) -> sentences in C language called statement.
  ; -> semicolon (terminator token)

  declaration -> is used for identifying identifiers 
    ismi tanıtan cümlelere declaration(declaration statement) 
    deniliyor.

  name lookup(isim arama) -> this phase has been done for 
  program to understand where the identifier has been declared

  expression (ifade) ->
    x                   -> expression
    x;                  -> expression statement
    10                  -> expression
    x * x + y * y       -> expression
    x * x + y * y;      -> expression statement
    x * x + y * y > 0   -> expression
    func();             -> expression statement              

    When terminator operator(;) has been added to those 
    expressions, they will become expression statements

  object (değişken) -> 
    objects have types(data types).
    objects have storage(yer).
  type (tür) ->
    1. basic types (fundemental types) (built-in types) 
    2. user-defined type

  constants have types 

  expressions have types, value, value category
    L value (sol taraf degeri)
    R value (sag taraf degeri)

  x       -> L value
  34      -> R value
  x + 5   -> R value
  +x      -> R value

  constant expression (sabit ifadesi) : 
    -> If an expressions value, has been guaranteed to known by 
    compiler in compile time, it is called constant expression.
    -> Eğer bir ifadenin değeri, derleme zamanında, derleyici 
    tarafından bilinme garantisindeyse böyle ifadelere 
    sabit ifadesi deniliyor.
*/

/*
  // constant expression

  int x = 5;
  int y = x + 3;  // syntax error
  // output -> expression must have a constant value

  int main(void){

  }
*/

/*
              ------------------------------------
              | number systems - sayı sistemleri |
              ------------------------------------
*/

/*
  decimal system      (onluk)
  octal system        (sekizlik)
  hexadecimal system  (onaltilik)
  binary system       (ikilik)

  unsigned binary system  (işaretsiz ikilik sayi sistemi)
    only positive -> sadece pozitif sayılar
  signed binary system    (işaretli ikilik sayi sistemi)
    both negative and positive -> hem negatif hem pozitif sayılar

  ----> Check memory_units.png <----
  binary digit(bit)   1 bit
  nibble              4 bit
  byte                8 bit (1 byte)
  word                2 byte
  double word DWORD   4 byte
  quad word   QWORD   8 byte 

  ----> Check unsigned_binary_calc.png <----
  0101'0001   = (1 * 2^0) + (1 * 2^4) + (1 * 2^6) 
              = 1 + 16 + 64 
              = 81


  79 to binary -> 0100'1111
  79 / 2 = 39 ->  1   -> LSB
  39 / 2 = 19 ->  1
  19 / 2 = 9  ->  1
  9 / 2 = 4   ->  1
  4 / 2 = 2   ->  0
  2 / 2 = 1   ->  0
  1 / 2 = 0   ->  1 

  unsigned -->
  1111'1111 = 255                 (1 byte)
  1111'1111'1111'1111 = 65,535    (2 byte)
  = 4,294,967,295                 (4 byte)
  = 18,446,744,073,709,551,615    (8 byte)

  one's complement (bire tumleyen)  -> change all bits 
  two's complement (ikiye tumleyen) -> add 1 to one's complement

  1000'0011
  0111'1100   -> one's complement
  0111'1101   -> two's complement

  0100'1010
  1011'0101   -> one's complement
  1011'0110   -> two's complement

  signed -->
  1110'0101 
  0001'1011 -> two's complement = 27
  1110'0101 = -27

  1011'1100
  0100'0100 -> two's complement = 68
  1011'1100 = -68


  0111'1111 = 127
  1000'0000 = -128
  1111'1111 = -1

  (1 byte) -128                        127
  (2 byte) -32'768                     32'767
  (4 byte) -2,147,483,648              2,147,483,647
  (8 byte) -9,223,372,036,854,775,808  9,223,372,036,854,775,807


  hex digits -> 0123456789ABCDE

  0   0000
  1   0001
  2   0010
  ...
  A   1010
  B   1011
  C   1100
  D   1101
  E   1110
  F   1111

  A2C1 -> 1010'0010'1100'0001
*/

/*
                      --------------
                      | characters |
                      --------------
*/

/*
  alfabetic characters + numeric characters = 
                                      alfanumeric characters
  control characters -> not printable characters
  punctuation characters -> printable but not alfanumeric 
                                                  characters

  @  64   -> at sign                  (IS NOT BEEN USED IN C)
  $  36   -> dolar sign               (IS NOT BEEN USED IN C)
  `  96   -> grave accent (backtick)  (IS NOT BEEN USED IN C)


  !  33   -> exclamation mark 
  "  34   -> double quote
  #  35   -> number sign (hash)       
  %  37   -> percent
  &  38   -> ampersand
  '  39   -> single quote
  *  42   -> asterisk
  +  43   -> plus sign
  ,  44   -> comma
  -  45   -> hyphen
  .  46   -> period / full-stop
  /  47   -> slash
  :  58   -> colon
  ;  59   -> semicolon
  <  60   -> less than 
  =  61   -> equal sign
  >  62   -> greater than
  ?  63   -> question mark     
  \  92   -> backslash
  ^  94   -> caret   
  _  95   -> underscore 
  |  124  -> pipe 
  ~  126  -> tilda

  ( ) parantheses                     parantez
  [ ] bracket (square bracket)        koseli parantez
  { } brace (curly brace)             suslu parantez
  < > angular bracket                 acisal parantez

  left - right, opening - closing
*/

/*
  #include <ctype.h>

  int main(void)
  {
    for (int i = 0; i < 128; ++i){
      if (ispunct(i))
        printf("%c  %d\n", i, i);
    }
  }

  //  output ->
  // !  33
  // "  34
  // #  35
  // $  36
  // %  37
  // &  38
  // '  39
  // (  40
  // )  41
  // *  42
  // +  43
  // ,  44
  // -  45
  // .  46
  // /  47
  // :  58
  // ;  59
  // <  60
  // =  61
  // >  62
  // ?  63
  // @  64
  // [  91
  // \  92
  // ]  93
  // ^  94
  // _  95
  // `  96
  // {  123
  // |  124
  // }  125
  // ~  126
*/

/*
                      ----------------
                      | header files |
                      ----------------
*/

/*
  What does the header files contains?
  Başlık dosyasında neler bulunur? 
  -----------------------------------

  1. function prototypes that we want, client codes to call
    müşteri(client) kodların çağırmasını istediğimiz 
    fonksiyonların prototipi(bildirimi)
  2. global degiskenlerin bildirimi (global variable declarations)
  3. user-defined type bildirimleri 
  4. type alias(tür eş isimleri)
  5. macrolar
*/

/*
  standart library consists of modules (header files)
    -> <stdio.h>    input&output operation
    -> <ctype.h>    character types
    -> <math.h>     math operations
    -> <stdlib.h>   exit abort
    ...
    https://en.cppreference.com/w/c/header
*/

/*
                  ------------------------------
                  | seperate compilation model |
                  ------------------------------
*/

/*
  There are 2 types of files 
    1. source(implementation) file  (file.c)
    2. header file                  (file.h)

  <---- check c_program.png ---->

  file1.h
  ==============
  int foo(int);     // function declaration

  file1.c 
  ===============
  int foo(int x){  // function definition
    return x * x;
  }

  main.c 
  ========
  #include <file.h>

  int main(void){
    int x = foo(11);
  }


  1. compiler will see foo function's declaration in main.c file
    #include <file.h>
  2. compiler will generate main functions entry and exit codes
    and external reference to foo() function
  3. file1.c will be compiled to file1.o(object file)
  4. main.c will be compiled to main.o
  5. linker will link main.o and file1.o together. 
*/
/*
                ----------------------
                | external reference |
                ----------------------
*/

/*
    main.c
    ========
    void foo(int x){
      int y = bar(x);     
    }
    // compiler must see bar functions declaration or definition
    
    in the object code that will be generated from main.c -> main.o
    compiler will write an external reference of bar() function
    for linker to understand which functions are being used inside 
    main.o(object file). 
    So linker can find the object code(.o file) where bar() 
    function's code were in and link both object codes.

    i.e bar functions code is in bar_code.c file 
      bar_code.o and main.o will be linked when the executable file 
      is being created.
*/

