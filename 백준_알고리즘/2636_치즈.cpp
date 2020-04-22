#include <iostream>
#include <vector>
#include <cstring>
#define MAX 101
using namespace std;

int n, m, all = 0, cheese = 0, hour = 0;
int map[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX];
vector<pair<int, int> > v;

void printMap() {
    printf("=================\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= n || 0 > ny || ny >= m || visited[nx][ny]) continue;

        if(map[nx][ny]) v.push_back(make_pair(nx, ny));
        else dfs(nx, ny);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %d", &map[i][j]);
            if(map[i][j]) all++;
        }
    }

    while(all > 0) {
        v.clear();
        memset(visited, false, sizeof(visited));

        dfs(0, 0);

        cheese = 0;
        for(int i = 0; i < v.size(); i++) {
            if(map[v[i].first][v[i].second]) {
                map[v[i].first][v[i].second] = 0;
                cheese++;
            }
        }

        hour++;
        all -= cheese;
    }

    printf("%d\n%d\n", hour, cheese);
}

/**
 * dfs/bfs 문제
 * 
 * 공기와 접촉된 칸을 어떻게 찾을까 고민했었는데
 * 처음에는 상하좌우에 0이 있으면 접촉된 칸이라고 판단하려고 했는데
 * 구멍을 따로 구분하기가 힘들었다..
 * 
 * 생각해보니 0으로 dfs돌려서 만나는 부분이 구멍 외의 접촉된 칸이었음.
 * 그래서 1을 만나면 벡터에 넣어주고 dfs 끝나고 0으로 바꿔줌
 * **/