#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
/*理解指针的试验
 *牵涉到数组
 **/
int main(void){
  char** pp=calloc(5,sizeof(char*));
  int ints[6]={1,2,3,4,5,6};
  char* pChar=NULL;
  char string[5]={'8','9','a','b','c'};
  char chars[]={'1','3','2'};
  char* cp=&chars[0];
  //char charss[5][4]={"1111","2222","3333","4444","5555"};//声明方式一
  char charss[5][4]={
                     {'1','1','1','1'},
                     {'2','2','2','2'},
                     {'3','3','3','3'},
                     {'4','4','4','4'},
                     {'a','a','a','a'}
                     };//和声明方式一等效
                     
  for(int i=0;i<5;++i){
    pp[i]=charss[i];//等效于*(pp+i)=charss[i];
  }
  //string="12345568";//此种赋值会报错。
  for(int i=0;i<5;++i){
  /**如果charss的长度为[5][4],就会打印如下。
   *第1个是11112222333344445555
   *第2个是2222333344445555
   *第3个是333344445555
   *第4个是44445555
   *第5个是5555
   *由此得出推论一，
   *“如果，二维数组charss子数组长度(也就是字符串实际元素长度)==声明子数组元素长度，
   *且最后一个元素不为'\0'，0
   *会自动转为char数组，若转以string打印，将不再限制长度，将其之后的字符全部取出，故而，
   *其余对应如下
   *第2个元素--->2222333344445555
   *第3个元素--->333344445555
   *第4个元素--->44445555
   *第5个元素--->5555”
   */
    printf( "第%d个子char数组的第一个元素是%c\n",i+1,*pp[i]);
    printf( "第%d个string是%s\n",i+1,pp[i]);
  }
  printf("charss数组的第%d个元素转换为字符串：%s\n",2,pp[1]);
  printf( "chars数组的第%d个是%c\n",2,*(cp+1)); //虽然cp是数组chars的第一个元素的指针，
                                              //但是，仍然可以此查找到第二个元素。
                                              //以此推论，数组也是开辟出一块连续的内存空间。
  printf("string：%s\n",charss[2]);//打印出
                                   //33334444aaaa
                                   //得证推论一
  /*如果不加强转符号
   *就会如下警报
   *initialization of ‘char *’ from incompatible pointer type ‘char (*)[5]’
   */
  char* ps=(char*)&string;
  printf("验证指针：%s\n",ps);
  return 0;
}
