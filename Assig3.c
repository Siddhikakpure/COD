#include <stdio.h>

void display_board(char board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c",board[i][j]);
            if(j<2){
                printf(" | ");
            }
        }
        printf("\n");
        if(i<2){
            printf("...............\n");
        }
    }
}
int check_win(char board[3][3],char player){
    for(int i=0;i<3;i++){
        if((board[i][0]==player && board[i][1]==player && board[i][2]==player)|| (board[0][i]==player && board[1][i]==player && board[2][i]==player)){
            return 1;//player has won
        }
    }
    if((board[0][0]==player && board[1][1]==player && board[2][2]==player)||(board[0][2]==player && board[1][1]==player && board[2][0]==player)){
        return 1;//player has won
    }
    return 0;
}

int main(){
    char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},};
    int currentPlayer=1;
    int totalMoves=0;
    int choice;

    do{
        // display the board
        display_board(board);

        // get the current player's move
        printf("Player %d, Enter your choice(1-9):",currentPlayer);
        scanf("%d",&choice);

        int row=(choice-1)/3;
        int col=(choice-1)%3;
        // check if the chosen cell is vLID OR NOT or already taken
        if(choice>=1 && choice<=9 && board[row][col]!='X' && board[row][col]!='O'){
            board[row][col]=(currentPlayer==1)?'X':'O';
            totalMoves++;

            // check if player is won or not
            if(check_win(board,(currentPlayer==1)?'X':'O')){
                display_board(board);
                printf("Player %d wins! \n",currentPlayer);
                break;
            }
            // also check for a draw 
            if(totalMoves==9){
                display_board(board);
                printf("Its a draw\n");
                break;
            }
            // switch to other player
            currentPlayer=(currentPlayer==1)?2:1;
        }else{
            printf("Invalid move! Try again.\n");
        }
    }while(1);

    return 0;
}