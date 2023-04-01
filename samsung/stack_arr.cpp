#include <iostream>
using namespace std;

int stack[10];
int idx = 0;

void push(int data) {
    stack[idx++] = data;
}

int pop() {
    return stack[--idx];
}

int main() {
    push(3);
    push(4);
    push(5);
    cout << pop();
    cout << pop();
    cout << pop();
}


