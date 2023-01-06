#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define size 26

int score = 0, posX = 13, posY = 13,posx = 13, posy = 13, gameOver = 0;//PosX and PosY are cordinates of snake and posx and posy are cordinates of fruit
char board[size][size];

char getch(void);
void set_board();
void fruit();
void print();
void game_over();
void check();
void input();

int main(){
    while(1){
        check();
        set_board();
        print();
        input();
        game_over();
        system("clear");
    }
    return 0;
}

void set_board(){
    //to set board and update boundary, fruit and  snake
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if( row == 0 || row == size-1 || col == 0 || col == size-1){
                board[row][col] = '#';
            }
            else{
                board[row][col] = ' ';
            }
        }
    }
    board[posX][posY] = '0';
    board[posx][posy] = '@';
}

void fruit(){
    //to spawn new fruit 
    int row = 13 ,col = 13;
    srand(time(NULL));
    posx =  rand()%26;
    posy = rand()%26;
}

void print(){
    //to print the 2-d array
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            printf("%c",board[row][col]);
        }
        printf("\n");
    }
    printf("Press X to exit game\n");
}

void game_over(){
    //To check if snake has touch the boundary or user have press x, if yes exit the program
    if(board[posX][posY] == '#' || gameOver){
        printf("Your Score is %d\n", --score);
        exit(0);
    }
}

void check(){
    //to check if snake have ate the fruit yet or not and if snake has eaten the fruit then call fruit function to spawn new food
    if(posX == posx && posY == posy){
        score++;
        fruit();
    }
    return;
}

void input(){
    //To act according ot user input
    switch(getch()){
        case 'w':
            posX--;
            break;
        case 's':
            posX++;
            break;
        case 'a':
            posY--;
            break;
        case 'd':
            posY++;
            break;
        case 'x':
            gameOver = 1;
        }
}

char getch(void){
    //This Function is copied from stack overflow as linux don't provide conio.h and i don't have enough skills to make it myself
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}