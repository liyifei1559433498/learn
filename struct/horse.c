#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

typedef struct Horse horse;

struct Horse{
  int age;
  int height;
  char name[20];
  char father[20];
  char monther[20];
};

int main(void){
  struct Horse my_horse;
  
  printf("Enter the name of the horse:");
  scanf("%s",my_horse.name);
  
  printf("How old is %s?",my_horse.name);
  scanf("%d",&my_horse.age);
  
  printf("How height is %s (in hands)?",my_horse.name);
  scanf("%d",&my_horse.height);
  
  printf("Who is %s's father?",my_horse.name);
  scanf("%s",&my_horse.father);
  
  printf("Who is %s's monther?",my_horse.name);
  scanf("%s",&my_horse.monther);
  
  printf("%s is %d years old,%d hands height,",my_horse.name,my_horse.age,my_horse.height);
  printf(" and has %s and %s parents.\n",my_horse.father,my_horse.monther);
  return 0;
}

