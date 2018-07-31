//
//  Node.c
//  2-Practice
//
//  Created by FlyElephant on 2018/7/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "Node.h"

void printList(ListNode *head) {
    ListNode *node = head;
    while (node != NULL) {
        printf("%d  ",node->val);
        node = node->next;
    }
    printf("\n");
}

void delete_node_x(ListNode *list,int x) {
    if (list == NULL) {
        return;
    }
    if (list->val == x) {
        ListNode *next = list->next;
        list->val = next->val;
        list->next = next->next; // 覆盖当前结点，实现删除功能
        delete_node_x(list, x);
    } else {
        delete_node_x(list->next, x);
    }
}

void delete_node_normal(ListNode *list,int x) {
    ListNode *pre = list; // 前驱结点
    ListNode *node = list;
    while (node != NULL) {
        if (node->val == x) {
            pre->next = node->next;
            node = node->next;
        } else {
            pre = node;
            node = node->next;
        }
    }
}
