#include <stdio.h>

int main(void){
  int choice =0;
  printf("Pick a number between 1 and 10 you may win a prize!\n");
  scanf("%d",&choice);
  
  if((choice>10)||(choice<1)){
    choice=11;
  }
  
  switch(choice){
    case 7:
      printf("Congratulations!\n");
      break;
    
    case 2:
      printf("You win the folding thermometer-pen-watch-umbrella.\n");
      break;
    
    default:
      printf("Sorry,you lose.\n");
    }
    return 0;
}
