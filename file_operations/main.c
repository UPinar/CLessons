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
    FILE* f = fopen("../date.h", "r");   // read mode

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
    FILE* f = fopen("../date.h", "r");   // read mode

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
  //  main.c ../date.c ../nutility.c -std=c23
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
  #include "../nutility.h"

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
