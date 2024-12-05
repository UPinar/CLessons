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

/*
  // writing lines shorter than 30 characters to the console

  #include <stdio.h>  // fopen, fgets, fclose
  #include <string.h> // strlen

  #define   BUFFER_SIZE  100

  int main(void)
  {
    char buf[BUFFER_SIZE];

    FILE* f_src = fopen("../headers/nutility.h", "r");
    if (f_src == NULL){
      printf("nutility.h could not be opened.\n");
      return 1;
    }

    while (fgets(buf, BUFFER_SIZE, f_src) != NULL)
      if (strlen(buf) < 30)
        printf("%s", buf);
    
    fclose(f_src);

    // output ->
    //  #ifndef   NUTILITY_H
    //  #define   NUTILITY_H
    //  
    //  
    //  extern const int g_primes[];
    //  #define PNAMES_SIZE 335
    //  
    //  
    //  void randomize(void);
    //  void sgets(char* pStr);
    //  void swap(int* x, int* y);
    //  
    //  
    //  
    //  int is_prime(int val);
    //  
    //  
    //  
    //  #endif // NUTILITY_H
  }
*/

/*
                    ----------------------
                    | fputs in <stdio.h> |
                    ----------------------
*/

/*
  // fputs function prototype
  int fputs(const char* str, FILE* file_pointer);

  - returns EOF when fails, 0 when succeeds.
*/

/*
  #include <stdio.h>  // fopen, fputs, fclose

  int main(void)
  {
    FILE* f = fopen("log.txt", "w");
    if (f == NULL){
      printf("log.txt could not be created.\n");
      return 1;
    }

    char str[] = "hello world";

    for (int i = 0; i < 5; ++i){
      fputs(str, f);
      fputs("\n", f);
    }

    fclose(f);

    // output ->
    //  hello world
    //  hello world
    //  hello world
    //  hello world
    //  hello world
  }
*/

/*
  - unformatted input/output functions 
    will write bytes to the file as they are.

  - fwrite, fread unfomatted input/output functions
*/

/*
                ---------------------------------
                | fwrite and fread in <stdio.h> |
                ---------------------------------
*/

/*
  // fwrite function prototype
  size_t fwrite(const void* buffer, 
                size_t      element_size, 
                size_t      element_count,
                FILE*       file_pointer);

  - returns the number of items written to the file.


  // fread function prototype
  size_t fread(void*   buffer, 
               size_t  element_size, 
               size_t  element_count,
               FILE*   file_pointer);

  - returns the number of items read from the file.
*/

/*
  - because of those functions are unformatted 
    IO functions, we need to open the file in binary mode.
*/

/*
  #include <stdio.h>  // fopen
  #include "../headers/nutility.h"

  #define   SIZE    100

  int main(void)
  {
    int primes_count = 100000;

    char filename[SIZE];
    sprintf(filename, "primes%d.dat", primes_count);

    FILE* f_dest = fopen(filename, "wb");
    if (f_dest == NULL){
      printf("%s could not be created.\n", filename);
      return 1;
    }

    int x = 2;
    int count = 0;

    while (count < primes_count){
      if (is_prime(x)){
        fwrite(&x, sizeof(int), 1, f_dest);
        ++count;
      }
      ++x;
    }

    fclose(f_dest);
  }

  // primes100000.dat -> 400'000 bytes
*/

/*
  #include "../headers/person.h"
  #include "../headers/nutility.h"
  #include <stdio.h>  // fopen, fwrite, fclose, sprintf

  #define   SIZE    100

  int main(void)
  {
    int person_count = 10000;

    char filename[SIZE];
    sprintf(filename, "person%d.dat", person_count);

    FILE* f_dest = fopen(filename, "wb");
    if (f_dest == NULL){
      printf("%s could not be created.\n", filename);
      return 1;
    }

    randomize();
    Person_t per;

    while (person_count--){
      person_set_random(&per);
      fwrite(&per, sizeof(Person_t), 1, f_dest);
    } 

    fclose(f_dest);
  }

  // person10000.dat -> 800'000 bytes
*/

