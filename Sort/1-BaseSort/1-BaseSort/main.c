//
//  main.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/7.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include "Util.h"
#include "InsertSort.h"
#include "SwapSort.h"
#include "SelectSort.h"
#include "MergeSort.h"
#include "Practice.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    printf("insert sort result:\n");
    insertSort(a, 10);
    printData(a, 10);
    int sa[] = {10,9,8,7,6,5,4,3,2,1};
    printf("shell sort result:\n");
    shellSort(sa, 10);
    printData(sa, 10);
    int ba[] = {10,9,8,7,6,5,4,3,2,1};
    printf("bubble sort result:\n");
    bubbleSort(ba, 10);
    printData(ba, 10);
    int qa[] = {10,9,8,7,6,5,4,3,2,1};
    printf("quick sort result:\n");
    quickSort(qa, 0, 9);
    printData(qa, 10);
    int select[] = {10,9,8,7,6,5,4,3,2,1};
    printf("select sort result:\n");
    selectSort(select, 10);
    printData(select, 10);
    int ma[] = {10,9,8,7,6,5,4,3,2,1};
    printf("merge sort result:\n");
    mergeSort(ma, 0, 9);
    printData(ma, 10);
    int ra[] = {-1,9,8,-7,6,5,-4,3,2,-1};
    printf("re sort result:\n");
    resort(ra, 10);
    printData(ra, 10);
    return 0;
}
