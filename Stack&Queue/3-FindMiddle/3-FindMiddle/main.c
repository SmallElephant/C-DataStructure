//
//  main.c
//  3-FindMiddle
//
//  Created by FlyElephant on 2017/11/24.
//  Copyright © 2017年 FlyElephant. All rights reserved.
//

#include <stdio.h>

int find_middle(int a[], int b[], int n) {
    int s1 = 0, e1 = n - 1;
    int s2 = 0, e2 = n - 1;
    while (s1 != e1 || s2 != e2) {
        int m1 = (s1 + e1) / 2;
        int m2 = (s2 + e2) / 2;
        if (a[m1] == b[m2]) {
            return a[m1];
        }
        if (a[m1] < b[m2]) {
            if ((s1 + e1) % 2 == 0) { //  元素个数是奇数，保留中间元素
                s1 = m1;
                e2 = m2;
            } else { // 元素个数是偶数，a舍弃中间元素，保持两个数组舍弃的元素个数一致
                s1 = m1 + 1;
                e2 = m2;
            }
        }
        if (a[m1] > b[m2]) {
            if ((s2 + e2) % 2 == 0) {
                e1 = m1;
                s2 = m2;
            } else {
                e1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return a[s1] < b[s2] ? a[s1] : b[s2];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[5] = {11,13,15,17,19};
    int b[5] = {2,4,6,8,20};
    int mid = find_middle(a, b, 5);
    printf("两个数组的中位数:%d\n",mid);
    return 0;
}
