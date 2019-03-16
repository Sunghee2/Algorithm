#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int land[51][51] = { 0 };
bool visited[51][51] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if((land[new_x][new_y] == 1) && (visited[new_x][new_y] == 0) && (0 <= new_x) && (new_x < n) && (0 <= new_y) && (new_y < m)) {
            visited[new_x][new_y] = 1;
            dfs(new_x, new_y);
        } 
    }
}

int main() {
    int testcase, k, x, y;
    scanf("%d", &testcase);

    while(testcase-- > 0) {
        scanf("%d %d %d", &n, &m, &k);

        memset(land, 0, sizeof(land));
        memset(visited, 0, sizeof(visited));
        while(k-- > 0) {
            scanf("%d %d", &x, &y);
            land[x][y] = 1;
        }

        int bug = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((land[i][j] == 1) && (visited[i][j] == 0)) {
                    dfs(i, j);
                    bug++;
                }
            }
        }

        printf("%d\n", bug);
    }   
}

/**
 * 전형적인 dfs, bfs문제.
 * 배추가 심어져 있다고 입력받은 좌표는 land에서 1로 변경해줌.
 * 그리고 모든 land좌표에서 1인 것과 아직 방문하지 않은 좌표에서 dfs 호출. 
 * -> 호출할 때마다 지렁이 한 마리씩 추가!
 * dfs에서는 상하좌우 움직이면서 방문하지 않았고 1인 경우에는 visited=true하고 dfs호출.
 * **/