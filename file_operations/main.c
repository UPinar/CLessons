/*
                      ===================
                      | File Operations |
                      ===================
*/

/*
  - her dosyanın bir formatı vardır. Format, dosyadaki bitlerin 
    ne anlama geldiğini belirler. (file format)

  - işletim sistemlerinin sistem fonksiyonları daha fazla 
    kontrol olanağı sağlar.
  
  - işletim sisteminin sistem fonksiyonları yerine 
    taşınabilirliği sağlamak için C standart dosya fonksiyonları
    kullanılır.
*/

/*
  #include <stdio.h>  // fopen, fclose

  - fopen will return an address of a structure variable.
  FILE* fopen(const char* filename, const char* open_mode);

  - fclose will close the file.
  int fclose(FILE* file_pointer);

  - fprintf(FILE* file_pointer, const char* format, ...);
  - fputc(int character, FILE* file_pointer);
*/

/*
  -------------------------------------------------

  - reading from a file (dosyadan okuma)
  * fgetc, fscanf, fgets, fread 

  -------------------------------------------------

  - writing to a file   (dosyaya yazma)
    - changing existing data  (mevcut veriyi değiştirme)
    - appending data          (veri ekleme)

  * fputc, fprintf, fputs, fwrite

  -------------------------------------------------

  - file pointer        (dosya konum göstericisi)
      is an integral variable(offset) 
      file pointer will change after each read/write operation.

    - sequential access (sıralı erişim)
      döngüsel bir yapıda okuma/yazma işlemi yapıldığında 
      her işlemden sonra dosya konum göstericisi
      N sonraki byte'ın indexini tutar.

    - random access (rastgele erişim)
      doğrudan istenilen bir byte'a erişim yapılabilir.
  
  * fseek, rewind, ftell, fsetpos, fgetpos

  -------------------------------------------------
*/

/*
                      ----------------------
                      | fopen in <stdio.h> |
                      ----------------------
*/

/*
  // fopen function prototype
  FILE* fopen(const char* filename, const char* open_mode);
    
  - if it fails, it will return NULL.

  ------------------------------------------
                file open mode :
  ------------------------------------------

  1)  dosya varsa ne olur, yoksa ne olur?

  2)  dosyadan okuma işlemi yapılabilir mi ?
      dosyaya yazma işlemi yapılabilir mi ?

  ------------------------------------------

  - "r"  : read(okuma) mode 
  1)  dosya varsa açılır, yoksa açılmaz.
  2)  dosyadan okuma işlemi yapılabilir.
      dosyaya yazma işlemi yapılamaz.

                -----------------

  - "r+" : read+ mode
  1)  dosya varsa açılır, yoksa açılmaz.
  2)  dosyadan okuma işlemi yapılabilir.
      dosyaya yazma işlemi yapılabilir.

                -----------------

  - "w"  : write(yazma) mode     
  1)  dosya varsa budanır(truncate), yoksa oluşturulur.
  2)  dosyadan okuma işlemi yapılamaz.
      dosyaya yazma işlemi yapılabilir.

                -----------------

  - "w+" : write+ mode
  1)  dosya varsa budanır(truncate), yoksa oluşturulur.
  2)  dosyadan okuma işlemi yapılabilir.
      dosyaya yazma işlemi yapılabilir.

                -----------------

  - "a"  : append(sona ekleme) mode   
  1)  dosya varsa (budanmadan) açılır, yoksa oluşturulur.
  2)  dosyadan okuma işlemi yapılamaz.
      dosyaya sadece sondan ekleme yoluyla yazma işlemi yapılabilir.

                -----------------

  - "a+" : append+ mode
  1)  dosya varsa (budanmadan) açılır, yoksa oluşturulur.
  2)  dosyadan okuma işlemi yapılabilir.
      dosyaya sadece sondan ekleme yoluyla yazma işlemi yapılabilir.

                -----------------

  - text mode   : dosyanın text modunda açılacağını belirtir.
    (r, w, a, r+, w+, a+)

  - binary mode : dosyanın binary modunda açılacağını belirtir.
    (rb, wb, ab, rb+, wb+, ab+) 
    (r+b, w+b, a+b) also valid.

                -----------------
                
  ------------------------------------------
*/

/*
  dosya açma işleminin başarılı olma garantisi yoktur.
  örneğin;
    - dosya yoksa okuma("r") modunda açılamaz.
    - dosya yazma modunda açılmak isteniliyor fakat sistemin 
      belli sayıda dosya açma izni var ve bu sayıya ulaşıldı
      ise dosya açılamaz.
    - dosya işlemleri yapılırken dinamik bellek tahsisi yapılıyorsa
      ve bellek yetersiz ise dosya açılamaz.
*/

/*
  #include <stdio.h>  // fopen, fclose

  int main(void)
  {
    FILE* f1 = fopen("file1.txt", "r");   // read mode

    if (f1 == NULL){
      printf("file1.txt could not be opened.\n");
      return 1;
    }

    printf("file1.txt is opened.\n");
    fclose(f1);

    // output -> file1.txt could not be opened.
  }
*/

/*
  #include <stdio.h>  // fopen

  int main(void)
  {
    FILE* f1 = fopen("file1.txt", "w");   // write mode

    if (f1 == NULL){
      printf("file1.txt could not be created.\n");
      return 1;
    }
    printf("file1.txt has been created.\n");
    fclose(f1);

    // output -> file1.txt has been created.
  }
*/

/*
  // existing files in directory : main.c, file1.txt
  
  #include <stdio.h>  // fopen

  int main(void)
  {
    FILE* f1 = fopen("file1.txt", "r");   // read mode

    if (f1 == NULL){
      printf("file1.txt could not be opened.\n");
      return 1;
    }

    printf("file1.txt is opened.\n");
    fclose(f1);

    // output -> file1.txt is opened.
  }
*/

