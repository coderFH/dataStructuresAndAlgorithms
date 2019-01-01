//
//  stack.h
//  02-栈
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdbool.h>

typedef struct _TreeNode {
    int _data;
    struct _TreeNode *_left;
    struct _TreeNode *_right;
}TreeNode;

typedef struct _Stack {
    int _len;
    int _top;//始终指向待压入的位置
    TreeNode **_space;
}Stack;

//初始化
void initStack(Stack *s,int size);

//栈是否满
bool isStackFull(Stack *s);

//栈是否空
bool isStackEmpty(Stack *s);

//压栈
void push(Stack *s,TreeNode *ch);

//出栈
TreeNode* pop(Stack *s);

//复位
void resetStack(Stack *s);

//销毁
void clearStack(Stack *s);

#endif /* stack_h */
