#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct Trie {
    bool finish;
    Trie* next[26];

    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for(int i = 0; i < 26; i++) {
            if(next[i]) delete next[i];
        }
    }

    void insert(const char* key) {
        if(*key == '\0') finish = true;
        else {
            int curr = *key - 'A';
            if(next[curr] == NULL) next[curr] = new Trie();
            next[curr] -> insert(key + 1);
        }
    }

    Trie* find(const char* key) {
        if(*key == '\0') return this;
        int curr = *key - 'A';
        if(next[curr] == NULL) return NULL;
        return next[curr] -> find(key + 1);
    }
};

struct cmp {
    bool operator() (pair<int, string> p1, pair<int, string> p2) {
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

int W, B, score, cnt;
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
char board[4][4];
bool visited[4][4];
Trie *root = new Trie;
map<string, int> m;
map<string, int> ans;
priority_queue<pair<int, string>, vector<pair<int, string> >, cmp> pq;

void saveWord(string str, int len) {
    if(len <= 2) m[str] = 0;
    else if(len <= 4) m[str] = 1;
    else if(len == 5) m[str] = 2;
    else if(len == 6) m[str] = 3;
    else if(len == 7) m[str] = 5;
    else m[str] = 11;
}

void dfs(string str, int x, int y) {
    if(str.length() > 8) return;
    if(!root -> find(str.c_str())) return;

    visited[x][y] = true;

    if(!ans[str] && m[str]) {
        pq.push(make_pair(str.length(), str));
        score += m[str];
        ans[str] = 1;
        cnt++;
    }

    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= 4 || 0 > ny || ny >= 4) continue;
        if(visited[nx][ny]) continue;

        dfs(str + board[nx][ny], nx, ny);
        visited[nx][ny] = false;
    }
}

int main() {
    cin >> W;
    string str;
    for(int i = 0; i < W; i++) {
        cin >> str;
        saveWord(str, str.length());
        root -> insert(str.c_str());
    }

    cin >> B;
    for(int b = 0; b < B; b++) {
        score = 0, cnt = 0;
        ans.clear();
        while(!pq.empty()) pq.pop();

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cin >> board[i][j];
            }
        }
 
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                memset(visited, false, sizeof(visited));
                str = board[i][j];
                dfs(str, i, j);
            }
        }

        cout << score << " " << pq.top().second << " " << cnt << endl;
    }
}