/*
  // existing files in directory : main.c

  #include <stdio.h>  // sprintf, fopen, fclose

  int main(void)
  {
    char filename[40];

    for (int i = 0; i < 3; ++i){
      sprintf(filename, "file%02d.txt", i + 1);
      FILE* f = fopen(filename, "w");   // write mode
      fclose(f);
    }
  }

  // files in directory : 
  //  main.c, file01.txt, file02.txt, file03.txt
*/

/*
                    -----------------------
                    | fclose in <stdio.h> |
                    -----------------------
*/

/*
  // fclose function prototype
  int fclose(FILE* file_pointer);

  - returns 0 when succeeds, non-zero when fails.
  - generally fopen is tested but fclose is not tested in code.
*/

/*
  #include <stdio.h>  // fopen, fclose
  #include <stdlib.h> // exit, EXIT_FAILURE
  #include <time.h>   // time

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");   // write mode

    if (f == NULL){
      printf("log.txt could not be created.\n");
      exit(EXIT_FAILURE);
    }

    time_t sec;
    time(&sec);

    fprintf(f, "current time : %s", ctime(&sec));
    fclose(f);
  }

  // log.txt -> 
  //  current time : Sat Nov 30 05:40:15 2024
*/

/*
  // existing files in directory : main.c, log.txt

  #include <stdio.h>  // fopen, fclose
  #include <stdlib.h> // exit, EXIT_FAILURE
  #include <time.h>   // time

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");   // write mode

    if (f == NULL){
      printf("log.txt could not be created.\n");
      exit(EXIT_FAILURE);
    }

    time_t sec;
    time(&sec);

    fprintf(f, "current time : %s", ctime(&sec));
    fclose(f);
  }

  // log.txt -> 
  //  current time : Sat Nov 30 05:42:11 2024

  // log.txt is trucated and new data is written.
*/

/*
  // existing files in directory : main.c, log.txt

  #include <stdio.h>  // fopen, fclose
  #include <stdlib.h> // exit, EXIT_FAILURE
  #include <time.h>   // time

  int main(void)
  {
    FILE* f = fopen("log.txt", "a");   // append mode

    if (f == NULL){
      printf("log.txt could not be opened.\n");
      exit(EXIT_FAILURE);
    }

    time_t sec;
    time(&sec);

    fprintf(f, "current time : %s", ctime(&sec));
    fclose(f);
  }
  
  // log.txt ->
  //  current time : Sat Nov 30 05:42:11 2024
  //  current time : Sat Nov 30 05:43:02 2024
*/

/*
                  --------------------------
                  | fcloseall in <stdio.h> |
                  --------------------------
*/

/*
  // fcloseall function prototype (NON-STANDARD)
  int fcloseall(void);

  - returns the number of closed files.
*/

/*
  #include <stdio.h>  // fcloseall(non-standard)

  int main(void)
  {
    char filename[40];

    for (int i = 0; i < 3; ++i){
      sprintf(filename, "file%02d.txt", i + 1);
      FILE* f = fopen(filename, "w");   // write mode
    }

    int N = fcloseall();
    printf("closed file count = %d\n", N);
    // output -> closed file count = 3
  }
  // files in directory : 
  //  main.c, file01.txt, file02.txt, file03.txt
*/

/*
                      ----------------------
                      | fgetc in <stdio.h> |
                      ----------------------
*/

/*
  // fgets function prototype
  int fgetc(FILE* file_pointer);

  - returns character's ASCII value when succeeds.
  - returns EOF(End of File) when fails.

  #define   EOF   (-1)
*/

/*
  #include <stdio.h>  // fopen, fgetc, putchar, EOF

  int main(void)
  {
    FILE* f = fopen("../headers/date.h", "r");   // read mode

    if (f == NULL){
      printf("date.h could not be opened.\n");
      return 1;
    }

    int ch;
    while ((ch = fgetc(f)) != EOF)
      putchar(ch);
    
    fclose(f);
  }
*/

/*
  #include <stdio.h>  // fopen, fgetc, putchar, EOF

  int main(void)
  {
    FILE* f = fopen("../headers/date.h", "r");   // read mode

    if (f == NULL){
      printf("date.h could not be opened.\n");
      return 1;
    }

    fclose(f);
    fclose(f);    // undefined behaviour (UB)

    // because of "fclose(f)" already been invoked. 
    // f(pointer to a structure) becomes a dangling pointer.
    // passing "f" to `fclose` function for the second time 
    // is undefined behaviour(UB).
  }
*/

/*
  #include <stdio.h>  // printf, fopen, fgetc, putchar
  #include <stdlib.h> // exit, EXIT_FAILURE

  int main(int argc, char** argv)
  {
    if (argc != 2){
      printf("usage: %s <filename>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    FILE* f = fopen(argv[1], "r");   // read mode

    if (f == NULL){
      printf("%s could not be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(f)) != EOF)
      putchar(ch);

    fclose(f);
  }

  // command line -> prog.exe command.bat
  // output -> 
  //  @echo off
  //  cls
  //  gcc -Wall -Wextra -Wpedantic -Wconversion -o prog ^
  //  main.c ../src/date.c ../src/nutility.c -std=c23
  //  
  //  if %errorlevel% neq 0 (
  //      echo Compilation failed.
  //      exit /b %errorlevel%
  //  )
  //  REM  prog.exe
  //  REM  del prog.exe
*/

/*
  // counting characters in a file

  #include <stdlib.h> // exit, EXIT_FAILURE
  #include <stdio.h>  // printf, fopen, fgetc

  int main(int argc, char** argv)
  {
    if (argc != 3){
      printf("usage: %s <filename> <character>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    FILE* f = fopen(argv[1], "r");   // read mode
    if (f == NULL){
      printf("%s could not be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    int ch;
    int key = *argv[2];
    int count = 0;

    while ((ch = fgetc(f)) != EOF)
      if (ch == key)
        ++count;
    
    fclose(f);
    printf("'%c' character count in %s : %d\n", key, argv[1], count);
  }

  // command line -> prog.exe command.bat a
  // output -> 'a' character count in command.bat : 7
*/

