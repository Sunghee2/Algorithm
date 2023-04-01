#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node() {
        next = NULL;
    }
}

Node *head;
Node *tail;
Node stack;

// stack -> next가 가장 마지막에 저장된 원소가 되도록 설정
// tail이 가장 처음 들어온 원소
void push(int data) {
    Node *nNode = new Node;
    nNode -> data = data;
    nNode -> next = stack -> next;
    stack -> next = nNode;
}

int Top() {
    if(stack.next != NULL) {
        return stack.next -> data;
    }
}

void pop() {
    if(stack.next != NULL) {
        stack.next = stack.next -> next;
    }
}
// stack 포인터가 아닌 것은 변하지 않기 때문
// 절대적인 고유한 일이 있기 때문에