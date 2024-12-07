#include <stdio.h>
#include <string.h>

int main(void){
  char str1[]="This string contains the holy grail.";
  char str2[]="holy grail";
  char str3[]="holy grill";
  if(strstr(str1,str2)){
    printf("\"%s\" was found in \"%s\"\n",str2,str1);
  }else{
     printf("\n\"%s was not found.\n",str2);
  }
  
  if(!strstr(str1,str3)){
    printf("\"%s\" is not found in \"%s\"\n",str3,str1);
  }else{
     printf("\"%s\"is found in \"%s\"",str3,str1);
  }
  return 0;
}

