#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main(void){
  int player=0;
  int winner=0;
  int choice=0;
  char ctemp;
  char stemp[]={};
  unsigned int row=0;
  unsigned int column=0;
  bool inputright=true;
  bool isover=false;
  char board[3][3]={
                  {'1','2','3'},
                  {'4','5','6'},
                  {'7','8','9'}
                  };
  for(unsigned int i=0;i<9&&winner==0;++i){
    
    player=i%2+1;
    printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
    printf("---+---+---\n");

      do{

        if(inputright){ 
          if(isover){
            printf("玩家 %d ,此位置已有占用，请重新选择合适的位置输入 %c ",player,(player==1)?'X':'O');
          }else{
            printf("玩家 %d ,请在合适的位置输入 %c ",player,(player==1)?'X':'O');
          }
        }else{
          printf("玩家 %d ,您输入错了，请重新在合适的位置输入 %c ",player,(player==1)?'X':'O');
        }
        getchar();
        
        scanf("%c",&ctemp);
        //printf("-----------ctempsize=%c\n",ctemp);
        printf("-----------ctemp=%s\n",ctemp);
        if(sizeof(stemp)>2){
        
        }
        if(ctemp<49||ctemp>57){//不在0-9范围之内
          choice=0;
          ctemp=-1;
          //--i;
          inputright=false;
          //continue;
          }else{
          choice=ctemp-48;        
          row=--choice/3;
          column=choice%3;
          inputright=true;
          isover=false;
        }
        if(board[row][column]>'9'){
          isover=true;
        }
      getchar();
      }while(choice<0||choice>8||board[row][column]>'9'||inputright==false); 
      
      if(inputright){
        board[row][column]=(player==1)?'X':'O';
      }
    if((board[0][0]==board[1][1]&&board[0][0]==board[2][2])||
       (board[0][2]==board[1][1]&&board[0][2]==board[2][0])    
    ){
      winner=player;
    }else{
       for(unsigned int line=0;line<2;++line){
         if(board[line][0]==board[line][1]&&board[line][0]==board[line][2]||
            board[0][line]==board[1][line]&&board[0][line]==board[2][line]
         ){
           winner=player;
         }
       }
    }
  } 
    printf("\n");
    printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
    printf("---+---+---\n");
    if(winner){
      printf("\n%d，你赢了\n",player);
    }else{
      printf("真没意思，平局\n");
    }
  return 0;
}
