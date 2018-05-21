//
//  BinarySearchTree.h
//  1-BaseSearch
//
//  Created by FlyElephant on 2018/5/21.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>

#endif /* BinarySearchTree_h */

typedef struct BTNode{
    int key; // 可以是对象，这里使用关键字表示
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

BTNode *BSTSearch(BTNode *bt,int key);

void testBSTOperation(void);
void createBST(int key[],int n);

BTNode *insert(BTNode *bt,int key); // 1 success 0 fail


