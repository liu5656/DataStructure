//
//  main.cpp
//  LoopQueue_c++
//
//  Created by lj on 17/1/9.
//  Copyright © 2017年 lj. All rights reserved.
//

#include <iostream>


#define MAXSIZE 100

typedef struct {
    char *base;
    int front;
    int rear;
} SqQueue;




bool initQueue(SqQueue &queue) {
    
    queue.base = (char *)malloc(MAXSIZE * sizeof(char));
    if (!queue.base) {
        return false;
    }
    queue.front = queue.rear = 0;
    return true;
}

int QueueLength(SqQueue &queue) {
    return (MAXSIZE - queue.front + queue.rear) % MAXSIZE;
}

bool EnQueue(SqQueue &queue, char e) {
    
    if ((queue.rear + 1) % MAXSIZE == queue.front) {
        return false; // 满
    }
    queue.base[queue.rear] = e;
    queue.rear = (queue.rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &queue, char &e) {
    
    if (queue.rear == queue.front) {
        return false; // 空
    }
    e = queue.base[queue.front];
    queue.front = (queue.front + 1) % MAXSIZE;
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    SqQueue queue;
    initQueue(queue);
    int c = 0;
    while ((c = getchar()) != '\n') {
        EnQueue(queue, c);
    }
    printf("\n%d\n",QueueLength(queue));
    char e;
    while (queue.rear != queue.front) {
        DeQueue(queue, e);
        printf("%c", e);
    }
    printf("\n");
    
    
    return 0;
}
