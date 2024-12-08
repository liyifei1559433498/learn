#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CAP_INCR 10

int main(void){
  unsigned long long *pPrimes=NULL;
  bool found =false;
  unsigned long long limit=0LL;
  int count=0;
  printf("输入你想要的质数个数：");
  scanf("%llu",&limit);
  
  size_t capacity=10;
  pPrimes=calloc(capacity,sizeof(unsigned long long));
  if(!pPrimes){
    printf("我怕内存不足");
    return 1;
  }
  
  *pPrimes=2ULL;
  *(pPrimes +1)=3ULL;
  *(pPrimes+2)=5ULL;
  count=3;
  
  unsigned long long trial=*(pPrimes+2)+2ULL;
  unsigned long long *pTemp=NULL;
  while(count<limit){
    for(int i=1;i<count;++i){
      if(!(found=(trial%*(pPrimes+i)))){
        break;
      }
    }
    if(found){
      if(count==capacity){
        capacity+=CAP_INCR;
        pTemp=realloc(pPrimes,capacity*sizeof(unsigned long long));
        if(!pTemp){
          printf("不好，分配内存失败");
          free(pPrimes);
          pPrimes=NULL;
          return 2;
        }
        pPrimes=pTemp;
      }
      *(pPrimes+count++)=trial;    
    }
    trial+=2ULL;
  }
  printf("%llu内存里找到了%d个素数:\n",limit,count);
  for(int i=0;i<count;++i){
    printf("%12llu",*(pPrimes+i));
    if(!(i+1)%5){
      printf("\n");
    }
  }
  printf("\n");
  free(pPrimes);
  pPrimes=NULL;
  return 0;
}
