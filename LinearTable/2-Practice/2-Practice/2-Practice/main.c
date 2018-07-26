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
    
    SqlList data = {{10,3,1,4,5},5};
    deleteMinNumber(&data, 5);
    printData(data.data, data.length);
    return 0;
}

