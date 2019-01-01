//
//  main.c
//  05-队列(线式存储)
//
//  Created by Ne on 2018/11/7.
//  Copyright © 2018年 Ne. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

int main(int argc, const char * argv[]) {
    Queue q;
    initQueue(&q,26);
    for (char ch='a'; ch <= 'z'; ch++) {
        if (!isQueueFull(&q)) {
            enQueue(&q, ch);
        }
    }
    while (!isQueueEmpty(&q)) {
        printf("%c ",deQueue(&q));
    }
    return 0;
}
