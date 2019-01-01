//
//  main.c
//  03-栈(链)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>
#include "stackList.h"

int main(int argc, const char * argv[]) {
    
    Stack s;
    initStack(&s);
    for (char ch = 'A'; ch <= 'M'; ch++) {
        push(&s, ch);
    }
    
    //复位
    resetStack(&s);
    
    while (!isStackEmpty(&s)) {
        printf("%c ",pop(&s));
    }
    
    //销毁
    clearStack(&s);
    
    return 0;
}
