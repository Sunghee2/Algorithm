#include <iostream>
#include <string>
#define MAX 5
using namespace std;

int tc, n;
string input, ans;
char map[MAX][MAX];
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, -1, -1, 1, 1 };

void dfs(int x, int y, string word, int idx) {
    if(idx == word.size()) {
        ans = "YES";
        return;
    }

    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < MAX && 0 <= ny && ny < MAX) {
            if(map[nx][ny] == word.at(idx)) {
                dfs(nx, ny, word, idx + 1);
            }
        }
    }
}

void findWord(string word) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(map[i][j] == word.at(0)) {
                dfs(i, j, word, 1);
            }
        }
    }
}

int main() {
    cin >> tc;
    for(int t = 0; t < tc; t++) {
        for(int i = 0; i < MAX; i++) {
            for(int j = 0; j < MAX; j++) {
                cin >> map[i][j];
            }
        }

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> input;

            ans = "NO";
            findWord(input);  

            cout << input << " " << ans << endl;
        }
    }
}

/**
 * 시간복잡도 : O(8^n) 으로 시간초과남
 * **/