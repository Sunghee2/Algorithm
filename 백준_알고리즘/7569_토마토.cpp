#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

typedef struct {
    int x, y, z;
} Point;

int m, n, h, cnt;
int box[MAX][MAX][MAX];
Point dir[6] = { { 0, 0, 1 }, { 0, 1, 0 }, { 0, -1, 0 }, { 1, 0, 0 }, { -1, 0, 0 }, { 0, 0, -1 } };
queue<Point> q;

int bfs() {
    int day = 1;

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            q.pop();

            for(int i = 0; i < 6; i++) {
                int nx = x + dir[i].x;
                int ny = y + dir[i].y;
                int nz = z + dir[i].z;

                if(0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h && box[nx][ny][nz] == 0) {
                    box[nx][ny][nz] = 1;
                    Point np = { nx, ny, nz };
                    q.push(np);
                    cnt--;
                }

                if(cnt == 0) return day;
            }
        }
        day++;
    }

    return -1;
}

int main() {
    scanf("%d %d %d", &m, &n, &h);

    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf(" %d", &box[i][j][k]);
                if(box[i][j][k] == 0) cnt++;
                else if(box[i][j][k] == 1) {
                    Point p = { i, j, k };
                    q.push(p);
                }
            }
        }
    }

    if(cnt == 0) printf("0\n");
    else printf("%d\n", bfs());
}

// 그냥 기존 토마토 문제(https://www.acmicpc.net/problem/7576) -> 2차원 문제를 3차원으로 확장시켜놓은 문제

// 입력 받을 때 0(익지 않은 토마토)의 개수를 셈(cnt)
// cnt == 0이면(토마토가 모두 익어있는 상태), 0 출력
// 입력 받을 때 1(익은 토마토)은 queue에 넣음
// bfs
// 앞, 뒤, 위, 아래, 오른쪽, 왼쪽 큐에 넣음(앞, 뒤 주의! 문제를 꼼꼼하게 안 읽어서 처음에는 모든 높이 다 해당되는 줄 알았음ㅠ)
// day를 세기 위해서 안에 while 루프를 돌음(-> 이 방법 아니면 예전에 많이 쓰던 그냥 box에 1이 아닌 day를 적어놓고 최댓값 찾는 방법도 있을 듯)
// 큐 돌면서 cnt가 0이 되면(모두 익었으면), day를 리턴하여 출력
// 만약 큐가 다 비었는데 cnt가 0이 아니라면(다 익지 못함), -1을 리턴하여 출력