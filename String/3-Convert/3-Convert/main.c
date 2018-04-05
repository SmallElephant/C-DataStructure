//
//  main.c
//  3-Convert
//
//  Created by FlyElephant on 2018/4/2.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int strToInt(char *str) {
    int res = 0;
    while (*str != '\0') {
        int cur = *str - '0';
        res = res * 10 + cur;
        str++;
    }
    return res;
}

double strToDouble(char *str) {
    int sign = 1;
    int res = 0;
    if (*str == '+') {
        str++;
    }
    if (*str == '-') {
        sign = -1;
        str++;
    }
    int decimal = 0;
    double digit = 0;
    while (*str != '\0') {
        if (*str != '.') {
            int cur = *str - '0';
            res = res * 10 + cur;
            str++;
            if (decimal == 1) {
                digit--;
            }
        } else {
            str++;
            decimal = 1;
        }
    }
    return sign * res * pow(10.0, digit);
}

//http://blademastercoder.github.io/2015/02/04/leetcode-MajorityElement.html
int findMoreHalfNumber(int a[], int n) {
    int num = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) { //如果count为0，代表前面的数字正好全部抵消了
            num = a[i]; //current重新设定为当前遍历到的值
            count = 1;
        } else {
            if (num == a[i]) { //current等于当前遍历到的值 count++
                count++;
            } else { //current不等于当前遍历到的值 抵消 count--
                count--;
            }
        }
    }
    count = 0; // count = 0 需要进行重新验证，不能直接返回num
    for (int i = 0; i < n; i++) {
        if (a[i] == num) {
            count++;
        }
    }
    return count > n / 2 ? num : 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char *str = "1234";
    int num = strToInt(str);
    printf("转换结果:%d\n",num);
    char *str2 = "-1234.56";
    double res2 = strToDouble(str2);
    printf("FlyElephant转换结果:%f\n",res2);
    double test = pow(10.0, -2);
    printf("pow结果:%f\n",test);
    int a[] = {1,2,3,2,2,2,5,4,2};
    int half = findMoreHalfNumber(a, 9);
    printf("中间的数值:%d\n",half);
    return 0;
}
