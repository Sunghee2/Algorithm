#include <iostream>
#include <cstring>
#define MAX 21
using namespace std;

int tc, r, c, memory, direction;
bool end_flag;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
char ops[MAX][MAX];
int visited[MAX][MAX][16][4];

void run(int x, int y) {
    if(end_flag) return;

    char op = ops[x][y];
    if(visited[x][y][memory][direction]) return;
    else visited[x][y][memory][direction] = 1;

    if('0' <= op && op <= '9') {
        memory = op - '0';
    }

    switch(op) {
        case '<':
            direction = 1;
            break;
        case '>':
            direction = 0;
            break;
        case '^':
            direction = 3;
            break;
        case 'v':
            direction = 2;
            break;
        case '_':
            direction = memory == 0 ? 0 : 1;
            break;
        case '|':
            direction = memory == 0 ? 2 : 3;
            break;
        case '@':
            end_flag = true;
            return;
        case '+':
            memory = memory == 15? 0 : memory + 1;
            break;
        case '-':
            memory = memory == 0? 15 : memory - 1;
            break;
    }

    if(op == '?') {
        for(int i = 0; i < 4; i++) {
            int nr = x + dx[i];
            int nc = y + dy[i];

            if(0 > nr || nr >= r || 0 > nc || nc >= c) {
                if(i == 0) nc = 0;
                else if(i == 1) nc = c - 1;
                else if(i == 2) nr = 0;
                else nr = r - 1;
            }

            int tmp = direction;
            direction = i;
            run(nr, nc);
            direction = tmp;
        }
    } else {
        int nr = x + dx[direction];
        int nc = y + dy[direction];

        if(0 > nr || nr >= r || 0 > nc || nc >= c) {
            if(direction == 0) nc = 0;
            else if(direction == 1) nc = c - 1;
            else if(direction == 2) nr = 0;
            else nr = r - 1;
        }

        run(nr, nc);
    }

}

int main() {
    scanf("%d", &tc);
    for(int t = 1; t <= tc; t++) {
        scanf("%d %d", &r, &c);

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                scanf(" %c", &ops[i][j]);
            }
        }

        memory = 0;
        direction = 0;
        end_flag = false;
        memset(visited, false, sizeof(visited));
        run(0, 0);

        if(end_flag) printf("#%d YES\n", t);
        else printf("#%d NO\n", t);
    }
}


/**
 * 구현, 완탐 문제로.. 쉬웠지만.. 조건이 많아 디버깅 하는데 엄청 오래걸림.....
 * 다른 문제와 다른 점은 단순히 visited[x][y]로 체크하면 안 됨.
 * 다시 돌아와도 memory, direction이 다르면 _나 |에 의해서 이전과 다른 방향으로 갈 수 있음
 * 따라서 방문 체크를 x, y, memory, direction 이 모두 같은지 확인 하는 것.
 * 맨 처음에는 이 방문 체크를 struct 배열로 ops에 했었는데..
 * 지금 처럼 int 배열로 따로 빼는 것이 구현하기에 훨씬 편한 것 같다..
 * **/