/*
  // counting alphabet characters in a file

  #include <stdlib.h> // exit, EXIT_FAILURE
  #include <stdio.h>  // printf, fopen, fgetc
  #include <ctype.h>  // isalpha, isupper

  #define  ALPHABET_SIZE  26

  int main(int argc, char** argv)
  {
    if (argc != 2){
      printf("usage: %s <filename>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    FILE* f = fopen(argv[1], "r");   // read mode
    if (f == NULL){
      printf("%s could not be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    int alp_count[ALPHABET_SIZE] = { 0 };
    int ch;

    while ((ch = fgetc(f)) != EOF)
      if (isalpha(ch))
        ++alp_count[toupper(ch) - 'A'];

    fclose(f);

    for (int i = 0; i < ALPHABET_SIZE; ++i){
      printf("'%c' character count in %s : %d\n", 'A' + i, 
                                                  argv[1], 
                                                  alp_count[i]);
    }
  }

  // command line -> prog.exe command.bat
  // output -> 
  //  'A' character count in command.bat : 7
  //  'B' character count in command.bat : 1
  //  'C' character count in command.bat : 12
  //  'D' character count in command.bat : 5
  //  'E' character count in command.bat : 22
  //  'F' character count in command.bat : 4
  //  'G' character count in command.bat : 4
  //  'H' character count in command.bat : 2
  //  'I' character count in command.bat : 10
  //  'J' character count in command.bat : 0
  //  'K' character count in command.bat : 0
  //  'L' character count in command.bat : 11
  //  'M' character count in command.bat : 4
  //  'N' character count in command.bat : 7
  //  'O' character count in command.bat : 13
  //  'P' character count in command.bat : 5
  //  'Q' character count in command.bat : 1
  //  'R' character count in command.bat : 13
  //  'S' character count in command.bat : 3
  //  'T' character count in command.bat : 8
  //  'U' character count in command.bat : 1
  //  'V' character count in command.bat : 3
  //  'W' character count in command.bat : 4
  //  'X' character count in command.bat : 4
  //  'Y' character count in command.bat : 1
  //  'Z' character count in command.bat : 0
*/

/*
  // counting alphabet characters in a file from DESC order

  #include <stdlib.h> // exit, EXIT_FAILURE, qsort
  #include <stdio.h>  // printf, fopen, fgetc
  #include <ctype.h>  // isalpha, isupper

  #define  ALPHABET_SIZE  26

  typedef struct {
    int m_ch;     // character's code
    int m_count;  // character's total count
  } Data_t;

  int data_compare(const void* vp1, const void* vp2)
  {
    int x = ((const Data_t*)vp1)->m_count;
    int y = ((const Data_t*)vp2)->m_count;

    return (x < y) - (x > y);
  }

  int main(int argc, char** argv)
  {
    if (argc != 2){
      printf("usage: %s <filename>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    FILE* f = fopen(argv[1], "r");   // read mode
    if (f == NULL){
      printf("%s could not be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    Data_t data_arr[ALPHABET_SIZE] = {
      { 'A', 0 }, { 'B', 0 }, { 'C', 0 }, { 'D', 0 }, { 'E', 0 }, 
      { 'F', 0 }, { 'G', 0 }, { 'H', 0 }, { 'I', 0 }, { 'J', 0 }, 
      { 'K', 0 }, { 'L', 0 }, { 'M', 0 }, { 'N', 0 }, { 'O', 0 }, 
      { 'P', 0 }, { 'Q', 0 }, { 'R', 0 }, { 'S', 0 }, { 'T', 0 }, 
      { 'U', 0 }, { 'V', 0 }, { 'W', 0 }, { 'X', 0 }, { 'Y', 0 }, 
      { 'Z', 0 }
    };

    int ch;
    while ((ch = fgetc(f)) != EOF){
      if (isalpha(ch))
        ++data_arr[toupper(ch) - 'A'].m_count;
    }

    fclose(f);

    qsort(data_arr, ALPHABET_SIZE, sizeof(Data_t), &data_compare );

    for (int i = 0; i < ALPHABET_SIZE; ++i)
      printf("{ '%c', %2d }\n",  data_arr[i].m_ch, 
                                data_arr[i].m_count);

    // command line -> prog.exe command.bat
    // output ->
    //  { 'E', 22 }
    //  { 'R', 13 }
    //  { 'O', 13 }
    //  { 'C', 12 }
    //  { 'L', 11 }
    //  { 'I', 10 }
    //  { 'T',  8 }
    //  { 'A',  7 }
    //  { 'N',  7 }
    //  { 'P',  5 }
    //  { 'D',  5 }
    //  { 'M',  4 }
    //  { 'G',  4 }
    //  { 'F',  4 }
    //  { 'W',  4 }
    //  { 'X',  4 }
    //  { 'V',  3 }
    //  { 'S',  3 }
    //  { 'H',  2 }
    //  { 'U',  1 }
    //  { 'B',  1 }
    //  { 'Q',  1 }
    //  { 'Y',  1 }
    //  { 'J',  0 }
    //  { 'K',  0 }
    //  { 'Z',  0 }
  }
*/

/*
                      ----------------------
                      | fputc in <stdio.h> |
                      ----------------------
*/

/*
  // fputc function prototype
  int fputc(int character, FILE* file_pointer);
*/

/*
  #include <stdio.h>  // fopen, fputc, fclose
  #include <stdlib.h> // exit, EXIT_FAILURE

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");   // write mode
    if (f == NULL){
      printf("log.txt could not be created.\n");
      exit(EXIT_FAILURE);
    }

    fputc('A', f);
    fputc('B', f);
    fputc('C', f);

    fclose(f);
  }
  // log.txt -> ABC
*/

