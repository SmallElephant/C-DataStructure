//
//  SwapSort.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/7.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "SwapSort.h"

void bubbleSort(int a[],int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) { // 方案实现比较简单，强烈推荐
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void bubbleSort1(int a[],int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int partition(int a[],int low,int high) {
    int pivot = a[high]; // 默认选取最后一个元素作为基准值
    int index = low;
    for (int i = low; i < high; i++) {
        if (a[i] <= pivot) {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[index], &a[high]);
    return index;
}

void quickSort(int a[],int low,int high) {
    if (low >= high) {
        return;
    }
    int mid = partition(a, low, high);
    quickSort(a, low, mid - 1);
    quickSort(a, mid + 1, high);
}


