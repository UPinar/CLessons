#include "nutility.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void randomize(void){
  srand((unsigned)time(NULL));
}

void sgets(char* pStr){
  int c;
  while ((c = getchar()) != '\n')
    *pStr++ = (char)c;
  *pStr = '\0';
}

void swap(int* x, int* y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void set_array_random(int* p_array, size_t size){
  while(size--)
    *p_array++ = rand() % 1000;
}

void print_array(const int* p_array, size_t size){
  for (size_t i = 0; i < size; ++i){
    if (i && i % 10 == 0)
      putchar('\n');
    printf("%3d ", p_array[i]);
  }
  printf("\n---------------------------------------\n");
}

void sort_array(int* pArr, size_t size){
  for (size_t i = 0; i < size - 1; ++i){
    for (size_t k = i + 1; k < size; ++k){
      if (pArr[i] > pArr[k]){
        int temp = pArr[i];
        pArr[i] = pArr[k];
        pArr[k] = temp;
      }
    }
  }
}

void reverse_array(int* p_array, size_t size)
{
  for(size_t i = 0; i < size / 2; ++i)
    swap(p_array + i, p_array + size - i - 1);
}

int get_sum(const int* p_array, size_t size)
{
  int sum = 0;
  for(size_t i = 0; i < size; ++i)
    sum += p_array[i];
  
  return sum;
}

double get_mean(const int* p_array, size_t size)
{
  return (double)get_sum(p_array, size) / (double)size;
}

double get_std_dev(const int* p_array, size_t size)
{
  double mean = get_mean(p_array, size);
  double sum_square = 0.;

  for(size_t i = 0; i < size; ++i)
    sum_square += (p_array[i] - mean) * (p_array[i] - mean);

  return sqrt(sum_square / ((int)size - 1));
}

int get_max_elem(const int* p_array, size_t size)
{
  int max = p_array[0];
  for(size_t i = 1; i < size; ++i)
    if(p_array[i] > max)
      max = p_array[i];
  
  return max;
}

int get_min_elem(const int* p_array, size_t size)
{
  int min = *p_array;
  for(size_t i = 1; i < size; ++i)
    if(p_array[i] < min)
      min = p_array[i];
  
  return min;
}

void get_min_max(const int* p_array, size_t size, int* p_min, int* p_max)
{
  *p_min = *p_max = *p_array;

  for(size_t i = 1; i < size; ++i){
    if(p_array[i] > *p_max)
      *p_max = p_array[i];
    else if(p_array[i] < *p_min)
      *p_min = p_array[i];
  }
}

void copy_array(int* p_dest, const int* p_source, size_t size)
{
  while (size--)
    *p_dest++ = *p_source++;
}

void swap_arrays(int* p_array1, int* p_array2, size_t size)
{
  while (size--)
    swap(p_array1++, p_array2++);
}

void swap_T(void* vp1, void* vp2, size_t size)
{
  char* p1 = vp1;
  char* p2 = vp2;

  while (size--)
  {
    char temp = *p1;
    *p1++ = *p2;
    *p2++ = temp;
  }
}

const char* p_names[] = {
"ata", "emrecan", "adem", "burhan", "korhan", "demir", "bilal", 
"emrecan", "celik", "zahide", "dost", "lale", "baran", "saniye", 
"poyraz", "saadet", "aynur", "yeliz", "berivan", "mukerrem", "melih", 
"necati", "cezmi", "muslum", "azize", "atif", "rupen", "alev", "haldun", 
"hulusi", "yelda", "billur", "yasemin", "tarcan", "yasar", "tarkan", 
"refik", "berk", "kenan", "izzet", "adnan", "sefa", "kazim", "gursel", 
"huseyin", "suheyla", "binnaz", "nusret", "aykut", "efecan", "esra", 
"tonguc", "kunter", "yurdanur", "abdi", "fugen", "ayse", "aydan", "edip", 
"nazli", "nucahit", "onat", "cumhur", "yalcin", "ziya", "ali", "ismail", 
"recep", "sarp", "yilmaz", "hilal", "atakan", "cemre", "emirhan", 
"ceylan", "sabriye", "necmettin", "nagehan", "muhsin", "perihan", 
"suleyman", "zeliha", "cahide", "beril", "askin", "zahit", "sevim", 
"ege", "utku", "ercument", "seyhan", "sadegul", "enes", "sadi", "candan",
"cemile", "tansel", "turgut", "sumeyye", "aylin", "hakan", "ferhunde", 
"cebrail", "nihat", "alparslan", "osman", "efe", "ece", "soner", "necmi",
"polat", "naci", "pelinsu", "kerim", "eylul", "beste", "mert", "akin", 
"kamile", "kerem", "bekir", "nalan", "bulent", "tijen", "durmus", "cansu", 
"sadri", "atil", "yesim", "sevilay", "furkan", "ediz", "helin", "sadettin",
"gulden", "samet", "binnur", "celal", "murat", "sezer",
"bilge", "yunus", "cem", "temel", "sefer", "petek", "haluk", "teoman", 
"aslican", "aycan", "azmi", "nazife", "nurullah", "yasin", "nedim", 
"abdulmuttalip", "gulsen", "devlet", "mahir", "tarik", "yurdagul", 
"nisan", "derya", "emre", "sade", "leyla", "fadime", "tamer", "julide", 
"busra", "feramuz", "dilek", "dilber", "tansu", "abdullah", "mehmet", 
"nuri", "gizem", "nefes", "yavuz", "demet", "zekai", "zerrin", "umit", 
"gul", "emine", "sezen", "ugur", "turhan", "aziz", "tuncer", "handan", 
"okan", "irmak", "lamia", "can", "kelami", "ceyhan", "cahit", "gazi",
"bilgin", "su", "tayyar", "ferhat", "nuriye", "cemal", "engin", "pelin", 
"yusuf", "garo", "iffet", "galip", "deniz", "belgin", "muzaffer", 
"niyazi", "kayahan", "hulki", "kaya", "necmiye", "kasim", "hulya", 
"sidre", "esin", "suphi", "cengiz", "olcay", "rumeysa", "tugay", "asim", 
"yurdakul", "feraye", "derin", "cuneyt", "keriman", "naciye", "esen", 
"tevfik", "naz", "gurbuz", "cetin", "bora", "taci", "sadullah", "gulsah", 
"menekse", "semsit", "burak", "fikret", "cihan", "ceyda", "selenay", 
"alican", "figen", "nasrullah", "cesim", "zubeyde", "sezai", "melike", 
"nurdan", "arda", "nazif", "fuat", "gunay", "tufan", "fahri", "handesu", 
"kezban", "halime", "beyhan", "ciler", "tayyip", "afacan", "mustafa", 
"kurthan", "tugra", "ahmet", "hasan", "hakki", "metin", "aytac", "pinat",
"selin", "kaan", "melisa", "sevda", "nihal", "nevsin", "pakize", 
"teslime", "tunc", "nahit", "ceyhun", "hikmet", "eda", "malik", "anil", 
"canan", "egemen", "hande", "hilmi", "muruvvet", "cemil", "diana", 
"tayfun", "zarife", "tekin", "murathan", "caner", "devrim", "agah", 
"kamil", "ayla", "papatya", "kayhan", "durriye", "melek", "tanju", 
"sinem", "jade", "sadiye", "refika", "birhan", "sami", "orkun", "erdem", 
"ufuk", "dogan", "atalay", "fazilet", "taner", "polathan", "bennur", 
"aslihan", "cihat", };
