#include <iostream>
#include <queue>
#define MAX 201
using namespace std;

int N, r1, c1, r2, c2;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
bool visited[MAX][MAX];

typedef struct {
    int x, y;
} Point;

int bfs() {
    queue<Point> q;
    Point s = {r1, c1};
    visited[r1][c1] = true;
    q.push(s);

    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            if(x == r2 && y == c2) return time;

            for(int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
                if(visited[nx][ny]) continue;

                Point n = {nx, ny};
                q.push(n);
                visited[nx][ny] = true;
            }
        }
        time++;
    }

    return -1;
}

int main() {
    scanf("%d", &N);
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    printf("%d\n", bfs());
}