//
//  stackList.h
//  03-栈(链)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#ifndef stackList_h
#define stackList_h

#include <stdbool.h>
#include <stdio.h>

typedef struct _Node {
    char data;
    struct _Node *next;
}Node;

typedef struct _Stack {
    Node *top;
}Stack;

//初始化
void initStack(Stack *s);

//栈是否空
bool isStackEmpty(Stack *s);

//压栈
void push(Stack *s,char ch);

//出栈
char pop(Stack *s);

//复位
void resetStack(Stack *s);

//销毁
void clearStack(Stack *s);

#endif /* stackList_h */