/*
  #include <stdio.h>  // fopen, fputc, fclose
  #include <stdlib.h> // exit, EXIT_FAILURE

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");   // write mode
    if (f == NULL){
      printf("log.txt could not be created.\n");
      exit(EXIT_FAILURE);
    }

    for (int i = 'A'; i <= 'Z'; ++i)
      fputc(i, f);
    fputc('\n', f);

    for (int i = 'a'; i <= 'z'; ++i)
      fputc(i, f);
    fputc('\n', f);

    for (int i = '0'; i <= '9'; ++i)
      fputc(i, f);
    fputc('\n', f);
    
    fclose(f);
  }

  // log.txt ->
  //  ABCDEFGHIJKLMNOPQRSTUVWXYZ
  //  abcdefghijklmnopqrstuvwxyz
  //  0123456789
*/

/*
  // generate a file with random characters

  #include <stdlib.h> // exit, EXIT_FAILURE, rand, srand
  #include <stdio.h>  // fopen, printf, fputc
  #include <ctype.h>  // isalnum
  #include "../headers/nutility.h"

  int get_random_char(void)
  {
    int ch;
    while (!isalnum(ch = rand() % 128))
      ;

    return ch;
  }

  int main(int argc, char** argv)
  {
    if (argc != 5){
      printf("usage: %s <filename> <line> <min> <max>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    int line_count = atoi(argv[2]);
    int min_line_len = atoi(argv[3]);
    int max_line_len = atoi(argv[4]);

    FILE* f = fopen(argv[1], "w");   // write mode
    if (f == NULL){
      printf("%s could not be created.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    randomize();

    for (int i = 0; i < line_count; ++i){
      int line_len = rand() % (max_line_len - min_line_len + 1) + 
                                                    min_line_len;

      while (line_len--){
        fputc(get_random_char(), f);
      }
      fputc('\n', f);
    }

    fclose(f);
  }

  // command line -> prog.exe log.txt 20 30 40
  // log.txt ->
  //  DTrcxJ3YvdwiUbxfibkud8lekvcZt7c
  //  QLV3KIzxTOOChRJhp1uqLxSVbT3Or6bx3m7LTS0
  //  K5dZChE2y21WwoBGJuRvpRpQ68YhxrgWNGBo
  //  q1JJSF2PHz96klmwnD3ybtArP2J7d0Zty
  //  UvJTWdoZtjM0UPTUh8eFLdHmfVXnp0h
  //  WjTfAWC0fqmcvtGXvYrhvhXpcsexSjJ3QA7
  //  Aq2TgTUsNRQBSPo5pL4wKWOHHPpVbmSxn
  //  y1M5S6cfB9hd2UoCH4gVJcHywhfDwXWnHf
  //  f6KH3z1NYkGribmwKu7xKFEeKmv8enb
  //  3KTyY4UblPAYndi0k2RUuSMHxn8NB9vHsF9OCW
  //  Le9lRK8d7xM6oSX4dfBccl7mq6flKxj
  //  5ObnF5phyI145RPQTdZ6Zxq95yybdWsd2tY
  //  eTXQJOFbIiWQHBcA8ouXd4fCUsfpYR7mkEvyX8
  //  L5dMq2PXDok1GmPL9nFFOarrf1JBgcCbIs
  //  PxJ5EIlVZ8M21QXoDIXBrsXEqgwduGMa
  //  rUMkbvuqvnjEWdNDeWmSARMQpjn1cqCyyEAygd2t
  //  pismbsIXMpaQyO4lHxz6ZD3Qdqfhr2ICDYEu
  //  t9rImUfHOBJYwjmvcO8hm7SLuBJYcRPodQjODx
  //  cJR0BeKh2qf8sGmGe6LcbzgTdGe0fspw84i9RZV4
  //  JgabFmnMYooWZLwBVJlQJQIn3SUyjP
*/

/*
                    ------------------------
                    | text and binary mode |
                    ------------------------
*/

/*
  - dosyayı text modunda açmak, dosyanın içeriğinin text ile
    alakalı olduğunu belirtir.
  - dosyaya binary modunda açmak, dosyanın içeriğinin text ile
    alakalı olmadığını belirtir.
    yazıların karakterleri ile alakalı anlam taşımayan dosyalara
    binary dosya denir.
*/

/*
  - differences between text and binary mode in windowsOS

    1) '\n' -> 10 in ASCII
      when a file is opened in text mode, 
      10 will be replaced with 13 10 (CR NL).

      when a file is opened in binary mode,
      10 will be written as 10 in the file.

    2) ctrl z -> 26 in ASCII
      when a file is opened in text mode, 
      ctrl z(26) will be considered as EOF.

      when a file is opened in binary mode,
      ctrl z(26) will be read as ctrl z(26).
*/

/*
  #include <stdio.h>  // fopen, fputc
  #include <stdlib.h> // exit, EXIT_FAILURE

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");   // write-text mode

    if (f == NULL){
      printf("log.txt could not be created.\n");
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 100; ++i)
      fputc('\n', f);

    fclose(f);

    // size of log.txt -> 200 bytes
    // because of '\n' -> 13 10 (CR NL)
  }
*/

/*
  #include <stdio.h>  // fopen, fputc
  #include <stdlib.h> // exit, EXIT_FAILURE

  int main(void)
  {
    FILE* f = fopen("log.txt", "wb");   // write-binary mode

    if (f == NULL){
      printf("log.txt could not be created.\n");
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 100; ++i)
      fputc('\n', f);

    fclose(f);

    // size of log.txt -> 100 bytes
    // because of '\n' -> 10
  }
*/

