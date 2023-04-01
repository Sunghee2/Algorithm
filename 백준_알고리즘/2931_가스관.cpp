#include <iostream>
#define MAX 26
#define E 0
#define W 1
#define N 2
#define S 3
using namespace std;

int R, C, sx, sy, dir;
char map[MAX][MAX];
// 동 서 북 남
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void check_empty() {
    int x = -1, y = -1;
    for(int i = 0; i < 4; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];

        if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;
        if(map[nx][ny] == '.') continue;

        x = nx, y = ny, dir = i;
    }

    if(x != -1) {
        if(map[x][y] == '|') {
            x += dx[dir];
        } else if(map[x][y] == '-') {
            y += dy[dir];
        } else if(map[x][y] == '+') {
            x += dx[dir];
            y += dy[dir];
        } else if(map[x][y] == '1') {
            if(dir == W) {
                x += 1;
                y -= 1;
                dir = S;
            } else if(dir == N) {
                x -= 1;
                y += 1;
                dir = E;
            }
        } else if(map[x][y] == '2') {
            if(dir == S) {
                x += 1;
                y += 1;
                dir = E;
            } else if(dir == W) {
                x -= 1;
                y -= 1;
                dir = N;
            }
        } else if(map[x][y] == '3') {
            if(dir == E) {
                x -= 1;
                y += 1;
                dir = N;
            } else if(dir == S) {
                x += 1;
                y -= 1;
                dir = W;
            }
        } else if(map[x][y] == '4') {
            if(dir == E) {
                x += 1;
                y += 1;
                dir = S;
            } else if(dir == N) {
                x -= 1;
                y -= 1;
                dir = W;
            }
        }
    }
}

int main() {
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'M') sx = i, sy = j;
        }
    }

    
}