//
//  main.c
//  2-Practice
//
//  Created by FlyElephant on 2018/7/26.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include "Question.h"

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

void printData(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ",arr[i]);
    }
    printf("\n");
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
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    reverseArr(arr, 4, 6);
    printData(arr, 10);
    return 0;
}

