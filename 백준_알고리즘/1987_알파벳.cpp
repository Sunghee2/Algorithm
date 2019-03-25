#include <iostream>

int r, c, ans = 0;
char map[21][21];
bool visited[26] = { 0 };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int num) {
    if(num > ans) ans = num;
    visited[(int)map[x][y] - 65] = true;
    
    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(0 <= new_x && new_x < r && 0 <= new_y && new_y < c && !visited[(int)map[new_x][new_y] - 65]) {
            dfs(new_x, new_y, num + 1);
        }
    }
    
    visited[(int)map[x][y] - 65] = false;
}

int main() {
    scanf("%d %d", &r, &c);

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    dfs(0, 0, 1);
    printf("%d\n", ans);
}

/**
 * dfs
 * for문을 통해 여러 방향으로 갈 수 있다는 것 기억하기.
 * 맨 처음에는 visited 초기화 문제때문에 틀렸음.
 * 지금 가는 길 말고 더 긴 길이 있을 때 이미 visited는 현재 길들을 true해 놓은 상태라
 * false로 바꿔줬어야 함.
 * 예전에는 int나 다른 방법을 생각했을텐데.. 생각해보니 그냥 for문 끝나고 false로 바꿔주면 되는 것이었음..ㅠ
 * **/