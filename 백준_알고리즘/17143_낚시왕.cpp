#include <iostream>
#include <cstring>
#define MAX 101
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
using namespace std;

typedef struct {
    int speed, direction, size;
} Shark;

int R, C, m, sum = 0;
Shark sea[MAX][MAX] = {};
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int changeDirection(int d) {
    if(d == UP) return DOWN;
    else if(d == DOWN) return UP;
    else if(d == RIGHT) return LEFT;
    else return RIGHT;
}

void moveShark() {
    Shark tmp_sea[MAX][MAX] = {};
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(sea[i][j].size > 0) {
                int nr = i, nc = j;
                int distance = sea[i][j].direction < 2? sea[i][j].speed % ((R - 1) * 2) : sea[i][j].speed % ((C - 1) * 2);
                while(distance-- > 0) {
                    int d = sea[i][j].direction;

                    if(0 > nr + dx[d] || nr + dx[d] >= R || 0 > nc + dy[d] || nc + dy[d] >= C) {
                        d = changeDirection(d);
                        sea[i][j].direction = d;
                    }

                    nr += dx[d];
                    nc += dy[d];
                }

                if(tmp_sea[nr][nc].size > 0) {
                    tmp_sea[nr][nc] = tmp_sea[nr][nc].size > sea[i][j].size? tmp_sea[nr][nc] : sea[i][j];
                } else {
                    tmp_sea[nr][nc] = sea[i][j];
                }
            }
        }
    }
    memcpy(sea, tmp_sea, sizeof(sea));
}

void moveKing(int idx) {
    for(int i = 0; i < R; i++) {
        if(sea[i][idx].size > 0) {
            sum += sea[i][idx].size;
            sea[i][idx].size = 0;
            break;
        }
    }
}

void solve(int idx) {
    if(idx == C) return;

    moveKing(idx);
    moveShark();

    solve(idx + 1);
}

int main() {
    scanf("%d %d %d", &R, &C, &m);

    int r, c, s, d, z;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        Shark shark = { s, d - 1, z };
        sea[r - 1][c - 1] = shark;
    }

    solve(0);

    printf("%d\n", sum);
}

/**
 * 전형적인 시뮬문제... 그리고 맨 처음에 시간초과 난 문제..
 * 지금 구조체에서 size 값으로 null인지 아닌지 판단하고 있는데 
 * 차라리 death 같이 값을 하나 더 둬서 0, 1 판단하면 더 좋을 것 같음.
 * 그리고 지금 구조체 배열을 쓰고 있는데 공간복잡도를 더 생각하면 좋을 듯... 시간 없어서 넘 급하게 풀었음ㅠ
 * 
 * 처음에는 상어를 하나하나 거리 계산을 했는데 
 * 32번째 줄 추가하고 시간초과 해결..
 * 어차피 방향은 반대 방향으로만 바뀌어서 움직이는 곳이 한정되어있어 여러번 이동할 필요가 없음..
 * (기억해놓으면 좋을 듯.. 다른 문제에서도 충분히 활용할 수 있을듯)
 * 
 * moveKing에서 사람 한 칸 이동하고 가장 위에 있는 상어를 먹음
 * moveShark에서 상어가 이동
 * tmp_sea배열을 만들어서 (겹치는 상어가 있을 수 있어서 복사해서 사용함)
 * sea 배열에서 상어를 찾아서 이동시킨 다음 tmp_sea에 넣음
 * 넣을 때 이미 상어가 있으면 크기 비교함.
 * 마지막으로 tmp_sea 배열을 sea로 복사
 * **/