#define __STOC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUF_LEN 100
#define COUNT 5

int main(void){
  char buf[BUF_LEN];
  size_t str_count=0;
  size_t capacity=COUNT;
  char** pS=calloc(capacity,sizeof(char*));
  char** psTemp=NULL;
  char* pTemp=NULL;
  size_t str_len=0;
  bool sorted=false;
  printf("Enter strings to be sorted,one per line.Press Enter to end:\n");
  
  char* ptr=NULL;
  while(true){
    ptr=fgets(buf,BUF_LEN,stdin);
    if(!ptr){
      printf("Error reading string.\n");
      free(pS);
      pS=NULL;
      return 1;   
    }
    if(*ptr=='\n')break;
  
    if(str_count==capacity){
      capacity+=capacity/4;
      if(!(psTemp=realloc(pS,capacity)))return 1;
      pS=psTemp;    
    }
    str_len=strlen(buf)+1;
    if(!(pS[str_count]=malloc(str_len))) return 2;
    strcpy(pS[str_count++],buf);
  } 
  while(!sorted){
    sorted=true;
    for(size_t i=0;i<str_count-1;++i){
      if(strcmp(pS[i],pS[i+1])>0){
        sorted=false;
        pTemp=pS[i];
        pS[i]=pS[i+1];
        pS[i+1]=pTemp;
      }
    }
  }
  
  printf("Your input sorted in ascending sequence is:\n\n");
  for(size_t i=0;i<str_count;++i){
    printf("%s",pS[i]);//因为用的是%s，输出字符串，
                       //所以这个指针内存里面的指针指向的内存，
                       //直接以字符串的形式输出
    free(pS[i]);
    pS[i]=NULL;
  }
  free(pS);
  pS=NULL;
  
  return 0;
}

