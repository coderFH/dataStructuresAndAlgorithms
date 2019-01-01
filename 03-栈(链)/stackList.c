//
//  stackList.c
//  03-栈(链)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include "stackList.h"
#include <stdlib.h>

void initStack(Stack *s){
    s->top = (Node *)malloc(sizeof(Node));
    s->top->next = NULL;
}

//栈是否空
bool isStackEmpty(Stack *s){
    return  s->top->next == NULL;
}

//压栈
void push(Stack *s,char ch){
    Node *cur = (Node *)malloc(sizeof(Node));
    cur->data = ch;
    cur->next = s->top->next;
    s->top->next = cur;
}

//出栈
char pop(Stack *s){
    Node *t = s->top->next;
    char ch = t->data;
    s->top->next = t->next;
    free(t);
    return ch;
}

//复位
void resetStack(Stack *s) {
    while (!isStackEmpty(s)) {
        pop(s);
    }
}

//销毁
void clearStack(Stack *s) {
    resetStack(s);
    free(s->top);
}

