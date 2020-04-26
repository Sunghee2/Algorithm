#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int n, m;
int map[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX][2];

typedef struct {
    int x, y, flag, dist;
} Point;

void printMap() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }    
}

int bfs() {
    queue<Point> q;
    Point start = { 1, 1, 1, 0 };
    q.push(start);
    visited[1][1][1] = true;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int flag = q.front().flag;
        int dist = q.front().dist;
        q.pop();

        if(x == n && y == m) return dist + 1;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(1 > nx || nx > n || 1 > ny || ny > m) continue;
            if(visited[nx][ny][flag]) continue;

            if(!map[nx][ny]) {
                Point new_point = { nx, ny, flag, dist + 1 };
                q.push(new_point);
                visited[nx][ny][flag] = true;
            } else if(flag) {
                Point new_point = { nx, ny, 0, dist + 1 };
                q.push(new_point);
                visited[nx][ny][0] = true;
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf(" %1d", &map[i][j]);
        }
    }

    printf("%d\n", bfs());
}

/**
 * 14923 미로 탈출이랑 같은 문제
 * **/