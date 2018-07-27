//
//  Question.c
//  2-Practice
//
//  Created by FlyElephant on 2018/7/26.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "Question.h"

void printData(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}

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

// 最简单的方式可以从后向前扫描顺序表，每遇到一个值在s与t之间的元素，则删除该元素，其后所有元素全部前移，移动次数比较多，效率不够高
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

void delete_same(SqlList *list) { // 有序顺序表的特点，是相同的元素是连续的，找到第一个不连续的数字即可
    if (list->length <= 1) {
        return;
    }
    int i = 0;
    for (int j = 1; j < list->length; j++) {
        if (list->data[i] != list->data[j]) {
            list->data[++i] = list->data[j];
        }
    }
    list->length = i + 1;
}

void mergeList(SqlList *list1,SqlList *list2,SqlList *res) {
    if (list1->length == 0) {
        res = list2;
    }
    if (list2->length == 0) {
        res = list1;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < list1->length && j < list2->length) {
        if (list1->data[i] < list2->data[j]) {
            res->data[k++] = list1->data[i++];
        } else {
            res->data[k++] = list2->data[j++];
        }
    }
    while (i < list1->length) {
        res->data[k++] = list1->data[i++];
    }
    while (j < list2->length) {
        res->data[k++] = list2->data[j++];
    }
    res->length = k;
}

void reverse(int arr[],int left,int right,int n) { // left 索引开始，right 索引结束
    if (left >= right || right >= n) {
        return;
    }
    int mid = (right - left) / 2;
    for (int i = 0; i <= mid; i++) {
        swap(&arr[left + i], &arr[right - i]);
    }
}

void reverseArr(int arr[],int m,int n) {
    reverse(arr, 0, m+n-1, m+n);
    reverse(arr, 0, n-1, m+n);
    reverse(arr, n, m+n-1, m+n);
}

void searchExchangeInsert(int arr[],int x,int n) {
    int low = 0;
    int high = n - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            high = mid - 1;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            index = mid;
            break;
        }
    }
    if (index != -1 && index != n - 1) { // 元素存在，且不是最后一个元素
        swap(&arr[index], &arr[index+1]);
    }
    if (low > high) {
        printData(arr, 10);
        for (int i = n - 1; i > high; i--) {
            arr[i+1] = arr[i];
        }
        printData(arr, 10);
        arr[high+1] = x;
    }
}


