//
//  Tree.h
//  1-Tree
//
//  Created by FlyElephant on 2018/4/17.
//  Copyright © 2018年 rrd. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>

#endif /* Tree_h */
#include "CustomStruct.h"

void testTreeMethod(void);

void preOrder(BTNode *root);
void inOrder(BTNode *root);
void postOrder(BTNode *root);

int getDepth(BTNode *root);
BTNode *search(BTNode *root,char key);
void level(BTNode *root, int maxSize);
int getBinaryTreeWidth(BTNode *root, int maxSize);

void preOrderNonRecursive(BTNode *root,int maxSize);
void inOrderNonRecursive(BTNode *root, int maxSize);
