//
//  BinarySearchTree.c
//  1-BaseSearch
//
//  Created by FlyElephant on 2018/5/21.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "BinarySearchTree.h"

BTNode *rootNode = NULL;

void testBSTOperation() {
    int key[] = {5,4,8,3,7,9,6,10};
    createBST(key, 8);
    BTNode *node = rootNode;
    while (node) {
        printf("node value:%d\n",node->key);
        node = node->lchild;
    }
    printf("print value\n");
    int res = isBinarySearchTree(node);
    if (res) {
        printf("node is binary tree\n");
    } else {
        printf("node is not binary tree\n");
    }
}

BTNode *BSTSearch(BTNode *bt,int key) {
    if (bt == NULL) {
        return NULL;
    } else {
        if (bt->key == key) { // match key
            return bt;
        } else if (bt->key < key) { // search right child tree
            return BSTSearch(bt->rchild, key);
        } else { // search left child tree
            return BSTSearch(bt->lchild, key);
        }
    }
}

void createBST(int key[],int n) {
    rootNode = NULL;
    for (int i = 0;i < n; i++) {
        if (i == 0) {
            rootNode = insert(rootNode, key[i]);
        } else {
            insert(rootNode, key[i]);
        }
    }
}

//https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
BTNode *insert(BTNode *bt,int key) {
    if (bt == NULL) {
        BTNode *node = (BTNode *)malloc(sizeof(BTNode)); // create btnode
        node->lchild = NULL;
        node->rchild = NULL;
        node->key = key;
        return node;
    } else {
        if (key < bt->key) {
            bt->lchild = insert(bt->lchild, key);
        } else if (key > bt->key) {
            bt->rchild = insert(bt->rchild, key);
        }
        return bt; // unchanged
    }
}

int preData = -1000;

int isBinarySearchTree(BTNode *node) {
    if (node == NULL) {
        return 1;
    } else {
        int b1 = isBinarySearchTree(node->lchild);
        if (b1 == 0 || preData < node->key) { // left tree is false,root value smaller than current left tree value
            return 0;
        }
        preData = node->key;
        int b2 = isBinarySearchTree(node->rchild);
        return b2;
    }
}

