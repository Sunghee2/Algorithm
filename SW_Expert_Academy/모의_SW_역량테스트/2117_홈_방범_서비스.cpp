#include <iostream>
#include <cstring>
#include <queue>
#define MAX 21
using namespace std;

typedef struct {
    int x, y;
} Point;

int T, N, M, house;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int sx, int sy) {
    queue<Point> q;
    Point s = { sx, sy };
    visited[sx][sy] = true;
    q.push(s);

    int cnt = 0;
    int k = 0;
    while(k++ <= N) {
        int size = q.size();
        while(size--) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            if(map[x][y]) cnt++;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
                if(visited[nx][ny]) continue;

                Point p = { nx, ny };
                visited[nx][ny] = true;
                q.push(p);
            }
        }

        int cost = k * k + (k - 1) * (k - 1);
        if((cnt * M) - cost >= 0) house = cnt > house ? cnt : house;
    }
}

void check() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            memset(visited, false, sizeof(visited));
            bfs(i, j);
        }
    }
}

int main() {
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                scanf(" %d", &map[i][j]);
            }
        }

        house = 0;
        check();
        printf("#%d %d\n", tc, house);
    }
}

/**
 * 마름모 그리는게 주..인 문제
 * 이전에 비슷한 문제를 풀었는데 그 때는 마름모 가장자리를 그려서 가장자리 닿으면 종료해서 그 안에 개수 세는 식으로 했는데
 * 이거는 계속 크기가 증가하다보니 위 방법이 비효율적일 것 같았음
 * 
 * 마름모를 생각해보면
 * 방문한 곳말고 각 가장자리에서 위, 아래, 양 옆 방향으로 나아가면 크기를 키울 수 있음.
 * **/