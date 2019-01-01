//
//  list.h
//  01-单链表
//
//  Created by Ne on 2018/11/3.
//  Copyright © 2018年 Ne. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

//创建链表
Node * createList(void);

//头插法
void headInsertList(Node *head,int data);

//尾插法
void endInsertList(Node *head,int data);

//遍历
void travereList(Node *head);

//链表的长度
int lenList(Node *head);

//查找
Node * searchList(Node *head,int find);

//删除
void deleteList(Node *head,Node *pfind);

//排序
void popSortList(Node *head);

//反转
void reverseList(Node *head);

//销毁
void destroyList(Node *head);

#endif /* list_h */
