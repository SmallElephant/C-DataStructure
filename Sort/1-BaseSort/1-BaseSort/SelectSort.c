//
//  SelectSort.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/8.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "SelectSort.h"

void selectSort(int a[],int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void max_heapify(int a[],int start,int end) { // 从start到end 开始构造大顶堆
    int dad = start;
    int son = 2 * start + 1;
    while (son <= end) {
        if (son + 1 <= end && a[son] < a[son + 1]) { // 如果左孩子的数值小于右孩子的数值
            son = son + 1;
        }
        if (a[dad] > a[son]) { // 如果父节点的值最大，返回
            return;
        } else {
            swap(&a[dad], &a[son]); // 先进行交换，将父节点交换至子节点，然后递归找到合适的位置
            dad = son;
            son = son / 2 - 1;
        }
    }
}

// 父节点i的左孩子的位置，2 * i + 1  右孩子的位置 2 * i + 2
// 子节点i的父节点的位置 floor(i / 2 -1)
// n 个节点最多有 n / 2 - 1个父结点
void heapSort(int a[],int n) {
    for (int i = n / 2 - 1; i >= 0; i--) { // 从最后一个父节点开始，
        max_heapify(a, i, n); // 从树的最底层开始和孩子比较，构造之后树的最顶层是整个数组的最大值
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]); // 将最大值调整至底部
        max_heapify(a, 0, i - 1); //  其余树节点继续进行构造，将剩余数组中的最大值调整至树顶，也就是0的位置
    }
}
