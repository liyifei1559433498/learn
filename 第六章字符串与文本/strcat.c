#include <stdio.h>
#include <string.h>

int main(void){
  char str1[]="To be,or not to be,";
  char str2[]="that is the question.";
  int retval = strcat(str1,str2);//报错了
  if(retval){
    printf("There was an error joining the strings,Error code=%d\n",retval);//走到了这里
  }else{
     printf("The combined strings:\n%s\n",str1);
  }
  
}
