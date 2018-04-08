//
//  main.c
//  4-Search
//
//  Created by FlyElephant on 2018/4/8.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.将串str中所有值为ch1的字符串转换成ch2的字符，如果str为空串，或者串中不含值为ch1的字符，则什么都不做

void replaceStr(char *str, char *pattern, char *replace) {
    int sLen = (int)strlen(str);
    int pLen = (int)strlen(pattern);
    for (int i = 0; i < sLen; i++) {
        int j = 0;
        for (j = 0; j < pLen; j++) {
            if (str[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == pLen) {
            for (int h = 0; h < pLen; h++) {
                str[i + h] = replace[h];
            }
        }
    }
}


int main(int argc, const char * argv[]) {
//     char *str = "FlyElephant"; // 字符串常量，针对某个字符修改，报错
    char str[] = "FlyElephantChina";
    char pattern[] = "China";
    char replace[] = "Zhong";
    replaceStr(str, pattern, replace);
    printf("replace result:%s\n",str);
//    char str[] = "Hello world!";
//    for (char* p = str; p = strchr(p, 'l'); ++p) {
//        *p = 'E';
//    }
//     printf("%s\n", str);  // He11o wor1d!
    return 0;
}
