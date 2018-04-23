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
#include <stdlib.h>
#include "CustomStruct.h"

#endif /* Tree_h */

void testTreeMethod(void);
void testBinaryNonRecursive(void);
void testThreadMethod(void);

void preOrder(BTNode *root);
void inOrder(BTNode *root);
void postOrder(BTNode *root);

int getDepth(BTNode *root);
BTNode *search(BTNode *root,char key);
void level(BTNode *root, int maxSize);
int getBinaryTreeWidth(BTNode *root, int maxSize);

void preOrderNonRecursive(BTNode *root,int maxSize);
void inOrderNonRecursive(BTNode *root, int maxSize);
void postOrderNonRecursive(BTNode *root, int maxSize);

void inThread(TBTNode *p);
void createInThread(TBTNode *root);
TBTNode *First(TBTNode *p);
TBTNode *Next(TBTNode *p);
TBTNode *InOrderLastNode(TBTNode *p);
TBTNode *InOrderPriorNode(TBTNode *p);
TBTNode *InOrderPreNext(TBTNode *t);
void threadInOrder(TBTNode *root);

void createPreThread(TBTNode *root);
void preThread(TBTNode *p);
void threadPreOrder(TBTNode *root);

void createPostThread(TBTNode *p);
void postThread(TBTNode *p);
void threadPostOrder(TBTNode *p);
