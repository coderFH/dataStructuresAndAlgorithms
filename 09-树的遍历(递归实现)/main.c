//
//  main.c
//  09-树的遍历(递归实现)
//
//  Created by Ne on 2018/11/8.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>

typedef struct _TreeNode {
    int _data;
    struct _TreeNode *_left;
    struct _TreeNode *_right;
}TreeNode;

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
        printf("%d",r->_data);
        preOrderTraverase(r->_left);
        preOrderTraverase(r->_right);
    }
}

#pragma mark --中序遍历
void midOrderTraverase(TreeNode *r) {
    if (r) {
        
        midOrderTraverase(r->_left);
        printf("%d",r->_data);
        midOrderTraverase(r->_right);
    }
}

#pragma mark --后序遍历
void postOrderTraverase(TreeNode *r) {
    if (r) {
        postOrderTraverase(r->_left);
        postOrderTraverase(r->_right);
        printf("%d",r->_data);
    }
}

#pragma mark --求树的高度
int getHeightByPostOrder(TreeNode *t) {
    int lH, rH, maxH;
    if(t)
    {
        lH = getHeightByPostOrder(t->_left);
        rH = getHeightByPostOrder(t->_right);
        maxH = (lH>rH) ? lH : rH;
        return maxH +1;
    } else
        return 0;
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
    

    int maxH =getHeightByPostOrder(root);
    printf("\n 树的高度 = %d\n",maxH);

    return 0;
}
