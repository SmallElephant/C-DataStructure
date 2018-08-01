//
//  main.c
//  2-Practice
//
//  Created by FlyElephant on 2018/7/26.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include "Question.h"
#include "Node.h"

void insertList(SqlList *list,int i,int data) {
    if (i < 0 || i > list->length) {
        return;
    }
    for (int j = list->length;j > i; j--) {
        list->data[j] = list->data[j - 1];
    }
    list->data[i] = data;
    list->length++;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //1.链表插入
//    SqlList data = {{1,2,3,4,5},5};
//    SqlList *p = &data;
//    printf("%d---%d---%d\n",data.length,(*p).length,p->length);
//    insertList(&data, 2, 10);
//    printData(data.data, data.length);
     // 2.删除链表中最小的数字
//    SqlList data = {{10,3,1,4,5},5};
//    deleteMinNumber(&data, 5);
//    printData(data.data, data.length);
    // 3.反转链表中的数字
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    reverseList(arr, 10);
//    printData(arr, 10);
//    4.删除指定元素
//    SqlList list= {{1,2,3,4,5,6,4,4,4,10},10};
//    deleteSpecialNumber(&list, 4);
//    printData(list.data, list.length);
    // 5.有序表删除一定范围内的元素
//    SqlList list= {{1,2,3,4,5,6,7,8,9,10},10};
//    deleteRangeNumber(&list, 4, 7);
//    printData(list.data, list.length);
    
//    SqlList list= {{1,2,5,7,5,6,7,8,9,10},10};
//    delte_from_sequence(&list, 5, 7);
//    printData(list.data, list.length);
    
//    SqlList list= {{1,2,5,5,5,6,7,8,9,10},10};
//    delete_same(&list);
//    printData(list.data, list.length);
    
//    SqlList list1= {{1,3,5,7,9},5};
//    SqlList list2 = {{2,4,6,8,10},5};
//    SqlList res = {{},0};
//    mergeList(&list1, &list2, &res);
//    printData(res.data, res.length);
    
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    reverseArr(arr, 4, 6);
//    printData(arr, 10);
    
//    int arr[] = {1,2,3,4,6,7,8,9,10,0};
//    searchExchangeInsert(arr, 4, 9);
//    printData(arr, 10);
    
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    leftShift(arr, 4, 10);
//    printData(arr, 10);
    
//    int s1[] = {11,13,15,17,19};
//    int s2[] = {2,4,6,8,20};
//    int mid = mid_search(s1, s2, 5);
//    printf("两个升序序列的中位数是:%d\n",mid);
//    int marjority[] = {3,4,5,4,7,4,9,4,4};
//    int num = majority(marjority, 9);
//    printData(marjority, 9);
//    printf("majority的大多数数字:%d\n",num);
//    ListNode list = {1,NULL};
//    ListNode list2 = {2,NULL};
//    ListNode list3 = {3,NULL};
//    ListNode list4 = {2,NULL};
//    ListNode list5 = {4,NULL};
//    ListNode list6 = {5,NULL};
//    list.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    printList(&list);
//    delete_node_x(&list, 2);
//    printList(&list);
//    ListNode listHead = {-1,NULL};
//    ListNode list1 = {1,NULL};
//    ListNode list2 = {2,NULL};
//    ListNode list3 = {3,NULL};
//    ListNode list4 = {2,NULL};
//    ListNode list5 = {4,NULL};
//    ListNode list6 = {5,NULL};
//    listHead.next = &list1;
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    printList(&listHead);
//    delete_node_normal(&listHead, 2);
//    printList(&listHead);
    
//    ListNode list1 = {1,NULL};
//    ListNode list2 = {2,NULL};
//    ListNode list3 = {3,NULL};
//    ListNode list4 = {4,NULL};
//    ListNode list5 = {5,NULL};
//    ListNode list6 = {6,NULL};
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    printList(&list1);
//    reverse_print(&list1);
//    printf("\n");
    
//    ListNode listHead = {-1,NULL};
//    ListNode list1 = {6,NULL};
//    ListNode list2 = {5,NULL};
//    ListNode list3 = {4,NULL};
//    ListNode list4 = {2,NULL};
//    ListNode list5 = {8,NULL};
//    ListNode list6 = {9,NULL};
//    listHead.next = &list1;
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    delete_min_node(&list1);
//    printList(&listHead);
    
//    ListNode list1 = {1,NULL};
//    ListNode list2 = {2,NULL};
//    ListNode list3 = {3,NULL};
//    ListNode list4 = {4,NULL};
//    ListNode list5 = {5,NULL};
//    ListNode list6 = {6,NULL};
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    ListNode *head = reverse_list(&list1);
//    printList(head);
    
    // 链表
//    ListNode listHead = {-1,NULL};
//    ListNode list1 = {6,NULL};
//    ListNode list2 = {5,NULL};
//    ListNode list3 = {4,NULL};
//    ListNode list4 = {2,NULL};
//    ListNode list5 = {1,NULL};
//    ListNode list6 = {9,NULL};
//    listHead.next = &list1;
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    printList(&listHead);
//    sort_list(&listHead);
//    printList(&listHead);
    
    // 删除链表指定范围的值
//    ListNode listHead = {-1,NULL};
//    ListNode list1 = {6,NULL};
//    ListNode list2 = {5,NULL};
//    ListNode list3 = {4,NULL};
//    ListNode list4 = {2,NULL};
//    ListNode list5 = {1,NULL};
//    ListNode list6 = {9,NULL};
//    listHead.next = &list1;
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    printList(&listHead);
//    delete_range(&listHead, 3, 7);
//    printList(&listHead);
    
//    ListNode list1 = {1,NULL};
//    ListNode list2 = {2,NULL};
//    ListNode list3 = {3,NULL};
//    ListNode list4 = {4,NULL};
//    ListNode list5 = {5,NULL};
//    ListNode list6 = {6,NULL};
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//
//    ListNode node1 = {3,NULL};
//    ListNode node2 = {5,NULL};
//    ListNode node3 = {6,NULL};
//    node1.next = &node2;
//    node2.next = &node3;
//    ListNode *first = search_first_common(&list1, &node1);
//    if (first != NULL) {
//        printf("首个相同的结点:%d\n",first->val);
//    } else {
//        printf("无相同公共结点");
//    }
//    ListNode list1 = {5,NULL};
//    ListNode list2 = {3,NULL};
//    ListNode list3 = {1,NULL};
//    ListNode list4 = {2,NULL};
//    ListNode list5 = {4,NULL};
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    delete_min_sequence(&list1);
    
//    ListNode list1 = {1,NULL};
//    ListNode list2 = {2,NULL};
//    ListNode list3 = {3,NULL};
//    ListNode list4 = {4,NULL};
//    ListNode list5 = {5,NULL};
//    ListNode list6 = {6,NULL};
//    ListNode list7 = {7,NULL};
//    ListNode list8 = {8,NULL};
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    list6.next = &list7;
//    list7.next = &list8;
//    discreate(&list1);
//    ListNode listHead = {-1,NULL};
//    ListNode list1 = {1,NULL};
//    ListNode list2 = {2,NULL};
//    ListNode list3 = {3,NULL};
//    ListNode list4 = {4,NULL};
//    ListNode list5 = {5,NULL};
//    ListNode list6 = {6,NULL};
//    ListNode list7 = {7,NULL};
//    ListNode list8 = {8,NULL};
//    listHead.next = &list1;
//    list1.next = &list2;
//    list2.next = &list3;
//    list3.next = &list4;
//    list4.next = &list5;
//    list5.next = &list6;
//    list6.next = &list7;
//    list7.next = &list8;
//    discreate3(&listHead);
    
    ListNode list1 = {7,NULL};
    ListNode list2 = {10,NULL};
    ListNode list3 = {10,NULL};
    ListNode list4 = {21,NULL};
    ListNode list5 = {30,NULL};
    ListNode list6 = {42,NULL};
    ListNode list7 = {42,NULL};
    ListNode list8 = {42,NULL};
    list1.next = &list2;
    list2.next = &list3;
    list3.next = &list4;
    list4.next = &list5;
    list5.next = &list6;
    list6.next = &list7;
    list7.next = &list8;
    delete_repeat(&list1);
    return 0;
}

