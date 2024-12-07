#include <stdio.h>
#include <string.h>
int main(void){  
  int a=16;
  int *n=&a;
  printf("The addrss of the a:%d\n",*n);  
  
  char b='b';
  char *cb=&b;
  printf("The addrss of the b:%p,The *cb is %c\n",cb,*cb);

  char multiple[]="My string";
  char *p=&multiple[0];
  printf("The addrss of the first array element:%p\n",p);
  
  p=multiple;
  printf("The address obtained from the array name:%p\n",multiple);
  
  
  for(int i=0;i<strnlen(multiple,sizeof multiple);++i){
    printf("multiple[%d]=%c *(p+%d)=%c &multiple[%d]=%p p+%d=%p\n",i,multiple[i],i,*(p+i),i,&multiple[i],i,p+i);
  }
  return 0;
}
