#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int l, r, c;
char building[31][31][31];
bool visited[31][31][31];
int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };

typedef struct {
    int x, y, z, dist;
} Point;

Point s, e;

int bfs(Point start, Point end) {
    queue<Point> q;
    q.push(start);
    visited[start.z][start.x][start.y] = true;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int dist = q.front().dist;
        q.pop();

        if(x == end.x && y == end.y && z == end.z) {
            return dist;
        }

        for(int i = 0; i < 6; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            int new_z = z + dz[i];

            if(0 <= new_x && new_x < r && 0 <= new_y && new_y < c && 0 <= new_z && new_z < l && !visited[new_z][new_x][new_y] && building[new_z][new_x][new_y] != '#') {
                visited[new_z][new_x][new_y] = true;
                Point new_p = { new_x, new_y, new_z, dist + 1 };
                q.push(new_p);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &l, &r, &c);

    while(l != 0 || r != 0 || c != 0) {
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    scanf(" %c", &building[i][j][k]);
                    if(building[i][j][k] == 'S') {
                        s.x = j; 
                        s.y = k; 
                        s.z = i; 
                        s.dist = 0;
                    } else if(building[i][j][k] == 'E') {
                        e.x = j; 
                        e.y = k; 
                        e.z = i; 
                        e.dist = 0;
                    }
                }
            }
        }

        int ans = bfs(s, e);
        if(ans == -1) {
            printf("Trapped!\n");
        } else {
            printf("Escaped in %d minute(s).\n", ans);
        }

        scanf("%d %d %d", &l, &r, &c);
    }
}

/**
 * 3차원 bfs문제
 * 3차원만 잘 구현하면 되는 문제.. 당장 몇 달 전에 못 풀었던 문제인데 감격ㅠ
 * 입력받을 때 s, e기억해서 bfs에 전달
 * s 큐에 넣고 x,y,z 이동하면서 벽이 아니고 방문하지 않은 것은 다시 큐에 넣음.
 * e에 가게 된다면 거리 리턴
 * 큐를 그냥 빠져나오면 갈 수 없는 것 
 * **/