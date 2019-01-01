//
//  main.c
//  06-队列(链式存储)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

int main(int argc, const char * argv[]) {
    Queue q;
    initQueue(&q);
    for (char ch='a'; ch <= 'z'; ch++) {
        enQueue(&q, ch);
    }
    resetQueue(&q);
    while (!isQueueEmpty(&q)) {
        printf("%c ",deQueue(&q));
    }
    return 0;
}
