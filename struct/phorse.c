#define __STDC_WANT_LIB_EXIT__ 1
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Horse horse;

struct Horse{
  int age;
  int height;
  char name[20];
  char father[20];
  char monther[20];
};

int main(void){
  struct Horse *phorses[50];
  int hcount = 0;
  char test = '\0';
  
  for(hcount = 0; hcount < sizeof(phorses)/sizeof(struct Horse*); ++hcount){
    printf("Do you want to enter details of a%s horse (Y or N)?",hcount?"nother":"");
    
    scanf(" %c",&test);
    getchar();
    if(tolower(test)=='n'){
      break;
    }
    phorses[hcount] = (struct Horse*) malloc(sizeof(struct Horse));
    
    printf("姓名:\n");
    //scanf("%s",phorses[hcount]->name);//此方法可行
    scanf("%s",(*phorses[hcount]).name);//此方法亦可行
    
    printf("%s的年龄：\n",phorses[hcount]->name);
    //scanf("%d",&phorses[hcount]->age);//此方法可行
    int* page=&(phorses[hcount]->age);
    scanf("%d",page);//此方法亦可行
    
    printf("%s的身高/厘米:\n",phorses[hcount]->name);
    scanf("%d",&phorses[hcount]->height);
    
    printf("%s的父亲：\n",(*phorses[hcount]).name);
    scanf("%s",phorses[hcount]->father);
    
    printf("%s的母亲：\n",phorses[hcount]->name);
    scanf("%s",phorses[hcount]->monther);
    
  }
  
  printf("\n");
  for(int i = 0;i < hcount;++i){
    printf("%s有%d岁了, 身高%dcm,",phorses[i]->name,phorses[i]->age,phorses[i]->height);
    printf("父亲是%s，母亲是%s.\n",phorses[i]->father,phorses[i]->monther);
  }
  return 0;
}
