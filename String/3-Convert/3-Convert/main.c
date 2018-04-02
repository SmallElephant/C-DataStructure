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
    return 0;
}
