#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BUF_LEN 100
#define COUNT 10
int main(void){
  char buf[BUF_LEN]={};
  char* ptr;
  size_t capacity=COUNT;
  size_t str_count=0;
  size_t str_len=0;
  char** pS=calloc(capacity,sizeof(char*));
  char** psTemp=NULL;
  char* pTemp=NULL;
  bool haveDot=false;
  printf("输入浮点数，按回车结束\n");
  while(true){
    ptr=fgets(buf,BUF_LEN,stdin);
    if(!ptr){
      printf("错误");
      return 1;
    }
    haveDot=false;
    for(int j=0;j<sizeof(buf);++j){
      
      if(buf[j]=='.'){
        if(haveDot){
          printf("您输入了一个非浮点数");
          return 5;
        }
        haveDot=true;
      }else if(buf[j]<'0'||buf[j]>'9'){
        //printf("您输入的是%c",buf[j]);
        if(buf[j]!='\0'&&buf[j]!=10&&buf[j]!=4){//如果不是结尾（'\0'）,换行（10）,传输结束（4）
          printf("您输入的字符包含了非数字%c",buf[j]);
          return 4; 
        }
      }
    }

    if(*ptr=='\n'){
      break;
    }
    if(str_count==capacity){
      capacity+=capacity/4;
      if(!(psTemp=realloc(pS,capacity))) return 2;
      pS=psTemp;
    }
    
    str_len=strnlen(buf,BUF_LEN)+1;
    if(!(pS[str_count]=malloc(str_len))) return 3;
    strcpy(pS[str_count++],buf);

  }
  float fTmp=0.0f;
  for(int i=0;i<str_count;++i){
    float big_temp=0.0f;
    float sml_temp=0.0f;
    float sml_d=1.0f;
    bool isBig=true;
    int ten=10;
    float fTmpin=0.0f;
  
    pTemp=pS[i];
    for(int j=0;j<sizeof(pTemp);++j){
       if(pTemp[j]=='.'){
         isBig=false;
         continue;
       }
       if(pTemp[j]>='0'&&pTemp[j]<='9'){
     
         if(isBig){
           big_temp=big_temp*10+(pTemp[j]-'0');
         }else{
           sml_d=sml_d*10;
           sml_temp=sml_temp+(pTemp[j]-'0')/sml_d;
         }       
       }
       fTmpin=big_temp+sml_temp;
    }
    fTmp+=fTmpin;
  } 
    printf("平均数是%f\n",fTmp/str_count);
    printf("\n");
  
  return 0;
}
