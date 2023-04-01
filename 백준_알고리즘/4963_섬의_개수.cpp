#include <iostream>
#include <cstring>
#define MAX 51
using namespace std;

int w = 1, h = 1;
int map[MAX][MAX];
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };
bool visited[MAX][MAX];

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= h || 0 > ny || ny >= w) continue;
        if(visited[nx][ny] || map[nx][ny] == 0) continue;

        dfs(nx, ny);
    }
}

int check() {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!visited[i][j] && map[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    while(1) {
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0) break;
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf(" %d", &map[i][j]);
            }
        }

        printf("%d\n", check());
    }
}

/**
 * bfs,dfs 문제
 * 특별한 것 그냥 상하좌우 + 대각선까지 확인해야된다는 점
 * **/