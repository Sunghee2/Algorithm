#include <iostream>
#include <cstring>

int x, y, ans = 0;
int map[301][301];
int zero[301][301];
bool visited[301][301] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int cx, int cy) {
    visited[cx][cy] = true;

    for(int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(0 <= nx && nx < x && 0 <= ny && ny < y && !visited[nx][ny] && map[nx][ny] != 0) {
            dfs(nx, ny);
        }
    }
}

int callDFS() {
    int num = 0; 
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j ++) {
            if(!visited[i][j] && map[i][j] != 0) {
                dfs(i, j);
                num++;
            }
            if(num >= 2) {
                return num;
            }
        }
    }
    return num;
}

int melt() {
    bool zero_flag = false;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(map[i][j] != 0) {
                zero_flag = true;
                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(0 <= ni && ni < x && 0 <= nj && nj < y) {
                        if(map[ni][nj] == 0) {
                            zero[i][j]++;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(zero[i][j] != 0) {
                map[i][j] = map[i][j] > zero[i][j]? map[i][j] - zero[i][j] : 0;
            }
        }
    }

    if(!zero_flag) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    scanf("%d %d", &x, &y);
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    while(true) {
        memset(visited, 0, sizeof(visited));
        int c = callDFS();
        if(c >= 2) {
            printf("%d\n", ans);
            return 0;
        }

        memset(zero, 0, sizeof(zero));
        int m = melt();
        ans++;
        if(m == 0) {
            printf("0\n");
            return 0;
        }
    }
}

/**
 * dfs, bfs문제 - 난 dfs로 풀었음.
 * callDFS는 방문안한 것을 체크해서 dfs를 돌게하는 함수임. 즉, 덩어리가 몇 개인지 확인하는 함수
 * 그래서 dfs() 호출되는 수가 덩어리 수임. 만약 2번 이상 호출하면 그냥 멈추고 리턴함
 * 만약 이 리턴값이 2를 넘겼으면 두 덩어리 이상이므로 85번째 줄에서 출력하고 끝냄.
 * 하지만 2를 넘기지 않았으면 melt() 함수를 호출함. 이 함수에서 처음 for문은 동서남북의 0을 세서 zero배열에 넣음
 * 두번째 있는 for문은 zero배열에 저장된 것 가지고 빙하 높이를 빼는 것임.
 * 처음에는 그냥 0을 세서 바로 하나씩 빼버렸는데 그러면 중복으로 빠지기때문에 불가능했음
 * 그래서 나눠서 함. zero_flag는 모두가 0인지 확인하는 것임. 빙하가 모두 녹았는지 확인하는 것.
 * 빙하가 다 녹았으면 이 리턴값에 의해서 93번째 줄에서 출력하고 끝나게 됨. 아니라면 다시 while문에 의해
 * 처음 callDFS로 돌아가서 반복
 **/