//
//  main.c
//  02-栈
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

int main(int argc, const char * argv[]) {
    Stack s;
    initStack(&s, 100);
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!isStackFull(&s)) {
            push(&s, ch);
        }
    }
    
    while (!isStackEmpty(&s)) {
        printf("%c\t",pop(&s));
    }
    return 0;
}