/*
  #include <stdio.h>  // fopen, fread, fclose

  int main(void)
  {
    FILE* f_src = fopen("primes100000.dat", "rb");

    if (f_src == NULL){
      printf("primes100000.dat could not be opened.\n");
      return 1;
    }

    int x;

    while (fread(&x, sizeof(int), 1, f_src) == 1)
      printf("%d ", x);

    fclose(f_src);

    // output ->
    //  ... 
    //  1299269 1299283 1299289 1299299 1299317 1299323 1299341
    //  1299343 1299349 1299359 1299367 1299377 1299379 1299437 
    //  1299439 1299449 1299451 1299457 1299491 1299499 1299533
    //  1299541 1299553 1299583 1299601 1299631 1299637 1299647 
    //  1299653 1299673 1299689 1299709
  }
*/

/*
  #include <stdio.h>  // fopen, fread, fclose
  #include "../headers/nutility.h"

  #define   SIZE    12

  int main(void)
  {
    FILE* f_src = fopen("primes100000.dat", "rb");

    if (f_src == NULL){
      printf("primes100000.dat could not be opened.\n");
      return 1;
    }

    int arr[SIZE];

    size_t N;

    while ((N = fread(&arr, sizeof(int), SIZE, f_src)) != 0)
      print_array(arr, N);


    fclose(f_src);

    // output ->
    //  ... 
    //  ---------------------------------------
    //  1299317 1299323 1299341 1299343 1299349 
    //  1299359 1299367 1299377 1299379 1299437
    //  1299439 1299449
    //  ---------------------------------------
    //  1299451 1299457 1299491 1299499 1299533 
    //  1299541 1299553 1299583 1299601 1299631
    //  1299637 1299647
    //  ---------------------------------------
    //  1299653 1299673 1299689 1299709
    //  ---------------------------------------

    // 8333 * 12 = 99996 bytes
    // 100000 - 99996 = 4 bytes (last array will have 4 elements)
  }
*/

/*
  #include <stdio.h>  // fopen, fread, fclose
  #include "../headers/person.h"

  int main(void)
  {
    FILE* f_src = fopen("person1000.dat", "rb");

    if (f_src == NULL){
      printf("primes100000.dat could not be opened.\n");
      return 1;
    }

    Person_t per;

    while (fread(&per, sizeof(Person_t), 1, f_src) != 0)
      person_print(&per);

    fclose(f_src);

    // output ->
    //  ...
    //  26613 abdullah       maganda        02 Eylul 1950 Cumartesi
    //  20149 naci           kucukkaya      09 Agustos 2022 Sali
    //  6003  aynur          kilicdar       09 Mayis 1999 Pazar
    //  10817 cebrail        tercan         02 Eylul 1964 Carsamba
  }
*/

/*
  #include <stdio.h>  // fopen, fread, fclose
  #include "../headers/person.h"

  int main(void)
  {
    FILE* f_src = fopen("person1000000.dat", "rb");

    if (f_src == NULL){
      printf("person1000.dat could not be opened.\n");
      return 1;
    }

    Person_t per;
    int day = 5, month = 12;

    while (fread(&per, sizeof(Person_t), 1, f_src) != 0)
    {
      if (per.m_birth_date.m_day == day && 
          per.m_birth_date.m_month == month)
      {
        person_print(&per);
      }
    }

    fclose(f_src);

    // output ->
    //  ...
    //  3527  arda       takes          05 Aralik 2021 Pazar
    //  10895 gulsah     terlemez       05 Aralik 1975 Cuma
    //  2891  mehmet     kalpsiz        05 Aralik 1985 Persembe
    //  3067  egemen     altinisik      05 Aralik 2000 Sali
    //  26438 ege        merdane        05 Aralik 1979 Carsamba
  }
*/

/*
  #include <stdio.h>  // fopen, fread, fclose
  #include <string.h> // strchr
  #include "../headers/person.h"

  int main(void)
  {
    FILE* f_src = fopen("person1000000.dat", "rb");

    if (f_src == NULL){
      printf("person1000.dat could not be opened.\n");
      return 1;
    }

    Person_t per;
    int ch = 'z';

    while (fread(&per, sizeof(Person_t), 1, f_src) != 0)
    {
      if (per.m_birth_date.m_year > 2010 &&
          strchr(per.m_name, ch) && 
          strchr(per.m_surname, ch))
      {
        person_print(&per);
      }
    }

    fclose(f_src);

    // output ->
    //  ...
    //  14822 yavuz       acgoze         31 Aralik 2022 Cumartesi
    //  26740 muzaffer    kazanci        29 Kasim 2022 Sali
    //  76    azmi        iliksiz        06 Temmuz 2011 Carsamba
    //  18772 cezmi       cangoz         01 Ocak 2012 Pazar
    //  8539  yilmaz      yagizeli       31 Agustos 2020 Pazartesi
  }
*/

