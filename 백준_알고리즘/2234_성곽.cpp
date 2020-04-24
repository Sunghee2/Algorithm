#include <iostream>
#include <cstring>
#include <math.h>
#define MAX 51
using namespace std;

int n, m, tmp_size, room_num = 0, max_size, max_size2;
int map[MAX][MAX];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
bool visited[MAX][MAX];

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= m || 0 > ny || ny >= n || visited[nx][ny]) continue;
        if(map[x][y] & (int) pow(2, i)) continue;

        dfs(nx, ny);
        tmp_size++;
    }
}

void callDFS(bool flag) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                tmp_size = 1;
                dfs(i, j);
                if(flag) max_size2 = tmp_size > max_size2 ? tmp_size : max_size2;
                else {
                    max_size = tmp_size > max_size ? tmp_size : max_size;
                    room_num++;
                }
            }
        }
    }
}

void removeWall() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!map[i][j]) continue;
            
            for(int k = 0; k < 4; k++) {
                int num = (int) pow(2, k);
                if(map[i][j] & num) {
                    map[i][j] &= ~num;
                    memset(visited, false, sizeof(visited));
                    callDFS(1);
                    map[i][j] |= num;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    memset(visited, false, sizeof(visited));
    callDFS(0);
    removeWall();
    printf("%d\n%d\n%d\n", room_num, max_size, max_size2);
}

/**
 * 완전 탐색 문제
 * 다른 문제와 다른 점은 벽이 서:1, 북:2, 동:4, 남:8인데
 * 주어지는 입력값은 한 칸에 있는 벽의 합으로 주어짐
 * 그래서 비트로 각 값이 있는지 확인하고(51번째 줄)
 * 백트래킹으로 지운 다음 dfs돌리고 다시 복구
 * **/