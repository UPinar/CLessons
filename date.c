#include "date.h"

#include <stdio.h>  
#include <stdlib.h> // atoi, rand
#include <time.h>

// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------

#define  PRIVATE
#define  PUBLIC
#define  YEARBASE       1900
#define  RAND_YEAR_MIN  1940
#define  RAND_YEAR_MAX  2024

#define  ISLEAP(Y)    \
  ((Y) % 4 == 0 && ((Y) % 100 != 0 || (Y) % 400 == 0))

#define  MDAYS(Y, M)  (day_tabs[ISLEAP((Y))][(M)])

// ---------------------------------------------------------
// ------------------- PRIVATE FUNCTIONS -------------------
// ---------------------------------------------------------

PRIVATE
static const int day_tabs[][13] = {
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

PRIVATE 
static int is_valid_date(int day, int month, int year)
{
  return  (year >= YEARBASE) && 
          (month > 0 && month <= 12) &&
          (day > 0 && day <= MDAYS(year, month));
}

PRIVATE
static Date_t* date_inner_set(Date_t* p_date, int d, int m, int y)
{
  if (!is_valid_date(d, m, y))
    return NULL;

  p_date->m_day = d;
  p_date->m_month = m;
  p_date->m_year = y;

  return p_date;
}

// Tomohiko Sakamoto’s Algorithm
PRIVATE
static int date_inner_day_of_week(int d, int m, int y)
{
  static const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

  if (m < 3)
    y -= 1;

  return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}

PRIVATE
static int date_total_days_count(const Date_t *p_date)
{
  int total_day_count = date_get_day_of_year(p_date);
  int year = date_get_year(p_date);

  for (int i = YEARBASE; i < year; ++i)
    total_day_count += ISLEAP(i) ? 366 : 365;

  return total_day_count;
}

PRIVATE 
static Date_t* day_count_to_date(Date_t* p_dest, int total_days)
{
  int year = YEARBASE;

  while (total_days > (ISLEAP(year) ? 366 : 365)) 
  {
    total_days -= ISLEAP(year) ? 366 : 365;
    ++year;
  }

  int month = 1;

  while (total_days > MDAYS(year, month)) 
  {
    total_days -= MDAYS(year, month);
    ++month;
  }

  int day = total_days;

  return date_inner_set(p_dest, day, month, year);
}


// ---------------------------------------------------------
// ------------------- PUBLIC FUNCTIONS --------------------
// ---------------------------------------------------------

// ------------------------ Setters ------------------------
// ---------------------------------------------------------

PUBLIC
Date_t* date_set(Date_t* p_date, int day, int month, int year)
{
  return date_inner_set(p_date, day, month, year);
}

PUBLIC
Date_t* date_set_by_string(Date_t* p_date, const char* p_date_str)
{
  // "dd-mm-yyyy"

  int day = atoi(p_date_str);
  int month = atoi(p_date_str + 3);
  int year = atoi(p_date_str + 6);

  return date_inner_set(p_date, day, month, year);
}

PUBLIC
Date_t* date_set_today(Date_t* p_date)
{
  time_t sec;
  time(&sec);
  struct tm* p_time = localtime(&sec);

  int day = p_time->tm_mday;
  int month = p_time->tm_mon + 1;
  int year = p_time->tm_year + YEARBASE;

  return date_inner_set(p_date, day, month, year);
}

PUBLIC
Date_t* date_set_random(Date_t* p_date)
{
  int year = 
    rand() % (RAND_YEAR_MAX - RAND_YEAR_MIN + 1) + RAND_YEAR_MIN;

  int month = rand() % 12 + 1;
  int day = rand() % MDAYS(year, month) + 1;

  return date_inner_set(p_date, day, month, year);
}

PUBLIC
Date_t* date_set_year(Date_t* p_date, int year)
{
  return date_inner_set(p_date, 
                        date_get_day_of_month(p_date), 
                        date_get_month(p_date), 
                        year);
}

PUBLIC
Date_t* date_set_month(Date_t* p_date, int month)
{
  return date_inner_set(p_date, 
                        date_get_day_of_month(p_date), 
                        month, 
                        date_get_year(p_date));
}

PUBLIC
Date_t* date_set_day(Date_t* p_date, int day)
{
  return date_inner_set(p_date, 
                        day, 
                        date_get_month(p_date), 
                        date_get_year(p_date));
}


// ------------------------ Getters ------------------------
// ---------------------------------------------------------

PUBLIC
int date_get_year(const Date_t* p_date)
{
  return p_date->m_year;
}

PUBLIC
int date_get_month(const Date_t* p_date)
{
  return p_date->m_month;
}

PUBLIC
int date_get_day_of_month(const Date_t* p_date)
{
  return p_date->m_day;
}

PUBLIC
int date_get_day_of_year(const Date_t* p_date)
{
  int day_sum = date_get_day_of_month(p_date);

  int year = date_get_year(p_date);
  int month = date_get_month(p_date);

  for (int i = 1; i < month; ++i)
    day_sum += MDAYS(year, i);

  return day_sum;
}

PUBLIC
int date_get_day_of_week(const Date_t* p_date)
{
  int year = date_get_year(p_date);
  int month = date_get_month(p_date);
  int day = date_get_day_of_month(p_date);

  return date_inner_day_of_week(day, month, year);
}

// ------------------------ Utility ------------------------
// ---------------------------------------------------------

PUBLIC
int date_compare(const Date_t* p_date1, const Date_t* p_date2)
{
  int y1 = date_get_year(p_date1);
  int y2 = date_get_year(p_date2);

  if (y1 != y2)
    return y1 - y2;

  int m1 = date_get_month(p_date1);
  int m2 = date_get_month(p_date2);

  if (m1 != m2)
    return m1 - m2;

  return  date_get_day_of_month(p_date1) - 
          date_get_day_of_month(p_date2);
}

PUBLIC
int date_diff(const Date_t* p_date_from, const Date_t* p_date_to)
{
  return  date_total_days_count(p_date_to) - 
          date_total_days_count(p_date_from);
}

PUBLIC 
Date_t* date_N_days_after(Date_t* p_dest, Date_t* p_source, int N)
{
  int total_days = date_total_days_count(p_source) + N;
  return day_count_to_date(p_dest, total_days);
}

PUBLIC
Date_t* date_N_days_before(Date_t* p_dest, Date_t* p_source, int N)
{
  return date_N_days_after(p_dest, p_source, -N);
}


// --------------------- Formatted I/O ---------------------
// ---------------------------------------------------------

PUBLIC
void date_print(const Date_t* p_date)
{
  static const char* const p_months[] = 
      { "", "Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran",
        "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik" };

  static const char* const p_days[] = 
      { "Pazar", "Pazartesi", "Sali", "Carsamba", 
        "Persembe", "Cuma", "Cumartesi" };

  int day = date_get_day_of_month(p_date);
  int month = date_get_month(p_date);
  int year = date_get_year(p_date);
  int week_day = date_get_day_of_week(p_date);

  printf("%02d %s %d %s\n", 
          day, 
          p_months[month], 
          year, 
          p_days[week_day]);
}

PUBLIC
Date_t* date_scan(Date_t* p_date)
{
  int day, month, year;
  int N = scanf("%d %d %d", &day, &month, &year);

  if (N != 3)
    return NULL;

  return date_inner_set(p_date, day, month, year);
}