/*
  #include <stdio.h>  // fopen, fread, fclose
  #include <string.h> // strstr
  #include "../headers/person.h"

  int main(void)
  {
    FILE* f_src = fopen("person1000000.dat", "rb");

    if (f_src == NULL){
      printf("person1000.dat could not be opened.\n");
      return 1;
    }

    Person_t per;
    char str[20] = { "kan" };

    while (fread(&per, sizeof(Person_t), 1, f_src) != 0)
    {
      if (strstr(per.m_name, str) && 
          strstr(per.m_surname, str))
      {
        person_print(&per);
      }
    }

    fclose(f_src);

    // output ->
    //  ...
    //  6612  atakan      polatkan       31 Ocak 2017 Sali
    //  9217  hakan       yurekyakan     19 Mayis 1990 Cumartesi
    //  6137  tarkan      polatkan       10 Temmuz 2017 Pazartesi
    //  17655 hakan       yavasakan      18 Ekim 1983 Sali
  }
*/

/*
  // copying a file chunk by chunk

  #include <stdio.h>  // fopen, fclose, printf

  #define   CHUNK_SIZE    1024

  int main(int argc, char* argv[])
  {
    if (argc != 3){
      printf("usage: %s <source> <destination>\n", argv[0]);
      return 1;
    }
    
    FILE* f_src = fopen(argv[1], "rb");
    if (f_src == NULL){
      printf("%s could not be opened.\n", argv[1]);
      return 2;
    }

    FILE* f_dst = fopen(argv[2], "wb");
    if (f_dst == NULL){
      printf("%s could not be created.\n", argv[2]);
      fclose(f_src);
      return 3;
    }

    char buffer[CHUNK_SIZE];
    size_t N;
    int byte_count = 0;

    while ((N = fread(buffer, 1, CHUNK_SIZE, f_src)) != 0){
      fwrite(buffer, 1, N, f_dst);
      byte_count += (int)N;
    }

    fclose(f_src);
    fclose(f_dst);

    printf("%d bytes copied from %s to %s\n", byte_count, 
                                              argv[1], 
                                              argv[2]);
  }

  // command line -> prog.exe primes100000.dat abc.dat
  // output -> 400000 bytes copied from primes100000.dat to abc.dat
*/

/*
  #include <string.h> // strcpy, strchr
  #include <stdio.h>  // printf
  #include "../headers/person.h"

  #define   SIZE  100

  void change_extension(char* dest, const char* source)
  {
    strcpy(dest, source);
    char* p = strchr(dest, '.');
    if (p != NULL)
      strcpy(p, ".txt");
  }

  int main(void)
  {
    char src_filename[SIZE] = "person1000000.dat";
    char dest_filename[SIZE];

    change_extension(dest_filename, src_filename);

    FILE* f_src = fopen(src_filename, "rb");  // read-binary mode
    if (f_src == NULL){
      printf("%s could not be opened.\n", src_filename);
      return 1;
    }

    FILE* f_dst = fopen(dest_filename, "w");  // write-text mode
    if (f_dst == NULL){
      printf("%s could not be created.\n", dest_filename);
      fclose(f_src);
      return 2;
    }

    Person_t per;

    while (fread(&per, sizeof(Person_t), 1, f_src) != 0)
      person_print_file(f_dst, &per);
  }
*/

/*
            ---------------------------------------
            | file pointer manipulation functions |
            ---------------------------------------
*/

/*
                    ----------------------
                    | fseek in <stdio.h> |
                    ----------------------
*/

/*
  // fseek function prototype
  int fseek(FILE* file_pointer, long offset, int origin);
*/

