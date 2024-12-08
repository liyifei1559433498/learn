#include <stdio.h>
#include <stdlib.h>

int main(void){
  int count=10;
  double* data=calloc(count,sizeof(double));
  printf("data的地址是%p\n",(data));
  for(int i=0;i<count;++i){
    data[i]=(double)(i+1)*(i+1);
  }
  for(int i=0;i<count;++i){
    printf("第%d个元素是%f\n",i+1,*(data+i));
  }
  return 0;
}
