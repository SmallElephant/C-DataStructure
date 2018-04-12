//
//  main.c
//  1-BaseOperation
//
//  Created by FlyElephant on 2018/4/11.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>

//设数组A[0..n-1]的n个元素有多个零元素，设计一个算法，讲A中的所有非零元素移动到A数组的前端.

void swap(int *a, int *b) { // 传递地址，数据交换
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printData(int data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t",data[i]);
    }
    printf("\n");
}

void moveElement(int data[], int n) {
    int i = 0; // 左指针
    for (int j = 0; j < n; j++) {
        if (data[j] != 0) {
            swap(&data[i], &data[j]);
            i++;
        }
    }
}

int findMax(int data[], int i, int j) {
    if (i == j) {
        return data[i];
    } else {
        int max = findMax(data, i + 1, j);
        return data[i] > max ? data[i] : max;
    }
}

int findSum(int data[], int i, int j) {
    if (i == j) {
        return data[i];
    } else {
        int sum = findSum(data, i + 1, j);
        return data[i] + sum;
    }
}

float findAverage(int data[], int i, int j) {
    if (i == j) {
        return data[i];
    } else {
        float average = findAverage(data, i + 1, j);
        return (data[i] + average * (j - i)) / (j - i + 1);
    }
}

//设计一个算法，将数组A[0...n-1]的奇数移动到偶数之前，要求不新增存储空间，且时间复杂度为O(n).

void divide(int data[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (data[i] % 2 == 1 && i < j) { // 从左向右遍历，找到第一个偶数
            i++;
        }
        while (data[j] % 2 == 0 && i < j) { // 从右向左遍历，找到第一个奇数
            j--;
        }
        if (i < j) { // 数据交换
            swap(&data[i], &data[j]);
            i++;
            j--;
        }
    }
}


int parition(int data[], int low, int high) {
    int i = low, j = high;
    int pivot = data[high];
    while (i < j) {
        while (data[i] <= pivot && i < j) { // 从左向右遍历，找到第一个大于base的数字
            i++;
        }
        while (data[j] >= pivot && i < j) { // 从右向左遍历，找到第一个小于base的数字
            j--;
        }
        if (i < j) {
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i], &data[high]);
    return i;
}

void quickSort(int data[], int low, int high) {
    if (low >= high) {
        return;
    }
    int index = parition(data, low, high);
    quickSort(data, low, index - 1);
    quickSort(data, index + 1, high);
}


int parition2(int data[], int low, int high) {
    int pivot = data[high]; // 基准值不参与比较，最后进行交换
    int j = low; // 左指针
    for (int i = low; i < high; i++) {
        if (data[i] <= pivot) {
            swap(&data[i], &data[j]);
            j++;
        }
    }
    swap(&data[j], &data[high]);
    return j;
}

void quickSort2(int data[], int low, int high) {
    if (low >= high) {
        return;
    }
    int index = parition2(data, low, high);
    quickSort2(data, low, index - 1);
    quickSort2(data, index + 1, high);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int data[] = {1,0,2,0,3,0,4,0,0,0,5,6};
    moveElement(data, 12);
    printData(data, 12);
    
    int max = findMax(data, 0, 11);
    printf("max value:%d\n",max);
    int sum = findSum(data, 0, 11);
    printf("sum value:%d\n",sum);
    float average = findAverage(data, 0, 11);
    printf("average number value:%f\n",average);
    
    int divideData[] = {1,3,5,2,8,9,7,10,19};
    divide(divideData, 9);
    printData(divideData, 9);
    
    int partitionData[] = {3,7,8,4,2,1,9,5,5};
    printf("初始数组\n");
    printData(partitionData, 9);
    printf("first method quick divide\n");
    quickSort(partitionData, 0, 8);
    printData(partitionData, 9);
    
    int partitionData2[] = {3,7,8,4,2,1,9,5,5};
    printf("second method quick divide\n");
    quickSort2(partitionData2, 0, 8);
    printData(partitionData2, 9);
    return 0;
}
