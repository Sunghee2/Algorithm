#include <iostream>
#include <cstring>
#define MAX 51
using namespace std;

typedef struct {
    int x, y;
} Point;

int N, M;
char map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool flag = false;

void print_dist() {
    printf("=================\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }    
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;
        if(map[nx][ny] != map[x][y]) continue;
        if(dist[nx][ny] == -1) {
            dist[nx][ny] = dist[x][y] + 1;
            dfs(nx, ny);
            dist[nx][ny] = 0;
        } else {
            if(dist[x][y] - dist[nx][ny] >= 3) {
                flag = true;
            }
        }
    }
} 

int main() {
    memset(dist, -1, sizeof(dist));

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!visited[i][j]) {
                dist[i][j] = 0;
                dfs(i, j);
                dist[i][j] = -1;
                if(flag) {
                    printf("Yes\n");
                    return 0;
                }
            }
        }
    }

    printf("No\n");
}

/**
 * 사이클 찾는 문제
 * dfs 이용
 * -1로 초기화 시키고 dfs돌면서 방문안한 곳(-1) 에는 dist + 1함
 * 방문한 곳은 현재 위치와 3이상 차이나는지 확인
 * **/