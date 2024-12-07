#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  char another_game='y';
  const unsigned int DELAY=1;
  bool correct=true;
  unsigned int tries=0;
  unsigned int digits=0;
  time_t seed=0;
  unsigned int number=0;
  time_t wait_start=0;
  clock_t start_time=0;
  unsigned int score=0;
  unsigned int total_digits=0;
  unsigned int game_time=0;  
  
  while(another_game == 'y')  {
    printf("\nDo you want to play again (y/n)? ");
    scanf("%c",&another_game); 
    getchar();   
  }
  return 0;
}
