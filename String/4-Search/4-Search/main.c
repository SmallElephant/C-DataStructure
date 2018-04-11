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
#include <stdbool.h>

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

//采用定长顺序存储表示串，编写一个函数，删除串中从下标i的字符开始，如果第i字符开始么有组从的j个字符，则有几个删除几个.

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

//采用顺序存储方式存储串，编写一个函数，将串str1中的下标i到下标j之间的子串（包含i和j两个位置上的字符）用str2串替换.

void replaceStrFromPos(char str[], int start, int end, char restr[]) {
    int sLen = (int)strlen(str);
    if (start >= sLen || end >= sLen) {
        return;
    }
    int j = 0;
    int relen = (int)strlen(restr);
    for (int i = start; i <= end; i++) {
        if (j < relen) {
            str[i] = restr[j++];
        }
    }
}

// 统计子串出现的次数,不考虑子串重叠，比如串aaaa，子串aaa考虑重叠出现的次数是2，不考虑是1
int numberOfSubstr(char str[], char subStr[]) {
    int i = 0;
    int k = 0;
    int j = 0;
    int sum = 0;
    int sLen = (int)strlen(str);
    int subLen = (int)strlen(subStr);
    while (i < sLen) {
        if (str[i] == subStr[j]) {
            i++;
            j++;
        } else {
            k++;
            j = 0;
            i = k;
        }
        if (j >= subLen) {
            j = 0;
            sum++;
        }
    }
    return sum;
}

char findFirstChar(char str1[], char str2[]) {
    int len1 = (int)strlen(str1);
    int len2 = (int)strlen(str2);
    char res = '\0';
    for (int i = 0; i < len1; i++) {
        bool isExist = false;
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                isExist = true;
            }
        }
        if (!isExist) {
            res = str1[i];
            break;
        }
    }
    return res;
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
    
    char origin[] = "abcdefghijk";
    char originRe[] = "fly";
    replaceStrFromPos(origin, 2, 4, originRe);
    printf("replace string from postion:%s\n",origin);
    
    char countStr[] = "aaaa";
    char countSubStr[] = "aaa";
    int sum = numberOfSubstr(countStr, countSubStr);
    printf("%s count in %s number is:%d\n",countSubStr, countStr, sum);
    
    char findStr1[] = "abcdefg";
    char findStr2[] = "abc";
    char findRes = findFirstChar(findStr1, findStr2);
    printf("%s first not in %s is %c\n",findStr1,findStr2,findRes);
    return 0;
}
