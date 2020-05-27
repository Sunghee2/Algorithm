#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

int M, N, num = 0, sx, sy, ans;
char map[MAX][MAX];
bool visited[MAX][MAX][32];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct {
    int x, y, cur_state;
} Point;

void bfs(int sx, int sy) {
    queue<Point> q;
    Point sp = { sx, sy, 0 };
    visited[sx][sy][0] = true;
    q.push(sp);

    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int x = q.front().x;
            int y = q.front().y;
            int cur_state = q.front().cur_state;
            q.pop();

            if(map[x][y] == 'E' && cur_state == (1 << num) - 1) {
                ans = time;
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;
                if(map[nx][ny] == '#') continue;

                if('0' <= map[nx][ny] && map[nx][ny] <= '5') {
                    int new_state = cur_state | (1 << (map[nx][ny] - '0'));
                    if(visited[nx][ny][new_state]) continue;
                    visited[nx][ny][new_state] = true;
                    Point np = { nx, ny, new_state };
                    q.push(np);
                } else {
                    if(visited[nx][ny][cur_state]) continue;
                    visited[nx][ny][cur_state] = true;
                    Point np = { nx, ny, cur_state };
                    q.push(np);                    
                }
            }
        }
        time++;
    }
}

int main() {
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'X') map[i][j] = num++ + '0';
            else if(map[i][j] == 'S') {
                sx = i;
                sy = j; 
                map[i][j] = '.';
            }
        }
    }

    bfs(sx, sy);
    printf("%d\n", ans);
}

/**
 * 비트마스크 사용
 * 
 * 단순히 방문한 물건 개수를 세면 중복될 수 있어서
 * 각 물건마다 번호 부여 0부터~최대 4까지 --> 방문할 때마다 비트를 이용해서 방문체크
 * **/