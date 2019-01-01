//
//  main.c
//  01-单链表
//
//  Created by Ne on 2018/11/3.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {
    //测试创建链表
    Node *node = createList();
    
    //头插法
    headInsertList(node, 6);
    headInsertList(node, 2);
    headInsertList(node, 8);
    headInsertList(node, 3);
    travereList(node);
    
    printf("\n");
   
    //尾插法
    Node *node1 = createList();
    endInsertList(node1, 11);
    endInsertList(node1, 22);
    endInsertList(node1, 33);
    endInsertList(node1, 44);
    travereList(node1);
    
    //长度
    int count = lenList(node);
    printf("\n链表的长度是:count=%d\n",count);

    //查找
    Node *findNode = searchList(node,4);
    if (findNode) {
        printf("查找:%d\n",findNode->data);
        //删除
        deleteList(node, findNode);
        printf("删除后遍历");
        travereList(node);
    } else {
        printf("没有找到\n");
    }
    
    //排序
    popSortList(node);
    printf("排序后:");
    travereList(node);
    printf("\n");
    
    //反转
    reverseList(node);
    printf("反转后:");
    travereList(node);
    printf("\n");
    
    //销毁
    destroyList(node);
    
    return 0;
}
