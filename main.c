#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpace();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


int main(){

    char winner = ' ';

    resetBoard();

    while(winner == ' ' && checkFreeSpace != 0) {
        printBoard();

        playerMove();
        winner = checkWinner();

        if(winner != ' ' || checkFreeSpace() == 0){
            break;
        }

        computerMove();
        winner = checkWinner();

        if(winner != ' ' || checkFreeSpace() == 0){
            break;
        }
    }

    printBoard();
    printWinner(winner);
    return 0;
}

void resetBoard(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
        
    }
    
}
void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpace(){
    int freeSpace = 9;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' '){
                freeSpace --;
            }
        }
        
    }
    return freeSpace;
}
void playerMove(){
    int x;
    int y;

    do{
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid move!\n");
        }else{
            board[x][y] = PLAYER;
            break;
        }

    } while (board[x][y] != ' ');
    

}
void computerMove(){
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpace() > 0){
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        
        board[x][y] = COMPUTER;
    }
    else{
        printWinner(' ');
    }
}
char checkWinner(){

    for (int row = 0; row < 3; row++) {
        if(board[row][0] == board[row][1] && board[row][0] == board[row][2]){
            return board[row][0];
        }
    }

    for (int column = 0; column < 3; column++) {
        if(board[0][column] == board[1][column] && board[0][column] == board[2][column]){
            return board[0][column];
        }
    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
            return board[0][2];
    }
    
    return ' ';
}
void printWinner(char winner){
    if(winner == PLAYER){
        printf("YOU WIN\n");
    } 
    else if(winner == COMPUTER){
        printf("YOU LOSE\n");
    }
    else{
        printf("DRAW\n");
    }
}
