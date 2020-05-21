#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100
using namespace std;

int M, N, sx, sy, sd, ex, ey, ed, ans;
int map[MAX][MAX];
bool visited[MAX][MAX][4];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

typedef struct {
    int x, y, dir;
} Robot;

// dir 1 = 오 / -1 = 왼
int turnDir(int cur_d, int dir) {
    if(dir == 1) {
        return (cur_d + 1) % 4;
    } else {
        return (cur_d - 1) < 0 ? 3 : cur_d - 1;
    }
}

int changeDir(int num) {
    if(num == 1) return 0; // 동
    else if(num == 2) return 2; // 서
    else if(num == 3) return 1; // 남
    else return 3; // 북
}

void bfs() {
    queue<Robot> q;
    Robot s = { sx - 1, sy - 1, changeDir(sd) };
    visited[sx - 1][sy - 1][changeDir(sd)] = true; 
    q.push(s);

    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int x = q.front().x;
            int y = q.front().y;
            int d = q.front().dir;
            q.pop();

            if((x + 1) == ex && (y + 1) == ey && d == changeDir(ed)) {
                ans = time;
                return;
            }

            // 방향 회전(오, 왼)    
            int right_dir = turnDir(d, 1);
            int left_dir = turnDir(d, -1);
            if(!visited[x][y][left_dir]) {
                Robot lr = { x, y, left_dir };
                visited[x][y][left_dir] = true;
                q.push(lr);
            }
            if(!visited[x][y][right_dir]) {
                Robot rr = { x, y, right_dir };
                visited[x][y][right_dir] = true;
                q.push(rr);
            }
        
            // 앞으로 3번, 2번, 1번 가기
            for(int i = 1; i <= 3; i++) {
                int nx = x + (dx[d] * i);
                int ny = y + (dy[d] * i);

                if(0 > nx || nx >= M || 0 > ny || ny >= N) continue;
                if(visited[nx][ny][d]) continue;
                if(map[nx][ny] == 1) break;

                Robot nr = { nx, ny, d };
                visited[nx][ny][d] = true;
                q.push(nr);
            }
        }
        time++;
    }

}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    scanf("%d %d %d", &sx, &sy, &sd);
    scanf("%d %d %d", &ex, &ey, &ed);

    memset(visited, false, sizeof(visited));
    bfs();

    printf("%d\n", ans);
}