/*
  #include <stdio.h>  // fopen, fputc, fgetc, fclose
  #include <stdlib.h> // exit, EXIT_FAILURE

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");   // write-text mode

    if (f == NULL){
      printf("log.txt could not be created.\n");
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; ++i)
      fputc('\n', f);

    fclose(f);

    // -------------------------------------------------  

    f = fopen("log.txt", "r");   // read-text mode

    int ch;
    while ((ch = fgetc(f)) != EOF)
      printf("%d ", ch);
    // output -> 10 10 10 10 10

    // writing in text mode, 
    // ('\n') will be written as (13 10)
    // when reading in text mode,
    // (13 10) will be read as (10)

    fclose(f);
    putchar('\n');

    // -------------------------------------------------  
    
    f = fopen("log.txt", "rb");   // read-binary mode

    while ((ch = fgetc(f)) != EOF)
      printf("%d ", ch);
    fclose(f);

    // output -> 13 10 13 10 13 10 13 10 13 10

    // writing in text mode,
    // ('\n') will be written as (13 10)
    // when reading in binary mode,
    // (13 10) will be read as (13 10) NOT (10)

    // -------------------------------------------------  
  }
*/

/*
  #include <stdio.h>  // fopen, fputc, fgetc, fclose, putchar
  #include <stdlib.h> // exit, EXIT_FAILURE

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");   // write-text mode

    if (f == NULL){
      printf("log.txt could not be created.\n");
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; ++i)
      fputc(65, f);

    fputc(26, f);

    for (int i = 0; i < 5; ++i)
      fputc(66, f);

    // size of log.txt -> 11 bytes
    fclose(f);

    // -------------------------------------------------

    f = fopen("log.txt", "r");   // read-text mode

    int ch;
    while ((ch = fgetc(f)) != EOF)
      printf("%d ", ch);

    // output -> 65 65 65 65 65

    // when reading in text mode,
    // ctrl z(26) will be considered as EOF.

    putchar('\n');
    fclose(f);

    // -------------------------------------------------

    f = fopen("log.txt", "rb");   // read-binary mode

    while ((ch = fgetc(f)) != EOF)
      printf("%d ", ch);

    // output -> 65 65 65 65 65 26 66 66 66 66 66

    // when reading in binary mode,
    // ctrl z(26) will be read as ctrl z(26).
    
    fclose(f);

    // -------------------------------------------------
  }
*/

/*
  // program to copy a file

  #include <stdio.h>    // fopen, fclose, fgetc, fputc
  #include <stdlib.h>   // exit, EXIT_FAILURE

  int main(int argc, char** argv)
  {
    if (argc != 3){
      printf("usage: %s <source> <destination>\n", argv[0]);
      return 1;
    }

    FILE* f_src = fopen(argv[1], "rb");

    if (f_src == NULL){
      printf("%s could not be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    FILE* f_dst = fopen(argv[2], "wb");

    if (f_dst == NULL){
      printf("%s could not be created.\n", argv[2]);
      fclose(f_src);
      exit(EXIT_FAILURE);
    }

    int ch;
    int byte_count;
    while ((ch = fgetc(f_src)) != EOF){
      fputc(ch, f_dst);
      ++byte_count;
    }
    
    fclose(f_src);
    fclose(f_dst);

    printf("%d bytes copied from %s to %s\n", byte_count,
                                              argv[1], 
                                              argv[2]);
  }
  // command line -> prog.exe command.bat test.bat
  // output ->  227 bytes copied from command.bat to test.bat

  // command line -> prog.exe prog.exe test.exe
  // output ->  91111 bytes copied from prog.exe to test.exe
*/

/*
  // splitting a file into smaller files

  #include <stdio.h>    
  // fopen, fclose, fcloseall, fgetc, fputc, sprintf
  #include <stdlib.h>   // exit, EXIT_FAILURE, atoi

  #define   FILENAME_LEN   100

  int main(int argc, char** argv)
  {
    if (argc != 3){
      printf("usage: %s <source> <bytes>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    FILE* f_src = fopen(argv[1], "rb");

    if (f_src == NULL){
      printf("%s could not be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    int chunk_size = atoi(argv[2]);
    int file_count = 0;
    char dest_filename[FILENAME_LEN];

    int ch;
    int byte_count = 0;
    FILE* f_dst = NULL;

    while ((ch = fgetc(f_src)) != EOF){
      if (f_dst == NULL){
        sprintf(dest_filename, "part%02d.txt", ++file_count);
        f_dst = fopen(dest_filename, "wb");

        if (f_dst == NULL){
          printf("%s could not be created.\n", dest_filename);
          fcloseall();
          exit(EXIT_FAILURE);
        }
      }

      fputc(ch, f_dst);
      ++byte_count;

      if (byte_count % chunk_size == 0){
        fclose(f_dst);
        f_dst = NULL;
      }
    }

    fclose(f_src);
    if (f_dst != NULL)
      fclose(f_dst);

    printf("%d byte %s file splitted to %d files, each %d bytes.\n", 
      byte_count, argv[1], file_count, chunk_size);                                         
  }

  // command line -> prog.exe main.c 1000
  // output -> 
  //  26582 byte main.c file splitted to 27 files, each 1000 bytes.
*/

/*
                    -----------------------
                    | remove in <stdio.h> |
                    -----------------------
*/

/*
  // remove function prototype
  int remove(const char* filename);

  - deletes the file with the given name.
  - returns 0 when succeeds, non-zero when fails.
*/

