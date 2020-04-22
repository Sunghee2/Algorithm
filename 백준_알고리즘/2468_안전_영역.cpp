#include <iostream>
#include <cstring>
using namespace std;

int n, min_num = 101, max_num = 0, ans = 0;
int map[101][101];
int visited[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int rain) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if((0 <= new_x) && (new_x < n) && (0 <= new_y) && (new_y < n) && (!visited[new_x][new_y]) && (map[new_x][new_y] > rain)) {
            dfs(new_x, new_y, rain);
        }
    }
}

void callDFS(int rain) {
    int safe_zone = 0;

    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((!visited[i][j]) && (map[i][j] > rain)) {
                dfs(i, j, rain);
                safe_zone++;
            }
        }
    }
    
    if(safe_zone > ans) ans = safe_zone;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            min_num = min_num > map[i][j]? map[i][j] : min_num;
            max_num = max_num < map[i][j]? map[i][j] : max_num;
        }
    }

    for(int i = 0; i <= max_num; i++) {
        callDFS(i);
    }

    printf("%d\n", ans);
}

/**
 * 비가 오지 않는 경우도 생각해야됨.
 * 그래서 49~51번째 줄의 for문에서 비가 오지 않는 경우(0)부터 max값(input받을 때부터의 )
 * **/