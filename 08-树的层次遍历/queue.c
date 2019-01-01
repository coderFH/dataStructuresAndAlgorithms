//
//  queue.c
//  06-队列(链式存储)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>
//初始化
void initQueue(Queue *q){
    q->front = q->rear = (Node *)malloc(sizeof(Node));
    q->front->next = NULL;
}

//是否空
int isQueueEmpty(Queue *q){
    return q->front == q->rear;
}

//插入
void enQueue(Queue *q,TreeNode *ch){
    Node *cur = (Node *)malloc(sizeof(Node));
    cur->data = ch;
    cur->next = NULL;
    q->rear->next = cur;
    q->rear = cur;
}

//删除
TreeNode* deQueue(Queue *q){
    TreeNode* ch = q->front->next->data;
    if (q->front->next == q->rear) {//如果要删除的位置正好是头节点后的第一个有效节点
        q->rear = q->front;
        free(q->front->next);
        q->front->next = NULL;
    } else {
        Node *t = q->front->next;
        q->front->next = t->next;
        free(t);
    }
    return ch;
}

//复位
void resetQueue(Queue *q){
    Node *head = q->front->next;
    q->front->next = NULL;//先打断
    q->rear = q->front;
    Node *t;
    while (head) {
        t = head->next;
        free(head);
        head = t;
    }
}

//销毁
void clearQueue(Queue *q){
    resetQueue(q);
    free(q->front);
}

