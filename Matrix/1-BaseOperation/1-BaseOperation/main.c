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
    return 0;
}
