#include <stdio.h>

int main(void){
  double values[5]={0.0};
  for(int i=0;i<5;++i){
    printf("  %zu",sizeof values/sizeof(double));
    printf("\n");
  }
  
 
  
}
