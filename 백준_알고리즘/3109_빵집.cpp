#include <iostream>
#define MAX 10001
using namespace std;

int R, C, cnt = 0;
bool done;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1, 0, 1 };
int dy[4] = { 1, 1, 1 };

void dfs(int x, int y) {
    visited[x][y] = true;
    if(y == C - 1) {
        done = true;
        cnt++;
        return;
    }

    for(int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;
        if(visited[nx][ny] || map[nx][ny] == 'x') continue;
    
        dfs(nx, ny);
        if(done) return;
    }
}

int main() {
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    for(int i = 0; i < R; i++) {
        done = false;
        dfs(i, 0);
    }

    printf("%d\n", cnt);
}

/**
 * 최대한 안 겹치게 가기 위해서 오른쪽 위 대각선, 오른쪽, 오른쪽 아래 대각선 순으로 가야함
 * 그리고 백트래킹 XX
 * 한 번 도착하면 그냥 끝임. 또 백트래킹으로 돌았다가 한 번 출발했는데 여러번 도착한 것으로 개수가 중복으로 세질 수 있음
 * 그래서 bool 값을 두어서 끝난지 체크해야함
 * **/