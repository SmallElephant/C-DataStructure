//
//  Question.c
//  2-Practice
//
//  Created by FlyElephant on 2018/7/26.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "Question.h"

bool deleteMinNumber(SqlList *list,int num) {
    if (list->length == 0) {
        return false;
    }
    int pos = 0;
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] < list->data[pos]) {
            pos = i;
        }
    }
    list->data[pos] = list->data[list->length - 1];
    list->length--;
    return true;
}

void swap(int *a,int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void reverseList(int a[],int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(&a[i], &a[n - i - 1]);
    }
}

void deleteSpecialNumber(SqlList *list,int num) {
    int len = list->length;
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (list->data[i] != num) {
            list->data[k] = list->data[i];
            k++;
        }
    }
    list->length = k;
}

void deleteRangeNumber(SqlList *list,int s,int t) {
    if (s >= t) {
        return;
    }
    int len = list->length;
    int i;
    for (i = 0; i < len && list->data[i] < s; i++) { // 寻找≥s的第一个元素
        
    }
    int j;
    for (j = i; j < len && list->data[j] <= t; j++) { // 寻找大于>t的第一个元素
    }
    for (; j < len; j++,i++) {
        list->data[i] = list->data[j];
    }
    list->length = i;
}

void delte_from_sequence(SqlList *list,int s,int t) { // 元素只需要移动一次，效率比较高
    if (s >= t) {
        return;
    }
    int len = list->length;
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (list->data[i] >=s && list->data[i] <= t) {
            k++;
        } else {
            list->data[i-k] = list->data[i]; // 重点可以看看
        }
    }
    list->length = list->length - k;
}


