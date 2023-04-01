#include <iostream>
#include <queue>
#define MAX 11
using namespace std;

int N, M;
char map[MAX][MAX];
pair<int, int> blue, red;
bool visited[MAX][MAX][MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct {
    int bx, by, rx, ry;
} Point;

int bfs() {
    queue<Point> q;
    Point sp = { blue.first, blue.second, red.first, red.second };
    visited[blue.first][blue.second][red.first][red.second] = true;
    q.push(sp);

    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        time++;
        while(size--) {
            int bx = q.front().bx;
            int by = q.front().by;
            int rx = q.front().rx;
            int ry = q.front().ry;
            q.pop();

            printf("blue(%d,%d), red(%d,%d)\n", bx, by, rx, ry);

            for(int i = 0; i < 4; i++) {
                int nbx = bx, nby = by, nrx = rx, nry = ry;
                bool flag = false;
                while(1) {
                    if (0 > nbx + dx[i] || nbx + dx[i] >= N || 0 > nby + dy[i] || nby + dy[i] >= M || map[nbx + dx[i]][nby + dy[i]] == '#') break;
                    else {
                        nbx += dx[i];
                        nby += dy[i];
                        if (map[nbx][nby] == 'O') {
                            flag = true;
                            break;
                        }
                    }
                }


                // blue가 hole에 빠졌을 때
                if(flag) continue;

                while (1) {
                    if (0 > nrx + dx[i] || nrx + dx[i] >= N || 0 > nry + dy[i] || nry + dy[i] >= M || map[nrx + dx[i]][nry + dy[i]] == '#') break;
                    else {
                        nrx += dx[i];
                        nry += dy[i];
                        if (map[nrx][nry] == 'O') return time;
                    }
                }

                if(nbx == nrx && nby == nry) {
                    if(i == 0) {
                        if(ry < by) nry--;
                        else nby--;
                    } else if(i == 1) {
                        if(ry > by) nry++;
                        else nby++;
                    } else if(i == 2) {
                        if(rx > bx) nrx++;
                        else nbx++;
                    } else {
                        if(rx < bx) nrx--;
                        else nbx--;
                    }
                }
                if (visited[nbx][nby][nrx][nry]) continue;
                visited[nbx][nby][nrx][nry] = true;
                Point np = { nbx, nby, nrx, nry };
                q.push(np);
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'B') {
                blue = make_pair(i, j);
                map[i][j] = '.';
            } else if(map[i][j] == 'R') {
                red = make_pair(i, j);
                map[i][j] = '.';
            }
        }
    }

    printf("%d\n", bfs());
}

/**
 * blue, red를 visited 4차원으로 만들어서 체크함.
 * bfs에서 첫번째 무한루프를 통해서 새로 움직여야하는 blue값을 갱신해줌
 * 만약 홀에 빠지면 flag를 트루로 바꿔서 다음 로직 실행안되도록 함
 * 두번째 while(1)을 통해서 red값 갱신함
 * 만약 여기서 홀에 빠지면 현재 time값을 리턴시킴
 * 
 * 만약 새로 갱신시킨 red, blue값이 같다면! 값을 바꿔줘야함
 * 원래 값이 어느 것이 먼저였냐에 따라서 값을 바꿔줌
 * 예를 들어 아래와 같은 경우
 * ...RB 이런 식으로 된 경우 위의 로직으로 왼쪽으로 이동시키면 둘 다 0, 0이 되버림.
 * 그래서 R, B가 원래 어느 위치에 있었냐에 따라 값을 다시 바꿔줘야함.
 * 
 * 이렇게 최종 갱신 값을 visited했는지 확인하고 큐에 넣음.
 * **/