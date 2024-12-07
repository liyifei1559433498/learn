#include <stdio.h>

int main(){
  char str[][70]={
    "Computers do what you tell them to do,not what you want them todo",
    "When you put something in memory, remember where you put it.",
    "Never test for a condition you don't know what to do with."
  };
  unsigned int count=0;
  unsigned int strCount=sizeof(str)/sizeof(str[0]);
  printf("There are %u strings.\n",strCount);
  for(unsigned int i=0;i<strCount;++i){
    count=0;
    while(str[i][count]){
      ++count;
    }
    printf("The string:\n   \"%s\"\ncontains %zu characters.\n",str[i],strnlen(str[i],sizeof(str[i])));
  }
  return 0;
}
