//
//  main.c
//  1-Tree
//
//  Created by FlyElephant on 2018/4/13.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    testTreeMethod();
    BTNode root = {'1',NULL,NULL};
    BTNode bNode = {'2',NULL,NULL};
    BTNode cNode = {'4',NULL,NULL};
    BTNode dNode = {'3',NULL,NULL};
    BTNode eNode = {'5',NULL,NULL};
    root.leftNode = &bNode;
    root.rightNode = &cNode;
    bNode.leftNode = &dNode;
    bNode.rightNode = &eNode;
    preOrderNonRecursive(&root, 6);
    inOrderNonRecursive(&root, 6);
    postOrderNonRecursive(&root, 6);
    return 0;
}