/*
  ---------------------------------------------------------

  origin parameter values:
    - SEEK_SET (origin will be the beginning of the file)
    - SEEK_CUR (origin will be current position of file pointer)
    - SEEK_END (origin will be the end of the file)

  ---------------------------------------------------------

  fseek(f, 1000L, SEEK_SET);
    - moves the file pointer to the 1000th byte of the file.
  
  fseek(f, 0L, SEEK_SET);
    - moves the file pointer to the beginning of the file.

  fseek(f, -100L, SEEK_SET);    !!!! WRONG !!!
  if SEEK_SET macro is used, offset must be POSITIVE.

  ---------------------------------------------------------

  fseek(f, 0L, SEEK_END);
    - moves the file pointer to the end of the file.
    - append mode is using this function call.

  fseek(f, -999L, SEEK_END);
    - moves the file pointer to the 999th byte before 
      the end of the file.

  ---------------------------------------------------------

  fseek(f, 0L, SEEK_CUR);
    - moves the file pointer to the current position 
      of the file pointer.

  fseek(f, 100L, SEEK_CUR);
    - moves the file pointer 100 bytes forward from its 
      current position.

  fseek(f, -100L, SEEK_CUR);
    - moves the file pointer 100 bytes backward from its 
      current position.

  ---------------------------------------------------------

  - before reading operation after a write operation
  - before writing operation after a read operation

  file pointer position MUST BE set.
  if not, undefined behavior(UB) will occur.

  ---------------------------------------------------------
*/

/*
                    -----------------------
                    | rewind in <stdio.h> |
                    -----------------------
*/

/*
  // rewind function prototype
  void rewind(FILE* file_pointer);

  - moves the file pointer to the beginning of the file.
  - equivalent to fseek(f, 0L, SEEK_SET);
*/

/*
                    ----------------------
                    | ftell in <stdio.h> |
                    ----------------------
*/

/*
  // ftell function prototype
  long ftell(FILE* file_pointer);

  - returns the current position of the file pointer.
  - returns -1L when failed.
*/

/*
  #include <stdio.h>  // fopen, fclose, fseek, ftell

  int main(void)
  {
    FILE* f_src = fopen("person1000000.dat", "rb");
    if (f_src == NULL){
      printf("person1000000.dat could not be opened.\n");
      return 1;
    }

    fseek(f_src, 0L, SEEK_END);
    printf("%ld\n", ftell(f_src));  // output -> 80000000
    // returns the size of the file in bytes.

    fclose(f_src);
  }
*/

/*
  #include <stdio.h>  // fopen, fclose, fseek, fread, printf

  int main(void)
  {
    FILE* f_src = fopen("primes100000.dat", "rb");
    if (f_src == NULL){
      printf("primes100000.dat could not be opened.\n");
      return 1;
    }

    int N = 44444;
    int x;
    fseek(f_src, ((N - 1) * (long)sizeof(int)), SEEK_SET);
    fread(&x, sizeof(int), 1, f_src);

    printf("%d'th prime number = %d\n", N, x);
    // output -> 44444'th prime number = 538259

    fclose(f_src);
  }
*/

/*
  #include <stdio.h>  // fopen, fclose, fseek, fread, printf
  #include "../headers/person.h"

  int main(void)
  {
    FILE* f_src = fopen("person1000000.dat", "rb");
    if (f_src == NULL){
      printf("primes100000.dat could not be opened.\n");
      return 1;
    }

    int N = 33333;
    Person_t per;

    fseek(f_src, ((N - 1) * (long)sizeof(Person_t)), SEEK_SET);
    fread(&per, sizeof(Person_t), 1, f_src);

    person_print(&per);
    // output -> 17607 sumeyye  engereke   20 Ekim 1956 Cumartesi

    fclose(f_src);
  }
*/

/*
  #include <stdio.h>  // fopen, fclose, fread, printf
  #include <stdlib.h>
  #include "../headers/person.h"

  void print_person_records(const char* filename)
  {
    FILE* f = fopen(filename, "rb");
    if (f == NULL){
      printf("%s could not be opened.\n", filename);
      exit(EXIT_FAILURE);
    }

    Person_t per;

    while (fread(&per, sizeof(Person_t), 1, f) != 0)
      person_print(&per);

    fclose(f);
  }

  int main(void)
  {
    print_person_records("person1000000.dat");

    // output ->
    //  ...
    //  6062  nefes        gilgamis     22 Eylul 1948 Carsamba
    //  25044 billur       temizel      09 Temmuz 1986 Carsamba
    //  24339 tonguc       altinorak    06 Ocak 2004 Sali
    //  20403 candan       ormanci      09 Mart 1977 Carsamba
    //  10538 tekin        koylu        30 Agustos 1950 Carsamba
  }
*/