/*
  #include <stdio.h>  // remove, printf, sprintf
  #include <stdlib.h> // exit, EXIT_FAILURE

  #define  FILENAME_LEN   100

  int main(void)
  {
    char filename[FILENAME_LEN];

    for (int i = 1; i <= 27; ++i){
      sprintf(filename, "part%02d.txt", i);

      if (remove(filename) == 0)
        printf("%s is deleted.\n", filename);
      else {
        printf("%s could not be deleted.\n", filename);
        exit(EXIT_FAILURE);
      }
    }
    // output ->
    //  part01.txt is deleted.
    //  part02.txt is deleted.
    //  part03.txt is deleted.
    //  part04.txt is deleted.
    //  part05.txt is deleted.
    //  part06.txt is deleted.
    //  part07.txt is deleted.
    //  part08.txt is deleted.
    //  part09.txt is deleted.
    //  part10.txt is deleted.
    //  part11.txt is deleted.
    //  part12.txt is deleted.
    //  part13.txt is deleted.
    //  part14.txt is deleted.
    //  part15.txt is deleted.
    //  part16.txt is deleted.
    //  part17.txt is deleted.
    //  part18.txt is deleted.
    //  part19.txt is deleted.
    //  part20.txt is deleted.
    //  part21.txt is deleted.
    //  part22.txt is deleted.
    //  part23.txt is deleted.
    //  part24.txt is deleted.
    //  part25.txt is deleted.
    //  part26.txt is deleted.
    //  part27.txt is deleted.
  }
*/

// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------

/*
  // merging smaller files into a single file

  #include <stdio.h>  
  // fopen, fputc, fgetc, fclose, printf, sprintf, remove
  #include <stdlib.h> // exit, EXIT_FAILURE

  #define   FILENAME_LEN  100

  int main(int argc, char** argv)
  {
    if (argc != 2){
      printf("usage: %s <destination>\n", argv[0]);
      return 1;
    }

    FILE* f_dst = fopen(argv[1], "wb");

    if (f_dst == NULL){
      printf("%s could not be created.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    char source_filename[FILENAME_LEN];

    int file_count = 0;
    int byte_count = 0;
    
    FILE* f_src = NULL;
    while(1){
      sprintf(source_filename, "part%02d.txt", file_count + 1);
      f_src = fopen(source_filename, "rb");

      if (f_src == NULL)
        break;

      ++file_count;

      int ch;
      while ((ch = fgetc(f_src)) != EOF){
        fputc(ch, f_dst);
        ++byte_count;
      }

      fclose(f_src);
    }

    fclose(f_dst);
    printf("%d files merged to total %d bytes %s file\n", 
      file_count, byte_count, argv[1]);

    for (int i = 1; i <= file_count; ++i){
      sprintf(source_filename, "part%02d.txt", i);

      if (remove(source_filename) == 0)
        printf("%s is deleted.\n", source_filename);
      else {
        printf("%s could not be deleted.\n", source_filename);
        exit(EXIT_FAILURE);
      }
    }
  }

  // command line -> prog.exe split.exe
  // output ->
  //  5 files merged to total 91835 bytes split.exe file
  //  part01.txt is deleted.
  //  part02.txt is deleted.
  //  part03.txt is deleted.
  //  part04.txt is deleted.
  //  part05.txt is deleted.

  // command line -> split.exe 
  // output -> usage: split.exe <source> <bytes>
*/

/*
                    -----------------------
                    | rename in <stdio.h> |
                    -----------------------
*/

/*
  // rename function prototype
  int rename(const char* old_filename, const char* new_filename);

  - renames the file with the given name.
  - returns 0 when succeeds, non-zero when fails.
*/

/*
  #include <stdio.h>  // rename, printf

  int main(int argc, char** argv)
  {
    if (argc != 3){
      printf("usage: %s <source> <destination>\n", argv[0]);
      return 1;
    }

    if (rename(argv[1], argv[2]) == 0)
      printf("%s is renamed as %s.\n", argv[1], argv[2]);
    else
      printf("%s could not be renamed as %s.\n", argv[1], argv[2]);
  }

  // command line -> prog.exe command.bat cli.bat
  // output -> command.bat is renamed as cli.bat
*/

/*
                    -----------------------
                    | tmpnam in <stdio.h> |
                    -----------------------
*/

/*
  - unique file name generator function

  // tmpnam function prototype
  char* tmpnam(char* buffer);

  - if buffer (char array address) passed to the function, 
    function will write the unique file name to the buffer.

  - if NULL passed to the function, function will 
    allocate memory for the buffer and returns
    static storage duration char array address

  char filename[L_tmpnam]; 
  - L_tmpname macro guarantees that the buffer is large enough 
    to hold the unique file name.
*/

/*
  #include <stdio.h>  // tmpnam, L_tmpnam

  int main(void)
  {
    char filename[L_tmpnam];
    printf("unique file name : %s\n", tmpnam(filename));
    // output -> unique file name : s850.0
  }
*/

// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------

/*
  // encrypting a file

  #include <stdio.h>  
  // fopen, fclose, L_tmpnam, tmpnam, fgetc, fputc
  #include <stdlib.h> 
  // atoll, exit, EXIT_FAILURE, srand, rand

  int main(int argc, char** argv)
  {
    if (argc != 3){
      printf("usage: %s <source_file> <seed>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    FILE* f_src = fopen(argv[1], "rb");
    if (f_src == NULL){
      printf("%s could not be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    char dest_filename[L_tmpnam];
    tmpnam(dest_filename);

    FILE* f_dst = fopen(dest_filename, "wb");  
    if (f_dst == NULL){
      printf("%s temp file could not be created.\n", dest_filename);
      fclose(f_src);
      exit(EXIT_FAILURE);
    }

    long long seed = atoll(argv[2]);
    srand((unsigned)seed);

    int ch;
    while ((ch = fgetc(f_src)) != EOF)
      fputc(ch ^ rand(), f_dst);

    fclose(f_src);
    fclose(f_dst);

    if (remove(argv[1])){
      printf("%s could not be deleted.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    if (rename(dest_filename, argv[1])){
      printf("%s file could not be renamed\n", dest_filename);
      exit(EXIT_FAILURE);
    }
  }

  // command line -> prog.exe command.bat 123456
  // command line -> command.bat 
  // output -> 
  //  'í' is not recognized as an internal or 
  //  external command, operable program or batch file.
  // command line -> prog.exe command.bat 123456
  // command line -> command.bat (VALID)
*/

// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------
// --------------------------------------------------------

/*
  - formatted output : 
    * printf, fprintf, sprintf, snprintf
  - formatted input : 
    * scanf, fscanf, sscanf
  
  - non-formatted input/output : 
    * fgetc, fputc
*/

/*
                --------------------------------
                | fprintf, fscanf in <stdio.h> |
                --------------------------------
*/

/*
  // fprintf function prototype
  int fprintf(FILE* file_pointer, const char* format, ...);

  - returns the number of characters written to the file.

  ---------------------------------------------------------

  // fscanf function prototype
  int fscanf(FILE* file_pointer, const char* format, ...);

  - returns the number of items read from the file.
*/

/*
  #include <stdio.h>

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");

    if (f == NULL){
      printf("log.txt could not be created.\n");
      return 1;
    }

    fprintf(f, "%d %f %c %s\n", 123, 3.14, 'A', "hello");
    // log.txt -> 123 3.140000 A hello

    fclose(f);
  }
*/

/*
  #include <stdio.h>    // fopen, fprintf, fclose
  #include <stdlib.h>   // rand
  #include "../headers/nutility.h"

  int main(void)
  {
    FILE* f = fopen("records.txt", "w");

    if (f == NULL){
      printf("records.txt could not be created.\n");
      return 1;
    }

    randomize();

    for (int i = 0; i < 10000; ++i)
      fprintf(f, "%-12d %-16s %-18s %d\n",  
        rand(), 
        get_random_name(),
        get_random_surname(),
        rand() % 101);

    // records.txt ->
    //  12842        nahit            damar              67
    //  6246         emrecan          uraz               90
    //  32322        emrecan          keskin             97
    //  10080        sevilay          esbereli           73
    //  ...
    
    fclose(f);
  }
*/

/*
  #include <stdio.h>    
  // fopen, fclose, printf, fputc, fprintf
  #include "../headers/nutility.h"  

  int main(void)
  {
    FILE* f = fopen("primes.txt", "w");

    if (f == NULL){
      printf("primes.txt could not be created.\n");
      return 1;
    }

    int x = 2;
    int prime_count = 0;

    while (prime_count < 100000){
      if (is_prime(x)){
        if (prime_count && prime_count % 5 == 0)
          fputc('\n', f);

        fprintf(f, "%12d ", x);
        ++prime_count;
      }
      ++x;
    }

    fclose(f);

    // primes.txt ->
    //   2            3            5            7           11 
    //  13           17           19           23           29 
    //  31           37           41           43           47 
    //  53           59           61           67           71 
    //  73           79           83           89           97 
    //  ...
  }
*/

/*
  #include <stdio.h>  // fopen, fscanf, fclose, EOF

  #define   STR_SIZE  100

  int main(void)
  {
    FILE* f = fopen("run.bat", "r");   // read-text mode
    if (f == NULL){
      printf("run.bat could not be opened.\n");
      return 1;
    }

    char str[STR_SIZE];

    while (fscanf(f, "%s", str) != EOF)
      printf("%s\n", str);

    fclose(f);
    // output ->
    //  @echo
    //  off
    //  cls
    //  gcc
    //  -Wall
    //  -Wextra
    //  -Wpedantic
    //  -Wconversion
    //  -o
    //  prog
    //  ^
    //  main.c
    //  ../src/date.c
    //  ../src/nutility.c
    //  -std=c23
    //  if
    //  %errorlevel%
    //  neq
    //  0
    //  (
    //  echo
    //  Compilation
    //  failed.
    //  exit
    //  /b
    //  %errorlevel%
    //  )
    //  prog.exe
    //  del
    //  prog.exe
  }
*/

/*
  #include <stdio.h>  // fopen, fscanf, fclose, EOF

  #define   STR_SIZE  100

  int main(void)
  {
    FILE* f = fopen("records.txt", "r");   // read-text mode
    if (f == NULL){
      printf("records.txt could not be opened.\n");
      return 1;
    }

    int NO;
    char s1[STR_SIZE];
    char s2[STR_SIZE];
    int grade;

    while (fscanf(f, "%d%s%s%d", &NO, s1, s2, &grade) != EOF)
      printf("%-8d %-12s %-16s %d\n", NO, s1, s2, grade);
    // output ->
    //  ...
    //  13386    ziya         beyaz            92
    //  14099    cihat        yasmak           64
    //  27614    atil         terlemez         5
    //  23074    candan       lokmaci          68
    //  24463    beril        tombeki          22
    //  13402    pakize       cankoc           96
  }
*/

/*
  #include <stdio.h>  // fopen, fscanf, fclose, EOF

  #define   STR_SIZE  100

  int main(void)
  {
    FILE* f = fopen("records.txt", "r");   // read-text mode
    if (f == NULL){
      printf("records.txt could not be opened.\n");
      return 1;
    }

    int NO;
    char s1[STR_SIZE];
    char s2[STR_SIZE];
    int grade;

    while (fscanf(f, "%d%s%s%d", &NO, s1, s2, &grade) != EOF)
      if (grade == 66)
        printf("%-8d %-12s %-16s %d\n", NO, s1, s2, grade);
      
    // output ->
    //  29793    tansu        yilmaz           66
    //  15806    abdi         supuren          66
    //  2946     tufan        tekinalp         66
    //  13592    tevfik       yaygara          66
    //  10528    okan         azmak            66
    //  ...
  }
*/

