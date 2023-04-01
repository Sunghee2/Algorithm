#include <iostream>

int queue[50000];
int head = 0, tail = 0;

void enQueue(int data) {
    if(tail == 50000) return;
    queue[tail] = data;
    tail++;
}

int front() {
    if(head == tail) return -1;
    return queue[head];
}

void deQueue() {
    if(head == tail)  //queue가 비어있다
        return;
    head++;
}