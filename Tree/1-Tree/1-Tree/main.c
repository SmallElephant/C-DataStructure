//
//  main.c
//  1-Tree
//
//  Created by FlyElephant on 2018/4/13.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
#include "Practice.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    testTreeMethod();
//    testThreadMethod();
    // 先序 A B D E C F
    // 中序 D B E A F C
    // 后序 D E B F C A
    char pre[] = {'A','B','D','E','C','F'};
    char in[] = {'D','B','E','A','F','C'};
    char post[] = {'D','E','B','F','C','A'};
    BTNode *s = createBTree(pre, in, 0, 5, 0, 5);
    postOrder(s);
    printf("\n");
    BTNode *postTree= createBTTreePost(post, in, 0, 5, 0, 5);
    preOrder(postTree);
    printf("\n");
    level(postTree, 6);
    int count = countNode(s);
    printf("tree node count:%d\n",count);
    int leafCount = leafNodeCount(s);
    printf("leaf node count:%d\n",leafCount);
    linkLeafNode(s);
    printLeafNodeLink();
    BTParentNode *root = NULL;
    BTParentNode node = {'A',NULL,NULL,NULL};
    BTParentNode bNode = {'B',NULL,NULL,NULL};
    BTParentNode cNode = {'C',NULL,NULL,NULL};
    BTParentNode dNode = {'D',NULL,NULL,NULL};
    BTParentNode eNode = {'E',NULL,NULL,NULL};
    node.leftNode = &bNode;
    node.rightNode = &cNode;
    bNode.rightNode = &dNode;
    cNode.leftNode = &eNode;
    root = &node;
    updateParentTree(root, NULL);
    printParentNodePath(&dNode);
    printParentAllPath(root);
    return 0;
}
