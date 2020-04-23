#include <iostream>
#include <cstring>
#include <map>
#define MAX 101
using namespace std;

int n, m, hour = 0, all = 0;
int paper[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX];
map<pair<int, int>, int> cheese;

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= n || 0 > ny || ny >= m || visited[nx][ny]) continue;

        if(paper[nx][ny]) cheese[make_pair(nx, ny)]++;
        else dfs(nx, ny);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {
           scanf(" %d", &paper[i][j]);
           if(paper[i][j]) all++;
       }
    }

    while(all > 0) {
        cheese.clear();
        memset(visited, false, sizeof(visited));

        dfs(0, 0);

        int sum = 0;
        map<pair<int, int>, int>:: iterator it;
        for(it = cheese.begin(); it != cheese.end(); it++) {
            if(it -> second >= 2) {
                paper[it -> first.first][it -> first.second] = 0;
                sum++;
            }
        }

        all -= sum;
        hour++;
    }

    printf("%d\n", hour);
}

/**
 * 2636 치즈 문제에서
 * vector로 치즈 수집했던 것을 map으로 바꿔서
 * 2번 만나는 경우만 체크해주면 삭제하는 것임.
 * 
 * 치즈 외부 공기에서 dfs 돌아서
 * 치즈를 2번 만나면 삭제
 * **/