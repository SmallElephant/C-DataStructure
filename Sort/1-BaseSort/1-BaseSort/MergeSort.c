//
//  MergeSort.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/8.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "MergeSort.h"

void merge(int a[],int low,int mid,int high) {
    if (low >= high) {
        return;
    }
    int i = low; // left pointer
    int j = mid + 1; // right pointer
    int len = high - low + 1;
    int temp[len];
    int k = 0;
    while (i <= mid && j <= high) {
        temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    }
    while (i <= mid) { // left remainder
        temp[k++] = a[i++];
    }
    while (j <= high) {
        temp[k++] = a[j++];
    }
    for (int i = 0; i < len; i++) {
        a[low+i] = temp[i];
    }
}

void mergeSort(int a[],int low,int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}
