//
//  main.c
//  10-树的遍历(循环实现)
//
//  Created by Ne on 2018/11/8.
//  Copyright © 2018年 Ne. All rights reserved.
//


#include <stdio.h>
#include "stack.h"

#if 0

a1
b2         c3
d4     e5          f6

preOrder:  1 2 4 5 3 6 中左右
midOrder:  4 2 5 1 3 6 左中右
postOrder: 4 5 2 6 3 1 左右中

#endif

//先中后 三种遍历的方式,本质压栈顺序是没有什么不同的
//所谓的先中后,无非是访问根节点的时机不同而已

#pragma mark --先序遍历
void preOrderTraverase(TreeNode *r) {
    if (r) {
        Stack s;
        initStack(&s, 1000);
        while (r || !isStackEmpty(&s)) {
            while (r) {
                printf("%d",r->_data);
                push(&s, r);//压栈
                r  = r->_left;
            }
            r = pop(&s); //出栈
            r = r->_right;
        }
    }
}

#pragma mark --中序遍历
void midOrderTraverase(TreeNode *r) {
    if (r) {
        Stack s;
        initStack(&s, 1000);
        while (r || !isStackEmpty(&s)) {
            while (r) {
                push(&s, r);//压栈
                r  = r->_left;
            }
            r = pop(&s); //出栈
            printf("%d",r->_data);
            r = r->_right;
        }
    }
}

#pragma mark --后序遍历
void postOrderTraverase(TreeNode *r) {
    if (r) {
        Stack s;
        initStack(&s,1000);
        TreeNode *cur; //当前结点
        TreeNode *pre = NULL; //前一次访问的结点
        push(&s,r);
        while(!isStackEmpty(&s))
        {
            cur = pop(&s);
            push(&s,cur);
            if((cur->_left==NULL&&cur->_right==NULL)||
               (pre!=NULL&&(pre==cur->_left||pre==cur->_right))) {
                //如果当前结点没有孩子结点或者孩子节点都已被访问过
                printf("%d\t",cur->_data);
                pop(&s);
                pre=cur;
            } else {
                if(cur->_right != NULL) push(&s,cur->_right);
                if(cur->_left != NULL) push(&s,cur->_left);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    TreeNode a,b,c,d,e,f;
    TreeNode * root = &a;
    
    a._data = 1;
    b._data = 2;
    c._data = 3;
    d._data = 4;
    e._data = 5;
    f._data = 6;
    
    a._left = &b;
    a._right = &c;
    
    b._left = &d;
    b._right = &e;
    
    c._left = NULL;
    c._right = &f;
    
    d._left = d._right = NULL;
    e._left = e._right = NULL;
    f._left = f._right = NULL;
    
    printf(" 先序遍历:");
    preOrderTraverase(root);
    
    printf("\n 中序遍历:");
    midOrderTraverase(root);
    
    printf("\n 后序遍历:");
    postOrderTraverase(root);
    
    return 0;
}
