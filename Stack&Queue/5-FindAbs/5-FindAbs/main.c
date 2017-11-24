//
//  main.c
//  5-FindAbs
//
//  Created by FlyElephant on 2017/11/24.
//  Copyright © 2017年 FlyElephant. All rights reserved.
//

#include <stdio.h>

typedef struct DataNode {
    int data;
    struct DataNode *link;
} ListNode;

int abs(int num) {
    return num > 0 ? num : (-num);
}

void remove_repeat(ListNode *listNode, int n) {
    int *p = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1; i++) {
        *(p + i) = 0;
    }
    ListNode *head = listNode;
    ListNode *tmp;
    if (head->link != NULL) {
        int val = abs(head->data);
        *(p + val) = 1;
        while (head->link != NULL) {
            int index = abs(head->link->data);
            int res = *(p + index);
            if (res) { // 删除结点
                tmp = head->link;
                head->link = tmp->link;
            } else {
                head = head->link;
                *(p + index) = 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode node8 = { 10, NULL};
    ListNode node7 = { 2, &node8};
    ListNode node6 = { -1, &node7};
    ListNode node5 = { -4, &node6};
    ListNode node4 = { 4, &node5};
    ListNode node3 = { 3, &node4};
    ListNode node2 = { 2, &node3};
    ListNode node1 = { 1, &node2};
    remove_repeat(&node1, 10);
    ListNode *test = &node1;
    while (test != NULL) {
        printf("%d\t",test->data);
        test = test->link;
    }
    printf("\n");
    return 0;
}