/*
  #include <stdio.h>  
  // fopen, fclose, fread, fseek, fwrite, printf
  #include <string.h> // strcmp, strcpy
  #include <stdlib.h> // exit, EXIT_FAILURE
  #include "../headers/person.h"

  void print_person_records(const char* filename)
  {
    FILE* f = fopen(filename, "rb");
    if (f == NULL){
      printf("%s could not be opened.\n", filename);
      exit(EXIT_FAILURE);
    }

    Person_t per;

    while (fread(&per, sizeof(Person_t), 1, f) != 0)
      person_print(&per);

    fclose(f);
  }

  int replace_names(const char* filename,
                    const char* old_name,
                    const char* new_name)
  {
    FILE* f = fopen(filename, "r+b"); // read(+)-binary mode
    if (f == NULL){
      printf("%s could not be opened.\n", filename);
      return 0;
    }

    Person_t per;
    int replaced_count = 0;

    while (fread(&per, sizeof(Person_t), 1, f) != 0)
    {
      if (strcmp(per.m_name, old_name) == 0)
      {
        strcpy(per.m_name, new_name);
        fseek(f, -((long)sizeof(Person_t)), SEEK_CUR);
        fwrite(&per, sizeof(Person_t), 1, f);
        fseek(f, 0L, SEEK_CUR);

        ++replaced_count;
      }
    }

    fclose(f);

    return replaced_count;
  }

  int main(void)
  {
    int N = replace_names("person10000.dat", "ahmet", "XXXXXXXX");
    printf("%d names replaced.\n", N);
    // output -> 34 names replaced.

    print_person_records("person10000.dat");

    // output ->
    //  ...
    //  2378  figen        elmali       01 Mart 1976 Pazartesi
    //  22370 abdi         canbay       29 Agustos 1971 Pazar
    //  1939  cemile       beyaz        11 Ocak 1942 Pazar
    //  22967 eda          korukcu      10 Kasim 1965 Carsamba
    //  5868  XXXXXXXX     elkizi       12 Agustos 2009 Carsamba
    //  4021  tunc         kelleci      11 Subat 2011 Cuma
    //  ...
  }
*/

/*
  dosyadan silmek denilen bir işlem yoktur.
    - dosyanın kopyası çıkartılır, silinecek bytelar yazılmaz.
    - eski dosya sikinir kopya olan dosyanın ismi değiştirilir.
*/

/*
  #include <stdio.h>  
  // fopen, fclose, tmpnam, L_tmpnam, fread, fwrite
  #include <stdlib.h> // exit, EXIT_FAILURE
  #include "../headers/person.h"

  int delete_records( const char* filename, int day)
  {
    FILE* f_src = fopen(filename, "rb");
    if (f_src == NULL){
      printf("%s could not be opened.\n", filename);
      exit(EXIT_FAILURE);
    }

    char dest_filename[L_tmpnam];
    tmpnam(dest_filename);

    FILE* f_dst = fopen(dest_filename, "wb");
    if (f_dst == NULL){
      printf("%s could not be created.\n", dest_filename);
      fclose(f_src);
      exit(EXIT_FAILURE);
    }

    Person_t per;
    int record_count = 0;
    int copy_count = 0;

    while (fread(&per, sizeof(Person_t), 1, f_src) != 0)
    {
      ++record_count;

      if (per.m_birth_date.m_day != day){
        fwrite(&per, sizeof(Person_t), 1, f_dst);
        ++copy_count;
      }
    }

    fclose(f_dst);
    fclose(f_src);

    if (remove(filename) != 0){
      printf("%s could not be deleted.\n", filename);
      exit(EXIT_FAILURE);
    }

    if (rename(dest_filename, filename) != 0){
      printf("%s could not be renamed.\n", dest_filename);
      exit(EXIT_FAILURE);
    }

    return record_count - copy_count;
  }

  void print_person_records(const char* filename)
  {
    FILE* f = fopen(filename, "rb");
    if (f == NULL){
      printf("%s could not be opened.\n", filename);
      exit(EXIT_FAILURE);
    }

    Person_t per;

    while (fread(&per, sizeof(Person_t), 1, f) != 0)
      person_print(&per);

    fclose(f);
  }

  int main(void)
  {
    for (int i = 1; i <= 30; ++i){
      printf( "i = %d, %d records deleted.\n", 
              i, delete_records("person10000.dat", i));
    }
    
    print_person_records("person10000.dat");

    // output ->
    //  i = 1, 334 records deleted.
    //  i = 2, 321 records deleted.
    //  i = 3, 312 records deleted.
    //  i = 4, 308 records deleted.
    //  i = 5, 325 records deleted.
    //  i = 6, 355 records deleted.
    //  i = 7, 326 records deleted.
    //  i = 8, 342 records deleted.
    //  i = 9, 304 records deleted.
    //  i = 10, 315 records deleted.
    //  i = 11, 328 records deleted.
    //  i = 12, 330 records deleted.
    //  i = 13, 340 records deleted.
    //  i = 14, 365 records deleted.
    //  i = 15, 337 records deleted.
    //  i = 16, 309 records deleted.
    //  i = 17, 333 records deleted.
    //  i = 18, 347 records deleted.
    //  i = 19, 337 records deleted.
    //  i = 20, 344 records deleted.
    //  i = 21, 328 records deleted.
    //  i = 22, 343 records deleted.
    //  i = 23, 321 records deleted.
    //  i = 24, 366 records deleted.
    //  i = 25, 314 records deleted.
    //  i = 26, 283 records deleted.
    //  i = 27, 321 records deleted.
    //  i = 28, 319 records deleted.
    //  i = 29, 268 records deleted.
    //  i = 30, 321 records deleted.
    //  16156 cetin        fakir        31 Ekim 1957 Persembe
    //  18    bekir        sonmez       31 Ocak 1999 Pazar
    //  24954 nuri         cuhadar      31 Aralik 2017 Pazar
    //  11139 lamia        cangoz       31 Temmuz 1941 Persembe
    //  ...
  }
*/

