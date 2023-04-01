#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node() {
        prev = NULL;
        next = NULL;
    }
};

Node *head;
Node *tail;

void insertNode(int data) {
    Node *nNode = new Node;
    nNode -> prev = tail;
    nNode -> data = data;
    tail = nNode;
    tail -> next = nNode;
}

void deleteNode(Node *node) {
    Node *tmp = node -> prev;
    tmp -> next = node -> next;

    free(node);
}

int main() {
    insertNode(3);
    insertNode(6);
    insertNode(7);

    Node *tmp = head;
    while(tmp -> next != NULL) {
        cout << tmp -> data << " ";
    }
}