#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int i, j, height=20, width=20;
int gameOver, score;
int x, y, fruitx, fruity, flag;

void setup() {
    gameOver = 0;
// store the height and width;
    x = height/2;
    y = width/2;

    label1:
    fruitx = rand()%20;
     if(fruitx == 0) 
         goto label1;
     

     label2: 
     fruity = rand()%20;
      if(fruity == 0) 
          goto label2;
        score = 0;
      
}

//function to draw the boundaries

void draw() {
    system("clear");// clear the screen

    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            if((i == 0) || (i ==  width -1 )|| (j==0 )|| (j == height -1)) {
                cout<<"#";
            }
            else {
                if( i == x && j == y)
                cout<<"0";
                else if( i == fruitx && j == fruity)
                cout<<"*";
                else
                cout<<" ";
            }
        }
        cout<<endl;
    }
   // create a score board
   cout<<"Score = "<<score<<endl;
   cout<<"Press X to qiut the Game";
}

//create function to take input from the user

void input() {
    if(kbhit()) {
        switch (getch()) 
        {
        case 'a': 
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}
//create function for snake movements

void logic() {
    sleep(10);
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    } 
    //if the game is over
    if( x < 0 || x > height || y < 0 || y > width)
    gameOver = 1;

    if( x == fruitx && y == fruity) {
    label3:
        fruitx = rand()%20;
        if(fruitx == 0)
            goto label3;

    //After eating the above fruit 
    //generate the new fruit

    label4:
        fruity = rand()%20;
        if(fruity == 0) 
            goto label4;
        score+=10;
    }

}

// To drive the code above 
int main() {
    int m,n;
    setup();
    //function call
    while (!gameOver) 
    {
       draw();
       input();
       logic();
    }
    return 0;
}

