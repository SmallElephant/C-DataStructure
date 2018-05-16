//
//  main.c
//  1-BaseSearch
//
//  Created by FlyElephant on 2018/5/16.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include "BaseSearch.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {2,4,6,8,10,14,15,17,20,21};
    int res = binarySeach(a, 0, 9, 2);
    if (res >= 0) {
        printf("target number index is:%d\n",res);
    } else {
        printf("number is not found\n");
    }
    return 0;
}
