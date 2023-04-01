#include <iostream>
#define MAX 5
using namespace std;

int ans = 0;
char map[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[26];

bool checkNum() {
    int lee, im;
    for(int i = 1; i < 26; i++) {
        if(visited[i]) {
            if(map[i / 5][i % 5] == 'Y') im++;
            else lee++;
        }
    }

    return lee > im;
}

bool checkMove() {
    
}

void dfs(int idx, int all) {
    if(all == 7) {
        if(checkNum()) {
            ans++;
        }
        return;
    }

    for(int i = idx; i < 25; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, all + 1);
        visited[i] = false;
    }
}

int main() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    dfs(0, 0);
    printf("%d\n", ans);
}

/**
 * 맨 처음에는 dfs 백트래킹으로 구현했다가.. 틀린 문제.. 다시 풀어보기..
 * 
 * "서로 가로나 세로로 반드시 인접해야한다"
 * 한 점을 기준으로 dfs, bfs로는 십자가 모양을 찾을 수 없음!!
 * 그래서 25 C 7로 7개 선정해야함!
 * 
 * 0  1  2  3  4 
 * 5  6  7  8  9
 * 10 11 12 14 14
 * 15 16 17 18 19
 * 20 21 22 23 24
 * **/