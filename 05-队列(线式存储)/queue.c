//
//  queue.c
//  05-队列(线式存储)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>

void initQueue(Queue *q,int size) {
    q->_len = size;
    q->_space = (char *)malloc(sizeof(char)*q->_len);
    q->_rear = q->_front = 0;
}

int isQueueFull(Queue *q){
    // (value + 1) % 队列的长度
    return (q->_rear + 1) % q->_len == q->_front;
}

int isQueueEmpty(Queue *q){
    return  q->_front == q->_rear;
}

void enQueue(Queue *q,char ch){
    q->_space[q->_rear] = ch;
    q->_rear = ++q->_rear % q->_len;//因为是循环队列,rear往前走的时候,一定要注意是否回到起始位置
}

char deQueue(Queue *q){
    char ch = q->_space[q->_front];
    q->_front = ++q->_front % q->_len;
    return ch;
}

//复位
void resetQueue(Queue *q) {
    q->_rear = q->_front;
}

//销毁
void clearQueue(Queue *q) {
    free(q->_space);
}
