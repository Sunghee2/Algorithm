// #include <iostream>
// using namespace std;

// class Node {
// public:
//     char data;
//     Node* prev;
//     Node* next;
//     Node() {
//         next = NULL;
//     }
// };

// int T, cur_idx = 0;
// string s;
// Node *head;
// Node *tail;

// void insertNode(char a, int idx) {
//     cout << a << " " << idx;
//     Node *nNode = new Node;
//     Node *tmp = head;
//     while(idx--) {
//         tmp = tmp -> next;  
//     }
//     tmp -> prev = nNode;
//     nNode -> next = tmp;
//     nNode -> data = a;
//     nNode -> prev = tmp -> prev -> next;
//     tmp -> prev -> next = nNode;
// }

// void deleteNode(int idx) {
//     Node *tmp = head;
//     while(idx--) {
//         tmp = tmp -> next;
//     }
//     tmp -> prev -> next = tmp -> next;
//     tmp -> next -> prev = tmp -> prev;
// }

// int main() {
//     cin >> T;
//     for(int tc = 0; tc < T; tc++) {
//         cin >> s;
//         for(int i = 0; i < s.length(); i++) {
//             switch(s[i]) {
//                 case '<':
//                     // cur_idx = cur_idx - 1 < 0? 0 : cur_idx - 1;
//                     break;
//                 case '>':
//                     // cur_idx = cur_idx + 1;
//                     break;
//                 case '-':
//                     deleteNode(cur_idx);
//                     break;
//                 default:
//                     insertNode(s[i], cur_idx++);
//                     break;
//             }
//         }
//     }


// }


#include <iostream>

class Node {
public:
    char data;
    Node *prev;
    Node *next;
    Node() {
        prev = 0;
        next = 0;
    }
};

Node head;
Node tail;
char str[1000001];

int main() {
    int T;
    scanf(" %d", &T);
    head.data = -1;
    tail.data = -1;

    for(int tc = 0; tc < T; tc++) {
        head.next = &tail;
        tail.prev = &head;

        scanf("%s", str);
        Node* cur;
        cur = &head;

        for(int i = 0; str[i]; i++) {
            if(str[i] == '<') {
                if(cur != &head) cur = cur -> prev;
            } else if(str[i] == '>') {
                if(cur -> next != &tail) cur = cur -> next;
            } else if(str[i] == '-') {
                if(cur != &head) {
                    Node* tmp = cur;
                    cur -> prev -> next = cur -> next;
                    cur = cur -> prev;
                    free(tmp);
                }
            } else {
                Node *nNode = new Node;
                nNode -> data = str[i];
                nNode -> prev = cur;
                nNode -> next = cur -> next;
                cur -> next = nNode;
                cur = nNode;
            }
        }
        Node* t = head.next;
        while(t -> data != -1) {
            printf("%c", t -> data);
            t = t -> next;
        }
        printf("\n");
    }
}