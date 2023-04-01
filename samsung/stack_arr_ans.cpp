int stack[50000];
int top = 0;

void push(int data) {
    if(top >= 50000) return;
    stack[top] = data;
    top++;
}

int Top() {
    if(top == 0) return -1;
    return stack[top - 1];
}

void pop() {
    if(top > 0) return;
    top--;
    return;
}

