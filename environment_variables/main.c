#include <stdio.h>

/*
                    =========================
                    | environment variables |
                    =========================
*/

/*
  - key value pairs

  işletim sistemi, bir process çalıştırıldığında, 
  processin bellek alanında çevresel değişkenler
  (environment variables) tutar ve bu değişkenler
  program içinde kullanılabilirler.

  program içinde çevresel değişkenler oluşturulabilir.
*/

/*
                    ------------------------
                    | getenv in <stdlib.h> |
                    ------------------------        
*/

/*
  // getenv function's prototype
  char* getenv(const char* ev_string);

  - return NULL when fails, otherwise ev_string's value
*/

/*
  #include <stdlib.h>   // getenv, exit, EXIT_FAILURE

  int main(void)
  {
    const char* p_str = getenv("PATH");

    if (p_str == NULL) {
      fprintf(stderr,"PATH environment variable not found\n");
      exit(EXIT_FAILURE);
    }

    FILE* f = fopen("out.txt", "w");
    if (f == NULL) {
      fprintf(stderr, "cannot open file\n");
      exit(EXIT_FAILURE);
    }

    fputs(p_str, f);
    fclose(f);

    // out.txt ->
    //  C:\Windows\system32;
    //  C:\Windows;
    //  ...
  }
*/

/*
  // non-standart pointer array
  int main(int argc, char** argv, char** env)
  {
    for (int i = 0; env[i] != NULL; ++i)
      printf("[%2d] %s\n", i + 1, env[i]);

    // output -> 
    //  ...
    //  [10] HOMEDRIVE=C:
    //  ...
  }
*/

/*
  #include <stddef.h>   // size_t
  #include <stdlib.h>   // getenv
  #include "../headers/nutility.h"

  int main(void)
  {
    const char* const p_env[] = {
      "NUMBER_OF_PROCESSORS", "HOMEDRIVE", "SystemDrive",
      "windir", "OS" 
    };

    const char* env_str;

    for (size_t i = 0; i < asize(p_env); ++i) {
      if ((env_str = getenv(p_env[i])) != NULL)
        printf("%-20s = %s\n", p_env[i], env_str);
    }

    // output ->
    //  NUMBER_OF_PROCESSORS = 12
    //  HOMEDRIVE            = C:
    //  SystemDrive          = C:
    //  windir               = C:\WINDOWS
    //  OS                   = Windows_NT
  }
*/

/*
  // for windows "_putenv" function 
  // is for setting environment variables

  #include <stdlib.h>

  int main(void)
  {
    if (_putenv("UNIQUE_ENV_VAR=111")) {
      fprintf(stderr, "cannot set environment variable\n");
      return 1;
    }

    const char* p_str;

    if ((p_str = getenv("UNIQUE_ENV_VAR")) != NULL) {
      printf("UNIQUE_ENV_VAR = %s\n", p_str);
    }
  }
*/