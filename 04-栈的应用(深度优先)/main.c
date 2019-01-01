//
//  main.c
//  04-栈的应用(深度优先)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>
#include "stackList.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAXROW 10
#define MAXLINE 10

Stack s;
Point prePoint[MAXROW][MAXLINE];

//1 代表墙，2 走过的路，0 代表路
int maze[MAXROW][MAXLINE] = {
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,1,1,1,1,1,1,1,
    1,1,0,1,1,1,1,1,1,1,
    1,1,0,0,0,0,1,1,1,1,
    1,1,0,1,1,0,1,1,1,1,
    1,1,0,1,1,0,1,1,1,1,
    1,1,1,1,1,0,1,1,1,1,
    1,1,1,1,1,0,0,0,1,1,
    1,1,1,1,1,1,1,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
};

void displyMaze() {
    for(int i=0; i< MAXROW; i++) {
        for(int j=0; j<MAXLINE; j++) {
            if(maze[i][j] == 1) printf("%2s"," *");
            else if(maze[i][j] == 2) printf("%2s"," #");
            else printf("%2s"," "); }
        putchar(10); }
    printf(" ====================\n");
}

void visit(int x,int y,Point prep) {
    Point p = {x,y};//当前点
    push(&s, p);
    prePoint[x][y] = prep;//把要出栈的坐标,赋值给下一个符合条件的
}

int main(int argc, const char * argv[]) {
    //定义起始点和结束点
    Point sp = {1,0},ep = {8,9};
    
    memset(prePoint,0xff,sizeof(Point)*MAXROW*MAXLINE);
    
    initStack(&s);
    push(&s, sp);
    int flage = 1;
    
    while (!isStackEmpty(&s)) {
        Point t;
        t = pop(&s);
        maze[t._x][t._y] = 2;//表示走过的路
        
        //上
        if (t._x-1 >= 0 && maze[t._x-1][t._y] != 1 && maze[t._x-1][t._y] != 2)
            visit(t._x-1, t._y,t);
        //下
        if (t._x+1 <= 9 && maze[t._x+1][t._y] != 1 && maze[t._x+1][t._y] != 2)
             visit(t._x+1, t._y,t);
        //左
        if (t._y-1 >= 0 && maze[t._x][t._y-1] != 1 && maze[t._x][t._y-1] != 2)
             visit(t._x, t._y-1,t);
        //右
        if (t._x+1 <= 9 && maze[t._x][t._y+1] != 1 && maze[t._x][t._y+1] != 2)
             visit(t._x, t._y+1,t);
        
        if (t._x == ep._x && t._y == ep._y) {
            flage = 0;
            clearStack(&s);
            break;
        }
    }
    
    if (flage) {
        printf("find no path\n");
    }else {
        printf("find path\n");
        Point t = ep;//(8,9)
        while (t._y != -1) {
            printf("(%d,%d)",t._x,t._y);//打印(8,9)
            t = prePoint[t._x][t._y];//将二维数组中(8,9)这个点的值重新赋值给t 也就是 t = (8,8).以此类推
        }
        printf("\n");
    }
    displyMaze();
    return 0;
}
