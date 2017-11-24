//
//  main.c
//  4-CommonSuffix
//
//  Created by FlyElephant on 2017/11/24.
//  Copyright © 2017年 FlyElephant. All rights reserved.
//

#include <stdio.h>

typedef struct DataNode {
    struct DataNode *next;
    char data;
} ListNode;

int listlen(ListNode *list) {
    int len = 1;
    while (list->next != NULL) {
        len++;
        list = list->next;
    }
    return len;
}

ListNode *find_listNode(ListNode *list1,ListNode *list2) {
    int len1 = listlen(list1);
    int len2 = listlen(list2);
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            list1 = list1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            list2 = list2->next;
        }
    }
    if (list1->data == list2->data) {
        return list1;
    } else {
        while (list1->next != NULL && list1->data != list2->data) {
            list1 = list1->next;
            list2 = list2->next;
        }
        return list1->next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode node3 = { NULL, 'd'};
    ListNode node2 = { &node3, 'd'};
    ListNode node1 = { &node2, 'm'};
    
    ListNode list6 = { NULL, 't'};
    ListNode list5 = { &list6, 'n'};
    ListNode list4 = { &list5, 'h'};
    ListNode list3 = { &list4, '_'};
    ListNode list2 = { &list3, 'y'};
    ListNode list1 = { &list2, 'm'};
    
    ListNode *result = find_listNode(&node1, &list1);
    if (result != NULL) {
        printf("起点的值:%c\n",result->data);
    } else {
        printf("无共同起点\n");
    }
    return 0;
}
