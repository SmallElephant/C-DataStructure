//
//  Practice.h
//  1-Tree
//
//  Created by FlyElephant on 2018/4/21.
//  Copyright © 2018年 rrd. All rights reserved.
//

#ifndef Practice_h
#define Practice_h

#include <stdio.h>
#include "CustomStruct.h"

#endif /* Practice_h */

BTNode *createBTree(char pre[],char in[], int preLeft, int preRight, int inLeft, int inRight);
BTNode *createBTTreePost(char post[], char in[], int postLeft, int postRight, int inLeft, int inRight);

// 统计二叉树的叶子节点数量
int countNode(BTNode *node);

int leafNodeCount(BTNode *node);
