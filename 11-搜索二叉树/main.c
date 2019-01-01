//
//  main.c
//  11-搜索二叉树
//
//  Created by Ne on 2018/11/8.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode {
    int _data;
    struct _TreeNode *_left;
    struct _TreeNode *_right;
}TreeNode;

#pragma mark --中序遍历
//之所以使用中序遍历,是以为搜索二叉树在创建的时候,就是安装一定的顺序去插入节点
//中序遍历的结果 如果是排好序列的结果,说明树创建的没有问题
void midOrderTraverase(TreeNode *r) {
    if (r) {
        midOrderTraverase(r->_left);
        printf("%d\t",r->_data);
        midOrderTraverase(r->_right);
    }
}

#pragma mark --迭代创建树
void insertBst(TreeNode **r,int data) {
    TreeNode *t = (*r);
    if (*r == NULL) {
        *r = (TreeNode *)malloc(sizeof(TreeNode));
        (*r)->_data = data;
        (*r)->_left = (*r)->_right = NULL;
    } else {
        while (1) {
            if (data > t->_data) {
                if (t->_right == NULL) {
                    t->_right = (TreeNode *)malloc(sizeof(TreeNode));
                    t->_right->_data = data;
                    t->_right->_left = t->_right->_right = NULL;
                    break;
                }
                t  = t->_right;
            }else {
                if (t->_left == NULL) {
                    t->_left = (TreeNode *)malloc(sizeof(TreeNode));
                    t->_left->_data = data;
                    t->_left->_left = t->_left->_right = NULL;
                    break;
                }
                t = t->_left;
            }
        }
    }
}

#pragma mark --递归创建树
void insertBstTraverse(TreeNode **r,int data) {
    if (*r == NULL) {
        *r = (TreeNode *)malloc(sizeof(TreeNode));
        (*r)->_data = data;
        (*r)->_left = (*r)->_right = NULL;
    } else {
        if (data > (*r)->_data) {
            insertBst(&(*r)->_right, data);
        }else {
            insertBst(&(*r)->_left, data);
        }
    }
}

#pragma mark --查找树
TreeNode * searchBst(TreeNode *r,int find) {
    while (r) {
        if (r->_data == find) {
            return r;
        } else if (find > r->_data) {
            r= r->_right;
        } else{
            r = r->_left;
        }
    }
    return NULL;
}

#pragma mark --查找(递归实现)
TreeNode * searchBstRecursive(TreeNode *r,int find) {
    if(r) {
        if (r->_data == find) {
            return r;
        } else if (find > r->_data) {
            return searchBstRecursive(r->_right, find);
        } else{
           return searchBstRecursive(r->_left, find);
        }
    }
    return NULL;
}

#pragma mark --查找最小节点
TreeNode* getMinNodeBst(TreeNode *r) {
    if (r) {
        while (r->_left) {
            r = r->_left;
        }
        return r;
    }
    return NULL;
}

#pragma mark --查找最大节点
TreeNode* getMaxNodeBst(TreeNode *r) {
    if (r) {
        while (r->_right) {
            r = r->_right;
        }
        return r;
    }
    return NULL;
}

#pragma mark --查找当前节点的父节点
TreeNode * getParentBst(TreeNode *r,TreeNode *child) {
    static TreeNode *parent = NULL;
    if (r) {
        if (r->_left == child || r->_right == child) {
            parent = r;
        }
        getParentBst(r->_left, child);
        getParentBst(r->_right, child);
    }
    return parent;
}

