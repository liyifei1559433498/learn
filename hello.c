#include <stdio.h>
#define T 3.14159

int main(void){
printf("------------------\n");
const float Revenue_Per_150=4.5f;
short JanSold=23500;
short FebSold=19300;
short MarSold=21600;
float RevQuarter=0.0f;

unsigned long QuarterSold=JanSold+FebSold+MarSold;
printf("Stock sold in\nJan:%d\nFeb:%d\nMar:%d\n",JanSold,FebSold,MarSold);
printf("Total stock sold in first quarter:%ld\n",QuarterSold);

RevQuarter = QuarterSold/(float)150*Revenue_Per_150;
printf("Sales revenue this quarter is:$%.2f\n",RevQuarter);

char first='A';
printf("字符的值:%5c      ",first);

//--------------密封线----------------
printf("\n");
return 0;
}
