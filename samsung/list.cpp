#include<iostream>
using namespace std;

typedef struct {
    int data, Node* next = nullptr;
} Node;

class List {

    Node *head;
    Node *tail;
    int size = 0;

    void add(int data) {
        Node n = { data, nullptr };

        size++;
        if(head == nullptr) {
            head = n;
            tail = n;
        } else {
            tail -> next = n;
            tail = tail -> next;
        }
    }

    void delete(int data) {
        if(!tail) return;

        Node *ptr = head;

        while(ptr != nullptr) {
            if(ptr -> data == data) {
                break;
            } else {
                ptr = 
            }
        }
    }
}

int main() {
    List<int> list;
    list.add(3);
    list.add(6);
    list.add(8);
}