/*
  #include <stdio.h>  // fopen, fscanf, fclose, EOF
  #include <string.h> // strcmp

  #define   STR_SIZE  100

  int main(void)
  {
    FILE* f = fopen("records.txt", "r");   // read-text mode
    if (f == NULL){
      printf("records.txt could not be opened.\n");
      return 1;
    }

    int NO;
    char s1[STR_SIZE];
    char s2[STR_SIZE];
    int grade;

    char searched_str[STR_SIZE] = "yilmaz";

    while (fscanf(f, "%d%s%s%d", &NO, s1, s2, &grade) != EOF)
      if (!strcmp(s1, searched_str))
        printf("%-8d %-12s %-16s %d\n", NO, s1, s2, grade);
      
    // output ->
    //  6200     yilmaz       savaskan         91
    //  30646    yilmaz       konca            33
    //  14644    yilmaz       kolcak           59
    //  24486    yilmaz       malazgirt        76
    //  ...
  }
*/

/*
  // will create files with the following content
  // grades0.txt, grades1.txt, grades2.txt, ... , grades100.txt 

  // in Operating Systems there might be some restrictions
  // on the number of files that can be opened simultaneously.

  #include <stdio.h>  
  // fopen, fclose, sprintf, fscanf, fprintf, printf

  #define   FILE_COUNT    101
  #define   FILENAME_LEN  100

  int main(void)
  {
    FILE* f_arr[FILE_COUNT];
    char filename[FILENAME_LEN];

    for (int i = 0; i < FILE_COUNT; ++i)
    {
      sprintf(filename, "grades%d.txt", i);

      f_arr[i] = fopen(filename, "w");
      if (f_arr[i] == NULL){
        printf("%s could not be created.\n", filename);
        return 1;
      }
    }

    FILE* f_src = fopen("records.txt", "r");
    if (f_src == NULL){
      printf("records.txt could not be opened.\n");
      return 1;
    }

    char no[40];
    char name[40];
    char surname[40];
    int grade;

    while (fscanf(f_src, "%s%s%s%d", no, name, surname, &grade) != EOF)
    {
      fprintf(f_arr[grade], "%-5s %-12s %-16s %d\n", 
                no, name, surname, grade);
    }

    fclose(f_src);

    for (int i = 0; i < FILE_COUNT; ++i)
      fclose(f_arr[i]);

  }
    // grades0.txt ->
    //  18118 yurdagul     kapici           0
    //  23546 ziya         efelik           0
    //  3345  asim         elibol           0
    //  24302 nevsin       soylu            0
    //  ...

    // grades33.txt ->
    //  348   hakan        uraz             33
    //  30862 emrecan      erim             33
    //  24692 emirhan      alemdar          33
    //  4707  gurbuz       ozvezneci        33
    //  ...

    // grades100.txt ->
    //  30577 niyazi       karasaban        100
    //  26580 tarkan       dumbuk           100
    //  14983 feramuz      demirdogen       100
    //  13019 kayhan       yanardag         100
    //  9264  kerem        ecevit           100
    // ...
*/

/*
            ------------------------------------
            | reading line by line from a file |
            ------------------------------------
*/

/*
                    ----------------------
                    | fgets in <stdio.h> |
                    ----------------------
*/

/*
  // fgets function prototype
  char* fgets(char* buffer, int size, FILE* file_pointer);

  - buffer : address of the buffer where the line will be written.
              guaranteed to be NTBS.
  - size : maximum number of characters to be read.

  - return value is the buffer address if minimum 1 character read, 
    NULL if EOF reached before reading any character.
*/

/*
  #include <stdio.h>    // fopen, fgets, fclose

  #define   BUFFER_SIZE  100

  int main(void)
  {
    char buf[BUFFER_SIZE];

    FILE* f_src = fopen("records.txt", "r");
    if (f_src == NULL){
      printf("records.txt could not be opened.\n");
      return 1;
    }

    while (fgets(buf, BUFFER_SIZE, f_src) != NULL)
      printf("%s", buf);

    fclose(f_src);

    // output ->
    //  ...
    //  14099        cihat            yasmak             64
    //  27614        atil             terlemez           5
    //  23074        candan           lokmaci            68
    //  24463        beril            tombeki            22
    //  13402        pakize           cankoc             96
  }
*/

/*
  #include <stdio.h>  // fopen, fgets, fclose
  #include <string.h> // strchr

  #define   BUFFER_SIZE  100

  int main(void)
  {
    char buf[BUFFER_SIZE];

    FILE* f_src = fopen("records.txt", "r");
    if (f_src == NULL){
      printf("records.txt could not be opened.\n");
      return 1;
    }

    char* p_newline;

    while (fgets(buf, BUFFER_SIZE, f_src) != NULL)
    {
      if ((p_newline = strchr(buf, '\n')) != NULL)
        *p_newline = '\0';

      printf("____%s____\n", buf);
    }

    fclose(f_src);

    // output ->
    //  ...
    //  ____14099        cihat            yasmak             64____
    //  ____27614        atil             terlemez           5____
    //  ____23074        candan           lokmaci            68____
    //  ____24463        beril            tombeki            22____
    //  ____13402        pakize           cankoc             96____
  }
*/

/*
  #include <stdio.h>  // fopen, fgets, fclose
  #include <string.h> // strchr

  #define   BUFFER_SIZE  20

  int main(void)
  {
    char buf[BUFFER_SIZE];

    FILE* f_src = fopen("records.txt", "r");
    if (f_src == NULL){
      printf("records.txt could not be opened.\n");
      return 1;
    }

    while (fgets(buf, BUFFER_SIZE, f_src) != NULL)
      printf("%s/", buf);
    
    fclose(f_src);

    // output ->
    // ...
    //  /3141         alev  /           konak   /           52
    //  /13183        mustaf/a          kelleci /           65
    //  /17273        nageha/n          altinisi/k          15
    //  /29231        anil  /           yorgun  /           94
    //  /17601        saadet/           oltu    /           66
    //  /24264        niyazi/           yurdakul/           61

    // reading max 19 characters from the file
    // and adds '\0' at the end of the buffer.
  }
*/