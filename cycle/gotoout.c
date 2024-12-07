#include <stdio.h>

int main(void){

  for(int i=0;i<3;++i){
    for(int j=0;j<2;++j){
      for(int k=0;k<3;++k){
        if(i<2){
        printf("-------%d\n",i);
        }else{
        goto out;
        }
      }
    }
  } 
  out:printf("我在外面\n");
}
