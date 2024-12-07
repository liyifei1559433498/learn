#include <stdio.h>

int main(void){
  int grades[10];
  int grade=0;
  unsigned int count=10;
  long sum=0;
  float average=0.0f;
  printf("Enter a grade: \n");
  for(unsigned int i=0;i<count;++i){
  
    printf("%-2u> ",i+1);
    scanf("%d>",&grades[i]);
    sum+=grades[i];
  }
  average=(float)sum/count;
  for (unsigned int i=0;i<count;++i){
    printf("\nGrade Number %-2u is %-3d",i+1,grades[i]);
  }
  printf("\nAverage of the ten grades entered is:%.2f\n",average);
  
  return 0;

}
