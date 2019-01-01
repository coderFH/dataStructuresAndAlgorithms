//
//  stack.c
//  02-栈
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>

//初始化
void initStack(Stack *s,int size) {
    s->_top = 0;
    s->_len = size;
    s->_space = (char *)malloc(sizeof(char)*s->_len);
}

//栈是否满
bool isStackFull(Stack *s){
    if(s->_top == s->_len)
        return true;
    else  return false;
}

//栈是否空
bool isStackEmpty(Stack *s){
    return s->_top == 0;
}

//压栈
void push(Stack *s,char ch){
    s->_space[s->_top++]=ch;
}

//出栈
char pop(Stack *s){
    return s->_space[--s->_top];
}

//复位
void resetStack(Stack *s) {
    s->_top = 0;
}

//销毁
void clearStack(Stack *s) {
    free(s->_space);
}
