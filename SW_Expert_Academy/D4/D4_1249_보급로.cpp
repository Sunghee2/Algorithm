#include <iostream>
#include <cstring>
#include <queue>
#define MAX 101
using namespace std;

typedef struct {
    int x, y;
} Point;

int tc, n;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {
    queue<Point> q;
    Point p = { 0, 0 };
    visited[0][0] = true;
    q.push(p);

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(!visited[nx][ny] || dist[nx][ny] > dist[x][y] + map[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + map[nx][ny];
                    Point np = { nx, ny };
                    q.push(np);
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cin >> n;
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        memset(dist, 0, sizeof(dist));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%1d", &map[i][j]);
            }
        }

        bfs();

        cout << "#" << t << " " << dist[n - 1][n - 1] << endl;

    }
}