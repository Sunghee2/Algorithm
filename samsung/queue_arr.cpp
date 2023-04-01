#include <iostream>

int arr[50000];
int idx = 0;

void enQueue(int data) {
    arr[idx++] = data;
}

int deQueue() {
    int res = arr[0];
    for(int i = 1; i < idx; i++) {
        arr[i - 1] = arr[i];
    }
    return res;
}

int main() {
    
}