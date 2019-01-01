//
//  queue.h
//  06-队列(链式存储)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

typedef struct _Node {
    char data;
    struct _Node *next;
}Node;

typedef struct _Queue {
    Node *front;
    Node *rear;
}Queue;

//初始化
void initQueue(Queue *q);

//是否空
int isQueueEmpty(Queue *q);

//插入
void enQueue(Queue *q,char ch);

//删除
char deQueue(Queue *q);

//复位
void resetQueue(Queue *q);

//销毁
void clearQueue(Queue *q);

#endif /* queue_h */