#pragma mark --树的删除
void deleteBst(TreeNode **r,TreeNode *pdel) {
    TreeNode *t = *r,*parent,*minRight;
    parent = getParentBst(t, pdel);
    if (pdel->_left == NULL && pdel->_right == NULL) {
        if (*r == pdel) {
            free(t);
            *r = NULL;
            return;
        }
        
        if (parent->_left == pdel) {
            parent->_left = NULL;
            
        } else {
            parent->_right = NULL;
        }
        free(pdel);
    } else if(pdel->_left !=NULL && pdel->_right == NULL){
        if (*r == pdel) {
            *r = pdel->_left;
            free(pdel);
            return;
        }
        if (parent->_left == pdel) {
            parent->_left = pdel->_left;
        } else {
            parent->_right = pdel->_right;
        }
        free(pdel);
    } else if (pdel->_left == NULL && pdel->_right != NULL) {
        if (*r == pdel) {
            *r = pdel->_right;
            free(pdel);
            return;
        }
        if (parent->_left == pdel) {
            parent->_left = pdel->_right;
        } else {
            parent->_right = pdel->_right;
        }
         free(pdel);
    } else {
        minRight = getMinNodeBst(pdel->_right);
        pdel->_data = minRight->_data;
        parent = getParentBst(t, minRight);
        if (minRight != pdel->_right) {
            parent->_left = minRight->_right;
        } else {
            parent->_right = minRight->_right;
        }
        free(minRight);
    }
}

#pragma mark --树的销毁
void destoryBst(TreeNode *r) {
    if (r) {
        destoryBst(r->_left);
        destoryBst(r->_right);
        free(r);
    }
}

/*
                   30
            8             36
                15    32     100
 */
int main(int argc, const char * argv[]) {
//测试迭代创建的搜索二叉树
    TreeNode *root = NULL;
    insertBst(&root,30);
    insertBst(&root,8);
    insertBst(&root,15);
    insertBst(&root,36);
    insertBst(&root,100);
    insertBst(&root,32);
    midOrderTraverase(root);
    printf("\n");
    
//测试递归创建的搜索二叉树
    TreeNode *root1 = NULL;
    insertBstTraverse(&root1,30);
    insertBstTraverse(&root1,8);
    insertBstTraverse(&root1,15);
    insertBstTraverse(&root1,36);
    insertBstTraverse(&root1,100);
    insertBstTraverse(&root1,32);
    midOrderTraverase(root1);
    
//迭代器查找
    TreeNode *pfind = searchBst(root, 1);
    if (pfind) {
        printf("\nfind %d \n",pfind->_data);
    } else {
        printf("\nfind non");
    }

//递归查找
    TreeNode *pfind1 = searchBstRecursive(root, 32);
    if (pfind1) {
        printf("\nfind %d \n",pfind1->_data);
    } else {
        printf("\nfind non\n");
    }

//最小值
    TreeNode *minNode = getMinNodeBst(root);
    printf("最小值:%d\n",minNode->_data);
    
//最大值
    TreeNode *maxNode = getMaxNodeBst(root);
    printf("最大值:%d\n",maxNode->_data);
    
//父节点
    TreeNode *parentNode = getParentBst(root, pfind1);
    printf("父节点是:%d\n",parentNode->_data);

//删除
    /*
            30
        8         36
     15        32    100
     */
//    TreeNode *pfind2 = searchBst(root, 15);//测试左右都是空
//    deleteBst(&root, pfind2);
//    midOrderTraverase(root);
    
//    TreeNode *root2 = NULL;
//    insertBst(&root2,30);
//    insertBst(&root2,8);
//    insertBst(&root2,7);
//    insertBst(&root2,36);
//    insertBst(&root2,100);
//    insertBst(&root2,32);
//    midOrderTraverase(root2);
//    printf("\n测试左节点是空的节点\n");
//    TreeNode *pfind3 = searchBst(root2, 7);//测试左是空
//    deleteBst(&root2, pfind3);
//    midOrderTraverase(root2);
    
//    TreeNode *pfind4 = searchBst(root, 8);//测试右是空
//    deleteBst(&root, pfind4);
//    midOrderTraverase(root);
    
//    TreeNode *pfind5 = searchBst(root, 36);//测试左右都不为空
//    deleteBst(&root, pfind5);
//    midOrderTraverase(root);
    
//树的销毁
    destoryBst(root);
    root = NULL;
    if (root == NULL) {
        printf("tree is empty\n");
    }
    return 0;
}
