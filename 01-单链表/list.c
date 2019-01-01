//
//  list.c
//  01-单链表
//
//  Created by Ne on 2018/11/3.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include "list.h"
#include <stdlib.h>

//带有头结点的链表,创建空链表
Node * createList(void) {
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

//头插法
void headInsertList(Node *head,int data) {
    Node *cur = (Node*)malloc(sizeof(Node));
    cur->data = data;
    cur->next = head->next;
    head->next = cur;
}

//尾插法
void endInsertList(Node *head,int data) {
    Node *cur = (Node*)malloc(sizeof(Node));
    Node *t = head;
    cur->data = data;
    while (t->next != NULL) {//只要节点的next指针不是NULL就继续往下遍历
        t = t->next;
    }
    //此时t一定是指向最后一个节点
    t->next = cur; //把添加的节点的地址赋值给 之前链表的最后一个节点的next
    cur->next = NULL;//置NULL操作
}


//遍历
void travereList(Node *head) {
    head = head->next;//头结点是没有数据的,先next一下指向第一个有效元素
    while (head) {
        printf("%2d ",head->data);
        head = head->next;
    }
}

//求链表长度
int lenList(Node *head) {
    int count = 0;
    head = head->next;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

//链表的查找
Node * searchList(Node *head,int find) {
    head = head->next;
    while (head) {
        if (head->data == find)
            break;
        head = head->next;
    }
    return head;
}

//链表的删除
void deleteList(Node *head,Node *pfind) {
    if (pfind->next == NULL) { //如果正好要删除的元素是最后一个节点
        while (head->next != pfind)//找到要删除元素的前驱
            head = head->next;
        head->next = pfind->next;//走到这里,肯定找到了 要删除元素的 前驱,然后让前驱直接指向当前元素next指针的指向
        free(pfind);
    } else {
        pfind->data = pfind->next->data;
        Node *t = pfind->next;
        pfind->next = t->next;
        free(t);
    }
}

//排序
void popSortList(Node *head) {
    /*Node *p,*q;
    int len = lenList(head);
    for (int i=0; i < len-1; i++) {
        p = head->next;//每次内重循环从头开始
        q = p->next;//p总是指向p的下一个节点,也就是被比较的节点
        for (int j=0; j < len-1-i; j++) {
            if (p->data > q->data) {
                p->data ^= q->data;
                q->data ^= p->data;
                p->data ^= q->data;
            }
            p = p->next;//指针后移一个
            q = p->next;//q永远是指向p的下一个节点
        }
    }*/
    //优化版本
    Node *prep,*p,*q,*t;
    int len = lenList(head);
    for (int i=0; i < len-1; i++) {
        prep = head;
        p = head->next;//每次内重循环从头开始
        q = p->next;//p总是指向p的下一个节点,也就是被比较的节点
        for (int j=0; j < len-1-i; j++) {
            if (p->data > q->data) {
                prep->next = q;
                p->next = q->next;
                q->next = p;
                
                //记得交换会p,q.保证p在前,q永远是p的下一个节点
//                t = p;
//                p = q;
//                q = t;
                //或者
                prep = q;
                q = p->next;
                continue;
            }
            prep = prep->next;
            p = p->next;//指针后移一个
            q = p->next;//q永远是指向p的下一个节点
        }
    }
}

//反转
void reverseList(Node *head) {
    Node *h = head->next;
    head->next = NULL;
    Node *t;
    while (h) {
        t = h->next;
        h->next = head->next;
        head->next = h;
        h = t;
    }
}

//销毁
void destroyList(Node *head) {
    Node *t;
    while (head) {
        t = head->next;
        free(head);
        head = t;
    }
}
