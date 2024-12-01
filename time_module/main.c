#include <stdio.h>

/*
                        ===================
                        | <time.h> module |
                        ===================
*/

/*
  types that defined in <time.h> module:
    - time_t    : type alias for an integral type.
    - clock_t
    - struct tm 
*/

/*
  time point :  
    tarih-zamanda bir an(nokta).
  epoch      :  
    tarih-zamanda bir başlangıç noktası(orjin).
    sistemden sisteme değişebilir.
    unix epcoh: 01 01 1970 00:00:00

  time point bilgisi epoch'tan ile süre arasındaki mesafe olarak 
  tutuluyor ise, bu duruma calendar time denir.
  "time_t" türü ile temsil edilir.

  epoch'tan ilerleyerek veya gerileyerek belirli bir sayıda
  saniye sonrasında varılan noktanın, insan için anlamlı 
  bir veriye dönüştürülmesine broken-down time denir.

  broken-down time, "struct tm" türü ile temsil edilir.
*/

/*
  struct tm {
    int tm_year;  // years since 1900
    int tm_mon;   // months since January [0, 11]
    int tm_mday;  // day of the month [1, 31]
    int tm_wday;  // days since Sunday [0, 6]
    int tm_yday;  // days since January 1 [0, 365]
    int tm_hour;  // hours since midnight [0, 23]
    int tm_min;   // minutes after the hour [0, 60]
    int tm_sec;   // seconds after the minute [0, 60]
    int tm_isdst; // daylight saving time flag
  };
*/

/*
  #include <time.h>

  // time function's prototype
  time_t time(time_t*);

  int main(void)
  {
    // ---------------------------------------------------------

    time_t sec;
    time(&sec); 
    // writes total seconds since epoch to OUT parameter

    printf("seconds since epoch = %lld\n", sec);  
    // output -> seconds since epoch = 1731527129

    // ---------------------------------------------------------

    printf("seconds since epoch = %lld\n", time(NULL));
    // output -> seconds since epoch = 1731527129

    // ---------------------------------------------------------
  }
*/

/*
  #include <time.h>

  // localtime function's prototype
  struct tm* localtime(const time_t*);

  // converts local time to broken-down time
  // returns a pointer to a `static` struct tm object

  int main(void)
  {
    time_t sec;
    time(&sec);

    // ---------------------------------------------------------

    for (int i = 0; i < 5; ++i) 
      printf("%p\n", (void*)localtime(&sec));

    // output ->
    //  000002F2A4DEE7D0
    //  000002F2A4DEE7D0
    //  000002F2A4DEE7D0
    //  000002F2A4DEE7D0
    //  000002F2A4DEE7D0

    // because of localtime function 
    // returns a pointer to a static object
    // address of the object is same in each call
    
    // ---------------------------------------------------------
  }
*/

/*
  // wants an output like this -> 01 Ocak 2024 Pazar 00:00:00

  #include <time.h>

  int main(void)
  {
    time_t sec;
    time(&sec);

    const char* const p_months[] = 
      { "Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran",
        "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik" };

    const char* const p_days[] = 
      { "Pazar", "Pazartesi", "Sali", "Carsamba", 
        "Persembe", "Cuma", "Cumartesi" };
      

    // ---------------------------------------------------------

    struct tm* p_tm = localtime(&sec);

    char stream[64];
    sprintf(stream, "%02d %s %d %s %02d:%02d:%02d\n", 
        p_tm->tm_mday, 
        p_months[p_tm->tm_mon], 
        p_tm->tm_year + 1900,
        p_days[p_tm->tm_wday],
        p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);

    puts(stream);
    // output -> 13 Kasim 2024 Carsamba 22:57:14

    // ---------------------------------------------------------

    sec = 1800000000;  // 1'800'000'000
    p_tm = localtime(&sec);

    sprintf(stream, "%02d %s %d %s %02d:%02d:%02d\n", 
        p_tm->tm_mday, 
        p_months[p_tm->tm_mon], 
        p_tm->tm_year + 1900,
        p_days[p_tm->tm_wday],
        p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);

    puts(stream);
    // output -> 15 Ocak 2027 Cuma 11:00:00

    // ---------------------------------------------------------

    sec = 0;
    p_tm = localtime(&sec); // localtime

    printf("%02d %s %d %s %02d:%02d:%02d\n", 
        p_tm->tm_mday, 
        p_months[p_tm->tm_mon], 
        p_tm->tm_year + 1900,
        p_days[p_tm->tm_wday],
        p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);
    // output -> 01 Ocak 1970 Persembe 03:00:00

    // ---------------------------------------------------------

    p_tm = gmtime(&sec);    // greenwich mean time

    printf("%02d %s %d %s %02d:%02d:%02d\n", 
        p_tm->tm_mday, 
        p_months[p_tm->tm_mon], 
        p_tm->tm_year + 1900,
        p_days[p_tm->tm_wday],
        p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);
    // output -> 01 Ocak 1970 Persembe 00:00:00

    // ---------------------------------------------------------
  }
*/

/*
  #include <time.h>

  int main(void)
  {
    time_t sec;
    time(&sec);
    struct tm* p_tm = localtime(&sec);

    if (p_tm->tm_isdst) {
      printf("daylight saving time is in effect\n");
    } 
    else {
      printf("daylight saving time is not in effect\n");
    }
    // output -> daylight saving time is not in effect(Turkiye)
  }
*/

