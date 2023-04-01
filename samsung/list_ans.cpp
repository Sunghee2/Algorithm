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

void insertNode(int data) {
    Node *nNode = new Node;
    tail -> next = nNode;
    nNode -> data = data;
    tail = nNode;
}

void deleteNode(Node *node) {
    Node *tmp = head;

    while(tmp -> next != NULL) {
        if(tmp -> next == node) {
            tmp -> next = node -> next;
        }
        tmp = tmp -> next;
    }
}

int main() {
    insertNode(3);
    insertNode(2);
    insertNode(6);
    insertNode(8);


    // Node *tmp = head;
    // while(tmp -> next != NULL) {
    //     cout << tmp -> data << " ";
    // }
}