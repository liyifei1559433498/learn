#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BUF_LEN 100
#define COUNT 10
/**用指针实现输入不限个数的浮点数，并求其平均值*/
int main(void){
  char buf[BUF_LEN]={};
  char* ptr;
  size_t capacity=COUNT;
  size_t str_count=0;
  size_t str_len=0;
  char** pS=calloc(capacity,sizeof(char*));//字符串指针的指针。动态分配内存，完成后生成内存数组。
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
    haveDot=false;//记录是否已有小数点。
    for(int j=0;j<sizeof(buf);++j){
      
      if(buf[j]=='.'){//检测到小数点。
        if(haveDot){//如果已有小数点，报错并结束当前程序。
          printf("您输入了一个非浮点数");
          return 5;
        }
        haveDot=true;//当前已有小数点。
      }else if(buf[j]<'0'||buf[j]>'9'){//如果字符不在0-9范围之内。
        //printf("您输入的是%c",buf[j]);
        if(buf[j]!='\0'&&buf[j]!=10&&buf[j]!=4){//如果不是结尾('\0'),换行(10),传输结束(4)。
          printf("您输入的字符包含了非数字%c",buf[j]);
          return 4; 
        }
      }
    }

    if(*ptr=='\n'){//检测到输入的是enter，表明结束此次输入。
      break;
    }
    if(str_count==capacity){//如果存放字符串的数组长度已与容量相同，扩充容量。
      capacity+=capacity/4;//扩充1/4
      if(!(psTemp=realloc(pS,capacity))) return 2;//扩充pS内存并存储pS，产生的指针先给psTemp，
      pS=psTemp;//成功之后给pS。
    }
    
    str_len=strnlen(buf,BUF_LEN)+1;//字符串长度，记得要+1,因为有'\0'。
    if(!(pS[str_count]=malloc(str_len))) return 3;//为最后的字符串分配内存，返回的指针放pS里。
    strcpy(pS[str_count++],buf);//将字符串给当前的指针，记得str_count++，因为或许还有输入。

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
    for(int j=0;j<sizeof(pTemp);++j){//遍历字符串数组，
       if(pTemp[j]=='.'){//如果有小数点，说明此后就是小数部分。
         isBig=false;//将标志改为false，说明不是整数部分了。
         continue;//小数点不参与运算。
       }
       if(pTemp[j]>='0'&&pTemp[j]<='9'){//字符在'0'-'9'的范围内。
     
         if(isBig){//此字符在整数部分。
           big_temp=big_temp*10+(pTemp[j]-'0');//字符转换为数字要减掉对应的ASCII码大小。
         }else{//此字符在小数部分。
           sml_d=sml_d*10;
           sml_temp=sml_temp+(pTemp[j]-'0')/sml_d;
         }       
       }
       fTmpin=big_temp+sml_temp;//完成此条数据的转换。
    }
    fTmp+=fTmpin;//加一起。
  } 
    printf("平均数是%f\n",fTmp/str_count);//算平均数。
    printf("\n");
  for(size_t i=0;i<str_count;++i){//释放指针指向的内存，也就是每一个字符串的内存。
    free(pS[i]);
    pS[i]=NULL;
  }
  free(pS);//释放指针的指针的内存。
  pS=NULL;
  return 0;
}
