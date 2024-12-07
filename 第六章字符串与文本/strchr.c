#include <stdio.h>
#include <string.h>

int main(void){
  char str[]="Peter piper picked a peck of pickled pepper.";
  char ch='p';
  char *pGot_char=str;
  int count =0;
  while(pGot_char=strchr(pGot_char,ch)){
    ++count;
    ++pGot_char;
  }
  printf("The character '%c' was found %d times in the following string:\n\"%s\"\n",ch,count,str);
}
