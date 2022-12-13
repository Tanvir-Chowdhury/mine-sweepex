#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

void game_init(int game[][10]){
    for(int i=0; i<10; i++){
        for(int j=0;j<10; j++){
            srand(time(0));
            if ((i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2))||(i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2))||(i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2))||(i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2))||(i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2))||(i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2))|| (i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2)) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2))) || (i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2)) || ((i==abs(rand()%10 - 2) ) && j==abs(rand()%10 - 2)) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) )) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) )) || (i==abs(rand()%10 - 2) && j==abs(rand()%10 - 2)) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) )) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) )) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) )) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) )) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) ))|| (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) )) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) )) || (i==abs(rand()%10 - 2) && (j==abs(rand()%10 - 2) ))){
                game[i][j] = 2;
            }
            else{
                game[i][j] = 0;
            }
        }
    }
    game[9][9] = 5;
}

void game_play(int game[][10]){
    system("cls");
    for (int i=0; i<10; i++){
        for(int j=0;j<10; j++){
            if(game[i][j]==5){
                printf("|");
                //printf("\033[0;31m");
                printf(" D ");
                //printf("\033[0m");
            }
            else if(game[i][j]==1){
                printf("|");
                //printf("\033[0;32m");
                printf(" Y ");
                //printf("\033[0m");
            }
            else{
                printf("|   ");
            }
        }
        printf("\n---------------------------------------\n");
    }
    printf("\nup -> w, down -> s, right -> d, left -> a\n");
}

void game_over(int game[][10]){
    //clrscr();
    system("cls");
    for (int i=0; i<10; i++){
        for(int j=0;j<10; j++){
            if(game[i][j]==5){
                printf("|");
                //printf("\033[0;31m");
                printf(" D ");
                //printf("\033[0m");
            }
            else if(game[i][j]==1){
                printf("|");
                //printf("\033[0;35m");
                printf(" Y ");
                //printf("\033[0m");
            }
            else if(game[i][j]==2){
                printf("|");
                //printf("\033[0;33m");
                printf(" B ");
                //printf("\033[0m");
            }
            else{
                printf("|   ");
            }
        }
        printf("\n---------------------------------------\n");
    }
    system("color 34");
    printf("GAME OVER\n");
    printf("You have encountered a bomb.\n");
    Beep(750, 700);
    //printf("\a");
}

void game_win(int game[][10]){
    //clrscr();
    system("cls");
    for (int i=0; i<10; i++){
        for(int j=0;j<10; j++){
            if(game[i][j]==1){
                printf("|");
                //printf("\033[0;36m");
                printf(" Y ");
                //printf("\033[0m");
            }
            else{
                printf("|   ");
            }
        }
        printf("\n---------------------------------------\n");
    }
    system("color 32");
    printf("Congratulations! You have won.\n");
    printf("You have successfully reached the destination.\n");
    Beep(750, 400);
    Beep(750, 400);
    Beep(750, 400);
    //printf("\a\a\a\a\a\a\a\a\a\a\a");
}

int main()
{
    system("color 3F");
    int game[10][10], a=0, b=0;
    game_init(game);
    game[a][b] = 1;
    //printf("This is the game board: \n");
    for (int i=0; i<10; i++){
        for(int j=0;j<10; j++){
            if(game[i][j]==5){
                printf("|");
                //printf("\033[0;31m");
                printf(" D ");
                //printf("\033[0m");
            }
            else if(game[i][j]==1){
                printf("|");
                //printf("\033[0;32m");
                printf(" Y ");
                //printf("\033[0m");
            }
            else{
                printf("|   ");
            }
        }
        printf("\n---------------------------------------\n");
    }
    //printf("Rules: \n");
    //printf("1.Y means your position.\n2.D means your destination.\n3.There are bombs in several places.\n4.Press w to go up, s to go down, d to go right, a to go left.\n");
    printf("\nup -> w, down -> s, right -> d, left -> a\n");

    while(1){
        char ch;
        //printf("\nEnter your direction: ");
        ch = getchar();
        getchar();
        switch(ch){
            case 'w':
                if(a-1<0){
                    printf("Invalid direction");
                }
                else if(game[a-1][b]==5){
                    game[a][b]=0;
                    a = a-1;
                    game[a][b] = 1;
                    game_win(game);
                    return 0;
                }
                else if(game[a-1][b]==2){
                    game[a][b]=0;
                    a = a-1;
                    game[a][b] = 1;
                    game_over(game);
                    return 0;
                }
                else{
                    game[a][b]=0;
                    a = a-1;
                    game[a][b] = 1;
                    game_play(game);
                }
                break;
            case 's':
                if(a+1>9){
                    printf("Invalid direction");
                }
                else if(game[a+1][b]==5){
                    game[a][b]=0;
                    a = a+1;
                    game[a][b] = 1;
                    game_win(game);
                    return 0;
                }
                else if(game[a+1][b]==2){
                    game[a][b]=0;
                    a = a+1;
                    game[a][b] = 1;
                    game_over(game);
                    return 0;
                }
                else{
                    game[a][b]=0;
                    a = a+1;
                    game[a][b] = 1;
                    game_play(game);
                }
                break;
            case 'a':
                if(b-1<0){
                    printf("Invalid direction");
                }
                else if(game[a][b-1]==5){
                    game[a][b]=0;
                    b = b-1;
                    game[a][b] = 1;
                    game_win(game);
                    return 0;
                }
                else if(game[a][b-1]==2){
                    game[a][b]=0;
                    b = b-1;
                    game[a][b] = 1;
                    game_over(game);
                    return 0;
                }
                else{
                    game[a][b]=0;
                    b = b-1;
                    game[a][b] = 1;
                    game_play(game);
                }
                break;
            case 'd':
                if(b+1>9){
                    printf("Invalid direction");
                }
                else if(game[a][b+1]==5){
                    game[a][b]=0;
                    b = b+1;
                    game[a][b] = 1;
                    game_win(game);
                    return 0;
                }
                else if(game[a][b+1]==2){
                    game[a][b]=0;
                    b = b+1;
                    game[a][b] = 1;
                    game_over(game);
                    return 0;
                }
                else{
                    game[a][b]=0;
                    b = b+1;
                    game[a][b] = 1;
                    game_play(game);
                }
                break;
            default:
                printf("Invalid direction");
                break;
        }
    }
    return 0;
}
