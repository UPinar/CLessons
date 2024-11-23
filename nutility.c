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

int* set_array_random_2(int* p_array, size_t size){
  int* p_ret = p_array;

  while(size--)
    *p_array++ = rand() % 1000;
  
  return p_ret;
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

int is_prime(int val)
{
  if (val < 2)
    return 0;

  if (val % 2 == 0)
    return val == 2;

  if (val % 3 == 0)
    return val == 3;

  if (val % 5 == 0)
    return val == 5;

  for (int i = 7; i * i <= val; i += 2)
    if (val % i == 0)
      return 0;

  return 1;
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

const int g_primes[] = {
   0, 2,   3,   5,   7,  11,  13,  17,  19,  23,  29,
     31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
     73,  79,  83,  89,  97, 101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
    419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
    467, 479, 487, 491, 499, 503, 509, 521, 523, 541
  };

const char* get_random_name(void)
{
  return RAND_ELEM(p_names);
}

const char* get_random_surname(void)
{
  static const char* const p_surnames[] = {
    "acar", "acgoze", "acuka", "ademoglu", "adiguzel", "agaoglu", "akarsu", "akcalar", "akgunes", "akkay",
    "akkuyu", "aklikit", "aksakal", "akyildiz", "akyoldas", "alemdar", "alniacik", "altindag", "altinisik", "altinorak",
    "arcan", "aslan", "avci", "aybeyaz", "aylak", "azmak", "bahceli", "bakirci", "baklavaci", "barutcu",
    "baturalp", "bayraktar", "bekar", "belgeli", "beyaz", "bilgic", "bozkaya", "boztas", "canbay", "candamar",
    "cangoz", "cankoc", "canlikaya", "cansever", "cansiz", "celik", "celiker", "cengaver", "cevikkol", "cilingir",
    "comakci", "corbaci", "cubukay", "cuhadar", "daglarca", "damar", "degirmenci", "demirdogen", "demirel", "derin",
    "dingin", "dokmeci", "dokuzcan", "dosteli", "dumbuk", "dunyalik", "ecevit", "edepli", "edepsiz", "efelik",
    "elebasi", "eliagir", "elibol", "elitemiz", "elkizi", "elmali", "eloglu", "emirkulu", "engerek", "engereke",
    "erdogan", "ergin", "erim", "ersoy", "ertakan", "esbereli", "esnedur", "esteberli", "etci", "ezergecer",
    "fakir", "fedai", "fincan", "firatonu", "fitrat", "gamsiz", "gedik", "geldik", "gilgamis", "girik",
    "girit", "gucsuz", "gultekin", "gumus", "gurkas", "hamsikoylu", "harmanci", "haselici", "hepguler", "hurmaci",
    "iliksiz", "issiz", "jilet", "kabasakal", "kadersiz", "kahraman", "kalemsiz", "kalinkas", "kalpsiz", "kalpten",
    "kapan", "kapici", "kaplan", "kara", "karabatur", "karaduman", "karaelmas", "karakis", "karakoyun", "karakuzu",
    "karamuk", "karaorman", "karasaban", "karataban", "karayel", "kayabasi", "kazanci", "kecisakal", "kelepce", "kelleci",
    "keskin", "kesman", "kilicdar", "kilimci", "kilinc", "kirboga", "kirci", "kocyigit", "kolcak", "komcu",
    "komurcu", "konak", "konca", "koralp", "korukcu", "kosnuk", "kotek", "koylu", "kucukkaya", "kulaksiz",
    "kurban", "kurtulus", "kusmen", "lalezar", "lokmaci", "lombak", "lufer", "maganda", "malazgirt", "malkaciran",
    "mazgirt", "merdane", "mertek", "merzifon", "mirza", "miskin", "miskinoglu", "muglali", "nazik", "nurtopu",
    "olmez", "oltu", "onaran", "ongun", "ordulu", "orhancan", "ormanci", "ortaca", "osmaneli", "otaci",
    "ovacik", "oztoklu", "ozvezneci", "pakdamar", "pirlanta", "polatkan", "portakal", "poturgeli", "reis", "renacan",
    "resimci", "saferikli", "safkan", "salca", "saldiray", "sallabas", "samanci", "saricakir", "sarikafa", "sarpdemir",
    "savaskan", "sefiloglu", "selercan", "semiz", "sener", "serce", "serinsun", "sessiz", "silahdar", "silifkeli",
    "simsek", "sivri", "sofuoglu", "sonmez", "sonuzun", "soylu", "soysalan", "soyubozuk", "sucu", "sulugoz",
    "supuren", "takes", "tamgun", "tamirci", "tantana", "tarumar", "tekinalp", "tekkaya", "tekkilic", "telek",
    "temiz", "temizel", "temizkalp", "tepecik", "tepsici", "tercan", "terlemez", "tertemiz", "tilki", "tokatci",
    "tombeki", "topatan", "topkapi", "tozkoporan", "tufancan", "tunali", "tuzcu", "tuztas", "ufurukcu", "ugursuz",
    "ulakci", "uluocak", "umutsuz", "unalan", "unalmis", "unkapani", "uraz", "uslu", "uyar", "uzay",
    "uzunadam", "yagizeli", "yanardag", "yanardoner", "yangin", "yaracan", "yaradan", "yarma", "yasayavas", "yasli",
    "yasmak", "yavas", "yavasakan", "yaygara", "yelden", "yeldirme", "yeldirmen", "yersiz", "yikilmaz", "yildirim",
    "yilgin", "yilmaz", "yolyapan", "yorganci", "yorgun", "yosun", "yurdakul", "yurekli", "yurekyakan", "yurtsuz",
    "zaimoglu", "zalim", "zengin",
	};

  return RAND_ELEM(p_surnames);
}

double get_random_double(void)
{
  return rand() % 100 + (double)(rand() / RAND_MAX);
}

void print_bits(unsigned int val)
{
  unsigned int mask = ~(~0u >> 1);

  while (mask) {
    putchar(mask & val ? '1' : '0');
    mask >>= 1;
  }
  putchar('\n');
}

// lookup table for counting set bits
const int set_bit_arr[] = {
  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
  4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
};