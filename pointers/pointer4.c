#include <stdio.h>

int main(void){
  char chars[]={'a','b','b','b','b','b'};
  long multiple[]={15L,25L,35L,45L};
  long *p=multiple;
  for(int i=0;i<sizeof(multiple)/sizeof(multiple[0]);++i){
    printf("address p+%d (&multiple[%d]): %llu *(p+%d) value:%lu\n",i,i,(unsigned long long)(p+i),i,*(p+i));
    printf("\nType long occupies:%d bytes\n",(int)sizeof(long));
  }
    //printf("multiple's size is %d\n",(int)strnlen(chars,sizeof(chars)));
    printf("multiple's size is %lu\n",sizeof(chars));
    
    return 0;
}
