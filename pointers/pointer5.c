#include <stdio.h>

int main(void){
  char board[3][3]={
                     {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'},
                   };
  char charss[][4]={
                     {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'},
                   };
  char *pboard=*board;
  for(int i=0;i<9;++i){
    printf("the values is %c\n",*(pboard+i));
  }
  printf("size of board:%ld\n",sizeof(charss)/sizeof(char));
  printf("address of board:%p\n",board);
  printf("address of board[0][0]:%p\n",&board[0][0]);
  printf("value of board[0]:%p\n",board[0]);
  
  printf("value of board[0][0]:%c\n",board[0][0]);
  printf("value of *board[0]:%c\n",*board[0]);
  printf("value of **board:%c\n",**board);
  printf("value of *board:%p\n",*board);
  
  for(int i=0;i<9;++i){
    printf("the value of board[%d][%d] is %p.\n",(i)/3,i%3,&board[i/3][i%3]);
  }
  return 0;
}
