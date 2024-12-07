#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>

int main(void){
  char preamble[]="The joke is:\n\n";
  char str[][40]={
    "My dog hasn\'t get any nose",
    "How does your dog smell then?\n",
    "My dog smells horrible.\n"
  };
  unsigned int strCount=sizeof(str)/sizeof(str[0]);
  unsigned int length=0;
  for(unsigned int i=0;i<strCount;++i){
    length+=strnlen(str[i],sizeof (str[i]));
  }
  
  char joke[length+strlen(preamble)+1];
  if(strcpy(joke,preamble)){
    
  }

  return 0;
}
