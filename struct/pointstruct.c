#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Horse Horse;

struct Horse{
  int age;
  int height;
  char name[20];
  char father[20];
  char monther[20];
  Horse* next;
};

int main(void){
  Horse* first = NULL;
  Horse* current = NULL;
  Horse* previous = NULL;
  char test = '\0';
  
  for(;;){
    printf("Do you want to enter details of a%s horse (Y or N)?\n",first != NULL?"nother":"");
    scanf(" %c",&test);
    
    if(tolower(test) == 'n')
      break;
    
    current = (Horse*)malloc(sizeof(Horse));
    if(first == NULL){
      first = current;
    }
    
    if(previous != NULL){
      previous->next = current;
    }
    
    printf("输入名字:\n");
    scanf("%s",current->name);
    
    printf("%s多大了？\n",current->name);
    scanf("%d",&current->age);
    
    printf("%s多高/厘米？\n",current->name);
    scanf("%d",&current->height);
    
    printf("%s的父亲名字：\n",current->name);
    scanf("%s",current->father);
    
    printf("%s的母亲名字：\n",current->name);
    scanf("%s",current->monther);
    
    current->next=NULL;
    previous = current;
  }
  printf("\n");
  current = first;
  while (current != NULL){
    printf("%s今年%d岁了，%d厘米高,",current->name,current->age,current->height);
    printf("父亲是%s，母亲是%s\n",current->father,current->monther);
    previous = current;
    current = current->next;
    free(previous);
    previous = NULL;
  }
  first = NULL;
  
  return 0;
}
