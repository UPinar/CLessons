#include <stdio.h>

/*
                  ==========================
                  | Command Line Arguments |
                  ==========================
*/

/*
  // int main(int argc, char* argv[]) 
  int main(int argc, char** argv) 
  {
    return 0;
  }

  // "argc" and "argv" are identifiers NOT keywords.
  // general convention is using "argc" and "argv"
  // argc : argument count
  // argv : argument vector
*/

/*
  int main(int argc, char** argv) 
  {
    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++) 
      printf("argv[%d] = %s\n", i, argv[i]);

    // command line -> prog.exe hello world 11 22 AB
    // output ->
    //  argc = 6
    //  argv[0] = prog.exe
    //  argv[1] = hello
    //  argv[2] = world
    //  argv[3] = 11
    //  argv[4] = 22
    //  argv[5] = AB

    // command line -> prog.exe "hello world" "11 22" AB
    // output ->
    //  argc = 4
    //  argv[0] = prog.exe
    //  argv[1] = hello world
    //  argv[2] = 11 22
    //  argv[3] = AB
  }
*/

/*
  #include <stdlib.h> // exit, EXIT_FAILURE

  int main(int argc, char** argv) 
  {
    // checking argument count
    if (argc != 3) 
    {
      printf("Usage: %s <source> <destination>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    printf("file %s copied to %s\n", argv[1], argv[2]);
  }

  // command line -> prog.exe a.txt b.txt c.txt
  // output -> Usage: prog.exe <source> <destination>

  // command line -> prog.exe a.txt b.txt
  // output -> file a.txt copied to b.txt
*/

/*
  // calculator program

  #include <stdlib.h> // exit, EXIT_FAILURE, atoi

  int main(int argc, char** argv)
  {
    if (argc != 4)
    {
      printf("Usage: %s <num1> <op> <num2>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);

    switch (*argv[2]){
    case '+': 
      printf("%d + %d = %d\n", num1, num2, num1 + num2); 
      break;
    case '-': 
      printf("%d - %d = %d\n", num1, num2, num1 - num2); 
      break;
    case 'x': 
      printf("%d x %d = %d\n", num1, num2, num1 * num2); 
      break;
    case '/': 
      if (num2 == 0) {
        printf("Division by zero\n");
        exit(EXIT_FAILURE);
      }
      printf("%d / %d = %f\n", num1, num2, (double)num1 / num2); 
      break;
    default: 
      printf("Invalid operator\n");
      break;
    }
  }

  // command line -> prog.exe 10 + 20 30
  // output -> Usage: prog.exe <num1> <op> <num2>

  // command line -> prog.exe 10 + 20
  // output -> 10 + 20 = 30

  // command line -> prog.exe 10 - 20
  // output -> 10 - 20 = -10

  // command line -> prog.exe 10 x 20
  // output -> 10 x 20 = 200

  // command line -> prog.exe 10 / 0
  // output -> Division by zero

  // command line -> prog.exe 10 / 20
  // output -> 10 / 20 = 0.500000

  // command line -> prog.exe 10 % 20
  // output -> Invalid operator
*/

/*
  // weekday program 

  #include <stdlib.h> // exit, EXIT_FAILURE, atoi
  #include "../date.h"

  int main(int argc, char** argv)
  {
    if (argc != 4)
    {
      printf("Usage: %s <day> <month> <year>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);

    Date_t d1;
    date_set(&d1, day, month, year);
    date_print(&d1);
  }

  // command line -> prog.exe 1 1 2001 12
  // output -> Usage: prog.exe <day> <month> <year>

  // command line -> prog.exe 1 1 2001
  // output -> 01 Ocak 2001 Pazartesi

  // command line -> prog.exe 30 11 2024
  // output -> 30 Kasım 2024 Cumartesi
*/

/*
  // calculate N days later 

  #include <stdlib.h> // exit, EXIT_FAILURE, atoi
  #include "../date.h"

  int main(int argc, char** argv)
  {
    if (argc != 5)
    {
      printf("Usage: %s <day> <month> <year> <N>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);

    Date_t d1;
    date_set(&d1, day, month, year);

    Date_t future_date;
    date_N_days_after(&future_date, &d1, atoi(argv[4]));
    date_print(&future_date);
  }

  // command line -> prog.exe 1 1 2001 12 15
  // output -> Usage: prog.exe <day> <month> <year> <N>

  // command line -> prog.exe 1 1 2001 12
  // output -> 13 Ocak 2001 Cumartesi

  // command line -> prog.exe 30 11 2024 15
  // output -> 15 Aralık 2024 Pazar

  // command line -> prog.exe 30 11 2024 999
  // output -> 26 Ağustos 2027 Perşembe
*/

/*
  // argv[argc] is guaranteed to be NULL 

  int main(int argc, char** argv) 
  {
    if (argv[argc] == NULL)
      printf("argv[%d] is NULL\n", argc);
    else
      printf("argv[%d] is NOT NULL\n", argc);
  }

  // command line -> prog.exe hello world 12 15
  // output -> argv[5] is NULL
*/

/*
  int main(int argc, char** argv) 
  {
    int i = 0;
    while (argv[i] != NULL){
      printf("argv[%d] = %s\n", i, argv[i]);
      ++i;
    }
  }

  // command line -> prog.exe hello world 12 15
  // output ->
  //  argv[0] = prog.exe
  //  argv[1] = hello
  //  argv[2] = world
  //  argv[3] = 12
  //  argv[4] = 15
*/

/*
  #include <string.h> // strcpy

  #define   FILE_NAME_SIZE  100

  int main(int argc, char** argv) 
  {
    char source_file_name[FILE_NAME_SIZE];
    char destination_file_name[FILE_NAME_SIZE];

    if (argc != 3) {
      printf("Usage: %s <source> <destination>\n", argv[0]);
      printf("Enter source file name: ");
      scanf("%s", source_file_name);

      printf("Enter destination file name: ");
      scanf("%s", destination_file_name);
    }
    else {
      strcpy(source_file_name, argv[1]);
      strcpy(destination_file_name, argv[2]);
    }

    printf("file %s copied to %s\n",  source_file_name, 
                                      destination_file_name);
  }

  // command line -> prog.exe a.txt
  // output -> Usage: prog.exe <source> <destination>
  // input  -> Enter source file name: a.txt
  // input  -> Enter destination file name: b.txt
  // output -> file a.txt copied to b.txt

  // command line -> prog.exe a.txt b.txt
  // output -> file a.txt copied to b.txt
*/