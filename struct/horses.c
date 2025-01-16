#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <ctype.h>

typedef struct Horse horse;

struct Horse{
  int age;
  int height;
  char name[20];
  char father[20];
  char monther[20];
};

int main(void){
  struct Horse my_horse[50];
  int hcount=0;
  char test='\0';
  for(hcount=0;hcount<sizeof(my_horse)/sizeof(struct Horse);++hcount){
    printf("Do you want to enter details of a%s horse (Y or N)?",hcount?"nother":"");
    getchar();
    scanf("%c",&test);
    if(tolower(test)=='n'){
      break;
    }
      printf("Enter the name of the horse:");
      scanf("%s",my_horse[hcount].name);
  
      printf("How old is %s?",my_horse[hcount].name);
      scanf("%d",&my_horse[hcount].age);
  
      printf("How height is %s (in hands)?",my_horse[hcount].name);
      scanf("%d",&my_horse[hcount].height);
  
      printf("Who is %s's father?",my_horse[hcount].name);
      scanf("%s",&my_horse[hcount].father);
  
      printf("Who is %s's monther?",my_horse[hcount].name);
      scanf("%s",&my_horse[hcount].monther);
      test='n';
  }
  printf("\n");
  for(int i=0;i<hcount;++i){
    printf("%s is %d years old,%d hands high,",my_horse[i].name,my_horse[i].age,my_horse[i].height);
    printf(" and has %s and %s as parents.\n",my_horse[i].father,my_horse[i].monther);
  }
  return 0;
}

