//
//  BaseSearch.c
//  1-BaseSearch
//
//  Created by FlyElephant on 2018/5/16.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "BaseSearch.h"

int binarySeach(int a[],int low,int high,int k) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == k) {
            return mid;
        } else if (a[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
