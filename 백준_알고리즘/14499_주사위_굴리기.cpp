#include <iostream>
#define MAX 21
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
using namespace std;

int n, m, x, y, k;
// 동, 서, 북, 남
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int map[MAX][MAX], dice[7];

void printDice() {
    printf("dice : ");
    for(int i = 1; i < 7; i++) printf("%d ", dice[i]);
    printf("\n");
}

void changeDice(int dir) {
    int top = dice[1];
    switch(dir) {
        case EAST:
            dice[1] = dice[6];
            dice[6] = dice[2];
            dice[2] = dice[5];
            dice[5] = top;
            break;
        case WEST:
            dice[1] = dice[5];
            dice[5] = dice[2];
            dice[2] = dice[6];
            dice[6] = top;
            break;
        case NORTH:
            dice[1] = dice[4];
            dice[4] = dice[2];
            dice[2] = dice[3];
            dice[3] = top;
            break;
        case SOUTH:
            dice[1] = dice[3];
            dice[3] = dice[2];
            dice[2] = dice[4];
            dice[4] = top;
            break;
    }
}

void move(int dir) {
    int nx = x + dx[dir - 1];
    int ny = y + dy[dir - 1];

    if(0 > nx || nx >= m || 0 > ny || ny >= n) return;

    changeDice(dir);
    if(map[ny][nx]) {
        dice[2] = map[ny][nx];
        map[ny][nx] = 0;
    } else {
        map[ny][nx] = dice[2];
    }
    x = nx;
    y = ny;

    printf("%d\n", dice[1]);
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    int dir;
    for(int i = 0; i < k; i++) {
        scanf(" %d", &dir);
        move(dir);
    }
}

// 이전에 풀었던 것 보니깐 알고보니 x, y를 반대로 써서 틀린 거였음... 
// 물론.. 오늘도 똑같이 실수 했다ㅎㅎ.. 문제 잘못 읽기 + 행/열 헷갈리기..
// 심지어 swap도 순서를 잘못해서 이미 변경된 인덱스로 다른 것을 변경시켰음...ㅎㅎ..
// 그래도 그런 실수 한 거에 비해 엄청 빨리 풀어서 위안..

// dice 순서는 아래와 같음
// 1, 2, 3, 4, 5, 6
// 1, 6, 2, 5, 3, 4 -> 내가 편한대로 함ㅎㅎ
// move 함수에서 일단 x, y를 이동시키고 만약 범위를 벗어나면 종료함
// 아니라면 changeDice함수를 통해서 동, 서, 남, 북 방향으로 주사위 숫자 변경
// 다시 move 돌아와서 map이 0이면 주사위 바닥 숫자를 옮기고(문제 읽다 놓친 부분)
// 0이 아니면 주사위 바닥에 숫자 변경함
// 출력