#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 21

int main(void){
  char word1[MAX_LENGTH];
  char word2[MAX_LENGTH];
  char scan[4];
  printf("Type in the first word (maximum %d characters):",MAX_LENGTH-1);
  int retval =scanf("%s",&scan);
  if(EOF==retval){
    printf("Error reading the word.\n");
    return 888;
  }else{
     printf("%s precedes %s\n",(strcmp(word1,word2)<0)?word1:word2,(strcmp(word1,word2)<0)?word2:word1);
  }
  int countscan=0;
  while(scan[countscan]!=0){
    printf("the %d char is %c\n",countscan,scan[countscan]);
    ++countscan;
  }
  printf("word1.size is %d\n",sizeof(countscan));
  return 0;
}
