#ifndef DATE_H
#define DATE_H

typedef struct Date {
  int m_day;
  int m_month;
  int m_year;
} Date_t;


// set functions - mutators - setters
Date_t* date_set(Date_t* p_date, int day, int month, int year);
Date_t* date_set_by_string(Date_t* p_date, const char* p_date_str); // dd-mm-yyyy
Date_t* date_set_today(Date_t* p_date);
Date_t* date_set_random(Date_t* p_date);

Date_t* date_set_year(Date_t* p_date, int year);
Date_t* date_set_month(Date_t* p_date, int month);
Date_t* date_set_day(Date_t* p_date, int day);


// get functions - accessors - getters
int date_get_year(const Date_t* p_date);
int date_get_month(const Date_t* p_date);
int date_get_day_of_month(const Date_t* p_date);  
int date_get_day_of_year(const Date_t* p_date);
int date_get_day_of_week(const Date_t* p_date);   // 0 - Sunday


// utility functions
int date_compare(const Date_t* p_date1, const Date_t* p_date2);
int date_diff(const Date_t* p_date_from, const Date_t* p_date_to);
Date_t* date_N_days_after(Date_t* p_dest, Date_t* p_source, int N);
Date_t* date_N_days_before(Date_t* p_dest, Date_t* p_source, int N);


// formatted input/output functions
void date_print(const Date_t* p_date);  // 1 Ocak 2001 - Pazartesi
Date_t* date_scan(Date_t* p_date);

#endif // DATE_H