/*
  #include <stdio.h>  
  // fopen, fclose, fseek, ftell
  #include <stdlib.h>   // exit, EXIT_FAILURE
  #include "../headers/person.h"

  int person_cmp_qsort(const void* vp1, const void* vp2)
  {
    return 
      person_compare((const Person_t*)vp1, (const Person_t*)vp2);
  }

  void sort_records(const char* filename)
  {
    FILE* f = fopen(filename, "r+b"); // read(+)-binary mode
    if (f == NULL){
      printf("%s could not be opened.\n", filename);
      return;
    }

    fseek(f, 0L, SEEK_END);
    long file_size = ftell(f);
    size_t person_count = (size_t)file_size / sizeof(Person_t);

    Person_t* mem_records = (Person_t*)malloc((size_t)file_size);
    if (mem_records == NULL){
      printf("Memory allocation failed.\n");
      fclose(f);
      exit(EXIT_FAILURE);
    }

    rewind(f);
    fread(mem_records, sizeof(Person_t), person_count, f);

    qsort(mem_records, 
          person_count, 
          sizeof(Person_t), 
          person_cmp_qsort);

    rewind(f);
    fwrite(mem_records, sizeof(Person_t), person_count, f);

    free(mem_records);
    fclose(f);
  }

  void print_person_records(const char* filename)
  {
    FILE* f = fopen(filename, "rb");
    if (f == NULL){
      printf("%s could not be opened.\n", filename);
      exit(EXIT_FAILURE);
    }

    Person_t per;

    while (fread(&per, sizeof(Person_t), 1, f) != 0)
      person_print(&per);

    fclose(f);
  }

  int main(void)
  {
    sort_records("person10000.dat");
    print_person_records("person10000.dat");

    // output ->
    //  11233 yeliz        dumbuk       10 Haziran 1992 Carsamba
    //  21828 yurdanur     dumbuk       17 Kasim 1953 Sali
    //  26356 zarife       dumbuk       23 Agustos 1979 Persembe
    //  3720  adnan        dunyalik     25 Mayis 2022 Carsamba
    //  19271 alev         dunyalik     29 Agustos 2011 Pazartes
    //  ...
    //  12468 candan       zalim        22 Haziran 1962 Cuma
    //  15476 candan       zalim        13 Mart 2001 Sali
    //  13132 cemre        zalim        19 Aralik 1941 Cuma
    //  ...
  }
*/


// siralamanin dosyanin ustunde yapilacagi ornek 
// bir sonraki derste.