#include <stdio.h>
typedef struct Horse H;
struct Date D;
struct Date{
  int day;
  int month;
  int year;
};
struct Horse{
  struct Date dob;
  int height;
  char name[20];
  char father[20];
  char monther[20];
};

H horse;
int main(void){
  horse.dob.day=2;
  printf("%d天\n",horse.dob.day);
  return 0;
}
