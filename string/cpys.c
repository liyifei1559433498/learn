#include <stdio.h>

int main(void){
  char source[]="Only the mediocre are always at their best.";
  char destination[50];
  if(strcpy(destination,source)){
    printf("An error occurred copying the string:\n");
  }
}
