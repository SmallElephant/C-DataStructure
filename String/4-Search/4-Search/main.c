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

//实现串str的逆转函数，如果str为空串，则什么都不做

void reverseStr(char str[]) {
    int len = (int)strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

//删除str中值为ch的所有字符，如果str为空串，或者串中不含值为ch的字符，则什么都不做.

void deleteStr(char str[], char ch) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void deleteStrFromPos(char str[], int pos, int len) {
    int sLen = (int)strlen(str);
    if (pos + len >= sLen) {
        str[pos] = '\0';
    } else {
        for (int i = pos + len; i < sLen; i++) {
            str[pos++] = str[i];
        }
        str[pos] = '\0';
    }
}


int main(int argc, const char * argv[]) {
//     char *str = "FlyElephant"; // 字符串常量，针对某个字符修改，报错
    char str[] = "FlyElephantChina";
    char pattern[] = "China";
    char replace[] = "Zhong";
    replaceStr(str, pattern, replace);
    printf("replace result:%s\n",str);
    
    char reStr[] = "abcd";
    reverseStr(reStr);
    printf("reverse result:%s\n", reStr);
    
    char delStr[] = "abcdeeffggee";
    deleteStr(delStr, 'e');
    printf("delete result:%s\n", delStr);
    
    char delPostion[] = "abcdefhijk";
    deleteStrFromPos(delPostion, 3, 3);
    printf("delete string from postion:%s\n",delPostion);
    return 0;
}
