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

class List {
public:
    Node *head;
    Node *tail;
    int cnt;

    void insert(int data) {
        Node *nNode = new Node;
        tail->next = nNode;
        nNode->data = data;
        tail = nNode;
    }

    void deleteNode(Node *node) {
        Node *tmp = head;
        while(tmp -> next != NULL) {
            if(tmp->next == node) {
                tmp->next = node -> next;
            }
            tmp = tmp->next;
        }
    }

    void print() {
        Node *pos = head;
        while(pos != NULL) {
            cout << pos -> data << " ";
            pos = pos -> next;
        }
        cout << endl;
    }

    // void printSum() {
    //     cout << sum << endl;
    // }
};

int N, tmp;

int main() {
    List list;
    scanf("%d", &N);
    while(N--) {
        scanf("%1d", &tmp);
        list.insert(tmp);
    }
    //list.printSum();
}