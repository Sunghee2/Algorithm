#include<iostream>
#define MAX 100000
using namespace std;

int N, ans;
bool flag;
char arr[MAX][81];
 
struct trie {
    trie* t[26];
    int cnt;
    bool end;
    
    trie() {
        for (int i = 0; i < 26; ++i) {
            t[i] = nullptr;
        }
        cnt = 0;
        end = false;
    }

    ~trie() {
        for (int i = 0; i < 26; ++i) 
            if (t[i] != nullptr)
                delete t[i];
    }
 
    void insert(char* str) {
        if (*str == '\0') {
            end = true;
            return;
        }
            
        int cur = *str - 'a';
        if (t[cur] == nullptr) {
            t[cur] = new trie();
            cnt++;
        }
        t[cur] -> insert(str + 1);
    }
 
    void search(char* str) {
        if (*str == '\0')
            return;
 
        if(flag) {
            flag = false;
            ans++;
        } else {
            if(end) ans++;
            else if(cnt > 1) ans++;
        }
            
        int cur = *str - 'a';
        t[cur] -> search(str + 1);
    }
};
 
int main() {
    while (scanf(" %d", &N) != -1) {
        ans = 0;
        trie* root = new trie();
       
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            root->insert(arr[i]);
        }
            
        for (int i = 0; i < N; i++) {
            flag = true;
            root -> search(arr[i]);
        }
 
        printf("%.2f\n", (double)ans / (double)N);
        delete root;
    }
}