/*
  #include <time.h>

  // ctime function's prototype
  char* ctime(const time_t*);
  // returns the address of static char[26] array
  // gets calendar time pointer as a parameter

  // asctime function's prototype
  char* asctime(const struct tm*);
  // returns the address of static char[26] array
  // gets broken-down time pointer as a parameter

  // both functions are returning the same array's address

  int main(void)
  {
    time_t sec = 12376472363;

    // ---------------------------------------------------------

    char* p_str1 = ctime(&sec);

    printf("[%s]\n", p_str1);
    // output -> 
    //  [Tue Mar 13 07:59:23 2362
    //  ]
    // ---> string is terminated with '\n' character

    // ---------------------------------------------------------

    struct tm* p_tm = localtime(&sec);
    char* p_str2 = asctime(p_tm);

    printf("[%s]\n", p_str2);
    // output ->
    //  [Tue Mar 13 07:59:23 2362
    //  ]

    // ---------------------------------------------------------

    printf("&p_str1[0] = %p\n", (void*)p_str1);
    printf("&p_str2[0] = %p\n", (void*)p_str2);

    // output ->
    //  &p_str1[0] = 0000017F98E2E590
    //  &p_str2[0] = 0000017F98E2E590

    // ---------------------------------------------------------
  }
*/

/*
  #include <time.h>

  int main(void)
  {
    time_t sec = time(NULL);
    struct tm* p_tm = localtime(&sec);

    printf("%s", asctime(p_tm));
    // output -> Thu Nov 14 00:03:46 2024
  }
*/

/*
        <--- check ../not_related/main.c -> localization --->
*/

/*
  #include <time.h>

  #define BUFFER_SIZE 100

  // strftime function's prototype
  size_t strftime(char*, size_t, const char*, const struct tm*);

  int main(void)
  {
    time_t sec = time(&sec);
    localtime(&sec);

    char buffer[BUFFER_SIZE];

    strftime(buffer, BUFFER_SIZE, "%A", localtime(&sec));
    printf("%s\n", buffer); // output -> Thursday
    strftime(buffer, BUFFER_SIZE, "%a", localtime(&sec));
    printf("%s\n", buffer); // output -> Thu

    strftime(buffer, BUFFER_SIZE, "%B %A", localtime(&sec));
    printf("%s\n", buffer); // output -> November Thursday
    strftime(buffer, BUFFER_SIZE, "%b %a", localtime(&sec));
    printf("%s\n", buffer); // output -> Nov Thu

    strftime(buffer, BUFFER_SIZE, "%D", localtime(&sec));
    printf("%s\n", buffer); // output -> 11/14/24
    strftime(buffer, BUFFER_SIZE, "%d", localtime(&sec));
    printf("%s\n", buffer); // output -> 14

    strftime(buffer, BUFFER_SIZE, "%H:%M:%S", localtime(&sec));
    printf("%s\n", buffer); // output -> 15:04:35

    strftime(buffer, BUFFER_SIZE, "%Y", localtime(&sec));
    printf("%s\n", buffer); // output -> 2024

    strftime(buffer, BUFFER_SIZE, "%c", localtime(&sec));
    printf("%s\n", buffer); // output -> Thu Nov 14 15:04:35 2024
  }
*/

/*
  // "setlocale" is locale dependent function

  #include <time.h>
  #include <locale.h>

  #define BUFFER_SIZE 100

  int main(void)
  {
    time_t sec = time(&sec);
    localtime(&sec);

    char buffer[BUFFER_SIZE];

    if (!setlocale(LC_ALL, "turkish")) {
      printf("locale setting failed\n");
      return 1;
    }

    size_t N = strftime(buffer, 
                        BUFFER_SIZE, 
                        "%d %B %A %Y", 
                        localtime(&sec));

    printf("%s\n", buffer); // output -> 14 Kasim Persembe 2024
    printf("N = %zu\n", N); // output -> N = 24
  }
*/

/*
  #include <time.h>
  #include <stdlib.h> // malloc, free, qsort
  #include "../headers/nutility.h"

  // clock function's prototype
  clock_t clock(void);

  // clock tick is a unit of time that a clock uses
  // to convert it to seconds CLOCKS_PER_SEC macro is used
  // CLK_TCK macro is also a type alias for CLOCK_PER_SEC

  int int_compare(const void* vp1, const void* vp2)
  {
    return *(const int*)vp1 - *(const int*)vp2;
    // trusting that no overflow will occur
  }

  int main(void)
  {
    size_t N = 1000000; //  1'000'000
    int* p = malloc(N * sizeof(int));

    if (!p){
      printf("memory allocation failed\n");
      return 1;
    }

    set_array_random(p, N);

    printf("[0] - sorting started for %zu elements\n", N);

    // ---------------------------------------------------------

    clock_t start = clock();
    qsort(p, N, sizeof *p, &int_compare);
    clock_t end = clock();

    // ---------------------------------------------------------

    printf("[1] - sorting end in %f seconds\n", 
            (double)(end - start) / CLOCKS_PER_SEC);

    printf("[1] - sorting end in %f seconds\n", 
            (double)(end - start) / CLK_TCK);

    // output ->
    //  [0] - sorting started for 1000000 elements
    //  [1] - sorting end in 0.055000 seconds
    //  [1] - sorting end in 0.055000 seconds

    free(p);
  }
*/