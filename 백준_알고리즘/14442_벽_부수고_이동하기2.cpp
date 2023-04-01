#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int n, m, k;
int map[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX][11];

typedef struct {
    int x, y, num, dist;
} Point;

int bfs() {
    queue<Point> q;
    Point start = { 1, 1, k, 0 };
    q.push(start);
    visited[1][1][k] = true;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int num = q.front().num;
        int dist = q.front().dist;
        q.pop();

        if(x == n && y == m) return dist + 1;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(1 > nx || nx > n || 1 > ny || ny > m) continue;
            if(visited[nx][ny][num]) continue;

            if(!map[nx][ny]) {
                Point new_point = { nx, ny, num, dist + 1 };
                q.push(new_point);
                visited[nx][ny][num] = true;
            } else if(num) {
                Point new_point = { nx, ny, num - 1, dist + 1 };
                q.push(new_point);
                visited[nx][ny][num] = true;
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf(" %1d", &map[i][j]);
        }
    }

    printf("%d\n", bfs());
}

/**
 * 벽 부수고 이동하기 문제는 1개 벽만 없애는 거지만
 * 이 문제에서는 입력받은 k개 벽을 제거할 수 있음
 * 
 * 그래서 visited[n][m][k]로 방문체크를 하고
 * num(k)가 0 이상이면 1제외해서 큐에 다시 넣는 식으로만 바꿔주면 됨.
 * **/