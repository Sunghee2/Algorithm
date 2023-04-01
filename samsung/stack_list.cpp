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

void push(int data) {
    Node *nNode = new Node;
    if(!head) {
        head = nNode;
    } else {
        
    }
    tail -> next = nNode;
    nNode -> data = data;
    tail = nNode;
}

int pop() {
    Node *tmp = head;

    int res;
    while(tmp -> next != NULL) {
        cout << tmp -> data << endl;
        if(tmp -> next == tail) {
            res = tail -> data;
            tmp -> next = NULL;
        }
        tmp = tmp -> next;
    }
    return res;
}

int main() {
    push(3);
    push(6);
    push(7);
    // pop();
    // pop();
    // pop();
}