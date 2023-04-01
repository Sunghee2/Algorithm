#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        next = NULL;
    }
};

Node *head;
Node *tail;

void enQueue(int data) {
    Node *nNode = new Node;
    nNode -> data = data;
    tail -> next = nNode;
    tail = nNode;
}

int front() {
    if(head == tail) return -1;
    return head -> data;
}

void deQueue() {
    if(head == tail) return;
    head = head -> next;
}