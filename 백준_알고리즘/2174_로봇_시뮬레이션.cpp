#include <iostream>
#include <vector>
#define MAX 102
using namespace std;

typedef struct {
    int x, y, dir;
} Robot;

char DIR, ORDER;
int A, B, N, M, NUM, LOOP;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int map[MAX][MAX];

int get_dir(char dir) {
    if(dir == 'E') return 0;
    else if(dir == 'W') return 2;
    else if(dir == 'N') return 3;
    else return 1;
}

int change_dir(bool is_right, int dir) {
    if(is_right) return dir == 3 ? 0 : dir + 1;
    else return dir == 0? 3 : dir - 1;
}

int main() {
    scanf("%d %d %d %d", &A, &B, &N, &M);

    vector<Robot> v(N + 1);
    for(int i = 1; i <= N; i++) {
        scanf("%d %d %c", &v[i].x, &v[i].y, &DIR);
        v[i].dir = get_dir(DIR); 
        map[v[i].x][v[i].y] = i;
    }

    while(M--) {
        
        scanf("%d %c %d", &NUM, &ORDER, &LOOP);

        if(ORDER == 'F') {
            while(LOOP--) {
                int nx = v[NUM].x + dx[v[NUM].dir];
                int ny = v[NUM].y + dy[v[NUM].dir];

                if(0 >= nx || nx > A || 0 >= ny || ny > B) {
                    printf("Robot %d crashes into the wall\n", NUM);
                    return 0;
                } else if(map[nx][ny] != 0) {
                    printf("Robot %d crashes into robot %d\n", NUM, map[nx][ny]);
                    return 0;
                }

                map[v[NUM].x][v[NUM].y] = 0;
                v[NUM].x = nx;
                v[NUM].y = ny;
                map[nx][ny] = NUM;
            }
        } else {
            if(LOOP % 4 == 0) continue;
            LOOP %= 4;
            while(LOOP--) {
                if(ORDER == 'L') v[NUM].dir = change_dir(false, v[NUM].dir);
                else v[NUM].dir = change_dir(true, v[NUM].dir);
            }
        }
    }
    printf("OK\n");
}

/**
 * 엄청 틀린 문제...
 * 
 * 문제에서 땅이 거꾸로 되어있어서 매우 헷갈렸음 + 동서남북 잘못 씀ㅠㅠ
 * 4
 * 3
 * 2
 * 1
 *   1 2 3 4 5 이런 식으로 되어있음
 * 
 * 여기서 가로가 A(5), 세로가 B(4)임 
 * 그래서 위처럼 되어있는 것을 아래와 같이 바꿔서 풀었음
 *   1 2 3 4
 * 1
 * 2
 * 3
 * 4
 * 5
 * 
 * 추가적으로 팁?
 * 여태까지는 회전 몇 번했을 때 회전 함수 내에서 나머지값 계산해서.. 결과를 리턴했는데
 * 회전을 여러번 하는 경우 한번 회전하는 함수를 그 회전하려는 횟수만큼 반복시키면 됨.. 
 * **/