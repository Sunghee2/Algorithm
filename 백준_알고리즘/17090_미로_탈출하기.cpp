#include <iostream>
#define MAX 501
using namespace std;

int N, M, ans = 0;
char map[MAX][MAX];
bool visited[MAX][MAX];
int out[MAX][MAX];

bool dfs(int i, int j) {
    int ni = i, nj = j;

    if(map[i][j] == 'U') {
        ni -= 1;
    } else if(map[i][j] == 'R') {
        nj += 1;
    } else if(map[i][j] == 'D') {
        ni += 1;
    } else if(map[i][j] == 'L') {
        nj -= 1;
    }

    if (0 > ni || ni >= N || 0 > nj || nj >= M) {
        out[i][j] = 1;
        return true;
    }
    if (out[ni][nj] == 1) {
        out[i][j] = 1;
        return true;
    }
    if(visited[ni][nj] || out[ni][nj] == -1) {
        out[i][j] = -1;
        return false;
    }

    visited[ni][nj] = true;
    bool ret = dfs(ni, nj);
    if(ret) out[i][j] = 1;
    else out[i][j] = -1;
    visited[ni][nj] = false;

    return ret;
}

void callDFS() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(out[i][j] == -1) continue;
            if(out[i][j] == 1) {
                ans++;
                continue;
            }
            visited[i][j] = true;
            if(dfs(i, j)) ans++;
            visited[i][j] = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    callDFS();

    printf("%d\n", ans);
}