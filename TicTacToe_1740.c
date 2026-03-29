/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : Tic tac toe bot
Online reference:
1. For the winning strategy (win > block > center > corner > side), I referred to this website:
https://www.esportsheaven.com/features/the-unbeatable-tic-tac-toe-strategy-never-lose-again/

2. To learn how to create a function that handles multiple variables, I took assistance from ChatGPT and used a while loop in my implementation.
*/

#include <stdio.h>

void printBoard(char a, char b, char c, char d, char e, char f, char g, char h, char i) {
    printf("\n\tCurrent Board\n\t %c | %c | %c \n\t-----------\n\t %c | %c | %c \n\t-----------\n\t %c | %c | %c \n\t\n", a,b,c,d,e,f,g,h,i);
}

int isEmpty(char a, char b, char c, char d, char e, char f, char g, char h, char i, char pos) {
    if (pos == '1') return (a != 'X' && a != 'O');
    if (pos == '2') return (b != 'X' && b != 'O');
    if (pos == '3') return (c != 'X' && c != 'O');      //check if position pos ('1'-'9') is empty (not 'X' or 'O')
    if (pos == '4') return (d != 'X' && d != 'O');
    if (pos == '5') return (e != 'X' && e != 'O');
    if (pos == '6') return (f != 'X' && f != 'O');
    if (pos == '7') return (g != 'X' && g != 'O');
    if (pos == '8') return (h != 'X' && h != 'O');
    if (pos == '9') return (i != 'X' && i != 'O');
    return 0;
}

char updateCell(char current, char pos, char player){
    if (pos == current) return player;                      //update the cell for position (pos to player) mark (X or O)
    return current;
}

int checkWin(char a, char b, char c, char d, char e, char f, char g, char h, char i, char p) {
    if ((a == p && b == p && c == p) ||
        (d == p && e == p && f == p) ||
        (g == p && h == p && i == p) ||         //Check if player p won
        (a == p && d == p && g == p) ||                     //O  OR  X
        (b == p && e == p && h == p) ||
        (c == p && f == p && i == p) ||
        (a == p && e == p && i == p) ||
        (c == p && e == p && g == p))
        return 1;
    return 0;
}

char findWinningMove(char a, char b, char c, char d, char e, char f, char g, char h, char i, char p){
    char pos;                           //check every cell to see if placing p there would result in a win.
    for (pos = '1';pos <= '9'; pos++){
        if (isEmpty(a,b,c,d,e,f,g,h,i,pos)){
            char ta = updateCell(a, pos, p);
            char tb = updateCell(b, pos, p);
            char tc = updateCell(c, pos, p);
            char td = updateCell(d, pos, p);
            char te = updateCell(e, pos, p);
            char tf = updateCell(f, pos, p);
            char tg = updateCell(g, pos, p);
            char th = updateCell(h, pos, p);
            char ti = updateCell(i, pos, p);

            if (checkWin(ta,tb,tc,td,te,tf,tg,th,ti,p)) 
                return pos;
        }
    }
    return '0';
}

char botMove(char a, char b, char c, char d, char e, char f, char g, char h, char i){
    char move;                                         //win>block >center>corner>side
    move = findWinningMove(a,b,c,d,e,f,g,h,i,'O');//win
    if (move != '0') return move;

    move = findWinningMove(a,b,c,d,e,f,g,h,i,'X');//block
    if (move != '0') return move;

    if (isEmpty(a,b,c,d,e,f,g,h,i,'5')) return '5';//center

    if (isEmpty(a,b,c,d,e,f,g,h,i,'1')) return '1';//corner
    if (isEmpty(a,b,c,d,e,f,g,h,i,'3')) return '3';
    if (isEmpty(a,b,c,d,e,f,g,h,i,'7')) return '7';
    if (isEmpty(a,b,c,d,e,f,g,h,i,'9')) return '9';//corner

    if (isEmpty(a,b,c,d,e,f,g,h,i,'2')) return '2';//side
    if (isEmpty(a,b,c,d,e,f,g,h,i,'4')) return '4';
    if (isEmpty(a,b,c,d,e,f,g,h,i,'6')) return '6';
    if (isEmpty(a,b,c,d,e,f,g,h,i,'8')) return '8';//side
    return '0';//no possible move
}

int main(){
    char a='1',b='2',c='3',d='4',e='5',f='6',g='7',h='8',i='9',playerMove,computerMove;
    
    printf("Welcome to Tic Tac Toe!\nYou are X(1), computer is O(0).\n");
    
    int t;
    printf("Enter 1 if you want to play first, 0 if computer should start: ");
    scanf("%d", &t);

    int turn=t;
    while (1){
        if(turn>0){ // player first
            printBoard(a,b,c,d,e,f,g,h,i);
            printf("Enter your move (1-9): ");
            scanf(" %c", &playerMove);

            while (!isEmpty(a,b,c,d,e,f,g,h,i,playerMove)){
                printf("Invalid move! Cell taken or wrong input. Enter again (1-9): ");//if cell is not empty then invalid
                scanf(" %c", &playerMove);
            }
            a = updateCell(a, playerMove, 'X');
            b = updateCell(b, playerMove, 'X');
            c = updateCell(c, playerMove, 'X');
            d = updateCell(d, playerMove, 'X');
            e = updateCell(e, playerMove, 'X');
            f = updateCell(f, playerMove, 'X');
            g = updateCell(g, playerMove, 'X');
            h = updateCell(h, playerMove, 'X');
            i = updateCell(i, playerMove, 'X');

            if (checkWin(a,b,c,d,e,f,g,h,i,'X')){
                printBoard(a,b,c,d,e,f,g,h,i);
                printf("Congratulations! You win!\n");
                break;
            }
            if (turn == 5){
                printBoard(a,b,c,d,e,f,g,h,i);
                printf("It's a draw!\n");
                break;
            }
        }
        if(turn>=0){ // computer plays
            turn++;
            computerMove= botMove(a,b,c,d,e,f,g,h,i);
            printf("Computer moves at position %c\n", computerMove);
            a = updateCell(a, computerMove, 'O');
            b = updateCell(b, computerMove, 'O');
            c = updateCell(c, computerMove, 'O');
            d = updateCell(d, computerMove, 'O');
            e = updateCell(e, computerMove, 'O');
            f = updateCell(f, computerMove, 'O');
            g = updateCell(g, computerMove, 'O');
            h = updateCell(h, computerMove, 'O');
            i = updateCell(i, computerMove, 'O');
            if (checkWin(a,b,c,d,e,f,g,h,i,'O')) {
                printBoard(a,b,c,d,e,f,g,h,i);
                printf("Computer wins! Better luck next time🤪🤪\n");
                break;
            }
            if (turn == 5){
                printBoard(a,b,c,d,e,f,g,h,i);
                printf("It's a draw!\n");
                break;
            }
        }
    }
    return 0;
}