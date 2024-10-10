#include <stdio.h>

/*
                    ============================
                    | random number generation |
                    ============================
*/

/*
  1 3 5 7 9 ?
  when unpredictability increas, randomness also increas

  1. True Random Number Generators
    - not deterministic (atmospheric noise, radioactive decay, etc.)
    - slow  
    - more quality

  2. Pseudo Random Number Generators 
    - generating numbers with algorithmic methods
    - deterministic (for same input, same output will be generated)
    - fast
    - less quality

    - changing the seed value will change the generated number chain,
    same seed value will generate same number chain

    - number chain that will be generated with PSRGs 
    are uniformly distributed in a defined range 

    - distribution model is needed for random number generation
      uniform distribution -> (düzgün dağılım)
      normal(Gaussian) distribution 
      biased distribution -> (hileli dağılım)
      etc.

    - random numbers generated must repeat after a certain point.
      after 32000 number generated, the same number is generated again,
      frequency is 1/32000
*/

/*
                        -------------------
                        | rand() function |
                        -------------------
*/

/*
  int rand(void); // rand functions declaration

  // rand functions implementation is different in different compilers

  // when same seed value is used in different compilers, 
  // different number chains will be generated
*/

/*
  #include <stdlib.h>

  int main(void){
    // RAND_MAX is a macro defined in stdlib.h

    printf("Max value rand() can generate = %d\n", RAND_MAX); 
    // output -> Max value rand() can generate = 32767
  }
*/

/*
  // standart default seed value is 1

  #include <stdlib.h>

  int main(void){

    for (int i = 0; i < 5; i++){
      printf("%d ", rand());
    }   
    // Programs 1st run output -> 41 18467 6334 26500 19169 
    // Programs 2nd run output -> 41 18467 6334 26500 19169
  }
*/

/*
                        --------------------
                        | srand() function |
                        --------------------
*/

/*
  // void srand(unsigned int); -> srand functions declaration

  #include <stdlib.h>

  int main(void){
    
    srand(1); // seed value is set to 1 which is the default value
    for (int i = 0; i < 5; i++){
      printf("%d ", rand());
    }   
    // Programs 1st run output -> 41 18467 6334 26500 19169 
    // Programs 2nd run output -> 41 18467 6334 26500 19169

    return 0;
  }
*/

/*
  #include <stdlib.h>

  int main(void){
    
    srand(127363u); 
    for (int i = 0; i < 5; i++){
      printf("%d ", rand());
    }   
    // output -> 22736 8266 9628 19992 2108 

    return 0;
  }
*/

/*
  #include <stdlib.h>

  int main(void){

    for (unsigned int i = 7654; i < 7660; ++i){
      srand(i);
      printf("Seed value = %u, Numbers = ", i);
      for (int j = 0; j < 5; j++){
        printf("%d ", rand());
      }
      printf("\n");
    }

    // output ->
    //  Seed value = 7654, Numbers = 25033 28342 12742 26880 18495
    //  Seed value = 7655, Numbers = 25036 6322 30606 18175 28810
    //  Seed value = 7656, Numbers = 25039 17070 15703 9471 6357
    //  Seed value = 7657, Numbers = 25043 27819 799 766 16671
    //  Seed value = 7658, Numbers = 25046 5799 18663 24829 26986
    //  Seed value = 7659, Numbers = 25049 16548 3759 16125 4532
  }
*/

/*
  WARNING:
    In professional applications, never use %(modulus) operator 
    for uniform distribution.
*/

/*
  // backgammon dice roll simulation
  #include <stdlib.h>
  #include <time.h>

  time_t time(time_t *ptr); // time function declaration

  void randomize(void){
    srand((unsigned)time(NULL));  // randomize idiom
  }

  int main(void){
    // epocche in unix -> 01:01:1970 00:00:00

    time_t sec;
    time(&sec); // current time is stored in sec
    printf("Current time = %lld\n", sec); 

    printf("Current time = %lld\n", time(NULL));

    randomize();

    for (int i = 0; i < 5; ++i){
      printf("(%d, %d) ", rand() % 6 + 1, rand() % 6 + 1);
    }

    // 1st run output -> 
    //  Current time = 1725797471
    //  (1, 1) (4, 5) (2, 5) (3, 2) (3, 2)

    // 2nd run output ->
    //  Current time = 1725797480
    //  (1, 6) (4, 2) (6, 4) (6, 4) (1, 6)
  }
*/

/*
  // min 5 character, max 9 character password generator
  
  #include <stdlib.h>
  #include <time.h>

  #define   MIN_LEN   5
  #define   MAX_LEN   9

  void print_random_password(void){
    int n = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;

    while (n--){
      printf("%c", rand() % 26 + 'A');
    }
    putchar(' ');
  }

  int main(void){
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; ++i){
      print_random_password();
    }

    // output -> IZSAQUZB VALVBDR WRYKA GTADYSQXK JMMXA
  }
*/

/*
  // heads possibility in heads or tails simulation 

  #include <stdlib.h>

  #define     NTOSS      100000000 // 100'000'000
  #define     HEADS      1

  int toss(void){
    return rand() % 2;
  }

  int main(void){
    int heads_count = 0;

    for(int i = 0; i < NTOSS; ++i){
      if (toss() == HEADS)
        ++heads_count;
    }
    printf("Heads possibility = %f\n", (double)heads_count / NTOSS);
    // output -> Heads possibility = 0.500000
  }
*/

/*
  // craps game simulation
  #include <stdlib.h>

  #define    NGAMES    10000000 // 10'000'000

  int roll_dices(void);
  int game_phase1(int sum);
  int game_phase2(int sum);

  int main(void){
    int win_count = 0;
    int sum = 0;
    for(int i = 0; i < NGAMES; ++i){
      sum = roll_dices();
      win_count += game_phase1(sum);
    }

    printf("Winning possibility = %f\n", (double)win_count / NGAMES);
    // output -> Winning possibility = 0.492299
  }

  int roll_dices(void){
    int dice1 = rand() % 6 + 1;   // bad practice for professional applications
    int dice2 = rand() % 6 + 1;   // bad practice for professional applications
    return dice1 + dice2;
  }
 
  int game_phase1(int sum){
    switch (sum)
    {
    case 7:
    case 11:
      return 1;
    case 2:
    case 3:
    case 12:
      return 0;
    default:
      return game_phase2(sum);
    }
  }

  int game_phase2(int old_sum){
    int sum = 0;
    for(;;){
      sum = roll_dices();

      if (sum == old_sum)
        return 1;
      if (sum == 7)
        return 0;
    }
  }
*/

/*
  // <--- check circle_dots.png ---> 
  #include <stdlib.h>

  #define   NPOINTS   10000000  // 10'000'000

  int main(void){
    int inside_circle_count = 0;

    for(int i = 0; i < NPOINTS; ++i){
      double p_x = (double)rand() / RAND_MAX;
      double p_y = (double)rand() / RAND_MAX;


      if (p_x * p_x + p_y * p_y <= 1.0)
        ++inside_circle_count;
    }

    printf("PI = %.12f\n", 4.0 * inside_circle_count / NPOINTS);
    // output -> PI = 3.140932400000 
  }
*/